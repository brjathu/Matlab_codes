function [ ] = histF( img,x )
%HISTF Summary of this function goes here
%   Detailed explanation goes here
a=imread(img);
gray=rgb2gray(a);

binNum=x;
binBounds=linspace(0,255,binNum+1);

hist=zeros(binNum,1);
for i=1:binNum
    hist(i)=sum(sum(gray<=binBounds(i+1)  & gray>=binBounds(i)));
end
binCenters=(binBounds(2:end)+binBounds(1:end-1))/2;
bar(binCenters,hist,0.4);


end

