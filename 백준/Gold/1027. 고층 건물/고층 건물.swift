
let INF = Double(Int.min)
let N = Int(readLine()!)!
let B = readLine()!.split{$0==" "}.map{Int(String($0))!}
var ans = 0

for i in 0..<N {
    var high = -1*INF
    var cnt = 0
    for j in stride(from: i-1, through: 0, by: -1) {
        let cur = Double(B[i]-B[j]) / Double(i-j)
        if high > cur {
            cnt += 1
            high = cur
        }
    }
    high = INF
    for j in i+1..<N {
        let cur = Double(B[j]-B[i]) / Double(j-i)
        if high < cur {
            cnt += 1
            high = cur
        }
    }
    ans = max(ans, cnt)
}

print(ans)
