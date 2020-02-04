#include<bits/stdc++.h>
#include<string.h>
using namespace std;
bool validate_sudoku(char board[9][9])
{
	unordered_set<string> records;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(board[i][j]=='.')
				continue;
			
			//generate unique strings row,col and 3x3 block
			string row="";
			row+=board[i][j];
			row+=" rows ";
			row+=i;
			string col="";
			col=board[i][j];
			col+=" col ";
			col+=j;
			string block="";
			block+=board[i][j];
			block+=" box ";
			block+=(i/3);
			block+=" - ";
			block+=(j/3);
			
			if(records.find(row)!=records.end())
				return false;
			if(records.find(col)!=records.end())
				return false;
			if(records.find(block)!=records.end())
				return false;
			
			//otherwise add row
			records.insert(row);
			records.insert(col);
			records.insert(block);
		}
	}
	return true;
}
int main()
{
	//board array
	//empty cell are represented by a .

	char board[9][9]={{'5','3','.','.','7','.','.','.','.'},
					  {'6','.','.','1','9','5','.','.','.'},
					  {'.','9','8','.','.','.','.','6','.'},
					  {'8','.','.','.','6','.','.','.','3'},
					  {'4','.','.','8','.','3','.','.','1'},
					  {'7','.','.','.','2','.','.','.','6'},
					  {'.','6','.','.','.','.','2','8','.'},
					  {'.','.','.','4','1','9','.','.','5'},
					  {'.','.','.','.','8','.','.','7','9'}};
	
	//calling validation function
	if(validate_sudoku(board))
		cout<<"VALID SUDOKU";
	else
		cout<<"INVALID SUDOKU";
	return 0;	
}
