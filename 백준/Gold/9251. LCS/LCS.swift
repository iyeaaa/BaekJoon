
let strn1 = Array(readLine()!), strn2 = Array(readLine()!)
let len1 = strn1.count, len2 = strn2.count
var dp = [[Int]](repeating: [Int](repeating: 0, count: len2+1), count: len1+1)

for i in 1...len1 {
    for j in 1...len2 {
        dp[i][j] = strn1[i-1] == strn2[j-1] ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1])
    }
}

print(dp[len1][len2])