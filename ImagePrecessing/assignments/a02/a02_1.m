clear all;
close all;
im=rgb2gray(imread('gantrycrane.png'));
im=im2double(im);
[m,n]=size(im)

Gx=[-1 -2 -1;0 0 0;1 2 1]
Gy=Gx'

imDeriX=im;
imDeriY=im;

for i=2:m-1
    for j=2:n-1
        imDeriX(i,j)=(sum(sum(im(i-1:i+1,j-1:j+1).*Gx)));
        imDeriY(i,j)=(sum(sum(im(i-1:i+1,j-1:j+1).*Gy)));
    end
end
        
imDeriX=(imDeriX)./4;
subplot(1,4,1);
imshow(uint8(abs(imDeriX)*255));
title('Derivative in x direction')

imDeriY=(imDeriY)./4;
subplot(1,4,2);
imshow(uint8(abs(imDeriY)*255));
title('Derivative in x direction')

imNorm=sqrt(imDeriX.^2+imDeriY.^2);
subplot(1,4,3);
imshow((imNorm));
title('Normal Derivative')

im45=(imDeriX+imDeriY)./sqrt(2);
subplot(1,4,4);
imshow(abs(im45));
title('Derivative in 45 degree')


