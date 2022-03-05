#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
    // Logic - We will initialize a stack and traverse through string from left to right. When we get an opening paranthesis, we will push it to the stack. When we encounter a closing paranthesis, we will check the top element of the stack. If it is the corresponding opening paranthesis, then we continue traversing, else we say expression is unbalanced. At end of traversal, if stack is empty expression is balanced, else unbalanced.

    string str;
    cout<<"Enter expression"<<'\n';
    getline(cin, str);
    stack<char> checker;
    bool checked = false;
    for(int i=0;i<str.length();i++){
        if(str[i]=='(' || str[i]=='{' || str[i]== '['){
            checker.push(str[i]);
        }
        else if(str[i]==')'){
            if(checker.empty() || checker.top() != '('){
                cout<<"Unbalanced"<<'\n';
                checked = true;
                break;
            }
            else checker.pop();
        }
        else if(str[i]=='}'){
            if(checker.empty() || checker.top() != '{'){
                cout<<"Unbalanced"<<'\n';
                checked = true;
                break;
            }
            else checker.pop();
        }
        else if(str[i]==']'){
            if(checker.empty() || checker.top() != '['){
                cout<<"Unbalanced"<<'\n';
                checked = true;
                break;
            }
            else checker.pop();
        }
    }
    if(!checked){
        if(checker.empty()) cout<<"Balanced"<<'\n';
        else cout<<"Unbalanced"<<'\n';
    }
}