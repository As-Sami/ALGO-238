#include <bits/stdc++.h>
using namespace std;

#define print(x) cout << #x << " = " << x << endl
const int N = 1000, K = 100; // N = max size of string, k = max string

const int base1 = 1231, m1 = 1000000000 + 7;
const int base2 = 1567, m2 = 1000000000 + 9;
long long power1[N], Hash1[K][N];
long long power2[N], Hash2[K][N];
map<char, int>mp1[51], mp2[51];

long long  seed_hash1, seed_len1;
long long  seed_hash2, seed_len2;


void init(){

	power1[0] = 1;
    for( int i=1 ; i<N ; i++ )
        power1[i] = power1[i-1] * base1,
        power1[i] %= m1;

    power2[0] = 1;
    for( int i=1 ; i<N ; i++ )
        power2[i] = power2[i-1] * base2,
        power2[i] %= m2;

	for( char c='a' ; c<='z' ; c++ ){
		for( int i=1 ; i<=50 ; i++ )
			mp1[i][c] = (mp1[i-1][c] * base1) + (c-'a'+1),
			mp1[i][c] %= m1;		
	}

	for( char c='a' ; c<='z' ; c++ ){
		for( int i=1 ; i<=50 ; i++ )
			mp2[i][c] = (mp2[i-1][c] * base2) + (c-'a'+1),
			mp2[i][c] %= m2;		
	}
}

void init_hash(string s, int ind){

	Hash1[ind][0] = 0;
    for( int i=1 ; i<=s.size() ; i++ )
        Hash1[ind][i] = (Hash1[ind][i-1] * base1) + (s[i-1] - 'a' + 1),
        Hash1[ind][i] %= m1;

    Hash2[ind][0] = 0;
    for( int i=1 ; i<=s.size() ; i++ )
        Hash2[ind][i] = (Hash2[ind][i-1] * base2) + (s[i-1] - 'a' + 1),
        Hash2[ind][i] %= m2;
}

void update(string dir, char c, int cnt){

	if( dir=="RIGHT" ){

		seed_hash1 *= power1[cnt];
		seed_hash1 %= m1;
		seed_hash1 += mp1[cnt][c];
		seed_len1 += cnt;

		seed_hash2 *= power2[cnt];
		seed_hash2 %= m2;
		seed_hash2 += mp2[cnt][c];
		seed_len2 += cnt;

	}else{

		seed_hash1 += (mp1[cnt][c] * power1[seed_len1]) % m1;
		seed_hash1 %= m1;
		seed_len1 += cnt;

		seed_hash2 += (mp2[cnt][c] * power2[seed_len2]) % m2;
		seed_hash2 %= m2;
		seed_len2 += cnt;

	}

}

long long get_hash1(int ind, int l){

	int n = seed_len1;

	long long ret = Hash1[ind][l + n - 1] - Hash1[ind][l-1] * power1[n];

	ret %= m1;

	if( ret < 0 )
		ret += m1;

	return ret;
}

long long get_hash2(int ind, int l){

	int n = seed_len2;

	long long ret = Hash2[ind][l + n - 1] - Hash2[ind][l-1] * power2[n];

	ret %= m2;

	if( ret < 0 )
		ret += m2;

	return ret;
}


// iterate through every string and check if if found the 
// pattern in the string

bool check1(int n){

	for( int i=0 ; i<n ; i++ )
	{
		for( int j=1 ; Hash1[i][j + seed_len1 - 1]!=0 ; j++ ){		
			
			if( seed_hash1 == get_hash1(i, j) )
				return 1;
		}

	}
	
	return 0;
}

bool check2(int n){

	for( int i=0 ; i<n ; i++ )
	{
		for( int j=1 ; Hash2[i][j + seed_len2 - 1]!=0 ; j++ ){		
			
			if( seed_hash2 == get_hash2(i, j) )
				return 1;
		}

	}
	
	return 0;
}

int main()
{
	init();

    int n;
    cin >> n;
    for( int i=0 ; i<n ; i++ ){
    	string s;
    	cin >> s;

    	init_hash(s, i);
    }
    
    
    int q;
    cin >> q;

    while(q--){
    	string op;
    	cin >> op;

    	if( op=="SEED" ){

    		char c;
    		cin >> c;

    		seed_hash1 = c-'a'+1;
    		seed_hash2 = c-'a'+1;
    		seed_len1 = 1;
    		seed_len2 = 1;

    	}else if( op=="UPDATE" ){

    		string dir;
    		char c;
    		int cnt;
    		cin >> dir >> c >> cnt;

    		update(dir, c, cnt);

    	}else if( op=="CHECK" ){

    		if( check1(n) and check2(n) )
    			cout << "Exists!" << endl;
    		else
    			cout << "Doesn't exist" << endl;
    	}
    	
    }
    
    return 0;
}
