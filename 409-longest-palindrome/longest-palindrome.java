class Solution {
    public int longestPalindrome(String s) {
        
        int n = s.length();

        int [] freq = new int[128];
  
    // freq count

        for(char ch : s.toCharArray()){
            freq[ch]++;
        }

   int ans = 0;

   boolean oddfound = false;
      
       // check every character freq

       for(int f : freq){
         
         if( f%2 == 0){
            ans +=f;
         }

         else{
             ans += f-1;
             oddfound = true;
         }
       }

       // one odd char will come in center

       if(oddfound){
        ans++;
       }

       return ans;

    }
}