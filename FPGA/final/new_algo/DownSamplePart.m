function [ imNew ] = DownSamplePart( im )
%A Summary of this function goes here
%   Detailed explanation goes here


flashFPGA = ['djtgcfg prog -d Atlys -i 0 -f /home/brjathu/FPGA/Processor_FPGA/BRAM_TEST.bit'];
system(flashFPGA)

instruction={   'ADDI'  'R10','9';
                'SHFLI' 'R10','12';
                'LOD128' 'R2','x';
                    'LOD128' 'R1','x';
                        'ADDI'  'R3','1';
                        'SHFLI' 'R3','10';
                        'CPYREG' 'R4','R3';
                        'ADDI'  'R4','1';
                        'ADD'   'R3','R5';
                        'ADD'   'R4','R5';
                        'ADD'   'R3','R6';
                        'ADD'   'R4','R6';
                        'LOAD'  'R7','R3';
                        'LOAD'  'R8','R4';
                        'ADDH'  'R9','R7';
                        'ADDL'  'R9','R7';
                        'ADDL'  'R9','R7';
                        'ADDH'  'R9','R8';
                        'INC128'  'R3','x';
                        'ADDI' 'R3','1';
                        'INC128'  'R4','x';
                        'ADDI' 'R4','1';
                        'LOAD'  'R7','R3';
                        'LOAD'  'R8','R4';
                        'ADDH'  'R9','R7';
                        'ADDH'  'R9','R7';
                        'ADDL'  'R9','R7';
                        'ADDL'  'R9','R7';
                        'ADDL'  'R9','R7';
                        'ADDL'  'R9','R7';
                        'ADDH'  'R9','R8';
                        'ADDH'  'R9','R8';
                        'INC128'  'R3','x';
                        'ADDI' 'R3','1';
                        'INC128'  'R4','x';
                        'ADDI' 'R4','1';
                        'LOAD'  'R7','R3';
                        'LOAD'  'R8','R4';
                        'ADDH'  'R9','R7';
                        'ADDL'  'R9','R7';
                        'ADDL'  'R9','R7';
                        'ADDH'  'R9','R8';
                        'SHFRI' 'R9','4';
                        'STORE' 'R10','R9';
                        'CLRREG' 'R9','x';
                        'ADDI'  'R10','1';
                        'ADDI'  'R6','1';
                        'CLRREG' 'R3','x';
                        'SUBI'  'R1','1';
                        'GOTOZ' '5','x';
                    'INC128' 'R5','x';
                    'INC128' 'R5','x';
                    'ADDI' 'R5','2';
                    'CLRREG' 'R6','x';
                    'SUBI'  'R2','1';
                    'GOTOZ' '4','x';
                'HALT'  'x','x';};

integer= {'0' '1' '2' '3' '4' '5' '6' '7' '8' '9' '10' '11' '12' '13' '14' '15'};

opcodes = {'LOAD','STORE','ADDI','ADD','SUBI','CLRREG','LOD128','INC128','CPYREG','SHFLI','SHFRI','HALT','ADDL','ADDH','GOTOZ','R1','R2','R3','R4','R5','R6','R7','R8','R9','R10','x'};
decode = {[1 1 1 0 0 0 0 0],[1 1 1 0 1 0 0 0],[1 1 0 0 1 0 0 0],[0 1 0 1 0 0 0 0],[0 1 0 1 1 0 0 0],[1 1 0 1 0 0 0 0],[1 1 0 1 1 0 0 0],[0 0 0 1 1 0 0 0],[0 0 1 0 1 0 0 0],[1 0 1 0 0 0 0 0],[1 0 1 0 1 0 0 0],[1 1 1 1 1 1 1 1],[1 0 0 0 1 0 0 0],[1 0 0 1 0 0 0 0],[1 0 1 1 0 0 0 0],[0 0 0 1],[0 0 1 0],[0 0 1 1],[0 1 0 0],[0 1 0 1],[0 1 1 0],[0 1 1 1],[1 0 0 0],[1 0 0 1],[1 0 1 0],[0 0 0 0]};

dictionary = containers.Map(opcodes,decode);
bi2de(dictionary(char(instruction(1,1))),'left-msb');
l=length(instruction)
temp = zeros(2,l);
for i=1:l
    temp(1,i)=bi2de(dictionary(char(instruction(i,1))),'left-msb');
    if (strcmp(char(instruction(i,1)),'GOTOZ'))
        temp(2,i)= str2double(char(instruction(i,2)));
    elseif (ismember(instruction(i,3),integer))
        temp(2,i)=bi2de(dictionary(char(instruction(i,2))),'left-msb')*16 + str2double(char(instruction(i,3)));
    else
        temp(2,i)=bi2de(dictionary(char(instruction(i,2))),'left-msb')*16+ bi2de(dictionary(char(instruction(i,3))),'left-msb');
    end
end



k=length(temp);


send = zeros(2*1023,1);
for m=1:2*k
    send(m)=temp(m);
end

p=im';
inter=p(:)';
send=send(:)';

final = [send(:);inter(:)];

ss=dec2hex(final);

s = serial('/dev/ttyXRUSB0');
set(s,'BaudRate',115200);
s.InputbufferSize=256*256*4;
s.OutputbufferSize=256*256*4;
s.Timeout=10;
s.StopBits=2;
s.Parity = 'none';
fopen(s);
pause(0.1)

fwrite(s,final,'uint8')
fclose(s)

pause(5)
display('please send the image')


fopen(s);
out = fread(s)
fclose(s)

b=flipud(out);
b=b(1:16384);

imNew=uint8(zeros(128,128));

for (i=1:128)
    for (j=1:128)
        imNew(i,j)= b(128*(i-1)+j);
    end
end

end



