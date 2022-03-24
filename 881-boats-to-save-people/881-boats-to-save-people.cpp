class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
      sort(people.begin(), people.end());
        
        int tot = 0, boats = 0, beg = 0, end = people.size() - 1;
        
        while(tot < people.size()){
            boats++;
            if(people[end] + people[beg] <= limit){
                end--;
                beg++;
                tot+=2;
            }
            else{
                end--;
                tot++;
            }
        }
        
        return boats;
    }
};