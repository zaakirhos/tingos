
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



  let quotes = [];

  async function getRandomUser() {
    // gets the response from the api and put it inside a constant
    const response = await fetch("https://type.fit/api/quotes");
    //the response have to be converted to json type file, so it can be used
    const quotes = await response.json();
    //the addquotes adds the object "quotes" to an array
    addQuotes(quotes);
  }

  function addQuotes(fetchedQUotes) {
    // the push method add a new item to an array
    // here it will be adding the object from the function getRandomUser each time it is called
    quotes.push(quotes);
    //the fetched quotes is available only on this scope
    console.log("This is the value of date inside the function addquotes:");
    console.log(quotes);
  }

  //Calls the function that fetches the quotes
  getRandomUser();

  console.log("This is the value of quotes outside the scope");
  console.log(quotes);

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
