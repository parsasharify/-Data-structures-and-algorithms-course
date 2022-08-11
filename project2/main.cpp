#include <iostream>


using namespace std;

#include<bits/stdc++.h>

using namespace std;


int numberOfNights(int array[], int n) {
    // array = [10, 9, 7, 8, 6, 5, 3, 4, 2, 1]
    stack<int> s; // monotonic stack of pairs (array[j],turns[j])
    // int s[n];
    int hold;
    int count = 0;// # result: number of turns to delete all deletable elements
    for (int i = 0; i < n; i++) {

// initially assuming current element can be deleted
        int turns = 1;

//peeking at the top of the stack
        while (s.size() > 0 and s.top() <= array[i]) {
            hold = s.top();
            s.pop();
            if (s.top() <= array[i]) {
                s.pop();
                turns = max(hold + 1, turns);
            } else {
                s.push(hold);
                break;
            }
        }
//corner case: current element is the largest so far, cant be deleted
        if (s.size() == 0)
            turns = 0;
        s.push(array[i]);
        s.push(turns);

      count = max(count, turns);
    }
    return count;
}


int main() {

    int size;
    cin >> size;
    int array[size];
    int holdImput;
    for (int i = 0; i < size; ++i) {
        cin >> holdImput;
        array[i] = holdImput;
    }

    int count = numberOfNights(array, size);

    cout << count << "\n";

}
