#include <iostream>
using namespace std; 
#include <algorithm> 
#include <vector> 

#define  OR_SYMBOL '|'
#define AND_SYMBOL '&'

char condfile[] = "1|1&1|1&1&1"; //template representation

int main(void) {
	vector<bool> actual = {false,true,false,true,true,false};
	vector<int> initrow;
	vector<vector<int>> rules;
	rules.push_back(initrow);
	int n = sizeof(condfile)/sizeof(condfile[0]);
	int divider = 0; 
	int valcounter = 0; 
	for (size_t i = 1; i < n+1; i++)
	{
		if(i==n)break;
		char condSymbol = condfile[i-1];
		switch (i%2){
			case 0:
				if(condSymbol==OR_SYMBOL){
					cout << i-1 << "***OR***" << std::endl;
					divider++;
					vector<int> row;
					rules.push_back(row);
				}if(condSymbol==AND_SYMBOL){
					cout << i-1 << "***and**" << std::endl;
				}
				break;
			default:
				bool comparator = (int)condSymbol-48; //48 == '0' symbol
				bool trueval = !(actual[valcounter]^comparator);
				cout << i-1 << " TEMPLATE: " << comparator;
				cout <<" | VALUE: " << actual[valcounter];
				cout <<" | TRUEVAL: " << trueval << std::endl;
				//rules[divider].push_back(char_to_int);
				
				rules[divider].push_back(trueval);
				valcounter++;
				break;
		}

	}
	cout << "START \r\n" << endl; 

	vector<bool> balance;
	for (int i = 0; i < rules.size(); i++) { 
        for (int j = 0; j < rules[i].size(); j++){ 
            cout << i <<" RLS | " << rules[i][j] << " " << endl; 
		}
		if (all_of(begin(rules[i]),end(rules[i]),[](bool a){ return a;})){
			cout << "Condition part ["<< i <<"] is  TRUE\n";
			balance.push_back(true);
		}else{
			cout << "Condition part ["<< i <<"] has a FALSE\n";
			balance.push_back(false);
		}
    } 
	cout << "\r\n\r\n************************************************" << endl;
	cout << "################################################" << endl;
	if (any_of(begin(balance),end(balance),[](bool a){ return a;})){
			cout << "TOTAL BALANCE  is TRUE" << endl;
		}else{
			cout << "TOTAL BALANCE  is FALSE" << endl;
		}
	cout << "################################################" << endl;
	cout << "************************************************\r\n\r\n" << endl;
	cout << "STOP" << endl; 

}