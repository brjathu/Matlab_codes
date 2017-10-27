close all
clear all
num=100000;
bit_stream = randi([0 1], num,1);
s=zeros(num,1);
BER = zeros(16,1);
N0_val = zeros(16,1);
for g=-5:1:10
   
    for k = 1:num
        if(bit_stream(k)==0)
            s(k,1)=1;
        else
            s(k,1)=1i;
        end
    end

    
    N0 = 1/(10^(0.1*g));
    N0_val(g+6)=N0;
    nr = sqrt(N0/2).*randn(num,1);
    nc = sqrt(N0/2).*randn(num,1);

    n = nr + 1i.*nc;

    r = s + n;
    out = zeros(num,1);
    error = 0;
    for j=1:num
        if(abs(r(j,1)-1)<abs(r(j,1)-1i))
            out(j,1)=0;
        else
            out(j,1)=1;
        end

        if(out(j,1)~= bit_stream(j,1))
            error = error + 1;
        end
    end

    BER(g+6) = error/num
end

semilogy(-5:10,BER,'r')
hold on
semilogy(-5:10,(qfunc(sqrt(1./N0_val))));