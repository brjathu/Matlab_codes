n=-100:100;
u=@(n) n>=0;
d=@(n) n==0;
one=@(n) n==n;
% x1=(-1).^(n/5).*(mod(n,5)==0);
% stem(n,x1)

% x2=cos(pi/3*n).*u(n);
% stem(n,x2)

% x3=u(n)+u(n-4)-2*u(n-8);
% stem(n,x3)

% xn1=@(n) d(n)+2*d(n-1)+3*d(n-2)+d(n-4);
% xn2=@(n) u(n)-u(n-4);
% 
% xn=xn1;
% yn1=@(n) (-1).^n.*xn(n)+2*xn(n-1);
% 
% 
% z=conv(xn1(n),xn1(n),'same');
% stem(n,z)
% axis([-10 10 -1 20]);


% a=[1 1];
% b=[1 -0.5];
% zplane(a,b);
% hn=filter(a,b,d(n));
% % stem(n,hn)
% % p=conv(hn,cos(0.25*pi*n.*u(n)),'same');
% stem(n,hn);
% axis([-10 10 -2 2]);

x=[155 160 165 170 175 180];
f=[4 11 20 24 17 4];
a=[]
l=0;
for i=1:length(x)
    for j=1:f(i)
        a=[a x(i)];
        l=l+x(i)^2;
    end
end
l
mean(a)
var(a)