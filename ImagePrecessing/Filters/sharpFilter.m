g1=[0 0 0;
    0 1 0;
    0 0 0];

g2=[1 1 1;
    1 1 1;
    1 1 1];


g2=g2/9;

G=g1+2*(g1-g2);

a=imread('me.jpg');
gray=rgb2gray(a);


subplot(2,2,1);
imshow(gray);


subplot(2,2,2);
newImg2=imfilter(gray,G);
% imshow(convTwoFun(a,G));
imshow(newImg2);



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

G2=g1+2*(g1-g);

subplot(2,2,3);
imshow(imfilter(gray,G2));