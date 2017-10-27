% NUMERICAL COMPUTATION OF FOURIER SERIES COEFFICIENTS

% approximate the integral as a summation

% x = abs(cos(pi*t));     % PERIODIC SIGNAL

T = 1;                    % PERIOD
wo = 2*pi/T;

M = 200;                  % DISCRETIZATION OF THE TIME AXIS
delT = T/M;
t = [0:delT:T-delT];      % TIME AXIS
x = abs(cos(pi*t));       % COMPUTE SAMPLES OF x(t) ON GRID

N = 20;                   % COMPUTE FS COEFFICIENTS C(0)...C(N)
J = sqrt(-1);
c = zeros(1,N+1);         % COMPUTE C(k) WITH A SUM
c(1) = 1/T * delT * sum(x);
for k = 1:N
    c(k+1) = 1/T * delT * sum(x .* exp(-J*k*wo*[0:M-1]*delT));
    % note: because Matlab indexing begins with 1 instead of 0,
    % it is necessary to add 1 to the index. c(k+1) means 'c(k)'!
end

% NOTE: C(-k) = conj(C(k)) because x(t) is a REAL signal.
% Therefore only compute c(k) for k >= 0.

figure(1)                 % PLOT THE LINE SPECTRUM
stem([0:N]/T,abs(c),'.')  % (THE LINE SPECTRUM IS A PLOT OF C(K))
xlabel('Herz')
ylabel('|C(k)|')
title('LINE SPECTRUM')


t = [0:500]/500*2*T;       % PLOT TWO PERIODS OF THE SIGNAL
y = c(1) * ones(size(t));  % SYNTHESIZED FROM THE NUMERICALLY
for k = 1:N                % OBTAINED FS COEFFICIENTS
    y = y + c(k+1)*exp(J*k*wo*t) + conj(c(k+1))*exp(-J*k*wo*t);
end
figure(2)
plot(t,real(y));