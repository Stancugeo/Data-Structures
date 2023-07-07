#include <iostream>
using namespace std;
void Merge(int * v , int start , int mij , int end){
	int temp[end-start+1];
	int i = start;
	int j = mij + 1;
	int newi = 0 ;
	while(i <= mij && j <= end){
		if(v[i] <= v[j]){
			temp[newi] = v[i];
			i++;
			
		}else{
			temp[newi] = v[j];
			j++;

		}
		newi++;

	}
	while(i <= mij){
		temp[newi] = v[i];
		newi++;
		i++;
	}
	while(j <= end){
		temp[newi] = v[j];
		newi++;
		j++;
	}
	for(int i = start ; i <= end ; i++){
		v[i] = temp[i-start];
	}


}
void MergeSort(int * v , int start , int end){
	if(start >= end) return ;
	int mij = (start+end)/2;
	MergeSort(v,start,mij);
	MergeSort(v,mij+1,end);
	Merge(v,start,mij,end);

}
void heapify(int * arr , int n , int i ){
    int largest = i ;
    int left = 2*i + 1 ;
    int right = 2*i + 2 ;
    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void heapSort(int* arr,int n){

    for(int i = n / 2 - 1 ; i >= 0 ; i--){
        heapify(arr,n,i);
    }
    for(int i = n - 1 ; i > 0 ;  i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);

    }
}
int partition(int * v , int begin , int end){
    int pindex = begin;
    int value = v[end];
    for(int i = begin ; i <= end-1 ; i ++){
        if(value >= v[i]){
            swap(v[i],v[pindex]);
            pindex++;
        }
    }
    swap(v[end],v[pindex]);
    return pindex;
}
void QuickSort(int * v , int begin , int end){
    if(begin < end){
        p = partition(v,begin,end);
        QuickSort(v,begin,p-1);
        QuickSort(v,p+1,end);
    }
}
void SelectionSort(int * v, int begin , int end){
	int indx = begin;
	while(indx < end){
		int min_i = indx;
		for(int i = indx+1; i <= end; i ++){
			if(v[min_i] > v[i]) min_i = i;
		}
		swap(v[indx],v[min_i]);
		indx += 1;
	}
}
