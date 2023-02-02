
let N = Int(readLine()!)!
var S = [Int](repeating: 0, count: 301)
var dp = [Int](repeating: 0, count: 301)

for i in 1...N {
    S[i] = Int(readLine()!)!
}

dp[1] = S[1]; dp[2] = dp[1]+S[2]

for i in stride(from: 3, through: N, by: 1) {
    dp[i] = max(dp[i], dp[i-3]+S[i-1]+S[i], dp[i-2]+S[i])
}

print(dp[N])