%{
 int blockCom = 0;
 int inlineCom = 0;
%}

%%
\/\*  blockCom = 1;
\/\/  inlineCom = 1;
\n    if (blockCom || inlineCom) {printf("\n");} if (inlineCom) {inlineCom = 0;} 
\*\/  blockCom = 0;
.     if (blockCom || inlineCom) { REJECT; }
%%

int main (void) {
  yylex();
  return EXIT_SUCCESS;
}
