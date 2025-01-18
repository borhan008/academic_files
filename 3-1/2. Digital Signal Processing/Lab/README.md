# Digital Signal Processing Lab

### 1. Linear Convolution

$$y[n]=x[n]*h[n]=\sum x[k] h[n-k]$$

```matlab
function y = linearConv(x, h)
        N = length(x);
        M = length(h);

        l = N+M-1;

        y = zeros(1, l);

        for n=1:l
            for k=1:N
                hIndex = n-k+1;
                if(hIndex > 0 && hIndex <= M)
                    y(n) = y(n) + x(k)*h(hIndex);
                end
            end
        end
end

fprintf("Enter the value of x:");
x = str2num(input('', 's'));

fprintf("Enter the value of h:");
h = str2num(input('', 's'));

fprintf("By Calculating customly");
y = linearConv(x, h)


fprintf("By Calculating using the built-in function");
y = conv(x,h)

% Plotting
figure;

subplot(3, 1, 1);
stem(x, 'filled');
xticks(0:length(x)+1);
title("Plot of X[n]");

subplot(3, 1, 2);
stem(h, 'filled');
xticks(0:length(h)+1);
title("Plot of h[n]");

subplot(3, 1, 3);
stem(y, 'filled');
xticks(0:length(y)+1);
title("Plot of Convolution Y[n]");

%% Input:
%% 1 3 1
%% 1 3 1 1
```

#### Input

```
1 3 1
1 3 1 1
```

### 2. Associative Property

$$x[n] * (h_1[n] * h_2[n]) = (x[n] * h_1[n]) * h_2[n]$$

#### Using custom function

```matlab
function y = linearConv(x, h)
        N = length(x);
        M = length(h);

        l = N+M-1;

        y = zeros(1, l);

        for n=1:l
            for k=1:N
                hIndex = n-k+1;
                if(hIndex > 0 && hIndex <= M)
                    y(n) = y(n) + x(k)*h(hIndex);
                end
            end
        end
end

function checkAssociativity(x, h1, h2)
    fprintf("By Calculating customly: (x*h1)*h2 ");
    y1 = linearConv( linearConv(x, h1) , h2)
    fprintf("By Calculating customly: (x)*(h1*h2) ");
    y2 = linearConv(x, linearConv(h1, h2))

    if y1 == y2
        fprintf("Associativity is proved");
    else
        fprintf("Associavitiy is not proved");
    end
end

fprintf("Enter the values of x:");
x = str2num(input('', 's'));

fprintf("Enter the values of h1:");
h1 = str2num(input('', 's'));

fprintf("Enter the values of h2:");
h2 = str2num(input('', 's'));

checkAssociativity(x, h1, h2)


%% Input:
%% 1 3 1
%% 1 3 1 1
%% 1 2 3
```

#### Using built-in function

```matlab
function checkAssociativity(x, h1, h2)
    fprintf("By Calculating: (x*h1)*h2 ");
    y1 = conv( conv(x, h1) , h2)
    fprintf("By Calculating: (x)*(h1*h2) ");
    y2 = conv(x, conv(h1, h2))

    if y1 == y2
        fprintf("Associativity is proved");
    else
        fprintf("Associavitiy is not proved");
    end
end

fprintf("Enter the values of x:");
x = str2num(input('', 's'));

fprintf("Enter the values of h1:");
h1 = str2num(input('', 's'));

fprintf("Enter the values of h2:");
h2 = str2num(input('', 's'));

checkAssociativity(x, h1, h2)



%% Input:
%% 1 3 1
%% 1 3 1 1
%% 1 2 3
```

#### Input

```
1 3 1
1 3 1 1
1 2 3
```

### 2. Distributed Property

$$x[n] * (h_1[n] + h_2[n]) = (x[n] * h_1[n]) + (x[n] * h_2[n])$$

#### Using Custom function

