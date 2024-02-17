let now = new Date();
console.log(now); // shows current date/time

// 0 means 01.01.1970 UTC+0
let Jan01_1970 = new Date(0);
console.log( Jan01_1970 );

// now add 24 hours, get 02.01.1970 UTC+0
let Jan02_1970 = new Date(24 * 3600 * 1000);
console.log( Jan02_1970 );

//Dates before 01.01.1970 have negative timestamps, e.g.:
// 31 Dec 1969
let Dec31_1969 = new Date(-24 * 3600 * 1000);
console.log( Dec31_1969 );

let date = new Date("2017-01-26");
console.log(date);
// The time is not set, so it's assumed to be midnight GMT and
// is adjusted according to the timezone the code is run in
// So the result could be
// Thu Jan 26 2017 11:00:00 GMT+1100 (Australian Eastern Daylight Time)
// or
// Wed Jan 25 2017 16:00:00 GMT-0800 (Pacific Standard Time)


/**
 * new Date(year, month, date, hours, minutes, seconds, ms)
 * Create the date with the given components in the local time zone. Only the first two arguments are obligatory.
 * The year must have 4 digits: 2013 is okay, 98 is not.
The month count starts with 0 (Jan), up to 11 (Dec).
The date parameter is actually the day of month, if absent then 1 is assumed.
If hours/minutes/seconds/ms is absent, they are assumed to be equal 0.
 */

new Date(2011, 0, 1, 0, 0, 0, 0); // 1 Jan 2011, 00:00:00
new Date(2011, 0, 1); // the same, hours etc are 0 by default


//The maximal precision is 1 ms (1/1000 sec):
date = new Date(2011, 0, 1, 2, 3, 4, 567);
console.log( date ); // 1.01.2011, 02:03:04.567


//Accessors
console.log( date.getFullYear() );
console.log(date.getMonth()); //0-11
console.log(date.getDate()); //1-31
//getHours(), getMinutes(), getSeconds(), getMilliseconds()
console.log(date.getDay()) //Sun-Sat: 0-6
console.log(date.getTime()); //the date in timestamp, milliseconds since Jan 1 1970


//Returns the difference between UTC and the local time zone, in minutes:
console.log(date.getTimezoneOffset());



/**
 * Setters:
 * setFullYear(year, [month], [date])
setMonth(month, [date])
setDate(date)
setHours(hour, [min], [sec], [ms])
setMinutes(min, [sec], [ms])
setSeconds(sec, [ms])
setMilliseconds(ms)
 */


//Autocorrection
date = new Date(2013, 0, 32); // 32 Jan 2013 ?!?
console.log(date); // ...is 1st Feb 2013!

date = new Date(2016, 1, 28);
date.setDate(date.getDate() + 2); //No problem if it was a leap year
console.log( date ); // 1 Mar 2016

//Now
console.log(Date.now())


//Parse
let ms = Date.parse('2012-01-26T13:51:50.417-07:00');
console.log(ms); // 1327611110417  (timestamp)
