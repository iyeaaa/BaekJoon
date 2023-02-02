
let N = Int(readLine()!)!
var G = (0...N).map{_ in [Int]()}
var memo = (0...N).map{_ in (0, 0)}
var V = (0...N).map{_ in false}

for _ in 1..<N {
    let input = readLine()!.split{$0==" "}.map{Int(String($0))!}
    G[input[0]].append(input[1])
    G[input[1]].append(input[0])
}

find(1)
print(min(memo[1].0, memo[1].1))

func find(_ cur: Int) {
    V[cur] = true
    memo[cur].0 = 1
    for next in G[cur] where !V[next] {
        find(next)
        memo[cur].1 += memo[next].0
        memo[cur].0 += min(memo[next].0, memo[next].1)
    }
}
