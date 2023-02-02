
var ans = ""
var coin = [1, 10, 25]
var dp = [Int](repeating: 99999999, count: 100)
dp[0] = 0

for c in coin {
    for i in c..<100 {
        dp[i] = min(dp[i], dp[i-c]+1)
    }
}

for _ in 0..<Int(readLine()!)! {
    var cnt = 0
    var n = Int(readLine()!)!
    while n > 0 {
        cnt += dp[n%100]
        n /= 100
    }
    ans += "\(cnt)\n"
}

print(ans)