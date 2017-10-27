    for u=1:5   % dfferent U infinity  
     colorstflex = 'kbgrm';
     figure(u); cla;  %% for diffrent RE
     plotStyle = {'-o','-*','-r.','-s','-^'};
     hold on
     for k=1:3   
     Vel_rel(Vel_rel == 0) = NaN;
     x_Dmat = repmat(x_D,[5 1]);
     plot(x_Dmat,Vel_rel(u,:,k),plotStyle{k},'color',colorstflex(k));hold on
     legendInfo{k}=['flex no. ', num2str(k)]); % or whatever is appropriate
     legend(legendInfo)
end 
end 