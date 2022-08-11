#include <iostream>
#include<bits/stdc++.h>

using namespace std;


int main() {
    int m, n, row, coloumn;
    char direction;
    cin >> n >> m;
    std::map<int, int> coloumnToColored;
    std::map<int, char> rowToDirection;
    std::map<int, int>::iterator coloumnToColoredITR;
    std::map<int, char>::iterator rowToDirectionITR;
    for (int i = 0; i < m; ++i) {

        cin >> coloumn >> row >> direction;
        coloumnToColoredITR = coloumnToColored.lower_bound(coloumn);
        if (coloumnToColoredITR->first == coloumn) {
            cout << 0 << "\n";
            continue;
        }
        if (direction == 'U') {
            coloumnToColoredITR = coloumnToColored.upper_bound(coloumn);
            rowToDirection.insert({row, 'U'});
            if (coloumnToColoredITR == coloumnToColored.end()) {
                coloumnToColored.insert({coloumn, row});
                cout << row << "\n";
                continue;
            }
            rowToDirectionITR = rowToDirection.find(n + 1 - coloumnToColoredITR->first);

            if (rowToDirectionITR->second == 'U') {
                coloumnToColored.insert({coloumn, row - rowToDirectionITR->first + coloumnToColoredITR->second});
                cout << row - rowToDirectionITR->first + coloumnToColoredITR->second << "\n";
            } else {
                coloumnToColored.insert({coloumn, row - rowToDirectionITR->first});
                cout << row - rowToDirectionITR->first << "\n";
            }
        } else {
            rowToDirectionITR = rowToDirection.upper_bound(row);
            rowToDirection.insert({row, 'L'});
            if (rowToDirectionITR == rowToDirection.end()) {
                coloumnToColored.insert({coloumn, coloumn});
                cout << coloumn << "\n";
                continue;
            }
            coloumnToColoredITR = coloumnToColored.find(n + 1 - rowToDirectionITR->first);

            if (rowToDirectionITR->second == 'U') {
                coloumnToColored.insert({coloumn, coloumn - (n + 1 - rowToDirectionITR->first)});
                cout << coloumn - (n + 1 - rowToDirectionITR->first) << "\n";
            } else {
                coloumnToColored.insert(
                        {coloumn, coloumnToColoredITR->second + (coloumn) - coloumnToColoredITR->first});
                cout << coloumnToColoredITR->second + coloumn - coloumnToColoredITR->first << "\n";
            }

        }

    }
}
