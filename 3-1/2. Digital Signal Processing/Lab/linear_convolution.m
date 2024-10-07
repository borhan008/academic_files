clear all
clc
close all
x = [2 1 2 1];
nx = 0:3;
h = [1 2 3 4];
nh = 0:3;
b = [5 6 7 8];
nb = 0:3;
y = conv(x, h);
ny = nx(1) - nh(1):nx(length(x)) + nh(length(h));

subplot(3, 1, 1);
stem(nx, x);
xlabel('n-->');
ylabel('x-->');
title('first sequence');
grid on;

subplot(3, 1, 2);
stem(nh, h);
xlabel('n-->');
ylabel('h-->');
title('second sequence');
grid on;

subplot(3, 1, 3);
stem(ny, y);
xlabel('n-->');
ylabel('y-->');
title('Linear Convolved sequence');
grid on;

disp('First Sequence is :');
x
disp('Second sequence is :');
h
disp('Linear convolution is :');
y
