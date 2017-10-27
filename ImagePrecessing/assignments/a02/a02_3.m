clear all;
close all;
% im=im2double(imread('a02images/cirateg/a.jpg'));
% bear=im2double(rgb2gray((imread('a02images/cirateg/coc.jpg'))));

im=im2double(rgb2gray((imread('a02images/ciratefi106/2instances/a3.jpg'))));
template=im2double(rgb2gray((imread('a02images/ciratefi106/2instances/q3.ppm'))));

im=imresize(im,1/(2^0.25));
imshow(template);
[m,n]=size(im)
[l,k]=size(template)
imNew=im;

midL=ceil(l/2);
midK=ceil(k/2);
for i=midL+1:m-(l-midL-1)
    for j=midK+1:n-(k-midK-1)
        x=im(i-midL:i+(l-midL-1),j-midK:j+(k-midK-1));
        y=(template-mean(mean(template)));
        a=(x-mean(mean(x))).* y;
        imNew(i,j)=sum(sum(a))/sqrt(sum(sum( a.^2 ))*sum(sum( y.^2 )));
        
    end
end
imNew=(imNew-min(min(imNew)))/(max(max(imNew))-min(min(imNew)));
% b=20;
% c=floor(b/2);
% imNonMax=zeros(m,n);
% for i=c+1:m-(b-c-1)
%     for j=c+1:n-(b-c-1)
%         x=imNew(i-c:i+(b-c-1),j-c:j+(b-c-1));
%         y=max(max(x));
%         if(imNew(i,j)==y)
%             imNonMax(i,j)=imNew(i,j);
%         end
%         
%     end
% end


hLocalMax = vision.LocalMaximaFinder;
hLocalMax.MaximumNumLocalMaxima = 5;
hLocalMax.NeighborhoodSize = [5 5];
hLocalMax.Threshold = 0.98;

location = step(hLocalMax, imNew)
rows=location(:,2)
cols=location(:,1)
     

imshow((im));

hold on,
for i=1:length(rows)
    rectangle('Position',[ cols(i)-midK rows(i)-midL k l], 'LineWidth',2, 'EdgeColor','b');
    im( rows(i)-midL:rows(i)-midL+l ,cols(i)-midK: cols(i)-midK+k)=0;
end
figure,
imshow((im));
title('Original Image')