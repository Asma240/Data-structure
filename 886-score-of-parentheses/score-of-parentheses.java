class Solution {
    public int scoreOfParentheses(String s) {
          int score=0;
    Stack<Integer> stack = new Stack<>();
    stack.push(0);
    for(char c: s.toCharArray()){
        if(c=='('){
            stack.push(0);

        }else{
            int inside = stack.pop();
            if(inside==0){
            score=1;
            }else{
                score=2*inside;

            }

        int previous = stack.pop();
        stack.push(previous+score);
        }

    }
      return stack.pop();
    }
}