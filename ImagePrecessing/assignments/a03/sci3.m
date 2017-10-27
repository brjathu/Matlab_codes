clear all;
im=im2double(rgb2gray(imread('img/176035.jpg')));
[m,n]=size(im);
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
    
% fzIm=(conv2(im,lapKer,'same'));
% fzIm=fzIm~=0;
% 
% gradXIm=conv2(im,gradX,'same');
% gradYIm=conv2(im,gradY,'same');
% gradIm=sqrt(gradYIm.^2+gradXIm.^2);
% fgIm=1-gradIm/max(max(gradIm));
% 
% imCost=wz*fzIm+wd*fgIm;

while(1)
    imshow(im);
    [y x]=(ginput(1));
        x=round(x)
        y=round(y)
    % The gradient strength cost Fg
    dImg = double(im);
    [dY, dX] = gradient(dImg);
    dFg = sqrt(dX.^2 + dY.^2);
    dFg = 1 - dFg./max(dFg(:));
    
    % The zero-crossing cost Fz
    lFz = ~edge(dImg, 'zerocross');

    % The Sum:

    imCost = 0.2.*double(lFz)+ 0.2.*dFg;



    imVist=zeros(m,n);

    % x=68;
    % y=249;
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

    point(1)=x;
    point(2)=y;
    
    
    List=[];
    while(1)

        [f g]=(find(imVistCost(:,:,2)==point(1) & imVistCost(:,:,3)==point(2)));

        for j=1:length(f)
            List=[List [imVistCost(f(j),g(j),1);f(j);g(j)]];
        end
        if(length(List)==0)
            break
        end
        [cv cb]=sort(List(1,:));
        List=List(:,cb);

        point(1)=List(2,1);
        point(2)=List(3,1);
        List=[];
        im(point(1),point(2))=255;


    end
    imshow(im);
    
end
