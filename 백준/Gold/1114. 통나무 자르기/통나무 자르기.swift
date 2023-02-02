
let input = readLine()!.split{$0==" "}.map{Int(String($0))!}
let (l, k, c) = (input[0], input[1], input[2])
var p = [0]+readLine()!.split{$0==" "}.map{Int(String($0))!}.sorted()+[l]

var (lf, ryt) = (0, l)
var first_cut = 0
while lf <= ryt {
    let mid = (lf + ryt) >> 1
    let (ispsb, first) = psb(mid)
    if ispsb {
        ryt = mid - 1
        first_cut = first
    } else {
        lf = mid + 1
    }
}

print(lf, first_cut)

func psb(_ x: Int) -> (Bool, Int) {
    var cur = l // 통나무가 시작되는 위치. 잘린것 고려.
    var cnt = c
    var idx = p.count-1
    var lastIdx = p.last!
    while idx >= 0 {
        if cur - p[idx] > x {
            if cnt <= 0 || p[idx+1] == cur {
                return (false, 0)
            } else {
                cnt -= 1
                cur = p[idx+1]
                lastIdx = p[idx+1]
            }
        } else {
            idx -= 1
        }
    }
    if cnt > 0 {
        lastIdx = p[1]
    }
    return (true, lastIdx)
}

