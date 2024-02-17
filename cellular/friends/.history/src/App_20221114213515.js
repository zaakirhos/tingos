import Grid from "./components/Grid";
import { shuffleArray } from "./utils";

function App() {
  const random = (max, min) => {
    return Math.floor(Math.random() * max + min);
  };
  const randoms = () => {
    let randomBunnies = [];
    for (let i = 0; i < 1000; i++) {
      randomBunnies.push(random(6, 1));
    }
    for (let i = 0; i < 24; i++) {
      randomBunnies.push(20);
    }
    return randomBunnies;
  };
  console.log(ran)

  return <Grid initialBunnies={shuffleArray(randoms())} />;
}

export default App;
