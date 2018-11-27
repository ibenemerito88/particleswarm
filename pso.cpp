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
	return pow(x,e);
}

int main()
{
	// Set domain
	float domain[2] = {-32, 115};
	// Set parameters
	float parameters[3] = {0.7298, 1.49618, 1.49618};
	float x = randint(domain[0],domain[1]);
	float vina = -fabs(domain[1]-domain[0]);
	float vinb = -vina;
	float v = vina + randint(0,1)*(vinb-vina);
	float e = 2; // Polynomial exponent


	Particle p1(parameters,x,v,x); // The best position is initialised to the initial position

	// Check and set global best g
	// Generate random best position
	float g = randint(domain[0],domain[1]);
	// Check if g is the best
	if (evalF(g,e)>evalF(p1.getX(),e))
		g = p1.getX();


	for (int i = 1; i<=50000; i++)
	{
		float r1 = randint(0,1);
		float r2 = randint(0,1);

		// Update velocity
		p1.setV(p1.getW()*p1.getV()+r1*p1.getC1()*(p1.getP()-p1.getX()) + r2*p1.getC2()*(g - p1.getX()));
		// Update position
		p1.updateX(p1.getV());
		// Update particle's best position
	if (evalF(p1.getP(),e)>evalF(p1.getX(),e))
		p1.setP(p1.getX());

	// Update global best
	if (evalF(g,e)>evalF(p1.getX(),e))
		g = p1.getX();

	// Constrain inside the box
	if (p1.getX()>domain[1])
	{
		p1.setX(domain[1]);
		p1.setV(0);
	}
	if (p1.getX()<domain[0])
	{
		p1.setX(domain[0]);
		p1.setV(0);
	}
	
	


	}

cout<<p1.getX()<<endl;


















	return 0;




}
