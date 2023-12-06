class Problem5 {
    public int firstUniqChar(String s) {
        int n=s.length();
        int[] a=new int[26];
        for(int i=0;i<n;i++){
            a[s.charAt(i)-'a']++;
        }
        int ind=-1;
        for(int i=0;i<n;i++){
            if(a[s.charAt(i)-'a']==1){
                ind=i;
                break;
            }
        }
        return ind;
    }
}