/*
  216. Combination Sum III : ( https://leetcode.com/problems/combination-sum-iii/description/ )
*/

class Solution {
public:
    vector<vector<int>> sum;
    
    void solve(int k,int n,vector<int>temp,int num ){

        if(k == 0){
            
            if(n != 0){

                return;

            }else{

                sum.push_back(temp);
                return;
            }

        }
        
        int d = num + 1 ;

        for(int i = d ; i <= 9 ; i++){

            temp.push_back(i);

            solve(k-1 , n-i , temp , i);

            temp.pop_back();

        }
    }

    vector < vector <int> > combinationSum3 ( int k , int n ) {
        vector <int> comb;
        int num = 0 ;
        solve( k , n , comb , num);
        return  sum;
    }
};
