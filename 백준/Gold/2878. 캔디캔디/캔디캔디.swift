
let inp = readLine()!.split{$0==" "}.map{UInt64(String($0))!}
let (m, n) = (inp[0], inp[1])
var l = [UInt64](); for _ in 0..<n {l.append(UInt64(readLine()!)!) }
l.sort()
var rest: UInt64 = l.reduce(0, +) - m
var ans: UInt64 = 0

for i in 0..<n {
    let num: UInt64 = UInt64(min(l[Int(i)], rest/(n-i)))
    ans &+= (num * num)
    rest -= num
}

print(ans)

