import logo from './logo.svg';
import {Switch, Route, Link} from 'react-router-dom';
import "boo"
import R from './components/R'
import './App.css';

function App() {
  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <p>
          Edit <code>src/App.js</code> and save to reload.
        </p>
        <a
          className="App-link"
          href="https://reactjs.org"
          target="_blank"
          rel="noopener noreferrer"
        >
          Learn React
        </a>
        <R></R>
      </header>
    </div>
  );
}

export default App;
