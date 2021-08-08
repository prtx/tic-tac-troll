void notsoeasy()
{

	srand(time(NULL));
	int flow = TRUE,count=0,move,trollnum=rand()%9+1,trolled=FALSE,drawcase=FALSE;
	char c;

	while(flow)
	{

		system("clear");

		printf("\n\t\t\t\tTicTacTroll\n\n");

		show(map);

		int valid = FALSE;
		while(!valid)
		{

			if(count%2==0)
			{
				printf("\n\t\t\t\tPlayer's move: ");
				scanf("%d",&move);
			}
			else
			{
				if(count==1)
				{
					if(map[1][1]==11)
					{
						if(rand()%2)
							move=5+2*(rand()%2+1);
						else
							move=5-2*(rand()%2+1);
					}
					else
						move=5;
				}
				else if(deathorglory(map)!=FALSE)
					move=deathorglory(map);
				else
					move=rand()%9+1;
			}

			if(move==trollnum && trolled==FALSE && count%2==0)
				break;

			valid=validcheck(move);
			if(valid==FALSE && count%2==0)
				printf("\n\t\t\tInvalid move. Try again\n");
			else
				image[move/3][move%3-1]=0;
		}


		if(move==trollnum && trolled==FALSE && count%2==0)
		{
			if(count%2==0)
				printf("\t\t\tPlayer Trolled. Press Enter");
			else
				printf("\t\t\tComputer Trolled. Press Enter");
			getchar();
			getchar();
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

		flow=flowcheck(map);

		if(flow)
			count++;

		if(count==9 && !trolled)
			count++;

		if(count==10)
		{
			flow=FALSE;
			drawcase=TRUE;
			count++;
		}

	}

	system("clear");
	show(map);
	if(drawcase)
		printf("\n\t\t\t\tDraw\n\n");
	else if(count%2==0)
		printf("\n\t\t\t      Congratulations Player\n\n");
	else
		printf("\n\t\t\t    Computer Wins\n\n");

}
