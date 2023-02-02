
import Foundation

let input = readLine()!.split{$0==" "}.map{Int(String($0))!}
let (vertical, width, height) = (input[0], input[1], input[2])
var C = [(A: Int, B: Int)]()
let N = Int(readLine()!)!

for _ in 0..<N {
    let input = readLine()!.split{$0==" "}.map{Int(String($0))!}
    C.append((Int(pow(2.0, Double(input[0]))), input[1]))
}
C.reverse()

print(f(vertical, width, height))

func f(_ v: Int,_ w: Int,_ h: Int) -> Int {
    if v == 0 || w == 0 || h == 0 {
        return 0
    }
    for i in 0..<N {
        let (len, cnt) = C[i]
        if cnt <= 0 { continue }
        if v < len || w < len || h < len { continue }
        C[i].B -= 1
        if len == v && len == w && len == h { return 1 }
        return f(v, w, h-len) + f(len, w-len, len) + f(v-len, w, len) + 1
    }
    print(-1)
    exit(0)
}