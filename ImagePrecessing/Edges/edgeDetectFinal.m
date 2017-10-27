clear all;
imgOriginal=imread('../testImg/girl.png');
imgOriginal=im2double(imgOriginal(:,:,1));

[m, l]=size(imgOriginal);



sig=1.2;

%generating gussian filter
G=@(x,y,sigma) 1/(2*pi*sigma^2)*exp(-(x^2+y^2)/2/sigma^2);
w=ceil(6*sig+1);
g=zeros(w,w);
for i=1:w
    for j=1:w
        a=i-ceil(w/2);
        b=j-ceil(w/2);
        g(i,j)=G(a,b,sig);
    end
end
g=g/sum(sum(g));


%derivative filters
Gy=[-1 -2 -1;
    0 0 0;
    1 2 1];

Gx=[-1 0 1;
    -2 0 2;
    -1 0 1];

imgGuss=conv2(imgOriginal,g);
imgDeriX=conv2(imgGuss,Gx);
imgDeriY=conv2(imgGuss,Gy);
imgNorm=sqrt(imgDeriX.^2+imgDeriY.^2);
imgTangent=zeros(m,l);
imgNonMax=imgNorm;
for i=2:m-1
    for j=2:l-1
        if(imgNorm(i,j)==0)
            imgTangent(i,j)=5;
            tang=5;
        else
            tang=imgDeriY(i,j)/imgDeriX(i,j);
        end
        
        if (-0.4142<tang && tang<=0.4142)
            if(imgNorm(i,j)<imgNorm(i,j+1) || imgNorm(i,j)<imgNorm(i,j-1))
                imgNonMax(i,j)=0;
            end
        
        
        elseif (-2.4142<tang && tang<= -0.4142)
            if(imgNorm(i,j)<imgNorm(i-1,j+1) || imgNorm(i,j)<imgNorm(i+1,j-1))
                imgNonMax(i,j)=0;
            end
        
       elseif (0.4142<tang && tang<=2.4142)
            if(imgNorm(i,j)<imgNorm(i-1,j-1) || imgNorm(i,j)<imgNorm(i+1,j+1))
                imgNonMax(i,j)=0;
            end
        
        elseif ( abs(tang) >2.4142)
            if(imgNorm(i,j)<imgNorm(i-1,j) || imgNorm(i,j)<imgNorm(i+1,j))
                imgNonMax(i,j)=0;
            end
      
        end
        
    end
end


imgHyst=imgNonMax;
th=0.19;
tl=0.10;

imgTH=im2bw(imgHyst,th);
imgTL=im2bw(imgHyst,tl);

for i=1:m
    for j=1:l
        if (imgHyst(i,j)>=th)
            imgHyst(i,j)=1;
        end
        if (imgHyst(i,j)<th && imgHyst(i,j)>=tl)
            imgHyst(i,j)=2;
        end
        
        if (imgHyst(i,j)<tl)
            imgHyst(i,j)=0;
        end
    end
end

v=1;

for i=2:m-1
    for j=2:l-1
        if(imgHyst(i,j)==2)
            if(imgHyst(i,j+1)==1 || imgHyst(i,j-1)==1 || imgHyst(i+1,j)==1 || imgHyst(i-1,j)==1 || imgHyst(i+1,j+1)==1 ||  imgHyst(i-1,j-1)==1 || imgHyst(i+1,j-1)==1 || imgHyst(i-1,j+1)==1 )
                imgHyst(i,j)==1;

            end
        end
    end
end

for i=2:m-1
    for j=2:l-1
        if(imgHyst(i,j)==2)
            imgHyst(i,j)==0;
        end
    end
end


imshow(imgHyst)

            



