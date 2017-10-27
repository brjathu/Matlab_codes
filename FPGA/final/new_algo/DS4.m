clear all;
clc;
imIn=uint8((imread('cameraman.tif')));
imIn = imresize(imIn,2);
final = uint8(zeros(256,256));

[m,n] =size(imIn);
im=zeros(m+2,n+2);

for i=1:m
    im(i+1,:)=[imIn(i,1),imIn(i,:),imIn(i,512)];
end
im(1,:)=im(2,:);
im(514,:)=im(513,:);

prompt = 'Enter any key to continue: ';
imshow(final);


x=input(prompt);
a=DownSamplePart(im(1:258,1:258));
final(1:128,1:128)=a;
imshow(final);

% 
% x=input(prompt);
% b=DownSamplePart(im(256:514,1:258));
% final(129:256,1:128)=b;
% imshow(final);
% 
% 
% x=input(prompt);
% c=DownSamplePart(im(1:258,257:514));
% final(1:128,129:256)=c;
% imshow(final);
% 
% 
% x=input(prompt);
% d=DownSamplePart(im(257:514,257:514));
% final(129:256,129:256)=d;
% imshow(final);

% imshow(final);

% filter = [1 2 1;
%           2 4 2;
%           1 2 1]
%       
% imOutt = conv2(im, filter);
% imOutt = imOutt/16;
% imOutt = uint8(imOutt);
% 
% imOuttt = uint8(zeros(256,256));
% 
% for i=1:2:516
%     for j=1:2:516
%         imOuttt(ceil(i/2),ceil(j/2)) = imOutt(i,j);
%     end
% end
% 
% 
% imOut4 = imOuttt(2:257,2:257);
% ssd = max(max((abs(imOut4-final))))

