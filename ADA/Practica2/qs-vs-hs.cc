//Juan Andrés Orocondo Álvarez 20993208G
/*
ADA. 2022-23
Práctica 2:"Empirical analysis by means of program-steps account of two sorting algorithms: Middle-Quicksort and Heapsort."
*/
#include <unistd.h>
#include <iostream>
#include <math.h>


using namespace std;

double pasos=0;

//--------------------------------------------------------------
// Middle Quick Sort
void middle_QuickSort(int * v, long left, long right){
	if (left<right){
	    long i=left; 
        long j=right;
		int pivot=v[(i+j)/2];
		do {
            while (v[i]<pivot) {i++;pasos++;}
            while (v[j]>pivot) {j--;pasos++;}
            if (i<=j){ 
                swap(v[i], v[j]);
                i++; j--;
            }
            pasos++;
        } while (i<=j);
        if (left < j)  middle_QuickSort(v,left,j);
        if (i < right) middle_QuickSort(v,i,right);
    }


}

//--------------------------------------------------------------                
//HEAPSORT
// Procedure sink used by Heapsort algorith
// Sink an element (indexed by i) in a tree to keep the heap property. n is the size of the heap. 

void sink(int *v, size_t n, size_t i) {
    do {
        pasos++;
        size_t largest = i;  // Initialize largest as root
        size_t l = 2*i + 1;  // left = 2*i + 1
        size_t r = 2*i + 2;  // right = 2*i + 2
 
    // Is left child larger than root?
        if (l < n && v[l] > v[largest])
            largest = l;
 
    // Is right child larger than largest so far
        if (r < n && v[r] > v[largest])
            largest = r;
 
    // If largest is still root then the process is done
        if (largest == i) break;
    
	// If not, swap new largest with current node i and repeat the process with childs. 
        swap(v[i], v[largest]);
        i=largest;
     } while (true);
}
 
//--------------------------------------------------------------                
// Heapsort algorithm (ascending sorting)
void heapSort(int *v, size_t n) {
    if( n < 2 ) // nothing to do
        return;

    // Build a MAX-HEAP with the input array
    for (size_t i = n / 2 - 1; true; i--) {
        sink(v, n, i);

        if (i==0) break; //as size_t is unsigned type
	}	

  	// A this point we have a HEAP on the input array, let's take advantage of this to sort the array:
    // One by swap the first element, which is the largest (max-heap), with the last element of the vector and rebuild heap by sinking the new placed element on the begin of vector.  
    for (size_t i=n-1; i>0; i--) {
		// Move current root to the end.
        swap(v[0], v[i]);
 		// Now largest element is at the end but do not know if the element just moved to the beginning is well placed, so a sink process is required.
		// Note that, at the same time, the HEAP size is reduced one element by one.
        sink(v, i, 0);
		// The procedure ends when HEAP has only one element, the lower of the input array
    }
}

int main(){

       srand(0);

    cout << "# QUICKSORT VERSUS HEAPSORT"
		<< endl
		<< "# Average processing Msteps (millions of program steps)"
        << endl
        << "# Number of samples (arrays of integer): 30"
        << endl
        << "# \t\t RANDOM ARRAYS \t\t SORTED ARRAYS \t\t REVERSE SORTED ARRAYS"
        << endl
        << "# Size \t QuickSort \t HeapSort \t QuickSort \t HeapSort \t QuickSort \t HeapSort"
        << endl
        << "# ======================================================================================================="
        << endl;

    for (int exp = 15; exp <= 20; exp++){
    size_t size = size_t( pow(2,exp) );
    int* v = new int [size];
    int* v1 = new int [size];
    int* v2 = new int [size];
    if (!v){
        cerr << "Error, not enough memory!" << endl;
        exit (EXIT_FAILURE);
    }

    cout << size << "\t\t" << std::flush;

    for(int i=0;i<30;i++){
        for (size_t j = 0; j < size; j++) 
            v[j] = rand(); 

        middle_QuickSort(v,0,size-1);

    }

    cout << (pasos/1000000)/30;
    cout << "   \t";
    pasos=0;

    for(int i=0;i<30;i++){
        for (size_t j = 0; j < size; j++) 
            v[j] = rand(); 

        heapSort(v,size);
    }

    cout << (pasos/1000000)/30;
    cout << "   \t";
    pasos=0;

    for(size_t i=0;i<size;i++){
        v1[i]=i;
    }

    middle_QuickSort(v1,0,size-1);
    cout << (pasos/1000000) << "   \t";
    pasos=0;

    heapSort(v1,size);
    cout<< (pasos/1000000) << "   \t";
    pasos=0;

    for(size_t i=0;i<size;i++){
        v2[i] = (size - 1) - i; 
    }

    middle_QuickSort(v2,0,size-1);
    cout << (pasos/1000000) << "   \t";
    pasos=0;


    for(size_t i=0;i<size;i++){
        v2[i] = (size - 1) - i; 
    }

    heapSort(v2,size);
    cout<< (pasos/1000000) << endl;

    for (size_t i = 1; i < size; i++)
        if (v[i] < v[i-1]){ 
            cerr << "Panic, array not sorted! " << i << endl; 
            exit(EXIT_FAILURE);            
        }

    for (size_t i = 1; i < size; i++)
        if (v1[i] < v1[i-1]){ 
            cerr << "Panic, array not sorted! " << i << endl; 
            exit(EXIT_FAILURE);            
        }

    for (size_t i = 1; i < size; i++)
        if (v2[i] < v2[i-1]){ 
            cerr << "Panic, array not sorted! " << i << endl; 
            exit(EXIT_FAILURE);            
        }

    delete[] v; 
    }

}


