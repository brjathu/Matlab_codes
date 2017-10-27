
load handel.mat
 
hfile = 'handel.wav';
wavwrite(y, Fs, hfile)
clear y Fs
 
% Read the data back into MATLAB, and listen to audio.
[y, Fs, nbits, readinfo] = wavread(hfile);
% sound(y, Fs);

[x,fs,bits]=wavread(hfile);
y=upfirdn(x,[1],1,2);
%wavwrite(y,fs/2,bits,'downsample_by_2'); 
% sound(y,fs/2);


[x,fs,bits]=wavread(hfile);
y=upfirdn(x,[1],1,4);
%wavwrite(y,fs/4,bits,'downsample_by_4'); 
% sound(y,fs/4);

[x,fs,bits]=wavread(hfile);
y=upfirdn(x,[1],1,8);
%wavwrite(y,fs/4,bits,'downsample_by_4'); 
%sound(y,fs/8);


[x,fs,bits]=wavread(hfile);
y=upfirdn(x,[1],2,1);
%wavwrite(y,fs/4,bits,'downsample_by_4'); 
sound(y,2*fs);

