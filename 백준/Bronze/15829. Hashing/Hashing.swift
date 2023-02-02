let n = Int(readLine()!)!
var save = 1
let str = Array(readLine()!)
var result = 0

for i in 0..<n {
    result = (result + ((Int(str[i].asciiValue!) - 96) * save)) % 1234567891
    save *= 31
}

print(result)

