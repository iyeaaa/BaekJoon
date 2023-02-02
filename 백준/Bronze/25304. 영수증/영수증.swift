let ans = Int(readLine()!)!
let N = Int(readLine()!)!
var sum = 0

for _ in 0..<N {
    let input = readLine()!.split(separator: " ").map{Int(String($0))!}
    let (cost, cnt) = (input[0], input[1])
    sum += cost*cnt
}

print(sum == ans ? "Yes" : "No")