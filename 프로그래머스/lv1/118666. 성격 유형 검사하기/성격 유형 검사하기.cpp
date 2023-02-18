
#include <vector>
#include <iostream>

using namespace std;

int A[26];

string solution(vector<string> survey, vector<int> choices) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string answer = "";
    int n = survey.size();
    for (int i = 0; i < n; i++) {
        if (choices[i] <= 3) {
            A[survey[i][0]-65] += (4-choices[i]);
        } else if (choices[i] >= 5) {
            A[survey[i][1]-65] += (choices[i]-4);
        }
    }

    answer += A['R'-'A'] >= A['T'-'A'] ? 'R' : 'T';
    answer += A['C'-'A'] >= A['F'-'A'] ? 'C' : 'F';
    answer += A['J'-'A'] >= A['M'-'A'] ? 'J' : 'M';
    answer += A['A'-'A'] >= A['N'-'A'] ? 'A' : 'N';

    return answer;
}
