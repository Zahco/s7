/*
 * Ceci est une ardoise JavaScript.
 *
 * Saisissez du code JavaScript, puis faites un clic droit ou sélectionnez à partir du menu Exécuter :
 * 1. Exécuter pour évaluer le texte sélectionné (Ctrl+R),
 * 2. Examiner pour mettre en place un objet Inspector sur le résultat (Ctrl+I), ou,
 * 3. Afficher pour insérer le résultat dans un commentaire après la sélection. (Ctrl+L)
 */

function printObject(obj) {
  for (var e in obj) {
    console.log((obj.hasOwnProperty(e) ? "" : "PROTOTYPE - ") 
                + e + " : " + typeof obj[e] + " = " + obj[e]);
  }
}


function merge(a, b) {
  var r = {};
  for (var e in a) {
    r[e] = a[e];
  }
  for (var e in b) {
    r[e] = b[e];
  }
  return r;
}


var obj = {
  nom: "toto",
  age: 3,
  majeur: false,
  address: { num : 3, rue : "rue"},
  travail: function() { return false; }
};
var obj2 = {
  i: true
}
printObject(merge(obj, obj2));