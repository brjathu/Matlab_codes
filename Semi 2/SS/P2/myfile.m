a=wavread('output.wav');
b=(fft(a));
plot(abs(b))