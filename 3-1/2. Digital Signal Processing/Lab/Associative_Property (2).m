A = [2 1 2 1];
B = [1 2 3 4];
C = [5 6 7 8];

LHS = conv(conv(A,B), C);
RHS = conv(A, conv(B, C));

if(LHS==RHS)
% disp('Associative Property is proved')
else
disp('Associative Property is not proved');
end
