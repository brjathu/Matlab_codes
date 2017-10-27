n=0:15
x=1+cos(n*pi/4)-0.5*cos(3*pi*n/4)

y=fft(x,16)
abs(y)
stem(y)