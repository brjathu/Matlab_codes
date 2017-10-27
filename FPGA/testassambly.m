clear all;
% instruction = {'ADDI' 'R2','1';
% 'SHFLI' 'R2','10';
% 'LOAD' 'R3','R2';
% 'ADDH' 'R3','15';
% 'ADDL' 'R3','15';
% 'STORE' 'R2','R3';
% 'HALT' 'x','x'};


instruction = {

'ADDI' 'R2','10';
'ADDI' 'R3','10';
'STORE' 'R2','R3';
'ADD' 'R5','R2';
'LOAD' 'R4','R2';
'STORE' 'R5','R4';
'HALT' 'x','x'

}


integer= {'0' '1' '2' '3' '4' '5' '6' '7' '8' '9' '10' '11' '12' '13' '14' '15'};

opcodes = {'LOAD','STORE','ADDI','ADD','CLRREG','LOD128','INC128','CPYREG','SHFLI','SHFRI','HALT','ADDL','ADDH','R1','R2','R3','R4','R5','R6','R7','R8','R9','R10','x'};
decode = {[1 1 1 0 0 0 0 0],[1 1 1 0 1 0 0 0],[1 1 0 0 1 0 0 0],[0 1 0 1 0 0 0 0],[1 1 0 1 0 0 0 0],[1 1 0 1 1 0 0 0],[0 0 0 1 1 0 0 0],[0 0 1 0 1 0 0 0],[1 0 1 0 0 0 0 0],[1 0 1 0 1 0 0 0],[1 1 1 1 1 1 1 1],[1 0 0 0 1 0 0 0],[1 0 0 1 0 0 0 0],[0 0 0 1],[0 0 1 0],[0 0 1 1],[0 1 0 0],[0 1 0 1],[0 1 1 0],[0 1 1 1],[1 0 0 0],[1 0 0 1],[1 0 1 0],[0 0 0 0]};

dictionary = containers.Map(opcodes,decode);
l=length(instruction);
temp = zeros(2,l);
for i=1:l
    temp(1,i)=bi2de(dictionary(char(instruction(i,1))),'left-msb');
    if (ismember(instruction(i,3),integer))
        temp(2,i)=bi2de(dictionary(char(instruction(i,2))),'left-msb')*16 + str2double(char(instruction(i,3)));
    else
        temp(2,i)=bi2de(dictionary(char(instruction(i,2))),'left-msb')*16+ bi2de(dictionary(char(instruction(i,3))),'left-msb');
    end
end

k=length(temp);
send = uint8(zeros(100,1));
for m=1:2*k
    send(m)=temp(m);
end
    
s = serial('/dev/ttyXRUSB0');
set(s,'BaudRate',115200);
s.InputbufferSize=256*256*2;
s.Timeout=10;
fopen(s);
pause(0.1)


for i=1:100
    fwrite(s,send(i), 'uint8')
end
32
pause(5)
52
out = fread(s)
fclose(s)
delete(s)
clear s


