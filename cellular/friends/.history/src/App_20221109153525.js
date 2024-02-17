import Grid from "./components/Grid";
import { useState, useMemo } from "react";

function App() {
  const random = () => {
    const maxNumber = 1;
    return Math.floor(Math.random() * maxNumber);
  };
  const randoms = () => {
    let randomBunnies = [];
    for (let i = 0; i < 100; i++) {
      randomBunnies.push(random());
    }
    return randomBunnies;
  };
  const randomBunnies = useMemo(() => randoms());

  return <Grid randomBunnies={randomBunnies} />;
}

export default App;
