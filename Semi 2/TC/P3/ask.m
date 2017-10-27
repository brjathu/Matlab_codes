function []=ask(bit_pattern,n)
cf=1.2E6;            %carrier frequency 1.2 MHz
%sampling frequency 100MHz, i.e.,samples taken at intervals of 1e-8s.
%bit rate of 400kbps, i.e.,250 samples per bit
delt=1E-8;
fs=1/delt;
spb=250;        %samples per bit
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

%ASK Modulation
ASK=[];
if n==2
    for bit_no=1:1:length(bit_pattern)
        if bit_pattern(bit_no)==1
            t_bit=(bit_no-1)*spb*delt:delt:(bit_no*spb-1)*delt;
            Wc=cf*2*pi*t_bit;
            mod=(1)*sin(Wc);
        elseif bit_pattern(bit_no)==0
            t_bit=(bit_no-1)*spb*delt:delt:(bit_no*spb-1)*delt;
            Wc=cf*2*pi*t_bit;
            mod=(0)*sin(Wc);
        end
        ASK=[ASK mod];
    end
    subplot(2,1,2);plot(t,ASK);
    ylabel('Amplitude');
    title('ASK Modulated Signal');
    axis([0 tmax -2 2]);
end


if n==4
    for bit_no=1:2:length(bit_pattern)
        if bit_pattern(bit_no)==0 && bit_pattern(bit_no+1)==0
            
            t_bit=(bit_no-1)*spb*delt:delt:((bit_no+1)*spb-1)*delt;
            Wc=cf*2*pi*t_bit;
            mod=(0)*sin(Wc);
        elseif bit_pattern(bit_no)==0 && bit_pattern(bit_no+1)==1
            t_bit=(bit_no-1)*spb*delt:delt:((bit_no+1)*spb-1)*delt;
            Wc=cf*2*pi*t_bit;
            mod=(1/3)*sin(Wc);
        elseif bit_pattern(bit_no)==1 && bit_pattern(bit_no+1)==1
            t_bit=(bit_no-1)*spb*delt:delt:((bit_no+1)*spb-1)*delt;
            Wc=cf*2*pi*t_bit;
            mod=(2/3)*sin(Wc);
        elseif bit_pattern(bit_no)==1 && bit_pattern(bit_no+1)==0
            t_bit=(bit_no-1)*spb*delt:delt:((bit_no+1)*spb-1)*delt;
            Wc=cf*2*pi*t_bit;
            mod=(1)*sin(Wc);
        end
        ASK=[ASK mod];
    end
    subplot(2,1,2);plot(t,ASK);
    ylabel('Amplitude');
    title('ASK Modulated Signal');
    axis([0 tmax -2 2]);
end
end

