function [ out ] = Kaiser( N,alpha,n )

beta=alpha*sqrt(1-(2*n/(N-1)).^2);          %calulate Beta for a given alpha

if(abs(n)<=(N-1)/2)                         
    out=Io(beta,1e-6)/Io(alpha,1e-6);           %CALCULATE KAISER WINDOW 
else
    out=0;
end
end

function [ sumOut ] = Io( x,th )             
%bessial function calulations
sumOut=1;
i=1;
while(1)
    iterVal=(1/factorial(i)*(x/2).^(i)).^2;
    if(iterVal<th)
        break
    end
    sumOut=sumOut+iterVal;
    i=i+1;
end
end

