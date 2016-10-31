%{
  int nbchar = 0;
  int nbword = 0;
  int nbline = 0;
%}

%%


[\t ]*[^\t\n ]+    ++nbword; nbchar += strlen(yytext);
\n                 ++nbline; ++nbchar;
.                  ++nbchar;

%%

int main(void) {
  yylex();
  printf("nbchar: %d\n", nbchar);
  printf("nbword: %d\n", nbword);
  printf("nbline: %d\n", nbline);
  return EXIT_SUCCESS;
}
