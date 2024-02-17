import React, {useState, useEffect} from 'react'
import RestaurantDataService from "../services/restaurant";
import { Link } from "react-router-dom";

const RestaurantsList = () => {
    const [restaurants, setRestaurants] = useState([]);
     useEffect(() => {
       retrieveRestaurants();
     }, []);

     
    return (
        <div>
            Hello
        </div>
    )
}

export default RestaurantsList
