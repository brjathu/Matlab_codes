%derivative filter
Gy=[-1 -2 -1;
    0 0 0;
    1 2 1];

Gx=[-1 0 1;
    -2 0 2;
    -1 0 1];


%generating gussian filter
G=@(x,y,sigma) 1/(2*pi*sigma^2)*exp(-(x^2+y^2)/2/sigma^2);
w=5;
g=zeros(w,w);
for i=1:w
    for j=1:w
        a=i-ceil(w/2);
        b=j-ceil(w/2);
        g(i,j)=G(a,b,1);
    end
end
g=g/sum(sum(g));


a=imread('../testImg/me.jpg');
gray=rgb2gray(a);
[m, l]=size(gray);


newImg=mat2gray(conv2(gray,g));



subplot(2,2,1);
% imshow(gray);
imshow(edge(newImg,'canny'));
title('original Image');


subplot(2,2,2);

imshow(newImg);
title('gussinan filtered');



newImgY=(conv2(newImg,Gy));
newImgX=(conv2(newImg,Gx));








newImgNorm=((abs(newImgY)+abs(newImgX)));
newImgNorm=im2double(newImgNorm);


% newImgNorm=newImgNorm.^(1/2);
% newImgNorm=mat2gray(newImgNorm);
% imshow(newImg4);

% imshow(edge(gray,'canny'));



newImgTheta=zeros(m,l);
% newImgTheta=uint8(newImgTheta);
% newImgTheta=abs(atan(im2double(newImgY)./im2double(newImgX)));

newImgThetaN=zeros(m,l);
% newImgThetaN=uint8(newImgThetaN);
newImgNM=zeros(m,l);

for i=1:m
    for j=1:l
        newImgTheta(i,j)=(180/pi*atan((newImgY(i,j)/newImgX(i,j))));
        
        if ((newImgTheta(i,j)>=0 && newImgTheta(i,j)<=22.5) || (newImgTheta(i,j)>=-22.5 && newImgTheta(i,j)<=0))
            newImgThetaN(i,j)=0;
        end
        
        if ((newImgTheta(i,j)>=22.5 &&newImgTheta(i,j)<=67.5) )
            newImgThetaN(i,j)=45;
        end
        
        
        if ((newImgTheta(i,j)>=67.5 &&newImgTheta(i,j)<=90) || (newImgTheta(i,j)<=-67.5 &&newImgTheta(i,j)>=-90))
            newImgThetaN(i,j)=90;
        end
        
        if ((newImgTheta(i,j)<=-22.5 &&newImgTheta(i,j)>=-67.5) )
            newImgThetaN(i,j)=135;
        end
        
        % non maximum suppersion
        
        if (newImgThetaN(i,j)==0)
            if (newImgNorm(i,j)<newImgNorm(i+1,j) || newImgNorm(i,j)<newImgNorm(i-1,j))
                newImgNM(i,j)=0;
            else
                newImgNM(i,j)=newImgNorm(i,j);
            end
        end
        
        if (newImgThetaN(i,j)==45)
            if (newImgNorm(i,j)<newImgNorm(i+1,j+1) || newImgNorm(i,j)<newImgNorm(i-1,j-1))
                newImgNM(i,j)=0;
            else
                newImgNM(i,j)=newImgNorm(i,j);
            end
        end
        
        if (newImgThetaN(i,j)==90)
            if (newImgNorm(i,j)<newImgNorm(i,j+1) || newImgNorm(i,j)<newImgNorm(i,j-1))
                newImgNM(i,j)=0;
            else
                newImgNM(i,j)=newImgNorm(i,j);
            end
        end
        
        if (newImgThetaN(i,j)==135)
            if (newImgNorm(i,j)<newImgNorm(i-1,j+1) || newImgNorm(i,j)<newImgNorm(i+1,j-1))
                newImgNM(i,j)=0;
            else
                newImgNM(i,j)=newImgNorm(i,j);
            end
        end
        
    end
end






newImgH=zeros(m,l);
newImgL=zeros(m,l);
th=0.2;
% for i=1:m
%     for j=1:l
%         if (newImgNM(i,j)>th)
%             newImgH(i,j)=newImgNM(i,j);
%         end
%         
%         if (newImgNM(i,j)>th/6)
%             newImgL(i,j)=newImgNM(i,j);
%         end
%     end
% end

newImgH=im2bw(newImgNM,th);
newImgL=im2bw(newImgNM,0.1);
subplot(2,2,3);
imshow(newImgH);
 
subplot(2,2,4);           
imshow(newImgL | newImgH);











