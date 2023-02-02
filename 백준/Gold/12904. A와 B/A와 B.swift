
let S = Array(readLine()!), n = S.count
var T = Array(readLine()!), m = T.count

for i in 0..<m-n {
    if T.last! == "A" {
        T.removeLast()
    } else {
        T.removeLast()
        T.reverse()
    }
}

print(S==T ? 1 : 0)