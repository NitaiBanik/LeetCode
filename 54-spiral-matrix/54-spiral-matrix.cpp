class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& inputMatrix) {
       int numberOfRows = inputMatrix.size();
      int numberOfCols = inputMatrix[0].size();

      int topRow = 0, buttomRow = numberOfRows - 1;
      int leftCol = 0, rightCol = numberOfCols - 1;

      vector<int>answer;

      while(topRow <= buttomRow && leftCol <= rightCol){
        for(int i = leftCol; i <= rightCol; i++){
          answer.push_back(inputMatrix[topRow][i]);
        }
        topRow++;

        for(int i = topRow; i<= buttomRow; i++){
          answer.push_back(inputMatrix[i][rightCol]);
        }
        rightCol--;

        if(topRow <= buttomRow){
          for(int i = rightCol; i >= leftCol; i--){
            answer.push_back(inputMatrix[buttomRow][i]);
          }
          buttomRow--;
        }

        if(leftCol <= rightCol){
          for(int i = buttomRow; i >= topRow; i--){
            answer.push_back(inputMatrix[i][leftCol]);
          }
          leftCol++;
        }
      }
      return answer;
    }
};