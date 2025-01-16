
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

function checkDistributiveProperty(x, h)
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

checkDistributiveProperty(x, h)


%% Input:
%% 1 3 1
%% 1 3 1 1
%% 1 2 3
```

#### Using Built in function
```matlab
function checkDistributiveProperty(x, h)
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

checkDistributiveProperty(x, h)


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

### 6. Sampling Theorem



