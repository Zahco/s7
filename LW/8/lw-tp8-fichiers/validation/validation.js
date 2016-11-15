
var form = document.forms[0];
form.onsubmit = validation;

var img = document.getElementById("img_submit");
img.onmouseover = function () {
  if (validation()) {
    form.submit();
  }
};

function validation() {
  var error = false;
  var lastname = document.getElementById("lastname");
  if (lastname.value.length < 3) {
    error = true;
    lastname.className = "error";
  } else {
    lastname.className = "";
  }
  var firstname = document.getElementById("firstname");
  if (firstname.value.length < 3) {
    error = true;
    firstname.className = "error";
  } else {
    firstname.className = "";
  }
  var email = document.getElementById("email");
  var regexp = /\w+@\w+\.\w+/;
  if (email.value.match(regexp) == null) {
    error = true;
    email.className = "error";
  } else {
    email.className = "";
  }
  return !error;
}
