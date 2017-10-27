G=@(x,y,sigma) 1/(2*pi*sigma^2)*exp(-(x^2+y^2)/2/sigma^2);
w=3;
g=zeros(w,w);
for i=1:w
    for j=1:w
        a=i-ceil(w/2);
        b=j-ceil(w/2);
        g(i,j)=G(a,b,2);
    end
end
g
g=g/sum(sum(g));

g2=[1 1 1;
    1 1 1;
    1 1 1];

g2=g2/9;



a=imread('me.jpg');
gray=rgb2gray(a);

subplot(2,2,1);
imshow(gray);


subplot(2,2,2);
imshow(imfilter(gray,g2));
% imshow(convTwoFun(a,g));

subplot(2,2,3);
imshow(imfilter(gray,g));

