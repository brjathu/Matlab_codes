%  x=[6.0 -1.3 -8.0 -11.7 -11.0 -6.0 1.3 8.0 11.7 11.0 6.0 -1.3];
%  n=0:11;
%  t=n*0.3;
%  plot(t,x)
%  title('sin wave sample');
%  xlabel('T(s)')
%  ylabel('y(t)')


% clear all
% clc
% 
% u=@(n) n>=0;
% d=@(n) n==0;
% 
% n=-20:20;
% f = 3 *d(n + 2) - d(n - 1) + 2 *d(n - 3);
% g=u(n+4)-u(n-3);
% a=conv(f,g,'same')
% stem(n,a)


load debug.txt
x=debug;
h = ones(1,11)/11;
y=conv(x,h)
plot(x)
length(x)
length(y)
hold on


y2 = y;
y2(1:5) = [];
y2(end-4:end) = [];

plot(y2,'r.')