#include <bits/stdc++.h>
using namespace std;

#define print(x) cout << #x << " = " << x << endl

const int N = 10000;
int a[N];

void generate(){
    for( int i=0 ; i<N ; i++ )
        a[i] = rand()%N + 1;
}

int q_part(int i, int j){
    bool r = true;

    while(i<j){
        if( a[i]>a[j] ){
            swap(a[i] , a[j]);
            r ^= 1;
        }
        if( r ) j--;
        else i++;
    }
    return i;
}

void quickSort(int i, int j){

    if( i>=j ) return;

    int p = q_part(i,j);
    quickSort(i, p-1);
    quickSort(p+1,j);
}

void merge(int i, int j, int m){
    // vector<int> v(j-i+1);
    int v[j-i+1];
    int st=i, mid = m+1, k = 0;
    
    for( int kk=i ; kk<=j ; kk++ )
    {
        if( st > m )
            v[k++] = a[mid++];
        else if( mid>j )
            v[k++] = a[st++];
        else if( a[st] < a[mid] )
            v[k++] = a[st++];
        else
            v[k++] = a[mid++];
    } 

    for( int p=0 ; p<k ; p++ )
        a[i++] = v[p];
}

void mergesort(int i, int j){

    if( i>=j )return;

    int mid = (i+j)/2;

    mergesort(i,mid);
    mergesort(mid+1, j);

    merge(i,j,mid);
}

int main()
{
    
    auto t1 = clock();

    for( int i=0 ; i<1000 ; i++ ){
        generate();
        quickSort(0,N);
    }
    
    auto t2 = clock();

    for( int i=0 ; i<1000 ; i++ ){
        generate();
        mergesort(0,N);
    }
    
    auto t3 = clock();

    cout << t2-t1 << endl;
    cout << t3-t2 << endl;
   
    
    return 0;
}
