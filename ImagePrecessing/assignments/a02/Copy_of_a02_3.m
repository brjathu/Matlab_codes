clear all;
close all;

im=im2double(imread('a02images/cirateg/aa.jpg'));
bear=im2double(rgb2gray((imread('a02images/cirateg/b.jpg'))));


imshow(im)
hold on,
rat=0.4;
for j=1:3
    [rows, cols]= temMat(im,bear,0.98);
    [l,k]=size(bear)
    midL=ceil(l/2);
    midK=ceil(k/2);
    hold on,
    for i=1:length(rows)
        rectangle('Position',[ (cols(i)-midK) rows(i)-midL k l].*(2)^((j-1)*rat), 'LineWidth',2, 'EdgeColor','b');
        im( rows(i)-midL:rows(i)-midL+l ,cols(i)-midK: cols(i)-midK+k)=0;
    end
    im=imresize(im,1/(2^rat));
end



