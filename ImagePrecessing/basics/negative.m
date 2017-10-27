clear all
close all

a=imread('me.jpg');
red=a(:,:,1);
green=a(:,:,2);
blue=a(:,:,3);

imNew=zeros(size(a,1),size(a,2),3);
imNew=uint8(imNew);

for m=1:size(a,1)
    for l=1:size(a,2)
      imNew(m,l,1)=255-red(m,l);
      imNew(m,l,2)=255-green(m,l);
      imNew(m,l,3)=255-blue(m,l);
    end
end

imshow(imNew);

