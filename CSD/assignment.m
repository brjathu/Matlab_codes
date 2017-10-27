clearvars
L = 0.062;
R =0.5;
n = 5;

kt = 0.026; %Mn/A 
kb = 0.02; %V/rad.s-1

Jeq = 0.00001; %kg/m2
beq = 0.001; %Nm/rad.s-1

for i=1:10
    %run through iteration and change one value and plot the graph
    b2 = L*Jeq;
    b1 = L*beq + R*Jeq;
    b0 = R*beq + kb*kt;
    a0 = kt/n;
    
    sys = tf([a0] , [b2 b1 b0 0]); %generating system transfer function
    step(sys);
    grid on;
    axis([0 0.2 0 0.8]);
    title('Step responce of the link position','FontWeight','bold','FontSize',12)
    ylabel('Joint Position [rad]','FontSize',12); 
    xlabel('Time [s]','FontSize',12);

    legendInfo{i} = sprintf(strcat('n = ',num2str(n))); %ploting the legend for each iteration
    h=legend('Location','eastoutside');
    set(h,'FontSize',12);
    hold on;
    
    display(stepinfo(sys))
    n = n + 5
end
legend(legendInfo);
