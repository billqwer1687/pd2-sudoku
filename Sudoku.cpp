#include"Sudoku.h"
#include<fstream>
using namespace std;

//int num[8][8];
void Sudoku::print(int num[9][9])
{
	for(int row=0;row<9;row++)
	{
		for(int col=0;col<9;col++)
		{
			cout<<num[row][col]<<" ";

		}
		cout<<"\n";
	}
}

void Sudoku::givequestion()
{	
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			cout<<num[i][j]<<endl;
		}
		cout<<endl;
	}
}
void Sudoku::readin()
{
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			cin>>num[i][j];
		}
	}
}
bool Sudoku::compare()
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(tmp[i][j]==tmp2[i][j])
			{
				com[i][j]=1;
			}
			if(tmp[i][j]!=tmp2[i][j])
			{
				com[i][j]=0;
			}
		}
	}
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(com[i][j]==0)
			{
				return true;
			}
		}

	}
	return false;
}
bool Sudoku::solve2(int num[9][9])
{
	int row,col;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			tmp2[i][j]=num[i][j];
		}
	}
	if(!getblank(num,row,col))
	{
		return true;
	}
	for(int num1=9;num1>=1;num1--)
	{
		if(check(num,row,col,num1))
		{
			tmp2[row][col]=num1;
			if(solve2(tmp2))
			{
				return true;
			}
			tmp2[row][col]=0;
		}
	}
	return false;
}
bool Sudoku::solve(int num[9][9])
{
	int row,col;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			tmp[i][j]=num[i][j];
		}
	}
	if(!getblank(num,row,col))
	{
		return true;
	}
	for(int num1=1;num1<=9;num1++)
	{
		if(check(num,row,col,num1))
		{
			tmp[row][col]=num1;
			if(solve(tmp))
			{
				return true;
			}
			tmp[row][col]=0;
		}
	}
	return false;

}

bool Sudoku::chkrow()
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			tmp5[i][j]=num[i][j];
		}
	}
	for(int number=1;number<=9;number++)
	{
		for(int j=0;j<9;j++)
		{
			/**********/
			for(int i=0;i<9;i++)
				a[i]=0;
			/*********/
			if(tmp5[0][j]==number)
			{
				a[number-1]++;
			}
			if(tmp5[1][j]==number)
			{
				a[number-1]++;
			}
			if(tmp5[2][j]==number)
			{
				a[number-1]++;
			}
			if(tmp5[3][j]==number)
			{
				a[number-1]++;
			}
			if(tmp5[4][j]==number)
			{
				a[number-1]++;
			}
			if(tmp5[5][j]==number)
			{
				a[number-1]++;
			}
			if(tmp5[6][j]==number)
			{
				a[number-1]++;
			}
			if(tmp5[7][j]==number)
			{
				a[number-1]++;
			}
			if(tmp5[8][j]==number)
			{
				a[number-1]++;
			}
			/**********/
			for(int i=0;i<9;i++)
				if(a[i]>1)
				{	
					return false;
				}
			/*********/
		}
	}
	return true;
}
bool Sudoku::chkcol()
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			tmp6[i][j]=num[i][j];
		}
	}
	
	for(int number=1;number<=9;number++)
	{
		for(int j=0;j<9;j++)
		{
			/**********/
			for(int i=0;i<9;i++)
				b[i] = 0;
			/*********/
			if(tmp6[j][0]==number)
			{
				b[number-1]++;
			}
			if(tmp6[j][1]==number)
			{
				b[number-1]++;
			}
			if(tmp6[j][2]==number)
			{
				b[number-1]++;
			}
			if(tmp6[j][3]==number)
			{
				b[number-1]++;
			}
			if(tmp6[j][4]==number)
			{
				b[number-1]++;
			}
			if(tmp6[j][5]==number)
			{
				b[number-1]++;
			}
			if(tmp6[j][6]==number)
			{
				b[number-1]++;
			}
			if(tmp6[j][7]==number)
			{
				b[number-1]++;
			}
			if(tmp6[j][8]==number)
			{
				b[number-1]++;
			}
			/********/
			for(int i=0;i<9;i++)
				if(b[i]>1)
				{
					return false;
				}
			/*******/
		}
		
	}
	return true;
}

