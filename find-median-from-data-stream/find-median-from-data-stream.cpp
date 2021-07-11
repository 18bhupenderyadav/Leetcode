class MedianFinder {
public:
    /** initialize your data structure here. */
    
    multiset<int> left,right;
    
    MedianFinder() 
    {
        left.clear();
        right.clear();
    }
    
    void addNum(int num) 
    {
        if(left.size()==0)
        {
            left.insert(num);
        }
        else
        {
            if(*left.rbegin()<num)
                right.insert(num);
            else
                left.insert(num);
        }
        
        if(left.size()>right.size()+1)
        {
            right.insert(*left.rbegin());
            left.erase((--left.end()));
        }
        if(right.size()>left.size()+1)
        {
            left.insert(*right.begin());
            right.erase(right.begin());
        }
    }
    
    double findMedian() 
    {
        if(left.size()>right.size())
            return *left.rbegin();
        else if(right.size()>left.size())
            return *right.begin();
        
        return (double)(*left.rbegin()+*right.begin())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */