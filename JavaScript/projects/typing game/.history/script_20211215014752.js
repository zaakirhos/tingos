
const quoteDisplayElement = document.getElementById("quoteDisplay");
const author = document.getElementsByClassName("author");
const quoteInputElement = document.getElementById("quoteInput");
const timerElement = document.getElementById("timer");



var quotes = [];

function main(quotes) {

  quoteInputElement.addEventListener("input", () => {
  const quoteArray = quoteDisplayElement.querySelectorAll("span");
  const valueArray = quoteInputElement.value.split("");
  let correct = true;
  quoteArray.forEach((characterSpan, i) => {
    const character = valueArray[i];
    if (character == null) {
      characterSpan.classList.remove("correct");
      characterSpan.classList.remove("incorrect");
      correct = false;
    } else if (character === characterSpan.innerText) {
      characterSpan.classList.add("correct");
      characterSpan.classList.remove("incorrect");
    } else {
      characterSpan.classList.remove("correct");
      characterSpan.classList.add("incorrect");
      correct = false;
    }
  });
  if (correct) renderNextQuote();
});

function renderNextQuote() {
  const quote = quotes[Math.floor(Math.random() * quotes.length)];
  const quoteText = quote.text;
  console.log(quotes)
  words = quote.split(" ");

  quoteDisplayElement.innerText = "";
  author[0].innerText = quote
  quote.split("").forEach(character => {
    const characterSpan = document.createElement("span");
    // characterSpan.classList.add("correct");
    // characterSpan.classList.add("incorrect");
    characterSpan.innerText = character;
    quoteDisplayElement.appendChild(characterSpan);
  });
  quoteInputElement.value = null;
  startTimer();
}

let startTime;
function startTimer() {
  timerElement.innerHTML = 0;
  startTime = new Date();
  setInterval(() => {
    timerElement.innerText = getTimer();
  }, 1000);
}

function getTimer() {
  return Math.floor((new Date() - startTime) / 1000);
}

renderNextQuote();
}


async function getQuotes() {
  const response = await fetch("https://type.fit/api/quotes");
  const fetchedQuotes = await response.json();
  main(fetchedQuotes);
}


getQuotes();