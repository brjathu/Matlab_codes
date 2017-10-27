close all;
clear all;

AudioFile='sound.wav';
N=22050*4;
f=0.25:0.25:22050;
t=f*4/22050;
Cf=8E3;

Afile=fopen(AudioFile,'r');
if Afile ~= -1
    fseek(Afile,1000,-1);
    Xt=fread(Afile,N,'uchar');
    Xt=(Xt'-128)/(max((Xt)-128));
    subplot(2,1,1);plot(t,Xt);
    axis([1 2 -1 2])
    xlabel('Time (s)');
    ylabel('Amplitude');
    title('Audio signal (Time domain');
    pause
    Xf=abs(fft(Xt));
    subplot(2,1,2);plot(f(1:10000),Xf(1:10000));
    xlabel('Frequency (Hz)');
    ylabel('Real magnitude');
    title('Audio Signal (Frequency domain');
    pause
    
    Wc=2*pi*Cf*t;
    u=0.8;
    Ac=1;
    Xm=Ac*cos(Wc).*(1+u*Xt);
    figure;
    plot(t,Xm);
    xlabel('Time (s)');
    ylabel('Amplitude');
    title('Modulated audio signal (Time domain) Fc=8kHz');
    
    pause
    
    figure;
    Xmf=(abs(fft(Xm))+1);
    plot(f,Xmf);
    axis([5000 11000 0 5000]);
    xlabel('Frequency (hz)');
    ylabel('Real magnitude');
    title('AM modulated audio signal (Frequency domain) Fc=8KHz');
    
    fclose(Afile);
else
    display 'error wav file'
end
