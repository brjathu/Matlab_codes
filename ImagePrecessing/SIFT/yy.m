run('/home/brjathu/Softwares/Matlab/MatlabFiles/vlfeat-0.9.20/toolbox/vl_setup')

im = vl_impattern('roofs1') ;
figure(1) ; clf ;
image(im) ; axis image off ;

imgs = im2single(rgb2gray(im)) ;
frames = vl_covdet(imgs, 'verbose') ;

hold on ;
vl_plotframe(frames) ;