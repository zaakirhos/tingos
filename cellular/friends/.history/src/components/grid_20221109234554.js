import React from "react";
import styled from "styled-components";

const Grid = ({ randomBunnies }) => {
  console.log(randomBunnies);
  return (
    <GridDive className="grid-outline">
      {randomBunnies.map((randomBunny) => {
        return <div className="cell">{randomBunny}</div>;
      })}
    </GridDive>
  );
};

export default Grid;
const GridDive = styled.div`
  .grid-outline {
    display: grid;
    grid-template-rows: repeat(20, auto);
    grid-template-columns: repeat(25, auto);
    height: 90vh;
    width: 70vw;
    border: 1px solid rgb(110, 105, 105);
  }

  .grid-outline > * {
    border: 0.5px dashed yellow;
    color: white;
    display: flex;
    text-align: center;
  }
`; 
