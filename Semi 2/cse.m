x=1:0.001:6;
a=(1+sqrt(5))/2;
b=(sqrt(5)-1)/2;

% fx=1/sqrt(5)*(a.^x-(b.^x)*cos(pi*x));
% px=x^3/15-11*x^2/30+11*x/10+1/5;
f

for i=1:1:6000
    x=i/1000;
    fx(i)=1/sqrt(5)*(a.^x-(b.^x)*cos(pi*x));
    px(i)=x^3/15-11*x^2/30+11*x/10+1/5;
end

plot(fx,'r');
hold on
plot(px);

