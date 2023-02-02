
var ans = ""

for _ in 0..<Int(readLine()!)! {
    func f() -> Bool {
        for value in l {
            s.remove(value)
            var strn = [Character]()
            for i in 0..<value.count {
                strn.append(value[i])
                if s.contains(strn) {
                    return false
                }
            }
            s.insert(value)
        }
        return true
    }

    let n = Int(readLine()!)!
    var s = Set<[Character]>()
    var l = [[Character]]()

    for _ in 0..<n {
        let strn = Array(readLine()!)
        l.append(strn)
        s.insert(strn)
    }

    ans += f() ? "YES\n" : "NO\n"
}

print(ans)