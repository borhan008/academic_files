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

m = conv(x, h);
nm = [nx(1) - nh(1): nx(length(x)) + nh(length(h))];
o = conv(h, x);
nm = [nx(1) - nh(1): nx(length(x)) + nh(length(h))];

disp('Left hand Sequence'); 
m
disp('Right hand Sequence'); 
o

if (m == o)
    disp('Commutative Property is proved');
else
    disp('Commutative Property is not proved');
end
