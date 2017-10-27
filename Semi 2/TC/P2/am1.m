%am1.m
%generation and study of AM signals
%initializations and clearing of workspace
close all;
clear all;
clc;
%Am modulation is one of the fundamental methods of communication.
%Here the carrier's amplitude is modulated (varied) by the input data
%signal
%---------BASICS----------
%To show how this works we need 2 signals, a carrier and an info signal
%consider a time window of 1ms (0.001s)
%lets say we have a carrier at 50kHz (long wave). Therefore in
%1ms we have 50 oscillations.
%(1E-3=0.001)
%lets define constants we want
%Info signal amplitude _0 Am
%modulation index - u
%carrier amplitude - Ac

Am=1;
u=0.1;
%Ac=1;
Cf=2E6;
Sf=50E3;

%we will represent the signal as samples taken at intervals of 1e-8 s
delt=1E-8;
fs=1/delt;
tmax=1E-3;
t=0:delt:tmax;
Wc=Cf*2*pi*t;
Ws=Sf*2*pi*t;

%-------------Signal generation-----------------
Ac=cos(Wc);     %generate carrier
Xt=Am*cos(Ws)+Am*5*cos(Ws*3); %info signal

subplot(2,1,1);plot(1000*t,Ac);
ylabel('Amplitude');
title('Carrier');
axis([0 0.05 -2 2]);

subplot(2,1,2);plot(1000*t,Xt);
xlabel('Time');
ylabel('Amplitude');
title('Info Signal');
axis([0 0.05 -2 2]);

pause
%-------------AM Analysis----------------
%Now we look at how AM works
%AM is basically described by
%
%   Xm=Ac*(1+u*Xt)
%this is the most fundermental form of AM, which has the full carrier
%component and two sidebands
%generation of Am signal

Xm=Ac.*(1+u*Xt);

%See what it looks like
figure;
plot(1000*t,Xm);
xlabel('Time (ms)');
ylabel('Amplitude');
title('Modulated signal');
axis([0 0.05 -2 2]);
pause

%Frequency domain analysis is also very informative. This shows how the
%frequency composition of the signal

N=tmax/delt;
Xf=0.00002*abs(fft(Xm));
delf=fs/N;
f=0:delf*1E-3:fs*1E-3;
figure;
plot(f(1500:2500),Xf(1500:2500));
axis([1500 2500 0 1.2]);
xlabel('Frequency (kHz)');
ylabel('Amplitude');
title('Modulated siganl (Frequency domain)');
pause
%zoom in on the frequency region of interset
figure;
plot(f(1800:2200),Xf(1800:2200));
axis([1800 2200 0 1.2]);
xlabel('Frequency (kHz)');
ylabel('Amplitude');
title('Modulated signal (Frequency domain');
