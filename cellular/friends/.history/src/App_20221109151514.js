import Grid from "./components/Grid";

function App() {
  const random = () => {
    const maxNumber = 1;
    const randomNumber = Math.floor(Math.random() * maxNumber + 1);
  }
    return <div>{randomNumber}</div>;
  }
  return <Grid />;
}

export default App;
