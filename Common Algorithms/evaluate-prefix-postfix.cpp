#include<iostream>
#include<string>
#include<stack>
using namespace std;

int PostfixEval(int op1, int op2, char operation){
    if(operation == '+') return op2+op1;
    if(operation == '-') return op2-op1;
    if(operation == '*') return op2*op1;
    if(operation == '/') return op2/op1;
    if(operation == '^') return op2^op1;
}

int PrefixEval(int op1, int op2, char operation){
    if(operation == '+') return op2+op1;
    if(operation == '-') return op2-op1;
    if(operation == '*') return op2*op1;
    if(operation == '/') return op2/op1;
    if(operation == '^') return op2^op1;
}

int main(){
    // 1. Postfix evaluation

    // Logic - We traverse through the postfix expression left to right. When we get operand, we push it to stack. When we get operator, we perform that particular operation on the two topmost elements of the stack, and pop both of them and push the result to the stack. At end, only one element will remain in stack, which will be the solution.

    // string postfix;
    // cout<<"Enter postfix expression"<<'\n';
    // getline(cin, postfix);

    // stack<int> temp;

    // for(int i=0;i<postfix.length();i++){
    //     if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/' || postfix[i]=='^'){
    //         int op1 = temp.top();
    //         temp.pop();
    //         int op2 = temp.top();
    //         temp.pop();
    //         int result = PostfixEval(op1, op2, postfix[i]);
    //         temp.push(result);
    //     }
    //     else{
    //         int operand = postfix[i] - '0';
    //         temp.push(operand);
    //     }
    // }
    // cout<<temp.top()<<'\n';

    // 2. Prefix evaluation

    // Logic - Same as postfix, just expression will be traversed from right to left.

    string prefix;
    cout<<"Enter prefix expression"<<'\n';
    getline(cin, prefix);

    stack<int> temp;

    for(int i=prefix.length()-1;i>=0;i--){
        if(prefix[i]=='+' || prefix[i]=='-' || prefix[i]=='*' || prefix[i]=='/' || prefix[i]=='^'){
            int op1 = temp.top();
            temp.pop();
            int op2 = temp.top();
            temp.pop();
            int result = PrefixEval(op1, op2, prefix[i]);
            temp.push(result);
        }
        else{
            int operand = prefix[i] - '0';
            temp.push(operand);
        }
    }
    cout<<temp.top()<<'\n';
}