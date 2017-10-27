%% SIFT ALGORITHM with comparision 
% Descrption: In this programe we compare keypoints and descriptors of two
% images using SIFT algorithm implemented in Programe 'Vijay_ti_1.m'and
% calculate the percentage match.
% Author: VIJAY ANAND
%%
clc;
close all;
clear all;
% tic;
% Applying SIFT on First Image 
I=imread('lena256.jpg');
I_read=imresize(I,[256 256]);
I_enlarge=imresize(I_read,[512 512]);
I=rgb2gray(I_enlarge);
%I=I_enlarge;
imshow(I);
I=im2double(I);

I_temp=I;
original=I;
octave1=[];
octave2=[];
octave3=[];
%% FORMING OCTAVES
tic;
k2=0;
sigma_1=1.6;
[m,n]=size(I);
I_temp(m:m+4,n:n+4)=0; % zero padding
clear c;
tic;
for k1=0:3
    k=sqrt(2);
sigma=(k^(k1+(2*k2)))*sigma_1;

for x=-2:2
    for y=-2:2
        h(x+3,y+3)=(1/((2*pi)*((k*sigma)*(k*sigma))))*exp(-((x*x)+(y*y))/(2*(k*k)*(sigma*sigma))); 
    end
end


for i=1:m
    for j=1:n
        temp1=I_temp(i:i+4,j:j+4)'.*h;
        conv_1(i,j)=sum(sum(temp1));
    end
end
% figure, imshow(conv_1(1:m-4,1:n-4));
octave1=[octave1 conv_1];
end
%% octave 2
clear I_temp;
% k2=1;
I_temp2=imresize(original,1/((k2+1)*2));
 k2=1;
y=size(I_temp2)
[m,n]=size(I_temp2);
I_temp2(m:m+4,n:n+4)=0;
clear c;

for k1=0:3
    k=sqrt(2);
sigma=(k^(k1+(2*k2)))*sigma_1;

for x=-2:2
    for y=-2:2
        h1(x+3,y+3)=(1/((2*pi)*((k*sigma)*(k*sigma))))*exp(-((x*x)+(y*y))/(2*(k*k)*(sigma*sigma)));
    end
end

for i=1:m
    for j=1:n
        temp2=I_temp2(i:i+4,j:j+4)'.*h1;
        conv_2(i,j)=sum(sum(temp2));
    end
end
% figure, imshow(conv_2(1:m-4,1:n-4));
octave2=[octave2 conv_2];
end
%% octave 3
clear I_temp;
% k2=2;
I_temp3=imresize(original,1/((k2+1)*2));
z=size(I_temp3)
 k2=2;
[m,n]=size(I_temp3);
I_temp3(m:m+4,n:n+4)=0;
clear c;

for k1=0:4
    k=sqrt(2);
sigma=(k^(k1+(2*k2)))*sigma_1;


for x=-2:2
    for y=-2:2
        h2(x+3,y+3)=(1/((2*pi)*((k*sigma)*(k*sigma))))*exp(-((x*x)+(y*y))/(2*(k*k)*(sigma*sigma)));
    end
end


for i=1:m
    for j=1:n
        temp3=I_temp3(i:i+4,j:j+4)'.*h2;
        conv_3(i,j)=sum(sum(temp3));
    end
end
% figure, imshow(conv_3(1:m-4,1:n-4));
octave3=[octave3 conv_3];
end
% clear a;
% a=imresize(original,1/((k2+1)*2));
fprintf('\n Time for Gaussian scale space construction: %.3f s\n',toc) ;

%% DOG---difference of gaussian
tic;

 diff_11=octave1(1:512,1:512)-octave1(1:512,513:1024);
 
 diff_12=octave1(1:512,513:1024)-octave1(1:512,1025:1536);
 
 diff_13=octave1(1:512,1025:1536)-octave1(1:512,1537:2048);
 
 diff_21=octave2(1:256,1:256)-octave2(1:256,257:512);
 
 diff_22=octave2(1:256,257:512)-octave2(1:256,513:768);
 
 diff_23=octave2(1:256,513:768)-octave2(1:256,769:1024);
 

 diff_31=octave3(1:128,1:128)-octave3(1:128,129:256);
 
