// we have an array with the name and surname
let arr = ["John", "Smith"];
//arr is not modified

// destructuring assignment
// sets firstName = arr[0]
// and surname = arr[1]
let [firstName, surname] = arr;
alert(firstName); // John
alert(surname); // Smith

[firstName, surname] = arr.split(" ");
alert(firstName); // John
alert(surname); // Smith

// second element is not needed
let [firstName, , title] = ["Julius", "Caesar", "Consul", "of the Roman Republic"];
alert( title ); // Consul


let user = new Map();
user.set("name", "John");
user.set("age", "30");
// Map iterates as [key, value] pairs, very convenient for destructuring
for (let [key, value] of user) {
  alert(`${key}:${value}`); // name:John, then age:30
}

//Swapping
let guest = "Jane";
let admin = "Pete";
// Let's swap the values: make guest=Pete, admin=Jane
[guest, admin] = [admin, guest];
alert(`${guest} ${admin}`); // Pete Jane (successfully swapped!)

/**
 * Usually, if the array is longer than the list at the left, the “extra” items are omitted.
 * For example, here only two items are taken, and the rest is just ignored:
 */

let [name1, name2] = ["Julius", "Caesar", "Consul", "of the Roman Republic"];
alert(name1); // Julius
alert(name2); // Caesar
// Further items aren't assigned anywhere


//If we’d like also to gather all that follows – we can add one more parameter that gets “the rest” using three dots "...":
let [name1, name2, ...rest] = ["Julius", "Caesar", "Consul", "of the Roman Republic"];

// rest is array of items, starting from the 3rd one
alert(rest[0]); // Consul
alert(rest[1]); // of the Roman Republic
alert(rest.length); // 2

//If the array is shorter than the list of variables at the left, there’ll be no errors. Absent values are considered undefined:
let [firstName, surname] = [];
alert(firstName); // undefined
alert(surname); // undefined

//If we want a “default” value to replace the missing one, we can provide it using =:
let [name = "Guest", surname = "Anonymous"] = ["Julius"];
alert(name);    // Julius (from array)
alert(surname); // Anonymous (default used)

