/******************************************************************************
Write a program for Iterative and Recursive Binary Search and verify the time complexity. 
Write a program to perform quick/merge sort using Divide and Conquer strategy and verify the time complexity.
*******************************************************************************/

/*
1.	Accept Mobile user information (e.g. MobileNo, Name, BillAmount etc.).
a.	Display the data in descending order of MobileNo. (Quick Sort) 
b.	Display the data in ascending order of MobileNo. (Merge Sort) 
c.	Display details for Mobileno specified by user (Linear Search and Recursive and Non-recursive Binary Search)
d.	Display the number of passes and comparisons for different test cases (Worst, Average, Best case).
*/

#include <iostream>
#include<stdlib.h>
#define MAX 10
using namespace std;

struct stack
{

	int a, b;
}s[MAX];

int top=-1;

int isempty()
{
	if(top == -1)
		return 1;
	else
		return 0;
}//end of isempty

int isfull()
{
	if(top == MAX)
		return 1;
	else
		return 0;
}//end of isfull

void push(int x, int y)
{
	if(isfull() == 1 )
	{
		printf("\n Stack is full !");
	}//end of if
	else
	{
		top++;
		s[top].a=x;
		s[top].b=y;
	}//end of else
}//end of push
void pop(int *x, int *y)
{
	if(isempty() == 1 )
	{
		printf("\n Stack is empty !");
	}//end of if
	else
	{
		*x=s[top].a;
		*y=s[top].b;
		top--;
	}//end of else
}//end of pop

void accept(int a[10], int n){
    cout<<"Enter the "<<n<<" numbers ";
    for(int i = 0; i < n; i++)
        cin>>a[i];
}

void display(int a[10], int n){
    for(int i = 0; i < n; i++)
        cout << a[i] << "\t";
}

int linear_search(int a[10],int n, int key){
    for(int i = 0; i < n ; i++){
        if(key == a[i]){
            return i;
        }
    }
    return -1;
}

