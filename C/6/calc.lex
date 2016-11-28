%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <math.h>
//  #include "yystype.h"
  #include "calc.tab.h"
%}

NOMBRE (([[:digit:]]+(\.[0-9]+)?)|(\.[0-9]+))([eE][+-]?[0-9]+)?
VARIABLE [a-zA-Z]+[a-zA-Z0-9]*
%%
{NOMBRE} {
  double l;
  char *end;
  printf("NOMBRE: Analyse de %s=", yytext);
  l = strtod(yytext, &end);
  if ( *end != '\0' ) { // Erreur d'analyse syntaxique
    fprintf(stderr, "Erreur dans l'analyse de %s comme entier (%lf)\n", yytext,l);
    exit(EXIT_FAILURE);
  }
  if ( (l==HUGE_VAL||l==-HUGE_VAL||l==0.) && errno==ERANGE ) { 
    // Depassement de capacité
    fprintf(stderr, "Dépassement de capacité dans l'analyse de %s "
	    "comme entier\n", yytext);
    exit(EXIT_FAILURE);
  }
  printf("%f\n", l);
  yylval.val = l;
  return NOMBRE;
}
{VARIABLE} yylval.sptr = yytext; return VARIABLE;
sin return SIN;
cos return COS;
tan return TAN;
\+ return '+';
\- return '-';
\* return '*';
\/ return '/';
\( return '(';
\) return ')';
\n return '\n';
=  return '=';
. {}
%%

