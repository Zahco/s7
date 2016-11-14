%{
  int i = 1;
  int _argc = 0;
  char **_argv;
  int nbchar = 0;
  int nbword = 0;
  int nbline = 0;
  int _nbchar = 0;
  int _nbword = 0;
  int _nbline = 0;
  #define yyterminate()  printf("%d\t%d\t%d\t[Total]\n", nbchar, nbword, nbline);\
                          return 0;
%}

%%

[\t ]*[^\t\n ]+    ++nbword; nbchar += strlen(yytext);
\n                 ++nbline; ++nbchar;
.                  ++nbchar;

%%

int yywrap() {
  fclose(yyin);
  printf("%d\t%d\t%d\t%s\n", nbchar - _nbchar,
    nbword - _nbword,
    nbline - _nbline,
    _argv[i]);
  _nbchar = nbchar;
  _nbword = nbword;
  _nbline = nbline;
  ++i;
  while (i < _argc && (yyin = fopen(_argv[i], "r")) == NULL) {
    fprintf(stderr, "fopen: Unknown file \"%s\"\n", _argv[i]);
    ++i;
  }
  if (i == _argc) {
    return 1;
  }
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    return EXIT_FAILURE;
  }
  _argc = argc;
  _argv = argv;
  yyin = fopen(argv[i], "r");
  if (yyin == NULL) {
    return EXIT_FAILURE;
  }
  yylex();
  return EXIT_SUCCESS;
}
