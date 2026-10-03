class MinStack {
public:
stack<long long>st;
long long minele;
    MinStack() {
        
    }
    
    void push(int val) {
       if(st.empty()){
        st.push(val);
        minele=val;
       } 
       else if(minele<=val){
        st.push(val);
       }
       else{
        st.push(2LL*val-minele);
        minele=val;
       }
    }
    
    void pop() {
       if(minele<=st.top()){
        st.pop();
       }
       else if(minele>st.top()){
        minele=2LL*minele-st.top();
        st.pop();
        
       }
        
    }
    
    int top() {
        if(minele<=st.top()){
            return st.top();
        }
        return minele;
    }
    
    int getMin() {
        
        return minele;
    }
};
