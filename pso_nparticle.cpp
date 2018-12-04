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
// Do it with pointers as inputs
//return  pow(x[0],e)+pow(x[1],e);
//	return pow(x,e);
 	return pow(x,4)+2*pow(x,3)-12*pow(x,2)-2*x+6;
	//return sin(x);
}


int main()
{

	// Set parameters
	// w, c1, c2
	float parameters[3] = {0.7298, 1.49618, 1.49618};
	// Set number of particles
	int N = 100;
	//Set dimension
	int D = 1;
	//Set domain 
	float domain[2] = {-5,5};
	// Initial estimate
//	float x = randint(domain[0],domain[1]);
	// Initial velocity
	float vina = -fabs(domain[1]-domain[0]);
	float vinb = -vina;
//	float v = vina + randint(0,1)*(vinb-vina);
	// Polynomial exponent
	float e = 2; 

	// Constructor: array of objects through default constructor
	Particle p[N][D];
	// Initialise particles: the best individual position is initialised
	// to the initial position
	//
	// Each particle has a D-dimensional position, velocity and guess
	for( int j = 0; j<N; j++)
	{
		
		// Iterate over the dimensions to set the initial values
		for( int k = 0; k<D; k++)
		{
			// Generate initial estimate in the k-th dimension
			float x = randint(domain[0],domain[1]);
			// Generate initial velocity in the k-th dimension
			float v = vina + randint(0,1)*(vinb-vina);
			// Initialise k-th dimension of the j-th particle
			p[j][k].setValues(D,parameters,x,v,x);

			// Unefficient because it sets the constants D time for each particle
			// but they only must be defined once per particle
		}
	}


	// Check and set global best g
	// Generate random  D-dimensional best position
	float g[D];
       	for(int k=0; k<D; k++)
	       g[k]=randint(domain[0],domain[1]);

	// Check if g is the best
	for( int j=0; j<N; j++)
	{
		for (int k=0; k<D; k++)
		{
			if (evalF(g[k],e)>evalF(p[j][k].getP(),e))
				g[k] = p[j][k].getP();
		}
	}

	int iteration = 0;
	// Begin solution 
	for (int i = 0; i<=5000; i++)
	{
	// Cycle on particles
	for (int j = 0; j<N; j++)
	{
		for (int k = 0; k<D; k++)
		{
		// Generate random numbers for the j-th particle
		float r1 = randint(0,1);
		float r2 = randint(0,1);
		
		// Update velocity of j-th particle
		p[j][k].setV(p[j][k].getW()*p[j][k].getV()+r1*p[j][k].getC1()*(p[j][k].getP()-p[j][k].getX()) + r2*p[j][k].getC2()*(g[k] - p[j][k].getX()));
		// Update position of j-th particle
		p[j][k].updateX(p[j][k].getV());

		// Constrain inside the box
		if (p[j][k].getX()>domain[1])
		{
			p[j][k].setX(domain[1]);
			p[j][k].setV(0);
		}
		if (p[j][k].getX()<domain[0])
		{
			p[j][k].setX(domain[0]);
			p[j][k].setV(0);
		}

		
		// Update personal best of j-th particle
		if (evalF(p[j][k].getP(),e)>evalF(p[j][k].getX(),e))
		p[j][k].setP(p[j][k].getX());
		
		// Update global best
		if (evalF(g[k],e)>evalF(p[j][k].getP(),e))
			g[k] = p[j][k].getP();

		}
		}
	iteration++;
	}

//float m = 0;
//for (int i=0; i<N;i++)
//{
//	m+=p[i].getX();
//}
//m=m/N;

//cout<<"Estimated minimum at x = "<<m<<endl;
//cout<<"Value at minimum = "<<evalF(m,e)<<endl;
//cout<<g<<endl;

for (int j=0;j<N;j++)
	cout<<"j = "<<j+1<<" - x(j) = "<<p[j][1].getX()<<" - f(xj) = "<<evalF(p[j][1].getX(),e)<<endl;

	return 0;




}
