import React, {useState, useEffect} from 'react'
import RestaurantDataService from "../services/restaurant";

const Review = () => {

     RestaurantDataService.createReview(data)
       .then((response) => {
         setSubmitted(true);
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
