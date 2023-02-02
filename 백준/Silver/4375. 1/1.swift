
while let n = readLine() {
    let n = Int(n)!
    var one = 1
    var cnt = 1
    while one % n != 0 {
        one = (one*10 + 1) % n
        cnt += 1
    }
    print(cnt)
}