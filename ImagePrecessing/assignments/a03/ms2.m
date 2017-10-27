clear all;
im=im2double((imread('3.jpg')));
X = reshape(im,size(im,1)*size(im,2),3);
dataPts=X';
copy=zeros(3,size(im,1)*size(im,2));
bandWidth=0.1;
bandSq=bandWidth^2;
[numDim,numPts] = size(dataPts);
stopThresh      = 1e-3*bandWidth;  
clustCent       = []; 
VisitedFlag = zeros(1,numPts); 
new=VisitedFlag;
x=1;

while(length(new)~=0)  
    length(new)
    myMean          = dataPts(:,x);
    myMembers=[x];
    while(1)
        sqDistToAll = sum((repmat(myMean,1,numPts) - dataPts).^2);
        inInds      = find(sqDistToAll < bandSq);
        inIndMember      = find(sqDistToAll < bandSq/2);
        
        myOldMean   = myMean;
        myMean      = mean(dataPts(:,inInds),2);
        myMembers=[myMembers inIndMember];
        
        if norm(myMean-myOldMean) < stopThresh
            
            merge=0;
            for k=1:size(clustCent,2)
                if(norm(clustCent(:,k)-myMean)<bandWidth/2)
                    merge=1;
                    break
                end
            end
            
            if(merge==1)
                clustCent(:,k)=(clustCent(:,k)+myMean)/2;
                copy(:,myMembers)=repmat(clustCent(:,k),1,length(myMembers));
                
            else
                clustCent=[clustCent myMean];
                copy(:,myMembers)=repmat(myMean,1,length(myMembers));
            end
            
            copy(:,x)=myMean;
            VisitedFlag(myMembers) = 1;
            break;
        end
    end
    
        new=find(VisitedFlag==0);
        if(length(new)~=0)
            x=new(ceil((length(new))*rand));
        end
end


Ims = reshape(copy',size(im,1),size(im,2),3); 
figure,
imshow(Ims)
