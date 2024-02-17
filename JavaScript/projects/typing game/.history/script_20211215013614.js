
const quoteDisplayElement = document.getElementById("quoteDisplay");
const quoteLength = document.getElementById("quoteLength");
const quoteInputElement = document.getElementById("quoteInput");
const timerElement = document.getElementById("timer");



var quotes = [];

async function getQuotes() {
  const response = await fetch("https://type.fit/api/quotes");
  const fetchedQuotes = await response.json();
main(fetchedQuotes);
}


function main(fetchedQuotes) {