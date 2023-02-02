
let N = Int(readLine()!)!
var ans = 0
var memo = [Int](repeating: 1, count: 41); memo[2] = 1

for i in 3...N {
    memo[i] = memo[i-1] + memo[i-2]
    ans += 1
}

print(memo[N], ans)