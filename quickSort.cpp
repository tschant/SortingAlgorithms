#include <cstdlib>
using namespace std;

template <class T>
int swap(T* A, T* B)
{
	//swap algorithm
	T temp;
	temp = A;
	A = B;
	B = temp;
}

//recursive function for quick sort
template <class T>
void partition(T A[], int first, int last)
{
	//needs to be at least 2 elements
	//and first needs to be less than last
	if(first==last || first >= last) 
		return;

	int lastS1 = first;
	
	//use the middle value of the array as pivot
	int middle = (first + last) / 2; 

	//select a random pivot point within the range
	//simple random number generator based on first number within the list
	//int middle = ((3 * A[first] + 2) % (last - first)) + first;
	//if(middle < first || middle > last)
	//	{ cout<<"middle not a valid number " << middle << endl; return;}
	
	T pivot = A[middle];
	swap(A[middle], A[first]); 
	//temp var for first unknown
	int firstUn = first + 1;
	
	while(firstUn <= last){
		if(A[firstUn] < pivot)
		{
			lastS1++;
			swap(A[firstUn], A[lastS1]);
		}
		firstUn++;
	}
	//move the pivot into correct place
	swap(A[first],A[lastS1]);
	
	//sort the first half of the list (recursively)
	partition(A, first, lastS1-1);
	//sort the second half of the list (recursively)
	partition(A, lastS1+1, last); 
}


template <class T>
void quickSort(T a[], int n)
{
	//used to start sorting process
	partition(a, 0, n);

	//for debugging
	//for(int i = 0; i < n; i++)
	//{
	//	cout << a[i] << " ";
	//}
	//cout << endl;
}
