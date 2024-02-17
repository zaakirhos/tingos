/**
 * class MyClass {
  // class methods
  constructor() { ... }
  method1() { ... }
  method2() { ... }
  method3() { ... }
  ...
}
 */

class User {
  constructor(name) {
    this.name = name;
  }

  sayHi() {
    alert(this.name);
  }
}

// Usage:
let user = new User("John");
user.sayHi();

class User {
  constructor(name) { this.name = name; }
  sayHi() { alert(this.name); }
}

// class is a function
alert(typeof User); // function

// ...or, more precisely, the constructor method
alert(User === User.prototype.constructor); // true

// The methods are in User.prototype, e.g:
alert(User.prototype.sayHi); // the code of the sayHi method

// there are exactly two methods in the prototype
alert(Object.getOwnPropertyNames(User.prototype)); // constructor, sayHi

//Class Expression
let User = class {
  sayHi() {
    alert("Hello");
  }
};

//Computed names
class User {
  ["say" + "Hi"]() {
    alert("Hello");
  }
}

new User().sayHi();