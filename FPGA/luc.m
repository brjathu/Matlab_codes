clc;
clear all;
k = 2;


original_image = im2double(imread('image.jpg'));
original_image = rgb2gray(original_image);               %convert image to grayscale
figure, imshow(original_image),title('Original Image');

%original_image = im2double(original_image);           %for greater arithmetic accuracy
%disp(original_image);
[h,w] = size(original_image);



resized_image = uint8(zeros(256,256));

%averageing process to reduce the size
i = 1;
for row = 2:2:512
    j=1;
    if row ==512 
        x=1;
    else
        x=row+1;
    end
    for column = 2:2:512
        if column ==512
            y=1;
        else
            y=column+1;
        end
        average_value = (2*original_image(row-1,column-1)+4*original_image(row-1,column)+2*original_image(row-1,y)+8*original_image(row,column-1)+32*original_image(row,column)+8*original_image(row,y)+2*original_image(x,column-1)+4*original_image(x,column)+2*original_image(x,y))/64*255
        %average_value = (1*original_image(row-1,column-1)+4*original_image(row-1,column)+1*original_image(row-1,column+1)+4*original_image(row,column-1)+8*original_image(row,column)+4*original_image(row,column+1)+1*original_image(row+1,column-1)+2*original_image(row+1,column)+1*original_image(row+1,column+1))/16;
         
        resized_image(i,j) = average_value;
        j=j+1;
    end

    i = i+1;
end
% disp(resized_image);
%resized_image = uint8(resized_image.*255);           %coverts to unsigned 8bit integers
figure, imshow(resized_image), title('Resized image');