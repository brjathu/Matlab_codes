function [ wdc ] = Dolpe(N,r,x)
wdc=0;
x0=cosh(1/(N-1)*acosh(1/r));
for i=1:(N-1)/2
    wdc=wdc+ Chebyshev(N,x0*cos(i*pi/N))*cos(2*pi*x*i/N);
end
wdc=2*wdc+1/r;
wdc=wdc/N;

end


function [ out ] = Chebyshev( k,x )
    if (abs(x)<=1)
        out=cos(k*acos(x));
    else
        out=cosh(k*acosh(x));
    end
end

