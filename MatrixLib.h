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

		/* Operator overloading */
		Matrix operator+(const Matrix&) const;
		Matrix operator-(const Matrix&) const;
		Matrix operator*(const int) const;
		Matrix operator/(const int) const;

		/* Methods */
		vector<int> getSize() const;

		int element(int, int) const;
		void element(int, int, int);

		int det() const;
		Matrix inv() const;

		vector<int> diag() const;
		void diag(vector<int>);

		vector<int> row(int) const;
		void row(vector<int>, int);

		vector<int> col(int) const;
		void col(vector<int>, int);

	private:
		vector<vector <int>> data;

	};
}