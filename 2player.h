void twoplay()
{

	srand(time(NULL));
	int flow = TRUE,count=0,move,trollnum=rand()%9+1,trolled=FALSE;
	char c;

	while(flow)
	{
		system("clear");

		printf("\n\t\t\t\tTicTacTroll\n\n");

		if(move==trollnum)
			printf("\t\t\t\t  Trolled");

		show(map);

		int valid = FALSE;
		while(!valid)
		{
			printf("\n\t\t\t\t%dP move: ",count%2+1);
			scanf("%d",&move);

			if(move==trollnum && trolled==FALSE)
				break;

			valid=validcheck(move);
			if(valid==FALSE)
				printf("\n\t\t\tInvalid move. Try again\n");
            else
				image[move/3][move%3-1]=0;
		}

		if(move==trollnum && trolled==FALSE)
		{
			trolled=TRUE;
		}
		else if(count%2==0)
		{
			map[move/3][move%3-1]=11;
		}
		else
		{
			map[move/3][move%3-1]=22;
		}
		count++;
		flow=flowcheck(map);

		if(count==10)
		{
			flow=FALSE;
			count++;
		}

	}

	system("clear");
	show(map);
	if(count==11)
		printf("\n\t\t\t\tDraw\n\n");
	else if(count%2==0)
		printf("\n\t\t\t    Congratulations 2P\n\n");
	else
		printf("\n\t\t\t    Congratulations 1P\n\n");
}
