
var ans = ""

for i in 1... {
    let input = readLine()!.split{$0==" "}.map{Int(String($0))!}
    if input == [0, 0] { break }
    let (n, m) = (input[0], input[1])
    var g = [[Int]](repeating: [], count: n+1)
    var v = [Bool](repeating: false, count: n+1)
    var t = 0

    for _ in 0..<m {
        let input = readLine()!.split{$0==" "}.map{Int(String($0))!}
        g[input[0]].append(input[1])
        g[input[1]].append(input[0])
    }

    func isTree(_ i: Int) -> Bool {
        var queue = [i], idx = 0; v[i] = true
        var node_cnt = 0, edge_cnt = 0
        while idx < queue.count {
            let cur = queue[idx]; idx += 1
            node_cnt += 1
            edge_cnt += g[cur].count
            for next in g[cur] where !v[next] {
                queue.append(next)
                v[next] = true
            }
        }
        return edge_cnt == (node_cnt - 1) * 2
    }

    for i in 1...n where !v[i] {
        t += isTree(i) ? 1 : 0
    }

    if t == 0 {
        ans += "Case \(i): No trees.\n"
    } else if t == 1 {
        ans += "Case \(i): There is one tree.\n"
    } else {
        ans += "Case \(i): A forest of \(t) trees.\n"
    }
}

print(ans)