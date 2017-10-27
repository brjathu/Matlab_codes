function music(f,T)
Fs=8000;
t=0:1/Fs:T;
n=T*Fs;
y=exp(-10/T*t).*sin(2*pi*f*t);
plot(t,y,'r');
soundsc(y,Fs);

end