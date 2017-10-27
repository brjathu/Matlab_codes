G=@(t)  0*(t<-2)   +  (-4-2*t).*(t>=-2 & t<0)   +   (-4+3*t).*(t>=0 & t<4)   +  (16-2*t).*(t>=4 & t<8)   + 0*(t>=8);

t=-10:0.01:10;

% plot(t,G(t));
% hold on
% plot(t,-2*G((t-1)/2),'r');

% 
% y=diric(t,600);
% plot(t,y)

% y=sawtooth(t);
% plot(t,y)

% y=square(t);
% plot(t,y)

% y=tripuls(t,0.1);
% plot(t,y)

% y=sinc(t);
% plot(t,y)

n=0:40;
d=@(n) n==0;

x1=cos(2*pi*0.1*n);
x2=cos(2*pi*0.4*n);
x=2*x1-3*x2;

a=[2.2403 2.4908 2.2403];
b=[1 -0.4 0.75];

% y1=conv(x1,h,'same');
% y2=conv(x2,h,'same');
% y=conv(x,h,'same');
% yt=2*y1-3*y2;
% d=y-yt;
% stem(n,d)


% xd=[zeros(1,10) x];
% yd=conv(h,xd,'same');
% d=yd-y;
% stem(n,d)






%
% n=-1:20;
% u=@(n) n>=0;
% d=@(n) n==0;
% g=@(n) 10*exp(-pi/4)*sin(3*pi*n/16).*u(n);
% 
% stem(n,g(n/3))


%
% n=0:100;
% no=randn(1,length(n));
% 
% x=sin(0.1*pi*n);
% xno=x+no;
% % stem(n,xno)
%  
% 
% stem(n,y)



ts=0.00001;
t=-0.1:ts:0.1;
m=2+sin(2*pi*1000*t);
c=cos(2*pi*10000*t);
g=m.*c;
y=abs(g);
cutoff=2000;
[a b]=butter(5,2*cutoff*ts);
z=filter(a,b,y);


figure (1)
plot(t,m/5,t,z);
legend('Input Signal','Output Signal')
xlabel ('time')
ylabel('amplitude')
title ('Case Study')
% Finding the FT of the signals
M=abs(fftshift(fft(m)));
G=abs(fftshift(fft(g)));
Y=abs(fftshift(fft(y)));
Z=abs(fftshift(fft(z)));
% Creating the vector for the frequency axis
f=[-length(t)/2:length(t)/2-1]/(length(t)*ts);
% Plotting all FT on one sheet, in a 2x2 matrix format
figure (2)
subplot (221)
plot(f,M)
subplot(222)
plot(f,G)
subplot (223)
plot(f,Y)
subplot(224)
plot(f,Z)










