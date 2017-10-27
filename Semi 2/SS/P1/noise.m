% N=12*pi;
% Omega0=2*pi/N;
% n=-1*N:1:1*N;
% phi=0;
% A=1;
% Xn=A*cos(Omega0*n+phi);
% stem(n,Xn,'o','MarkerFaceColor','k','markerSize',5)
% title(['N =' num2str(N) ', \Omega_0 = 2\pi/' num2str(N) ':Periodic'])

% 
% nmax=10;
% n=-nmax:nmax;
% C=0.8;
% alpha=0.92;
% xn=C*alpha.^n;
% subplot(2,2,1)
% stem(n,xn,'o','MarkerFaceColor','k','markerSize',5)

% 
% nmax=20;
% n=-nmax:nmax;
% theta=0;
% c=1*exp(j*theta);
% omega0=2*pi*1/16;
% alphamag=1.12;
% alpha=alphamag*exp(j*omega0);
% xn=abs(c)*alphamag.^n.*cos(omega0*n+theta)+j*abs(c)*alphamag.^n.*sin(omega0*n+theta);
% subplot(2,1,1);
% stem(n,xn,'o','MarkerFaceColor','k','markerSize',5)
% hold on
% x=-nmax:1/100:nmax;
% plot(x,abs(c)*alphamag.^x, '--r', x, -abs(c)*alphamag.^x, '--r')









% clear all
% clc
% close all
% uimp=@(x) (x==0);
% ustep=@(x) (x>=0);
% 
% num=[4.43e-4 8.86e-4 4.43e-4];
% den=[1 -1.94 +0.94];
% % zplane(num,den);
% n=-50:50;
% xn_f=filter(num,den,uimp(n));
% [r, p, k]=residuez(num,den);
% display(r(1));
% display(r(2));
% % display(r(3));
% display(p(1));
% display(p(2));
% % display(p(3));
% display(k);
% xn_p=r(1)*p(1).^n.*ustep(n) + r(2)*p(2).^n.*ustep(n) + k*uimp(n);
% display(r(1));
% display(r(2));
% display(p(1));
% display(p(2));
% display(k);
% subplot 121
% stem(n,xn_f,'b--.');
% title('Inverse Transform -convolution Method');
% ylabel('x_f[n]');
% xlabel('n');
% 
% subplot 122
% stem(n,xn_p,'r--.');
% title('Inverse Transform -partial fraction method');
% ylabel('x_p[n]');
% xlabel('n');
% n=0:200;
% xn=ustep(n)-ustep(n-100);
% plot(n,xn);
% 
% yn=zeros(1,201);
% for i=3:length(yn)
%     yn(i)=4.43e-4*xn(i)+8.86e-4*xn(i-1)+4.43e-4*xn(i-2)+ 1.94*yn(i-1)-0.94*yn(i-2);
% end
% 
% plot(n ,yn);

% 
% clear all
% clc
% close all
% uimp=@(x) (x==0);
% ustep=@(x) (x>=0);
% 
% [baila,fs]=audioread('baila.wav');
% % a1=audioplayer(baila,fs);
% % a1.play;
% % dispaly('playing the origanal track');
% % pause(21);
% 
% num=[4.43e-4 8.86e-4 4.43e-4];
% den=[1 -1.94 +0.94];
% % zplane(num,den);
% n=-50:50;
% baila_filt=filter(num,den,baila);
% 
% 
% baila_F=fftshift(fft(baila));
% baila_FF=fftshift(fft(baila_filt));
% f=(-length(baila)/2:length(baila)/2-1).*(fs/length(baila));
% figure
% subplot 121
% plot(f,abs(baila_F),'b');
% 
% subplot 122
% plot(f,abs(baila_FF),'r');


y=xlsread('dataset_1.xlsx')
