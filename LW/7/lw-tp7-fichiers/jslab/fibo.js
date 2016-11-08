function fibo(rank) {
  let tmp = 1;
  let res = 1;
  for (let i = 3; i <= rank; i++) {
    res += tmp;
    tmp = res - tmp;
  }
  return res;
}


function testFibo(max) {
  for(var i = 1; i <= max; ++i) {
    var tmp = fibo(i);
    console.log("fibo(" + i + ")=" + tmp);
  }
}

//testFibo(10, 15);

/*var tab = ['ichi ', 'ni', 'san ', 'shi ', 'go', 'roku ', 'shichi ', 'hachi ', 'kyû ', 'jû '];
for(var i in tab) {
  console.log(i + " " + tab[i]);
}*/
for (var i = 1; i < tab.length; ++i) {
   console.log(i + " " + tab[i]);
}
