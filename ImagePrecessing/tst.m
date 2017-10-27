close all;
clear all;
h=fspecial('gaussian',1);
im=(rgb2gray(imread('peppers.png')));
figure;
imshow(im);
%im=[1,2,3,2;5,6,5,4;8,9,8,7;11,12,11,10];
imPadX=padarray(im,[1,1]);
sample1=double(imPadX);
imPadY=imPadX;
imPad=imPadX;
immagPad=imPadX;
imGauss=imPadX;
[m,n]=size(imPadX);
sobelX=[-1,-2,-1;0,0,0;1,2,1];
sobelY=[-1,0,1;-2,0,2;-1,0,1];
% % d=[0,0,0;0,0,0;0,0,0];
% % k=[0,0,0;0,0,0;0,0,0];
for i=1:m-2;
    for j=1:n-2;
       sumX=0;
       sumY=0;
       for x=1:3;
           for y=1:3;
            
            %d(x,y)=sample1(i+x-1,j+y-1);
            %k(x,y)=sobel(x,y)*sample1(i+x-1,j+y-1);
            sumX=sumX+sobelX(x,y)*sample1(i+x-1,j+y-1);
            sumY=sumY+sobelY(x,y)*sample1(i+x-1,j+y-1);
           end
       end
       
   imPadX(i+2-1,j+2-1)=((sumX)+1080)/2160*255;
      
           
   imPadY(i+2-1,j+2-1)=((sumY)+1080)/2016*255;
    imPad(i+2-1,j+2-1)=sqrt(sumY^2+sumX^2);
   immagPad(i+2-1,j+2-1)=180*(atan(abs(sumX)/abs(sumY)))/pi;
   imGauss(i+2-1,j+2-1)=i*exp((i^2+j^2)/2);
       %sum
       
    end
end
imshow(mat2gray(imPadY))