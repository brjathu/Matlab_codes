%brightness
% im=imread('../testImg/me.jpg');
% subplot(1,2,1);
% imshow(im);
% 
% imNew=zeros(size(im,1),size(im,2),3);
% imNew=uint8(imNew);
% imNew(:,:,1)=min(im(:,:,1)+20,255);
% imNew(:,:,2)=min(im(:,:,2)+20,255);
% imNew(:,:,3)=min(im(:,:,3)+20,255);
% 
% subplot(1,2,2);
% imshow(imNew);



%intensity - negative
% im=imread('../testImg/me.jpg');
% subplot(1,2,1)
% imshow(im);
% 
% imNew=zeros(size(im,1),size(im,2),3);
% imNew=uint8(imNew);
% imNew(:,:,1)=255-im(:,:,1);
% imNew(:,:,2)=255-im(:,:,2);
% imNew(:,:,3)=255-im(:,:,3);
% subplot(1,2,2);
% imshow(imNew);im=imread('../testImg/me.jpg');

%intensity -power law transform
%  im=im2double(imread('../testImg/me.jpg'));
% subplot(1,2,1)
% imshow(im(:,:,1));
% 
% imNew=zeros(size(im,1),size(im,2),1);
% gamma=1.01;
% imNew(:,:,1)=((im(:,:,1)./255).^gamma).*255;
% 
% subplot(1,2,2);
% imshow(imNew);



%histrogram
% im=rgb2gray(imread('../testImg/me.jpg'));
% subplot(1,2,1);
% imhist(im);
% subplot(1,2,2);
% 
% 
% numbins=255;
% bins=zeros(numbins,1);
% m=size(im,1);
% n=size(im,2);
% for i=1:m
%     for j=1:n
%         num=ceil(im(i,j)/(255/numbins));
%         if (num==0)
%             num=1;
%         end
%         
%         bins(num)=bins(num)+1;
%     end
% end
% bins=bins./(m*n);
% binBounds=linspace(0,255,numbins+1);
% barCenter=binBounds(1:numbins)+(255/numbins/2);
% bar(barCenter,bins,0.1)


%histeq
im=rgb2gray(imread('../testImg/me.jpg'));
subplot(2,2,1);
imshow(im);
img=histeq(im);

subplot(2,2,2);
imshow(img);

subplot(2,2,3);
imhist(im);

subplot(2,2,4);
imhist(img);



