diff_32=octave3(1:128,129:256)-octave3(1:128,257:384);

 diff_33=octave3(1:128,257:384)-octave3(1:128,385:512);
 

fprintf('\n Time for Differential scale space construction: %.3f s\n',toc) ;

%% find exterma from DOG
tic;
key=[];

x1=0;
y1=0;
z1=0;
f=0;

for i=2:511
    for j=2:511
%         x1=0;
% y1=0;
% z1=0;

        
if (((diff_12(i,j)>diff_12(i-1,j))&&(diff_12(i,j)>diff_12(i+1,j))....
        &&(diff_12(i,j)>diff_12(i,j-1))&&(diff_12(i,j)>diff_12(i+1,j+1))....
        &&(diff_12(i,j)>diff_12(i-1,j-1))&&(diff_12(i,j)>diff_12(i-1,j+1)).....
        &&(diff_12(i,j)>diff_12(i+1,j-1))&&(diff_12(i,j)>diff_12(i,j+1))))
    x1=x1+1;
else
    continue;
end

if x1>0
    if((diff_12(i,j)>diff_13(i,j))&&(diff_12(i,j)>diff_13(i-1,j)).....
            &&(diff_12(i,j)>diff_13(i+1,j))&&(diff_12(i,j)>diff_13(i,j-1))......
            &&(diff_12(i,j)>diff_13(i+1,j+1))&&(diff_12(i,j)>diff_13(i-1,j-1))...
            &&(diff_12(i,j)>diff_13(i-1,j+1))&&(diff_12(i,j)>diff_13(i+1,j-1))&&(diff_12(i,j)>diff_13(i,j+1)))
        y1=y1+1;
    else
        continue;
        
    end 
end
%   if y1>0
%        
%     if ((diff_12(i,j)>diff_11(i,j))&&(diff_12(i,j)>diff_11(i-1,j))&&(diff_12(i,j)>diff_11(i+1,j))&&(diff_12(i,j)>diff_11(i,j-1))&&(diff_12(i,j)>diff_11(i+1,j+1))&&(diff_12(i,j)>diff_11(i-1,j-1))&&(diff_12(i,j)>diff_11(i-1,j+1))&&(diff_12(i,j)>diff_11(i+1,j-1))&&(diff_12(i,j)>diff_11(i,j+1)))
%         z1=z1+1;
%     else 
%         continue;
%     end
%   end
  
  key(i,j)=diff_12(i,j);
  f=1;
  


end
end
    
fprintf('\n Time for finding key points: %.3f s\n',toc) ;
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
 
   if f==0
    x=0;
y=0;
z=0;

for i=2:511
    for j=2:511
        
if (((diff_12(i,j)<diff_12(i-1,j))&&(diff_12(i,j)<diff_12(i+1,j))&&(diff_12(i,j)<diff_12(i,j-1))&&(diff_12(i,j)<diff_12(i+1,j+1))&&(diff_12(i,j)<diff_12(i-1,j-1))&&(diff_12(i,j)<diff_12(i-1,j+1))&&(diff_12(i,j)<diff_12(i+1,j-1))&&(diff_12(i,j)<diff_12(i,j+1))))
    x=x+1;
else
   continue;
end

if x>0
    if ((diff_12(i,j)<diff_13(i,j))&&(diff_12(i,j)<diff_13(i-1,j))&&(diff_12(i,j)<diff_13(i+1,j))&&(diff_12(i,j)<diff_13(i,j-1))&&(diff_12(i,j)<diff_13(i+1,j+1))&&(diff_12(i,j)<diff_13(i-1,j-1))&&(diff_12(i,j)<diff_13(i-1,j+1))&&(diff_12(i,j)<diff_13(i+1,j-1))&&(diff_12(i,j)<diff_13(i,j+1)))
        y=y+1;
    else
        continue;
        
    end 
