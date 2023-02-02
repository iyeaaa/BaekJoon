
let input = readLine()!.split{$0==" "}.map{Int(String($0))!}
let (n, m) = (input[0], input[1])
var g = [[Character]]()
var v = [[Int]](repeating: [Int](repeating: 0, count: m), count: n)
var ans = 0

for _ in 0..<n { g.append(Array(readLine()!)) }

for i in 0..<n {
    for j in 0..<m where v[i][j] == 0 && isCicle(i, j) {
        ans += 1
    }
}

print(ans)

func isCicle(_ y: Int, _ x: Int) -> Bool {
    if v[y][x] == 2 {
        return false
    }
    if v[y][x] == 1 {
        v[y][x] = 2
        return true
    }
    v[y][x] = 1
    let rtn: Bool
    switch g[y][x] {
    case "D": rtn = isCicle(y+1, x)
    case "L": rtn = isCicle(y, x-1)
    case "U": rtn = isCicle(y-1, x)
    default:  rtn = isCicle(y, x+1)
    }
    v[y][x] = 2
    return rtn
}