const RANDOM_QUOTE_API_URL = "https://zenquotes.io/api/quotes";
const quoteDisplayElement = document.getElementById("quoteDisplay");
const quoteLength = document.getElementById("quoteLength");
const quoteInputElement = document.getElementById("quoteInput");
const timerElement = document.getElementById("timer");


let currentQuotes = []

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

async function getRandomQuote() {
  const response = await fetch(RANDOM_QUOTE_API_URL);
  const data = await response.json();
  return data.content;
}

console.log(getRandomQuote());


function renderNextQuote() {
  const quote = getRandomQuote();
  words = quote.split(" ");
  quoteLength.innerHTML = words.length;

  quoteDisplayElement.innerText = "";
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
