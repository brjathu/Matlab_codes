clear all;
imgOriginal=imread('../testImg/candy.png');
imgOriginal=rgb2gray(imgOriginal);

[m, l]=size(imgOriginal);

sig=1.2;

%generating gussian filter
G=@(x,y,sigma) 1/(2*pi*sigma^2)*exp(-(x^2+y^2)/2/sigma^2);
w=ceil(6*sig+1);
g=zeros(w,w);
for i=1:w
    for j=1:w
        a=i-ceil(w/2);
        b=j-ceil(w/2);
        g(i,j)=G(a,b,sig);
    end
end
g=g/sum(sum(g));


%derivative filters
Gy=[-1 -1 -1;
    0 0 0;
    1 1 1];

Gx=[-1 0 1;
    -1 0 1;
    -1 0 1];



imgGuss=conv2(imgOriginal,g,'same');
imgDeriX=conv2(imgGuss,Gx,'same');
imgDeriY=conv2(imgGuss,Gy,'same');

imgDeriXX=conv2(imgDeriX.^2,g,'same');
imgDeriYY=conv2(imgDeriY.^2,g,'same');
imgDeriXY=conv2(imgDeriX.*imgDeriY,g,'same');

r=5;
R=(imgDeriXX.*imgDeriYY  - imgDeriXY.^2)-0.06*((imgDeriXX + imgDeriYY).^2) ;



mx=ordfilt2(R,r*r,ones(r,r));



hPoints=(R==mx) & (R>1e7);

[row,colm]=find(hPoints);


x=detectHarrisFeatures(imgOriginal);


imshow(imgOriginal), hold on,
% 
% imshow(imgDeriXX)
% plot(x.selectStrongest(200)); 
 plot(colm,row,'r+');

