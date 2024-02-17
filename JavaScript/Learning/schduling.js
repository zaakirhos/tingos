//SetTimeout
//let timerId = setTimeout(func|code, [delay], [arg1], [arg2], ...)

function sayHi() {
  console.log("Hello");
}

setTimeout(sayHi, 1000); //calls sayHi after 1 sec

let timerId = setTimeout(() => console.log("never happens"), 1000);
console.log(timerId); // timer identifier

clearTimeout(timerId);
console.log(timerId); // same identifier (doesn't become null after canceling)



//setInterval
// repeat with the interval of 2 seconds
let timerId = setInterval(() => console.log('tick'), 2000);
// after 5 seconds stop
setTimeout(() => { clearInterval(timerId); console.log('stop'); }, 5000);