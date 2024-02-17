import logo from './logo.svg';
import React from 'react'
import {Switch, Route, Link} from 'react-router-dom';
import "bootstrap/dist/css/bootstrap.min.css";

import RestaurantsList from './components/RestaurantsList';
import './App.css';

function App() {
  return (
    <div className="App">
      <Link to="/">
        <RestaurantsList />
      </Link>
    </div>
  );
}

export default App;
