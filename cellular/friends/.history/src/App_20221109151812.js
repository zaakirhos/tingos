import Grid from "./components/Grid";
import use

function App() {
  const random = () => {
    const maxNumber = 1;
    const randomNumber = Math.floor(Math.random() * maxNumber + 1);
  }
  const randoms = () =>{
    randomBunnies = []
    for(let i = 0; i<100; i++){
      randomBunnies.add(random())
    }
  }
  return <Grid />;
}

export default App;
