#include <iostream>

using namespace std;
	
int binSrch(int *arr, int find, int lo, int mid, int hi){

	if(lo <= hi || arr[mid] == find){
		//cout << "current mid: " << arr[mid] << "\n";
		if (arr[mid] == find)
			return mid;
		else if(arr[mid] > find){
			//cout << "lo:" << lo << " mid: " << mid << " hi" << hi << "\n";     
			return binSrch(arr, find, lo, ((mid+lo-1)/2), mid-1);
		}
		else if(arr[mid] < find)
			//cout << "lo:" << lo << " mid: " << mid << " hi" << hi << "\n";    
			return binSrch(arr, find, mid+1, (hi+mid+1)/2, hi);
	    return -1;
	}
	else return -1;

}

int main(){
	
// int *arrX; 
// int *arrY

int arx[6] = {0, 3, 5 , 7, 12, 44};
int ary[7] = {4, 55, 66, 77, 88, 99, 111};
//cout << arx[2] << " : 5 test \n";
int* arxx = arx;
int* aryy = ary;
//cout << arxx[2] << " : 5 test 2 \n";



cout << "First test srch even arr for found # lower half: (2) " << binSrch(arxx, 5, 0, 3, 5) << "\n";
cout << "Second test srch even arr for found # upper half: (5) " << binSrch(arxx, 44, 0, 3, 5)<< "\n";
cout << "Third test srch even arr for not found # hi: (-1) " << binSrch(arxx, 59, 0, 3, 5)<< "\n";
cout << "\n";
cout << "First test srch odd arr for found # lower half: (0) " << binSrch(aryy, 4, 0, 3, 6)<< "\n";
cout << "Second test srch odd arr for found # lower half: (1) " << binSrch(aryy, 55, 0, 3, 6)<< "\n";
cout << "Third test srch odd arr for not found #: (-1) " << binSrch(aryy, 59, 0, 3, 6)<< "\n";
cout << "Fourth test srch odd arr for found # upper half: (4) " << binSrch(aryy, 88, 0, 3, 6)<< "\n";

}