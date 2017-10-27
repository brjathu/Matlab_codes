function yy = bellenv( fc,fm,I0,tau,dur,fsamp)
%BELLENV Summary of this function goes here
%   Detailed explanation goes here
fs=fsamp;
ts=1/fs;

As=1;


t=0:ts:dur;
I=I0*exp(-t/tau);
A=1*exp(-t/tau);

x=As*cos(2*pi*fm*t+0);
Xc=A.*cos(2*pi*t*fc+I.*x+0);
soundsc(Xc);
plot(t,Xc);
specgram(Xc);
end

