// A Dynamic Programming based solution for 0-1 Knapsack problem
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int wt[100];
int val[100];
int K[101][10001];

//class Tesoro{
//    
//}



// Returns the maximum value that can be put in a knapsack of capacity W

int knapSack(int n, int w) {
    K[n + 1][w + 1];
    int m = w;
    int i, j;

    for (int i = 0; i <= n; i++)
        K[i][0] = 0;

    for (int i = 0; i <= m; i++)
        K[0][i] = 0;

    // Build table K[][] in bottom up manner
    for (i = 1; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            if (wt[i - 1] <= j)
                K[i][j] = max(val[i - 1] + K[i - 1][j - wt[i - 1]], K[i - 1][j]);
            else
                K[i][j] = K[i - 1][j];
        }
    }

    return K[n][m];
}

vector<pair<int, int> > printPath(int n, int w) {
    int j = w;
    vector<pair<int, int> > sol;
    for (int i = n; i > 0; i--) {
        if (K[i][j] == K[i - 1][j])
            continue;
        else {
            sol.push_back(pair<int, int>(wt[i - 1], val[i - 1]));
            j -= wt[i - 1];
        }
    }
    return sol;
}

int main() {
    //cout << "Enter the number of items in a Knapsack:";
    unsigned n, W, auxp;

    while (cin >> W) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            //cout << "Enter value and weight for item " << i << ":";
            cin >> auxp;
            wt[i] = auxp + (auxp * 2);
            cin >> val[i];
        }

        //    int val[] = { 60, 100, 120 };
        //    int wt[] = { 10, 20, 30 };
        //    int W = 50;
        //cout << "Enter the capacity of knapsack";
        cout << knapSack(n, W);

        vector<pair<int, int> > obj = printPath(n, W);

        cout << endl << obj.size() << endl;

        for (int i = obj.size()-1; i >= 0; i--) {
            cout << obj[i].first/3 << " " << obj[i].second << "\n";
        }
        cout << "----\n";
    }
    return 0;
}