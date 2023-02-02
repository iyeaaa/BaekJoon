
import Foundation

let N = Int(readLine()!)!
let a = readLine()!.split(separator: " ").map{Int(String($0))!}.sorted(by: >)
var space = a[0]-1
var sum = a.reduce(0, +) - a[0]

if N == 1 { print(1); exit(0) }

print(space > sum ? sum + a[0] - space + sum : sum+a[0])
