
let input = readLine()!.split(separator: " ").map{Int(String($0))!}
let N = input[0]
var (K, I) = (input[1], input[2])

for round in 1...100000 {
    if (K+1)/2 == (I+1)/2 {
        print(round)
        break
    }
    K = (K+1)/2
    I = (I+1)/2
}