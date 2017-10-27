close, clear all
clc
% N=12;
% Omega0=2*pi/N;
% n=-N:1:N;
% phi=0;
% A=1;
% Xn=A*cos(Omega0*n+phi);
% stem(n,Xn,'o','MarkerFaceColor','g','markerSize',5)
% title(['N =' num2str(N) ', \Omega_0 = 2*pi/' num2str(N) ':Periodic'])


% nmax=10;
% n=-nmax:nmax;
% C=1;
% alpha=0.92;
% xn=C*alpha.^n;
% subplot(2,2,1)
% stem(n,xn,'o','MarkerFaceColor','k','markerSize',5)


nmax=20;
n=-nmax:nmax;
theta=0;
c=1*exp(j*theta);
omega0=2*pi*1/16;
alphamag=1.12;
alpha=alphamag*exp(j*omega0);
xn=abs(c)*alphamag.^n.*cos(omega0*n+theta)+j*abs(c)*alphamag.^n.*sin(omega0*n+theta);
subplot(2,1,1);
stem(n,xn,'o','MarkerFaceColor','k','markerSize',5)
hold on
x=-nmax:1/100:nmax;
plot(x,abs(c)*alphamag.^x, '--r', x, -abs(c)*alphamag.^x, '--r')