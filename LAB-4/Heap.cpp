#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int tree[N];
int cnt;

bool empty(){
	return cnt==0;
}

void push(int x){
	tree[++cnt] = x;

	int c = cnt;
	int par = c/2;
	while( par>0 ){

		if( tree[par] > tree[c] )
		{
			swap(tree[par] , tree[c]);
			c = par;
			par /= 2;
		}
		else
			return;
	}

}

int top(){
	if( cnt==0 ){
		cout << "Heap is empty!!" << endl;
	}

	return tree[1];
}

int pop(){
	if( cnt==0 ){
		cout << "Heap is empty!!" << endl;
	}

	int ret = tree[1];

	tree[1] = tree[cnt--];

	int l, r, cur=1;
	l = 2*cur;
	r = l + 1;
	while( l<=cnt ){

		int mx = tree[l];

		if( tree[r]<=cnt )
			mx = min(mx, tree[r]);

		if( mx < tree[cur] ){
			if( tree[l] == mx ){
				swap(tree[l] , tree[cur]);
				cur = l;
			}else{
				swap(tree[r] , tree[cur]);
				cur = r;
			}
		}else
			return ret;

		l = cur*2;
		r = l+1;

	}
	return ret;
}

void heapSort(int a[], int n){

	for( int i=0 ; i<n ; i++ )
		push(a[i]);
	
	for( int i=0 ; i<n ; i++ )
		a[i] = pop();
}

int main()
{
    
	int n = 10;
	int a[] = {5, 2, 4, 3, 1, 8, 3, 7, 4, 2};
	heapSort(a, n);
	for( int i=0 ; i<10 ; i++ )
		cout << a[i] << " \n"[i==9];
	

    return 0;
}