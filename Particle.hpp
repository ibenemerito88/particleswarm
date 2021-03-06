#include <iostream>
using std::cout;
using std::cin;

class Particle
{
public:
	// Constructor initialises properties of the particle
	// Use default constructor

	void setValues(int dim, float parameters[3], float X, float V, float P)
	{
		setD(dim);
		setW(parameters[0]);
		setC1(parameters[1]);
		setC2(parameters[2]);
		setX(X);
		setV(V);
		setP(P);
	//	setAverage(X);
	//	setStd(X);
	}

	void setD( float dim)
	{
		D = dim;
	}

	void setW( float number)
	{
		w = number;
	}

	void setC1( float C1)
	{
		c1 = C1;
	}

	void setC2(float C2)
	{
		c2 = C2;
	}

	void setX(float X) // Set initial position
	{ 
		x = X;
	}

	void updateX(float V)
	{
		x += V;
	}

	void setV(float V) // Set velocity
	{
		v = V;
	}

	void setP(float P)
	{
		p = P;
	}

	float getW()
	{
		return w;
	}

	float getC1()
	{
		return c1;
	}

	float getC2()
	{
		return c2;
	}

	float getX()
	{
		return x;
	}

	float getV()
	{
		return v;
	}

	float getP() // Personal best
	{
		return p;
	}

//	float getMean()
//	{
//		return avg;
//	}

//	float getStd()
//	{
//		return std;
//	}

//	float setAverage(float arr[], int size) 
//	{
//		int i, sum = 0;
//		float avg;
//		for (i = 0; i < size; ++i) 
//		{
//		  	sum += arr[i];
//	     	}
//	     	avg = double(sum) / size;
//	     	return avg;
//	}

//	float setStd(float arr[], int size)
//	{
//		int i, std = 0;
//		float std;
//		for (i=0; i<size; i++)
//			std += pow(arr[i]-getMean(),2);
//		return std/size;
//	}


private:
	int D; // Dimension
	float w; // Inertial weight
	float c1; // First constant
	float c2; // Second constant
	float x;
	float v;
	float p;
// 	float avg;
//	float std;
	//	float best_position;
};
