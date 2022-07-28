#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> ConstructLPS(string pattern)
{
	vector<int> lps(pattern.length());
	int index = 0;

	for (int i = 1; i < pattern.length(); )
	{
		if (pattern[i] == pattern[index]) {
			index++ ;
			lps[i] = index; 
			i++;
		} 
		else
		{
			if (index != 0)
				index = lps[index - 1];
			else
				lps[i] = index, i++;
		}
	}
	return lps;
}

void KMP(string text, string pattern) {

	vector<int> lps = ConstructLPS(pattern);
	// for(auto x : lps)
	// 	cout << x << ' ';
	// cout << endl;

	int total = 0;

	for ( int i = 0, j = 0 ; i < text.size() ; ) {

		if ( text[i] == pattern[j] ) {
			i++;
			j++;
		}

		if ( j == pattern.size() ) {
			j = lps[j - 1];
			total++;

		} else if ( i < text.size() and text[i] != pattern[j] ) {
			if (j != 0)
				j = lps[j - 1];
			else
				i++;
		}
	}

	cout << total << endl;
}

int main() {

	// int t;
	// cin >> t;

	// for ( int i = 1 ; i <= t ; i++ )
	// {
	// 	string text, pattern;
	// 	cin >> text >> pattern;
	// 	cout << "Case " << i << ": ";
	// 	KMP(text, pattern);
	// }


	string s;
	cin >> s;
	vector<int> lsp = ConstructLPS(s);

	for(auto x : s)
		cout << x << ' ' ;
cout << endl;
	for(auto x : lsp)
		cout << x << ' ' ;



	return 0;
}