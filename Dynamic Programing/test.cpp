#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

vector<int> getPossibleDigits(map<int, string>& validDigits, const string& fd) {
    vector<int> potd;

    for (const auto& entry : validDigits) {
        int mismatches = 0;
        const string& pattern = entry.second;
        for (size_t i = 0; i < fd.length(); ++i) {
            if (fd[i] != pattern[i]) {
                mismatches++;
            }
        }

        if (mismatches <= 1) {
            potd.push_back(entry.first);
        }
    }

    return potd;
}

void gch(const vector<vector<int>>& possibleNumbers, int index, vector<int>& curcom, vector<vector<int>>& result) {
    if (index == possibleNumbers.size()) {
        result.push_back(curcom);
        return;
    }

    for (int digit : possibleNumbers[index]) {
        curcom.push_back(digit);
        gch(possibleNumbers, index + 1, curcom, result);
        curcom.pop_back();
    }
}

vector<vector<int>> getCombinations(const vector<vector<int>>& possibleNumbers) {
    vector<vector<int>> result;
    vector<int> curcom;
    gch(possibleNumbers, 0, curcom, result);
    return result;
}

void solve() {
    vector<string> segd(3);
    for (int i = 0; i < 3; ++i) {
        getline(cin, segd[i]);
        segd[i] = segd[i];
    }

    vector<string> placementlelo(3);
    for (int i = 0; i < 3; ++i) {
        getline(cin, placementlelo[i]);
        placementlelo[i] = placementlelo[i];
    }

    map<int, string> digp;
    for (int digit = 0; digit < 10; ++digit) {
        string pattern;
        for (int row = 0; row < 3; ++row) {
            pattern += segd[row].substr(digit * 3, 3);
        }
        digp[digit] = pattern;
    }

    vector<vector<int>> possibleNumbers;
    int len = placementlelo[0].length() / 3;
    for (int i = 0; i < len; ++i) {
        string fd;
        for (int row = 0; row < 3; ++row) {
            fd += placementlelo[row].substr(i * 3, 3);
        }

        vector<int> matchingDigits = getPossibleDigits(digp, fd);
        if (matchingDigits.empty()) {
            cout << "Invalid";
            return;
        }
        possibleNumbers.push_back(matchingDigits);
    }

    int totalSum = 0;
    vector<vector<int>> combinations = getCombinations(possibleNumbers);
    for (const auto& combination : combinations) {
        string number;
        for (int digit : combination) {
            number += to_string(digit);
        }
        totalSum += stoi(number);
    }

    cout << totalSum;
}

int main() {
    solve();
    return 0;
}
