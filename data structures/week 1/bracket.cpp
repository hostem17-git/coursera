#include<bits/stdc++.h>
using namespace std;

bool isbracket(char s);

int check(string s)
{
    stack<char> st;
    stack<int> pos_st;
    int pos=0;
    bool found=false;
    while(s[pos] && !found){
       
        if(isbracket(s[pos])){
           
            if(s[pos]=='[' || s[pos]=='{' || s[pos]=='('){
                st.push(s[pos]);
                pos_st.push(pos+1);
            }
            else{
                if(s[pos]==']'){
                    if(st.empty() || st.top()!='[')
                        return pos_st.top();
                    else{
                        st.pop();
                        pos_st.pop();
                    }
                }
                else if(s[pos]=='}'){
                    if(st.empty() || st.top()!='{'){
                        return pos_st.top();
                        
                    }
                    else{
                        st.pop();
                        pos_st.pop();
                    }
                }else{
                    if(st.empty() || st.top()!='(')
                        return pos_st.top();
                    else{
                        st.pop();
                        pos_st.pop();
                    }
                }
            }
        }
        pos++;
    }
    if(st.empty())
        return -1;
    else
        return pos_st.top();
}
bool isbracket(char s){
    return  (  s=='[' || s== ']' || s=='{' || s=='}' || s=='(' || s==')' );
}

int main(){
    string s;
    cin>> s;
    int t=check(s);
    if(t==-1)
        cout<<"Success\n";
    else    
        cout<<t<<endl;
   
}