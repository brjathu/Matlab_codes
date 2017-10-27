% imIn=uint8((imread('cameraman.tif')));
% im=imresize(imIn,0.1);
im=uint8(zeros(52,52));
for i=1:52
    for j=1:52
        im(i,j) = 255*(mod(i+j,2));
    end
end



s = serial('/dev/ttyXRUSB0');
set(s,'BaudRate',9600);

s.InputbufferSize=256*256*2;
s.Timeout=20;
fopen(s);
pause(0.1)


[m,n] =size(im);
count = 0;
for i=1:m
    for j=1:n
        fwrite(s,im(i,j), 'uint8')
         count = count +1
           pause(0.01)
    end
end

out = fread(s)
fclose(s)
delete(s)
clear s



out2=uint8(out)

imNew=uint8(zeros(m,n));

for i=1:floor(length(out2)/m)
    for j=1:n
        imNew(i,j) = out2(length(out2)-j-m*(i-1)+1);
    end
end

imshow(imNew)