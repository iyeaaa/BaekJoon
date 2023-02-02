
let N = Int(readLine()!)!
let A = readLine()!.split(separator: " ").map{Int(String($0))!}
var dp = A

for i in 1..<N {
    for j in 0..<i where A[j] < A[i] {
        dp[i] = max(dp[i], dp[j]+A[i])
    }
}

print(dp.max()!)