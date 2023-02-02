
import Foundation

struct Disjoint_Set {
    var parent: [Int]
    var size: [Int]
    var rank: [Int]

    init(_ x: Int) {
        parent = Array(0...x)
        size = [Int](repeating: 1, count: x)
        rank = [Int](repeating: 0, count: x)
    }

    mutating func find(_ x: Int) -> Int {
        if parent[x] == x { return x }
        parent[x] = find(parent[x])
        return parent[x]
    }

    mutating func uni(_ x: Int, _ y: Int) {
        let x = find(x), y = find(y)
        if rank[x] < rank[y] {
            parent[x] = y; size[y] += size[x]
        } else {
            parent[y] = x; size[x] += size[y]
        }
        if rank[x] == rank[y] { rank[x] += 1 }
    }
}

func dist(_ x1: Int, _ y1: Int, _ x2: Int, _ y2: Int) -> Double {
    sqrt(Double((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)))
}

var ans = ""
for _ in 0..<Int(readLine()!)! {
    let n = Int(readLine()!)!
    var l = [(x: Int, y: Int, r: Int)]()
    var uf = Disjoint_Set(n)
    var v = [Bool](repeating: false, count: n)
    var cnt = 0

    for i in 0..<n {
        let input = readLine()!.split{$0==" "}.map{Int(String($0))!}
        let (x, y, r) = (input[0], input[1], input[2])
        l.append((x, y, r))
        for j in 0..<i {
            if dist(l[j].x, l[j].y, x, y) > Double(l[j].r + r) {
                continue
            }
            uf.uni(i, j)
        }
    }

    for i in 0..<n {
        let p = uf.find(i)
        if !v[p] { cnt += 1; v[p] = true }
    }

    ans += "\(cnt)\n"
}

print(ans)