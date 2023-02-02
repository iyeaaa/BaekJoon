
let input = readLine()!.split{$0==" "}.map{Int(String($0))!}
let (N, M) = (input[0], input[1])
var G = [[Int](repeating: 0, count: 1005)]

for _ in 0..<N {
    G.append([0]+readLine()!.split{$0==" "}.map{Int(String($0))!})
}

for i in 1...N {
    for j in 1...M {
        G[i][j] += max(G[i-1][j], G[i][j-1], G[i-1][j-1])
    }
}

print(G[N][M])