url = 'http://192.168.43.1:8080/shot.jpg';
url2='circles.png';
 
% rgb  = imread(url2);
% fh = image(rgb);
% gray_image = rgb2gray(rgb);     
% [centers, radii] = imfindcircles(rgb,[20 25],'ObjectPolarity','dark','Sensitivity',0.9,'Method','twostage')
% centers
% radii
% 
% h = viscircles(centers,radii);

% ss  = imread(url);%%%%%%%%%%%%%%%%%circle detection
% fh = image(ss);
% while(1)
%     ss  = imread(url);
%     
%     [centers, radii] = imfindcircles(ss,[50 100],'ObjectPolarity','dark','Sensitivity',0.9,'Method','twostage')
%     h = viscircles(centers,radii);
%     set(fh,'CData',ss);
%     drawnow;
%     delete(h); 
% end









clear all
clc
%Detect objects using Viola-Jones Algorithm

%To detect Face
FDetect = vision.CascadeObjectDetector;

%Read the input image
I = imread('people.jpg');

%Returns Bounding Box values based on number of objects
BB = step(FDetect,I);

figure,
imshow(I);
for i = 1:size(BB,1)
    h=rectangle('Position',BB(i,:),'LineWidth',5,'LineStyle','-','EdgeColor','r');
end
title('Face Detection');

