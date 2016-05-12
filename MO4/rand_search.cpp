#include <conio.h>
#include "Best_sample.h"
#include <iomanip>

void main()
{
	string path = "input.txt",
		path1 = "input1.txt";;
	pair<double, double> result, res;
	Rand_Search A;
	A.Read(path);
	result = A.DoAlgorithm();
	Best_sample B;
	B.Read(path1);
	//res=B.DoAlgorithm();
	cout << setprecision(12)<< result.first << "  " << result.second << "\n" << A.Function(result) << " " << A.countIter << " " << A.countCalc << endl;// ;
	//cout << setprecision(12) << res.first << "  " << res.second << "\n" << B.Function(res) << " " << B.countIter << " " << B.countCalc;
	_getch();
}
