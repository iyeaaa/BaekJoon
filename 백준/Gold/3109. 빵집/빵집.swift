
let input = readLine()!.split{$0==" "}.map{Int(String($0))!}
let (R, C) = (input[0], input[1])
var V = [[Bool]](repeating: [Bool](repeating: false, count: C), count: R)
var G = [[Character]]()
var ans = 0

for _ in 0..<R {
    G.append(Array(readLine()!))
}

func isReach(_ y: Int, _ x: Int) -> Bool {
    if x == C-1 {
        return true
    }
    for ny in [y-1, y, y+1] {
        let nx = x+1
        guard (0..<R) ~= ny && (0..<C) ~= nx else { continue }
        if G[ny][nx] == "x" || V[ny][nx] { continue }

        V[ny][nx] = true
        if isReach(ny, nx) { return true }
    }
    return false
}

for i in 0..<R where isReach(i, 0) {
    ans += 1
}

print(ans)