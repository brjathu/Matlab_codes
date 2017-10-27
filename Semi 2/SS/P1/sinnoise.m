ts=1E-4;
fs=1/ts;
t=0:ts:5E-2;

x=sin(2*pi*100*t);
subplot(2,2,1);plot(t,x)

y=x+wgn(1,length(t),-20);
subplot(2,2,2);plot(t,y)


g=conv(y,[1 1 1 1 1 1 1]/7,'same');
subplot(2,2,3);plot(t,g)

X=0.00002*abs(fftshift(fft(x)));
Y=0.00002*abs(fftshift(fft(y)));
F=fs/2*linspace(-1,1,length(t));
c=500;
subplot(2,2,4);plot(F,Y);
z=[]
for i=4:length(x)-3
    z(i)=1/7*(y(i-3)+y(i-2)+y(i-1)+y(i)+y(i+1)+y(i+2)+y(i+3));
end

figure
plot(t(3:length(x)-3),z(3:length(x)-3))
