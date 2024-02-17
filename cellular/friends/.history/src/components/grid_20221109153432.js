import React from "react";


const Grid = ({randomBunnies}) => {
    console.log()
  return (
    <div className="grid-outline">
        {randomBunnies.map(randomBunny => {
            <div className="cell">{randomBunny}</div>
        })}
    </div>
  )
};

export default Grid;
