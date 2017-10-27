clear all;
close all;
im=(imread('a01images/im02small.png'));
m=size(im,1)
n=size(im,2)
subplot(1,4,1);
imshow(im);
title('Original')


numBins=255;
binBounds=linspace(0,255,numBins+1);
binCenters = (binBounds(1:end-1)+(binBounds(1)-binBounds(2))/2);
imgNew=zeros(m,n,3);
imgNew=uint8(imgNew);


cumHist=zeros(numBins+1,3);
for i=2:numBins+1
    cumHist(i,1)=sum(sum(im(:,:,1)<=binBounds(i)));
    cumHist(i,2)=sum(sum(im(:,:,2)<=binBounds(i)));
    cumHist(i,3)=sum(sum(im(:,:,3)<=binBounds(i)));
end

hist=zeros(3,numBins);
for i=1:3
    hist(i,:)=cumHist(2:end,i)-cumHist(1:end-1,i);
    hist(i,:)=hist(i,:)/sum(hist(i,:));
    cumHist(:,i)=cumHist(:,i)/(m*n);
    temp=cumHist(:,i);
    imgNew(:,:,i)=uint8(temp(im(:,:,i)+1).*255);
    
end

subplot(1,4,2);
imshow(imgNew);
title('Histogram equalized Image')

subplot(1,4,3);
bar(binCenters,hist(1,:),1);
title('Original Histogram')


cumHistEq=zeros(numBins+1,1);
for i=2:numBins+1
    cumHistEq(i)=sum(sum(imgNew(:,:,1)<=binBounds(i)));
end
histEq=cumHistEq(2:end)-cumHistEq(1:end-1);
histEq=histEq/sum(histEq);
cumHistEq=cumHistEq/(m*n);
subplot(1,4,4);
bar(binCenters,histEq);
title('Equalized Histogram')