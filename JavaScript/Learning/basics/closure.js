//If a variable is declared inside a code block {...}, it’s only visible inside that block.
{
  // do some job with local variables that should not be seen outside

  let message = "Hello"; // only visible in this block

  console.log(message); // Hello
}

try {
  console.log(message); // Error: message is not defined
} catch {
    console.log("'message' is not defined")
}



let na = "John";

function sayHi() {
  console.log("Hi, " + na);
}

na = "Pete";

sayHi(); // what will it show: "John" or "Pete"?