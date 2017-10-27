clear all
clc

ts=1E-5;
Fs=1/ts;
t=0:ts:1;

cf=3E3;
mf=1E2;
A=2;
u=0.2;

x=cos(2*pi*mf*t);
c=2*cos(2*pi*cf*t);
% plot(t,x)
b=10;
phi=2*pi*cf*t+b*x;
y=A*cos(phi);
% plot(t,y)
F=Fs/2*linspace(-1,1,length(t));
X=0.00002*abs(fftshift(fft(x)));
C=0.00002*abs(fftshift(fft(c)));
Y=0.00002*abs(fftshift(fft(y)));
plot(F,Y);
axis([-2E4 2E4 0 1])

