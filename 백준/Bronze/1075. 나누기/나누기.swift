
import Foundation

var N = Int(readLine()!)! / 100 * 100
let F = Int(readLine()!)!

while N % F != 0 {
    N += 1
}

N %= 100
print(N <= 9 ? "0\(N)" : N)