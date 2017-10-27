% y=0.5;
% 
% t=0:0.001:5
% for n=1:5
%     y=y+4/(2*n-1)^2/pi^2*cos((2*n-1)*pi*t);
% end
% 
% plot(t,y);

t=0:0.001:5;
w=2*pi;
f=2+2*cos(w*t)+6*sin(w*t)+4*cos(2*w*t)-2*sin(2*w*t);
plot(t,f);