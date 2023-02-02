var n = Int(readLine()!)!
var arr = readLine()!.split{$0 == " "}.map{Int(String($0))!}
print(arr.min()!, arr.max()!)