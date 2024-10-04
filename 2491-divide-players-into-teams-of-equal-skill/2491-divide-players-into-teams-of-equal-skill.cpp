class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        vector<int>temp(1001,0);
        int n = skill.size();
        int sum = 0 ;
        for( int i = 0 ; i< skill.size(); i++){
            sum = sum + skill[i];
            temp[skill[i]]++;
        }
        int team  = n/2;
        if(sum%team!=0){
return -1;}
        int target = sum/team;
        long long chem = 0;
        for( int i =0 ; i < skill.size(); i++){
           int curr = skill[i];
            int rem = target - curr;
            if(temp[rem]<=0){
return -1;}
            chem +=(long long)(curr) * (long long)(rem);
            temp[rem]= temp[rem]-1;
        }
        return chem/2;
    }
    
};