#include <conio.h>

#include "Best_sample.h"


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
	res=B.DoAlgorithm();

	cout << result.first << "  " << result.second << "\n" << A.Function(result)<<endl;// << " " << A.countIter << " " << A.countCalc;
	cout << res.first << "  " << res.second << "\n" << B.Function(res) << " " << B.countIter << " " << B.countCalc;
	_getch();
}
