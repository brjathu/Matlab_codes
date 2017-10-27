% % clear all;
% % clc;
% % instruction={'ADDI' 'R10','1';
% %         'SHFLI' 'R10','10';
% %         'ADDI' 'R2','13';
% %         'ADDI' 'R1','13';
% %         'ADDI' 'R3','1';
% %         'SHFLI' 'R3','7';
% %         'CPYREG' 'R4','R3';
% %         'ADDI' 'R4','1';
% %         'ADD' 'R3','R5';
% %         'ADD' 'R4','R5';
% %         'ADD' 'R3','R6';
% %         'ADD' 'R4','R6';
% %         'LOAD' 'R7','R3';
% %         'LOAD' 'R8','R4';
% %         'ADDH' 'R9','R7';
% %         'ADDL' 'R9','R7';
% %         'ADDH' 'R9','R8';
% %         'ADDI' 'R3','13';
% %         'ADDI' 'R4','13';
% %         'LOAD' 'R7','R3';
% %         'LOAD' 'R8','R4';
% %         'ADDH' 'R9','R7';
% %         'ADDL' 'R9','R7';
% %         'ADDH' 'R9','R8';
% %         'ADDI' 'R3','13';
% %         'ADDI' 'R4','13';
% %         'LOAD' 'R7','R3';
% %         'LOAD' 'R8','R4';
% %         'ADDH' 'R9','R7';
% %         'ADDL' 'R9','R7';
% %         'ADDH' 'R9','R8';
% %         'SHFRI' 'R9','3';
% %         'STORE' 'R10','R9';
% %         'CLRREG' 'R9','x';
% %         'ADDI' 'R10','1';
% %         'ADDI' 'R6','1';
% %         'CLRREG' 'R3','x';
% %         'SUBI' 'R1','1';
% %         'GOTOZ' '5','x';
% %         'ADDI' 'R5','13';
% %         'ADDI' 'R5','13';
% %         'CLRREG' 'R6','x';
% %         'SUBI' 'R2','1';
% %         'GOTOZ' '4','x';
% %         'HALT' 'x','x';};
% % 
% % integer= {'0' '1' '2' '3' '4' '5' '6' '7' '8' '9' '10' '11' '12' '13' '14' '15'};
% % 
% % opcodes = {'LOAD','STORE','ADDI','ADD','SUBI','CLRREG','LOD128','INC128','CPYREG','SHFLI','SHFRI','HALT','ADDL','ADDH','GOTOZ','R1','R2','R3','R4','R5','R6','R7','R8','R9','R10','x'};
% % decode = {[1 1 1 0 0 0 0 0],[1 1 1 0 1 0 0 0],[1 1 0 0 1 0 0 0],[0 1 0 1 0 0 0 0],[0 1 0 1 1 0 0 0],[1 1 0 1 0 0 0 0],[1 1 0 1 1 0 0 0],[0 0 0 1 1 0 0 0],[0 0 1 0 1 0 0 0],[1 0 1 0 0 0 0 0],[1 0 1 0 1 0 0 0],[1 1 1 1 1 1 1 1],[1 0 0 0 1 0 0 0],[1 0 0 1 0 0 0 0],[1 0 1 1 0 0 0 0],[0 0 0 1],[0 0 1 0],[0 0 1 1],[0 1 0 0],[0 1 0 1],[0 1 1 0],[0 1 1 1],[1 0 0 0],[1 0 0 1],[1 0 1 0],[0 0 0 0]};
% % 
% % dictionary = containers.Map(opcodes,decode);
% % bi2de(dictionary(char(instruction(1,1))),'left-msb');
% % l=length(instruction)
% % temp = zeros(2,l);
% %  %bi2de(dictionary(char(instruction(3,3))))+bi2de(dictionary(char(instruction(3,2))))*16;
% % for i=1:l
% %     temp(1,i)=bi2de(dictionary(char(instruction(i,1))),'left-msb');
% %     if (strcmp(char(instruction(i,1)),'GOTOZ'))
% %         temp(2,i)= str2double(char(instruction(i,2)));
% %     elseif (ismember(instruction(i,3),integer))
% %         temp(2,i)=bi2de(dictionary(char(instruction(i,2))),'left-msb')*16 + str2double(char(instruction(i,3)));
% %     else
% %         temp(2,i)=bi2de(dictionary(char(instruction(i,2))),'left-msb')*16+ bi2de(dictionary(char(instruction(i,3))),'left-msb');
% %     end
% % end
% % 
% % count = 0;
% % k=length(temp);
% % send = zeros(2*127,1);
% % for m=1:2*k
% %     send(m)=temp(m);
% % end
% %     
% % imIn=uint8((imread('cameraman.tif')));
% % im=imresize(imIn,0.1);
% % 
% % in_file=fopen('sample2.coe','wt');
% % 
% s = serial('/dev/ttyXRUSB0');
% set(s,'BaudRate',9600);
% s.InputbufferSize=256*256;
% s.Timeout=20;
% fopen(s);
% % pause(0.1)
% % 
% % 
% % [m,n] =size(im);
% % count = 0;
% % p=im';
% % inter=p(:)';
% % send=send(:)';
% % 
% % final = [send(:);inter(:)];
% % 
% % % for k=1:length(final)
% % %     fprintf(in_file,'%s\n',dec2hex(final(k)));
% % % %     fprintf(in_file,'\n');
% % % end
% % 
% % 
% % ss=dec2hex(final);
% % 
% % for k=1:2:length(ss)
% %     fprintf(in_file,'%c',ss(k,1));
% %     fprintf(in_file,'%c',ss(k,2));
% %     fprintf(in_file,'%c',ss(k+1,1));
% %     fprintf(in_file,'%c,\xa',ss(k+1,2));
% % end
% % 
% % fclose(in_file);
% % % for k=1:length(final)
% % %     fwrite(s,final(k),'uint8')
% % %     count = count +1
% % %     pause(0.01)
% % % end
% % 
% % % pause(1)
% 
% out = fread(s)
% fclose(s)
% delete(s)
% clear s
% 
% 
% 
% out2=uint8(out)
% 
% imNew=uint8(zeros(m,n));



b=flipud(a);
imNew=uint8(zeros(13,13));

for (i=1:2:26)
    for (j=1:2:26)
        imNew(floor(i/2+1),floor(j/2+1))= b(26*(floor(i/2+1)-1)+j)
    end
    
end





