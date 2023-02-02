

var lfStack = Array(readLine()!)
var rytStack = [Character]()
let M = Int(readLine()!)!

for _ in 0..<M {
    let cmd = readLine()!
    switch cmd {
    case "L":
        if !lfStack.isEmpty {
            rytStack.append(lfStack.removeLast())
        }
    case "D":
        if !rytStack.isEmpty {
            lfStack.append(rytStack.removeLast())
        }
    case "B":
        if !lfStack.isEmpty {
            lfStack.removeLast()
        }
    default:
        lfStack.append(cmd.last!)
    }
}

print(String(lfStack + rytStack.reversed()))