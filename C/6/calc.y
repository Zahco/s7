
%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "lex.yy.h"
//  #include "yystype.h"
  void yyerror(const char *s);
  
  typedef struct list {
    double valeur;
    char *identificateur;
    struct list *next;
  } list;
  list *getItem(list *l, char *id) {
    if (l == NULL) {
      return NULL;
    }
    if (strcmp(l->identificateur, id) == 0) {
      return l;
    }
    return getItem(l->next, id);
  }
  void createOrUpdateItem(list **l, char *id, double val) {
    list *item = getItem(*l, id);
    if (item == NULL) {
      item = malloc(sizeof(*item));
      char *str = malloc(strlen(id) + 1);
      strcpy(str, id);
      item->identificateur = str;
      item->next = *l;
      l = item;
    }
    item->valeur = val;
  }
  double getVal(list *l, char *id) {
    list *l = getItem(l, id);
    if (l == NULL) {
      return 0/0;
    } else {
      return l->valeur;
    }
  }
  void dispose(list **l) {
    if (*l == NULL) {
      return;
    }
    list *item = (*l)->next;
    free((*l)->identificateur);
    free(*l);
    l = null;
    dispose(&item);
  }
  list *allId = null;
%}

%union {
  double val;
  char *sptr;
}


%token <val> NOMBRE
%token <sptr> VARIABLE

%type <val> exp
%type <val> ligne

%token COS
%token SIN
%token TAN

%left '-' '+'
%left '*' '/'
%right MOINSU

%%
ligne : ligne exp '\n' {printf("resultat : %f \n",$2);}
      | ligne '\n'
      | ligne affect '\n'
      | %empty {}
      ;
exp   : exp '+' exp {$$ = $1 + $3;}
      | exp '-' exp {$$ = $1 - $3;}
      | exp '*' exp {$$ = $1.val * $3;}
      | exp '/' exp {$$ = $1.val / $3;}
      | SIN '(' exp ')' {$$ = sin($3);}
      | COS '(' exp ')' {$$ = cos($3);}
      | TAN '(' exp ')' {$$ = tan($3);}
      | '(' exp ')' {$$ = $2;}
      | '-' exp %prec MOINSU
      | NOMBRE      {$$ = $1;}
      | VARIABLE {$$ = getVal(allId, $1);}
      ;
affect: VARIABLE '=' exp { createOrUpdateItem(&allId, $1, $3); }
;
%%
void yyerror(const char *s) {
 fprintf(stderr,"%s\n", s);
}
int main(void) {
 yyparse();
 return EXIT_SUCCESS;
}
