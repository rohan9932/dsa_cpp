#include<bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;

    int sum = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X')) {
            sum += m[s[i+1]] - 1;
            i++;
        } else if(s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')) {
            sum += m[s[i+1]] - 10;
            i++;
        } else if(s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')) {
            sum += m[s[i+1]] - 100;
            i++;
        } else {
            sum += m[s[i]];
        }
    }

    return sum;
}

int main() {
return 0;
}