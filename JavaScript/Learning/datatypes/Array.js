//Declaration
let arr = new Array();
arr = [];

let fruits = ["Apple", "Orange", "Plum"];
fruits[2] = "Pear"; // now ["Apple", "Orange", "Pear"]
fruits[3] = "Lemon"; // now ["Apple", "Orange", "Pear", "Lemon"]
console.log(fruits.length); // 3
console.log(fruits); // Apple,Orange,Plum

//All types are welcome
arr = [
  "Apple",
  { name: "John" },
  true,
  function () {
    console.log("hello");
  },
];

// get the object at index 1 and then show its name
console.log(arr[1].name); // John
// get the function at index 3 and run it
arr[3](); // hello
console.log(fruits.pop()); // remove "Pear" and console.log it
console.log(fruits); // Apple, Orange
fruits.push("Pear");
console.log(fruits); // Apple, Orange, Pear
console.log(fruits.shift()); // remove Apple and console.log it
console.log(fruits); // Orange, Pear
fruits.unshift("Apple");
console.log(fruits); // Apple, Orange, Pear
fruits = ["Apple"];
fruits.push("Orange", "Peach");
fruits.unshift("Pineapple", "Lemon");

// ["Pineapple", "Lemon", "Apple", "Orange", "Peach"]
console.log(fruits);

//The tricky length
fruits = [];
fruits[123] = "Apple";
console.log(fruits.length); // 124

arr = [1, 2, 3, 4, 5];
arr.length = 2; // truncate to 2 elements
console.log(arr); // [1, 2]

arr.length = 5; // return length back
console.log(arr[3]); // undefined: the values do not return

//With new
arr = new Array("Apple", "Pear", "etc");
console.log(arr.toString());

//Multi dim
let matrix = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9],
];

console.log(matrix[1][1]); // 5, the central element

//Splice: arr.splice(start, deleteCount, [elem1, ..., elemN])
arr = ["I", "go", "home"];
delete arr[1]; // remove "go"
console.log(arr[1]); // undefined
// now arr = ["I",  , "home"];
console.log(arr.length); // 3, why the length is still 3? Use splice

arr = ["I", "study", "JavaScript"];
arr.splice(1, 1); // from index 1 remove 1 element
console.log(arr); // ["I", "JavaScript"]

arr = ["I", "study", "JavaScript", "right", "now"];
// remove 3 first elements and replace them with another
arr.splice(0, 3, "Let's", "dance");
console.log( arr ) // now ["Let's", "dance", "right", "now"]

//The splice method is also able to insert the elements without any removals.
//For that we need to set deleteCount to 0:
arr = ["I", "study", "JavaScript"];
// from index 2
// delete 0
// then insert "complex" and "language"
arr.splice(2, 0, "complex", "language");
console.log( arr ); // "I", "study", "complex", "language", "JavaScript"


//Slice: arr.slice(start, end)
arr = ["t", "e", "s", "t"];
console.log( arr.slice(1, 3) ); // e,s (copy from 1 to 3)
console.log( arr.slice(-3) ); // e,s,t (copy from 3 right till the end)

//Concat
arr = [1, 2];
// create an array from: arr and [3,4]
console.log( arr.concat([3, 4]) ); // 1,2,3,4
// create an array from: arr and [3,4] and [5,6]
console.log( arr.concat([3, 4], [5, 6]) ); // 1,2,3,4,5,6
// create an array from: arr and [3,4], then add values 5 and 6
console.log( arr.concat([3, 4], 5, 6) ); // 1,2,3,4,5,6
let arrayLike = {
  0: "something",
  length: 1
};
console.log( arr.concat(arrayLike) ); // 1,2,[object Object]

arrayLike = {
  0: "something",
  1: "else",
  [Symbol.isConcatSpreadable]: true,
  length: 2
};
console.log( arr.concat(arrayLike) ); // 1,2,something,else


//For each
/*
syntax:
arr.forEach(function(item, index, array) {
  ... do something with item
});
*/
["Bilbo", "Gandalf", "Nazgul"].forEach(console.log);
["Bilbo", "Gandalf", "Nazgul"].forEach((item, index, array) => {
  console.log(`${item} is at index ${index} in ${array}`);
});


//Searching in arrays
//arr.indexOf(item, from)
//arr.lastIndexOf(item, from) – same, but looks for from right to left.
//arr.includes(item, from) – looks for item starting from index from, returns true if found.
arr = [1, 0, false];