```matlab
function y = linearConv(x, h)
        N = length(x);
        M = length(h);

        l = N+M-1;

        y = zeros(1, l);

        for n=1:l
            for k=1:N
                hIndex = n-k+1;
                if(hIndex > 0 && hIndex <= M)
                    y(n) = y(n) + x(k)*h(hIndex);
                end
            end
        end
end

function checkDistributiveProperty(x, h1, h2)
    mx = max(length(h1), length(h2))
    h1(length(h1)+1:mx)=0
    h2(length(h2)+1:mx)=0

    fprintf("By Calculating customly: x*(h1+h2) ");
    y1 = linearConv(x, h1+h2)
    fprintf("By Calculating customly: x*h1+x*h2 ");
    y21 = linearConv(x, h1);
    y22 = linearConv(x, h2);
    y2 = y21 + y22

    if y1 == y2
        fprintf("Distributive  property is proved");
    else
        fprintf("Distributive is not proved");
    end
end

fprintf("Enter the values of x:");
x = str2num(input('', 's'));

fprintf("Enter the values of h1:");
h1 = str2num(input('', 's'));

fprintf("Enter the values of h2:");
h2 = str2num(input('', 's'));

checkDistributiveProperty(x, h1, h2)



%% Input:
%% 1 3 1
%% 1 3 1 1
%% 1 2 3
```

#### Using built-in function

```matlab
function checkDistributiveProperty(x, h1, h2)
    mx = max(length(h1), length(h2))
    h1(length(h1)+1:mx)=0
    h2(length(h2)+1:mx)=0

    fprintf("By Calculating customly: x*(h1+h2) ");
    y1 = conv(x, h1+h2)
    fprintf("By Calculating customly: x*h1+x*h2 ");
    y21 = conv(x, h1);
    y22 = conv(x, h2);
    y2 = y21 + y22

    if y1 == y2
        fprintf("Distributive  property is proved");
    else
        fprintf("Distributive is not proved");
    end
end

fprintf("Enter the values of x:");
x = str2num(input('', 's'));

fprintf("Enter the values of h1:");
h1 = str2num(input('', 's'));

fprintf("Enter the values of h2:");
h2 = str2num(input('', 's'));

checkDistributiveProperty(x, h1, h2)



%% Input:
%% 1 3 1
%% 1 3 1 1
%% 1 2 3
```

#### Input

```
1 2 3
1 1 1 1 1 1 1
1
```

### 3. Commutative Property

$$x[n] * h[n] = h[n] * x[n]$$

#### Usign custom function

```matlab
function y = linearConv(x, h)
        N = length(x);
        M = length(h);

        l = N+M-1;

        y = zeros(1, l);

        for n=1:l
            for k=1:N
                hIndex = n-k+1;
                if(hIndex > 0 && hIndex <= M)
                    y(n) = y(n) + x(k)*h(hIndex);
                end
            end
        end
end

function checkCommutativeProperty(x, h)
    fprintf("By Calculating customly: x*h ");
    y1 = linearConv(x, h)
    fprintf("By Calculating customly: h*x ");
    y2 = linearConv(h, x)

    if y1 == y2
        fprintf("Commutative  property is proved");
    else
        fprintf("Commutative  is not proved");
    end
end

fprintf("Enter the values of x:");
x = str2num(input('', 's'));

fprintf("Enter the values of h:");
h = str2num(input('', 's'));

checkCommutativeProperty(x, h)


%% Input:
%% 1 3 1
%% 1 3 1 1
%% 1 2 3
```

#### Using Built in function

```matlab
function checkCommutativeProperty(x, h)
    fprintf("By Calculating customly: x*h ");
    y1 = conv(x, h)
    fprintf("By Calculating customly: h*x ");
    y2 = conv(h, x)

    if y1 == y2
        fprintf("Commutative property is proved");
    else
        fprintf("Commutative is not proved");
    end
end

fprintf("Enter the values of x:");
x = str2num(input('', 's'));

fprintf("Enter the values of h:");
h = str2num(input('', 's'));

checkCommutativeProperty(x, h)


%% Input:
%% 1 3 1
%% 1 3 1 1
```

#### Input

```
1 3 1 45
1 2 1
```

### 5. Circular Convolution

$$y[n] = \sum_{k=0}^{N-1} x[k] \cdot h[(n-k) \mod N]$$

```matlab
function y = circularConvolution(x, h)
    N = max(length(x), length(h));

    x = [x, zeros(1, N-length(x))];
    h = [h, zeros(1, N-length(h))];
    y = zeros(1, N);

    for n = 1:N
        for k = 1:N
            y(n) = y(n) + x(k) * h(mod(n-k, N) + 1);
        end
    end
end

fprintf("Enter the values of x:");
x = str2num(input('', 's'));

fprintf("Enter the values of h:");
h = str2num(input('', 's'));

fprintf("Circular convolution of x and h manually");
y=circularConvolution(x, h)

fprintf("Circular convolution of x and h (built in function)");
y=cconv(x,h, max(length(x), length(y)))

%% Input:
%% 1 3 1
%% 1 3 1 1
```

