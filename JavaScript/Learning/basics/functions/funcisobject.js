function sayHi() {
  console.log("Hi");
}

console.log(sayHi.name); // sayHi

//length of params
function f1(a) {}
function f2(a, b) {}
function many(a, b, ...more) {}
console.log(f1.length); // 1
console.log(f2.length); // 2
console.log(many.length); // 2