import Foundation

func lowerBound(find: Int, numbers: [Int]) -> Int {
    var start = 0, end = numbers.count - 1
    var mid = (start + end) / 2

    while start < end {
        mid = (start + end) / 2
        if numbers[mid] < find {
            start = mid + 1
        } else {
            end = mid
        }
    }

    return end
}

let input = Int(readLine()!)!

var numbers: [Int] = readLine()!.split(separator: " ").map { Int(String($0))! }

var dp: [Int] = []
for number in numbers {
    if dp.isEmpty {
        dp.append(number)
        continue
    }

    if dp[dp.count - 1] < number {
        dp.append(number)
    } else {
        let index = lowerBound(find: number, numbers: dp)
        dp[index] = number
    }
}

print(dp.count)