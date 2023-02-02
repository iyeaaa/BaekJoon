
var ans = ""
let N = Int(readLine()!)!

for i in 1...N {
    let input = readLine()!.split{$0==" "}.map{["0"]+Array($0).map{String($0)}}
    let one = input[0], two = input[1], three = input[2]
    let n1 = one.count-1, n2 = two.count-1, n3 = three.count-1
    var memo = (0...n3).map{_ in (0...n1).map{_ in false}}

    memo[0][0] = true

    for idx in 1...n3 {
        for i in 0...idx {
            let j = idx - i
            if i > n1 || j > n2 { continue }
            if i == 0 {
                memo[idx][i] = memo[idx-1][i] && two[j] == three[idx]
            } else if j == 0 {
                memo[idx][i] = memo[idx-1][i-1] && one[i] == three[idx]
            } else {
                memo[idx][i] = memo[idx-1][i-1] && one[i] == three[idx]
                        || memo[idx-1][i] && two[j] == three[idx]
            }
        }
    }

    ans += "Data set \(i): " + (memo[n3][n1] ? "yes\n" : "no\n")
}

print(ans)