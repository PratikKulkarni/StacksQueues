class Problem9 {
    priority_queue<int> maxq;
    priority_queue<int,vector<int>,greater<int>> minq;
public:
    
    MedianFinder() {
        maxq.push(1);
        maxq.pop();
        minq.push(2);
        minq.pop();
    }
    
    void addNum(int num) {
        int x,y;
        y=maxq.size();
        
        if(maxq.size()==minq.size()){
            
            if((num==maxq.top()) || ((num>maxq.top()) && (num<=minq.top())))
                maxq.push(num);
            else if(num<maxq.top())
                maxq.push(num);
            else{
                minq.push(num);
                cout << "Hello1" << endl;
                x=minq.top();
                cout << "Hello2" << endl;
                minq.pop();
                cout << "Hello3" << endl;
                maxq.push(x);
                cout << "Hello4" << endl;
            }
        
        }
        else{
            if((num<=minq.top()) && (num>=maxq.top())){
                minq.push(num);
            }
            else if(num<maxq.top()){
                maxq.push(num);
                cout << "Hello1" << endl;
                x=maxq.top();
                cout << "Hello2" << endl;
                maxq.pop();
                cout << "Hello3" << endl;
                minq.push(x);
                cout << "Hello4" << endl;
            }
            else{
                minq.push(num);
            }
        }
    }
    
    double findMedian() {
        double val1,val2;
        double median;
        if(minq.size()==maxq.size()){
            val1=minq.top();
            val2=maxq.top();
            median=((val1+val2)/2);
        }
        else{
            median=maxq.top();
        }
        return median;
    }
};
