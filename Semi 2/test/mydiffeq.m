function y=mydiffeq(x)
%MYDIFFEQ Summary of this function goes here
%   Detailed explanation goes here
y=zeros(1,length(x)-1);
for i=1:length(x)-1
    if i==1
        y(1)=x(1);
    else
        y(i)= x(i) + 2 *x(i - 1) - 1.1 *y(i - 1);
    end
end


end

