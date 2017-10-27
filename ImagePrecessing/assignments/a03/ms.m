clear all;
im=im2double((imread('img/12003.jpg')));

X = reshape(im,size(im,1)*size(im,2),3);
dataPts=X';
bandWidth=0.2;
bandSq=bandWidth^2;
[numDim,numPts] = size(dataPts);
initPtInds      = 1:numPts;
numInitPts      = numPts;  
stopThresh      = 1e-3*bandWidth;  
clustCent       = []; 
clusterVotes    = zeros(1,numPts,'uint16');  
beenVisitedFlag = zeros(1,numPts,'uint8'); 
numClust        = 0;


while numInitPts
    (numInitPts)
    tempInd         = ceil( (numInitPts-1e-6)*rand); 
    stInd           = initPtInds(tempInd);
    
    myMean          = dataPts(:,stInd);
    myMembers       = [];  
    thisClusterVotes    = zeros(1,numPts,'uint16');  
    while(1)
        sqDistToAll = sum((repmat(myMean,1,numPts) - dataPts).^2);
        inInds      = find(sqDistToAll < bandSq);
        thisClusterVotes(inInds) = thisClusterVotes(inInds)+1;
        
        
        myOldMean   = myMean;
        myMean      = mean(dataPts(:,inInds),2);
        myMembers   = [myMembers inInds];
        beenVisitedFlag(myMembers) = 1;
        
        
         %**** if mean doesn't move much stop this cluster ***
        if norm(myMean-myOldMean) < stopThresh
            
            %check for merge posibilities
            mergeWith = 0;
            for cN = 1:numClust
                distToOther = norm(myMean-clustCent(:,cN));     %distance from posible new clust max to old clust max
                if distToOther < bandWidth/2                    %if its within bandwidth/2 merge new and old
                    mergeWith = cN;
                    break;
                end
            end
            
            
            if mergeWith > 0    % something to merge
                clustCent(:,mergeWith)       = 0.5*(myMean+clustCent(:,mergeWith));             %record the max as the mean of the two merged (I know biased twoards new ones)
                %clustMembsCell{mergeWith}    = unique([clustMembsCell{mergeWith} myMembers]);   %record which points inside 
                clusterVotes(mergeWith,:)    = clusterVotes(mergeWith,:) + thisClusterVotes;    %add these votes to the merged cluster
            else    %its a new cluster
                numClust                    = numClust+1;                   %increment clusters
                clustCent(:,numClust)       = myMean;                       %record the mean  
                %clustMembsCell{numClust}    = myMembers;                    %store my members
                clusterVotes(numClust,:)    = thisClusterVotes;
            end

            break;
        end
    end
    initPtInds      = find(beenVisitedFlag == 0);           %we can initialize with any of the points not yet visited
    numInitPts      = length(initPtInds);    

    
end


[val,data2cluster] = max(clusterVotes,[],1);                %a point belongs to the cluster with the most votes

%*** If they want the cluster2data cell find it for them

cluster2dataCell = cell(numClust,1);
for cN = 1:numClust
    myMembers = find(data2cluster == cN);
    cluster2dataCell{cN} = myMembers;
end


for i = 1:length(cluster2dataCell)                                              % Replace Image Colors With Cluster Centers
X(cluster2dataCell{i},:) = repmat(clustCent(:,i)',size(cluster2dataCell{i},2),1); 
end

Ims = reshape(X,size(im,1),size(im,2),3); 

imshow(Ims)
