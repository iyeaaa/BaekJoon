
let input = readLine()!.split{$0==" "}.map{Int(String($0))!}
let (n, k) = (input[0], input[1])
var a = readLine()!.split{$0==" "}.map{Int(String($0))!}
var s = 0, ans = 0
var d = [0: 1]

a.forEach {
    s += $0
    ans += d[s-k, default: 0]
    d[s, default: 0] += 1
}

print(ans)