// MatrixLib.h - Contains declaration of Function class  
#pragma once  

#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;


#ifdef MATRIXLIB_EXPORTS  
#define MATRIXLIB_API __declspec(dllexport)   
#else  
#define MATRIXLIB_API __declspec(dllimport)   
#endif  

namespace MatrixLib
{

	class Matrix
	{
	public:
		/* Overloaded constructors */
		Matrix();
		Matrix(int);
		Matrix(int, int);
		Matrix(int, int, int);

		/* Destructor */
		~Matrix();

		/* Methods */
		vector<int> getSize();

		int element(int, int);
		void element(int, int, int);

		int det();
		Matrix inv();

		vector<int> diag();
		void diag(vector<int>);

		vector<int> row(int);
		void row(vector<int>, int);

		vector<int> col(int);
		void col(vector<int>, int);

	private:
		vector<vector <int>> data;

	};
}