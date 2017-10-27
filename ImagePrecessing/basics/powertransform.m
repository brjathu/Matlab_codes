

a=imread('me.jpg');
m=size(a,1);
l=size(a,2);

red=a(:,:,1);
green=a(:,:,1);
blue=a(:,:,1);

gray=rgb2gray(a);

gamma=0.9;
c=1/(1.0^gamma);



%for gray only
gray=im2double(gray);
out=255*c*((gray/255.0).^gamma);
imshow(out);


newImg=zeros(m,l);
red=im2double(red);
green=im2double(green);
blue=im2double(blue);
newImg(:,:,1)=255.0*c*((red/255.0).^0.9);
newImg(:,:,2)=255.0*c*((green/255.0).^1);
newImg(:,:,3)=255.0*c*((blue/255.0).^1.2);
% newImg=uint8(newImg);
imshow(newImg);



%graph of 2 lines
gray=rgb2gray(a);
line1=0:0.5:100;
line2=155/55*([201:1:255]-200)+100;
t=[line1, line2];
plot(t);

s=t(gray+1);

imshow(mat2gray(s));


