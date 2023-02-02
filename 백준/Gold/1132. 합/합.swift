
extension Character {
    var int: Int { Int(unicodeScalars.first!.value) - 65 }
}

let N = Int(readLine()!)!
var l = [Int](repeating: 0, count: 10)
var zero = [Bool](repeating: false, count: 10)
var zeroalpha = 0, ans = 0

for _ in 0..<N {
    var i = 1
    let S: [Character] = Array(readLine()!).reversed()
    for v in S {
        l[v.int] += i
        i *= 10
    }
    zero[S.last!.int] = true
}

l[l.enumerated().filter{!zero[$0.0]}.min{$0.1<$1.1}!.0] = 0
l.sort(by:>)

for i in 0..<9 {
    ans += (9-i)*l[i]
}

print(ans)
