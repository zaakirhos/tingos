import React from "react";
import ''


const Grid = ({randomBunnies}) => {
  return (
    <dive className="grid-outline">
        {randomBunnies.map(randomBunny => {
            <div className="cell">{randomBunny}</div>
        })}
    </dive>
  )
};

export default Grid;
