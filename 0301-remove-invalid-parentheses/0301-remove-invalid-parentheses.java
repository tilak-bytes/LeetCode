class Solution {
    public boolean valid(String s){
        int x = 0;
        int i = 0;
        while(i < s.length()){
            if(s.charAt(i) == '('){
                x++;
            }else if(s.charAt(i) == ')'){
                if(x > 0){
                    x--;
                }else{
                    return false;
                }
            }
            i++;
        } 
        return x == 0 ? true : false;       
    }
    // public void helper(String s, int i, int x, String a, List<String> ans){
    //     if(i >= s.length()){
    //         ans.add(a);
    //     }
    //     if(s)
    // }
    public void helper(String s, int i, String a, List<String> ans){
        if(i >= s.length()){
            if(valid(a)){
                ans.add(a);
            }
            return;
        }
        if(s.charAt(i) == '(' || s.charAt(i) == ')'){
        helper(s, i+1, a, ans);
        helper(s, i+1, a+s.charAt(i), ans);
        }else{
            helper(s, i+1, a+s.charAt(i), ans);
        }
    }
    
    public List<String> removeInvalidParentheses(String s) {
        Stack<Character> sb = new Stack<>();
        
        // for(char c : s.toCharArray()){
            
        // }
        List<String> ans = new ArrayList<>();
        helper(s, 0, "", ans);
        Set<String> x = new HashSet<>();
        int max = 0;
        for(String st : ans){
            max = Math.max(st.length(), max);
        }
        for(String st : ans){
            if(st.length() == max){
                x.add(st);
            }
        }
        List<String> xx = new ArrayList<>();
        for(String str : x){
            xx.add(str);
        }
        return xx;
    }
}