% clear all;
% close all;
% im=im2double(((imread('DIP3E_Original_Images_CH09/Fig0916(a)(region-filling-reflections).tif'))));
% % im=im2double(((imread('DIP3E_Original_Images_CH09/Fig0916(a)(region-filling-reflections).tif'))));
%    
%    
% w=15;
% [Y,X]=meshgrid(-w:w,-w:w);
% imMorDim=zeros(2*w+1,2*w+1);
% imMorDim=((X.^2+Y.^2)<=w^2);
%   
% % imMorSqr=[1 1 1 ;
% %        1 1 1  ;
% %        1 1 1 ]; 
% 
% % imMorSqr=ones(19,19) ;
%    
% [m,n]=size(im);
% [l,k]=size(imMorDim);
% 
% 
% imPad=zeros(m+floor(l/2)*2,n+floor(k/2)*2);
% imPad(floor(l/2)+1:m+floor(l/2),floor(k/2)+1:n+floor(k/2))=im(:,:);
% 
% imEro=zeros(m+floor(l/2)*2,n+floor(k/2)*2);
% imDil=zeros(m+floor(l/2)*2,n+floor(k/2)*2);
% 
% for i=floor(l/2)+1:m+floor(l/2)
%     for j=floor(k/2)+1:n+floor(k/2)
%         s=sum(sum(imPad(i-floor(l/2):i+floor(l/2),j-floor(k/2):j+floor(k/2)).*imMorDim));
% %         if(s==sum(sum(imMorDim)))
% %             imEro(i,j)=1;
% %         end
%         if(s>0)
%             imDil(i,j)=1;
%         end
%     end
% end
% 
% 
% for i=floor(l/2)+1:m+floor(l/2)
%     for j=floor(k/2)+1:n+floor(k/2)
%         s=sum(sum(imDil(i-floor(l/2):i+floor(l/2),j-floor(k/2):j+floor(k/2)).*imMorDim));
%         if(s==sum(sum(imMorDim)))
%             imEro(i,j)=1;
%         end
% %         if(s>0)
% %             imDil(i,j)=1;
% %         end
%     end
% end
% 
% 
% imDilOut(:,:)=imDil(  floor(l/2)+1:m+floor(l/2),floor(k/2)+1:n+floor(k/2)  );
% imEroOut(:,:)=imEro(  floor(l/2)+1:m+floor(l/2),floor(k/2)+1:n+floor(k/2)  );
% subplot(1,2,1);
% imshow(im);
% title('Orignal Image')
% 
% subplot(1,2,2);
% imshow(imEroOut);
% title('Opening of image');








clear all;
close all;
im=im2double(((imread('DIP3E_Original_Images_CH09/Fig0916(a)(region-filling-reflections).tif'))));
  
imMorDim=[0 1 0 ;
       1 1 1  ;
       0 1 0 ]; 

   
BW3 = bwmorph(im,'skel',Inf);
figure
imshow(BW3)
   
[m,n]=size(im);
[l,k]=size(imMorDim);
% 
% 
% imPad=zeros(m+1*2,n+1*2);
% imPad(1+1:m+1,1+1:n+1)=im(:,:);
% 
% imEro=zeros(m+1*2,n+1*2);
% imDil=zeros(m+1*2,n+1*2);
% 
% for i=1+1:m+1
%     for j=1+1:n+1
%         s=sum(sum(imPad(i-1:i+1,j-1:j+1).*imMorDim));
%         if(s>0)
%             imDil(i,j)=1;
%         end
%     end
% end
% 
% imshow(imDil);
% title('Opening of image');