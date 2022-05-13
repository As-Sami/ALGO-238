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
        if (pattern[i] == pattern[index])
         lps[i] = index + 1, index++ , i++;
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

void KMP(string text, string pattern){

	vector<int> lps = ConstructLPS(pattern);

	for( int i=0, j=0 ; i<text.size() ; ){

		if( text[i]==pattern[j] ){
			i++;
			j++;
		}

		if( j==pattern.size() ){
			cout << "pattern found at ->" << i-j << "\n";
			return;

		}else if( i<text.size() and text[i] != pattern[j] ){
			if(j != 0)
				j = lps[j-1];
			else
				i++;
		}
	}

	cout << "Not found\n";
}

int main(){

	string text, pattern;
	cin >> text >> pattern;


	KMP(text, pattern);


	return 0;
}