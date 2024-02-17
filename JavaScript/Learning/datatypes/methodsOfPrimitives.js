//There are 7 primitive types: string, number, bigint, boolean, symbol, null and undefined.
//The “object wrappers” are different for each primitive type and are called: String, Number, Boolean and Symbol. 


let str = "Hello";

console.log( str.toUpperCase() ); // HELLO

// The string str is a primitive. So in the moment of accessing its property, a special object is created that knows the value of the string, and has useful methods, like toUpperCase().
// That method runs and returns a new string (shown by alert).
// The special object is destroyed, leaving the primitive str alone.


let n = 1.23456;

console.log( n.toFixed(2) ); // 1.23

let zero = new Number(0);

if (zero) {
  // zero is true, because it's an object
  console.log("zero is truthy!?!");
}

let num = Number("123"); // convert a string to number

//The special primitives null and undefined are exceptions. They have no corresponding “wrapper objects” and provide no methods.