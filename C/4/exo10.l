%{
  int nb_string = 0;
  int length_string = 0;
  int length_com = 0;
  int i = 1;
  int _argc;
  char **_argv;
%}

%x STR
%x INLINECOM
%x BLOCKCOM

CARAC .|\n

%%

\"                BEGIN STR; printf("%s", yytext);
<STR>\\\"         length_string += yyleng; printf("%s", yytext);
<STR>\"           ++nb_string; BEGIN INITIAL; printf("%s", yytext);
<STR>{CARAC}      ++length_string; printf("%s", yytext);

\/\/              BEGIN INLINECOM;
<INLINECOM>\n     BEGIN INITIAL;
<INLINECOM>.      ++length_com;

\/\*              BEGIN BLOCKCOM;
<BLOCKCOM>{CARAC} ++length_com;
<BLOCKCOM>\*\/    BEGIN INITIAL;

%%

int yywrap() {
  fclose(yyin);
  if (i < _argc) {
    yyin = fopen(_argv[i], "r");
    ++i;
    return 0;
  }
  return 1;
}

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    return EXIT_FAILURE;
  }
  _argc = argc;
  _argv = argv;
  yyin = fopen(argv[i], "r");
  ++i;
  yylex();
  
  printf("\n\n\nnb_string:     %d\n", nb_string);
  printf("length_string: %d\n", length_string);
  printf("length_com:    %d\n", length_com);
  return EXIT_SUCCESS;
}
