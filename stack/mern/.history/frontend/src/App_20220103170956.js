import logo from './logo.svg';
import React from 'react'
import {Routes, Route, Link} from 'react-router-dom';
import "bootstrap/dist/css/bootstrap.min.css";

import RestaurantsList from './components/RestaurantsList';
import Review from "./components/Review";
import './App.css';

function App() {
  return (
    <div className="App">
      <Routes>
        <Route exact path="/r" element={<RestaurantsList />}></Route>
        <Route exact path="/re" element={<Review />}></Route>
      </Routes>
    </div>
  );
}

export default App;
