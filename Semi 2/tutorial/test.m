% t=linspace(0,6,60);
% f=@(x) x*(x>=0 & x<=1)+(1/x)*(x>=1 & x<=6);
% y=[];
% for i=1:60
%    y(i)=f(t(i));
% end
% stem(t,y)

% Ts=0.1;
% N=100;
% t=[0:N]*Ts;
% x=sin(2*t);
% y=x.^2;
% plot(t,x,'r-',t,y,'g')
% grid on

% music(262,5)
% music(262*2,5)
% music(262*3,5)
% music(262*4,5)



% Fs=8000;
% t=0:1/Fs:1000/Fs;
% f1=400;f2=440;
% y=cos(2*pi*f1*t)+2*sin(2*pi*f2*t);
% % plot(t,y);
% f=fft(y);
% plot(f);