
Ts = 1/4; % sampling time
t = -50/Ts:0.001:50/Ts;
n = -50/Ts:1:50/Ts;
% figure;
% plot(t,funx(t*Ts),'b-')
% xlabel('t');
% ylabel('Amplitude')
% figure;
% stem(n,funx(n*Ts),'k-')
% xlabel('n');
% ylabel('Amplitude')



xn = funx(n*Ts);
figure

plot(t,funx(t),'g') %the original signal
hold on
plot(t,recon(t,60,xn,Ts),'r--') % reconstructed signal
axis([-20 20 -0.5 2])