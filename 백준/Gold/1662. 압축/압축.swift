
let S = Array(readLine()!)
var b = [[(s: Int, e: Int)]]()
var prev = 0
var ans = 0

print(f(0, S.count-1))

func f(_ s: Int, _ e: Int) -> Int {
    if s - 1 == e {
        return 0
    }
    let braket = findBraket(s, e)
    var rtn = 0
    var end = s

    if braket.isEmpty {
        return e - s + 1
    }

    for (bs, be) in braket {
        rtn += (bs - end - 1) + Int(String(S[bs-1]))!*f(bs+1, be-1)
        end = be + 1
    }
    return rtn + (e - end + 1)
}

func findBraket(_ s: Int, _ e: Int) -> [(Int, Int)] {
    var stack = [Int]()
    var rtn = [(Int, Int)]()
    for i in stride(from: s, through: e, by: 1) {
        if S[i] == "(" {
            stack.append(i)
            continue
        }
        if S[i] == ")" {
            let temp = stack.popLast()!
            if stack.isEmpty {
                rtn.append((temp, i))
            }
        }
    }
    return rtn
}



