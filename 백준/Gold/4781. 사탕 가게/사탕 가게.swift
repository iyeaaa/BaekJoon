
var ans = ""
while true {
    let input = readLine()!.split{$0==" "}.map{String($0)}
    let (n, m) = (Int(input[0])!, Int(Double(input[1])!*100+0.5))
    var memo = [Int](repeating: 0, count: m+1)

    if n == 0 && m == 0 { break }

    for _ in 1...n {
        let input = readLine()!.split{$0==" "}.map{String($0)}
        let (calorie, cost) = (Int(input[0])!, Int(Double(input[1])!*100+0.5))
        for i in cost...m {
            memo[i] = max(memo[i], memo[i-cost] + calorie)
        }
    }

    ans += "\(memo[m])\n"
} 

print(ans)