end
  if y>0
      
   if ((diff_12(i,j)<diff_11(i,j))&&(diff_12(i,j)<diff_11(i-1,j))&&(diff_12(i,j)<diff_11(i+1,j))&&(diff_12(i,j)<diff_11(i,j-1))&&(diff_12(i,j)<diff_11(i+1,j+1))&&(diff_12(i,j)<diff_11(i-1,j-1))&&(diff_12(i,j)<diff_11(i-1,j+1))&&(diff_12(i,j)<diff_11(i+1,j-1))&&(diff_12(i,j)<diff_11(i,j+1)))
       z=z+1;
   else 
       continue;
   end
  end
  
  key(i,j)=diff_12(i,j);
  
  






end
    end
  
   end
  
 key1=key*255;
 figure,imshow(key1);
 
 
 
 %% finding key point location

[key_m,key_n]=size(key);
  r=1;  
key_p=[];
for i=1:key_m
    for j=1:key_n
    
    if key(i,j)>0
%         key_p=[key_p,i,j];
           key_p(r,1)=i;
           key_p(r,2)=j;
           r=r+1;

    end
end
end
 fprintf('\n total number of key points of image 1 are: \n');
 length(key_p)
%% magnitude and phase calculation

for i=2:511
    for j=2:511
        mag_1(i,j)=((diff_12(i+1,j)-diff_12(i-1,j))^2)+((diff_12(i,j+1)-diff_12(i,j-1))^2);
        phase(i,j)=atan2((diff_12(i,j+1)-diff_11(i,j-1)),(diff_12(i+1,j)-diff_11(i-1,j)));
    end
end
mag=sqrt(mag_1);

%% orintation.....

for k=1:length(key_p)
    
m=key_p(k,1);
n=key_p(k,2);

if (m<=2)||(n<=2)||(m>=509)||(n>=509)
    continue;
end
temp_mag=mag(m-2:m+2,n-2:n+2);
temp_phase=phase(m-2:m+2,n-2:n+2);
clear bin_p;
clear bin_m;
s=1;
     
for i=1:5
    for j=1:5
        k1=1;
        for x=1:36
            if temp_phase(i,j)>-pi+(k1-1)*0.1745 && temp_phase(i,j)<-pi+0.1745*k1
                
                bin_p(k1,s)=temp_phase(i,j);
                bin_m(k1,s)=temp_mag(i,j);
                s=s+1;
            end
            bin_p(k1,s)=0;
            bin_m(k1,s)=0;
            %s=s+1;
            k1=k1+1;
           
        end
    end
end

for i=1:36
d1=sum(bin_m(i,:));
magv(i,k)=d1;
end


end



max_mag=max(magv);

for i=1:length(key_p)
    
    if max_mag(1,i)==0
        continue;
    end
    
    j=find(magv(:,i)==(max_mag(1,i)));
    
    
    max_mag(2,i)=j;
end

   %% discriptor
   
   
    
   for k=1:length(key_p)
    magv_2=[];
m=key_p(k,1);
n=key_p(k,2);

 if (m<=8)||(n<=8)||(m>=503)||(n>=503)
     continue;
 end
temp_mag_d=mag(m-7:m+8,n-7:n+8);
temp_phase_d=phase(m-7:m+8,n-7:n+8);

store_phase=[];
for i=1:4:13
    for j=1:4:13
        vijj=temp_mag_d(i:i+3,j:j+3);
        vijj_phase=temp_phase_d(i:i+3,j:j+3);
        
    %end
    store_phase=[store_phase,vijj_phase];
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    s=1;
    for i1=1:4
    for j1=1:4
        k1=1;
        for x=1:8
            if vijj_phase(i1,j1)>-pi+(k1-1)*(pi/4) && vijj_phase(i1,j1)<-pi+(pi/4)*k1
                
                bin_p1(k1,s)=vijj_phase(i1,j1);
                bin_m1(k1,s)=vijj(i1,j1);
                s=s+1;
            end
            bin_p1(k1,s)=0;
            bin_m1(k1,s)=0;
            %s=s+1;
            k1=k1+1;
           
            
        end
    end
 end

