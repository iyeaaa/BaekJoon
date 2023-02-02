
let input = readLine()!.split{$0==" "}.map{Int(String($0))!}
var (n, m) = (input[0], input[1])
var dp = (0...n).map{_ in (0...m).map{_ in 0}}
var man = [0]+readLine()!.split{$0==" "}.map{Int(String($0))!}.sorted()
var woman = [0]+readLine()!.split{$0==" "}.map{Int(String($0))!}.sorted()

for i in 1...n {
    for j in 1...m {
        dp[i][j] = dp[i-1][j-1] + abs(man[i]-woman[j])
        if (i > j) {
            dp[i][j] = min(dp[i][j], dp[i-1][j])
        }
        if (i < j) {
            dp[i][j] = min(dp[i][j], dp[i][j-1])
        }
    }
}

print(dp[n][m])