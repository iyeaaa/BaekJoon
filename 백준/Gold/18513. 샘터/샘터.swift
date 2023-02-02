var input = readLine()!.split(separator: " ").map{Int(String($0))!}
let (n, k) = (input[0], input[1])
let local = readLine()!.split(separator: " ").map{Int(String($0))!}

var queue = local
var index = 0
var visit = [Int:Int]()
var count = 0
for l in local { visit[l] = 0 }

f: while index < queue.count {
    let cur = queue[index]
    for i in [-1, 1] {
        let next = cur + i
        if visit[next] == nil {
            queue.append(next)
            visit[next] = visit[cur]! + 1
            count += 1
            if count == k {
                print(visit.values.reduce(0) {$0 + $1})
                break f
            }
        }
    }
    index += 1
}