for g=1:8
d2(:,1)=sum(bin_m1(g,:));
magv_2=[magv_2,d2];
end


    end


end

discriptor(k,:)=magv_2(:,:)';


    
end


%% Applying SIFT on Second Image

 
 fprintf('\n  1- Reduce intensity of Image \n 2- incrase intensity of Image \n 3- change the value of sigma from 1.6 to new Value \n 4- Rotate the Image \n');
 choice=input('Enter your Choice: ');
 switch choice
     
     case 1
          I2=I/5;
%                 a=imread('lena-256di.png');
%                 I2=imresize(a,[512 512]);
         sigma_1=1.6;
         %break;
     case 2
         I2=I*5;
         sigma_1=1.6;
         % break;
     case 3
         %          I2=imread('lena256.png');
         %          I2_read=imresize(I2,[256 256]);
         %          I2_enlarge=imresize(I2_read,[512 512]);
         %          I2=rgb2gray(I2_enlarge);
         I2=I;
         sigma_1= input(' Enter New Sigma value: ');
         %break;
     case 4
         fprintf('read the image \n');
         
         a=I;
%          a=rgb2gray(a1);
         [m,n]=size(a);
         old=[];
         map=[];
%          theta=20*(pi/180);
         theta_i=input('Enter the angle of rotation: ');
         theta=theta_i*(pi/180);
         for i=1:m
             for j=1:n
                 i1=(cos(theta)*(i-m/2))-(sin(theta)*(j-n/2))+m/2;
                 j1=(sin(theta)*(i-m/2))+(cos(theta)*(j-n/2))+n/2;
                 old((i-1)*m+j,1:2)=[i j];
                 map((i-1)*m+j,1:2)=[floor(i1) floor(j1)];
             end
         end
         b=imrotate(a,theta_i);
         [m1,n1]=size(b);
         margin=floor((m1-m)/2);
         
         if theta_i==90
             for i=1:m
                 for j=1:n
                     new((i-1)*m+j,1:2)=[map((i-1)*m+j,1)+margin+1 map((i-1)*m+j,2)+margin];
                 end
             end
             
         elseif theta_i==180
             
             for i=1:m
                 for j=1:n
                     new((i-1)*m+j,1:2)=[map((i-1)*m+j,1)+margin map((i-1)*m+j,2)+margin+1];
                 end
             end
         else
             
             for i=1:m
                 for j=1:n
                     new((i-1)*m+j,1:2)=[map((i-1)*m+j,1)+margin+1 map((i-1)*m+j,2)+margin+1];
                 end
             end
         end
         
         
         
         
         
         for i=1:m
             for j=1:n
                 c(i,j)=b(new((i-1)*m+j,1),new((i-1)*m+j,2));
             end
         end
         % imshow(c);
         I2=c;
         sigma_1=1.6;
         %break;
         
     otherwise
         fprintf('\n you have entered a wrong choice \n');
         
 end
 
         
%%%%%%%%%%%%%%%%%%%%%% end of switch statement %%%%%%%%%%%%%%%%%     
     
 
 


figure,imshow(I2);
I2=im2double(I2);

I2_temp=I2;
original2=I2;
octave_1=[];
octave_2=[];
octave_3=[];
%% forming octaves
tic;
k2=0;
[m,n]=size(I2);
I2_temp(m:m+4,n:n+4)=0; % zero padding
clear c;
tic;
for k1=0:3
    k=sqrt(2);
sigma=(k^(k1+(2*k2)))*sigma_1;

for x=-2:2
    for y=-2:2
        h(x+3,y+3)=(1/((2*pi)*((k*sigma)*(k*sigma))))*exp(-((x*x)+(y*y))/(2*(k*k)*(sigma*sigma))); 
    end
end


for i=1:m
    for j=1:n
        temp1=I2_temp(i:i+4,j:j+4)'.*h;
        conv_1(i,j)=sum(sum(temp1));
    end
