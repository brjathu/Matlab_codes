a=imread('candy.png');

imshow(a);



red=a(:,:,1);
blue=a(:,:,3);
green=a(:,:,2);




% grayalgo=(0.2989*red+0.5870*blue+0.1140*green);

% bwalgo=zeros(size(a,1),size(a,2));
% for l=1:size(a,1)
%     for m=1:size(a,2)
%         if(grayalgo(l,m)>255*0.60385)
%             bwalgo(l,m)=1;
%         end
%     end
% end




redbw=im2bw(red,0.65385);
subplot(2,2,1);
imshow(redbw);
title('redbw');


greenbw=im2bw(green,0.60385);
subplot(2,2,2);
imshow(greenbw);
title('greenbw');


bluebw=im2bw(blue,0.50385);
subplot(2,2,3);
imshow(bluebw);
title('bluebw');



igray=rgb2gray(a);

bwsum=(redbw & greenbw & bluebw);
subplot(2,2,4);
imcomp=imcomplement(bwsum);
imshow(imfill(imcomp,'holes'));
title('bwsum');
