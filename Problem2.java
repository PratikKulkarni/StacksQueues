class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> st=new Stack<Integer>();
        int n=tokens.length;
        int val1,val2;
        for(int i=0;i<n;i++){
            if(tokens[i].charAt(0)=='-'){
                if(tokens[i].length()>1){
                    val1=Integer.parseInt(tokens[i]);
                    st.push(val1);
                }else{
                    val1=st.peek();
                    st.pop();
                    val2=st.peek();
                    st.pop();
                    st.push(val2-val1);
                }
                
            }else if(tokens[i].charAt(0)=='+'){
                val1=st.peek();
                st.pop();
                val2=st.peek();
                st.pop();
                st.push(val2+val1);

            }else if(tokens[i].charAt(0)=='*'){
                val1=st.peek();
                st.pop();
                val2=st.peek();
                st.pop();
                st.push(val2*val1);

            }else if(tokens[i].charAt(0)=='/'){
                val1=st.peek();
                st.pop();
                val2=st.peek();
                st.pop();
                st.push(val2/val1);

            }else{
                st.push(Integer.parseInt(tokens[i]));
            }
        }
        return st.peek();
    }
}