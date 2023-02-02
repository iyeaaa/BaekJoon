
for _ in 0..<Int(readLine()!)! {
    let _ = Int(readLine()!)!
    let C = readLine()!.split{$0==" "}.map{Int(String($0))!}
    let M = Int(readLine()!)!
    var memo = (0...M).map{_ in 0}
    memo[0] = 1

    for c in C {
        for i in stride(from: c, through: M, by: 1) {
            memo[i] += memo[i-c]
        }
    }

    print(memo[M])
}