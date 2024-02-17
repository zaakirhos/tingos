//let func = new Function ([arg1, arg2, ...argN], functionBody);


let sum = new Function('a', 'b', 'return a + b');

alert( sum(1, 2) ); // 3

let sayHi = new Function('alert("Hello")');

sayHi(); // Hello