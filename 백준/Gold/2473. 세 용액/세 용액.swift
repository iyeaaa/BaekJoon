
let n = Int(readLine()!)!
let l = readLine()!.split{$0==" "}.map{Int(String($0))!}.sorted()
var md = Int.max
var ansElmt = [0, 0, 0]

for mid in 0..<n {
    var lf = mid+1, ryt = n-1
    while lf < ryt {
        let sum = l[lf] + l[ryt] + l[mid]
        if md > abs(sum) {
            md = abs(sum);
            ansElmt = [l[mid], l[lf], l[ryt]]
        }
        if sum < 0 {
            lf += 1
        } else {
            ryt -= 1
        }
    }
}

print(ansElmt.map{String($0)}.joined(separator: " "))