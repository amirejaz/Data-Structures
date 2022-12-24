#include<bits/stdc++.h>
using namespace std;

bool isOperand(char ele)
{
   return (ele >= 'a' && ele <= 'z') || (ele >= 'A' && ele <= 'Z');
          
}

string postfixToInfix(string postfix_exp){
    stack<string> sp;
    for(int i=0; postfix_exp[i] != '\0'; i++){
        if(isOperand(postfix_exp[i])){
            string op(1, postfix_exp[i]);
            sp.push(op);
        }
        else{
            string op1 = sp.top();
            sp.pop();
            string op2 = sp.top();
            sp.pop();
            sp.push("(" + op2 + postfix_exp[i] + op1 + ")" );
        }
    }
    return sp.top();
}

int main(){
    string postfix_exp = "ab+de/*";
    cout<<"The Infix expression is: "<<postfixToInfix(postfix_exp)<<endl;
    return 0;
}
