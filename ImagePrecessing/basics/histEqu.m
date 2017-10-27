a=imread('me.jpg');
m=size(a,1);
l=size(a,2);

red=a(:,:,1);
green=a(:,:,1);
blue=a(:,:,1);

gray=rgb2gray(a);

L=256;

s=zeros(L,1);


for i=0:L-1
    s(i+1)=sum(sum(gray<=i));
end

s=s/(m*l);
subplot(2,2,1);
imshow(gray);

subplot(2,2,2);
imshow(mat2gray(s(gray+1)));

subplot(2,2,3);
imhist(gray);

subplot(2,2,4);
imhist(mat2gray(s(gray+1)));