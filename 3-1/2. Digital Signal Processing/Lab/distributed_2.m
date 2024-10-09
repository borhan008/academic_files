A = [2 1 2 1];
B = [1 2 3 4];
C = [5 6 7 8];

LHS = conv(A, B+C);
RHS = conv(A, B) + conv(A, C);

disp("LHS: ")
LHS
disp("RHS : ")
RHS

if(LHS==RHS)
disp('Distributed Property is proved')
else
disp('Distributer Property is not proved');
end