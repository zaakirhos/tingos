export const shuffleArray = (array) => {
    let newArray = array
  for (let i = newArray.length - 1; i > 0; i--) {
    const j = Math.floor(Math.random() * (i + 1));
    const temp = newArray[i];
    newArray[i] = newArray[j];
    newArray[j] = temp;
  }
  return newArray;
};
export const shuffleMatrix = (matrix) =>{
  let newMatrix = []

  for (let i = 0; i<matrix.length; i++){
    newMatrix[i].push(shuffleArray(matrix[i]))
  }
  return new
}
const neighborInfo = (currentBunnies, i, j) =>{

}
export const nextBunnies = (currentBunnies) =>{

}