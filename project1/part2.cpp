#include <iostream>
//5 4
//14122
#include <bits/stdc++.h>
using namespace std;


unsigned long long int  countSubarray(unsigned long long int  arr[],
                  unsigned long long int  size, unsigned long long int  givenValue)
{
    unsigned long long int  count = 0;

    for (unsigned long long int  i = 0; i < size; i++) {

        for (unsigned long long int  j = i; j < size; j++) {
            unsigned long long int  sum = 0;
            for (unsigned long long int  l = i; l <= j ; ++l) {
                sum += arr[l];
            }

            if (sum <= givenValue) {
                count++;
            }

        }
    }

    return count;
}


int main()
{
    unsigned long long int  size;
    unsigned long long int  maxValue;
    cin>>size>>maxValue;
    unsigned long long int  array[size];
    unsigned long long int  holdImput;
    for (unsigned long long int  i = 0; i < size; ++i) {
        cin>>holdImput;
        array[i] = holdImput;
    }
    unsigned long long int  count = countSubarray(array, size, maxValue);
    cout << count;
}