function [] = populateBranchCost()
    global vert horz diag1 diag2 image
    %define four kernels to calculate the branch costs
    vertK = 0.25*[1 0 -1;1 0 -1];
    horzK = vertK';
    diag1K = [1 0; 0 -1]/sqrt(2);
    diag2K = [0 1; -1 0]/sqrt(2);
    %the following four matrices will have the costs of the 
    %vertical, horizontal, and the diagonal branches
    vert = conv2(image,vertK);
    horz = conv2(image,horzK);
    diag1 = conv2(image,diag1K);
    diag2 = conv2(image,diag2K);
    %negate the result :- a higher gradient implies lower cost
    vert = 1-abs(vert(1:size(image,1),2:size(image,2)+1));  
    horz = 1-abs(horz(2:size(image,1)+1,1:size(image,2)));
    diag1 = 1-abs(diag1(1:size(image,1),2:size(image,2)+1))+0.3;
    diag2 = 1-abs(diag2(2:size(image,1)+1,1:size(image,2)))+0.3;    
end

