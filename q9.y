%{
#include<stdio.h>
#include<stdlib.h>
%}
%token id num
%left '(' ')'
%left '+' '-'
%left '/' '*'

%% 

expression : '(' expression ')' 
| expression '+' expression {printf("\nplus recog!\n");$$=$1+$3;printf("\n %d\n",$$);}
| expression '-' expression {printf("\nminus recog!\n");$$=$1-$3;printf("\n %d\n",$$);}
| expression '*' expression {printf("\nMul recog!\n");$$=$1*$3;printf("\n %d\n",$$);}
| expression '/' expression {printf("\ndivision recog!\n");
                            if($3==0) printf("\ndivision by zero error \n");
                            else {$$=$1/$3;printf("\n %d\n",$$);}
                            }
| id
| num

%%

main(){
    printf(" Enter an arithmetic expression\n");
    yyparse();
} 
yyerror() { printf(" Invalid arithmetic Expression\n");
 exit(1);
}
