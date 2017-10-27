clear all;
% close all;
clc

%% SPECIFICATIONS

A=2;
B=4;
C=1;
t = cputime;                                %start CPU clock for calculate design time

Ap=0.1+0.01*A;                                    %maximum passband ripple ratio
Aa=5*10+B;                                      %minimum stopband attenuation
wa1=200+100*C;                                    %Lower stopband edge
wp1=300+100*C;                                    %Lower passband edge
wp2=600+100*C;                                    %Upper passband edge
wa2=750+100*C;                                    %Upper stopband edge
ws=2*(C*100 + 1000);


% Ap=0.12;                                    %maximum passband ripple ratio
% Aa=54;                                      %minimum stopband attenuation
% wa1=300;                                    %Lower stopband edge
% wp1=400;                                    %Lower passband edge
% wp2=700;                                    %Upper passband edge
% wa2=850;                                    %Upper stopband edge
% ws=2200;                                    %sampling frequency

Bt=min(abs(wp1-wa1),abs(wp2-wa2));          %transition width
wc1=wp1-Bt/2;                               %cutoff frequency 1
wc2=wp2+Bt/2;                               %cutoff frequency 2
    

T=2*pi/ws;                                  %sampling period

%% Kaiser window Design
deltaP=(10^(0.05*Ap)-1)/(10^(0.05*Ap)+1);   %\deltaP
deltaA=10^(-0.05*Aa);                       %\deltaA

delta=min(deltaP,deltaA);                   %find minimum value of deltaP and deltaA
Aa=-20*log10(delta);                        %resulting Aa
Ap=20*log10((1+delta)/(1-delta));           %resulting Ap

fprintf('minimum stopband attenuation Aa of the filter = %f\n',Aa);
fprintf('maximum passband ripple ratio Ap of the filter = %f\n',Ap);

alpha= 0*(Aa<=21)+  (0.5842*(Aa - 21)^(0.4) + 0.07886*(Aa - 21))*(Aa<=50 & Aa>21) + 0.1102*(Aa - 8.7)*(Aa>50);
                                            %calulate alpha form given emperical equation
D= 0.9222 * (Aa<=21)+ (Aa-7.95)/14.36*(Aa>21);
                                            %calulate D form given equation
N=ceil(ws*D/Bt+1);
N=N*(rem(N,2)==1)+(N+1)*(rem(N,2)==0);      %calculate value of N

fprintf('alpha = %f\n',alpha);
fprintf('D = %f\n',D);
fprintf('N = %d\n',N);

%given ideal frequency responce
Hone=@(w) ( 1*(abs(w))<=wc2 & abs(w)>=wc1 ).*(w<=ws/2 & w>=-ws/2);
H=@(w) Hone(w-(round(w/ws))*ws);            %represent ideal frequency resopnce

%impluse responce function
h=@(n) sinc(wc2*n*T/pi)/pi*T*wc2-sinc(wc1*n*T/pi)/pi*T*wc1;
ht=@(n) h(n).*Kaiser(N,alpha,n);            %impluse responce as function of n

w=-ws/2:0.01:ws/2;
n=-(N-1)/2:(N-1)/2;

window=ht(1:(N-1)/2);
window=[fliplr(window) ht(0) window];

e = cputime-t;
fprintf('design CPU time = %f\n',e);
%% Frequency responce
samp=1024+1;
Hw=zeros(1,samp);                           %frequncy responce of the filter

% for i=1:samp                                %calulate frequency responce without fft()
%     x=i-(samp+1)/2;
%     for k=-(N-1)/2:(N-1)/2
% %         Hw(i)=Hw(i)+ht(k)*exp(-1j*(x/(samp-1)*ws)*k*T);
%          Hw(i)=Hw(i)+window(k+(N+1)/2)*exp(-1j*(x/(samp-1)*ws)*k*T);
%     end
% end

[Hw,ww]=(freqz(window));


%% plot the results

subplot(2,2,1)
plot(w,H(w),'k','LineWidth',1);title('Ideal Frequency Response');xlabel('Frequency(rad/s)');ylabel('|H(w)|');
grid on
subplot(2,2,2)
stem(n,((ht(n))),'k','LineWidth',1);title('Impluse Responce hw(nT) using Kaiser window');xlabel('Samples');ylabel('Amplitude');
grid on
subplot(2,2,3)
% plot(((1:samp)-(1+samp)/2)/(samp-1)*ws,mag2db(abs(Hw)),'k','LineWidth',1.5);title('Frequency Response');xlabel('Frequency(rad/s)');ylabel('|H(w)| in dB');
% grid on
plot(ww/2/pi*ws,20*log10(abs(Hw)),'k','LineWidth',1);title('Magnitude response in the requency range 0 to ws/2');xlabel('Frequency(rad/s)');ylabel('|H(w)| in dB');
% grid on
% plot(ww(186:326)/2/pi*ws,20*log10(abs(Hw(186:326))),'k','LineWidth',1);title('Amplitude Response in the passband');xlabel('Frequency(rad/s)');ylabel('|H(w)| in dB');
axis([400 700 -0.02 0.02])
grid on
subplot(2,2,4)
stem(n,((Kaiser(N,alpha,n))),'k','LineWidth',1);title('Kaisar window');xlabel('Samples');ylabel('Amplitude');
grid on
% passBand=ceil((ws/2+wp1)/ws*(samp)):floor((ws/2+wp2)/ws*(samp));
% stopBand1=ceil((ws/2-wa1)/ws*(samp)):floor((ws/2+wa1)/ws*(samp));
% stopBand2=ceil((ws/2+wa2)/ws*(samp)):floor((ws/2+ws/2)/ws*(samp));
% 
% 
% a=min(abs(Hw(passBand)));
% b=max(abs(Hw(passBand)));
% 
% Aa=mag2db(max(abs(Hw(stopBand2))))
% Ap=20*log10(b/a)


%% TESTING 
figure,
n0=(1:501);

x=sin((0+wa1)/2*n0*T)+sin((wp1+wp2)/2*n0*T)+sin((wa2+ws/2)/2*n0*T); 
xx=sin((wp1+wp2)/2*n0*T);         %input signal
lenY=length(window)+length(n0)-1;                                           %length if output DFT

dftX1=fft(x,lenY);                          %input signal n point DFT 
dftX2=fft(window,lenY);                     %DFT of the window
y=ifft(dftX1.*dftX2,lenY);                  %take (n+p-1) point IDFT to get the output


%polt the results
subplot(2,2,1)
stem(n0,x,'k','LineWidth',1);title('Time domain of Input Signal');xlabel('Samples');ylabel('Magnitude');
axis([0 500 -3 3])
grid on
subplot(2,2,2)
stem(1:lenY,(y),'k','LineWidth',0.7);title('Output signal form designed FIR filter');xlabel('Samples');ylabel('Magnitude');
axis([0 600 -2 2])
grid on
subplot(2,2,3)
plot(((1:lenY)-lenY/2)/lenY*ws,abs((dftX1)),'k','LineWidth',1.5);title('Frequency Response of input signal');xlabel('Frequency(rad/s)');ylabel('X(w)');
grid on
subplot(2,2,4)
plot(((1:lenY)-lenY/2)/lenY*ws,abs(dftX1.*dftX2),'k','LineWidth',1.5);title('Frequency Response of output signal');xlabel('Frequency(rad/s)');ylabel('YS(w)');
grid on