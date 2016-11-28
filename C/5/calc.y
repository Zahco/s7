
%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <math.h>
  #include "lex.yy.h"
  #include "yystype.h"
  void yyerror(const char *s);
%}

%token NOMBRE
%token COS
%token SIN
%token TAN

%left '-' '+'
%left '*' '/'
%right MOINSU

%%
ligne : ligne exp '\n' {printf("resultat : %f \n",$2);}
      | ligne '\n'
      |
      ;
exp   : exp '+' exp {$$ = $1 + $3;}
      | exp '-' exp {$$ = $1 - $3;}
      | exp '*' exp {$$ = $1 * $3;}
      | exp '/' exp {$$ = $1 / $3;}
      | SIN '(' exp ')' {$$ = sin($3);}
      | COS '(' exp ')' {$$ = cos($3);}
      | TAN '(' exp ')' {$$ = tan($3);}
      | '(' exp ')' {$$ = $2;}
      | '-' exp %prec MOINSU
      | NOMBRE      {$$ = $1;}
      ;
%%
void yyerror(const char *s) {
 fprintf(stderr,"%s\n", s);
}
int main(void) {
 yyparse();
 return EXIT_SUCCESS;
}
