
let N = Int(readLine()!)!
let A = readLine()!.split(separator: " ").map{Int(String($0))!}
var dp = [(i: Int, d: Int)](repeating: (1, 1), count: N)
var ans = 1

for i in 1..<N {
    for j in 0..<i {
        if A[j] < A[i] {
            dp[i].i = max(dp[j].i+1, dp[i].i)
        } else
        if A[j] > A[i] {
            dp[i].d = max(dp[j].i+1, dp[j].d+1, dp[i].d)
        }
        ans = max(ans, dp[i].i, dp[i].d)
    }
}

print(ans)