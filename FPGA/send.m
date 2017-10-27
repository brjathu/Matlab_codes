w=1
im=(rgb2gray(imread('butterfly.jpg')));

[m,n]=size(im);

imPad=uint8(zeros(m+2*w,n+2*w));

imPad(1+w:m+w,1+w:n+w)=im(:,:);
    
ker = uint8([    1  1  1 ;
                 1  1  1 ;
                 1  1  1 ])
             
imNew = uint8(zeros(m,n));
for i=1+w:m+w
    for j=1+w:n+w
        imNew(i-w,j-w)=sum(sum(      imPad(i-w:i+w,j-w:j+w).*ker ./sum(sum(ker))  ));
    end
end

out2=imNew(1:K:m,1:K:n);
imshow(out2)








