// Ques 150. Evaluate Reverse Polish Notation ( Leetcode ) : https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

class Solution {
public:
    int expression(int b , int a , string character){
        if(character == "+")return (a+b);
        else if(character == "*")return (a*b);
        else if(character == "-")return (a-b);
        else return (a/b);
    }   

    int evalRPN( vector <string> & tokens) {
        int n = tokens.size();
        stack <int> s;
        for(int i=0 ; i<n ; i++ ){
            stringstream ss;
            stringstream ss1;
            if( tokens[i] == "+" || tokens[i] == "*" || tokens[i] == "/" || tokens[i] == "-"){
                int a ;
                a= s.top();
                s.pop();

                int b ;
                b = s.top();
                s.pop();

                string d = tokens[i];
                int c = expression(a , b , d);
                s.push(c);

            }else {

                s.push(stoi(tokens[i]));

            }

        }

        return s.top();

    }
};

Time Complexity : O (N)
Space Complexity : O (N)
