% t=0:0.001:1;
% f=0:9;
% x=t;
% y=abs(fft(x))/1000;
% stem(f,y(1:10));

[a,fs]=wavread('terminator.wav');
% sound(a)
delta=1/fs;
t=delta:delta:length(a)*delta;
subplot(2,2,1);
plot(t,a)


x=abs(fft(a))/length(a);
n=length(a)-1;
f=0:n;
subplot(2,2,2);
plot(f,x(1:n+1))
