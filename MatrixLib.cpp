// MatrixLib.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

namespace MatrixLib
{
	/* Constructor overloads */
	Matrix::Matrix()
	{
		this->data.clear();
	}

	Matrix::Matrix(int N)
	{
		this->data.resize(N, vector<int>(N));
	}

	Matrix::Matrix(int M, int N)
	{
		this->data.resize(M, vector<int>(N));
	}

	Matrix::Matrix(int M, int N, int initial)
	{
		this->data.resize(M, vector<int>(N, initial));
	}

	/* Destructor */
	Matrix::~Matrix()
	{
	}

	/* Get element i, j */
	int Matrix::element(int i, int j) const
	{
		return this->data[i][j];
	}

	/* Set element i, j */
	void Matrix::element(int i, int j, int entry)
	{
		this->data[i][j] = entry;
	}

	/* Get size of the matrix */
	vector<int> Matrix::getSize() const
	{
		vector<int> size(2);
		size[0] = this->data.size();
		size[1] = this->data[0].size();
		return size;
	}

	/* Get elements on the main diagonal of the matrix */
	vector<int> Matrix::diag() const
	{
		int length = min(getSize()[0], getSize()[1]);
		vector<int> diag(length);
		for (int i = 0; i < length; ++i)
		{
			diag[i] = this->data[i][i];
		}
		return diag;
	}

	/* Set elements on the main diagonal of the matrix */
	void Matrix::diag(vector<int> d)
	{
		int length = min(getSize()[0], getSize()[1]);
		for (int i = 0; i < length; ++i)
		{
			this->data[i][i] = d[i];
		}
	}

	/* Return row i of the matrix */
	vector<int> Matrix::row(int i) const
	{
		return this->data[i];
	}

	/* Set row i of the matrix */
	void Matrix::row(vector<int> arr, int i)
	{
		this->data[i] = arr;
	}

	/* Return column j of the matrix */
	vector<int> Matrix::col(int j) const
	{
		vector<int> arr;
		for (int i = 0; i < getSize()[0]; ++i)
		{
			arr[j] = this->data[i][j];
		}
		return arr;
	}

	/* Set column j of the matrix */
	void Matrix::col(vector<int> arr, int j)
	{
		for (int i = 0; i < getSize()[0]; ++i)
		{
			this->data[i][j] = arr[j];
		}
	}

	/*********************************************************
	 **                   Overloading                       **
	 *********************************************************/

	/* Overload operator + */
	Matrix Matrix::operator+(const Matrix& A) const
	{
		/* Handle size exception */
		if (A.getSize()[0] != getSize()[0] || A.getSize()[1] != getSize()[1])
			throw exception("Dimension mismatch");
		/* TODO: handle overflow exception */

		Matrix out;
		for (int i = 0; i < A.getSize()[0]; ++i){
			for (int j = 0; j < A.getSize()[1]; ++j){
				out.element(i, j, A.element(i, j) + this->element(i, j));
			}
		}
		return out;
	}

	/* Overload operator - */
	Matrix Matrix::operator-(const Matrix& A) const
	{
		/* Handle size exception */
		if (A.getSize()[0] != getSize()[0] || A.getSize()[1] != getSize()[1])
			throw exception("Dimension mismatch");
		/* TODO: handle overflow exception */

		Matrix out(A.getSize()[0], A.getSize()[1]);
		for (int i = 0; i < A.getSize()[0]; ++i){
			for (int j = 0; j < A.getSize()[1]; ++j){
				out.element(i, j, A.element(i, j) - this->element(i, j));
			}
		}
		return out;
	}

	/* Overload operator * for scalar */
	Matrix Matrix::operator*(const int c) const
	{
		/* TODO: handle overflow exception */

		Matrix out;
		for (int i = 0; i < getSize()[0]; ++i){
			for (int j = 0; j < getSize()[1]; ++j){
				out.element(i, j, c * this->element(i, j));
			}
		}
		return out;
	}

	/* Overload operator / for scalar */
	Matrix Matrix::operator/(const int c) const
	{
		/* TODO: handle overflow exception */

		Matrix out;
		for (int i = 0; i < getSize()[0]; ++i){
			for (int j = 0; j < getSize()[1]; ++j){
				out.element(i, j, this->element(i, j) / c);
			}
		}
		return out;
	}

	/* Overload operator << */
	ostream& operator<<(ostream& os, Matrix& A)
	{
		for (int i = 0; i < A.getSize()[0]; ++i)
		{
			for (int j = 0; j < A.getSize()[1]; ++j)
			{
				os << A.element(i, j);
			}
			os << endl;
		}
		return os;
	}

	/* Get the determinant of a 2 x 2 matrix */
	int Matrix::det() const
	{
		/* Handle size exception */
		if (getSize()[0] != getSize()[1])
			throw exception("Non-square matrix");

		return this->data[0][0] * this->data[1][1] - this->data[0][1] * this->data[1][0];
	}

	/* Inverse of a 2 x 2 matrix */
	Matrix Matrix::inv() const
	{
		/* Handle size exception */
		if (getSize()[0] != getSize()[1])
			throw exception("Non-square matrix");

		Matrix inverse(getSize()[0], getSize()[1]);
		inverse.element(0, 0, this->data[1][1]);
		inverse.element(1, 1, this->data[0][0]);
		inverse.element(0, 1, -this->data[0][1]);
		inverse.element(1, 0, -this->data[1][0]);
		return inverse / det();
	}
}