import Grid from "./components/Grid";
import { shuffleArray } from "./utils";

function App() {
  const random = (max, min) => {
    return Math.floor(Math.random() * max + min);
  };
  const randoms = () => {
    let randomBunnies = [];
    for (let i = 0; i < 32; i++) {
      randomBunnies[i] = []
      for(let j = 0; j<32; j++){
      }
      randomBunnies.push(random(5, 1));
    }
    for (let i = 0; i < 24; i++) {
      randomBunnies.push(20);
    }
    console.log(randomBunnies);
    return randomBunnies;
  };

  return <Grid initialBunnies={shuffleArray(randoms())} />;
}

export default App;
