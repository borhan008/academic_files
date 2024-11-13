clc;
clear all;
close all;

Am = 8; % Amplitude
n=8; % n-bit PCM System
sample = 30; % Number of sample in a period

x = 0:(2*pi/sample):4*pi;
analog_signal = Am*sin(x);

%--  Analog Signal --%
subplot(3, 1, 1);
plot( analog_signal); % plot for continous signal
title("Analog Signal"); 
xlabel("Time"); ylabel("Amplitude");

%-- Sampling ---%

subplot(3, 1, 2);
stem(analog_signal);  % stem  for discrete signal
title("Sampling Signal"); 
xlabel("Time"); ylabel("Amplitude");

%-- Quantizing --%

L = 2^n; % Level
Vmax = Am; Vmin = -Vmax;
del =(Vmax - Vmin)/L; % step size = V(peak to peak)/Level
part = Vmin+del : del : Vmax - del ; % quantized the levels
code = Vmin + (del/2) : del : Vmax - (del/2); %defining quantize  value
[ind, q] = quantiz(analog_signal, part, code); % ind = index, q=quantized value

subplot(3, 1, 3);
stem(q, '.');
title("Quantized Signal"); 
xlabel("Time"); ylabel("Amplitude");

%-- Encoding --%
figure
code2 = de2bi(ind, "left-msb"); % Convert decimal to binary
k=1;
for i=1:length(ind)
    for j=1:n
        coded(k) = code2(i, j); % convert matrix to a coded row vector
        k=k+1;
    end
end
subplot(2, 1, 1);
stairs(coded); grid on;
axis([0 100 -0.5 1.5]);
title("Encoded Signal"); 
xlabel("Time"); ylabel("Amplitude");


%-- Reconstruction from PCM Signal --%
qunt = reshape(coded, n, length(coded)/n); %convert from serial to parallel
index = bi2de(qunt', "left-msb");
q=Vmin+(del/2)+del*index;
subplot(2, 1, 2); grid on;
plot(q); grid on;
title("Reconstructed Analog Signal"); 
xlabel("Time"); ylabel("Amplitude");

