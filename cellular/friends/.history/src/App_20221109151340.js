import Grid from "./components/Grid";

function App() {
  const random(props) {
    var maxNumber = 45;
    var randomNumber = Math.floor(Math.random() * maxNumber + 1);
    return <div>{randomNumber}</div>;
  }
  return <Grid />;
}

export default App;
