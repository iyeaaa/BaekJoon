
import Foundation

let input = readLine()!.split{$0==" "}.map{Int(String($0))!}
let (N, L, I) = (input[0], input[1], input[2])
var memo = (0...N).map{_ in (0...N).map{_ in 1}}

for i in 1...N {
    for j in 1..<i {
        memo[i][j] = memo[i-1][j] + memo[i-1][j-1]
    }
}

print(f(N, L, I, ""))

func f(_ len: Int, _ limit: Int, _ idx: Int, _ cur: String) -> String {
    if len == 1 {
        return cur + (idx == 1 ? "0" : "1")
    }
    if limit == 0 {
        return cur + String(repeating: "0", count: len)
    }

    var first_Zero_Cnt = 0
    for i in 0...min(len-1, limit) {
        first_Zero_Cnt += memo[len-1][i]
    }
    if first_Zero_Cnt >= idx {
        return f(len-1, limit, idx, cur + "0")
    } else {
        return f(len-1, limit-1, idx-first_Zero_Cnt, cur + "1")
    }
}