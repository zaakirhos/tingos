import Grid from "./components/Grid";

function App() {
  const random = () => {
    var maxNumber = 45;
    var randomNumber = Math.floor(Math.random() * maxNumber + 1);
    return <div>{randomNumber}</div>;
  }
  return <Grid />;
}

export default App;
