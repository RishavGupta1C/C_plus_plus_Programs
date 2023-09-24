#include <iostream>
#include<vector>
#include<sstream>

using namespace std;

int main() {
	int T, w, x, y, z;      // test cases
	cin >> T;
	while(T--) {
        cin >> w >> x >> y >> z;
        if (w==x || w==y || w==z || w==x+y || w==y+z || w==z+x || w==x+y+z) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
	}
	/*
	int T;      // test cases
	cin >> T;
	int len = T;
	while(T--) {
        vector<int> arrOfIntegers;
        string inputString;
        int flag = 1;
        cin.sync()
        //cin.ignore();
	    getline(cin, inputString);
        stringstream ss(inputString);

        //vector<int> arrOfIntegers(T);
        //for (int& element : arrOfIntegers)
        //{
        //    cin >> element;
        //}
        int num;
	    while(ss >> num) {
            arrOfIntegers.push_back(num);
	    }
	    int i=0;
	    if (arrOfIntegers[i] == arrOfIntegers[i+1] || arrOfIntegers[i] == arrOfIntegers[i+2] || arrOfIntegers[i] == arrOfIntegers[i+3]) {
	        flag = 0;
	    }
        if(arrOfIntegers[i] == arrOfIntegers[i+1] + arrOfIntegers[i+2] || arrOfIntegers[i] == arrOfIntegers[i+1] + arrOfIntegers[i+3] || arrOfIntegers[i] == arrOfIntegers[i+2] + arrOfIntegers[i+3])
            flag = 0;
        if (arrOfIntegers[i] == arrOfIntegers[i+1] + arrOfIntegers[i+2] + arrOfIntegers[i+3]) {
            flag = 0;
        }
        if (flag == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
	} */
	return 0;
}
