clear all
close all
a=im2double(rgb2gray(imread('../testImg/me.jpg')));
[m,n,l]=size(a);
% imshow(a);


w=2;
sigma=1;
[Y,X]=meshgrid(-w:w,-w:w);
g=exp(-(X.^2+Y.^2)/2/sigma^2);
g=g/sum(sum(g));

imgGuss=conv2(a,g,'same');

Gy=[-1 0 1;-2 0 2; -1 0 1];
Gx=[-1 -2 -1;0 0 0 ; 1 2 1];
imDeriX=conv2(imgGuss,Gx,'same');
imDeriY=conv2(imgGuss,Gy,'same');
imNorm=sqrt(imDeriX.^2+imDeriY.^2);
imNonMax=imNorm;

for i=2:m-1
    for j=2:n-1
        if(imNorm(i,j)==0)
            tan=5;
        else
            tan=imDeriY(i,j)/imDeriX(i,j);
        end
        
        if(-0.4142<tan && tan<=0.4142)
            if(imNorm(i,j)<imNorm(i+1,j) || imNorm(i,j)<imNorm(i-1,j))
                imNonMax(i,j)=0;
            end
        elseif(-2.4142<tan && tan<= -0.4142)
            if(imNorm(i,j)<imNorm(i+1,j-1) || imNorm(i,j)<imNorm(i-1,j+1))
                imNonMax(i,j)=0;
            end
        elseif(0.4142<tan && tan<=2.4142)
            if(imNorm(i,j)<imNorm(i+1,j+1) || imNorm(i,j)<imNorm(i-1,j-1))
                imNonMax(i,j)=0;
            end
        elseif ( abs(tan) >2.4142)
            if(imNorm(i,j)<imNorm(i,j+1) || imNorm(i,j)<imNorm(i,j-1))
                imNonMax(i,j)=0;
            end
        end

        
        
    end
end


imgHyst=imNonMax;
th=0.23;
tl=0.14;


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



for i=2:m-1
    for j=2:l-1
        if(imgHyst(i,j)==2)
            if(imgHyst(i,j+1)==1 || imgHyst(i,j-1)==1 || imgHyst(i+1,j)==1 || imgHyst(i-1,j)==1 || imgHyst(i+1,j+1)==1 ||  imgHyst(i-1,j-1)==1 || imgHyst(i+1,j-1)==1 || imgHyst(i-1,j+1)==1 )
                imgHyst(i,j)==1;

            end
            
            if(imgHyst(i,j)==2)
                imgHyst(i,j)==0;
            end
        end
    end
end



imshow(imgHyst)

            






