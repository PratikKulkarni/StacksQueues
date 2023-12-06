class Problem1 {
    public int calPoints(String[] operations) {
        Stack<Integer> st=new Stack<Integer>();
        int n=operations.length;
        char ch;
        int val1,val2;
        for(int i=0;i<n;i++){
            ch=operations[i].charAt(0);
            //System.out.print(operations[i]+" ");
            if(ch=='-'){
                val1=Integer.parseInt(operations[i]);
                st.push(val1);
            }
            else if((ch-'+')==0){
                val1=st.peek();
                st.pop();
                val2=st.peek();
                st.push(val1);
                st.push(val1+val2);
            }
            else if((ch-'D')==0){
                val1=st.peek();
                st.push(val1*2);
            }
            else if(ch=='C'){
                st.pop();
            }
            else{
                val1=Integer.parseInt(operations[i]);
                st.push(val1);
            }
        }
        int sum=0;
        while(!st.empty()){
            sum+=st.peek();
            st.pop();
        }
        return sum;
    }
}