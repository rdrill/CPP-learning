#include <iostream>
using namespace std; 
#include <algorithm> 
#include <vector> 

char condfile[] = "20212041414";

int main(void) {
	vector<bool> actual;
	vector<int> initrow;
	vector<vector<int>> rules;
	rules.push_back(initrow);
	int n = sizeof(condfile)/sizeof(condfile[0]);
	int divider = 0; 
	for (size_t i = 1; i < n+1; i++)
	{
		if(i==n)break;
		int char_to_int = (int)(condfile[i-1])-(int)'0';
		switch (i%2){
			case 0:
				if(char_to_int==0){
					cout << i-1 << "***OR***" << std::endl;
					divider++;
					vector<int> row;
					rules.push_back(row);
				}else{
					cout << i-1 << "***and**" << std::endl;
				}
				break;
			default:
				cout << i-1 << " VALU ---> " << char_to_int << std::endl;
				rules[divider].push_back(char_to_int);
				break;
		}

	}
	cout << "START" << endl; 
	// vector<int> r1;
	// vector<int> r2;
	// rules.push_back(r1);
	// rules.push_back(r2);
	// for (size_t i = 0; i < 10; i++)
	// {
	// 	rules[0].push_back(i*2);
	// 	rules[1].push_back(i+2);
	// 	rules[2].push_back(i*2-2);
	// }
	
	for (int i = 0; i < rules.size(); i++) { 
        for (int j = 0; j < rules[i].size(); j++){ 
            cout << i <<" RLS | " << rules[i][j] << " " << endl; 
		}
    } 
	cout << "STOP" << endl; 
	// if (all_of(begin(something), 
    // end(something), 
    //        [](bool i)
    //         { 
    //           return i; // or return !i ;
    //         })) {
    //     cout << "All numbers are true\n";
    // }
	//cout << "Hello Easy C++ project!" << std::endl;
}