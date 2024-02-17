import React from "react";
import styled from "styled-components";



const Grid = ({ randomBunnies }) => {
  return (
    <GridDive>
      {randomBunnies.map((randomBunny) => {
        return <Cell>{randomBunny}</Cell>;
      })}
    </GridDive>
  );
};

export default Grid;
const GridDive = styled.div`
  display: grid;
  grid-template-rows: repeat(20, auto);
  grid-template-columns: repeat(25, auto);
  height: 90vh;
  width: 70vw;
  border: 1px solid rgb(110, 105, 105);
`;

const Cell = styled.div`
  border: 0.5px dashed yellow;
  color: white;
  display: flex;
  text-align: center;
`;
