class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        int carry = 1;
        for( int i = n-1 ; i>=0 ; i-- ){
        int sum = digits[i]+carry;
            if(sum<10){
            digits[i]= sum;
                carry = 0;
                break;
            }
            else{
                digits[i]= 0;
                carry = 1;
            }
        }
        if(carry == 1){
       vector<int>temp(n+1);
            temp[0]= 1;
            for (int i = 0; i < n; i++) {
                temp[i + 1] = digits[i];
            }
            return temp;
        }
        return digits;
    }
};