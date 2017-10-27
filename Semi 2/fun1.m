
% randamArray=randi([50 100],5,10);  %create random array
% disp(randamArray);                  %just display the array
% 
% 
% tic
% sinArray=sin(randamArray);
% toc
% 
% 
% disp(sinArray);
% 
% tic
% for i=1:5
%     for j=1:10
%         y(i,j)=sin(randamArray(i,j));
%     end
% end
% toc
% 
% disp(y);

% tic
% [bird,fs]=wavread('bird.wav');
% %soundsc(bird,fs);
% n=length(bird);
% disp(n);
% disp(fs);
% x=1:n;
% z=x*1/fs;
% disp(bird);

% subplot(311);
% plot(x,bird(x));
% title('1');xlabel('n');ylabel('A');
% 
% subplot(312);
% plot(bird);
% title('2');xlabel('n');ylabel('A');
% 
% subplot(313);
% plot(z,bird(x));
% title('3');xlabel('t');ylabel('A');
% y=bird(x);


% for i=1:1:n;
%     y(i)=bird(i);
% end
% 
% plot(x,y);

% toc



% a=randi([0 10], 3 ,2);
% b=randi([0 10], 3 ,2);
% num_col_a=size(a);
% num_col_b=size(b);
% disp(a);
% disp(b);
% if (num_col_a==num_col_b )
%    for i=1:num_col_a(1,1)
%        for j=1:num_col_a(1,2)
%            if a(i,j)==b(i,j)
%                y(i,j)=1;
%            else
%                y(i,j)=0;
%            end
%        end
%    end
%    disp(y);
% else
%     disp('error');
% end




img=imread('leaf.jpg');

arr=[2 3;1 3;1 2];
for m=1:10;
    for j=1:3
        img1=img;
       x=arr(j,1);
       img1(:,:,x)=0;
       y=arr(j,2);
       img1(:,:,y)=0;
       imshow(img1);
       pause(0.5);
    end
end


% imTemp=image;
% imTemp(:,:,2)=1;
% 
% imshow(imTemp);
% imtool(imTemp);