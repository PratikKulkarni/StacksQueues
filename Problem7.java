class Problem7 {
    public int[] dailyTemperatures(int[] temperatures) {
        Stack<Integer> st=new Stack<Integer>();
        int n=temperatures.length;
        int[] answer=new int[n];
        for(int i=0;i<n;i++){
            while((!st.empty()) && (temperatures[st.peek()]<temperatures[i])){
                answer[st.peek()]=i-st.peek();
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            answer[st.peek()]=0;
            st.pop();
        }
        return answer;
    }
}