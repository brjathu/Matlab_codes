del=@(n) 1*(n==0)+0;

n=0:10


X=4*del(n)+3*del(n-1)+2*del(n-2)+1*del(n-3)


fft(X,6)

