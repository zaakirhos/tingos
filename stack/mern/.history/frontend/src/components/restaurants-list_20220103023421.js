import React, {useState, useEffect} from 'react'
import RestaurantDataService from "../services/restaurant";
import { Link } from "react-router-dom";

const RestaurantsList = () => {
    const [restaurants, setRestaurants] = useState([]);
     useEffect(() => {
       retrieveRestaurants();
     }, []);
     
      const retrieveRestaurants = () => {
        RestaurantDataService.getAll()
          .then((response) => {
            console.log(response.data);
            setRestaurants(response.data.restaurants);
          })
          .catch((e) => {
            console.log(e);
          });
      };
    return (
        <div>
            Hello
        </div>
    )
}

export default RestaurantsList
