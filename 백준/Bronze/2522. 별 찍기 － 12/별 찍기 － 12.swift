let n = Int(readLine()!)!
var result = ""

for i in 1...n {
    let space = String(repeating: " ", count: n-i)
    let star = String(repeating: "*", count: i)
    result += space + star + "\n"
}

for i in 1..<n {
    let space = String(repeating: " ", count: i)
    let star = String(repeating: "*", count: n-i)
    result += space + star + "\n"
}

print(result)