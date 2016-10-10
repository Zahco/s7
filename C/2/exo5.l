%{
 int donteat = 0;
%}

%%
\\  donteat = 1;
\"   if (donteat) { donteat = 0; REJECT; }
%%

int main (void) {
  yylex();
  return EXIT_SUCCESS;
}
