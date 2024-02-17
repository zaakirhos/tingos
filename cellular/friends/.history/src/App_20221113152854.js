import Grid from "./components/Grid";


function App() {
  const random = (max, min) => {
    return Math.floor(Math.random() * max + min);
  };
  const randoms = () => {
    let randomBunnies = [];
    for (let i = 0; i < 475; i++) {
      randomBunnies.push(random(10, 1));
    }
    for (let i = 0; i < 25; i++) {
      randomBunnies.push(random(25, 15));
    }
    return randomBunnies;
  };

  const shuffleArray = (array) => {
    for (let i = array.length - 1; i > 0; i--) {
      const j = Math.floor(Math.random() * (i + 1));
      const temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
    return array;
  };


  return <Grid currentBunnies={currentBunnies} />;
}

export default App;
