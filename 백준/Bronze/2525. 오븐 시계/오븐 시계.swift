let str = readLine()!.split(separator: " ").map{Int(String($0))!}

var m = (str[1] + Int(readLine()!)!)
var h = (str[0] + m/60)%24

print(h, m%60)

