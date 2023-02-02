
let N = Int(readLine()!)!
let a = [0]+readLine()!.split(separator: " ").map{Int(String($0))!}
let b = [0]+readLine()!.split(separator: " ").map{Int(String($0))!}
var memo = [Int](repeating: 0, count: N+1)
var s = 0

for i in 1...N where b[i] == 1 { s += a[i] }
memo[1] = b[1] == 0 ? s + a[1] : s - a[1]

var ans = memo[1]

for i in stride(from: 2, through: N, by: 1) {
    if b[i] == 1 {
        memo[i] = max(s - a[i], memo[i-1] - a[i])
    } else {
        memo[i] = max(s + a[i], memo[i-1] + a[i])
    }
    ans = max(ans, memo[i])
}

print(ans)