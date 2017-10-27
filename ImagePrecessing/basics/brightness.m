clear all
a=imread('me.jpg');
subplot(2,2,1);
imshow(a);


b=rgb2gray(a);
x=45;

newImg=zeros(size(a,1),size(a,2));
newImg=uint8(newImg);
for m=1:size(a,1)
    for l=1:size(a,2)
        if b(m,l)+x>255
            newImg(m,l)=255;
        else
            newImg(m,l)=b(m,l)+x;
        end
        
    end
end

% for m=200:500
%     for l=300:450
%         newImg(m,l)=100;
%         
%     end
% end
imshow(newImg);



br=0;
bg=10;
bb=0;

red=a(:,:,1);
green=a(:,:,2);
blue=a(:,:,3);


for m=1:size(a,1)
    for l=1:size(a,2)
        if red(m,l)+br>255
            red(m,l)=255;
            green(m,l)=255;
            blue(m,l)=255;
        else
            red(m,l)=red(m,l)+br;
            green(m,l)=green(m,l)+bg;
            blue(m,l)=blue(m,l)+bb;
        end
        
    end
end




subplot(2,2,2);
imshow(red);

subplot(2,2,3);
imshow(green);


newImg2=zeros(m,l,3);
newImg2=uint8(newImg2);
newImg2(:,:,1)=red;
newImg2(:,:,2)=green;
newImg2(:,:,3)=blue;


subplot(2,2,4);
imshow(newImg2);




