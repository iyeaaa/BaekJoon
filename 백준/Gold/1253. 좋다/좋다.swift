

let n = Int(readLine()!)!
var c = [Int: Int]()
var a = readLine()!.split{$0==" "}.map{Int(String($0))!}
var ans = 0

for i in 0..<n {
    for j in i+1..<n {
        c[a[i]+a[j], default: 0] += 1
    }
}

for i in 0..<n {
    for j in 0..<n where i != j {
        c[a[i]+a[j], default: 0] -= 1
    }
    ans += c[a[i], default: -1] > 0 ? 1 : 0
    for j in 0..<n where i != j {
        c[a[i]+a[j], default: 0] += 1
    }
}

print(ans)