import React from "react";
import styled from "styled-components";

const colors = {
  1: "blue",
  2: "green",
  3: "#31dead",
  4: "#31de6b",
  5: "#adde31",
  6: "#ded831",
  7: "#dea431",
  8: "#de6e31",
  9: "#de4e31",
  10: "#de3131",
  11: "#f50202",
};

const Grid = ({ currentBunnies }) => {
  return (
    <GridDive>
      {currentBunnies.map((current) => {
        let color = current <= 10 ? colors[current] : null;
        return <Cell color={color}></Cell>;
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
  grid-gap: 5px;
  border: 1px solid rgb(110, 105, 105);
`;

const Cell = styled.div`
  border-radius: 50%;
  color: white;
  background: ${(props) => props.color || "#f50202"};
  display: flex;
  text-align: center;
`;
