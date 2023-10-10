#include <string>
#include "utils.h"
using namespace std;
int main()
{
	tuple <int, float, string> t(77, 1.1, "more light");
	cout << "io: " << t << endl;
}