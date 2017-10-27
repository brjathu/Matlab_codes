%%INIT VARIABLES:
 
%%Read in image:
 
ORIGINAL_IMAGE=imread('../testImg/girl.png');  
 sigma=1.2
 max_hysteresis_thresh=1
 min_hysteresis_thresh=0.04
%%Convert to double:
ORIGINAL_IMAGE=im2double(ORIGINAL_IMAGE);    
 
%%Save height and width
[H,W]=size(ORIGINAL_IMAGE);         
 
 
%%Derivatives in x and y
derivative_x=zeros(H,W);              
derivative_y=zeros(H,W);    
 
 
%%Gaussian kernel
size_of_kernel = ceil(6*sigma+1);         
adjust= ceil(size_of_kernel/2)
Y_GAUSSIAN=zeros(size_of_kernel,size_of_kernel);
X_GAUSSIAN=zeros(size_of_kernel,size_of_kernel);
 
%%Create gaussian kernels for both x and y directions based on the sigma
%%that was given.
 
for i=1:size_of_kernel
    for iiii=1:size_of_kernel
        Y_GAUSSIAN(i,iiii) = -( (i-((size_of_kernel-1)/2)-1)/( 2* pi * sigma^3 ) ) * exp ( - ( (i-((size_of_kernel-1)/2)-1)^2 + (iiii-((size_of_kernel-1)/2)-1)^2 )/ (2*sigma^2) );
    end
end
 
for i=1:size_of_kernel
    for iiii=1:size_of_kernel
        X_GAUSSIAN(i,iiii) = -( (iiii-((size_of_kernel-1)/2)-1)/( 2* pi * sigma^3 ) ) * exp ( - ( (i-((size_of_kernel-1)/2)-1)^2 + (iiii-((size_of_kernel-1)/2)-1)^2 )/ (2*sigma^2) );
    end
end
 
 
GRADIENT =  zeros(H,W);       
non_max = zeros(H,W);     
 
post_hysteresis = zeros(H,W); 
 
 
 
 
%%Image Derivatives:
 
for r=1+ceil(size_of_kernel/2):H-ceil(size_of_kernel/2)  
    for c=1+ceil(size_of_kernel/2):W-ceil(size_of_kernel/2)  
        reference_row=  r-ceil(size_of_kernel/2); 
        reference_colum=  c-ceil(size_of_kernel/2); 
        for yyy=1:size_of_kernel  
            for yyy_col=1:size_of_kernel  
                derivative_x(r,c) = derivative_x(r,c) + ORIGINAL_IMAGE(reference_row+yyy-1, reference_colum+yyy_col-1)*X_GAUSSIAN(yyy,yyy_col);
            end
        end
    end
end
 
 
for r=1+ceil(size_of_kernel/2):H-ceil(size_of_kernel/2)  
    for c=1+ceil(size_of_kernel/2):W-ceil(size_of_kernel/2) 
        reference_row=  r-ceil(size_of_kernel/2); 
        reference_colum=  c-ceil(size_of_kernel/2); 
        for yyy=1:size_of_kernel  
            for yyy_col=1:size_of_kernel 
                derivative_y(r,c) = derivative_y(r,c) + ORIGINAL_IMAGE(reference_row+yyy-1, reference_colum+yyy_col-1)*Y_GAUSSIAN(yyy,yyy_col);
            end
        end
    end
end
 
 
%%Compute the gradient magnitufde based on derivatives in x and y:
 
for r=1+ceil(size_of_kernel/2):H-ceil(size_of_kernel/2)  
    for c=1+ceil(size_of_kernel/2):W-ceil(size_of_kernel/2)  
        GRADIENT(r,c) = sqrt (derivative_x(r,c)^2 + derivative_y(r,c)^2 );
    end
end
 
%%Perform Non maximum suppression:
 
