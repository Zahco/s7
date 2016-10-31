%{
  int nb_string = 0;
  int length_string = 0;
  int length_com = 0;
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

int main(void) {
  yylex();
  printf("\n\n\nnb_string:     %d\n", nb_string);
  printf("length_string: %d\n", length_string);
  printf("length_com:    %d\n", length_com);
  return EXIT_SUCCESS;
}
