clear all
clc
spb=250;
bit_pattern=[1 0 1 0 1 0 0 0 1 ];
ts=1E-8;
tmax=(length(bit_pattern)*spb-1)*ts;
t=0:ts:tmax;
x=zeros(1,length(t));
%generating info signal
for i=1:length(t)-1
    x(i)=bit_pattern(ceil(i/spb));
    
end

plot(t,x)

fsk=[]
for i=1:length(bit_pattern)
    if (bit_pattern(i))==1
        t1=(i-1)*spb*ts:ts:(i*spb-1)*ts;
        mod=1*cos(2*pi*2.4E6*t1);
    else 
        t1=(i-1)*spb*ts:ts:(i*spb-1)*ts;
        mod=1*cos(2*pi*0.8E6*t1);
    end
    fsk=[fsk mod];
end

figure
plot(t,fsk)

