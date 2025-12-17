/******************************************************************************
Write a program for Iterative and Recursive Binary Search and verify the time complexity. 
Write a program to perform quick/merge sort using Divide and Conquer strategy and verify the time complexity.
*******************************************************************************/

#include <iostream>
#include<stdlib.h>
#define MAX 10
using namespace std;

class MobileUser{
    long int mobileno;
    string name;
    long int billamount;
    public:
        MobileUser(){
            mobileno = 0;
            name = "-";
            billamount = 0;
        }
        friend class Records;
};

class Records{
    MobileUser M[10];
    int n;
    public:
        Records(int n1){
            n = n1;
        }
        void accept();
        void display();
        int linear_search(long int key);
        int nonrec_binary_search(long int key);
        int rec_binary_search(long int key, int low, int high);
        int partition(int low,int high);
        void rec_quick(int low,int high);
        void adjust(int n, int i);
        void heapsort();
};


void Records :: accept(){
    cout<<"Enter the Mobile number, Name and Bill amount for n users "<<n<<endl;
    for(int i = 0; i < n; i++)
        cin>>M[i].mobileno>>M[i].name>>M[i].billamount;
}

void Records :: display(){
    cout<<"\nMobile No.\tName\tBill Amount"<<endl;
    for(int i = 0; i < n; i++){
        cout<<M[i].mobileno<<"\t"<<M[i].name<<"\t"<<M[i].billamount<<endl;
    }
}

int Records :: linear_search(long int key){
    for(int i = 0; i < n ; i++){
        if(key == M[i].mobileno){
            cout<<"\nMobile No.\tName\tBill Amount"<<endl;
            cout<<M[i].mobileno<<"\t"<<M[i].name<<"\t"<<M[i].billamount<<endl;
            return i;
        }
    }
    return -1;
}

int Records :: rec_binary_search(long int key, int low, int high){
    int mid;
    mid = (low + high)/2;
    if(low <= high){
        if(key == M[mid].mobileno){
            cout<<"\nMobile No.\tName\tBill Amount"<<endl;
            cout<<M[mid].mobileno<<"\t"<<M[mid].name<<"\t"<<M[mid].billamount<<endl;
            return mid;
        }
        else if(key > M[mid].mobileno)
            return rec_binary_search(key, low, mid - 1);
        else
            return rec_binary_search(key, mid + 1, high);
    }
    return -1;
}

int Records :: nonrec_binary_search(long int key){
    int mid, low = 0, high = n - 1;
    while(low <= high){
        mid = (low + high)/2;
        if(key == M[mid].mobileno){
            cout<<"\nMobile No.\tName\tBill Amount"<<endl;
            cout<<M[mid].mobileno<<"\t"<<M[mid].name<<"\t"<<M[mid].billamount<<endl;
            return mid;
        }
        else if(key > M[mid].mobileno)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int Records :: partition(int low,int high){
	int i,j;
	long int piv = M[high].mobileno;
	MobileUser temp;
	i = low - 1;
	for(j = low; j <= (high - 1); j++){
		if(M[j].mobileno >= piv){
			i++;
    		temp = M[i];
    		M[i] = M[j];
    		M[j] = temp;
		}
	}//end of for
	temp = M[i + 1];
	M[i + 1] = M[j];
	M[j] = temp;
	return i + 1;
}//end of partition

void Records :: rec_quick(int low,int high){
	int j = 0;
	if(low < high)
	{
		j = partition(low, high);
		rec_quick(low,j - 1);//for first array
		rec_quick(j + 1,high);//for 2nd array
	}//end of if
}//end of quick sort

void Records :: adjust(int n1, int i){
    int j;
    MobileUser temp;
    while((2 * i + 1) <= n1){
        j = 2 * i + 1;
        if((j + 1 <= n1) && (M[j+1].billamount > M[j].billamount))
            j++;
        if(M[i].billamount >= M[j].billamount)
            break;
        else{
            temp = M[i];
            M[i] = M[j];
            M[j] = temp;
            i = j;
        }
    }
}

void Records :: heapsort(){
    int i,n1 = n;
    MobileUser temp;
    for(i = (n1/2)-1; i >= 0; i--)
        adjust(n1-1, i);
    
    
    while(n1 > 0){
        temp = M[0];
        M[0] = M[n1-1];
        M[n1-1] = temp;
        n1--;
        adjust(n1-1,0);
    }
}

int main(){
    
    int n;
    
    int index,ch;
    long int key;
    
    while(1){
        cout<<"\n1. Linear Search";
        cout<<"\n2. Recursive Binary Search";
        cout<<"\n3. Non-Recursive Binary Search";
        cout<<"\n4. Heap Sort";
        cout<<"\n5. Exit";
        cout<<"\nEnter your choice ";
        cin>>ch;
        
        if(ch == 5)
            exit(0);
        
        cout<<"Enter the number of records ";
        cin>>n;
        
        Records r(n);
        r.accept();
        r.display();
        
        switch(ch){
            case 1:
                    cout << "\nEnter the Mobile Number to be searched ";
                    cin >> key;
                    index = r.linear_search(key);
                    if(index != -1)
                        cout << "The " << key << " found at an index " << index;
                    else
                        cout << "The " << key << " does not exist";
                    break;
                    
            case 2:
                    r.rec_quick(0, n - 1);
                    cout<<"\nRecords are sorted using Quicksort method"<<endl;
                    r.display();
                    
                    cout << "\nEnter the mobile number to be searched ";
                    cin >> key;
                    index = r.rec_binary_search(key, 0, n - 1);
                    if(index != -1)
                        cout << "The " << key << " found at an index " << index;
                    else
                        cout << "The " << key << " does not exist";
                    break;
                    
            case 3:
                    r.rec_quick(0, n - 1);
                    cout<<"\nRecords are sorted using Quicksort method"<<endl;
                    r.display();
                    
                    cout << "\nEnter the mobile number to be searched ";
                    cin >> key;
                    index = r.nonrec_binary_search(key);
                    if(index != -1)
                        cout << "The " << key << " found at an index " << index;
                    else
                        cout << "The " << key << " does not exist";
                    break;
                    
            case 4:
                    r.heapsort();
                    cout<<"\nRecords are sorted using Heap sort method"<<endl;
                    r.display();               
                    break;
                    
            default:
                    cout<<"\n Invalid choice";
        }
    }
    return 0;
}