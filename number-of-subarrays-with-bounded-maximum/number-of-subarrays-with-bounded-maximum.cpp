class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& ar, int lo, int hi) 
    {
        int head=0,tail=0,ans=0;
        int n=ar.size();

        // if ar[i] is between lo and hi -> head
        // if ar[i] is less than lo -> tail
        // if ar[i] is greater than hi -> breaker

        // if head comes then it makes all tails head and add heads to ans
        // if tail comes we can make subarray with heads so add heads in answer
        // if breaker comes make head and tail 0

        for(int i=0;i<n;i++)
        {
            if(ar[i]>=lo && ar[i]<=hi)
            {
                head+=tail+1;
                ans+=head;
                tail=0;
            }
            else if(ar[i]<lo)
            {
                ans+=head;
                tail++;
            }
            else
            {
                head=0;
                tail=0;
            }
        }

        return ans;
    }
};