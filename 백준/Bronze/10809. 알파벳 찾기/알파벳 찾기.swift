let S = readLine()!
var arr = [Int](repeating: -1, count: 26)
var count = 0
var result = ""

for ch in S {
    let index = Int(ch.asciiValue!-97)
    if arr[index] == -1 {
        arr[index] = count
    }
    count += 1
}

for i in arr {
    result.append(String(i) + " ")
}

print(result)

