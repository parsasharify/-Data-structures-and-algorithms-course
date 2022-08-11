#include <iostream>

#include <bits/stdc++.h>

using namespace std;


unsigned long long int  countSubarray(unsigned long long int arr[],
                  unsigned long long int  n, unsigned long long int  k) {
    unsigned long long int  count = 0;

    for (unsigned long long int  i = 0; i < n; i++) {
        unsigned long long int  sum = 0;
        for (unsigned long long int  j = i; j < n; j++) {
            sum = arr[j] + sum;

            if (sum <= k) {
                count++;
            } else {
                break;
            }
        }
    }

    return count;
}


int main() {
    unsigned long long int  size;
    unsigned long long int  maxValue;
    cin >> size >> maxValue;
    unsigned long long int  array[size];
    unsigned long long int  holdImput;
    for (unsigned long long int  i = 0; i < size; ++i) {
        cin >> holdImput;
        array[i] = holdImput;
    }
    unsigned long long int  count = countSubarray(array, size, maxValue);
    cout << count << "\n";
}