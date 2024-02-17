//Strings can be enclosed within either single quotes, double quotes or backticks:

let single = "single-quoted";
let double = "double-quoted";

let backticks = `backticks`;

/*
Single and double quotes are essentially the same. Backticks, however, 
allow us to embed any expression into the string, by wrapping it in ${…}:
*/
function sum(a, b) {
  return a + b;
}

console.log(`1 + 2 = ${sum(1, 2)}.`); // 1 + 2 = 3
//Another advantage of using backticks is that they allow a string to span multiple lines:
let guestList = `Guests:
 * John
 * Pete
 * Mary
`;

console.log(guestList); // a list of guests, multiple lines

let str1 = "Hello\nWorld"; // two lines using a "newline symbol"

// two lines using a normal newline and backticks
let str2 = `Hello
World`;

console.log(str1 == str2); // true

//Special Char:
console.log( "\u00A9" ); // ©
console.log( "\u{20331}" ); // 佫, a rare Chinese hieroglyph (long Unicode)
console.log( "\u{1F60D}" ); // 😍, a smiling face symbol (another long Unicode)
console.log( 'I\'m the Walrus!' ); // I'm the Walrus!

//Methods
let str = `Hello`;

// the first character
console.log( str[0] ); // H
console.log( str.charAt(0) ); // H

// the last character
console.log( str[str.length - 1] ); // o

console.log( str[1000] ); // undefined
console.log( str.charAt(1000) ); // '' (an empty string)

//We can also iterate over characters using for..of:
for (let char of "Hello") {
  console.log(char); // H,e,l,l,o (char becomes "H", then "e", then "l" etc)
}

console.log( 'Interface'.toUpperCase() ); // INTERFACE
console.log( 'Interface'.toLowerCase() ); // interface
console.log( 'Interface'[0].toLowerCase() ); // 'i'

str = 'Widget with id';

console.log( str.indexOf('Widget') ); // 0, because 'Widget' is found at the beginning
console.log( str.indexOf('widget') ); // -1, not found, the search is case-sensitive

console.log( str.indexOf("id") ); // 1, "id" is found at the position 1 (..idget with id)

//Start searching from a given position for indexOf()
console.log( str.indexOf('id', 2) ) // 12
//Search for all occurrence
str = "As sly as a fox, as strong as an ox";
let target = "as"; // let's look for it
let pos = 0;
while (true) {
  let foundPos = str.indexOf(target, pos);
  if (foundPos == -1) break;

  console.log(`Found at ${foundPos}`);
  pos = foundPos + 1; // continue the search from the next position
}

console.log( "Widget with id".includes("Widget") ); // true
console.log( "Hello".includes("Bye") ); // false
console.log( "Widget".includes("id") ); // true
console.log( "Widget".includes("id", 3) ); // false, from position 3 there is no "id"
console.log( "Widget".startsWith("Wid") ); // true, "Widget" starts with "Wid"
console.log( "Widget".endsWith("get") ); // true, "Widget" ends with "get"

//Substring
str = "stringify";
console.log( str.substring(2, 6) ); // "ring"
//Same as slice()
console.log( str.slice(0, 5) ); // 'strin', the substring from 0 to 5 (not including 5)
console.log( str.slice(0, 1) ); // 's', from 0 to 1, but not including 1, so only character at 0
//If there is no second argument, then slice goes till the end of the string:
console.log( str.slice(2) ); // 'ringify', from the 2nd position till the end

//In contrast with the previous methods, this one allows us to specify the length instead of the ending position:
console.log( str.substr(2, 4) ); // 'ring', from the 2nd position get 4 characters

console.log( str.codePointAt(0) ); //ascii code of s

//Creates a character by its numeric code
console.log( String.fromCodePoint(90) ); // Z

//comparison
console.log( 'Alma'.localeCompare('Zealand') ); // -1

