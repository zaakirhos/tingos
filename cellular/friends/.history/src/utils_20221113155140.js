export const shuffleArray = (array) => {
    let newArray =array
  for (let i = new.length - 1; i > 0; i--) {
    const j = Math.floor(Math.random() * (i + 1));
    const temp = new[i];
    new[i] = new[j];
    new[j] = temp;
  }
  return array;
};
