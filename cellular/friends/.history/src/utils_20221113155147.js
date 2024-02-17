export const shuffleArray = (array) => {
    let newArray =array
  for (let i = newAr.length - 1; i > 0; i--) {
    const j = Math.floor(Math.random() * (i + 1));
    const temp = newAr[i];
    newAr[i] = newAr[j];
    newAr[j] = temp;
  }
  return array;
};
