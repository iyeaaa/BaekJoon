
let N = Int(readLine()!)!
let H = readLine()!.split{$0==" "}.map{Int(String($0))!}
var A = [Int](repeating: 0, count: 1_000_005)
var ans = 0

H.forEach {
    if A[$0] > 0 {
        A[$0]-=1; A[$0-1]+=1
    } else {
        ans+=1; A[$0-1]+=1
    }
}

print(ans)