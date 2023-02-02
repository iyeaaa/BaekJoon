
let N = Int(readLine()!)!
var B = [[Int]](repeating: [Int](repeating: Int.max, count: N), count: N)
let dy = [-1, -1, -1, 0, 0, 1, 1, 1]
let dx = [-1, 0, 1, -1, 1, -1, 0, 1]
var close = [(y: Int, x: Int)]()
var ans = 0

for i in 0..<N {
    let input = Array(readLine()!)
    for j in 0..<input.count {
        if input[j] == "#" {
            close.append((i, j))
        } else {
            B[i][j] = Int(String(input[j]))!
        }
    }
}

for (y, x) in close {
    if isBomb(y, x) {
        rmvBomb(y, x)
        ans += 1
    }
}

print(ans)

func isRange(_ y: Int, _ x: Int) -> Bool {
    (0..<N) ~= y && (0..<N) ~= x
}

func isBomb(_ y: Int, _ x: Int) -> Bool {
    for dir in 0..<8 {
        let ny = y + dy[dir], nx = x + dx[dir]
        if !isRange(y, x) { continue }
        if B[ny][nx] == 0 { return false }
    }
    return true
}

func rmvBomb(_ y: Int, _ x: Int) {
    for dir in 0..<8 {
        let ny = y + dy[dir], nx = x + dx[dir]
        if !isRange(y, x) { continue }
        B[ny][nx] -= 1
    }
}
