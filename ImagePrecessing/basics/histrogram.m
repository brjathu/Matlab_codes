a=imread('me.jpg');
m=size(a,1);
l=size(a,2);

red=a(:,:,1);
green=a(:,:,1);
blue=a(:,:,1);

gray=rgb2gray(a);
binNum=255 ;
binBounds=linspace(0,255,binNum+1);

hist=zeros(binNum,1);
for i=1:binNum
    hist(i)=sum(sum(gray<=binBounds(i+1)  & gray>=binBounds(i)));
end
binCenters=(binBounds(2:end)+binBounds(1:end-1))/2;
bar(binCenters,hist,0.4);
