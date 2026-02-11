// Pascal's Triangle

class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans = new ArrayList<>();

        for (int i = 0; i < numRows; i++) {
            List<Integer> row = new ArrayList<>();

            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    row.add(1);
                } else {
                    row.add(ans.get(i - 1).get(j) + ans.get(i - 1).get(j - 1));
                }
            }

            ans.add(row);
        }

        return ans;
    }
}

// ============================================================================

vector<vector<int>> pascalTriangle(int N) {
    // Write your code here.
    if(N == 1) return {{1}};

    vector<vector<int>> ans(N);
    for(int i=0; i<N; i++) {
        ans[i].resize(i+1);
        ans[i][0] = 1;
        ans[i][i] = 1;
        for(int j=1; j<i; j++) {
            ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
        }
    }

    return ans;
}
// T : O(N^2)
// S : O(N^2)


vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element

    //calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}
// T : O(N)
// S : O(N)



int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

void pascalTriangle(int n) {
    // printing the entire row n:
    for (int c = 1; c <= n; c++) {
        cout << nCr(n - 1, c - 1) << " ";
    }
    cout << "n";
}

int main()
{
    int n = 5;
    pascalTriangle(n);
    return 0;
}
// T : O(N^2)
// S : O(N)
