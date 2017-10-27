clear all;
close all;
im=rgb2gray(imread('gantrycrane.png'));
im=im2double(im);
[m,n]=size(im)

w=3;
sigma=2;
[Y,X]=meshgrid(-w:w,-w:w);
g=exp(-(X.^2+Y.^2)/2/sigma);
g=g/sum(sum(g));

im=imfilter(im,g,'same');

Gx=[-1 -2 -1;0 0 0;1 2 1]
Gy=Gx'

% imDeriX=imfilter(im,Gx,'same');
% imDeriY=imfilter(im,Gy,'same');


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
imshow(uint8(abs(imDeriX)*255)*4);

imDeriY=(imDeriY)./4;
subplot(1,4,2);
imshow(uint8(abs(imDeriY)*255));

imNorm=sqrt(imDeriX.^2+imDeriY.^2);
subplot(1,4,3);
imshow((imNorm));

im45=(imDeriX+imDeriY)./sqrt(2);
subplot(1,4,4);
imshow(abs(im45));


