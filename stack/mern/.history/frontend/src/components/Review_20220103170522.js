import React, {useState, useEffect} from 'react'
import RestaurantDataService from "../services/restaurant";

const Review = () => {

    let data
     RestaurantDataService.createReview(data)
       .then((response) => {
         console.log(response.data);
       })
       .catch((e) => {
         console.log(e);
       });
    return (
        <div>
            
        </div>
    )
}

export default Review
