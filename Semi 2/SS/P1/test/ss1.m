% t=-1:0.001:1;
% A=1;
% omega0=2*pi;
% phi=0;
% x=A*cos(omega0*t*2+phi);
% plot(t,x);
% xlabel('t');
% ylabel('x(t)')
% grid on
% axis([-1 1 -1 1])


t=-10:0.01:10;
C=0.1;
a=-0.3;
x=C*exp(a*t);
plot(t,x)
grid on