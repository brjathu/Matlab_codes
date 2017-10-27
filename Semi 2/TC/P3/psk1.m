ts=1E-6;
bit_pattern=[1 0 1 0 0 0 1 1];
spb=250;
tmax=(length(bit_pattern)*spb-1)*ts;
t=0:ts:tmax;



%generating info signal
x=[];
for i=1:length(bit_pattern)
    if(i==1)
        x(1:spb)=bit_pattern(1);
    else
        x((i-1)*spb+1:(i*spb))=bit_pattern(i);
    end
end
% plot(t,x)

%psk
psk=[];
for i=1:length(bit_pattern)
    if (bit_pattern(i)==0)
        t1=(i-1)*spb*ts:ts:((i*spb)-1)*ts;
        mod=cos(2*pi*4E3*t1);
    else (bit_pattern(i)==1)
        t1=(i-1)*spb*ts:ts:((i*spb)-1)*ts;
        mod=cos(2*pi*4E3*t1+pi);
    end
    psk=[psk mod];
end
plot(t,psk);
    
        

