
let n = Int(readLine()!)!
let t = [0]+readLine()!.split(separator: " ").map{Int(String($0))!}
let m = Int(readLine()!)!
var memo = [[Int]](repeating: [Int](repeating: 0, count: n+1), count: 4)
var s = [Int](repeating: 0, count: n+1); s[1] = t[1]

for i in 2...n {s[i] = s[i-1] + t[i]}

for i in 1...3 {
    for j in stride(from: i*m, through: n, by: 1) {
        memo[i][j] = max(memo[i][j-1], memo[i-1][j-m] + (s[j]-s[j-m]))
    }
}

print(memo[3][n])