console.log( arr.indexOf(0) ); // 1
console.log( arr.indexOf(false) ); // 2
console.log( arr.indexOf(null) ); // -1
console.log( arr.includes(1) ); // true

//Find
/**
 * The syntax:
 * let result = arr.find(function(item, index, array) {
 * if true is returned, item is returned and iteration is stopped
 * for falsy scenario returns undefined
});
 */

let users = [
  {id: 1, name: "John"},
  {id: 2, name: "Pete"},
  {id: 3, name: "Mary"}
];
user = users.find(item => item.id == 1);
console.log(user.name); // John

//Filter
/**
 * let results = arr.filter(function(item, index, array) {
 * if true item is pushed to results and the iteration continues
 * returns empty array if nothing found
});
 */

users = [
  {id: 1, name: "John"},
  {id: 2, name: "Pete"},
  {id: 3, name: "Mary"}
];

// returns array of the first two users, filter returns an iterable
let filteredUsers = users.filter(item => item.id < 3);
console.log(filteredUsers.length); // 2

//Transformation: map, sort, reverse,split, join, reduce, reduceRight
//map
lengths = ["Bilbo", "Gandalf", "Nazgul"].map(item => item.length);//map item with its length
console.log(lengths); // 5,7,6

//sort (requires a function argument)
arr = [ 1, 13, 4]
arr.sort(function(a, b) { return a - b; });
console.log(arr);  // 1, 2, 15
arr.sort((a, b) => a - b);
console.log(arr);  // 1, 2, 15
countries = ['Burma', 'Andorra', 'Vietnam'];
console.log( countries.sort( (a, b) => a.localeCompare(b) ) ); // Andorra, Burma,Vietnam (correct!)

//Reverse
arr = [1, 2, 3, 4, 5];
arr.reverse();
console.log( arr ); // 5,4,3,2,1

//Split
cmds = "ls a -h -b";
arr = cmds.split(" ");
for (let cmd of arr) {
  console.log(`this command is${cmd}.`); // A message to Bilbo  (and other cmds)
}
arr = cmds.split(' ', 2);// only 3 are splitted, rest are ignored

//If delimiter does not exist
let noDelimString = "1897"; //returns an array contain one element that is the string
console.log("No Delim Result", noDelimString.split('-'))

//Join does the opposite of split
arr = ['Bilbo', 'Gandalf', 'Nazgul'];
let str = arr.join(';'); // glue the array into a string using ;
console.log( str ); // Bilbo;Gandalf;Nazgul

//Reduce
arr = [1, 2, 3, 4, 5];
let result = arr.reduce((sum, current) => sum + current, 0); //0 is initial value for sum, 
//1st element os treated as initial if initial is not provided
console.log(result); // 15
result = arr.reduceRight((sum, current) => sum + current);
console.log(result); // 15


//isArray
console.log(typeof {}); // object
console.log(typeof []); // object
//No difference, array is just like any other object, so isArray is used to distinguish
console.log(Array.isArray({})); // false
console.log(Array.isArray([])); // true

//thisArg in functions
/**
 * arr.find(func, thisArg)
 * arr.filter(func, thisArg)
 * arr.map(func, thisArg);
 * ...
 * thisArg is the optional last argument
 */

army = {
  minAge: 18,
  maxAge: 27,
  canJoin(user) {
    return user.age >= this.minAge && user.age < this.maxAge;
  }
};

users = [{age: 16},{age: 20},{age: 23},{age: 30}];
// find users, for who army.canJoin returns true
let soldiers = users.filter(army.canJoin, army);
console.log(soldiers.length); // 2
console.log(soldiers[0].age); // 20
console.log(soldiers[1].age); // 23

//Same as:
soldiers = users.filter((user) => army.canJoin(user));
console.log(soldiers.length); // 2


//Slicing 
 let baseURl = "https://digitalcollections.tricolib.brynmawr.edu/iiif/2/";
 let postFix =
   "~JP2~470f51915ee42083c974f3d5a02%5B%E2%80%A6%5Dcc9da0bb20ff9f541d82a/full/pct:100/1/default.jpg";
 let pid = "sc203248";
 let pidReady = pid.slice(0, 2) + ":" + pid.slice(2);
let src = baseURl + pidReady + postFix;
console.log(src)
let src2 =
  "https://digitalcollections.tricolib.brynmawr.edu/iiif/2/sc:203248~JP2~470f51915ee42083c974f3d5a02%5B%E2%80%A6%5Dcc9da0bb20ff9f541d82a/full/pct:100/1/default.jpg";
console.log(src == src2)