#include <iostream>

using namespace std;

class matrix
{
	private:

	int nr;
	std::string mx;

	public:

	int ROW;
    int COL;
    int **value_tab;
	int select();
	void questions();
	void download();
};
