#include<iostream>
#include<stack>
using namespace std;
    //Write a program to convert an Infix expression into a Postfix expression
int prec(char op){
        if(op == '+' || op == '-'){
            return 1;
        }
        if(op == '/' || op == '*'){
            return 2;
        }
        if(op == '^'){
            return 3;
        }
        else 
            return -1;
    }
    string in_to_post(string s){
        stack<char> st;
        string res;

        for(int i=0; i < s.length(); i++){
            char c = s[i];
            if((c >='a' && c<='z') || (c>='A'&& c<='Z') || (c >='0' && c <= '9')){
                res = res + c;
            }
            else if (c ==')'){
                st.push(')');
            }
            else if (c == ')') {
            while (st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop(); 
        }
            else {
            while (!st.empty() && prec(c) <= prec(st.top())) {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }

        }

    return res;    
    }
int main(){
    string exp ="(a+b)*c";
    cout << "Infix:" <<" " << exp << endl;
    cout << "Postfix:" <<" " << in_to_post(exp) << endl;
}
