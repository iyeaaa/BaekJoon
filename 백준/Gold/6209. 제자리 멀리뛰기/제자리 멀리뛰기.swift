
let ipt = readLine()!.split{$0==" "}.map{Int(String($0))!}
let (d, n, m) = (ipt[0], ipt[1], ipt[2])
var l = [Int](); for _ in 0..<n { l.append(Int(readLine()!)!) }
l.sort()

var (lf, ryt) = (0, d)
while lf <= ryt {
    let mid = (lf + ryt) >> 1
    if psb(mid) {
        lf = mid + 1
    } else {
        ryt = mid - 1
    }
}

print(ryt)

func psb(_ x: Int) -> Bool {
    var cur = 0
    var cnt = m
    for idx in 0..<l.count {
        if l[idx] - cur < x {
            if cnt <= 0 { return false }
            cnt -= 1
        } else {
            cur = l[idx]
        }
    }
    return d - cur >= x
}