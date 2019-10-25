#include <iostream>
#include <vector>

using namespace std;

struct elem {
    int color;
    bool used;
    elem() {
        color = -1;
        used = false;
    }
};

vector<elem> colors(256, elem());
int n, k;

int findColor (const int &a) {
    if (colors[a].color == -1) {
        auto from = a;
        for (auto i = a;;i--) {
            if (i == a - k || i < 0 || colors[i].used == true) {
                from = i+1;
                break;
            }
        }



        for (auto i = from; i < from + k; i++) {
            if (colors[i].used == true)
                break;
            colors[i].color = from;
        }
        colors[from].used = true;
    }
    colors[a].used = true;
    return colors[a].color;
}

int main() {
    cin >> n >> k;

    int color;
    for (auto i = 0; i < n; i++) {
        cin >> color;
        cout << findColor(color) << " ";
    }
    return 0;
}