var N = Int(readLine()!)!
let L = readLine()!.split{$0==" "}.map{Int(String($0))!}
var memo = [Int](repeating: 1, count: 1001)
var path = [Int](repeating: -1, count: 1001)
var stack = [Int]()

for i in 0..<N {
    for j in 0..<i where L[j] < L[i] && memo[j]+1 > memo[i] {
        memo[i] = memo[j] + 1
        path[i] = j
    }
}

var 정답인덱스 = memo.indices.max{memo[$0] < memo[$1]}!
print(memo[정답인덱스])

while 정답인덱스 != -1 {
    stack.append(L[정답인덱스])
    정답인덱스 = path[정답인덱스]
}

print(stack.reversed().map{String($0)}.joined(separator: " "))