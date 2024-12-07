clc;
clear all;
close all;
bits = [1 0 1 0 0 0 1 1 0];
bitrate = 1; % bits per second
figure;
[t,s] = prz(bits,bitrate);
plot(t,s,'LineWidth',3);
axis([0 t(end) -1.1 1.1])
grid on;
title(['Polar RZ: [' num2str(bits) ']']);
function [t,x] = prz(bits, bitrate)
% PRZ Encode bit string using polar RZ code.
% [T, X] = PRZ(BITS, BITRATE) encodes BITS array using polar RZ
% code with given BITRATE. Outputs are time T and encoded signal
% values X.
T = length(bits)/bitrate; % full time of bit sequence
n = 200;
N = n*length(bits);
dt = T/N;
t = 0:dt:T;
x = zeros(1,length(t)); % output signal
for i = 0:length(bits)-1
 if bits(i+1) == 1
 x(i*n+1:(i+0.5)*n) = 1;
 x((i+0.5)*n+1:(i+1)*n) = 0;
 else
 x(i*n+1:(i+0.5)*n) = -1;
 x((i+0.5)*n+1:(i+1)*n) = 0;
 end
end
end