
let n = Int(readLine()!)!
var memo = [Int](repeating: 0, count: n+1)

memo[0] = 1
memo[1] = 1
for i in stride(from: 2, through: n, by: 1) {
    memo[i] = (memo[i-1] + memo[i-2]) % 10
}

print(memo[n])