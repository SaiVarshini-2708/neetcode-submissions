class Solution {
public:
int operation(string ch,int a,int b){
    if(ch=="+") return a+b;
    else if(ch=="-") return a-b;
    else if(ch=="*") return a*b;
    else return a/b;
}
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                if(!st.empty()){
                    int b=st.top();
                    st.pop();
                    int a=st.top();
                    st.pop();
                    int x=operation(tokens[i],a,b);
                    st.push(x);
                }
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }

        return st.top();
        
    }
};
