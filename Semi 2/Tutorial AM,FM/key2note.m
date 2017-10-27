function xx = key2note(X, keynum, dur)
% KEY2NOTE Produce a sinusoidal waveform corresponding to a
% given piano key number
%
% usage: xx = key2note (X, keynum, dur)
%
% xx = the output sinusoidal waveform
% X = complex amplitude for the sinusoid, X = A*exp(j*phi).
% keynum = the piano keyboard number of the desired note
% dur = the duration (in seconds) of the output note
%
fs = 11025; %-- or use 8000 Hz
tt = 0:(1/fs):dur;
freq = 440 *(2^((49-keynum)/12));
sig = real( X*exp(j*2*pi*freq*tt));


A = linspace(0, 0.6, (length(sig)*0.2)); %rise 20% of signal
D = linspace(0.6, 0.5,(length(sig)*0.05)); %drop of 5% of signal
S = linspace(0.5, 0.5,(length(sig)*0.4)); %delay of 40% of signal
R = linspace(0.5, 0,(length(sig)*0.35)); %drop of 35% of signal

ADSR = [A D S R] ; %make a matrix

dif = length(sig) - length(ADSR); %find out the difference

x = cat(2, ADSR, zeros(1,dif)); %concatenates a horrizontal (2) ADSR + the difference of ADSR and the signal

xx = sig .* x; %times them together