
import Foundation

final class IO {
    private let buffer:[UInt8]
    private var index: Int = 0

    init(fileHandle: FileHandle = FileHandle.standardInput) {

        buffer = Array(try! fileHandle.readToEnd()!)+[UInt8(0)] // 인덱스 범위 넘어가는 것 방지
    }

    @inline(__always) private func read() -> UInt8 {
        defer { index += 1 }

        return buffer[index]
    }

    @inline(__always) func readInt() -> Int {
        var sum = 0
        var now = read()
        var isPositive = true

        while now == 10
                      || now == 32 { now = read() } // 공백과 줄바꿈 무시
        if now == 45 { isPositive.toggle(); now = read() } // 음수 처리
        while now >= 48, now <= 57 {
            sum = sum * 10 + Int(now-48)
            now = read()
        }

        return sum * (isPositive ? 1:-1)
    }

    @inline(__always) func readString() -> String {
        var now = read()

        while now == 10 || now == 32 { now = read() } // 공백과 줄바꿈 무시
        let beginIndex = index-1

        while now != 10,
              now != 32,
              now != 0 { now = read() }

        return String(bytes: Array(buffer[beginIndex..<(index-1)]), encoding: .ascii)!
    }

    @inline(__always) func readByteSequenceWithoutSpaceAndLineFeed() -> [UInt8] {
        var now = read()

        while now == 10 || now == 32 { now = read() } // 공백과 줄바꿈 무시
        let beginIndex = index-1

        while now != 10,
              now != 32,
              now != 0 { now = read() }

        return Array(buffer[beginIndex..<(index-1)])
    }

    @inline(__always) func writeByString(_ output: String) { // wapas
        FileHandle.standardOutput.write(output.data(using: .utf8)!)
    }
}

struct Disjoint_set {
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
        if rank[x] == rank[y] {
            rank[x] += 1
        }
    }

    mutating func isUni(_ x: Int, _ y: Int) -> Bool {
        find(x) == find(y)
    }
}

let io = IO(), MOD = Int(1e9)
let n = io.readInt(), m = io.readInt()
var g = [(x: Int, y: Int, w: Int)]()
var uf = Disjoint_set(n+1)
var s = 0, ans = 0

for i in 0..<m {
    g.append((io.readInt(), io.readInt(), io.readInt()))
    s += g[i].w
}
g.sort{$0.w > $1.w}

for (x, y, w) in g {
    let x = uf.find(x), y = uf.find(y)
    if x != y {
        let cnt = uf.size[x] * uf.size[y] % MOD
        ans = (ans + (cnt * s) % MOD) % MOD
        uf.uni(x, y)
    }
    s -= w
}

print(ans)