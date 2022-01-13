#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    vector<vector<int> > recurs_solve(int i, int ma, int val, vector<vector<int> > &mas) {
        int left = i;
        int j = i;
        while(i < ma) {
            mas[left][i] = val;
            val++;
            i++;
        }
        while(j < ma) {
            mas[j][i] = val;
            val++;
            j++;
        }
        while(i > left) {
            mas[j][i] = val;
            val++;
            i--;
        }
        while(j > left) {
            mas[j][left] = val;
            val++;
            j--;
        }
        if(left >= ma) {
            if(left == ma)mas[left][left] = val;
        } else {
            mas = recurs_solve(left+1, ma-1, val, mas);
        }
        return mas;
    }
    
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res;
        for(int i = 0; i < n; i++) {
            vector<int> val;
            for(int j = 0; j < n; j++) {
                val.push_back(0);
            }
            res.push_back(val);
        }
        
        res = recurs_solve(0, n-1, 1, res);
        
        
        
        return res;
    }
} A;

int main() {
    int n;
    cin >> n;

    vector<vector<int> > res = A.generateMatrix(n);

    for(int i = 0; i < n; i++) {
        for(int j = 0 ; j < n; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    } 

    return 0;
}