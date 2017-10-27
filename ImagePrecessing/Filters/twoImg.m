grayme=rgb2gray(imread('me.jpg'));
grayme2=rgb2gray(imread('me2.jpg'));


G=@(x,y,sigma) 1/(2*pi*sigma^2)*exp(-(x^2+y^2)/2/sigma^2);
w=15;
g=zeros(w,w);
g1=zeros(w,w);
for i=1:w
    for j=1:w
        a=i-ceil(w/2);
        b=j-ceil(w/2);
        g(i,j)=G(a,b,5);
        if a==0 &&b==0
            g1(i,j)=1;
        end
    end
end

g=g/sum(sum(g));
g1



G2=5*(g1-g);


subplot(2,2,1);
imshow(grayme2);


subplot(2,2,2);
imshow(imfilter(grayme,g));


subplot(2,2,3);
imshow(imfilter(grayme2,G2));
x=imfilter(grayme,g);
y=imfilter(grayme2,G2);
newImg=x(1:1200, 1:1600)+y;
subplot(2,2,4);
imshow(newImg);


