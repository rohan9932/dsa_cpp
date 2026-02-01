#include<bits/stdc++.h>
using namespace std;

int priority(char ch) {
    if(ch == '^') return 3;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    else return -1; //lowest priority 
}

string infixToPostfix(string infixStr) {
    int i = 0;
    stack<char> s;
    string ans = "";

    while(i < infixStr.length()) {
        //operand => push to the ans
        if((infixStr[i] >= 'A' && infixStr[i] <= 'Z') ||
            (infixStr[i] >= 'a' && infixStr[i] <= 'z') ||
            (infixStr[i] >= '0' && infixStr[i] <= '9')) 
        {
            ans += infixStr[i];
        }
        //first bracket => push to stack
        else if(infixStr[i] == '(') s.push('(');
        //second bracket => pop elements till first braket and add to answer
        else if(infixStr[i] == ')') {
            while(!s.empty() && s.top() != '(') {
                ans += s.top();
                s.pop();
            }
            s.pop(); //pop the first bracket out of the stack
        }
        //operator => 2 cases 
        //1. if stack empty => first operator -> enter in the stack
        //2. if priority wise greater => enter in the stack
        //3. if priority wise lesser => pop every operator which are greater and add them to answer
        else {
            while(!s.empty() && priority(infixStr[i]) <= priority(s.top())) {
                ans += s.top();
                s.pop();
            }

            //condition 1 and 2 will be fulfilled automatically as stack won't enter while loop 
            //when stack is empty or priority wise it's lesser than stack top
            s.push(infixStr[i]);
        }
        i++;
    }

    //add the rest of the operators in stack to the ans
    while(!s.empty()) {
        ans += s.top();
        s.pop();
    }

    return ans;
}

int main() {
    string input = "a+b*(c^d-e)";
    cout << infixToPostfix(input) << "\n";

    return 0;
}