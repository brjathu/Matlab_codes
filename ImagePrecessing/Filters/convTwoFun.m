function [ x ] = convTwoFun( a,g )
%CONVTWOFUN Summary of this function goes here
%   Detailed explanation goes here

% a=imread(im);
gray=rgb2gray(a);
% g=[0 0 0;
%     0 1 0;
%     0 0 0];
% g=g/sum(sum(g));
m=size(a,1);
l=size(a,2);


newImg=zeros(m,l);
newImg=uint8(newImg);


for i=2:m-1
    for j=2:l-1
        for a=1:3
            for b=1:3
                c=a-2;
                d=b-2;
                newImg(i,j)=newImg(i,j)+  gray(i-c,j-d)*g(a,b);  
            end
        end
    end
end


x=newImg;




end

