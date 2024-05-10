function rand_no() {
    n = Math.random()
    m = n * 3 + 1
    res = Math.floor(m)
    return `n${res}`
}

console.log(rand_no())

let first_name_obj = { n1: "Crazy", n2: "Amazing", n3: "Fire" }
let middle_name_obj = { n1: "Engine", n2: "Foods", n3: "Garments" }
let last_name_obj = { n1: "Bros", n2: "Limited", n3: "Hub" }

let name1 = eval(`first_name_obj.${rand_no()}`)
let name2 = eval(`middle_name_obj.${rand_no()}`)
let name3 = eval(`last_name_obj.${rand_no()}`)

let fin_name = name1.concat(" ", name2, " ", name3)

console.log(fin_name)
