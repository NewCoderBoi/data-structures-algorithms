#include<iostream>
#include<string>
#include<stack>

using namespace std;

int PriorityValue(char ch){
    if(ch == '^') return 3;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '+' || ch == '-') return 1;
}

bool HasHigherPrecedence(char c1, char c2){
    int pr1 = PriorityValue(c1);
    int pr2 = PriorityValue(c2);

    if(pr1>=pr2) return true;
    else return false;
}

int main(){
    // Logic - 

    // Observation - The order of operands in infix and postfix is always samw
    // We take the infix expression as string input, and traverse through it from left to right.
    // 1. If we get an operand - We append it to the resulting postfix expression. (Because observation)
    // 2. If we get an opening paranthesis - We push it to stack.
    // 3. If we get an operator -
    //    We check the top of the stack and append it to the resulting postfix expression till we either reach an operator with lower precedence, or we reach an opening paranthesis. We pop out the operators, but not the opening paranthesis. Then we push the operator we got into the stack.
    // 4. If we get a closing paranthesis -
    //    We append all operators on top of stack to res expression till we reach an opening paranthesis. We pop the opening paranthesis.
    // After infix expression is fully traversed, we append all operators in the stack to the res expression till stack is not empty.

    // Note - Error condition is not handled.

    string infix;
    cout<<"Enter infix expression"<<'\n';
    getline(cin, infix);

    string postfix = "";
    stack<char> temp;

    for(int i=0;i<infix.length();i++){
        if(infix[i]=='(') temp.push(infix[i]);
        else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='^'){
            while(!temp.empty()){
                if(temp.top()=='(') break;
                else if(HasHigherPrecedence(temp.top(),infix[i])){
                    postfix += temp.top();
                    temp.pop();
                }
                else if(!HasHigherPrecedence(temp.top(),infix[i])){
                    break;
                }
            }
            temp.push(infix[i]);
        }
        else if(infix[i]==')'){
            while(!temp.empty()){
                if(temp.top()=='('){
                    temp.pop();
                    break;
                }
                postfix += temp.top();
                temp.pop();
            }
        }
        else postfix += infix[i];
    }
    while(!temp.empty()){
        postfix += temp.top();
        temp.pop();
    }
    cout<<postfix<<'\n';

}