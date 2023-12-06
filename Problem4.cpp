class Problem4 {
public:

    int quick_select(vector<int>& v, int k , map<int, int> mp,int begin, int end){
        int pivot=rand()%(end-begin+1)+begin;
        int start,temp,x;
        start=begin;
        temp=v[end];
        v[end]=v[pivot];
        v[pivot]=temp;
        
        for(int i=begin;i<end;i++){
            
            if(mp[v[end]]>mp[v[i]]){
                temp=v[i];
                v[i]=v[start];
                v[start]=temp;
                start++;
            }
        }
        temp=v[start];
        v[start]=v[end];
        v[end]=temp;
        if((end-start+1)==k)
        return start;
        else if((end-start+1)<k){
            return quick_select(v,k-(end-start+1),mp,begin,start-1);
        }
        else{
            return quick_select(v,k,mp,start+1,end);
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            if((mp.find(nums[i])) == mp.end()){
                mp.insert({nums[i],1});
            }
            else{
                mp[nums[i]]++;
            }
        }
        vector<int> v;
        //vector<int> v_cnt;
        for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
            v.push_back(itr->first); 
        }
        int ind = quick_select(v,k,mp,0,v.size()-1);
        vector<int> v1;
        for(int i=ind;i<=(ind+k-1);i++)
        v1.push_back(v[i]);
        return v1;
    }
};