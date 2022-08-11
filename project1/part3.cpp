#include <iostream>

// CPP program to count
// subarrays having sum
// less than k.
#include <bits/stdc++.h>
using namespace std;

// Function to find number
// of subarrays having sum
// less than k.
unsigned long long int countSubarrays(unsigned long long int  arr[],unsigned long long int  size, unsigned long long int  maxValue){
    unsigned long long int start = 0;
    unsigned long long int sum = 0;
    unsigned long long int count = 0;
    for (unsigned long long int i = 0; i < size; ++i) {
        sum+=arr[i];
        if (sum<=maxValue){
            count+=(i-start+1);
        } else{
            for (unsigned long long int j = start; j < i ; ) {
                sum-=arr[j];
                j++;
                if (sum<=maxValue){
                    count+=(i-j+1);
                    //start = (++j);
                    start=j;
                    break;
                }
                start = j;
            }
        }

    }
    return count;


}

// Driver Code
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
    unsigned long long int
            count = countSubarrays(array, size, maxValue);
    cout << count <<"\n";
}