end
% figure, imshow(conv_1(1:m-4,1:n-4));
octave_1=[octave_1 conv_1];
end
%% octave 2
clear I2_temp;
% k2=1;
I2_temp2=imresize(original2,1/((k2+1)*2));
 k2=1;
y2=size(I_temp2)
[m,n]=size(I2_temp2);
I2_temp2(m:m+4,n:n+4)=0;
clear c;

for k1=0:3
    k=sqrt(2);
sigma=(k^(k1+(2*k2)))*sigma_1;

for x=-2:2
    for y=-2:2
        h1(x+3,y+3)=(1/((2*pi)*((k*sigma)*(k*sigma))))*exp(-((x*x)+(y*y))/(2*(k*k)*(sigma*sigma)));
    end
end

for i=1:m
    for j=1:n
        temp2=I_temp2(i:i+4,j:j+4)'.*h1;
        conv_2(i,j)=sum(sum(temp2));
    end
end
% figure, imshow(conv_2(1:m-4,1:n-4));
octave_2=[octave_2 conv_2];
end
%% octave 3
clear I2_temp;
% k2=2;
I3_temp3=imresize(original2,1/((k2+1)*2));
z2=size(I3_temp3)
 k2=2;
[m,n]=size(I3_temp3);
I3_temp3(m:m+4,n:n+4)=0;
clear c;

for k1=0:4
    k=sqrt(2);
sigma=(k^(k1+(2*k2)))*sigma_1;


for x=-2:2
    for y=-2:2
        h2(x+3,y+3)=(1/((2*pi)*((k*sigma)*(k*sigma))))*exp(-((x*x)+(y*y))/(2*(k*k)*(sigma*sigma)));
    end
end


for i=1:m
    for j=1:n
        temp3=I3_temp3(i:i+4,j:j+4)'.*h2;
        conv_3(i,j)=sum(sum(temp3));
    end
end
% figure, imshow(conv_3(1:m-4,1:n-4));
octave_3=[octave_3 conv_3];
end
% clear a;
% a=imresize(original,1/((k2+1)*2));
fprintf('Time for Gaussian scale space construction: %.3f s\n',toc) ;

%% DOG---difference of gaussian
tic;

 diff_11_2=octave_1(1:512,1:512)-octave_1(1:512,513:1024);
 
 diff_12_2=octave_1(1:512,513:1024)-octave_1(1:512,1025:1536);
 
 diff_13_2=octave_1(1:512,1025:1536)-octave_1(1:512,1537:2048);
 
 diff_21_2=octave_2(1:256,1:256)-octave_2(1:256,257:512);
 
 diff_22_2=octave_2(1:256,257:512)-octave_2(1:256,513:768);
 
 diff_23_2=octave_2(1:256,513:768)-octave_2(1:256,769:1024);
 

 diff_31_2=octave_3(1:128,1:128)-octave_3(1:128,129:256);
 
diff_32_2=octave_3(1:128,129:256)-octave_3(1:128,257:384);

 diff_33_2=octave_3(1:128,257:384)-octave_3(1:128,385:512);
 
 

fprintf('\n Time for Differential scale space construction: %.3f s\n',toc) ;

%% find exterma from DOG
tic;
key_2=[];

x11=0;
y11=0;
z11=0;
f1=0;

for i=2:511
    for j=2:511
%         x1=0;
% y1=0;
% z1=0;

        
if (((diff_12_2(i,j)>diff_12_2(i-1,j))&&(diff_12_2(i,j)>diff_12_2(i+1,j))....
        &&(diff_12_2(i,j)>diff_12_2(i,j-1))&&(diff_12_2(i,j)>diff_12_2(i+1,j+1))....
        &&(diff_12_2(i,j)>diff_12_2(i-1,j-1))&&(diff_12_2(i,j)>diff_12_2(i-1,j+1))....
        &&(diff_12_2(i,j)>diff_12_2(i+1,j-1))&&(diff_12_2(i,j)>diff_12_2(i,j+1))))
    x11=x11+1;
else
    continue;
end

