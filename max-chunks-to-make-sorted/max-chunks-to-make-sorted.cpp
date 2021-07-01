class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
       int x=0;int count=0;
       for(int i=0;i<arr.size();i++)
       {
           x=max(x,arr[i]);
           if(x==i)
           {
               count++;
           }
       } 
        return count;
    }
};