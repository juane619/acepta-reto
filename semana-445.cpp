#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;

void fastscan(int& number) {
    // variable to indicate sign of input number
    bool negative = false;
    register int c;

    number = 0;

    // extract current character from buffer
    c = getchar();
    if (c == '-') {
        // number is negative
        negative = true;

        // extract the next character from the buffer
        c = getchar();
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c > 47 && c < 58); c = getchar()) number = number * 10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative) number *= -1;
}

class Activity {
    int start, finish;

   public:
    Activity() { start = finish = 0; }

    Activity(int a, int b) {
        start = a;
        finish = b;
    }

    bool operator<(const Activity& other) const {
        return start < other.start ||
               (!(other.start < start) && finish < other.finish);
    }

    int getStart() const { return start; }
    int getFinish() const { return finish; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nactivities;

    while (cin >> nactivities) {
        unsigned long start, finish;

        vector<Activity> vactivities(nactivities);
        int persons_needed = 0;

        for (int i = 0; i < nactivities; i++) {
            cin >> start >> finish;

            Activity act(start, finish);
            vactivities[i] = act;
        }

        sort(vactivities.begin(), vactivities.end());

        priority_queue<int, vector<int>, greater<int> > end_times;

        int curr = 0;

        while (!end_times.empty() || curr < nactivities) {
            if (end_times.empty()) {
                end_times.push(vactivities[curr].getFinish());
                curr++;
            } else if (curr >= nactivities) {
                end_times.pop();
            } else {
                if (vactivities[curr].getStart() < end_times.top()) {
                    end_times.push(vactivities[curr].getFinish());
                    curr++;
                } else {
                    end_times.pop();
                }
            }

            persons_needed = max(persons_needed, (int)end_times.size());
        }

        cout << persons_needed - 1 << "\n";
    }
    return 0;
}
