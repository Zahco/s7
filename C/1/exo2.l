%%
[A-Z][a-z]* printf("IDENT : %s\n", yytext);
\'[a-z]*\'  printf("CHAINE : %s\n", yytext);
:=          printf("AFFECTATION\n");
\;          printf("SEPARATION\n");
.           /* ignorer le reste */

