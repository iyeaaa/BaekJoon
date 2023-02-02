
let input = readLine()!.split{$0==" "}.map{Int(String($0))!}
let (N, K, S) = (input[0], input[1], input[2])
var L = [(x: Int, c: Int)]()
var ans = 0

for _ in 0..<N {
    let input = readLine()!.split{$0==" "}.map{Int(String($0))!}
    L.append((input[0], input[1]))
}

L.sort{$0.x < $1.x}
visit_lf(0)
visit_ryt(N-1)
print(ans)

func visit_lf(_ v: Int) {
    if v >= N {return}
    if L[v].x >= S {return}

    var cnt = 0, idx = v
    ans += (S - L[idx].x) * 2
    while idx < N && L[idx].x < S {
        if L[idx].c + cnt > K {
            L[idx].c -= K - cnt
            visit_lf(idx)
            return
        } else if L[idx].c + cnt == K {
            L[idx].c = 0
            visit_lf(idx+1)
            return
        } else {
            cnt += L[idx].c
            idx += 1
        }
    }
}

func visit_ryt(_ v: Int) {
    if v < 0 {return}
    if L[v].x <= S {return}

    var cnt = 0, idx = v
    ans += (L[idx].x - S) * 2
    while idx >= 0 && L[idx].x > S {
        if L[idx].c + cnt > K {
            L[idx].c -= K - cnt
            visit_ryt(idx)
            return
        } else if L[idx].c + cnt == K {
            L[idx].c = 0
            visit_ryt(idx-1)
            return
        } else {
            cnt += L[idx].c
            idx -= 1
        }
    }
}
