/*
 * Roll no.- 2459
 * Name- Sharvari Sonkusare
 * CNumber- C22019221458
 * Assignment number- 5
 * Problem Statement:Write C++ program to store first year CGPA of students in array. Write
function for sorting array of floating point numbers in ascending/descending order using:
1. Bubble sort or Selection sort
2. Insertion sort
3. Merge sort or Quick sort
 */


#include<iostream>

using namespace std;



class array{
	int size;
	float arr[20];
public:
	array(int n){
		size=n;
	}
	array(){

	}
	void accept(float arr[],int size);
	void display(float arr[],int size);
	void bubbleSort(float arr[], int n);
	void selectionSort(float arr[],int size);
	void merge( int l, int m, int r);
    void insertionSort(float arr[],int size);
	void mergeSort(int l,int r);
	void  quickSort(float arr[], int low, int high);
	float partition (float arr[], int low, int high);


};

void array::accept(float arr[],int size){
		cout<<"Enter the CGPA of student"<<endl;
		for(int i=0; i<size;i++){
			cin>>arr[i];
		}
		cout<<"ACCEPTED";

}

void array:: display(float arr[],int size){
	cout<<"\nThe CGPA in sorted order are : ";
	   for(int i = 0; i<size; i++)
	      cout << arr[i] << "   ";
	   cout << endl;

}



void array::bubbleSort(float arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1]){
           float temp = arr[j];
           arr[j] = arr[j+1];
           arr[j+1] = temp;
        }
}


void array::selectionSort(float arr[],int size) {
   int i, j, min;
   for(i = 0; i<size-1; i++) {
      min = i;                   //get index of minimum data
      for(j = i+1; j<size; j++){
         if(arr[j] < arr[min]){
            min = j;
         }
      }
         float temp;
           temp = arr[i];
           arr[i] = arr[min];
           arr[min] = temp;
   }
   /*cout<<"\nThe sorted array is: ";
   	   for(int i = 0; i<size; i++)
   	      cout << arr[i] << "   ";
   	   cout << endl;*/

}

void array::insertionSort(float arr[],int size)
{
    int i, j;
    float key;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;

  // Move elements of array that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    /*cout<<"\nThe sorted array is: ";
    	   for(int k = 0; k<size; k++)
    	      cout << arr[k] << "   ";
    	   cout << endl;*/
}

// first sub array a[l...m]
//second sub array a[m+1....r]
void array::merge( int l, int m, int r)
{
    int n1 = m - l + 1;    //size of sub array 1
    int n2 = r - m;        //size of sub array 2

    // temporary arrays
    float L[n1], R[n2];

    // Copying data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
    }



    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = l;

    // Merge the temp arrays back into arr[l..r]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copying the remaining elements of L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of of arr to be sorted
void array:: mergeSort(int l,int r){
    if(l>=r){
        return;                          //returns recursively
    }
    int m =l+ (r-l)/2;
    mergeSort(l,m);
    mergeSort(m+1,r);
    merge(l,m,r);
}


/* Here we take last element as pivot, places the pivot element at its correct position in sorted array,
  and places all smaller (smaller than pivot)to left of pivot and all greater elements to right of pivot */
float array:: partition (float arr[], int low, int high)
{
    float pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            //swap
            float t = arr[i];
               arr[i] = arr[j];
               arr[j]= t;
        }
    }
    //swap arr[i+1] and arr[high]
    float c = arr[i+1];
       arr[i+1] = arr[high];
       arr[high]= c;
    return (i + 1);
}

/* arr[] --> Array to be sorted, low --> Starting index, high --> Ending index */
void array:: quickSort(float arr[], int low, int high)
{
    if (low < high)
    {
        // pi is partitioning index
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}






int main()
{
	int size,ch;
	//float cgpa;
	float arr[20];
	array m;
	cout<<"Enter total number of students present: "<<endl;
	cin>>size;
	m.accept(arr, size);



	do{
	cout<<"\n**MENU** \n1. BUBBLE SORT \n2. INSERTION SORT \n3. SELECTION SORT \n4. QUICK SORT \n5. MERGE SORT \n6.EXIT"<<endl;
	cout<<"Enter a choice: ";
	cin>>ch;

	switch(ch){
	case 1:
		m.bubbleSort(arr,size);
		m.display(arr, size);
		 break;
	case 2:
		m.insertionSort(arr, size);
		m.display(arr, size);
		break;
	case 3:
		m.selectionSort(arr,size);
		m.display(arr, size);
		break;
	case 4:
		m.quickSort(arr, 0, size-1);
		m.display(arr, size);

		break;
	case 5:
			m.mergeSort(0, size-1);
			m.display(arr, size);

			 break;
	case 6:
		break;
	default:
		cout<<"INVALID CHOICE. ENTER OTHER OPTION";
		 break;

	}
	}while(ch!=6);





return 0;

}







/*
 OUTPUT:

Enter total number of students present:
5
Enter the CGPA of student
9.9
8.7
5.7
9.3
7.2
ACCEPTED
**MENU**
1. BUBBLE SORT
2. INSERTION SORT
3. SELECTION SORT
4. QUICK SORT
5. MERGE SORT
6.EXIT
Enter a choice: 1

The CGPA in sorted order are : 5.7   7.2   8.7   9.3   9.9

**MENU**
1. BUBBLE SORT
2. INSERTION SORT
3. SELECTION SORT
4. QUICK SORT
5. MERGE SORT
6.EXIT
Enter a choice: 2

The CGPA in sorted order are : 5.7   7.2   8.7   9.3   9.9

**MENU**
1. BUBBLE SORT
2. INSERTION SORT
3. SELECTION SORT
4. QUICK SORT
5. MERGE SORT
6.EXIT
Enter a choice: 3

The CGPA in sorted order are : 5.7   7.2   8.7   9.3   9.9

**MENU**
1. BUBBLE SORT
2. INSERTION SORT
3. SELECTION SORT
4. QUICK SORT
5. MERGE SORT
6.EXIT
Enter a choice: 4

The CGPA in sorted order are : 5.7   7.2   8.7   9.3   9.9

**MENU**
1. BUBBLE SORT
2. INSERTION SORT
3. SELECTION SORT
4. QUICK SORT
5. MERGE SORT
6.EXIT
Enter a choice: 5

The CGPA in sorted order are : 5.7   7.2   8.7   9.3   9.9

**MENU**
1. BUBBLE SORT
2. INSERTION SORT
3. SELECTION SORT
4. QUICK SORT
5. MERGE SORT
6.EXIT
Enter a choice: 6











 TIME COMPLEXITIES:
 1. BUBBLE SORT=O(N^2)....WORST CASE
 2. DISPLAY= O(N)
 3. SELECTION SORT= O(N^2)
 4. INSERTION SORT= O(N^2)
 5. MERGE SORT =O(n*log(n))
 6. QUICK SORT=O(n*log(n))....FOR AVERAGE CASE


 */






