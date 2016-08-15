#pragma once
#include "Vector3.h"
#include <iostream>

namespace Benzene
{
	template <typename T>
	class Matrix44
	{

	public:

		const int MATRIX_LENGTH = 4;

		T m[MATRIX_LENGTH][MATRIX_LENGTH] = {
						{1, 0, 0, 0},
						{0, 1, 0, 0},
						{0, 0, 1, 0},
						{0, 0, 0, 1}
					};

		Matrix44(void)
		{}

		Matrix44(T a, T b, T c, T d, T e, T f, T g, T h,
					T i, T j, T k, T l, T m1, T n, T o, T p)
		{
			m[0][0] = a;
			m[0][1] = b;
			m[0][2] = c;
			m[0][3] = d;
			m[1][0] = e;
			m[1][1] = f;
			m[1][2] = g;
			m[1][3] = h;
			m[2][0] = i;
			m[2][1] = j;
			m[2][2] = k;
			m[2][3] = l;
			m[3][0] = m1;
			m[3][1] = n;
			m[3][2] = o;
			m[3][3] = p; 
		}

		~Matrix44(void);
		{}

		// Why two variants
		const T* operator [] (int i) const
		{
			return m[i];
		}

		// Why const vs no const
		T* operator [] (uint8_t i)
		{
			return m[i];
		}

		/*
			Multiplication
		*/
		Matrix44 operator * (const Matrix44& pRhs) const
		{
			Matrix44 product;
			for(int i=0; i<MATRIX_LENGTH; ++i)
			{
				for(int j=0; j<MATRIX_LENGTH; ++j)
				{
					product[i][j] = m[i][0] * pRhs[0][j] +
									m[i][1] * pRhs[1][j] +
									m[i][2] * pRhs[2][j] +
									m[i][3] * pRhs[3][j];
				}
			}

			return product;
		}

		/*
			Vector Matrix Multiplication
			ROW_MAJOR - [1, 2, 3]  --> Not very optimal as the 2D array of 
								Matrix is not accessed sequentially
			COLUMN_MAJOR --> Optimal compared to ROW_MAJOR. As the matrix array
						elements are accessed sequentially
			But the compiler optimitsation technologies optimise the looping of 
			multi dimensional arrays to acheieve comparable performance irrespective
			of the type of Vector used [Column/Row Major]
		*/
		Vector3<T> Product_VectorMultiplication(const Vector3<T> &vector)
		{
	#ifdef ROW_MAJOR
			return Vector3<T>(
				vector.x * m[0][0] + vector.y * m[1][0] + vector.z * m[2][0],
				vector.x * m[0][1] + vector.y * m[1][1] + vector.z * m[2][1],
				vector.x * m[0][2] + vector.y * m[1][2] + vector.z * m[2][2]);
	#else
			return Vector3<T>(
				vector.x * m[0][0] + vector.y * m[0][1] + vector.z * m[0][2],
				vector.x * m[1][0] + vector.y * m[1][1] + vector.z * m[1][2],
				vector.x * m[2][0] + vector.y * m[2][1] + vector.z * m[2][2]);
	#endif
		}

		/*
			Transpose the Matrix
		*/
		Matrix44 transpose() const
		{
			Matrix44 transMat;
			for(int i=0; i<MATRIX_LENGTH; i++)
			{
				for(int j=0; j<MATRIX_LENGTH; j++)
				{
					transMat[i][j] = m[j][i];
				}
			}
		}

		/*
			Override "<<" operator for displaying matrix
		*/
		friend std::ostream& operator << (std::ostream &s, const Matrix44 &m)
		{
			std::ios_base::fmtflags oldFlags = s.flags();
			int width = 12;									// total with of the displayed number
			s.precision(5);									// control the number of displayed decimals
			s.setf (std::ios_base::fixed);

			s << "(" << std::setw (width) << m[0][0] <<
			" " << std::setw (width) << m[0][1] <<
			" " << std::setw (width) << m[0][2] <<
			" " << std::setw (width) << m[0][3] << "\n" <<

			" " << std::setw (width) << m[1][0] <<
			" " << std::setw (width) << m[1][1] <<
			" " << std::setw (width) << m[1][2] <<
			" " << std::setw (width) << m[1][3] << "\n" <<

			" " << std::setw (width) << m[2][0] <<
			" " << std::setw (width) << m[2][1] <<
			" " << std::setw (width) << m[2][2] <<
			" " << std::setw (width) << m[2][3] << "\n" <<

			" " << std::setw (width) << m[3][0] <<
			" " << std::setw (width) << m[3][1] <<
			" " << std::setw (width) << m[3][2] <<
			" " << std::setw (width) << m[3][3] << ")\n";

			s.flags (oldFlags);
			return s; 
		}
	};

	// TYPEDEFs
	typedef Matrix44<float> Matrix44f;

}
