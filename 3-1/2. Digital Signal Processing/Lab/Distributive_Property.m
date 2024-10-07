A=[2 1 2 1 ];
B=[1 2 3 4 ]; 
C=[5 6 7 8 ]; 
A1=4;
LHS1=conv(B,C);
LHS= A1.*LHS1
RHS1= A1.*B;
RHS2 = A1.*C;
RHS = conv(RHS1,RHS2)
if(LHS==RHS)
disp('Distributive Property is proved')
else
disp('Distributive Property is not proved');
end