import React from "react";

const Grid = ({ randomBunnies }) => {
  console.log(randomBunnies);
  return (
    <div className="grid-outline">
      {randomBunnies.map((randomBunny) => {
        return <div className="cell">{randomBunny}</div>;
      })}
    </div>
  );
};

export default Grid;
