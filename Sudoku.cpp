#include"sudoku.h"
#include<fstream>
using namespace std;
int num[8][8];
void sudoku::print(int num[9][9])
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

void sudoku::givequestion()
{	
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			cout<<num[i][j];
		}
	}
}
void sudoku::readin()
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
bool sudoku::compare()
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
bool sudoku::solve2(int num[9][9])
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
	for(int num1=9;num1>=0;num1--)
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
bool sudoku::solve(int num[9][9])
{
	int row,col;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			tmp[i][j]=num[i][j];
		}
	}
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			tmp5[i][j]=num[i][j];
		}
	}
	if(!getblank(num,row,col))
	{
		return true;
	}
		for(int number=1;number<=9;number++)
		{
			for(int j=0;j<9;j++)
			{
				if(tmp5[0][j]==number)
				{
					a1[number-1]++;
				}
				if(tmp5[1][j]==number)
				{
					a2[number-1]++;
				}
				if(tmp5[2][j]==number)
				{
					a3[number-1]++;
				}
				if(tmp5[3][j]==number)
				{
					a4[number-1]++;
				}
				if(tmp5[4][j]==number)
				{
					a5[number-1]++;
				}
				if(tmp5[5][j]==number)
				{
					a6[number-1]++;
				}
				if(tmp5[6][j]==number)
				{
					a7[number-1]++;
				}
				if(tmp5[7][j]==number)
				{
					a8[number-1]++;
				}
				if(tmp5[8][j]==number)
				{
					a9[number-1]++;
				}
			}
		}
	
	for(int j=0;j<9;j++)
	{
		if(a1[j]||a2[j]||a3[j]||a4[j]||a5[j]||a6[j]||a7[j]||a8[j]||a9[j]>1)
		{
			cout<<a1[j]<<" "<<a2[j]<<" "<<a3[j];
			return false;
		}
	}
		for(int number=1;number<=9;number++)
		{
			for(int j=0;j<9;j++)
			{
				if(tmp5[j][0]==number)
				{
					b1[number-1]++;
				}
				if(tmp5[j][1]==number)
				{
					b2[number-1]++;
				}
				if(tmp5[j][2]==number)
				{
					b3[number-1]++;
				}
				if(tmp5[j][3]==number)
				{
					b4[number-1]++;
				}
				if(tmp5[j][4]==number)
				{
					b5[number-1]++;
				}
				if(tmp5[j][5]==number)
				{
					b6[number-1]++;
				}
				if(tmp5[j][6]==number)
				{
					b7[number-1]++;
				}
				if(tmp5[j][7]==number)
				{
					b8[number-1]++;
				}
				if(tmp5[j][8]==number)
				{
					b9[number-1]++;
				}
			}
		}
	for(int j=0;j<9;j++)
	{
		if(b1[j]||b2[j]||b3[j]||b4[j]||b5[j]||b6[j]||b7[j]||b8[j]||b9[j]>1)
		{
			return false;
		}
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
bool sudoku::getblank(int num[9][9],int &row,int &col)
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
bool sudoku::usedinrow(int num[9][9],int row,int num1)
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
bool sudoku::usedincol(int num[9][9],int col,int num1)
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
bool sudoku::usedinbox(int num[9][9],int boxstartrow,int boxstartcol,int num1)
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
bool sudoku::check(int num[9][9],int row,int col,int num1)
{
	return !usedinrow(num,row,num1)&&!usedincol(num,col,num1)&&!usedinbox(num,row-row%3,col-col%3,num1);
}
void sudoku::changenumber(int a,int b)
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
void sudoku::changerow(int a,int b)
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
void sudoku::changecolumn(int a,int b)
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
void sudoku::changerotate(int n)
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
void sudoku::changeflip(int n)
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
