let INF = 987654321
let CMD = [0]+readLine()!.split(separator: " ").map{Int(String($0))!}
let N = CMD.count-1
var memo = Array(repeating: Array(repeating: Array(repeating: INF
        , count: 5), count: 5), count: N+1)
var ans = Int.max
var C = [[0, 2, 2, 2, 2],
         [0, 1, 3, 4, 3],
         [0, 3, 1, 3, 4],
         [0, 4, 3, 1, 3],
         [0, 3, 4, 3, 1]]

memo[0][0][0] = 0

for i in 1...N {
    let cmd = CMD[i]
    for j in 0...4 {
        var temp1 = INF, temp2 = INF
        for k in 0...4 {
            temp1 = min(temp1, memo[i-1][k][j]+C[k][cmd])
            temp2 = min(temp2, memo[i-1][j][k]+C[k][cmd])
        }
        memo[i][cmd][j] = temp1
        memo[i][j][cmd] = temp2
    }
}

for i in 0...4 {
    ans = min(ans, memo[N][CMD[N]][i], memo[N][i][CMD[N]])
}

print(ans)