/**
 * This is used so GC does not skip any reachable objects,
 * even if an object is included into a child of another object, i.e., array.
 */

let john = { name: "John" };
let map = new Map();
map.set(john, "...");
john = null; // overwrite the reference
// john is stored inside the map,
// we can get it by using map.keys()

//Key has to be non-primitive (string, int, etc. not allowed)
let weakMap = new WeakMap();
let obj = {};
weakMap.set(obj, "ok"); // works fine (object key)

john = { name: "John" };
weakMap = new WeakMap();
weakMap.set(john, "...");
john = null; // overwrite the reference
// john is removed from memory!

//weakSet is similar to weakMap
let visitedSet = new WeakSet();
john = { name: "John" };
let pete = { name: "Pete" };
let mary = { name: "Mary" };

visitedSet.add(john); // John visited us
visitedSet.add(pete); // Then Pete
visitedSet.add(john); // John again
// visitedSet has 2 users now
// check if John visited?
console.log(visitedSet.has(john)); // true
// check if Mary visited?
console.log(visitedSet.has(mary)); // false
john = null;

// visitedSet will be cleaned automatically
