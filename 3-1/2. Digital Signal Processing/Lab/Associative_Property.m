A = [2 1 2 1];
B = [1 2 3 4];
C = [5 6 7 8];
A1 = 4;

LHS1= B+C;
LHSA=conv(A,LHS1);
RHS1= conv(A,B);
RHS2= conv(A,C);
RHSA= RHS1+RHS2;
if(LHSA==RHSA)
disp('Associative Property is proved')
else
disp('Associative Property is not proved');
end
