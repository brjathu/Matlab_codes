a=wavread('baila.wav');
d=@(n) n==0;
u=@(n) n>=0;
% n=-100:100;
hn=filter([4.43e-4 8.86e-4 4.43e-4],[1 -1.94 0.94],d(n));
bff=conv(hn,(u(n)-u(n-100)));


b=fftshift(fft(a));
plot(abs(b))



figure 
plot(bff)
% plot(fftshift(fft(abs(bff))))