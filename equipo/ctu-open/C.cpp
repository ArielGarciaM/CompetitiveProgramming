#include <bits/stdc++.h>
#define fuck long long
using namespace std;
typedef void(*fholder)();

struct hand {
    pair<long long, char> cards[5];
};

long long score(long long n) {
    return min(n, 10ll);
}

hand h;
long long last = 0, value = 0, twelve = 0, preval = 0;

void f1() {
    value++;
    long long numJs = 0;
    for(long long i = 0; i < 5; i++) {
        if(h.cards[i].first == 11)
            numJs++;
    }
    value += numJs*score(h.cards[0].first);
}

void f2() {
    value *= 2;
}

void f3() {
    set<char> suitset;
    for(long long i = 0; i < 5; i++)
        suitset.insert(h.cards[i].second);
    if(suitset.size() == 4)
        value *= 2;
}

void f4() {
    long long cntb = 0, cntr = 0;
    for(long long i = 0; i < 5; i++) {
        char c = h.cards[i].second;
        if(c == 'D' || c == 'H')
            cntr++;
        else
            cntb++;
    }
    value += abs(cntb - cntr);
}

void f5() {
    return;
}

void f6() {
    long long cnt7 = 0;
    for(long long i = 0; i < 5; i++) {
        if(h.cards[i].first == 7)
            cnt7++;
    }
    if(cnt7 == 4)
        value -= 121;
}

void f7() {
    if(value >= 0) {
        long long mn = 50;
        for(long long i = 0; i < 5; i++)
            mn = min(mn, score(h.cards[i].first));
        value += mn;
    }
}

void f8() {
    if(value < 0)
        value *= -1;
}

void f9() {
    long long cntd = 0;
    for(long long i = 0; i < 5; i++)
        if(h.cards[i].second == 'D')
            cntd++;
    if(cntd >= 3) {
        value++;
        for(long long i = 0; i < 5; i++) {
            long long v = h.cards[i].first;
            if(v == 2 || v == 5)
                h.cards[i].first = 7 - v;
            if(v == 6 || v == 9)
                h.cards[i].first = 15 - v;
        }
    }
}

void f10() {
    set<long long> vals;
    long long ctas = 0, mn = 40, mx = -40;
    for(long long i = 0; i < 5; i++) {
        long long v = h.cards[i].first;
        vals.insert(v);
        if(v == 14)
            ctas++;
        mn = min(mn, v);
        mx = max(mx, v);
    }
    if(vals.size() == 5 && mx == mn + 4)
        value += 5*ctas;
}

void f11() {
    return;
}

void f12() {
    long long ctwo = 0;
    for(long long i = 0; i < 5; i++)
        if(h.cards[i].first == 2)
            ctwo++;
    if(ctwo > 0)
        twelve = 1;
}

void f13() {
    long long ctwo = 0;
    for(long long i = 0; i < 5; i++)
        if(h.cards[i].first == 2)
            ctwo++;
    if(ctwo > 0)
        value *= 2;
}

int main() {
    fholder fs[13] = {f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13};
    for(long long i = 0; i < 5; i++) {
        string s;
        cin >> s;
        h.cards[i].second = s[s.length() - 1];
        s.pop_back();
        if(s[0] == 'J') {
            h.cards[i].first = 11;
            continue;
        }
        if(s[0] == 'Q') {
            h.cards[i].first = 12;
            continue;
        }
        if(s[0] == 'K') {
            h.cards[i].first = 13;
            continue;
        }
        if(s[0] == 'A') {
            h.cards[i].first = 14;
            continue;
        }
        h.cards[i].first = stoi(s);
    }
    for(long long i = 0; i < 5; i++) {
        //cout << h.cards[i].first << " " << score(h.cards[i].first) << endl;
        value += score(h.cards[i].first);
        //cout << value << endl;
    }
    for(long long i = 0; i < 13; i++) {
        preval = value;
        (*fs[i])();
        //cout << value << endl;
        if(value != preval)
            last = i;
        if(i == 11 && twelve == 1)
            (*fs[last])();
    }
    cout << value << endl;
}