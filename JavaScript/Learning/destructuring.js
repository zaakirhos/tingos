const letters = ['A', 'B', 'C', 'D', 'E']
const nums = ['1', '2', '3', '4', '5']

//Old way
const a = letters[0];
const b = letters[1];

//Destructuring
const [a, b] = letters

const [a,, c, ...letters]

function sumMult(a, b){
    return [a+b, a*b]
}
const [sum, prod, div='no div'] = sumMult(3, 4)


//With Objects: real power

const person1 = {
    name: "Kyle",
    age: 24,
    address: {
        city: 'Somewhere',
        state: 'One of them'
    }   
}


const person2 = {
    name: "Sally",
    age: 32,
    address: {
        city: 'Somewhere',
        state: 'Another one of them'
    }   
}

const {name: FirstName, address : { city}, age} = person2 // name is the key, and mapping to var firstName


