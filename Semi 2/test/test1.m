
% t = 0:0.001:2*pi; 
% plot(t,sin(t),t,sin(2*t),'r--')
% title('My Function');
% xlabel('t(s)');
% ylabel('y(t)');
% axis([0 2*pi -1.2 1.2]);

n = -20:50;
u =@(n) n >= 0;
d=@(n) n==0;
% stem(n,u(n)-u(n-4))
% stem(n, n .* u(n) - 2 *(n - 4) .* u(n - 4) + (n - 8) .* u(n - 8))
% stem(n,d(n) - 2 *d(n - 4));
% stem(n,(0.9).^n.*(u(n) - u(n - 20)))
% stem(n,cos(0.12 *pi*n) .*u(n))


% c1=conv(u(n)-u(n-4),single(u(n)),'same');
% stem(n,c1)
% title('example');
% xlabel('n');
% ylabel('x(n)');


f=u(n)-u(n-4);
g = n .* u(n) - 2 * (n - 4) .* u(n - 4) + (n -8) .*u(n - 8);

% stem(n,conv(f,f,'same'));
a=conv(f,f,'same');
hold on
stem(n,a,'r')
stem(n,f)








