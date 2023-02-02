
let N = Int(readLine()!)!
var w = [(t: Int, s: Int)]()
var last_time = Int.max

for _ in 0..<N {
    let input = readLine()!.split{$0==" "}.map{Int(String($0))!}
    w.append((input[0], input[1]))
}
w.sort{$0.s > $1.s}

for (t, s) in w {
    if last_time >= s {
        last_time = s - t
    } else {
        last_time -= t
    }
}

print(last_time < 0 ? -1 : last_time)