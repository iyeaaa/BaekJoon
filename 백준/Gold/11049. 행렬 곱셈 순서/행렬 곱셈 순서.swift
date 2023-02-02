
// f(s, e): 행렬 s부터 e까지 행렬을 곱하는데 필요한 곱셈 연산의 최솟값
// f(s, e) = min(f(s, m) + f(m+1, e) + (M[s].r * M[m].c * M[e].c)), m = [s, e)

let N = Int(readLine()!)!
var M = [(r: Int, c: Int)]()
var memo = [[Int]](repeating: [Int](repeating: 0, count: N), count: N)

for _ in 0..<N {
    let input = readLine()!.split{$0==" "}.map{Int(String($0))!}
    M.append((input[0], input[1]))
}

for len in 1..<N {
    for end in len..<N {
        let stt = end - len
        var temp = 98765431212345567
        for mid in stt..<end {
            let cnt = M[stt].r*M[mid].c*M[end].c
            temp = min(temp, memo[stt][mid] + memo[mid+1][end] + cnt)
        }
        memo[stt][end] = temp
    }
}

print(memo[0][N-1])