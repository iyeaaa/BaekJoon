
// f(n): n번째 글자를 새로운 줄에 썼을 때, 남게되는 칸의 제곱의 합

let input = readLine()!.split{$0==" "}.map{Int(String($0))!}
let (n, m) = (input[0], input[1])
var W = [Int](); for _ in 0..<n {W.append(Int(readLine()!)!)}
var memo = [Int](repeating: 0, count: n+1)

for i in stride(from: n-2, through: 0, by: -1) {
    var j = i+1
    var space = m - W[i]
    var temp = space * space + memo[i+1]
    while j < n && space - 1 >= W[j] {
        if j == n-1 {
            temp = 0
            break
        }
        space -= W[j] + 1
        temp = min(temp, space*space + memo[j+1])
        j += 1
    }
    memo[i] = temp
}

print(memo[0])