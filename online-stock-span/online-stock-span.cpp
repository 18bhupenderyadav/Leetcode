class StockSpanner {
public:
    stack<int>st;
    vector<int>ar;
    int curr;
    
    StockSpanner() {
        
        while(!st.empty()){
            st.pop();
        }
        
        ar.clear();
        curr = 0;
    }
    
    int next(int price) {
        
        ar.push_back(price);
        
        
        while(!st.empty() && ar[st.top()]<=price){
            st.pop();
        }
        
        
        
        int ans = 0;
        
        if(st.empty()){
            
            ans = curr+1;    
        }
        else{
            ans = curr - st.top();
        }
        
        st.push(curr); 
        curr++;
        return ans;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */