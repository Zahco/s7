%{
  int hauteur = 0;
  int longueur = 0;
  int facteur = 0;
  int isValid = 1;
  int x = 0;
  
  int max(int a, int b);
%}

%%

a   ++x; hauteur = max(x, hauteur); ++longueur;
b   --x; isValid = isValid && x != -1; ++longueur;
.

%%

int max(int a, int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

int main(void) {
  yylex();
  printf("hauteur: %d\n", hauteur);
  printf("longueur: %d\n", longueur);
  printf("facteur: %d\n", facteur);
  printf("isValid: %d\n", isValid);
  return EXIT_SUCCESS;
}