int nonrec_binary_search(int a[10],int n, int key){
    int mid, low = 0, high = n - 1;
    while(low <= high){
        mid = (low + high)/2;
        if(key == a[mid]){
            return mid;
        }
        else if(key < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int rec_binary_search(int a[10], int key, int low, int high){
    int mid;
    mid = (low + high)/2;
    if(low <= high){
        if(key == a[mid])
            return mid;
        else if(key < a[mid])
            return rec_binary_search(a, key, low, mid - 1);
        else
            return rec_binary_search(a, key, mid + 1, high);
    }
    return -1;
}

int partition(int a[10], int low,int high)
{
	int piv,i,j,temp;
	piv=a[low];
	i=low+1;
	j=high;
	while(1)
	{
		while(a[i] <= piv && i<high)
			i++;
		while(a[j] >= piv && j>low)
			j--;
		if(i<j){
		    temp = a[i];
		    a[i] = a[j];
		    a[j] = temp;
		}
		else
			break;
	}//end of while
	temp = a[low];
	a[low] = a[j];
	a[j] = temp;
	return j;
}//end of partition

void rec_quick(int a[10], int low,int high)
{
	int j = 0;
	if(low < high)
	{
		j = partition(a, low, high);
		rec_quick(a, low,j-1);//for first array
		rec_quick(a,j+1,high);//for 2nd array
	}//end of if
}//end of quick sort

void non_rec_quick(int a[10], int low ,int high)
{
	int j=0;
	push(low ,high);
	while(! isempty())
	{
		pop(&low , &high);
		while(low < high)
		{
			j = partition(a, low ,high);
			push(j+1,high);
			high=j-1;
		}//end of inner while
	}//end of while
}//end of non rec quick sort

void merge(int a[10], int low, int mid, int high){
    int h = low, i = low, j = mid + 1, b[10],k;
    while((h <= mid) && (j <= high)){
        if(a[h] <= a[j]){
            b[i] = a[h];
            h++;
        }
        else{
            b[i] = a[j];
            j++;
        }
        i++;
    }
    if(h > mid)
        for(k = j; k <= high; k++){
            b[i] = a[k];
            i++;
        }
    else
        for(k = h; k <= mid; k++){
            b[i] = a[k];
            i++;
        }
    for(k = low; k <= high; k++)
        a[k] = b[k];
}

void mergeSort(int arr[10], int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main()
{
    int a[10],key,n,index,ch;
    
    while(1){
        cout<<"\n1. Linear Search";
        cout<<"\n2. Recursive Binary Search";
        cout<<"\n3. Non-Recursive Binary Search";
        cout<<"\n4. Recursive Quicksort";
        cout<<"\n5. Non-Recursive Quicksort";
        cout<<"\n6. MergeSort";
        cout<<"\n7. Exit";
        cout<<"\nEnter your choice ";
        cin>>ch;
        switch(ch){
            case 1:
                    cout<<"Enter the total numbers ";
                    cin>>n;
            
                    accept(a,n);
                    cout<<"Entered "<<n<<" numbers are ";
                    display(a,n);
            
                    cout << "\nEnter the key to be searched using linear search method ";
                    cin >> key;
                    index = linear_search(a,n,key);
                    if(index != -1)
                        cout << "The " << key << " found at an index " << index;
                    else
                        cout << "The " << key << " does not exist";
                    break;
                    
            case 2:
                    cout<<"Enter the total numbers ";
                    cin>>n;
            
                    accept(a,n);
                    cout<<"Entered "<<n<<" numbers are ";
                    display(a,n);
                    
                    rec_quick(a, 0, n - 1);
                    cout<<"\nNumbers are sorted using Recursive Quicksort method"<<endl;
                    display(a,n);
                    
                    cout << "\nEnter the key to be searched using recursive binary search method ";
                    cin >> key;
                    index = rec_binary_search(a,key, 0, n - 1);
                    if(index != -1)
                        cout << "The " << key << " found at an index " << index;
                    else
                        cout << "The " << key << " does not exist";
                    break;
                    
            case 3:
                    cout<<"Enter the total numbers ";
                    cin>>n;
            
                    accept(a,n);
                    cout<<"Entered "<<n<<" numbers are ";
                    display(a,n);
                    
                    non_rec_quick(a, 0, n - 1);
                    cout<<"\nNumbers are sorted using Non-Recursive Quicksort method"<<endl;
                    display(a,n);
                    
                    cout << "\nEnter the key to be searched using non recursive binary search method ";
                    cin >> key;
                    index = nonrec_binary_search(a,n,key);
                    if(index != -1)
                        cout << "The " << key << " found at an index " << index;
                    else
                        cout << "The " << key << " does not exist";
                    break;
                    
            case 4:
                    cout<<"Enter the total numbers ";
                    cin>>n;
            
                    accept(a,n);
                    cout<<"Entered "<<n<<" numbers are ";
                    display(a,n);
                    
                    rec_quick(a, 0, n - 1);
                    cout<<"\nNumbers are sorted using Recursive Quicksort method"<<endl;
                    display(a,n);
                    break;
                    
            case 5:
                    cout<<"Enter the total numbers ";
                    cin>>n;
            
                    accept(a,n);
                    cout<<"Entered "<<n<<" numbers are ";
                    display(a,n);
                    
                    non_rec_quick(a, 0, n - 1);
                    cout<<"\nNumbers are sorted using Non-Recursive Quicksort method"<<endl;
                    display(a,n);
                    break;
                    
            case 6:
                    cout<<"Enter the total numbers ";
                    cin>>n;
            
                    accept(a,n);
                    cout<<"Entered "<<n<<" numbers are ";
                    display(a,n);
                    mergeSort(a,0,n-1);
                    cout<<"\nNumbers are sorted using Mergsort method"<<endl;
                    display(a,n);               
                    break;
                    
            case 7:
                    exit(0);
            default:
                    cout<<"\n Invalid choice";
        }
    }
    return 0;
}