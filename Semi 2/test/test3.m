x1=[0 0 0 0 1 1 0 0 0];
x2=[0 1 0 1 0 1 0 1 0];


% y1=mydiffeq(x1);
% y2=mydiffeq(x2);
% y3=mydiffeq(x1+x2*2);
% plot(y1)
% hold on
% plot (y2,'r')
% plot(y3,'g')
% plot(y1+y2*2,'r.')

% y4=mydiffeq(x1);
% y5=mydiffeq([0 0 0 0 0 1 1 0 0 0]);
% y6=mydiffeq( [1, zeros(1,100)]);
% hold on
% % stem(y4)
% % stem(y5,'r')
% stem(y6)


u=@(n) n>=0;
u(n)
n=-10:106;
h=mydiffeq(d(n));
x = cos(pi*n/8) .*(u(n)-u(n-50));
z=mydiffeq(x);
y=conv(x,h,'same')
% stem(y)
stem(n,y)
hold on
% stem(n,x)