### Input

```
2 1 2 1
1 2 3
```

### 6. Verification of Sampling Theorem

```matlab
%% Verification of sampling theorem:
%% Taking two continuous waves, summing them, sampling, and reconstructing

% Define the custom sinc function
function s = my_sinc(x)
    s = sin(pi * x) ./ (pi * x);  % Sinc function formula
    s(x == 0) = 1;  % Handle the case when x == 0
end

%% Signal X = Acos(2*pi*f*t)
function y = signal(a, f, t)
    y = a * cos(2 * pi * f * t);
end

%% Input for two signals: Xc = A cos(2*pi*f*t)
fc1 = input('Frequency for signal 1: ');
a1 = input('Amplitude for signal 1: ');
fc2 = input('Frequency for signal 2: ');
a2 = input('Amplitude for signal 2: ');

n = 20; % Number of periods to display in the graph

%% Time period for both signals
tc1 = 1 / fc1;
tc2 = 1 / fc2;

% Define the time vector with sufficient resolution
t = 0:1/(100*max(fc1, fc2)):n*max(tc1, tc2);

%% Plotting the original continuous signals
figure;

% Plot Signal 1
subplot(2, 1, 1);
xf1 = a1 * cos(2 * pi * fc1 * t);
plot(t, xf1, 'LineWidth', 1);
title("Signal 01");
xlabel(sprintf("Time (s), F=%f Hz, T=%f", fc1, tc1));
ylabel(sprintf("Amplitude, A=%f", a1));
grid on;

% Plot Signal 2
subplot(2, 1, 2);
xf2 = a2 * cos(2 * pi * fc2 * t);
plot(t, xf2, 'LineWidth', 1);
title("Signal 02");
xlabel(sprintf("Time (s), F=%f Hz, T=%f s", fc2, tc2));
ylabel(sprintf("Amplitude, A=%f", a2));
grid on;


%% Summation of both of the signal
x_sum =  a1 * cos(2 * pi * fc1 * t) +  a2 * cos(2 * pi * fc2 * t);

% Nyquist rate
f_max = max(fc1, fc2);
t_max = 1/f_max;
a_max = a1+a2;
f_nq = f_max*2; % Nyquist
t_nq = 1/f_nq;
sampleTime = 0:t_nq:n*max(tc1, tc2);
sampleSignal = a1 * cos(2 * pi * fc1 * sampleTime) +  a2 * cos(2 * pi * fc2 * sampleTime);


%% Plotting
figure;

subplot(3, 1, 1);
plot(t, x_sum, 'LineWidth', 1);
title("Summation of Signal");
xlabel(sprintf("Time (s), F=%f Hz, T=%f s", f_max, t_max));
ylabel(sprintf("Amplitude"));
grid on;

subplot(3, 1, 2);
stem(sampleTime, sampleSignal, 'r.');
hold on;
plot(t, x_sum, 'b--', 'LineWidth', 0.5);
title("Sampling and Summation Signal");
xlabel(sprintf("Time (s)"));
ylabel(sprintf("Amplitude"));
legend('Sample Signal', 'Original Signal');
grid on;

subplot(3, 1, 3);
stem(sampleTime, sampleSignal, 'LineWidth', 1)
title("Sampling Signal");
xlabel(sprintf("Time (s)"));
ylabel(sprintf("Amplitude"));
grid on;



% Perform FFT to find frequency components

x_sum_f = abs(fft(sampleSignal));

figure;

subplot(2, 1, 1);
plot(sampleTime, x_sum_f, 'LineWidth', 2);
title("Frequency domain representation");
xlabel(sprintf("Frequency"));
ylabel(sprintf("Amplitude"));
grid on;


% Reconstructing
t_recon = t;
x_recon = zeros(size(t_recon));

% Perform sinc interpolation
for i = 1:length(t_recon)
    for j = 1:length(sampleTime)
        x_recon(i) = x_recon(i) + sampleSignal(j) * my_sinc((t_recon(i) - sampleTime(j))/t_nq);
    end
end

subplot(2,1,2);
plot(t_recon, x_recon, 'r-', 'LineWidth', 1.5);
hold on;
plot(t, x_sum, 'b--', 'LineWidth', 0.5);
title('Reconstructed Signal');
xlabel('Time (s)');
ylabel('Amplitude');
legend('Reconstructed', 'Original');
grid on;
```

#### Input

```
20
10
20
10
```
