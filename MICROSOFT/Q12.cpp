/*
    Q 1392. Longest Happy Prefix (https://leetcode.com/problems/longest-happy-prefix/description/)
*/

class Solution {
public:
    string longestPrefix(string s) {

        int n = s.size();
        vector <int> anstis(n,0);

        int i = 1 , j = 0;
        while(i<n){

            if(s[i]==s[j]){

                anstis[i]=j+1;
                i++;
                j++;

            }else{

                if(j != 0){
                    j = anstis[j-1];
                }
                else{
                    anstis[i] = 0;
                    i++;
                }
            }
        }
        
        int l = anstis.back();
        return s.substr(0,l);
    }
};
