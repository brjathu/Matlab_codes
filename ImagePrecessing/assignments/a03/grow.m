function [ imOut ] = grow(im, th,x,y)
%GROW Summary of this function goes here
%   Detailed explanation goes here

[m,n]=size(im);
q=[[x,y]]
imOut=zeros(m,n);
val=255;

while(1)
    len=size(q);
    if(len(1)==0)
        break
    end 
    point=q(1,:);
    if( point(1)>=m-1 | point(1)<=1 | point(2)>=n-1 | point(2)<=1)
        len=size(q);
        q=q(2:len(1),:);
    else
        if(   (im(point(1)+1,point(2))-im(point(1),point(2))<th)  &  imOut(point(1)+1,point(2))~=val  )
            q=[q; [point(1)+1,point(2)]];
            imOut(point(1)+1,point(2))=val;
        end

        if((im(point(1)-1,point(2))-im(point(1),point(2))<th)    &  imOut(point(1)-1,point(2))~=val   )
            q=[q; [point(1)-1,point(2)]];
            imOut(point(1)-1,point(2))=val;
        end

        if((im(point(1),point(2)+1)-im(point(1),point(2))<th)  &  imOut(point(1),point(2)+1)~=val )
            q=[q; [point(1),point(2)+1]];
            imOut(point(1),point(2)+1)=val;
        end

        if((im(point(1),point(2)-1)-im(point(1),point(2))<th)   &  imOut(point(1),point(2)-1)~=val )
            q=[q; [point(1),point(2)-1]];
            imOut(point(1),point(2)-1)=val;
        end
        len=size(q);
        q=q(2:len(1),:);
    end
end



end

