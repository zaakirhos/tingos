import React, {useState, useEffect} from 'react'
import RestaurantDataService from "../services/restaurant";

const Review = () => {

    let data = {
      review_id: "61d36554f476a3c7ad933b91",
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
            
        </div>
    )
}

export default Review
