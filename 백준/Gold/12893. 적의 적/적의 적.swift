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

struct UnionFind {
    var parent: [Int]
    var enemy: [Int]

    init(_ n: Int) { parent = Array(0...n); enemy = Array(repeating: 0, count: n+1) }

    mutating func root(of x: Int) -> Int {
        if x == parent[x] { return x }
        parent[x] = root(of: parent[x])
        return parent[x]
    }

    mutating func merge(_ x: Int, with y: Int) {
        let (x, y) = (root(of: x), root(of: y))
        if x == y { return }
        parent[x] = y
    }

    mutating func isUnion(_ x: Int, with y: Int) -> Bool {
        root(of: x) == root(of: y)
    }
}

let io = IO()
let (N, M) = (io.readInt(), io.readInt())
var ds = UnionFind(N)
var answer = 1

for _ in 0..<M {
    let (a, b) = (ds.root(of: io.readInt()), ds.root(of: io.readInt()))
    if a == b { answer = 0; break }

    if ds.enemy[a] != 0 {
        ds.merge(ds.enemy[a], with: b)
    } else {
        ds.enemy[a] = b
    }

    if ds.enemy[b] != 0 {
        ds.merge(ds.enemy[b], with: a)
    } else {
        ds.enemy[b] = a
    }
}

print(answer)