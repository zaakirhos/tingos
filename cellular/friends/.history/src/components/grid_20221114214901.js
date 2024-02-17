import React from "react";
import styled from "styled-components";
import { useState, useMemo, useEffect } from "react";
import { shuffleMatrix } from "../utils";

const colors = {
  1: "264653",
  2: "2a9d8f",
  3: "e9c46a",
  4: "f4a261",
  5: "e76f51",
  20: "d90429",
};

const Grid = ({ initialBunnies }) => {
  const [currentBunnies, setCurrentBunnies] = useState(initialBunnies);
  const [nextBunnies, setNextBunnies] = useState();
  const [counter, setCounter] = useState(0);

  // const randomBunnies = useMemo(() => shuffleArray(randoms()));
  // console.log(randomBunnies);
  useEffect(() => {
    // animate();
    let newArray = shuffleMatrix(currentBunnies);
    setInterval(() => {
      setCurrentBunnies(newArray);
      setCounter(counter + 1);
      console.log(currentBunnies);
    }, 1000);
    // return () => {
    //   second;
    // };
  }, [counter]);
  return (
    <GridDive>
      {currentBunnies.map((currentBunnyArray) => {
       currentBunnyArray.map((currentBunny))
      })}
    </GridDive>
  );
};

export default Grid;
const GridDive = styled.div`
  display: grid;
  grid-template-rows: repeat(32, auto);
  grid-template-columns: repeat(32, auto);
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
  font-size: 20px;
`;
