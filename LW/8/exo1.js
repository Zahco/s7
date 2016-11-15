/*
 * Ceci est une ardoise JavaScript.
 *
 * Saisissez du code JavaScript, puis faites un clic droit ou sélectionnez à partir du menu Exécuter :
 * 1. Exécuter pour évaluer le texte sélectionné (Ctrl+R),
 * 2. Examiner pour mettre en place un objet Inspector sur le résultat (Ctrl+I), ou,
 * 3. Afficher pour insérer le résultat dans un commentaire après la sélection. (Ctrl+L)
 */

/*alert(document.getElementById("intro"));
alert(document.getElementsByTagName("p"));
alert(document.getElementsByClassName("content"));*/
/*
var elemsContent = document.getElementsByClassName("content");
/*for (var i = 0; i < elemsContent.length; ++i) {
  console.log(elemsContent[i]);
  elemsContent[i].className = "comment";
}
while (elemsContent.length > 0) {
  elemsContent[0].className = "comment";
}*/
/*
var span = document.createElement("span");
span.className = "comment";
span.appendChild(document.createTextNode("Je suis un commentaire dans une span."));
document.getElementsByTagName("body")[0].appendChild(span);
*/

var menu = document.getElementById("pmenu");
console.log(menu);
var elemsp = document.getElementsByTagName("p");
for (var i = 0; i < elemsp.length; ++i) {
  console.log(elemsp[i]);
  elemsp[i].appendChild(menu.cloneNode(true));
}
