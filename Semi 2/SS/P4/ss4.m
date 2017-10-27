 clear all
clc
close all
uimp=@(x) (x==0);
ustep=@(x) (x>=0);

num=[1 1 2];
den=[1 0 -0.25];
n=-50:50;
xn_f=filter(num,den,uimp(n));
[r, p, k]=residuez(num,den);

xn_p=r(1)*p(1).^n.*ustep(n) + r(2)*p(2).^n.*ustep(n) + k*uimp(n);

subplot 121
stem(n,xn_f,'b--.');
title('Inverse Transform -convolution Method');
ylabel('x_f[n]');
xlabel('n');

subplot 122
stem(n,xn_p,'r--.');
title('Inverse Transform -partial fraction method');
ylabel('x_p[n]');
xlabel('n')
figure
zplane([4.43e-4 8.86e-4 4.43e-4],[1 -1.94 0.94]);