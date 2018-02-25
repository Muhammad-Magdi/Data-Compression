#include "Compressor.h"

using namespace std;

int main(){
	Compressor c;
	cout << c.compress("Samples/Input/a.html") << endl;
	cout << c.deCompress("Samples/Compressed/COM_a.html") << endl;
	return 0;
}
