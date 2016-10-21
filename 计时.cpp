# include <iostream>
# include <ctime>
using namespace std;

int main() {
	int i = 0;
	clock_t start, stop;
	start = clock();
	while (i < 1000000000) {
		i++;
	}
	stop = clock();
	cout << CLK_TCK << endl;
	cout << CLOCKS_PER_SEC << endl << start << endl << stop << endl;
	cout << double(stop - start) / CLOCKS_PER_SEC;
	return 0; 
} 
