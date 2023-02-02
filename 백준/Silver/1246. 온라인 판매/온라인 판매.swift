
let input = readLine()!.split(separator: " ").map{Int(String($0))!}
let (N, M) = (input[0], input[1])
var P = [1000001]; for _ in 0..<M { P.append(Int(readLine()!)!) }
var ansPrice = 0, ansSum = 0
P.sort(by: >)

for i in 1...min(N, M) {
    let p = i*P[i]
    if ansSum < p {
        ansPrice = P[i]
        ansSum = p
    }
}

print(ansPrice, ansSum)