%{
  #include<stdio.h>
  #include<stdlib.h>
  enum {ACAT, ATTA, CGC, CGCAA, _MAX};
  int nbmotif[_MAX] = {0,0,0,0};
  void print_motif(void);
%}

%%
ACAT         ++nbmotif[ACAT]; REJECT;
ATTA         ++nbmotif[ATTA]; REJECT;
CGCAA        ++nbmotif[CGCAA]; REJECT;
CGC          ++nbmotif[CGC]; REJECT;
%%

int main (void) {
  yylex();
  print_motif();
  return EXIT_SUCCESS;
}

void print_motif(void) {
  printf("ACAT:\t%d\nATTA:\t%d\nCGC:\t%d\nCGCAA:\t%d\n", 
    nbmotif[ACAT], 
    nbmotif[ATTA], 
    nbmotif[CGC], 
    nbmotif[CGCAA]);
}
