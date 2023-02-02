
// f(n, k, m): 수열의 개수가 n, 인접한 비트의 개수가 k, 끝자리가 m으로 끝나는 수열의 개수
// f(n, k, 0) = f(n-1, k, 0) + f(n-1, k, 1)
// f(n, k, 1) = f(n-1, k, 0) + f(n-1, k-1, 1)
// ans = f(n, k, 0) + f(n, k, 1)

var memo = Array(repeating: Array(repeating: [0, 0], count: 101), count: 101)
var ans = ""

memo[1][0][0] = 1; memo[1][0][1] = 1

for i in 2...100 {
    for j in 0..<i {
        memo[i][j][0] = memo[i-1][j][0] &+ memo[i-1][j][1]
        memo[i][j][1] = memo[i-1][j][0] &+ (j == 0 ? 0 : memo[i-1][j-1][1])
    }
}

for _ in 0..<Int(readLine()!)! {
    let input = readLine()!.split{$0==" "}.map{Int(String($0))!}
    let (n, k) = (input[0], input[1])
    ans += "\(memo[n][k].reduce(0, +))\n"
}

print(ans)