bool Sudoku::solvable()
{
	if(chkrow()==false||chkcol()==false)
		return false;
	return true;
}


bool Sudoku::getblank(int num[9][9],int &row,int &col)
{
	for(row=0;row<9;row++)
	{
		for(col=0;col<9;col++)
		{
			if(num[row][col]==0)
			{
				return true;
			}
		}
	}
	return false;
}
bool Sudoku::usedinrow(int num[9][9],int row,int num1)
{
	for(int col=0;col<9;col++)
	{
		if(num[row][col]==num1)
		{
			return true;
		}
	}
	return false;
}
bool Sudoku::usedincol(int num[9][9],int col,int num1)
{
	for(int row=0;row<9;row++)
	{
		if(num[row][col]==num1)
		{
			return true;
		}
	}
	return false;
}
bool Sudoku::usedinbox(int num[9][9],int boxstartrow,int boxstartcol,int num1)
{
	for(int row=0;row<3;row++)
	{
		for(int col=0;col<3;col++)
		{
			if(num[row+boxstartrow][col+boxstartcol]==num1)
			{
				return true;
			}
		}
	}
	return false;
}
bool Sudoku::check(int num[9][9],int row,int col,int num1)
{
	return !usedinrow(num,row,num1)&&!usedincol(num,col,num1)&&!usedinbox(num,row-row%3,col-col%3,num1);
}
void Sudoku::changenumber(int a,int b)
{
	int i,j,tmp1,tmp2;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(num[i][j]==a)
			{
				tmp1=b;
				num[i][j]=tmp1;
			}
			else if(num[i][j]==b)
			{
				tmp2=a;
				num[i][j]=tmp2;
			}
		}
	}
}
void Sudoku::changerow(int a,int b)
{ 	
	int i,j;
	if(a==0&&b==1)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<9;j++)
			{
				swap(num[i][j],num[i+3][j]);
			}
		}

	}
	if(a==0&&b==2)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<9;j++)
			{
				swap(num[i][j],num[i+6][j]);
			}
		}
	}
	if(a==1&&b==2)
	{
		for(i=3;i<6;i++)
		{
			for(j=0;j<9;j++)
			{
				swap(num[i][j],num[i+3][j]);
			}
		}
	}

}
void Sudoku::changecolumn(int a,int b)
{
	int i,j;
	if(a==0&&b==1)
	{
		for(j=0;j<3;j++)
		{
			for(i=0;i<9;i++)
			{
				swap(num[i][j],num[i][j+3]);
			}
		}
	}
	if(a==0&&b==2)
	{
		for(j=0;j<3;j++)
		{
			for(i=0;i<9;i++)
			{
				swap(num[i][j],num[i][j+6]);
			}
		}
	}
	if(a==1&&b==2)
	{
		for(j=3;j<6;j++)
		{
			for(i=0;i<9;i++)
			{
				swap(num[i][j],num[i][j+3]);
			}
		}
	}


}
void Sudoku::changerotate(int n)
{
	int i,j,k;
	for(k=0;k<n;k++)
	{
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				num[i][j]=num[8-j][i];
			}
		}
	}	
}
void Sudoku::changeflip(int n)
{
	int i,j,tmp3[9][9],tmp4[9][9];
	if(n==1)
	{
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				tmp3[8-j][i]=num[j][i];
			}
		}
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				num[i][j]=tmp3[i][j];
			}
		}
	}
	if(n==0)
	{
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				tmp4[j][8-i]=num[j][i];
			}
		}
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				num[i][j]=tmp4[i][j];
			}
		}
	}
}
void Sudoku::change()
{
	srand(time(NULL));
	changenumber(rand()%10,rand()%10);
	changerow(rand()%3,rand()%3);
	changecolumn(rand()%3,rand()%3);
	changerotate(rand()%101);
	changeflip(rand()%2);
}
void Sudoku::transform()
{
	readin();
	change();
	print(num);
}
