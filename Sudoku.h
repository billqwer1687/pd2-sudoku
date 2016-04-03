#include<iostream>
#include<algorithm>
class Sudoku
{
	public:
	void print(int num[9][9]);
	void giveQuestion();
	void readIn();
	void changeRow(int a,int b);
	void rotate(int n);
	void changeCol(int a,int b);
	void changeNum(int a,int b);
	void flip(int n);
	bool getblank(int num[9][9],int &row,int &col);
	bool check(int num[9][9],int row,int col,int num1);
	bool solve1(int num[9][9]);
	bool solve2(int num[9][9]);
	bool usedinrow(int num[9][9],int row,int num1);
	bool usedincol(int num[9][9],int col,int num1);
	bool usedinbox(int num[9][9],int boxstartrow,int boxstartcol,int num1);
	bool compare();
	void change();
	void transform();
	void solve();
	/*****/
	bool chkrow();
	bool chkcol();
	bool solvable();
	/*****/
	int num[9][9];
	int com[9][9];
	int tmp[9][9];
	int tmp2[9][9];
	int tmp5[9][9];
	int tmp6[9][9];
	int a[9];
	int b[9];
};

