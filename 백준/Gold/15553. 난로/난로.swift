
let input = readLine()!.split{$0==" "}.map{Int(String($0))!}
let (n, m) = (input[0], input[1])
var l = [Int](); for _ in 0..<n {l.append(Int(readLine()!)!)}
var diff = [Int]();
var entire = l.last! + 1 - l.first!

for i in 1..<n {
    diff.append(l[i] - (l[i-1] + 1))
}
diff.sort(by: >)

for i in 0..<min(n-1, m-1) {
    entire -= diff[i]
}

print(entire)