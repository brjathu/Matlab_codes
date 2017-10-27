% close all;
clear all;
ws=20;
wc=5;
T=2*pi/ws;
N=121;

samp=1001;

w=-ws/2:0.01:ws/2;
n=-N:N;

Hone=@(w) ( 1*(abs(w))<wc).*(w<=ws/2 & w>=-ws/2);
H=@(w) Hone(w-(round(w/ws))*ws);

h=@(n) sinc(wc/pi*n*T)*T*wc/pi;

%rectangular window
winRect=@(n) (n<=(N-1)/2 & n>=-(N-1)/2)*1+0;

%von-hann and Hamming window
alpha=0.56;
winVon=@(n)   alpha+(1-alpha)*cos(2*pi*n/(N-1));

%blackman windows
winBlack=@(n)  0.42+0.5*cos(2*pi*n/(N-1))+0.08*cos(4*pi*n/(N-1));

ht=@(n) h(n).*winRect(n);

Hw=zeros(1,samp);  

for i=1:samp
    x=i-(samp+1)/2;
    for k=-(N-1)/2:(N-1)/2
        Hw(i)=Hw(i)+ht(k)*exp(-1j*(x/samp*ws)*k*T);
    end
end
 
subplot(2,2,1)
plot(w,H(w))

subplot(2,2,2)
plot(n,ht(n));

subplot(2,2,3)
plot(((1:samp)-(1+samp)/2)/(samp-1)*ws,(abs(Hw)))

% x=ceil(wc/ws*samp);
% mag2db(max(abs(out((samp+1)/2:x))-1))


