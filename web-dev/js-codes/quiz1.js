// const prompt = require("prompt-sync")({ sigint: true });

// function calcu(oper, a, b) {
//     let r = Math.random()
//     let res = 0
//     console.log(typeof a, typeof b)
//     if (r < 0.1) {
//         if (oper == 1) {
//             res = a - b
//         }
//         else if (oper == 2) {
//             res = a / b
//         }
//         else if (oper == 3) {
//             res = a + b
//         }
//         else {
//             res = a ** b
//         }
//         console.log("RIP lol!")
//     }
//     else {
//         if (oper == 1) {
//             res = a + b
//         }
//         else if (oper == 2) {
//             res = a - b
//         }
//         else if (oper == 3) {
//             res = a * b
//         }
//         else {
//             res = a / b
//         }
//         console.log("Good luck! :)")
//     }
//     console.log(res)
// }

// for (let i = 0; i < 10; i++) {
//     console.log("RUN" + i)
    
//     let oper = parseInt(prompt("Which operation do you want to perform?" + "\n\n1 for Addition (+)" + "\n2 for Subtraction (-)" + "\n3 for Multiplication (*)" + "\n4 for Division (/)" + "\n\nEnter your choice: "))
//     let a = parseInt(prompt("Enter the first number:"))
//     let b = parseInt(prompt("Enter the second number:"))

//     calcu(oper, a, b)
// }


/* Create a faulty calculator using JavaScript

This faulty calculator does following:
1. It takes two numbers as input from the user
2. It perfoms wrong operations as follows:

+ ---> -
* ---> +
- ---> /
/ ---> **

It performs wrong operation 10% of the times

*/

let random = Math.random()
console.log(random)
let a = prompt("Enter first number")
let c = prompt("Enter operation")
let b = prompt("Enter second number")

let obj = {
    "+": "-",
    "*": "+",
    "-": "/",
    "/": "**",
}



if (random > 0.1) {
    // Perform correct calculation
    console.log(`The result is ${a} ${c} ${b}`)
    alert(`The result is ${eval(`${a} ${c} ${b}`)}`)
    
}

else {
    // Perform wrong calculation
    c = obj[c]
    alert(`The result is ${eval(`${a} ${c} ${b}`)}`) 

}