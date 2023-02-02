
let S = [Character("0")]+Array(readLine()!)
let lenS = S.count-1
let N = Int(readLine()!)!
var A = [String]()
var lenW = [Int]()
var memo = [Bool](repeating: false, count: lenS+1)

memo[0] = true

for i in 0..<N {
    A.append(readLine()!)
    lenW.append(A[i].count)
}

for i in 1...lenS {
    for (word, lenW) in zip(A, lenW) {
        if i < lenW { continue }
        if memo[i] { continue }
        if !memo[i-lenW] { continue }
        if String(S[i-lenW+1...i]) != word { continue }
        memo[i] = true
    }
}

print(memo[lenS] ? 1 : 0)