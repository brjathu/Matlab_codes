clear all;
close all;
im=im2double(imread('a01images/im04small.png'));
m=size(im,1)
n=size(im,2)
subplot(1,2,1);
imshow(im);
title('Original Image')


w=5;
sigma=5;
[Y,X]=meshgrid(-w:w,-w:w);
g=exp(-(X.^2+Y.^2)/2/sigma);
g=g/sum(sum(g));

imgNew=zeros(m,n,3);
imgNew=im;

% for i=w+1:m-w
%     for j=w+1:n-w
%         sum=0;
%         for k=-w:w
%             for l=-w:w
%                 sum=sum+im(i+k,j+k)*g(k+w+1,l+w+1);
%             end
%         end  
%         imgNew(i,j)=sum;
%     end
% end


for i=w+1:m-w
    for j=w+1:n-w
        imgNew(i,j,1)=sum(sum(im(i-w:i+w,j-w:j+w,1).*g));
        imgNew(i,j,2)=sum(sum(im(i-w:i+w,j-w:j+w,2).*g));
        imgNew(i,j,3)=sum(sum(im(i-w:i+w,j-w:j+w,3).*g));
    end
end


subplot(1,2,2);
imshow(imgNew);
title('Blured Image')


