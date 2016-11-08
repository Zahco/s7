/*
 * Ceci est une ardoise JavaScript.
 *
 * Saisissez du code JavaScript, puis faites un clic droit ou sélectionnez à partir du menu Exécuter :
 * 1. Exécuter pour évaluer le texte sélectionné (Ctrl+R),
 * 2. Examiner pour mettre en place un objet Inspector sur le résultat (Ctrl+I), ou,
 * 3. Afficher pour insérer le résultat dans un commentaire après la sélection. (Ctrl+L)
 */
function Rect(lon, lar) {
  this.lon = lon;
  this.lar = lar;
}
var rect = new Rect(2, 2);
//printObject(rect);
Rect.prototype.color = 'red';
var rect2 = new Rect(3, 3);
//printObject(rect2);
//printObject(rect);
String.prototype.repeat = function (i) {
  var ret = '';
  for (var j = 0; j < i; ++j) {
    ret += this;
  }
  return ret;
} //console.log("cou".repeat(8));

Object.prototype.shuffle = function () {
  for (var e in this) {
    if (!this.hasOwnProperty(e)) {
      break;
    }
    var r = Math.trunc(Math.random() * this.length);
    var tmp = this[e];
    this[e] = this[r];
    this[r] = tmp;
  }
  return this;
};
var tab = [
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9
];
console.log(tab);
console.log(tab.shuffle());
var Shape = {
};
Shape.type = typeof this;
Shape.getType = function () {
  return this.type;
}
printObject(Shape);
function Triangle() {
  this.prototype = Shape;
}
printObject(Triangle);
