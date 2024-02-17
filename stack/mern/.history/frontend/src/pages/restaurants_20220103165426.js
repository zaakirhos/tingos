
import React from "react";
import { Switch, Route, Link } from "react-router-dom";
import "bootstrap/dist/css/bootstrap.min.css";

import RestaurantsList from "../components/RestaurantsList";

function App() {
  return (
      <RestaurantsList />
  );
}

export default App;
