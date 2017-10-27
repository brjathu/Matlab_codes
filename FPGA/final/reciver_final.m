clear all;
close all;
s = serial('/dev/ttyXRUSB0');
set(s,'BaudRate',115200);
s.InputbufferSize=256*256;
s.Timeout=10;
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

imshow(imNew)