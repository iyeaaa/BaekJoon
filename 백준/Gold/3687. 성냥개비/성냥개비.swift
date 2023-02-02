
import Foundation

let mat = [0, 0, 1, 7, 4, 2, 0, 8]
var dp = [Int](repeating: 99999999999999999, count: 101)

for i in 2...7 {
    dp[i] = mat[i]
}
dp[6] = 6

for i in 8...100 {
    for j in 2...7 {
        dp[i] = min(dp[i], dp[i-j]*10 &+ mat[j])
    }
}

var result = ""
for _ in 0..<Int(readLine()!)! {
    let n = Int(readLine()!)!
    result += "\(dp[n]) "
    if n % 2 == 0 {
        result += String(repeating: "1", count: n/2) + "\n"
    } else {
        result += "7" + String(repeating: "1", count: (n-3)/2) + "\n"
    }
}
print(result)

