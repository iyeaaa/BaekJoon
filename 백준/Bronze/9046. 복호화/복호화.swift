let n = Int(readLine()!)!
for _ in 0..<n {
    let input = readLine()!
    var dict = [Character: Int]()
    for char in input {
        if char.isLetter {
            dict[char, default: 0] += 1
        }
    }
    let max = dict.values.max()
    let answer = Array(dict.filter({ $0.value == max }))
    if answer.count > 1 {
        print("?")
    } else {
        print(answer[0].key)
    }
}