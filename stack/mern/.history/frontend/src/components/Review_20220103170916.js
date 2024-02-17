import React, {useState, useEffect} from 'react'
import RestaurantDataService from "../services/restaurant";

const Review = () => {

    let data = {
      text: "Grest Food",
      user_id: "1234",
      name: "Ron's",
    };
     RestaurantDataService.createReview(data)
       .then((response) => {
         console.log(response.data);
       })
       .catch((e) => {
         console.log(e);
       });
    return (
        <div>
            Reviews
        </div>
    )
}

export default Review
