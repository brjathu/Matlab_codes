%------------------reading image-----------------------------------------
im0= imread('../testImg/coin.jpg');
im = rgb2gray(im0);
im=histeq(im);
%----------------------------normalizing the pixel-------------------------
im111=im;
im=cast(im,'double');
im=im.*(1.0/255.0);
im;
%----------------------------receiving scale space size , initial sigma
%-----------------------------step size,blob threshhold from the user-----
n=input('number of scales\n');
[h,w]=size(im);
scale_space = zeros(h,w,n);
sigbegin=input('Input the beginning sigma\n');
sigma=sigbegin;
quo=input('Input Qoutient of scale\n');
k=2^quo;
threshold=input('input threshhold\n');
%--------------------Creating Scale Space---------------------------------
%--------------------by varying the sigma--------------------------------
%----------------and then convoluting with laplacian of Gaussian kernel--
for i=1:1:n
hw=3*sigma;
[X, Y] = meshgrid(-hw:hw, -hw:hw);
g = exp(-(X.^2 + Y.^2)/(2*sigma^2));
g= g/sum(sum(g));
kernel = [0 1 0 ; 1 -4 1 ; 0 1 0];
LoG= imfilter(g,kernel, 'same', 'replicate');
LoG=LoG.*(sigma^2);
%filt_size = 2*ceil(3*sigma)+1; % filter size
%LoG = sigma^2 * fspecial('log', filt_size, sigma);
imFiltered = imfilter(im, LoG, 'same', 'replicate');
scale_space(:,:,i)=imFiltered;
sigma=sigma*k;
end
%-------------------------------Squared Scale Space-----------------------
scale_space=scale_space.^2;
scale_space_begin=scale_space;
%u=0;
%--------------Maximas Calculating-----------------------------------------
for z=1:1:n
scale_space(:,:,z) =ordfilt2(scale_space_begin(:,:,z),9,[1 1 1;1 1 1;1 1 1]);
end
for i = 1:n
scale_space(:,:,i) = max(scale_space(:,:,max(i-1,1):min(i+1,n)),[],3);
end
scale_space = scale_space .* (scale_space == scale_space_begin);
%---------------------------------Finding the local maximas ---------------------------
%---------------------------------and plotting circles around
%---------------------------------the point radius depending on sigma------
imshow(im0);tot=0;
%hold on;
radwhole=[];
for i=1:n
    [rows, cols] = find(scale_space(:,:,i) >= threshold);
    numBlobs = length(rows);
    tot=tot+numBlobs;
    radi = sigbegin * k^(i-1) * sqrt(2);
    radi;
    for o= 1:1:numBlobs
        x=round(rows(o,1));
        y=round(cols(o,1));
        s=round(radi);
        radwhole=[radwhole;s];
        for p=max(x-s,1):1:min(x+s,h)
            for r=max(y-s,1):1:min(y+s,w)
                if (round((p-x)^2+(r-y)^2)<round(s^2) && round((p-x)^2+(r-y)^2)>round(s^2)-200)
                im0(p,r,3)=255;
                end
            end
        end
    end
end
%---------------------------------Showing the image------------------------
imshow(im0);