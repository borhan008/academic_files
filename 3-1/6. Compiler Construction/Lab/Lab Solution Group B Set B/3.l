%{
#include<stdio.h>
%}

/*
Rule :
    1. a[a-z]*a -> a [a..b...c...d] a  -> Accepted
    2. else -> Rejected

*/

%%
a[a-z]*a {printf("Matching");}
[a-z]* {printf("Not Matching");};
%%

int main(){
    printf("Enter an identifier: ");
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}