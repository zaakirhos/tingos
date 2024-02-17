import React from "react";


const Grid = ({randomBunnies}) => {
  return (
    <div className="grid-outline">
        {randomBunnies.map(randomBunny => {
            <div className="cell">{randomBunny}</div>
        })}
    </div>
  )
};

export default Grid;
