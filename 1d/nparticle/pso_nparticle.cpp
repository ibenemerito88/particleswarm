#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using std::cout;
using std::endl;
using std::rand;

#include "Particle.hpp"

float randnum()
{
	srand(time(NULL));
	float r = ((float) rand()) / (float) RAND_MAX;
	return r;
}

float randint(float a, float b)
{
	float r = a + randnum()*(b - a);
	return r;
}

float evalF(float x, float e)
{
//	return pow(x,e);
return pow(x,4)+2*pow(x,3)-12*pow(x,2)-2*x+6;
	//return sin(x);
}


int main()
{
	// Set domain
	float domain[2] = {-5,5};
	// Set parameters
	float parameters[3] = {0.7298, 1.49618, 1.49618};
	float x = randint(domain[0],domain[1]);
	float vina = -fabs(domain[1]-domain[0]);
	float vinb = -vina;
	float v = vina + randint(0,1)*(vinb-vina);
	float e = 2; // Polynomial exponent
	// Set number of particles
	int N = 1000;


	// Constructor: array of objects
	Particle p[N];
	// Initialise particles: the best individual position is initialised
	// to the initial position
	for( int i = 0; i<N; i++)
	{
		p[i].setValues(parameters,x,v,x);
	}


	// Check and set global best g
	// Generate random best position
	float g = randint(domain[0],domain[1]);
	// Check if g is the best
	for( int i=0; i<N; i++)
	{
		if (evalF(g,e)>evalF(p[i].getP(),e))
		g = p[i].getX();
	}

	// Begin solution 
	for (int i = 1; i<=5000; i++)
	{
	// Cycle on particles
	for (int j = 0; j<N; j++)
	{
		// Generate random numbers for the j-th particle
		float r1 = randint(0,1);
		float r2 = randint(0,1);

		// Update velocity of j-th particle
		p[j].setV(p[j].getW()*p[j].getV()+r1*p[j].getC1()*(p[j].getP()-p[j].getX()) + r2*p[j].getC2()*(g - p[j].getX()));
		// Update position of j-th particle
		p[j].updateX(p[j].getV());
	
		// Update personal best of j-th particle
		if (evalF(p[j].getP(),e)>evalF(p[j].getX(),e))
		p[j].setP(p[j].getX());

		// Update global best
		if (evalF(g,e)>evalF(p[j].getP(),e))
		{
			g = p[j].getX();
			cout<<"Change g"<<endl;
		}

		// Constrain inside the box
		if (p[j].getX()>domain[1])
		{
			p[j].setX(domain[1]);
			p[j].setV(0);
		}
		if (p[j].getX()<domain[0])
		{
			p[j].setX(domain[0]);
			p[j].setV(0);
		}

	}
	
	
//cout<<" x = "<<p[1].getX()<<endl;
//cout<<" v = "<<p[1].getV()<<endl;
//cout<<" g = "<<g<<endl;

	}

float m = 0;
for (int i=0; i<N;i++)
{
	m+=p[i].getX();
}
m=m/N;

cout<<"Estimated minimum at x = "<<m<<endl;
cout<<"Value at minimum = "<<evalF(m,e)<<endl;
cout<<g<<endl;

	return 0;




}
