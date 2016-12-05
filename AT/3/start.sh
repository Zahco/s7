execute_search() {
  ./ac-matrice mots text
  ./ac-liste mots text
  ./ac-mixte mots text
}


make clean
make
echo "Texte en cours de génération..."
./text_generator/genere-text text 5000000 2
echo "Texte généré"

./text_generator/genere-mots mots 100 10 2
execute_search

./text_generator/genere-mots mots 100 23 2
execute_search

./text_generator/genere-mots mots 100 45 2
execute_search

echo "Texte en cours de génération..."
./text_generator/genere-text text 5000000 4
echo "Texte généré"

./text_generator/genere-mots mots 100 10 4
execute_search

./text_generator/genere-mots mots 100 23 4
execute_search

./text_generator/genere-mots mots 100 45 4
execute_search

echo "Texte en cours de génération..."
./text_generator/genere-text text 5000000 20
echo "Texte généré"
./text_generator/genere-mots mots 100 10 20
execute_search

./text_generator/genere-mots mots 100 23 20
execute_search

./text_generator/genere-mots mots 100 45 20
execute_search


echo "Texte en cours de génération..."
./text_generator/genere-text text 5000000 70
echo "Texte généré"
./text_generator/genere-mots mots 100 10 70
execute_search

./text_generator/genere-mots mots 100 23 70
execute_search

./text_generator/genere-mots mots 100 45 70
execute_search
