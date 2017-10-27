% im = rgb2gray(imread('butterfly.jpg'));

im=rgb2gray(imread('butterfly.jpg'));


w=2;


[m,n]=size(im);
imZ= uint8(zeros(m+2*w,n+2*w));
imZ(w+1:m+w,w+1:n+w)=im(:,:);
imNew= uint8(zeros(m+2*w,n+2*w));
imNew2= uint8(zeros(m+2*w,n+2*w));

[Y,X]=meshgrid(-w:w,-w:w);
fil=zeros(2*w+1,2*w+1);


fil= (X.^2+Y.^2)< w^2 ;

fil= uint8(fil);

for j=w+1 : n-w-1
   for i=w+1 : m-w-1
       imNew(i-w:i+w,j-w:j+w) =imNew(i-w:i+w,j-w:j+w) + fil.*im(i,j)/sum(sum(fil));
   end
end
imshow(imNew(w:m+w-1,w:n+w-1))





count=0;
for j=w+1 : n-w-1
   for i=w+1 : m-w-1
       if(sum(sum((imNew(i-w:i+w,j-w:j+w).*fil - fil.*im(i,j)/sum(sum(fil))).*fil >= 0)) == (2*w+1)^2)
%          imNew2(i-w:i+w,j-w:j+w) = imNew2(i-w:i+w,j-w:j+w) + imNew(i-w:i+w,j-w:j+w).*fil - fil.*imNew(i,j)/sum(sum(fil)) ;
           count=count+1
           
           imNew(i-w:i+w,j-w:j+w)  =   imNew(i-w:i+w,j-w:j+w) - fil.*im(i,j)/sum(sum(fil)) ;
           imNew(i,j)=im(i,j);

       end
       
       
   end
end

imshow(imNew)