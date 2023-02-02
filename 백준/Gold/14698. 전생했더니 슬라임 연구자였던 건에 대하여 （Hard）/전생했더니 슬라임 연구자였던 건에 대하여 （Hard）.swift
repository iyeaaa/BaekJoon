
let MOD = 1_000_000_007
for _ in 0..<Int(readLine()!)! {
    let _ = Int(readLine()!)!
    var heap = [Int]()
    var ans = 1

    readLine()!.split{$0==" "}.forEach {
        heap.append(Int(String($0))!)
    }

    while heap.count > 1 {
        heap.sort(by:>)
        let x = heap.popLast()!, y = heap.popLast()!
        ans = (ans * ((x * y) % MOD)) % MOD
        heap.append(x * y)
    }

    print(ans)
}