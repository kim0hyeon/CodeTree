const fs = require('fs')
let input = fs.readFileSync(0).toString().trim()

input = Number(input)

console.log(input)
if (input < 0){
    console.log('minus')
}