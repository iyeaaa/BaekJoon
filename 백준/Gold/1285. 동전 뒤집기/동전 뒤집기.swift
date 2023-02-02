
var ans = Int.max
let n = Int(readLine()!)!
var g = [[Int]]()

for _ in 1...n {
    g.append(Array(readLine()!).map{$0=="H" ? 0 : 1})
}

for row in 0..<(1<<n) {
    var sum = 0
    for j in 0..<n {
        var back = 0
        for i in 0..<n {
            var cur = g[i][j]
            if row & (1<<i) != 0 {
                cur = 1 - cur
            }
            if cur == 1 {
                back += 1
            }
        }
        sum += min(back, n-back)
    }
    ans = min(ans, sum)
}

print(ans)