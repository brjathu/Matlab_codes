u=@(t) t>=0;
t=-10:0.01:10;
% x= u(t)-u(t-1)+ (-u(t-3)+u(t-4));
% t=-10:0.001:10;
% y= trapz(x)
% plot(t,y);
% axis([-10 10 -2 2]);


%3
% g=@(t) exp(-2*t).*u(t);
% f=@(t) u(t)-u(t-1);
% y=conv(g(t),f(t),'same');
% plot(t,y);

% %
% h=exp(-3*t).*u(t) + 2*exp(-1*t).*u(t);
% x=exp(-2*t).*u(t);
% y=conv(x,h,'same');
% plot(t,y)



% x=cos(3*pi*t).*sin(2*pi*t);
% Fs=100;
% NFFT=2^nextpow2(length(x));
% % plot(t,x)
% f=abs(fft(x,NFFT))/(length(x));
% fq=Fs/2*linspace(0,1,NFFT/2+1);
% plot(fq,f(1:NFFT/2+1));
% axis([0 10 -1 1])






