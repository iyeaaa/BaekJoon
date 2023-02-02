
var f = [Int](repeating: 1, count: 117)

for i in 4...116 {
    f[i] = f[i-1] + f[i-3]
}

print(f[Int(readLine()!)!])