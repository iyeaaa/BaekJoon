var ans = ""

for _ in 0..<Int(readLine()!)! {
    let N = Int(readLine()!)!
    let L = [0]+readLine()!.split{$0==" "}.map{Int(String($0))!}
    var S = [Int](repeating: 0, count: N+1)
    var memo = (0...N).map{_ in (0...N).map{_ in 0}}

    for i in 1...N {
        S[i] = S[i-1] + L[i]
    }

    for len in 2...N {
        for t in len...N {
            let h = t - len + 1
            var temp = Int.max
            for b in h..<t {
                temp = min(temp, memo[h][b] + memo[b+1][t] + S[t] - S[h-1])
            }
            memo[h][t] = temp
        }
    }

    ans += "\(memo[1][N])\n"
}

print(ans)