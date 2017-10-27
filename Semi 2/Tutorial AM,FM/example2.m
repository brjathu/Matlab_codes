fs=10E3;
ts=1/fs;

fc=13000;
fm=20;
As=1;
I=4;

t=0:ts:5;
x=As*cos(2*pi*fm*t+0);
Xc=A*cos(2*pi*t*fc+I*x+0);
soundsc(Xc);
plot(t,Xc);