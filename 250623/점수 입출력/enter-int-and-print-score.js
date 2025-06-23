const fs = require('fs');
let inputs = fs.readFileSync(0).toString().trim()

let num = Number(inputs)

console.log(`Your score is ${num} point.`)