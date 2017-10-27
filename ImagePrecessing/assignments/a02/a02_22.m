clear all;
close all;
im=im2double(((imread('DIP3E_Original_Images_CH09/Fig0916(a)(region-filling-reflections).tif'))));
% im=im2double(((imread('DIP3E_Original_Images_CH09/Fig0916(a)(region-filling-reflections).tif'))));
   


imPad=zeros(m+floor(l/2)*2,n+floor(k/2)*2);
imPad(floor(l/2)+1:m+floor(l/2),floor(k/2)+1:n+floor(k/2))=im(:,:);

imEro=zeros(m+floor(l/2)*2,n+floor(k/2)*2);
imDil=zeros(m+floor(l/2)*2,n+floor(k/2)*2);

for i=floor(l/2)+1:m+floor(l/2)
    for j=floor(k/2)+1:n+floor(k/2)
        s=sum(sum(imPad(i-floor(l/2):i+floor(l/2),j-floor(k/2):j+floor(k/2)).*imMorDim));
%         if(s==sum(sum(imMorDim)))
%             imEro(i,j)=1;
%         end
        if(s>0)
            imDil(i,j)=1;
        end
    end
end


for i=floor(l/2)+1:m+floor(l/2)
    for j=floor(k/2)+1:n+floor(k/2)
        s=sum(sum(imDil(i-floor(l/2):i+floor(l/2),j-floor(k/2):j+floor(k/2)).*imMorDim));
        if(s==sum(sum(imMorDim)))
            imEro(i,j)=1;
        end
%         if(s>0)
%             imDil(i,j)=1;
%         end
    end
end


imDilOut(:,:)=imDil(  floor(l/2)+1:m+floor(l/2),floor(k/2)+1:n+floor(k/2)  );
imEroOut(:,:)=imEro(  floor(l/2)+1:m+floor(l/2),floor(k/2)+1:n+floor(k/2)  );
subplot(1,2,1);
imshow(im);
title('Orignal Image')

subplot(1,2,2);
imshow(imEroOut);
title('Opening of image');