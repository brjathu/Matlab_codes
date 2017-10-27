clear all
close all
im=imread('a01images/im05small.png');
im2=imread('a01images/im05.png');
% subplot(1,3,1);
% imshow(im);
% title('Original Image');

m=size(im,1);
n=size(im,2);

zoom=4;

imZoom=uint8(zeros(floor(m*zoom),floor(n*zoom),3));

% for i=1:floor(m*zoom)
%     for j=1:floor(n*zoom)  
%         imZoom(i,j,:)=im(ceil(i/zoom),ceil(j/zoom),:);
%     end
% end




for i=zoom+1:ceil(m*zoom)-zoom-1
    for j=zoom+1:ceil(n*zoom)-zoom-1
        a=i/zoom;
        b=j/zoom;
        
        
        t2=((im(ceil(a),ceil(b),:)-im(floor(a),ceil(b),:))*(a-floor(a))+im(floor(a),ceil(b),:));
        t1=((im(ceil(a),floor(b),:)-im(floor(a),floor(b),:))*(a-floor(a))+im(floor(a),floor(b),:));
        imZoom(i,j,:)=(t2-t1)*(b-floor(b))+t1;
        
        
%         t2=((im(ceil(a),ceil(b),1)-im(floor(a),ceil(b),1))*(a-floor(a))+im(floor(a),ceil(b),1));
%         t1=((im(ceil(a),floor(b),1)-im(floor(a),floor(b),1))*(a-floor(a))+im(floor(a),floor(b),1));
%         imZoom(i,j,1)=(t2-t1)*(b-floor(b))+t1;
        
%         t2=((im(ceil(a),ceil(b),2)-im(floor(a),ceil(b),2))*(a-floor(a))+im(floor(a),ceil(b),2));
%         t1=((im(ceil(a),floor(b),2)-im(floor(a),floor(b),2))*(a-floor(a))+im(floor(a),floor(b),2));
%         imZoom(i,j,2)=(t2-t1)*(b-floor(b))+t1;
%         
%         t2=((im(ceil(a),ceil(b),3)-im(floor(a),ceil(b),3))*(a-floor(a))+im(floor(a),ceil(b),3));
%         t1=((im(ceil(a),floor(b),3)-im(floor(a),floor(b),1))*(a-floor(a))+im(floor(a),floor(b),3));
%         imZoom(i,j,3)=(t2-t1)*(b-floor(b))+t1;
        
        
    end
end


figure,imshow(imZoom);

