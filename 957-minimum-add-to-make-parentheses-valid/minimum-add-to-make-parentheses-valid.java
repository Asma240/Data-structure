class Solution {
    public int minAddToMakeValid(String s) {
        Deque<Character> stk = new ArrayDeque<>();
        int left =0;

        for(char ch: s.toCharArray()){
            if(ch =='('){
                stk.push(ch);
            }else if(!stk.isEmpty()){
                stk.pop();
            }else{
                left++;
            }
        }
        return left + stk.size();
        
    }
}