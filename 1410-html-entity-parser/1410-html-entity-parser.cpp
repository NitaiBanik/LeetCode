class Solution {
public:
    string entityParser(string text) {
        string parsedString, answer;
        for(auto chr: text){
            parsedString+=chr;
            answer+=chr;
            
            if(chr != ';') continue;
            
            int size = parsedString.size();
            if(size >= 6 && parsedString[size - 6] == '&' && parsedString[size - 5] == 'q' && parsedString[size - 4] == 'u' && parsedString[size - 3] == 'o' && parsedString[size - 2] == 't' && parsedString[size - 1] == ';'){
                answer.pop_back();
                answer.pop_back();
                answer.pop_back();
                answer.pop_back();
                answer.pop_back();
                answer.pop_back();
                answer += '"';
                
            }
            
           
            else if(size >= 6 && parsedString[size - 6] == '&' && parsedString[size - 5] == 'a' && parsedString[size - 4] == 'p' && parsedString[size - 3] == 'o' && parsedString[size - 2] == 's' && parsedString[size - 1] == ';'){
                answer.pop_back();
                answer.pop_back();
                answer.pop_back();
                answer.pop_back();
                answer.pop_back();
                answer.pop_back();
                answer += '\'';
                }
                      else if(size >= 7 && parsedString[size - 7] == '&' && parsedString[size - 6] == 'f' && parsedString[size - 5] == 'r' && parsedString[size - 4] == 'a' && parsedString[size - 3] == 's' && parsedString[size - 2] == 'l' && parsedString[size - 1] == ';'){
                answer.pop_back();
                answer.pop_back();
                answer.pop_back();
                answer.pop_back();
                answer.pop_back();
                answer.pop_back();
                answer.pop_back();
                answer += '/';
                }
            else if(size >= 4 && parsedString[size - 4] == '&' && parsedString[size - 3] == 'g' && parsedString[size - 2] == 't' && parsedString[size - 1] == ';'){
                answer.pop_back();
                answer.pop_back();
                answer.pop_back();
                answer.pop_back();
                answer+='>';
                
            }
            
            
            else if(size >= 4 && parsedString[size - 4] == '&' && parsedString[size - 3] == 'l' && parsedString[size - 2] == 't' && parsedString[size - 1] == ';'){
                answer.pop_back();
                answer.pop_back();
                answer.pop_back();
                answer.pop_back();
                 answer+='<';
                
            }
            
                        else if(size >= 5 && parsedString[size - 5] == '&' && parsedString[size - 4] == 'a' && parsedString[size - 3] == 'm' && parsedString[size - 2] == 'p' && parsedString[size - 1] == ';'){
                answer.pop_back();
                answer.pop_back();
                answer.pop_back();
                answer.pop_back();
                answer.pop_back();
                answer += '&';
                
            }
        }

        return answer;
        
    }
};