import React from "react";
import { FontAwesomeIcon } from "@fortawesome/react-fontawesome";
import styled from "styled-components";
import { useState, useMemo, useEffect } from "react";
import { shuffleMatrix } from "../utils";

const colors = {
  1: "264653",
  2: "2a9d8f",
  3: "e9c46a",
  4: "f4a261",
  5: "e76f51",
};

const Grid = ({ initialBunnies }) => {
  const [currentBunnies, setCurrentBunnies] = useState(initialBunnies);
  const [nextBunnies, setNextBunnies] = useState();
  const [counter, setCounter] = useState(0);

  useEffect(() => {
    setInterval(() => {
      setCounter(counter + 1);
    }, 1000);
    // return () => {
    //   second;
    // };
  }, [counter]);
  const createCells = () => {
    let cells = [];
    for (let i = 0; i < currentBunnies.length; i++) {
      for (let j = 0; j < currentBunnies[0].length; j++) {
        let color =
          currentBunnies[i][j] <= 5 ? colors[currentBunnies[i][j]] : "d90429";
        cells.push(
          <Cell>
            <FontAwesomeIcon icon="fab" style="font-size:48px;color:red" />
          </Cell>
        );
      }
    }
    return cells;
  };
  return (
    <GridDive>
      {/* {currentBunnies.map((currentBunnyArray) => {
        currentBunnyArray.map((currentBunny) => {
          let color = currentBunny <= 5 ? colors[currentBunny] : null;
          return <Cell color={"#" + color}></Cell>;
        });
      })} */}
      {createCells()}
    </GridDive>
  );
};

export default Grid;
const GridDive = styled.div`
  display: grid;
  grid-template-rows: repeat(60, auto);
  grid-template-columns: repeat(60, auto);
  height: 90vh;
  width: 70vw;
  grid-gap: 5px;
  padding: 5px;
  border: 1px solid rgb(110, 105, 105);
`;

const Cell = styled.div`
  border-radius: 50%;
  color: white;
  /* background: ${(props) => props.color}; */
  display: flex;
  text-align: center;
`;
