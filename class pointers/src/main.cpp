#include <iostream>
using namespace std; 
#include <algorithm> 
#include <vector> 


class HOLDER {
public:
	HOLDER(){};
    int i;
	int mux(int i){
		return i*3;
	}
	int res;
};

class OUTER {
public:
	OUTER(){};
    int u;
	int muxmux(HOLDER * hl , int i){
		hl->i=3;
		int rrr = hl->mux(i*3);
		hl->res = rrr;
		return  rrr;
	}
	HOLDER * hl;
};


int main(void) {

	HOLDER * hldr = new HOLDER();

	OUTER outr;
	outr.hl = hldr;

	outr.hl->i = 77;
	uint32_t result = outr.muxmux(hldr, 8);

	cout << outr.hl->i << endl;
	cout << hldr->i << endl;
	hldr->i	= 1212;
	cout << outr.hl->i << endl;
	outr.hl->i = 999;
	cout << hldr->res << endl;

}