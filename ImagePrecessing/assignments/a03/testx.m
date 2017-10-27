clear all;
im=im2double((imread('img/12003.jpg')));
im=im(:,:,3);
% imOut=(im>190);
% imshow(imOut)

x=258;
y=226;

imRed=grow(im,3,x,y);   %18,19,10  //3,2,2

[m,n]=size(im);
q=[[x,y]]
imOut=uint8(zeros(m,n));
val=255;
th=0.01;
while(1)
    len=size(q);
    if(len(1)==0)
        break
    end 
    point=q(1,:);
    if( point(1)>=m-1 || point(1)<=1 || point(2)>=n-1 || point(2)<=1)
        len=size(q);
        q=q(2:len(1),:);
    else
        if(   (im(point(1)+1,point(2))-im(point(1),point(2))<th)  &&  imOut(point(1)+1,point(2))~=val  )
            q=[q; [point(1)+1,point(2)]];
            imOut(point(1)+1,point(2))=val;
        end

        if((im(point(1)-1,point(2))-im(point(1),point(2))<th)    &&  imOut(point(1)-1,point(2))~=val   )
            q=[q; [point(1)-1,point(2)]];
            imOut(point(1)-1,point(2))=val;
        end

        if((im(point(1),point(2)+1)-im(point(1),point(2))<th)  &&  imOut(point(1),point(2)+1)~=val )
            q=[q; [point(1),point(2)+1]];
            imOut(point(1),point(2)+1)=val;
        end

        if((im(point(1),point(2)-1)-im(point(1),point(2))<th)   &&  imOut(point(1),point(2)-1)~=val )
            q=[q; [point(1),point(2)-1]];
            imOut(point(1),point(2)-1)=val;
        end
        len=size(q);
        q=q(2:len(1),:);
    end
end

imshow(imOut);

% hs=5;
% [m n]=size(im)
% imNew=zeros(m+hs-1,n+hs-1);
% imNew((hs-1)/2+1:m+(hs-1)/2,(hs-1)/2+1:n+(hs-1)/2)=im;
% 
% 
% [Y,X]=meshgrid(-(hs-1)/2:(hs-1)/2,-(hs-1)/2:(hs-1)/2)
% 
% G=exp(-(X.^2+Y.^2));
% G=G/sum(sum(G))
% 
% imScale=zeros(m+hs-1,n+hs-1);
% for i=(hs-1)/2+1:m+(hs-1)/2
%     for j=(hs-1)/2+1:n+(hs-1)/2
%         imScale(i-(hs-1)/2:i+(hs-1)/2,j-(hs-1)/2:j+(hs-1)/2)=imScale(i-(hs-1)/2:i+(hs-1)/2,j-(hs-1)/2:j+(hs-1)/2)+G.*imNew(i-(hs-1)/2:i+(hs-1)/2,j-(hs-1)/2:j+(hs-1)/2);
%     end
% end
% 
% imOut=imScale/(max(max(imScale)));
% imOutColor=zeros(m+hs-1,n+hs-1,3);
% imOutNew=zeros(m+hs-1,n+hs-1);
% figure,
% imshow(im)
% figure,
% imshow(imOut);
% 
% for i=(hs-1)/2+1:m+(hs-1)/2
%     for j=(hs-1)/2+1:n+(hs-1)/2
%         
%         p=[i j];
%         init=p;
%         
%             
%             while(1)
%                 
%                 if( p(1)<(hs-1)/2+1 | p(1)>m+(hs-1)/2 |  p(2)<(hs-1)/2+1 | p(2)>n+(hs-1)/2)
%                     break
%                 else
% 
%                     a=imOut(p(1)-(hs-1)/2:p(1)+(hs-1)/2,p(2)-(hs-1)/2:p(2)+(hs-1)/2).*X;
%                     b=imOut(p(1)-(hs-1)/2:p(1)+(hs-1)/2,p(2)-(hs-1)/2:p(2)+(hs-1)/2).*Y;
%                     ca=sum(sum(a))/sum(sum(imOut(p(1)-(hs-1)/2:p(1)+(hs-1)/2,p(2)-(hs-1)/2:p(2)+(hs-1)/2)));
%                     cb=sum(sum(b))/sum(sum(imOut(p(1)-(hs-1)/2:p(1)+(hs-1)/2,p(2)-(hs-1)/2:p(2)+(hs-1)/2)));
% 
%                     if(abs(p(1)-round(ca))<=2 & abs(p(2)-round(cb))<=2)
%                         break
%                     end
%                     p(1)=round(ca);
%                     p(2)=round(cb);
% 
%                 end
%                
%             end
%             if( ~(p(1)<(hs-1)/2+1 | p(1)>m+(hs-1)/2 |  p(2)<(hs-1)/2+1 | p(2)>n+(hs-1)/2))
%                 imOutNew(init(1),init(2))=im(p(1),p(2));
%                 display('changed!');
%             end
%     end
% end
% imOutNew=imOutNew((hs-1)/2+1:m+(hs-1)/2,(hs-1)/2+1:n+(hs-1)/2).*255;
% imOutColor=uint8(imOutColor.*255);
% figure,
% imshow(imOutNew*5)

