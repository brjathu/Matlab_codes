close all;
clear all;
Fc=3E3;
Fm=1E2;
Beta=20;

t=0:2E-5:1;
Wc=2*pi*Fc;
Wm=2*pi*Fm;
Ac=1;

subplot(2,1,1);plot(t,cos(Wc*t));
ylabel('Amplitude');
xlabel('carrier');
axis([0 0.01 -2 2]);
subplot(2,1,2);plot(t,cos(Wm*t));
xlabel('Time (ms)');
ylabel('Amplitude');
title('Info signal');
axis([0 0.01 -2 2]);

pause

Phi=Wc*t + Beta*sin(Wm*t);
Xc=Ac*cos(Phi);

figure;
subplot(2,1,1);plot(t,Xc);
xlabel('Time (s)');
ylabel('Amplitude');
title('Modulated signal (Time domain)');
axis([0 0.01 -2 2]);

Xf=0.00004*abs(fft(Xc));
subplot(2,1,2);plot(Xf(1:1E4));
xlabel('Frequency');
ylabel('Amplitude');
title('Modulated signal (frequency domain)');