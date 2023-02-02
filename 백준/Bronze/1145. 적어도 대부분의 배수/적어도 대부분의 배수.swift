
let L = readLine()!.split(separator: " ").map{Int(String($0))!}

for i in 1... {
    if L.filter({i%$0 == 0}).count >= 3 {
        print(i)
        break
    }
}