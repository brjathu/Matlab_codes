clear all;
im=((imread('img/12003.jpg')));
% im=((imread('img/302003.jpg')));

imThRed=(im(:,:,1)>205);
imThGreen=(im(:,:,2)>45);
imThBlue=(im(:,:,3)>40);
% 
% imThRed=(im(:,:,1)>155);
% imThGreen=(im(:,:,2)>100);
% imThBlue=(im(:,:,3)>70);

imOut=imThRed & imThGreen & imThBlue;
imshow(imOut)
