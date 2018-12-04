#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using std::cout;
using std::endl;
using std::rand;

float evalF(float x[2], float e)
{
	return pow(x[0],e)+pow(x[1],e);
}



float getMean(float arr[], int size) {
  int i, sum = 0;       
  float avg;          

   for (i = 0; i < size; ++i) {
      sum += arr[i];
   }
   avg = float(sum) / size;

   return avg;
}


int main()
{
	int D = 5;
	float e = 2;
	float g[D] = {1,2,3,4,5};
//	cout<<evalF(g,e)<<endl;

	float x[2] = {1,2};
	cout<<getMean(g,D)<<endl;





	return 0;
}

