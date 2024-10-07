clear 
clc 
close all 
x1 = [2 1 2 1]; 
nx1 = 0:length(x1)-1; 
subplot(3,1,1); 
stem(nx1, x1);
xlabel('n-->');
ylabel('x1--');
title('First sequence');
grid on;

x2 = [1 2 3 4]; 
nx2 = 0:length(x2)-1; 
subplot(3,1,2); 
stem(nx2, x2);
xlabel('n-->');
ylabel('x2-->');
title('Second sequence');
grid on;

N = 4; 
if length(x1) > N
    error('N must be >= the length of x1');
end;
if length(x2) > N
    error('N must be >= the length of x2');
end;

x1 = [x1, zeros(1, N - length(x1))]; 
x2 = [x2, zeros(1, N - length(x2))];
m = [0:N-1];

for n = 0:N-1
    y(n+1) = sum(x2(mod(n - m, N) + 1) .* x1); 
end;

ny = 0:3; 
subplot(3,1,3);
stem(ny, y);
xlabel('n-->'); 
ylabel('y-->');
title('Circular Convolution');
grid on;

disp('First seq is:'); 
x1
disp('Second seq is:'); 
x2
disp('Circular convolution is:'); 
y
