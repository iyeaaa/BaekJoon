
let MOD = 10007
let N = Int(readLine()!)!
var memo = (0...1001).map{_ in 0}; memo[0]=1

for _ in 0...9 {
    for j in 1...N {
        memo[j] = (memo[j] + memo[j-1]) % MOD
    }
}

print(memo[N]%MOD)