if x11>0
    if((diff_12_2(i,j)>diff_13_2(i,j))&&(diff_12_2(i,j)>diff_13_2(i-1,j))....
            &&(diff_12_2(i,j)>diff_13_2(i+1,j))&&(diff_12_2(i,j)>diff_13_2(i,j-1))....
            &&(diff_12_2(i,j)>diff_13_2(i+1,j+1))&&(diff_12_2(i,j)>diff_13_2(i-1,j-1))....
            &&(diff_12_2(i,j)>diff_13_2(i-1,j+1))&&(diff_12_2(i,j)>diff_13_2(i+1,j-1))....
            &&(diff_12_2(i,j)>diff_13_2(i,j+1)))
        y11=y11+1;
    else
        continue;
        
    end 
end
%   if y1>0
%        
%     if ((diff_12(i,j)>diff_11(i,j))&&(diff_12(i,j)>diff_11(i-1,j))&&(diff_12(i,j)>diff_11(i+1,j))&&(diff_12(i,j)>diff_11(i,j-1))&&(diff_12(i,j)>diff_11(i+1,j+1))&&(diff_12(i,j)>diff_11(i-1,j-1))&&(diff_12(i,j)>diff_11(i-1,j+1))&&(diff_12(i,j)>diff_11(i+1,j-1))&&(diff_12(i,j)>diff_11(i,j+1)))
%         z1=z1+1;
%     else 
%         continue;
%     end
%   end
  
  key_2(i,j)=diff_12_2(i,j);
  f1=1;


end
end
    
fprintf('\n Time for finding key points: %.3f s\n',toc) ;
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
 
   if f1==0
    x22=0;
y22=0;
z22=0;

for i=2:511
    for j=2:511
        
if (((diff_12_2(i,j)<diff_12_2(i-1,j))&&(diff_12_2(i,j)<diff_12_2(i+1,j))....
        &&(diff_12_2(i,j)<diff_12_2(i,j-1))&&(diff_12_2(i,j)<diff_12_2(i+1,j+1))....
        &&(diff_12_2(i,j)<diff_12_2(i-1,j-1))&&(diff_12_2(i,j)<diff_12_2(i-1,j+1))....
        &&(diff_12_2(i,j)<diff_12_2(i+1,j-1))&&(diff_12_2(i,j)<diff_12_2(i,j+1))))
    x22=x22+1;
else
   continue;
end

if x22>0
    if ((diff_12_2(i,j)<diff_13_2(i,j))&&(diff_12_2(i,j)<diff_13_2(i-1,j))....
            &&(diff_12_2(i,j)<diff_13_2(i+1,j))&&(diff_12_2(i,j)<diff_13_2(i,j-1))....
            &&(diff_12_2(i,j)<diff_13_2(i+1,j+1))&&(diff_12_2(i,j)<diff_13_2(i-1,j-1))....
            &&(diff_12_2(i,j)<diff_13_2(i-1,j+1))&&(diff_12_2(i,j)<diff_13_2(i+1,j-1))....
            &&(diff_12_2(i,j)<diff_13(i,j+1)))
        y=y+1;
    else
        continue;
        
    end 
end
%   if y>0
%       
%    if ((diff_12_2(i,j)<diff_11(i,j))&&(diff_12_2(i,j)<diff_11(i-1,j))&&(diff_12_2(i,j)<diff_11(i+1,j))&&(diff_12_2(i,j)<diff_11(i,j-1))&&(diff_12_2(i,j)<diff_11(i+1,j+1))&&(diff_12_2(i,j)<diff_11(i-1,j-1))&&(diff_12_2(i,j)<diff_11(i-1,j+1))&&(diff_12_2(i,j)<diff_11(i+1,j-1))&&(diff_12_2(i,j)<diff_11(i,j+1)))
%        z=z+1;
%    else 
%        continue;
%    end
%   end
  
  key_2(i,j)=diff_12_2(i,j);
  
  






end
    end
  
   end
  
 key22=key_2*255;
 figure,imshow(key22);
 
 %% finding key point location

[key_m,key_n]=size(key_2);
  r=1;  
