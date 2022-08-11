#include <iostream>
using namespace std;

int findNumber(string inputString , int size){
    int leftCount = 0;
    int rightCount = 0;
    int i=0 , j=size-1;
    int totalCount = 0;
    int startRightIndex = j;
    int startLeftIndex = 0;
    while (true){
        if (i == j){
            totalCount++;
            break;
        }
        if (i>j){
            if (j!= startRightIndex)
                totalCount++;
            break;
        }
        leftCount+=inputString[i];
        rightCount+=inputString[j];
        if (leftCount == rightCount){
            bool flag = true;
            for (int k = startLeftIndex; k <= i ; ++k) {
                if (inputString[k] != inputString[startRightIndex-i+k]){
                    flag = false;
                    break;
                }
            }

            if (flag== true){
                totalCount+=2;
                startLeftIndex = i+1;
                startRightIndex = j-1;
            }



        }
        i++;
        j--;

    }

    return totalCount;


}



int main() {
    int numberOfStrings;
    int stringSize;
    string inputString;
    cin >> numberOfStrings;
    for (int q = 0; q < numberOfStrings; ++q) {
        cin >> inputString;
        stringSize = inputString.length();
        int count = findNumber(inputString , stringSize);
        if (count==0)
            count++;
        cout<<count<<"\n";
    }


}
