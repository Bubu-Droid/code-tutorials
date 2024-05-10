let arr = [1, 2, 4, 5, 7]
//  Index  0, 1, 2, 3, 4

arr[0] = 5666;
// console.log(arr, typeof arr);
// console.log(arr.length)

// console.log(arr[0])
// console.log(arr[2])
// console.log(arr[4])

console.log(arr.toString())
console.log(arr.join(" and "))

console.log(arr.pop()) // removes last
console.log(arr.push(" ok ")) // adds last

console.log(arr.shift()) // removes first
console.log(arr.unshift(" ok ")) // adds first

delete arr[2] // although this deletes the element, yet it shows the length is unchanged and in place of the deleted element, it adds in "empty", i.e., undefined value

let arr1 = [1,2,3]
let arr2 = [4,5,6]
let arr3 = [7,8,9]

let arr4 = arr1.concat(arr2, arr3) // this returns a new array and does not change the previous one

arr.sort() // this changes the original array

arr.splice(2) // this returns an array containing all the elements starting from the 2nd position till the last and deletes them from the original array

arr.splice(1, 3) // this returns an array containing 3 elements starting from the 1st position and deletes them from the original array (completely removes them, i.e., does not leave any `empty' behind)

arr.splice(1,3,44234,234213,2134233466) // this will remove the elements similarly as previously and then add the elements mentioned starting from the 3rd argument and add it into the array starting from the 1st position

arr.splice(3)

let a = [1, 93, 5, 6, 88]


// for (let index = 0; index < a.length; index++) {
//     const element = a[index];
//     console.log(element)
    
// }

// a.forEach((value, index, arr)=>{
//     console.log(value, index, arr)
// })

// let obj = {
//     a: 1,
//     b: 2,
//     c: 3
// }
// for (const key in obj) {
//     if (Object.hasOwnProperty.call(obj, key)) {
//         const element = obj[key]; 
//         console.log(key, element)
//     }
// }

// for (const value of a) {
//     console.log(value)
// }

let arr = [1, 13, 5 ,7, 11];
// let newArr = []
// for (let index = 0; index < arr.length; index++) {
//     const element = arr[index];
//     newArr.push(element**2)
// }

let newArr = arr.map((e, index, array)=>{
    return e**2
})

console.log(newArr)
const greaterThanSeven = (e)=>{
    if(e>7){
        return true
    }
    return false
}
console.log(arr.filter(greaterThanSeven))

let arr535 = [1,2,3,4,5,6]

const red = (a, b)=>{
    return a+b
}

console.log(arr535.reduce(red))

console.log(Array.from("Bubu"))
