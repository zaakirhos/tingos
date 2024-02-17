import Grid from "./components/Grid";
import { useState, useMemo, useEffect } from "react";

function App() {
  const random = (max, min) => {
    return Math.floor(Math.random() * max + min);
  };
  const randoms = () => {
    let randomBunnies = [];
    for (let i = 0; i < 475; i++) {
      randomBunnies.push(random(2, 0));
    }
    for (let i = 0; i<25; i++){
      randomBunnies.push(random(2))
    }
    return randomBunnies;
  };
  const randomBunnies = useMemo(() => randoms());

  return <Grid randomBunnies={randomBunnies} />;
}

export default App;