key2_p=[];
for i=1:key_m
    for j=1:key_n
    
    if key_2(i,j)>0
%         key_p=[key_p,i,j];
           key2_p(r,1)=i;
           key2_p(r,2)=j;
           r=r+1;

    end
end
end

fprintf('total number of key points in second image are : \n');
length(key2_p)
 
%% magnitude and phase calculation

for i=2:511
    for j=2:511
        mag_2(i,j)=((diff_12_2(i+1,j)-diff_12_2(i-1,j))^2)+((diff_12_2(i,j+1)-diff_12_2(i,j-1))^2);
        phase2(i,j)=atan2((diff_12_2(i,j+1)-diff_11_2(i,j-1)),(diff_12_2(i+1,j)-diff_11_2(i-1,j)));
    end
end
mag2=sqrt(mag_2);

%% orintation.....

for k=1:length(key2_p)
    
m=key2_p(k,1);
n=key2_p(k,2);

if (m<=2)||(n<=2)||(m>=509)||(n>=509)
    continue;
end
temp_mag2=mag2(m-2:m+2,n-2:n+2);
temp_phase2=phase2(m-2:m+2,n-2:n+2);
clear bin_p;
clear bin_m;
s=1;
     
for i=1:5
    for j=1:5
        k1=1;
        for x=1:36
            if temp_phase2(i,j)>-pi+(k1-1)*0.1745 && temp_phase2(i,j)<-pi+0.1745*k1
                
                bin_p(k1,s)=temp_phase2(i,j);
                bin_m(k1,s)=temp_mag2(i,j);
                s=s+1;
            end
            bin_p(k1,s)=0;
            bin_m(k1,s)=0;
            %s=s+1;
            k1=k1+1;
           
        end
    end
end

for i=1:36
d1=sum(bin_m(i,:));
magv2(i,k)=d1;
end


end



max_mag2=max(magv2);

for i=1:length(key2_p)
    
    if max_mag2(1,i)==0
        continue;
    end
    
    j=find(magv2(:,i)==(max_mag2(1,i)));
    
    
    max_mag2(2,i)=j;
end

   %% discriptor
   
   
    
   for k=1:length(key2_p)
    magv_22=[];
m=key2_p(k,1);
n=key2_p(k,2);

 if (m<=8)||(n<=8)||(m>=503)||(n>=503)
     continue;
 end
temp_mag_d2=mag2(m-7:m+8,n-7:n+8);
temp_phase_d2=phase2(m-7:m+8,n-7:n+8);

store_phase2=[];
for i=1:4:13
    for j=1:4:13
        vijj2=temp_mag_d2(i:i+3,j:j+3);
        vijj_phase2=temp_phase_d2(i:i+3,j:j+3);
        
    %end
    store_phase2=[store_phase2,vijj_phase2];
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    s=1;
    for i1=1:4
    for j1=1:4
        k1=1;
        for x=1:8
            if vijj_phase2(i1,j1)>-pi+(k1-1)*(pi/4) && vijj_phase2(i1,j1)<-pi+(pi/4)*k1
                
                bin2_p1(k1,s)=vijj_phase2(i1,j1);
                bin2_m1(k1,s)=vijj2(i1,j1);
                s=s+1;
            end
            bin2_p1(k1,s)=0;
            bin2_m1(k1,s)=0;
            %s=s+1;
            k1=k1+1;
           
            
        end
    end
 end

for g=1:8
d22(:,1)=sum(bin2_m1(g,:));
magv_22=[magv_22,d22];
end


    end


end

discriptor2(k,:)=magv_22(:,:)';


    
end


%% calculating match 

count=0;
for i=1:length(key_p)
    for j=1:length(key2_p)
        
       if (key_p(i,1)==key2_p(j,1)) && (key_p(i,2)==key2_p(j,2))
           count=count+1;
           break;
       end
    end
end

fprintf('\n total number of matched key points are : \n');
count

perc=(count/length(key_p))*100;
fprintf('\n percentage match in key points are : \n');
perc


%% End of Programe






    







    
