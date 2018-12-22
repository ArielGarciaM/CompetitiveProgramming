#include <bits/stdc++.h>
using namespace std;

struct cow {
    int arr, time, sen;
    cow(int arr, int time, int sen) : arr(arr), time(time), sen(sen){};
};

bool comp(cow a, cow b) {
    if(a.arr != b.arr)
        return a.arr < b.arr;
    return a.sen < b.sen;
}

int main() {
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    int n, index[100005];
    cin >> n;
    vector<cow> cows;
    for(int i = 0; i < n; i++) {
        int arr, time;
        cin >> arr >> time;
        cows.push_back(cow(arr, time, i));
    }
    int mx = 0, curtime = 0, processed = 0, lastAdded = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    sort(cows.begin(), cows.end(), comp);
    for(int i = 0; i < n; i++) {
        index[cows[i].sen] = i;
    }
    /*or(auto c : cows)
        cout << c.sen << " " << c.arr << endl;*/
    while(processed < n) {
        if(pq.empty()) {
            cow tmp = cows[processed];
            //cout << processed << " " << tmp.sen << " " << tmp.arr << endl;
            pq.push(tmp.sen);
            lastAdded = processed;
        }
        cow c = cows[index[pq.top()]];
        //cout << "processing cow with seniority " << c.sen << endl;
        pq.pop();
        int nxtTime = max(curtime, c.arr), endTime = nxtTime + c.time;
        mx = max(mx, nxtTime - c.arr);
        int i = lastAdded + 1;
        while(i < n && cows[i].arr < endTime) {
            pq.push(cows[i].sen);
            lastAdded = i;
            i++;
        }
        //cout << "cow with seniority " << c.sen << " arrived at " << c.arr << " and ate from " << nxtTime << " to " << endTime << endl;
        curtime = endTime;
        processed++;
    }
    cout << mx << endl;
}