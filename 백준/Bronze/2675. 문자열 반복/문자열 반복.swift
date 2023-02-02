var n = Int(readLine()!)!
var result = ""

for _ in 0..<n {
    let l: Array<String> = readLine()!.split{$0 == " "}.map{String($0)}
    let rec: Int = Int(l[0])!
    let str: String = l[1]

    for ch in str {
        for _ in 0..<rec {
            result += String(ch)
        }
    }

    result += "\n"
}

print(result)