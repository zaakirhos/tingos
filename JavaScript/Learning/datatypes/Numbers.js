let billion = 1000000000;

billion = 1_000_000_000;

billion = 1e9;

console.log( 7.3e9 );  // 7.3 billions (same as 7300000000 or 7_300_000_000)

let ms = 0.000001;
ms = 1e-6; // six zeroes to the left from 1

console.log( 0xff ); // 255
console.log( 0xFF ); // 255 (the same, case doesn't matter)

let a = 0b11111111; // binary form of 255
let b = 0o377; // octal form of 255



//The method num.toString(base) returns a string representation of num in the numeral system with the given base.
let num = 255;
console.log( num.toString(16) );  // ff
console.log( num.toString(2) );  

//Two dot call for base 36
//base=36 is the maximum, digits can be 0..9 or A..Z.
console.log( 123456..toString(36) ); // 2n9c
//same as
console.log((123456).toString(36));


num = 1.23456;
console.log( Math.round(num * 100) / 100 ); // 1.23456 -> 123.456 -> 123 -> 1.23

num = 12.34;
console.log(num.toFixed(1)); // "12.3"
console.log(+num.toFixed(1)); // 12.3 + turns it to a number
console.log( 1e500 ); // Infinity



//Checks if it's not a number
console.log( isNaN(NaN) ); // true
console.log( isNaN("str") ); // true
console.log( NaN === NaN ); // false
//he value NaN is unique in that it does not equal anything, including itself:

console.log( isFinite("15") ); // true
console.log( isFinite("str") ); // false, because a special value: NaN
console.log( isFinite(Infinity) ); // false, because a special value: Infinity



//Compare with Object.is
//It works with NaN: 
console.log("Is NaN NaN: " + Object.is(NaN, NaN)); //True that’s a good thing.
//Object.is(a, b) is the same as a === b.

//parseInt and parseFloat, extra number from units
//parseInt(str, radix), radix is optional 
console.log( parseInt('100px') ); // 100
console.log( parseFloat('12.5em') ); // 12.5

console.log( parseInt('12.3') ); // 12, only the integer part is returned
console.log( parseFloat('12.3.4') ); // 12.3, the second point stops the reading
console.log( parseInt('a123') ); // NaN, the first symbol stops the process

console.log( parseInt('0xff', 16) ); // 255
console.log( parseInt('ff', 16) ); // 255, without 0x also works

console.log( parseInt('2n9c', 36) ); // 123456

