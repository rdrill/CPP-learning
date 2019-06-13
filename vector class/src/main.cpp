#include <iostream>
using namespace std; 
#include <algorithm> 
#include <vector> 


class HOLDER {
public:
	HOLDER(){};
    int i;
};


int main(void) {

	HOLDER hldr;
	hldr.i = 77;

	vector<HOLDER> vecholder;

	for (size_t i = 0; i < 10; i++)
	{
		HOLDER * s1 = new HOLDER;
		s1->i = i*2+3;
		vecholder.push_back(*s1);
	}
	
	for (size_t i = 0; i < 10; i++)
	{
		cout << vecholder[i].i << endl;
	}
	

	cout << hldr.i << endl;	

}