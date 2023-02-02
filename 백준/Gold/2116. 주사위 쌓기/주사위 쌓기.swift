
let N = Int(readLine()!)!
var D = [[Int]](repeating: [], count: N+1)
var ans = 0
var across = [0, 6, 4, 5, 2, 3, 1]

for i in 1...N {
    D[i] = [0]+readLine()!.split{$0==" "}.map{Int(String($0))!}
}

for start in 1...6 {
    var score = 0
    for i in 1...6 where i != start && i != across[start] {
        score = max(score, D[1][i])
    }
    var cur = across[start]
    for i in stride(from: 2, through: N, by: 1) {
        var next = 0
        for j in 1...6 where D[i][j] == D[i-1][cur] {
            next = j; break
        }
        var mx = 0
        for j in 1...6 where j != next && j != across[next] {
            mx = max(mx, D[i][j])
        }
        score += mx
        cur = across[next]
    }
    ans = max(ans, score)
}

print(ans)