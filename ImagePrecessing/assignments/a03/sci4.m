clear all;
im=im2double(rgb2gray(imread('img/176035.jpg')));
imColor=im2double((imread('img/176035.jpg')));
[m,n]=size(im);

imshow(imColor);
hold on,
[yy xx]=(ginput(1));
xx=round(xx);
yy=round(yy);
while(1)
    x=xx;
    y=yy;

    dImg = double(im);
    [dY, dX] = gradient(dImg);
    dFg = sqrt(dX.^2 + dY.^2);
    dFg = 1 - dFg./max(dFg(:));
    lFz = ~edge(dImg, 'zerocross');
    imCost = 0.1.*double(lFz)+ 0.1.*dFg;
    imCost=imCost/max(max(imCost));
    imVist=zeros(m,n);

    imVist(x,y)=1;
    imVistCost=zeros(m,n,3);

    L=[ [x;y;0]];
    while(length(L))
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
                    if(a<1 | a>m | b<1 | b>n)
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

    [yy xx]=(ginput(1));
    xx=round(xx)
    yy=round(yy)

    
    while (xx~=x & yy~=y)
        if(xx>0 | xx<m |yy>0 | yy<n)
            imColor(xx,yy,1)=255;
            imColor(xx,yy,2)=0;
            imColor(xx,yy,3)=0;
            xtemp=imVistCost(xx,yy,2);
            ytemp=imVistCost(xx,yy,3);
            xx=xtemp;
            yy=ytemp;
        end
        
    end
    imshow(imColor);
    
end
