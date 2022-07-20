struct Node{
    const string& word;
    int index;
    int sz;
    Node(const string& _word, int _index, int _sz): word(_word), index(_index), sz(_sz){}
};

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<Node> buckets[26];
        int answer = 0;
        
        for(string& word: words)
            buckets[word[0]-'a'].emplace_back(word, 0, word.size());
        
        for(char chr: s){
            auto bucket = buckets[chr-'a'];
            buckets[chr-'a'].clear();
            
            for(Node& node: bucket){
                node.index++;
                
                if(node.index == node.sz){
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