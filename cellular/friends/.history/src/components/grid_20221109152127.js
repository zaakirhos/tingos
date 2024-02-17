import React from "react";


const Grid = ({randomBunnies}) => {
  return (
    <dive className="grid-outline">
        {randomBunnies.map(randomBunny => {
            <div>random</div>
        })}
    </dive>
  )
};

export default Grid;
