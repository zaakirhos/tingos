import React from "react";


const Grid = ({randomBunnies}) => {
  return (
    <dive className="grid-outline">
        {randomBunnies.map(randomBunny => {
            <div class=>{randomBunny}</div>
        })}
    </dive>
  )
};

export default Grid;
