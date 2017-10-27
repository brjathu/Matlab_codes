%fsk.m
close all;
clear all;

bit_pattern=[ 1 0 0 1 1 0 1 1 1 0 1 1 0 0 0 1 1 1 1 0 0 0 1 1 ];
cf0=0.4E6;      %carrier frequency to encode binary 0, 0.8 MHz
cf1=0.8E6;      %carrier frequency to encode binary 1, 2.4 MHz
cf2=1.2E6;
cf3=2.4E6;
%sample frequency 100 MHz, i.e samples taken at intervals of 1e-8
%bit rate 250kbps, i.e 250 samples per bit
delt=1E-8;
fs=1/delt;
spb=250;
tmax=(spb*length(bit_pattern)-1)*delt;
t=0:delt:tmax;

%Generation of the binary info signal
bits=zeros(1,length(t));
for bit_no=1:1:length(bit_pattern)
    for sample=1:1:spb
        bits((bit_no-1)*spb+sample)=bit_pattern(bit_no);
    end
end

figure;
subplot(2,1,1);plot(t,bits);
ylabel('Amplitude');
title('Info Signal');
axis([0 tmax -2 2]);

%FSK Modulation
FSK=[];
for bit_no=1:1:length(bit_pattern)
    if bit_pattern(bit_no)==1
        t_bit=(bit_no-1)*spb*delt:delt:(bit_no*spb-1)*delt;
        Wc=cf1*2*pi*t_bit;
        mod=(1)*sin(Wc);
    elseif bit_pattern(bit_no)==0
        t_bit=(bit_no-1)*spb*delt:delt:(bit_no*spb-1)*delt;
        Wc=cf0*2*pi*t_bit;
        mod=(1)*sin(Wc);
    end
    FSK=[FSK mod];
end
subplot(2,1,2);plot(t,FSK);
ylabel('Amplitude');
title('FSK Modulated Signal');
axis([0 tmax -2 2]);



%FSK Modulation
FSK=[];
for bit_no=1:2:length(bit_pattern)
        if bit_pattern(bit_no)==0 && bit_pattern(bit_no+1)==0
            
            t_bit=(bit_no-1)*spb*delt:delt:((bit_no+1)*spb-1)*delt;
            Wc=cf0*2*pi*t_bit;
            mod=(1)*sin(Wc);
        elseif bit_pattern(bit_no)==0 && bit_pattern(bit_no+1)==1
            t_bit=(bit_no-1)*spb*delt:delt:((bit_no+1)*spb-1)*delt;  
            Wc=cf1*2*pi*t_bit;
            mod=(1)*sin(Wc);
        elseif bit_pattern(bit_no)==1 && bit_pattern(bit_no+1)==0
            t_bit=(bit_no-1)*spb*delt:delt:((bit_no+1)*spb-1)*delt;
            Wc=cf2*2*pi*t_bit;
            mod=(1)*sin(Wc);
        elseif bit_pattern(bit_no)==1 && bit_pattern(bit_no+1)==1
            t_bit=(bit_no-1)*spb*delt:delt:((bit_no+1)*spb-1)*delt;
           Wc=cf3*2*pi*t_bit;
         mod=(1)*sin(Wc);
        end
        FSK=[FSK mod];
    end
subplot(2,1,2);plot(t,FSK);
ylabel('Amplitude');
title('FSK Modulated Signal');
axis([0 tmax -2 2]);

