#include <cstdlib>
using namespace std;


//sorts into "buckets"
template <class T>
void radixSort(T a[], int n)
{
	int o0, o1, o2, o3, o4, o5, o6, o7, o8, o9;
	//default iteration is 4
	int digits = 4;
	//double array for storing vars based on LSD
	T bucket[10][n]; 
	//create a copy of a[]
	T copyA[n];
	//create a temporary array for checking the LSD
	T temp;
	//copy a into another array
	for(int i = 0; i < n; i++)
	{
		copyA[i] = a[i];
		//determine the amount of iterations needed
		//create a temp var to see which has the most digits
		int longDig = 0;
		temp = a[i];
		while(longDig >= 1)
		{
			longDig = longDig / 10;
			digits++;
		}
		//replace the old length if the new one is longer
		if(longDig > digits)
		{
			digits = longDig;
		}
	}

	//execute this for however many digits there are in the variables (takes the longest)
	for(int iter = 0; iter < digits; iter++)
	{
		//TEMP vars for the bucket lists, this also resets it after each run
		o0 = 0;
		o1 = 0;
		o2 = 0;
		o3 = 0;
		o4 = 0;
		o5 = 0;
		o6 = 0;
		o7 = 0;
		o8 = 0;
		o9 = 0;
		//go through the list sorting each var into a bucket
	  	for(int i = 0; i < n; i++)
	  	{
	  		//find the LSD
			temp = copyA[i] % 10;
			//check the LSD, and determine the bucket needed
			switch(temp)
			{
				//place the current element into a bucket based on the LSD
				case 0:
					bucket[0][o0] = a[i];
					//increment the bucket index so no var overwirets the older ones
					o0++;
					break;
				case 1:
					bucket[1][o1] = a[i];
					o1++;
					break;
				case 2:
					bucket[2][o2] = a[i];
					o2++;
					break;
				case 3:
					bucket[3][o3] = a[i];
					o3++;
					break;
				case 4:
					bucket[4][o4] = a[i];
					o4++;
					break;
				case 5:
					bucket[5][o5] = a[i];
					o5++;
					break;
				case 6:
					bucket[6][o6] = a[i];
					o6++;
					break;
				case 7:
					bucket[7][o7] = a[i];
					o7++;
					break;
				case 8:
					bucket[8][o8] = a[i];
					o8++;
					break;
				case 9:
					bucket[9][o9] = a[i];
					o9++;
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
	   	int bIndex = 0;
	   	while(bIndex < o0 && o0 > 0)
	   	{
	   		copyA[loc] = bucket[0][bIndex];
	   		a[loc] = bucket[0][bIndex];
	   		//divide the copy array by 10 to the power of the number of iterations (10=0 iter, 100=1 iter,  1000=2 iter)
	   		copyA[loc] = copyA[loc] / 10^(iter + 1);
	   		bIndex++;
	   		//after an element is placed back increment the location (no overlapping)
	   		loc++;
	   	} 
	   	bIndex = 0;
	   	while(bIndex < o1 && o1 > 0)
	   	{
	   		copyA[loc] = bucket[1][bIndex];
	   		a[loc] = bucket[1][bIndex];
	   		//divide the copy array by 10 to the power of the number of iterations (10=0 iter, 100=1 iter,  1000=2 iter)
	   		copyA[loc] = copyA[loc] / 10^(iter + 1);
	   		bIndex++;
	   		//after an element is placed back increment the location (no overlapping)
	   		loc++;
	   	} 
	   	bIndex = 0;
	   	while(bIndex < o2 && o2 > 0)
	   	{
	   		copyA[loc] = bucket[2][bIndex];
	   		a[loc] = bucket[2][bIndex];
	   		//divide the copy array by 10 to the power of the number of iterations (10=0 iter, 100=1 iter,  1000=2 iter)
	   		copyA[loc] = copyA[loc] / 10^(iter + 1);
	   		bIndex++;
	   		//after an element is placed back increment the location (no overlapping)
	   		loc++;
	   	} 
	   	bIndex = 0;
	   	while(bIndex < o3 && o3 > 0)
	   	{
	   		copyA[loc] = bucket[3][bIndex];
	   		a[loc] = bucket[3][bIndex];
	   		//divide the copy array by 10 to the power of the number of iterations (10=0 iter, 100=1 iter,  1000=2 iter)
	   		copyA[loc] = copyA[loc] / 10^(iter + 1);
	   		bIndex++;
	   		//after an element is placed back increment the location (no overlapping)
	   		loc++;
	   	} 
	   	bIndex = 0;
	   	while(bIndex < o4 && o4 > 0)
	   	{
	   		copyA[loc] = bucket[4][bIndex];
	   		a[loc] = bucket[4][bIndex];
	   		//divide the copy array by 10 to the power of the number of iterations (10=0 iter, 100=1 iter,  1000=2 iter)
	   		copyA[loc] = copyA[loc] / 10^(iter + 1);
	   		bIndex++;
	   		//after an element is placed back increment the location (no overlapping)
	   		loc++;
	   	} 
	   	bIndex = 0;
	   	while(bIndex < o5 && o5 > 0)
	   	{
	   		copyA[loc] = bucket[5][bIndex];
	   		a[loc] = bucket[5][bIndex];
	   		//divide the copy array by 10 to the power of the number of iterations (10=0 iter, 100=1 iter,  1000=2 iter)
	   		copyA[loc] = copyA[loc] / 10^(iter + 1);
	   		bIndex++;
	   		//after an element is placed back increment the location (no overlapping)
	   		loc++;
	   	} 
	   	bIndex = 0;
	   	while(bIndex < o6 && o6 > 0)
	   	{
	   		copyA[loc] = bucket[6][bIndex];
	   		a[loc] = bucket[6][bIndex];
	   		//divide the copy array by 10 to the power of the number of iterations (10=0 iter, 100=1 iter,  1000=2 iter)
	   		copyA[loc] = copyA[loc] / 10^(iter + 1);
	   		bIndex++;
	   		//after an element is placed back increment the location (no overlapping)
	   		loc++;
	   	} 
	   	bIndex = 0;
	   	while(bIndex < o7 && o7 > 0)
	   	{
	   		copyA[loc] = bucket[7][bIndex];
	   		a[loc] = bucket[7][bIndex];
	   		//divide the copy array by 10 to the power of the number of iterations (10=0 iter, 100=1 iter,  1000=2 iter)
	   		copyA[loc] = copyA[loc] / 10^(iter + 1);
	   		bIndex++;
	   		//after an element is placed back increment the location (no overlapping)
	   		loc++;
	   	} 
	   	bIndex = 0;
	   	while(bIndex < o8 && o8 > 0)
	   	{
	   		copyA[loc] = bucket[8][bIndex];
	   		a[loc] = bucket[8][bIndex];
	   		//divide the copy array by 10 to the power of the number of iterations (10=0 iter, 100=1 iter,  1000=2 iter)
	   		copyA[loc] = copyA[loc] / 10^(iter + 1);
	   		bIndex++;
	   		//after an element is placed back increment the location (no overlapping)
	   		loc++;
	   	} 
	   	bIndex = 0;
	   	while(bIndex < o9 && o9 > 0)
	   	{
	   		copyA[loc] = bucket[9][bIndex];
	   		a[loc] = bucket[9][bIndex];
	   		//divide the copy array by 10 to the power of the number of iterations (10=0 iter, 100=1 iter,  1000=2 iter)
	   		copyA[loc] = copyA[loc] / 10^(iter + 1);
	   		bIndex++;
	   		//after an element is placed back increment the location (no overlapping)
	   		loc++;
	   	} 
	}
	//delete [] copyA;
	//copyA = NULL;

	//for debugging
	//for(int i = 0; i < n; i++)
	//{
	//	cout << a[i] << " ";
	//}
	//cout << endl;
}
