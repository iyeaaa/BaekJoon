
let N = Int(readLine()!)!
let L = readLine()!.split(separator: " ").map{Int(String($0))!}
var memo = [Int](repeating: 1, count: N)

for i in 0..<N {
    for j in 0..<i where L[j] > L[i] {
        memo[i] = max(memo[i], memo[j] + 1)
    }
}

print(N - memo.max()!)