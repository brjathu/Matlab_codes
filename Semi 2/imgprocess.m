% img=imread('img.jpg');
% % imshow(img);
% % imagesc(img(:,:,3));
% % colormap gray;
% subplot(221);
% imshow(img);
% 
% subplot(222);
% blue_img=double(img);
% blue_img(:,:,3)=4*blue_img(:,:,2);
% blue_img=uint8(blue_img);
% imshow(blue_img);
% 
% subplot(223);
% ad_img=imadjust(img,[0.3,0.7],[]);
% imshow(ad_img);


% [wav, fs]=audioread('bird.wav');
% disp(fs);
% plot(wav);
% 
% sound(wav,fs);

J=imread('img2.jpg');
K = wiener2(J,[5 5]);
figure, imshow(K)