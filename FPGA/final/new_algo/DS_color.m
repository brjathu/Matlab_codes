clear all;
clc;
imIn=uint8((imread('coloredChips.png')));
imIn=imresize(imIn,[256,256]);
final = uint8(zeros(128,128,3));

[m,n,k] =size(imIn);
im=uint8(zeros(m+2,n+2,3));

for i=1:m
    im(i+1,:,:)=[imIn(i,1,:),imIn(i,:,:),imIn(i,256,:)];
end
im(1,:,:)=im(2,:,:);
im(258,:,:)=im(257,:,:);

prompt = 'Enter any key to continue: ';
imshow(final);


x=input(prompt);
a=DownSamplePart(im(:,:,1));
final(:,:,1)=a;
imshow(final);


x=input(prompt);
b=DownSamplePart(im(:,:,2));
final(:,:,2)=b;
imshow(final);


x=input(prompt);
c=DownSamplePart(im(:,:,3));
final(:,:,3)=c;
imshow(final);

