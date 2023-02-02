
let N = Int(readLine()!)!
var G = [[0]]
var ans = Int.max
var sum = 0

func dfs(_ x: Int, _ y: Int, _ d1: Int, _ d2: Int) -> Int {
    var popul = 0, sum = sum
    var maxValue = -1, minValue = Int.max
    var bound = Array(repeating: Array(repeating: false, count: N+1), count: N+1)

    let dl = [Int](repeating: -1, count: d1) + [Int](repeating: 1, count: d2)
    let dr = [Int](repeating: 1, count: d2) + [Int](repeating: -1, count: d1)
    var y1 = y
    var y2 = y

    for cnt in 0..<d1+d2 {
        for i in y1...y2 {
            bound[cnt+x][i] = true
        }
        y1 += dl[cnt]
        y2 += dr[cnt]
    }
    bound[x+d1+d2][y1] = true

    func rpt() {
        sum -= popul
        maxValue = max(maxValue, popul)
        minValue = min(minValue, popul)
        popul = 0
    }

    for r in 1..<x+d1 {
        for c in 1...y where !bound[r][c] {
            popul += G[r][c]
        }
    }
    rpt()
    for r in 1...x+d2 {
        for c in y+1...N where !bound[r][c] {
            popul += G[r][c]
        }
    }
    rpt()
    for r in x+d1...N {
        for c in 1..<y-d1+d2 where !bound[r][c] {
            popul += G[r][c]
        }
    }
    rpt()
    for r in x+d2+1...N {
        for c in y-d1+d2...N where !bound[r][c] {
            popul += G[r][c]
        }
    }
    rpt()

    maxValue = max(maxValue, sum)
    minValue = min(minValue, sum)

    return maxValue - minValue
}

for i in 1...N {
    G.append([0]+readLine()!.split{$0==" "}.map{Int(String($0))!})
    for p in G[i] { sum += p }
}

for x in 1...N {
    for y in 1...N {
        for d1 in 1...N {
            for d2 in 1...N {
                if x+d1+d2 > N { continue }
                if 1 > y-d1 { continue }
                if y+d2 > N { continue }

                ans = min(ans, dfs(x, y, d1, d2))
            }
        }
    }
}

print(ans)

