#include<bits/stdc++.h>
using namespace std;

int main(){
    int r, b, p;
    cout << "Enter number of red and blue balls respectively and profit on guessing correctly:\n";
    cin >> r >> b >> p;
    vector<vector<double>> dp(r + 1, vector<double>(b + 1, 0));
    vector<vector<char>> decision(r + 1, vector<char>(b + 1));
    // if there is only one type of ball in the bag, we can always guess correctly - so fill base cases : 
    dp[0][0] = 0;
    decision[0][0] = 'T';
    for(int i = 1; i <= r; i++){
        dp[i][0] = i * p;
        decision[i][0] = 'R';
    }
    for(int j = 1; j <= b; j++){
        dp[0][j] = j * p;
        decision[0][j] = 'B';
    }

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= b; j++){
            double guessR = (1.0 * i / (i + j)) * (p + dp[i - 1][j]) + (1.0 * j / (i + j)) * dp[i][j - 1];
            double guessB = (1.0 * i / (i + j)) * dp[i - 1][j] + (1.0 * j / (i + j)) * (p + dp[i][j - 1]);
            decision[i][j] = guessR > guessB ? 'R' : guessR == guessB ? 'T' : 'B'; 
            dp[i][j] = guessR > guessB ? guessR : guessB;
        }
    }
    // output the expected payoff using the optimal strategy
    cout << "The maximum expected payoff is : " << dp[r][b] << endl;
    cout << "The decision table to follow to achieve the maximum payoff is : \n";

    //output decision table that tells the optimal decision one should make if there are 'i' red balls
    //and 'b' blue balls remaining
    cout << "  ";
    for(int i = 0; i <= b; i++) cout << i << " ";
    cout << endl;
    for(int i = 0; i <= r; i++){
        cout << i << " ";
        for(int j = 0; j <= b; j++){
            cout << decision[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}