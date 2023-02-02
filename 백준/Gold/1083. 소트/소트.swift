
// t.c: O(N * (NlogN + N^2)) = O(N^3)
// s.c: O(N^2)

let N = Int(readLine()!)! // 배열 크기
var A = readLine()!.split{$0==" "}.map{Int(String($0))!} // 배열
var S = Int(readLine()!)! // 남은 교환 횟수

for i in 0..<N-1 { // 0부터 교환을 시작한다. N-1번째 인덱스는 고려할 필요없다.
    // 뒤에있는 요소들의 인덱스를 A가 큰 순서대로 정렬한다.
    let desc = Array(i+1..<N).sorted{A[$0] > A[$1]}
    // 제일 큰 요소부터 S보다 적게 swap할때만 고려한다.
    for j in desc where j - i <= S && A[j] > A[i] {
        A.insert(A[j], at: i) // j번째 숫자를 i번째에 넣는다.
        A.remove(at: j+1) // j+1번째 숫자를 삭제시킨다.
        S -= j - i // 남은 교환횟수를 차감시킨다.
        break // 더 고려할 필요 없으니 빠져나간다.
    }
}

print(A.map{String($0)}.joined(separator: " "))