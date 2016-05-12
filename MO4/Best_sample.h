
#include "rand_search.h"



class Best_sample
{
private:
	double _EPS1, _EPS2, _P, _P_eps, _V, _V_eps, _alpha;
	pair<double, double> x_0, x_1;//гиперквадрат


public:
	int countIter = 0,countCalc=0;

	double Function(pair<double, double> p)
	{
		int A1 = 1, A2 = 3;
		int a1 = 2, a2 = 1;
		int b1 = 3, b2 = 1;
		int c1 = 2, c2 = 1;
		int d1 = 3, d2 = 2;
		double x = p.first,
			y = p.second;
		countCalc++;
		return -((A1 / (1 + pow(((x - a1) / b1), 2) + pow(((y - c1) / d1), 2))) + (A2 / (1 + pow(((x - a2) / b2), 2) + pow(((y - c2) / d2), 2))));
	}
	pair<double, double> rand_search(pair<pair<double, double>, pair<double, double>>,int N)
	{
		double c = 0;
		double _x_lenght = abs(x_1.first - x_0.first),
			_y_lenght = abs(x_1.second - x_0.second);
		double _min_func = DBL_MAX;
		pair<double, double> _xk = x_0, _x_min = x_0;
		for (int i = 0; i < N; i++)
		{
			
				c = ((double)rand() * 1 + 1) / RAND_MAX;
				_xk.first = _x_lenght*c + x_0.first;
				_xk.second = _y_lenght*c + x_0.second;
			
				if (_xk.first + _xk.second <= 1)
				{

					if (Function(_xk) < _min_func)
					{
						_min_func = Function(_xk);
						_x_min = _xk;
					}
				}

		}
		return _x_min;
	}
	long int test_number()
	{
		_V = abs((x_0.second - x_0.first)*(x_1.second - x_1.first));
		_V_eps = _EPS1*_EPS2;
		_P_eps = _V_eps / _V; //Вероятность попадания в эту окрестность при одном испытании равна
		return abs(log(1 - _P) / log(1 - _P_eps));//число испытаний
	}
	pair<double, double> DoAlgorithm()
	{
		int N;
		pair<double, double> _xk = x_0, _x_min = x_0;
		pair<pair<double, double>, pair<double, double>> X;
		X.first = x_0;
		X.second = x_1;
		while (abs(x_1.first - x_0.first) > _EPS1 || abs(x_1.second - x_0.second) > _EPS2)
		{
			countIter++;
			_xk = _x_min;
			N = test_number();
			_x_min = rand_search(X,N);
			x_0.first = _x_min.first + (x_0.second - x_0.first) / (2 * _alpha);
			x_1.first = _x_min.first  -(x_0.second - x_0.first) / (2 * _alpha);
			x_0.second = _x_min.second + (x_1.second - x_1.first) / (2 * _alpha);
			x_1.second = _x_min.second - (x_1.second - x_1.first) / (2 * _alpha);
			
			Function(_x_min)<Function(_xk) ? _alpha *= 2 : _alpha /= 2;
		} 

		return _x_min;
	}

	void Read(string path)
	{
		ifstream read(path, ios_base::in);
		//countCalc = 0;
		read >> x_0.first >> x_0.second >> x_1.first >> x_1.second >> _EPS1 >> _EPS2 >> _P>>_alpha;
		read.close();
	}

};
