clear all;
close all;
im=imread('a01images/im03small.png');
m=size(im,1)
n=size(im,2)
subplot(1,4,1);
imshow(im);
title('Original')

numBins=20;
binBounds=linspace(0,255,numBins+1);
binCenters = (binBounds(1:end-1)+(binBounds(1)-binBounds(2))/2);

cumHist=zeros(numBins+1,3);
for i=2:numBins+1
    cumHist(i,1)=sum(sum(im(:,:,1)<=binBounds(i)));
    cumHist(i,2)=sum(sum(im(:,:,2)<=binBounds(i)));
    cumHist(i,3)=sum(sum(im(:,:,3)<=binBounds(i)));
end

histRed=cumHist(2:end,1)-cumHist(1:end-1,1);
histRed=histRed/sum(histRed);
subplot(1,4,2);
bar(binCenters(2:numBins-1),histRed(2:numBins-1),1,'red');
title('Red Histogram')

histGreen=cumHist(2:end,2)-cumHist(1:end-1,2);
histGreen=histGreen/sum(histGreen);
subplot(1,4,3);
bar(binCenters(2:numBins-1),histGreen(2:numBins-1),1,'green');
title('Green Histogram')

histBlue=cumHist(2:end,3)-cumHist(1:end-1,3);
histBlue=histBlue/sum(histBlue);
subplot(1,4,4);
bar(binCenters(2:numBins-1),histBlue(2:numBins-1),1,'blue');
title('Blue Histogram')



