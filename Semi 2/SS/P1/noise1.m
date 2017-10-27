clear, close all
load mtlb;
Fs=7418;
L=length(mtlb);
subplot(2,3,1)
plot([1:L]/Fs,mtlb);
axis tight
title('Original Signal');
xlabel('Time(s)')





load NoisySpeech.txt;
x=NoisySpeech;
subplot(2,3,2)
plot([1:L]/Fs,x,'r');
axis tight
title('Signal corrupted by Noise');

NFFT=2^nextpow2(L);


% 
% NFFT=1024;
% Fs=100;
% t=0:1/Fs:1;
% x=1+sin(80*pi*t);


Y=fft(mtlb,NFFT)/L;
f=Fs/2*linspace(0,1,NFFT/2+1);
subplot(2,3,3)
plot(f,2*abs(Y(1:NFFT/2+1)))
title('spectrum of original signal');

Y=fft(x,NFFT)/L;
subplot(2,3,4)
plot(f,2*abs(Y(1:NFFT/2+1)))


[b,a]=ellip(6,5,40,0.6);
dataOut=filter(b,a,x);
Y=fft(dataOut,NFFT)/L;
subplot(2,3,5)
plot(f,2*abs(Y(1:NFFT/2+1)))


