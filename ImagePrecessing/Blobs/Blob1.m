clear all;
close all;
imgOriginal=rgb2gray(imread('../testImg/coin.jpg'));
imgOriginal1=(imgOriginal);
imgOriginal=histeq(imgOriginal);
imgOriginal=cast(imgOriginal,'double');
imgOriginal=imgOriginal.*1.0/255.0;

[m, l]=size(imgOriginal);

sig=10;
sigbegin=sig;
n=10;
rate=2^(0.25);

scaleSpace=zeros(m,l,n);

w=min(ceil(3*sig),500);
[x, y] = meshgrid(-w:w, -w:w);
g=exp(-(x.^2+y.^2)/2/sig^2);
g=g/sum(sum(g));
imgGuss1=imfilter(imgOriginal, g,'same','replicate');
    
    
for k=1:n
    k        
    sig=rate*sig;

    w=min(ceil(3*sig),500);
    [x, y] = meshgrid(-w:w, -w:w);
    g=exp(-(x.^2+y.^2)/2/sig^2);
    g=g/sum(sum(g));
    imgGuss2=imfilter(imgOriginal, g,'same','replicate');
    
%     LoG=imfilter(g,kernel,'same','replicate');    
%     LoG=LoG.*sig^2;
%     sig=k*sig;
%     imgLoG=imfilter(imgOriginal, kernel,'same','replicate');
    
    scaleSpace(:,:,k)=imgGuss2-imgGuss1;
    imgGuss1=imgGuss2;
end

scaleSpace=scaleSpace.^2;
scaleSpaceBegin=scaleSpace;


for z=1:1:n
    scaleSpace(:,:,z) =ordfilt2(scaleSpaceBegin(:,:,z),9,ones(3));
    
end

for i = 1:n
    scaleSpace(:,:,i) = max(scaleSpace(:,:,max(i-1,1):min(i+1,n)),[],3);
end
scaleSpace = scaleSpace .* (scaleSpace == scaleSpaceBegin);


imshow(imgOriginal1);
tot=0;
hold on;
for i=1:n
    [rows, cols] = find(scaleSpace(:,:,i) >=0.002);
    numBlobs = length(rows);
    tot=tot+numBlobs;
    numBlobs;
    plot(cols,rows,'r+');
    t=0:0.1:2*pi;
    radi =  sigbegin * rate^(i-1) * sqrt(2); 
    for h=1:numBlobs
        x =cols(h)  + radi*cos(t);
        y =rows(h)  + radi*sin(t);
        plot(x,y,'r');
    end
end
