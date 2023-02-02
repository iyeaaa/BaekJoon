
let N = Int(readLine()!)!
var memo = [Int](repeating: 0, count: 101)

for i in 1...6 { memo[i] = i }

for i in stride(from: 7, through: N, by: 1) {
    for j in 3...i-3 {
        memo[i] = max(memo[i], memo[j]*(i-j-1))
    }
}

print(memo[N])