const fs = require('fs');
let input = fs.readFileSync(0).toString().trim();

input = Number(input)
input += 2;

console.log(input)