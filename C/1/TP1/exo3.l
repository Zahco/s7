%{
  #include<stdio.h>
  enum {VERBE, ADJ, NOM, PRONOM, VIDE};
  int etat = VIDE;
  void save(char *mot);
%}

VERBE verbe
ADJ adj
NOM nom
PRONOM pronom
MOT [A-Za-z]

%%
^{VERBE}        etat = VERBE;
^{ADJ}          etat = ADJ;
^{NOM}          etat = NOM;
^{PRONOM}       etat = PRONOM;
{MOT}*          save(yytext);
\n              etat = VIDE;
.

%%

void save(char *mot) {
  switch(etat) {
    case VERBE:
      printf("verbe:%s\n", mot);
      break;
    case ADJ:
      printf("adj:%s\n", mot);
      break;
    case NOM:
      printf("nom:%s\n", mot);
      break;
    case PRONOM:
      printf("pronom:%s\n", mot);
      break;
    case VIDE:
      printf("null:%s\n", mot);
      break;
    default:
      break;
  }
}


