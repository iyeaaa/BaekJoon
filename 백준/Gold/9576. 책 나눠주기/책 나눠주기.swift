
let T = Int(readLine()!)!
var result = ""

for _ in 0..<T {
    let input = readLine()!.split{$0==" "}.map{Int(String($0))!}
    let (N, M) = (input[0], input[1])
    var L = [(Int, Int)]()
    var B = [Bool](repeating: false, count: N+1)
    var cnt = 0

    for _ in 0..<M {
        let input = readLine()!.split{$0==" "}.map{Int(String($0))!}
        L.append((input[0], input[1]))
    }

    L.sort{$0.1 != $1.1 ? $0.1 < $1.1 : $0.0 < $1.0}

    for (s, e) in L {
        for i in s...e where !B[i] {
            B[i] = true
            cnt += 1
            break
        }
    }

    result += "\(cnt)\n"
}

print(result)