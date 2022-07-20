struct Node{
    const string& word;
    int index;
    Node(const string& _word, int _index): word(_word), index(_index){}
};

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<Node> buckets[26];
        int answer = 0;
        
        for(string& word: words)
            buckets[word[0]-'a'].emplace_back(word, 0);
        
        for(char chr: s){
            auto bucket = buckets[chr-'a'];
            buckets[chr-'a'].clear();
            
            for(Node& node: bucket){
                node.index++;
                
                if(node.index == node.word.size()){
                    answer++;
                }
                else{
                    buckets[node.word[node.index] - 'a'].push_back(node);
                }
            }
        }
        
        return answer;
    }
};