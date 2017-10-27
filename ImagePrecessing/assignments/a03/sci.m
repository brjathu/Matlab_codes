clear all;
im=im2double(rgb2gray(imread('img/302003.jpg')));
[m n]=size(im);
lapKer=[0 1 0;
        1 -4 1;
        0 1 0];
gradX=[-1 -2 -1;
        0 0 0;
        1 2 1];
gradY=gradX';

fzIm=(conv2(im,lapKer,'same'));
fzIm=fzIm~=0;

gradXIm=conv2(im,gradX,'same');
gradYIm=conv2(im,gradY,'same');
gradIm=sqrt(gradYIm.^2+gradXIm.^2);
fgIm=1-gradIm/max(max(gradIm));

imCost=fzIm+fgIm;




imVist=zeros(m,n);

x=152;
y=133;
imVist(x,y)=1;
imVistCost=zeros(m,n);

L=[ [x;y;0]];
while(length(L))
    point=L(:,1);
    L(:,1)=[];
    im(point(1),point(2))=0;
    for j=-1:1
        for k=-1:1
            
            if(j==0 & k==0)
                
            else
                dis=1;
                if(abs(k*j)==1)
                    dis=sqrt(2);
                end
                a=point(1)+j;
                b=point(2)+k;
                if(a<1 | a>m | b<1 | b>m)
                else
                    cost=point(3)+imCost(a,b)*dis;
                    if(imVist(a,b)==1 )
                        if(imVistCost(a,b)>cost)
                            f=find(L(:,1)==a & L(:,2)==b);
                            L(3,f)=cost;
                        end
                    else
                        L=[L [a;b;cost]];
                        imVist(a,b)=1;
                        imVistCost(a,b)=cost;
                    end
                end

            end
            
        end
    end
    [q,w]=sort(L(3,:));
    L=L(:,w);
    
    
end
imshow(imVist)

