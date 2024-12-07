clc;
close all;
clear all;
n=input('Enter n value for n-bit PCM system : ');
n1=input('Enter number of samples in a period i.e. sampling fequency: ');
L=2^n;
% Signal Generation where Amplitude Of signal is 10v
x=0:1/100:4*pi;
y=10*sin(x);
subplot(3,1,1);
plot(y);
title('Analog Signal');
ylabel('Amplitude');
xlabel('Time');
x=0:2*pi/n1:4*pi;% n1 number of samples have to be selected
s=10*sin(x);
subplot(3,1,2);
stem(s);grid on;
title('Sampled Sinal');
ylabel('Amplitude');
xlabel('Time');
% Quantization Process
vmax=10;
vmin=-vmax;
del=(vmax-vmin)/L;
part=vmin:del:vmax ; % level are between vmin and vmax with difference of del
code=vmin-(del/2):del:vmax+(del/2); % Contaion Quantized valuses
[ind,q]=quantiz(s,part,code); % Quantization process
% ind contain index number and q contain quantized values
l1=length(ind);
l2=length(q);
for i=1:l1
if(ind(i)~=0) % To make index as binary decimal so started from 0 to N
ind(i)=ind(i)-1;
end
i=i+1;
end
ind;
for i=1:l2
if(q(i)==vmin-(del/2)); % To make quantize value inbetween the levels
q(i)=vmin+(del/2);
end
end
q;
subplot(3,1,3);
stem(q);grid on; % Display the Quantize values
title('Quantized Signal');
ylabel('Amplitude');
xlabel('Time');
% Encoding Process
figure
code=de2bi(ind,'left-msb'); % Cnvert the decimal to binary
k=1;
for i=1:l1
for j=1:n
coded(k)=code(i,j); % convert code matrix to a coded row vector
j=j+1;
k=k+1;
end
i=i+1;
end
coded
subplot(2,1,1); grid on;
stairs(coded);% Display the encoded signal
axis([0 100 -2 3]);
title('Encoded Signal');
ylabel('Amplitude');
xlabel('Time');
% Demodulation Of PCM signal
qunt=reshape(coded,n,length(coded)/n);
index=bi2de(qunt','left-msb'); % Getback the index in decimal form
q=del*index+vmin+(del/2); % getback Quantized values
subplot(2,1,2); grid on;
plot(q);% Plot Demodulated signal
title('Demodulated Signal');
ylabel('Amplitude');
xlabel('Time');