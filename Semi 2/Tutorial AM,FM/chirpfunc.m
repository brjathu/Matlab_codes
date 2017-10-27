function x= chirpfunc( f1,f2,dur,fsamp )
%CHIRPFUNC Summary of this function goes here
%   Detailed explanation goes here
ts=1/fsamp;
t=0:ts:dur;
A=7.7;
f0=f1;
u=(f2-f1)/2*dur;
theta=0;
f=@(t) 2*u*t+f0;


phi=@(t) 2*pi*u*t.^2+2*pi*f0*t+theta;
fun=A*cos(phi(t));
soundsc(fun)
plot(t,fun);
figure
plot(t,f(t));
figure
spectrogram(fun);
colorbar
view(2)
end

