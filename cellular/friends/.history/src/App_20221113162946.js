import Grid from "./components/Grid";
import { shuffleArray } from "./utils";

function App() {
  const random = (max, min) => {
    return Math.floor(Math.random() * max + min);
  };
  const randoms = () => {
    let randomBunnies = [];
    for (let i = 0; i < ; i++) {
      randomBunnies.push(random(10, 1));
    }
    for (let i = 0; i < 25; i++) {
      randomBunnies.push(random(25, 15));
    }
    return randomBunnies;
  };

  return <Grid initialBunnies={shuffleArray(randoms())} />;
}

export default App;
