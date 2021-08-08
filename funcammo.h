# define TRUE 1
# define FALSE 0

int map[3][3]={1,2,3,4,5,6,7,8,9};
int image[3][3]={1,2,3,4,5,6,7,8,9};

void show(int map[3][3])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		printf("\n\t\t\t\t|");
		for(j=0;j<3;j++)
		{
			if(map[i][j]==11)
			{
				printf(" o ");
			}
			else if(map[i][j]==22)
			{
				printf(" * ");
			}
			else
			{
				printf(" _ ");
			}
		}
		printf("|");
	}
	printf("\n\n");
}

int flowcheck(int map[3][3])
{
	int i;
	if(map[0][0]==map[1][1] && map[1][1]==map[2][2])
	{
		return FALSE;
	}
	if(map[2][0]==map[1][1] && map[1][1]==map[0][2])
	{
		return FALSE;
	}
	for(i=0;i<3;i++)
	{
		if(map[i][0]==map[i][1] && map[i][1]==map[i][2])
		{
			return FALSE;
		}
		if(map[0][i]==map[1][i] && map[1][i]==map[2][i])
		{
			return FALSE;
		}
	}
	return TRUE;
}

int validcheck(int move)
{
	int i,j,count=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(move==image[i][j])
				count++;
		}
	}
	if(count==1)
	{

		return TRUE;
	}
	else
		return FALSE;
}

int deathorglory(int map[3][3])
{
	int i,j;

	for(i=0;i<3;i++)
	{

		if(map[i][i]==map[(i+1)%3][(i+1)%3] && map[i][i]==22 && map[(i+2)%3][(i+2)%3]!=22 && validcheck(4*((i+2)%3)+1))
			return 4*((i+2)%3)+1;

		if(map[i][(2*i+2)%3]==map[(i+1)%3][(2*i+4)%3] && map[i][(2*i+2)%3]==22 && map[(i+2)%3][(2*i+6)%3]!=22 && validcheck(((i+2)%3)*3+(2*i+6)%3+1))
			return ((i+2)%3)*3+(2*i+6)%3+1;

		for(j=0;j<3;j++)
		{

			if(map[i][j]==map[i][(j+1)%3] && map[i][j]==22 && map[i][(j+2)%3]!=22 && validcheck((j+2)%3+1+i*3))
				return i*3+(j+2)%3+1;
			if(map[j][i]==map[(j+1)%3][i] && map[j][i]==22 && map[(j+2)%3][i]!=22 && validcheck(((j+2)%3)*3+1+i))
				return ((j+2)%3)*3+i+1;

		}

		if(map[i][i]==map[(i+1)%3][(i+1)%3] && map[i][i]==11 && map[(i+2)%3][(i+2)%3]!=11 && validcheck(4*((i+2)%3)+1))
			return 4*((i+2)%3)+1;

		if(map[i][(2*i+2)%3]==map[(i+1)%3][(2*i+4)%3] && map[i][(2*i+2)%3]==11 && map[(i+2)%3][(2*i+6)%3]!=11 && validcheck(((i+2)%3)*3+(2*i+6)%3+1))
			return ((i+2)%3)*3+(2*i+6)%3+1;

		for(j=0;j<3;j++)
		{

			if(map[i][j]==map[i][(j+1)%3] && map[i][j]==11 && map[i][(j+2)%3]!=11 && validcheck((j+2)%3+1+i*3))
				return i*3+(j+2)%3+1;
			if(map[j][i]==map[(j+1)%3][i] && map[j][i]==11 && map[(j+2)%3][i]!=11 && validcheck(((j+2)%3)*3+1+i))
				return ((j+2)%3)*3+i+1;

		}

	}

	return FALSE;
}
