#include<iostream>
#include<algorithm>
class sudoku
{
	public:
	void print(int num[9][9]);
	void givequestion();
	void readin();
	void changerow(int a,int b);
	void changerotate(int n);
	void changecolumn(int a,int b);
	void changenumber(int a,int b);
	void changeflip(int n);
	bool getblank(int num[9][9],int &row,int &col);
	bool check(int num[9][9],int row,int col,int num1);
	bool solve(int num[9][9]);
	bool solve2(int num[9][9]);
	bool usedinrow(int num[9][9],int row,int num1);
	bool usedincol(int num[9][9],int col,int num1);
	bool usedinbox(int num[9][9],int boxstartrow,int boxstartcol,int num1);
	bool compare();
	int num[9][9];
	int com[9][9];
	int tmp[9][9];
	int tmp2[9][9];
	int tmp5[9][9];
	int a1[9],a2[9],a3[9],a4[9],a5[9],a6[9],a7[9],a8[9],a9[9];
	int b1[9],b2[9],b3[9],b4[9],b5[9],b6[9],b7[9],b8[9],b9[9];
};

