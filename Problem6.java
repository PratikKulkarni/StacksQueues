class Problem6 {
    Queue<Integer> queue;
 
    public RecentCounter() {
        queue= new LinkedList<Integer>();
    }
    
    public int ping(int t) {
        queue.add(t);
        if(queue.size()>1){
            while((queue.size()>1) && (queue.peek()<(t-3000))){
                queue.poll();
            }
        }
        return queue.size();
    }
}
