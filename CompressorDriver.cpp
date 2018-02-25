#include "Compressor.h"

using namespace std;

int main(){
	Compressor c;
	cout << c.compress("a.html") << endl;
	cout << c.deCompress("COM_a.html") << endl;
	return 0;
}
