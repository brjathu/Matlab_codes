R1=1000; R2=2000; C=200*10^-6;
a=(R1+R2)/R1/R2/C; b=1/(R1*C);
v0=2;
dur=0.6
t=[0:0.01:dur];

yH=v0*exp(-a*t);

yE= (b/a)*(1-exp(-a*t));

yT=yH+ yE;

subplot(311);plot(t,yH);axis([0 dur 0 2]);
ylabel('Homogeneous responce [V]'); grid on;

subplot(312);plot(t,yE);axis([0 dur 0 2]);
ylabel('Exogenous responce [V]'); grid on;

subplot(313);plot(t,yT);axis([0 dur 0 2]);
ylabel('Total responce [V]'); grid on;