#include <iostream>
#include <cstring>

using namespace std;

#define M 4
#define N 4

string dict[] = {"STOP", "IT", "RIGHT", "MEOW"};

int n = sizeof(dict)/sizeof(dict[0]);

bool isWord(string &s){
	for (int i = 0; i<n; i++){
		if(s.compare(dict[i]) == 0){
			return true;
		}
	}
	return false;
}

void findWords(char arr[M][N], bool searched[M][N], int i, int j, string &str);

void scanBoard(char arr[M][N]);

int main(){
	char boggle[M][N] = {{'T','I','Z', 'K'},
                         {'W','O','K', 'G'},
                         {'Q','M','E', 'R'},
                     	  {'B', 'G', 'I', 'H'}};
    //string v = "MEOW";
    //if(!isWord(v)) {cout << "FALSE";} else{ cout<< "TRUE";} 
    //cout << "TEST: " << "dict side is " << n << "\n";
 
    cout << "Following words of dictionary are present: \n";
    scanBoard(boggle);
    return 0;

}

void findWords(char arr[M][N], bool searched[M][N], int i, int j, string &str){
	searched[i][j] = true;
	//cout << arr[i][j] << " \n";
	str = str + arr[i][j];
	//cout << str << "\n";
	if(isWord(str))
		cout << "HIT: " << str << " \n";

	for(int row = i-1; row<=i+1 && row < M; row++){
		for(int col = j-1; col <=i+1 && col < N; col++){
			if(row >= 0 && col >=0 && !searched[row][col]){
				findWords(arr, searched, row, col, str);
			}
		}
	}

	str.erase(str.length()-1);
	searched[i][j] = false;	

}

void scanBoard(char arr[M][N]){
	
	bool searched[M][N] = {{false}};

	string str = "";


	for (int i = 0; i<M; i++){
		for (int j = 0; j<N; j++){
			findWords(arr, searched, i, j, str);
			}
		}
}

