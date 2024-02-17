function sum(a, b) {
  return a + b
}

console.log(sum(1, 2, 3, 4, 5)) //no error, the rest of the args are ignored


//Rest
function sumAll(...args) { // args is the name for the array
  let sum = 0;
  for (let arg of args){
      sum += arg
  }
  return sum
}
console.log( sumAll(1) ); // 1
console.log( sumAll(1, 2) ); // 3
console.log( sumAll(1, 2, 3) ); // 6


function showName(firstName, lastName, ...titles) {
  console.log(firstName + " " + lastName); // Julius Caesar

  // the rest go into titles array
  // i.e. titles = ["Consul", "Imperator"]
  console.log(titles[0]); // Consul
  console.log(titles[1]); // Imperator
  console.log(titles.length); // 2
}
showName("Julius", "Caesar", "Consul", "Imperator");


// The Argument object" the old way of ...rest
function showName() {
  console.log(arguments.length);
  console.log(arguments[0]);
  console.log(arguments[1]);

  // it's iterable
  // for(let arg of arguments) console.log(arg);
}
// shows: 2, Julius, Caesar
showName("Julius", "Caesar");
// shows: 1, Ilya, undefined (no second argument)
showName("Ilya");


//Spread
console.log( Math.max(3, 5, 1) ); // 5

let arr = [3, 5, 1];
console.log( Math.max(arr) ); // NaN, expects a list of numeric arguments, not a single array

console.log( Math.max(...arr) ); // 5 (spread turns array into a list of arguments)


let arr1 = [1, -2, 3, 4];
let arr2 = [8, 3, -8, 1];
console.log( Math.max(...arr1, ...arr2) ); // 8

//combine everything
console.log( Math.max(1, ...arr1, 2, ...arr2, 25) ); // 25


//With Strings
let str = "Hello";
console.log( [...str] ); // H,e,l,l,o