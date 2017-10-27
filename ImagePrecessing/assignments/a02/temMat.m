function [rows,cols ] = temMat(im,bear,th )

[m,n]=size(im)
[l,k]=size(bear)
imNew=im;

midL=ceil(l/2);
midK=ceil(k/2);
for i=midL+1:m-(l-midL-1)
    for j=midK+1:n-(k-midK-1)
        x=im(i-midL:i+(l-midL-1),j-midK:j+(k-midK-1));
        y=(bear-mean(mean(bear)));
        a=(x-mean(mean(x))).* y;
        if(sum(sum(a))~=0 && sum(sum(y))~=0)
            imNew(i,j)=sum(sum(a))/sqrt(sum(sum( a.^2 ))*sum(sum( y.^2 )));
        else
            imNew(i,j)=0
        end
        
    end
end

imNew=(imNew-min(min(imNew)))/(max(max(imNew))-min(min(imNew)));
% imNew=im2bw(imNew,th);
% b=20;
% c=floor(b/2);
% imNonMax=zeros(m,n);
% for i=c+1:m-(b-c-1)
%     for j=c+1:n-(b-c-1)
%         x=imNew(i-c:i+(b-c-1),j-c:j+(b-c-1));
%         y=max(max(x));
%         if(imNew(i,j)==y)
%             imNonMax(i,j)=imNew(i,j);
%         end
%         
%     end
% end

hLocalMax = vision.LocalMaximaFinder;
      hLocalMax.MaximumNumLocalMaxima = 3;
      hLocalMax.NeighborhoodSize = [5 5];
      hLocalMax.Threshold = th;

      location = step(hLocalMax, imNew)
      rows=location(:,2)
      cols=location(:,1)

end

