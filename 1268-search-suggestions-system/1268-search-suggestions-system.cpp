class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) { 
        sort(products.begin(), products.end());
        
        vector<vector<string>> results;
        
        int productPosition, productsStart = 0, n = products.size();
        string prefix;
        
        for(int i = 0; i < searchWord.size(); i++){
            prefix += searchWord[i];
            productPosition = lower_bound(products.begin() + productsStart, products.end(), prefix) - products.begin();
            
            vector<string>tempProducts;
            for(int j = productPosition; j < min(productPosition  + 3, (int)products.size()); j++){
                string stringToCompare = products[j].substr(0, prefix.size());
                if(stringToCompare == prefix){
                    productsStart = productPosition;
                    tempProducts.push_back( products[j]);
                }
                else break;
            }
            results.push_back(tempProducts);
        }
        
        return results;
    }
};