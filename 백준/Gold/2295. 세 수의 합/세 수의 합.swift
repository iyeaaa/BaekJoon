
let n = Int(readLine()!)!
var s = Set<Int>()
var l = [Int](repeating: 0, count: n+1)
var ans = 0

for i in 1...n {
    l[i] = Int(readLine()!)!
}

for i in 1...n {
    for j in 1...n {
        s.insert(l[i] + l[j])
    }
}

for i in 1...n {
    for j in 1...i {
        if s.contains(l[i] - l[j]) {
            ans = max(ans, l[i])
        }
    }
}

print(ans)