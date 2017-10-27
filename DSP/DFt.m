clear all;
close all;
u=@(x) (x>=0);  %create a u[n] function
t=30;
n=0:t;          %time domain of signals

N=10;   %N point DFT

X=@(n)  u(n)-u(n-5);    %create the given x[n]
Xdel=@(n) X(mod(n,N));  % generate periodic x[n]
y=fft(X(n),N);   %DFT of x[n]
x=ifft(y,N);    %IDFT of y

Xk=zeros(1,t+1);    %padding with zeros
Xk(1:N)=y(1:N)

invXk=zeros(1,t+1); %padding with zeros
invXk(1:N)=x(1:N)

subplot(3,1,1)
stem(n,Xdel(n),'o','MarkerFaceColor','k','markerSize',5)
title('Periodic X[n]')

subplot(3,1,2)
stem(n,Xk,'o','MarkerFaceColor','k','markerSize',5)
title('10 point DFT')


subplot(3,1,3)
stem(n,invXk,'o','MarkerFaceColor','k','markerSize',5)
title('Inverse DFT')