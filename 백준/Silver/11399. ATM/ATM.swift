let num = Int(readLine()!)!
let line = readLine()!.split(separator: " ").map{Int(String($0))!}.sorted(by: <)
var answer = 0

for i in 0..<num {
    for j in 0...i {
        answer += line[j]
    }
}

print(answer)