non_max = GRADIENT;
for r=1+ceil(size_of_kernel/2):H-ceil(size_of_kernel/2) 
    for c=1+ceil(size_of_kernel/2):W-ceil(size_of_kernel/2)  
       
        %%quantize:
        if (derivative_x(r,c) == 0) tangent = 5;       
        else tangent = (derivative_y(r,c)/derivative_x(r,c));   
        end
        if (-0.4142<tangent & tangent<=0.4142)
            if(GRADIENT(r,c)<GRADIENT(r,c+1) | GRADIENT(r,c)<GRADIENT(r,c-1))
                non_max(r,c)=0;
            end
        end
        if (0.4142<tangent & tangent<=2.4142)
            if(GRADIENT(r,c)<GRADIENT(r-1,c+1) | GRADIENT(r,c)<GRADIENT(r+1,c-1))
                non_max(r,c)=0;
            end
        end
        if ( abs(tangent) >2.4142)
            if(GRADIENT(r,c)<GRADIENT(r-1,c) | GRADIENT(r,c)<GRADIENT(r+1,c))
                non_max(r,c)=0;
            end
        end
        if (-2.4142<tangent & tangent<= -0.4142)
            if(GRADIENT(r,c)<GRADIENT(r-1,c-1) | GRADIENT(r,c)<GRADIENT(r+1,c+1))
                non_max(r,c)=0;
            end
        end
    end
end
 
 
 
 
post_hysteresis = non_max;
 
for r=1+ceil(size_of_kernel/2):H-ceil(size_of_kernel/2)  
    for c=1+ceil(size_of_kernel/2):W-ceil(size_of_kernel/2)  
        if(post_hysteresis(r,c)>=max_hysteresis_thresh) post_hysteresis(r,c)=1;
        end
        if(post_hysteresis(r,c)<max_hysteresis_thresh & post_hysteresis(r,c)>=min_hysteresis_thresh) post_hysteresis(r,c)=2;
        end
        if(post_hysteresis(r,c)<min_hysteresis_thresh) post_hysteresis(r,c)=0;
        end 
    end
end
 
 
 
vvvv = 1; 
 
while (vvvv == 1)
   
    vvvv = 0;
   
    for r=1+ceil(size_of_kernel/2):H-ceil(size_of_kernel/2)  
        for c=1+ceil(size_of_kernel/2):W-ceil(size_of_kernel/2)  
            if (post_hysteresis(r,c)>0)      
                if(post_hysteresis(r,c)==2) 
                   
                   
                    if( post_hysteresis(r-1,c-1)==1 | post_hysteresis(r-1,c)==1 | post_hysteresis(r-1,c+1)==1 | post_hysteresis(r,c-1)==1 |  post_hysteresis(r,c+1)==1 | post_hysteresis(r+1,c-1)==1 | post_hysteresis(r+1,c)==1 | post_hysteresis(r+1,c+1)==1 ) post_hysteresis(r,c)=1;
                        vvvv == 1;
                    end
                end
            end
        end
    end
   
end
 
 
 
for r=1+ceil(size_of_kernel/2):H-ceil(size_of_kernel/2) 
    for c=1+ceil(size_of_kernel/2):W-ceil(size_of_kernel/2)  
        if(post_hysteresis(r,c)==2) 
            post_hysteresis(r,c)==0;
        end   
    end
end
 
 imshow(non_max)
% imwrite(ORIGINAL_IMAGE,'C:\Documents and Settings\User\Desktop\Results\original_image.bmp');                        
%  
% imwrite(derivative_x,'C:\Documents and Settings\User\Desktop\Results\derivative_x.bmp');            
% imwrite(derivative_y,'C:\Documents and Settings\User\Desktop\Results\derivative_y.bmp');            
% imwrite(GRADIENT,'C:\Documents and Settings\User\Desktop\Results\gradient.bmp');       
% imwrite(non_max,'C:\Documents and Settings\User\Desktop\Results\non_max_supr.bmp');      
% imwrite(post_hysteresis,'C:\Documents and Settings\User\Desktop\Results\original_image.bmp');  
%  