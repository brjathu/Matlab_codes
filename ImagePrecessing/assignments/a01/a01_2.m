clear all;
close all;
im=im2double(imread('a01images/im02.png'));
m=size(im,1)
n=size(im,2)
subplot(1,2,1);
imshow(im);
title('Original')

gamma =input('please enter gamma value : ');
c = 1/(1.0^gamma);
result=zeros(m,n,3);
result=uint8(result);

result(:,:,:)= 255*c*((im(:,:,:)).^gamma);
% result(:,:,2)= 255*c*((im(:,:,2)).^gamma);
% result(:,:,3)= 255*c*((im(:,:,3)).^gamma);

subplot (1,2, 2)
imshow(result);
title('Gamma corrected value')

