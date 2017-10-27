a=imread('me.jpg');
gray=rgb2gray(a);
w=3;

m=size(a,1);
l=size(a,2);


newImg=zeros(m,l);
newImg=uint8(newImg);


for i=2:m-1
    for j=2:l-1
        g=gray(i-1:i+1,j-1:j+1);
        g2=zeros(w*w,1);
        for a=1:w
            for b=1:w
               g2(a*w+b)=g(a,b);
            end
        end
        newImg(i,j)=median(g2);
    end
end


subplot(2,2,1);
imshow(gray);

subplot(2,2,2);
imshow(newImg);




