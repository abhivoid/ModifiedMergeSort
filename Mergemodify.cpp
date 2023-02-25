#include <bits/stdc++.h>
#include <fstream>
using namespace std;
void merge(int array[], int const left, int const mid,
           int const right)
{
    int subArrayOne = mid - left + 1;
   int subArrayTwo = right - mid;
 
    
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
 
    
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    int indexOfSubArrayOne
        = 0, 
        indexOfSubArrayTwo
        = 0; 
    int indexOfMergedArray
        = left; 
    
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
         else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
   
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively
 
    int mid =(end - begin) / 4;
    int x=begin+mid;
    mergeSort(array, begin, x);
    mergeSort(array, x + 1, x+mid);
    mergeSort(array, x + 1+mid, x+mid+mid);
    mergeSort(array, x +1+mid+mid,end);
    merge(array, begin, x, x+mid);
    merge(array, x+1+mid, x+mid+mid, end);
    merge(array, begin, x+mid, end);
    
}
//void merge(int* a,int l,int n)
//{
//	if(n>l)
//	{
//		int i,b,c,x,t;
//		x=n+(n-l)/2;
//		merge(a,l,x);
//		merge(a,x+1,n);
//		int f[x-l+1],d[n-x];
//		b=0;
//		for(i=l;i<=x;i++)
//		{
//			f[b]=a[i];
//			b++;
//			
//		}
//		
//		c=0;
//		for(i=x+1;i<=n;i++)
//		{
//			d[c]=a[i];
//			c++;
//		}
//		b=0;
//		c=0;
//		for(i=l;i<=n;i++)
//		{
//			if(b>(x-l+1))
//			{
//				a[i]=d[c];
//				c++;
//				
//			}
//			else if(c>(n-x))
//			{
//				a[i]=f[b];
//				b++;
//			}
//			else
//			{
//				if(f[b]>d[c])
//				{
//				a[i]=d[c];
//				c++;	
//				}
//				else
//				{
//					a[i]=f[b];
//				b++;
//				}
//			}
//		}
//	}
//	
//}

int main()
{
	int i,j,c,n=5000;
	int m[n];
	fstream f;
	f.open("1k.txt");
	
	for(i=0;i<n;i++)
	{
		f>>m[i];
	}
	mergeSort(m,0,n-1);
	cout<<"Sorted:\n";
	for(i=0;i<n;i++)
	cout<<m[i]<<endl;
}
