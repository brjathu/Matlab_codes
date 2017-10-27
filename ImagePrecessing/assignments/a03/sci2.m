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
wz = 0.43;
wd = 0.43;
wg = 0.14;
    
fzIm=(conv2(im,lapKer,'same'));
fzIm=fzIm~=0;

gradXIm=conv2(im,gradX,'same');
gradYIm=conv2(im,gradY,'same');
gradIm=sqrt(gradYIm.^2+gradXIm.^2);
fgIm=1-gradIm/max(max(gradIm));

imCost=wz*fzIm+wd*fgIm;




A=[11 13 12 9 5 8 3 1 2 4 10;
14 11 7 4 2 5 8 4 6 3 8;
11 6 3 5 7 9 12 11 10 7 4;
7 4 6 11 13 18 17 14 8 5 2;
6 2 7 10 15 15 21 19 8 3 5;
8 3 4 7 9 13 14 15 9 5 6;
11 5 2 8 3 4 5 7 2 5 9;
12 4 2 1 5 6 3 2 4 8 12;
10 9 7 5 9 8 5 3 7 8 15];
im=A;
imCost=A;
[m n]=size(A);

imVist=zeros(m,n);

x=8;
y=3;
imVist(x,y)=1;
imVistCost=zeros(m,n,3);

L=[ [x;y;0]];
while(length(L))
%     pause,
% %     imVist
% %     L
    imVistCost;
    point=L(:,1);
    L(:,1)=[];

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
                        if(imVistCost(a,b,1)>cost)
                            f=find(L(:,1)==a & L(:,2)==b);
                            imVistCost(a,b,2)=point(1);
                            imVistCost(a,b,3)=point(2);
                            imVistCost(a,b,1)=cost;
                            L(3,f)=cost;
                        end
                    else
                        L=[L [a;b;cost]];
                        imVist(a,b)=1;
                        imVistCost(a,b,2)=point(1);
                        imVistCost(a,b,3)=point(2);
                        imVistCost(a,b,1)=cost;
                    end
                end

            end
            
        end
    end
    [q,w]=sort(L(3,:));
    L=L(:,w);

end

point(1)=x;
point(2)=y;
List=[];
for i=1:10
    pause
    
    [f g]=(find(imVistCost(:,:,2)==point(1) & imVistCost(:,:,3)==point(2)));
    
    for j=1:length(f)
        List=[List [imVistCost(f(j),g(j),1);f(j);g(j)]];
    end
    [cv cb]=sort(List(1,:));
    List=List(:,cb);
    
    List
    point(1)=List(2,1);
    point(2)=List(3,1);
    List=[];
    im(point(1),point(2))=255
    
    
end




% imshow(im);
% 
% while(1)
%     [y x]=(ginput(1));
%     x=round(x)
%     y=round(y)
% 
% end
