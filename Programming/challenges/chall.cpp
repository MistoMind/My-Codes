#include <bits/stdc++.h>
using namespace std;

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player, int tot_rank) {
    int player_size = player.size(), ranked_size = ranked.size(), start = ranked_size-1;
    vector<int> result(player_size);

    for(int i=0;i<player_size;i++){
        cout << "Player score = " << player[i] << endl;
        for(int j=start;j>=0;j--){
            if(ranked[j]==ranked[j-1])
                continue;
            cout << "Check ranked = " << ranked[j] << endl;
            if(player[i]>=ranked[j]){
                cout << "Found! so rank = " << j+1 << endl;
                result[i] = j+1;
                if(player[i+1]<ranked[j-1])
                    start = j;
                else start = j+1;
                cout << "Starting from " << start << endl;
                break;
            }
        }
        if(result[i]==0){
            result[i] = tot_rank+1;
            cout << "Sad you are last!" << endl;
        }
    }
    
    return result;
}

int main(){
    ifstream fin("input.txt");
    vector<int> ranked;
    vector<int> player;
    int tot_rank = 1;

    int n, num, m;
    fin >> n;
    for(int i=0;i<n;i++){
        fin >> num;
        ranked.push_back(num);
        if(ranked[i-1]!=num && i!=0)
            tot_rank++;
    }
    cout << "Tot ranks = " << tot_rank << endl;
    fin >> m;

    for(int i=0;i<m;i++){
        fin >> num;
        player.push_back(num);
    }

    vector<int> result = climbingLeaderboard(ranked, player, tot_rank);
    cout << "\nOur Result:-" << endl;
    for(int i=0;i<result.size();i++){
        cout << result[i] << endl;
    }

    fin.close();
}