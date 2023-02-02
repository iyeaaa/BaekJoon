
let ip = readLine()!.split{$0==" "}.map{Int(String($0))!}
let (N, M) = (ip[0], ip[1])
let B = readLine()!.split{$0==" "}.map{Int(String($0))!}.sorted()
var ans = 0, mx = 0

for i in stride(from:0,to:N,by:M) {
    if B[i] > 0 { break }
    ans += -2*B[i]
    mx = max(mx, -B[i])
}

for i in stride(from:N-1,through:0,by:-M) {
    if B[i] < 0 { break }
    ans += 2*B[i]
    mx = max(mx, B[i])
}

print(ans - mx)