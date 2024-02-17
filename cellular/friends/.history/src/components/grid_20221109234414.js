import React from "react";
import styled from "styled-components";

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
