clear all;
close all;
im=imread('a01images/im01.png');
subplot(1,5,1);
imshow(im);
title('Original Image');

subplot(1,5,2);
imRed=im;
imRed(:,:,2:3)=0;
imshow(imRed);
title('Red Image');

subplot(1,5,3);
imGreen=im;
imGreen(:,:,1)=0;
imGreen(:,:,3)=0;
imshow(imGreen);
title('Green Image');

subplot(1,5,4);
imBlue=im;
imBlue(:,:,1:2)=0;
imshow(imBlue);
title('Blue Image');


subplot(1,5,5);
imGray=imRed(:,:,1).*0.2989+imBlue(:,:,3).*0.1140+ imGreen(:,:,2).*0.5870;
imshow(imGray);
title('Gray Image');
