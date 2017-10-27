% im=im2double(rgb2gray(imread('butterfly.jpg')));
% [m,n]=size(im);
% imnew= downsample(im,4);
% 
% K=2;
% f=fir1(n,1/K);
% 
% f2=conv2(im,f,'same');
% out=f2(1:K:m,1:K:n);
% 
% out2=im(1:K:m,1:K:n);
% 
% figure,
% imshow(im);
% 
% 
% figure,
% imshow(out);
% 
% 
% figure,
% imshow(out2);






K=2;
im=uint8(zeros(256,256));

for i=1:256
    for j=1:256
        im(i,j) = 255*(mod(i+j,2));
    end
end
w=1
% im=(rgb2gray(imread('butterfly.jpg')));

[m,n]=size(im);

imPad=uint8(zeros(m+2*w,n+2*w));

imPad(1+w:m+w,1+w:n+w)=im(:,:);

% ker = ([       -2 -1  0 -1 -2
%                -1  3  6  3 -1;
%                 0  6  10 6  0;
%                -1  3  6  3 -1;
%                -2 -1  0 -1 -2])
    
ker = uint8([    1  2  1 ;
                 2  4  2 ;
                 1  2  1 ])
             
             
imNew = uint8(zeros(m,n));
for i=1+w:m+w
    for j=1+w:n+w
        imNew(i-w,j-w)=sum(sum(      imPad(i-w:i+w,j-w:j+w).*ker ./sum(sum(ker))  ));
    end
end

out2=imNew(1:K:m,1:K:n);
imshow(out2)


imMatlab= downsample(im,2);
imMatlab= downsample(imMatlab',2);
imMatlab=imMatlab';


ssd= sum(sum(imMatlab.^2 - out2.^2))






