function xr = recon(t,range,xn,Ts)
% Sum over an interval, time t and samples xn.
tmp = 0;
for n = -range:range;
tmp = tmp + (xn(round(length(xn)/2)+n).*sinc((t-n*Ts)/Ts));
end
xr = tmp;
