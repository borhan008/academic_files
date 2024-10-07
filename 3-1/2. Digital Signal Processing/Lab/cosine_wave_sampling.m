clear all
clc
close all

f1=input('The Frequency of the first sine wave in Hz :');
A1=input('Amplitude of first sine wave:');
f2=input('The frequency of the second sine wave in Hz:');
A2=input('amplitude of second Sine wave:');
fs=input('enter the sampling frequency in Hz:');
p=input('the number periods for display=');
teta=input('Phase Shift for First Wave:');

t = 0:0.0001:p*(1/f1);
xf1 = A1*cos(2*pi*f1*t + teta);

subplot(2,2,1);
plot(t,xf1);
xlabel('time in seconds-->');
ylabel('amplitude-->');
title('plot of first cosine wave');
axis([0 (p*(1/f1)) -1.2 1.2]);
grid on;

xf2 = A2*cos(2*pi*f2*t);
subplot(2,2,2);
plot(t,xf2,'r -',t,xf1)
xlabel('Time in seconds-->');
ylabel('Amplitude-->');
title('plot of Second Cosine wave');
axis([0 (p*(1/f1)) -1.2 1.2]);
grid on;

xsum = xf1 + xf2;
subplot(2,2,3);
plot(t,xsum);
xlabel('Time in seconds-->');
ylabel('Amplitude-->');
title('Plot of summed cosine waves');
axis([0 (p*(1/f1)) -2.2 2.2])
grid on;

ts = 0:1/fs:p*(1/f1);
xs = A1*cos(2*pi*f1*ts + teta) + A2*cos(2*pi*f2*ts);
nt = 0:length(ts)-1;
subplot(2,2,4)
stem(nt,xs);
axis([0 (length(nt)-1) -2.2 2.2]);
title('plot of sampled signal');
grid on;

ts = 0:1/fs:1;
xs = A1*cos(2*pi*f1*ts) + A2*cos(2*pi*f2*ts);
xfftmag2 = abs(fft(xs));
figure(2),subplot(2,1,1)
plot(xfftmag2);
subplot(2,1,1)
xlabel('frequency in hz-->');
ylabel('Amplitude-->');
title('the plot of cosine wave in the frequency domain');
grid on;

T = 1/fs;
n = 0:T:1-T;                      
t = linspace(-0.5, 1.5, 2000);    

ya = zeros(1, length(t));

for k = 1:length(n)
    ya = ya + xs(k) * sinc((t - n(k)) / T);
end

subplot(2,1,2)
plot(t, ya);
xlabel('Time (seconds)');
ylabel('Amplitude');
title('Reconstructed signal using sinc interpolation');
axis([0 0.12 -2 2]);
grid on;
