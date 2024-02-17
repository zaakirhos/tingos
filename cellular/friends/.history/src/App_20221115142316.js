import Grid from "./components/Grid";
import { shuffleArray } from "./utils";

function App() {
  const random = (max, min) => {
    return Math.floor(Math.random() * max + min);
  };
  const randoms = () => {
    let randomBunnies = [];
    for (let i = 0; i < 60; i++) {
      randomBunnies[i] = []
      for(let j = 0; j<60; j++){
         randomBunnies[i][(random(5, 1));
      }
     
    }
    for (let i = 0; i < 25; i++) {
      randomBunnies[i][random(31, 0)] = 20
    }
    return randomBunnies;
  };

  return <Grid initialBunnies={randoms()} />;
}

export default App;
