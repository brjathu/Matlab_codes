a=imread('ein.png');
gray=rgb2gray(a);
g=[0 0 0;
    0 1 0;
    0 0 0];


m=size(a,1);
l=size(a,2);


newImg=zeros(m,l);
newImg=uint8(newImg);


for i=2:m-1
    for j=2:l-1
        for a=1:3
            for b=1:3
                c=a-2;
                d=b-2;
                newImg(i,j)=newImg(i,j)+  gray(i-c,j-d)*g(a,b);  
            end
        end
    end
end


subplot(2,2,1);
imshow(gray);

subplot(2,2,2);
imshow(newImg);

newImg2=zeros(m,l);
newImg2=uint8(newImg2);

newImg2=imfilter(gray,g);

subplot(2,2,3);

imshow(newImg2);




