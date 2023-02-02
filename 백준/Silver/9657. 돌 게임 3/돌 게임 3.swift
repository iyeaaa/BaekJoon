
let N = Int(readLine()!)!
var S_win = [Bool](repeating: false, count: 1001)

S_win[1] = true; S_win[3] = true; S_win[4] = true; S_win[5] = true

for i in stride(from: 6, through: N, by: 1) {
    for j in [1, 3, 4] where !S_win[i-j] {
        S_win[i] = true
    }
}

print(S_win[N] ? "SK" : "CY")