PM=40;
ess= 0.02;

%open loop plant
numerator = 3 * [1 3];
denominator = conv([1 4],[1 3 20]);

G= tf(numerator, denominator);
bode(G); 
grid on;
hold on;
[gain, phase] = bode(G,15);


10*log(gain)
phase

K= 1/gain
G1=K*G;
bode(G1);

phi_le = PM - (180 + phase)


syms x
ple = double(abs(vpasolve(23.9977==180/pi*atan(15/x)- 180/pi*atan(x/15), x)))
zle = double(15*15 / abs(ple))

CLe=tf( [1  zle]  , [1 ple]);
% bode(CLe)
[gainLe,phaseLe]=bode(CLe,15)

KLe=1/gainLe
G2=KLe*CLe*G1;
bode(G2); grid on; hold on;
legend('Initial','Bandwidth adjusted', 'with lead compensator')


z=0.9446;
p=0.1;
CLa=tf([1 z],[1 p]);

G3 = CLa*G2;
bode(G3); grid on; hold on;
legend('Initial','Bandwidth adjusted', 'with lead compensator','with lag compensator' )
