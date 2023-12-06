class Problem10 {
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> dq;
        dq.push_back(0);
        for(int i=1;i<k;i++){
            if(dq.size()>0){
                while((!dq.empty()) && (nums[dq.back()]<nums[i]))
                dq.pop_back();
                dq.push_back(i);
            }
            else{
                dq.push_back(i);
            }
        }
        //cout << dq.front() << endl;
        vector<int> vect;
        vect.push_back(nums[dq.front()]);
        for(int i=k;i<n;i++){
            /*if(dq.front())
            if((dq.front()<=(i+k-1)) && (dq.front()>=i))
            cout << dq.front() << endl;*/
            while((!dq.empty()) && (nums[dq.back()]<nums[i])){
                dq.pop_back();
            }
            dq.push_back(i);
            if((dq.front()>=(i-k+1)) && (dq.front()<=i))
            vect.push_back(nums[dq.front()]);
            else{
                dq.pop_front();
                vect.push_back(nums[dq.front()]);
            } 
        }
        return vect;
        
    }
};