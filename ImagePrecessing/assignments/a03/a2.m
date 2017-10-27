clear all;
im=((imread('img/302003.jpg')));
% im=((imread('img/189003.jpg')));


% imshow((im));
% [y x]=(ginput(1));
% x=round(x)
% y=round(y)

x=170;
y=203;

[m,n]=size(im);

imRed=grow(im(:,:,1),12,x,y);   %10,12,2 for girl face  10,12,12 for 2 girl faces
imGreen=grow(im(:,:,2),6,x,y);
imBlue=grow(im(:,:,3),2,x,y);

imOut= imRed &  imGreen & imBlue;

im(:,:,2)=im(:,:,2)+uint8((imOut>0).*255);
imshow((im));

