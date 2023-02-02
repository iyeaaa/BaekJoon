
let MOD = 1_000_000_000
let n = Int(readLine()!)!
var F = [Int: Int]()

F[0] = 0; F[1] = 1

for i in stride(from: 1, through: -1000000, by: -1) {
    F[i-2] = (F[i]! - F[i-1]!) % MOD
}

for i in 2...1_000_000 {
    F[i] = abs(F[i-1]! + F[i-2]!) % MOD
}

print(F[n]! < 0 ? -1 : F[n]! == 0 ? 0 : 1)
print(abs(F[n]!))