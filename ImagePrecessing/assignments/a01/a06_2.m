close all;
clear all;
A=(imread('a01images/im06small.png'));
ang=-60;
rotMat = [cos((pi.*ang/180)) sin((pi.*ang/180)); -sin((pi.*ang/180)) cos((pi.*ang/180))];
centerW = round(size(A,1)/2);
centerH = round(size(A,2)/2);


r=ceil(sqrt(centerW^2+centerH^2));


h= uint8(zeros(2*r,2*r,3));
centerWnew = round(size(h,1)/2);
centerHnew = round(size(h,2)/2);
r=ceil(sqrt(centerW^2+centerH^2));

for x = 1:size(A,1)
    for y = 1:size(A,2)
        point =[x-centerW;y-centerH] ;
        product = rotMat * point;
        product = int16(product);
        newx =product(1,1);
        newy=product(2,1);
            if newx+centerWnew<=size(h,1) && newx+centerWnew > 0 && newy+centerHnew<=size(h,2) && newy+centerHnew > 0 
               h(newx+centerWnew,newy+centerHnew,:) = A(x,y,:);
            end
    end
end

g=[1 1 1;1 0 1;1 1 1];
g=g/8;
h=im2double(h);
for i=2:size(h,1)-1
    for j=2:size(h,2)-1
        if(h(i,j,1)==0 && h(i,j,2)==0 && h(i,j,3)==0)
            h(i,j,1)=uint8(sum(sum( h(i-1:i+1,j-1:j+1,1).*g )));
            h(i,j,2)=uint8(sum(sum( h(i-1:i+1,j-1:j+1,2).*g )));
            h(i,j,3)=uint8(sum(sum( h(i-1:i+1,j-1:j+1,3).*g )));
        end
    end
end

imshow(h);