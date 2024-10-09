clear all
clc
close all

x = [2 1 2 1];
h = [1 2 3 4];

m = conv(x, h);
o = conv(h, x);

disp('Left hand Sequence'); 
m
disp('Right hand Sequence'); 
o

if (m == o)
    disp('Commutative Property is proved');
else
    disp('Commutative Property is not proved');
end
