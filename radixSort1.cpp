#include <cstdlib>
using namespace std;

//sorts into "buckets"
template <class T>
void radixSort(T a[], int n)
{
	//the array needs at least 2 values
	if(n == 0)
		return;
	//create a temporary array for checking the LSD
	T temp[n];
	//double array for storing vars based on LSD
	T bucket[10][]; 
	//create a copy of a[]
	T *copyA = new T[n];
	copyA = a;

	//can only do this for 4 digit numbers, use 10^iter+1, so 10^2+1=1000
	for(int iter = 0; iter < 3; iter++)
	{
		//TEMP vars for the bucket lists, this also resets it after each run
		int o[10] = {0};
		//go through the list sorting each var into a bucket
	  	for(int i = 0; i < n; i++)
	  	{
	  		//find the LSD
			temp[i] = copyA[i] % 10;
			//check the LSD, and determine the bucket needed
			switch(temp[i])
			{
				//place the current element into a bucket based on the LSD
				case 0:
					bucket[0][o[0]] = a[i];
					//increment the bucket index so no var overwirets the older ones
					o[0]++;
					break;
				case 1:
					bucket[1][o[1]] = a[i];
					o[1]++;
					break;
				case 2:
					bucket[2][o[2]] = a[i];
					o[2]++;
					break;
				case 3:
					bucket[3][o[3]] = a[i];
					o[3]++;
					break;
				case 4:
					bucket[4][o[4]] = a[i];
					o[4]++;
					break;
				case 5:
					bucket[5][o[5]] = a[i];
					o[5]++;
					break;
				case 6:
					bucket[6][o[6]] = a[i];
					o[6]++;
					break;
				case 7:
					bucket[7][o[7]] = a[i];
					o[7]++;
					break;
				case 8:
					bucket[8][o[8]] = a[i];
					o[8]++;
					break;
				case 9:
					bucket[9][o[9]] = a[i];
					o[9]++;
					break;
				default:
					//unknown integer
					cout<<"Unknown value";
					break;
			}
	   	}
	   	//empty the bucket back into the original list and copy list
	   	//locaction in the main array, while sorting back
	   	int loc = 0;
	   	for(int index = 0; index < 10; index++)
	   	{
	   		int bIndex = 0;
	   		while(o[index] >= bIndex)
	   		{
	   			copyA[loc] = bucket[index][bIndex];
	   			a[loc] = bucket[index][bIndex];
	   			//divide the copy array by 10 to the power of the number of iterations (10=0 iter, 100=1 iter,  1000=2 iter)
	   			copyA[loc] = copyA[loc] / 10^(iter + 1);
	   			bIndex++;
	   			//after an element is placed back increment the location (no overlapping)
	   			loc++;
	   		} 
	   	}
	}
	delete [] copyA;

	//for debugging
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
