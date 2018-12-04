#include <iostream>
using std::cout;
using std::cin;

class Particle
{
public:
	// Constructor initialises properties of the particle
	// Use default constructor
	
	
	
	
	
	
	
	void setValues(float parameters[3], float X, float V, float P)
	{
		setW(parameters[0]);
		setC1(parameters[1]);
		setC2(parameters[2]);
		setX(X);
		setV(V);
		setP(P);
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


private:
	float w; // Inertial weight
	float c1; // First constant
	float c2; // Second constant
	float x;
	float v;
	float p;
	//	float best_position;
};
