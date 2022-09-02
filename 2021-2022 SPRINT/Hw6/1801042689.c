#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void red()   // red text
{
	printf("\033[1;31m");
}
void yellow() // yellow text
{
	printf("\033[1;33m");
}
void blue()  // blue text
{
	printf("\033[1;34m");
}

void green()  // green text
{
	printf("\033[1;32m");
}
void reset()	// reset text
{
	printf("\033[0m");
}
int dice() // dice system
{
    srand(time(NULL));
    int value;
    value =rand()% 6+ 1;
    return value;
}
//Print the Map
void printMap(char area[15][30], int row,int col) 
{  
  for(int i=0;i<15;i++)
   {
    for(int j=0;j<30;j++)
      {
      	if(i==1 && j==14)
      	{	
      		red();
      		printf("%c",area[i][j]);	
      		reset();
      	}
      	else if(i==7 && j==28)
      	{
      		red();
      		printf("%c",area[i][j]);	
      		reset();	
      	}

      	else if(i==13 && j==14)
      	{
      		red();
      		printf("%c",area[i][j]);	
      		reset();	
      	}

      	else if(i==3 && j==10)
      	{
      		red();
      		printf("%c",area[i][j]);	
      		reset();	
      	}
     		
     		else if(i==3 && j==18)
      	{
      		red();
      		printf("%c",area[i][j]);	
      		reset();	
      	}

      	else if(i==5 && j==26)
      	{
      		red();
      		printf("%c",area[i][j]);	
      		reset();	
      	}

      	else if(i==10&& j==26)
      	{
      		red();
      		printf("%c",area[i][j]);	
      		reset();	
      	}

      	else if(i==11 && j==10)
      	{
      		red();
      		printf("%c",area[i][j]);	
      		reset();	
      	}

      	else if(i==11 && j==18)
      	{
      		red();
      		printf("%c",area[i][j]);	
      		reset();	
      	}
      	else if(area[i][j]=='1')
      	{
      		yellow();
      		printf("%c",area[i][j]);
      		reset();
      	}
      	else if(area[i][j]=='2')
      	{
      		blue();
      		printf("%c",area[i][j]);
      		reset();
      	}
      	else if(area[i][j]=='-')
      	{
      		green();
      		printf("%c",area[i][j]);
      		reset();
      	}
      	else
      	{
      		printf("%c",area[i][j]);
      	}
      }
   	printf("\n");
	}
}

//Determining the player to start first
int startGame()
{	
	char a;
	int di,di1;
	printf("To start to game , players should dice and decide who is going to start first according to it ..\n");
	yellow();
	printf("PLAYER 1 ... press ENTER to dice ");
	scanf("%c",&a);
	di=dice();
	printf("DICE : %d\n",di);
	reset();
	blue();
	printf("PLAYER 2 ... press ENTER to dice ");
	scanf("%c",&a);
	di1=dice();
	printf("DICE : %d\n",di1);
	reset();
	while(di1==di)
	{
		printf("\nSame dice value... Please try again\n");
		yellow();
		printf("PLAYER 1 ... press ENTER to dice ");
		scanf("%c",&a);	
		di=dice();
		printf("DICE : %d\n",di);
		reset();
		blue();
		printf("PLAYER 2 ... press ENTER to dice ");
		scanf("%c",&a);	
		di1=dice();
		printf("DICE : %d\n",di1);
		reset();
	
	}
	if(di>di1)
	{
		return 0;
	}
	else if(di1>di)
	{
		return 1;
	}
}

//printing first map
void printFirstMap() 
{
	char area[15][30];
	char a = '.' , b = ':' ,player1 = '1' , player2='2' , finish='-' ,penalty='X';
	for(int rows = 0 ; rows < 15 ; rows++)
	{
		for(int cols = 0 ; cols < 30 ; cols++)
		{

			if(rows==0)
			{
				area[rows][cols]=a;
				printf("%c",area[rows][cols]);
			}

			

			// penalties player1 

			else if(rows==1 && cols==14)
			{
				area[rows][cols]=penalty;
				red();
				printf("%c",area[rows][cols]);
				reset();
			}

			else if(rows==7 && cols==28)
			{
				area[rows][cols]=penalty;
				red();
				printf("%c",area[rows][cols]);
				reset();
			}

			else if(rows==13 && cols==14)
			{
				area[rows][cols]=penalty;
				red();
				printf("%c",area[rows][cols]);
				reset();
			}

			//penalties player2 

			else if(rows==3 && cols==10)
			{
				area[rows][cols]=penalty;
				red();
				printf("%c",area[rows][cols]);
				reset();
			}

			else if(rows==3 && cols==18)
			{
				area[rows][cols]=penalty;
				red();
				printf("%c",area[rows][cols]);
				reset();
			}

			else if(rows==5 && cols==26)
			{
				area[rows][cols]=penalty;
				red();
				printf("%c",area[rows][cols]);
				reset();
			}

			else if(rows==10 && cols==26)
			{
				area[rows][cols]=penalty;
				red();
				printf("%c",area[rows][cols]);
				reset();
			}

			else if(rows==11 && cols==10)
			{
				area[rows][cols]=penalty;
				red();
				printf("%c",area[rows][cols]);
				reset();
			}

			else if(rows==11 && cols==18)
			{
				area[rows][cols]=penalty;
				red();
				printf("%c",area[rows][cols]);
				reset();
			}
			//--------------------------------------------------------------------------------------
			else if(rows==2 && cols==1)
			{
				area[rows][cols]=finish;
				green();
				printf("%c",area[rows][cols]);
				reset();
			}

			else if(rows==2 && (cols>1 && cols<28))
			{
				area[rows][cols]=a;
				printf("%c",area[rows][cols]);
				
			}
			else if((rows>2 && rows<12)&&(cols==2 || cols==27))
			{
				area[rows][cols]=b;
				printf("%c",area[rows][cols]);
			}

			else if(rows==4 && cols==3)
			{
				area[rows][cols]=finish;
				green();
				printf("%c",area[rows][cols]);
				reset();	
			}
			else if(rows==4 && (cols>4 && cols<25))
			{
				area[rows][cols]=a;
				printf("%c",area[rows][cols]);
			}
			else if((rows==4 || rows==10)&&(cols==4 || cols==25))
			{
				area[rows][cols]=a;
				printf("%c",area[rows][cols]);
			}

			else if((rows>4 && rows<10)&&(cols==4 || cols==25))
			{
				area[rows][cols]=b;
				printf("%c",area[rows][cols]);
			}


			else if(rows==10 && (cols>4 && cols<25))
			{
				area[rows][cols]=a;
				printf("%c",area[rows][cols]);
			}

			else if(rows==12 && (cols>1 && cols<28))
			{
				area[rows][cols]=a;
				printf("%c",area[rows][cols]);
			}

			else if (rows<14 && (cols==0 || cols==29))
			{
				area[rows][cols]=b;
				printf("%c",area[rows][cols]);
			}
			else if (rows==14)
			{
				area[rows][cols]=a;
				printf("%c",area[rows][cols]);

			}
			else if(rows==1 && cols==1)
			{
				yellow();
				area[rows][cols]=player1;

				printf("%c",area[rows][cols]);
				reset();
			}

			else if(rows==3 && cols==3)
			{
				blue();
				area[rows][cols]=player2;

				printf("%c",area[rows][cols]);
				reset();
			}
			else
				printf(" ");
		}
		printf("\n");
	}
}


int main()
{
	//	Determining the shape of the map
	 char array2d[15][30]={0};
   for(int i=0;i<15;i++)
    for(int j=0;j<30;j++)
      {
      	if(i==0 || i==14 || j==0 || j==29)
      	 	array2d[i][j]='.';
      	else
      		array2d[i][j]=' ';
	  	}
   
   for(int i=2;i<13;i++)
    for(int j=2;j<28;j++)
      {
      	if(i==2 || i==12 || j==2 || j==27)
      	 array2d[i][j]='.';
				else
      		array2d[i][j]=' ';      
	  	}
	  
   for(int i=4;i<11;i++)
    for(int j=4;j<26;j++)
      {
      	if(i==4 || i==10 || j==4 || j==25)
      	 array2d[i][j]='.';
      	else
      		array2d[i][j]=' ';
	  }
   
  // Penalty points
  array2d[1][14]= array2d[7][28] = array2d[13][14] = 'x';
  array2d[3][10]= array2d[3][18] = array2d[5][26] = 'x';
  array2d[10][26]= array2d[11][10] = array2d[11][18] = 'x';
  array2d[1][1]= '1';
  array2d[3][3]= '2';
  array2d[2][1]= '_';
  array2d[4][3]= '_';
	
 	 
  printFirstMap();

  //Determine the player to start first
 	int maxdice = startGame();
 	
 	int go_player1 = 1;   // player 1 path token
 	int endgame = 0;			// endgame
 	char cplayer1;        // press enter
 	int iplayer1; 				// dice one holds for player one
 	int lastrowvaluep1=1; // Assigned to because player 1 initially starts from(1,1)
 	int lastcolvaluep1=1; // Assigned to because player 1 initially starts from(1,1)
 	int oldrowvaluep1;		//
 	int oldcolvaluep1=1; 
  int temp=0;
  int go_player2 = 1;   // player 2 path token
	char cplayer2;
	int iplayer2; 				// 	dice one holds for player one
  int lastrowvaluep2=3; //  Assigned to because player 1 initially starts from(3,3)
  int lastcolvaluep2=3;	// 
  int oldrowvaluep2;
  int oldcolvaluep2=3;  //  Assigned to because player 1 initially starts from(3,) 
  int path_top_player1=1;
  int path_right_player1=1;
  int path_top_player2=3;
  int path_right_player2=3;
 	if(maxdice==0)
 	{
 		while(endgame==0)  // if endgame becomes 1 its game over
 		{	
	  	  while(go_player1 <5  || go_player2<5) 
   		  { 
			 //--------------------------PLAYER 1  -------------------------------
	 			
   			// PATH TOP FOR PLAYER 1
	 			if(go_player1 ==1) 
	 			{
	 				yellow();
	 				printf("\nPLAYER 1... press ENTER to dice...");
     				cplayer1=getchar();
     				iplayer1=dice();
		 			printf("DICE: %d \n",iplayer1);
		 			lastcolvaluep1 = lastcolvaluep1 + iplayer1;
					if(lastcolvaluep1 == 14)
	 	 			{
	 						printf("Penalty for player 1 ...\n");
 							oldcolvaluep1=14-iplayer1;
 							if(temp==1)
 							{
 									oldcolvaluep1=10;
 									temp=0;
 							}
 							lastcolvaluep1 = 12;
 							temp++;	 	 
 					}
	 				if(lastcolvaluep1 > 28)
	 				{ 		//will change direction in case of overflow
      					lastrowvaluep1 = lastrowvaluep1 + lastcolvaluep1 - 28;	 
	    				lastcolvaluep1 = 28;
		 				go_player1 = 2;  // going up and down
	 				}	
				 	array2d[lastrowvaluep1][lastcolvaluep1]= '1';
				 	array2d[1][oldcolvaluep1]= ' ';
	 			 	oldcolvaluep1=lastcolvaluep1;  
	 			 	oldrowvaluep1=lastrowvaluep1;
	 				reset();
	 			}

	 			// PATH RIGHT FOR PLAYER 1
	 		else if(go_player1 ==2)
	 		{
	 			yellow();
	 			printf("PLAYER 1... press ENTER to dice...\n");
    			cplayer1=getchar();
    			iplayer1=dice();
	 			printf("DICE: %d \n",iplayer1);
	 			lastrowvaluep1 = lastrowvaluep1 + iplayer1;
				if (lastrowvaluep1 == 7)
	 			{
	 	 			printf("Penalty for player 1 ...\n");
 					oldrowvaluep1=7-iplayer1;
 					if(temp==1)
 					{
 						oldrowvaluep1=5;
 						temp=0;
 					}
 					lastrowvaluep1 = 5;
 					temp++;	
 				}	
				if(lastrowvaluep1 > 13)
	 			{ 
	 				//will change direction in case of overflow
      				lastcolvaluep1 = lastcolvaluep1 - (lastrowvaluep1 - 13);	 	  
	    			lastrowvaluep1 = 13;
		 			go_player1 =3;   // going right to left
				}		
	 			array2d[lastrowvaluep1][lastcolvaluep1]= '1';
	 			array2d[oldrowvaluep1][28]= ' ';
	 			oldrowvaluep1=lastrowvaluep1;    // to assign null to old location in case of relocation
	 			oldcolvaluep1=lastcolvaluep1;				
	 			reset();
	 		}

	 		// PATH BOTTOM FOR PLAYER 1
	 		else if(go_player1 == 3)
	 		{
				yellow();	 			
	 			printf("PLAYER 1... press ENTER to dice...\n");
     			cplayer1=getchar();
     			iplayer1=dice();
	 	 		printf("DICE: %d \n",iplayer1);
	 	 		lastcolvaluep1 = lastcolvaluep1 - iplayer1;
	 			if(lastcolvaluep1 == 14)
	   			{
	    			printf("Penalty for player 1...\n");
			 		lastcolvaluep1 = 16; 
		 		}
				if(lastcolvaluep1 < 1)
	 			{		 
	 				//will change direction in case of overflow
       			lastrowvaluep1 = lastrowvaluep1 - ( 1 - lastcolvaluep1 );	 	 
	     		lastcolvaluep1 = 1;
		 		go_player1  = 4;   // bottom-up transitions
	 			}	
	 			array2d[lastrowvaluep1][lastcolvaluep1]= '1';
	 			array2d[13][oldcolvaluep1]= ' ';
	 			oldcolvaluep1=lastcolvaluep1;
	 			oldrowvaluep1=lastrowvaluep1;
	 			reset();
	 		}

	 		// PATH LEFT FOR PLAYER 1
	 		else if(go_player1 ==4)
	 		{
	 			yellow();
	 			printf("\nPLAYER 1... press ENTER to dice...\n");
      			cplayer1=getchar();
      			iplayer1=dice();
	    		printf("DICE: %d \n",iplayer1);
	    		lastrowvaluep1 = lastrowvaluep1 - iplayer1;
				if(lastrowvaluep1 <= 2)
	 			{ 
         			lastcolvaluep1 = 1;	// Pulls to starting position to end game
	    	 		lastrowvaluep1 = 1; // Pulls to starting position to end game
		 		 	go_player1  = 4;       // going right to left 
				 	printf(" *** PLAYER 1 WON THE GAME *** \n");
		 			endgame = 1;
		 			break;
	 			}		
	 			array2d[lastrowvaluep1][lastcolvaluep1]= '1';
	 			array2d[oldrowvaluep1][1]= ' ';
				oldrowvaluep1=lastrowvaluep1;    // to assign null to old location in case of relocation
	 			oldcolvaluep1=lastcolvaluep1;
	 			reset();
	 		}

	 		// -------------------------------- PLAYER 2 ----------------------------
	 	    //PATH TOP FOR PLAYER 2
	 	    if(go_player2==1)
	 		{
	 			blue();
	 			printf("\nPLAYER 2... press ENTER to dice...");
     		cplayer2=getchar();
     		iplayer2=dice();
	 	 		printf("DICE: %d \n",iplayer2);
	 	 		lastcolvaluep2 = lastcolvaluep2 + iplayer2;
	 			if (lastcolvaluep2 == 10)
	 			{
	  				printf("Penalty for player 2...\n");
	  				lastcolvaluep2 = 8; 	 
	 			}
	 			else if ( lastcolvaluep2 == 18   )
	 			{
	  				printf("Penalty for player 2...\n");
	  				lastcolvaluep2 = 16; 	 
	 			}
	 			else if (lastcolvaluep2 > 26)
	 			{ 
	 				//will change direction in case of overflow
      		lastrowvaluep2 = lastrowvaluep2 + lastcolvaluep2 - 26;	
		 			if(lastrowvaluep2 == 5)
		 			{
		  				printf("Penalty for player 2...\n");
		 					lastrowvaluep2=3;
		 			}  
	    		lastcolvaluep2 = 26;
		  		go_player2=2;  // going up and down
	 			}	
	 			array2d[lastrowvaluep2][lastcolvaluep2]= '2';
	 			array2d[3][oldcolvaluep2]= ' ';
	 			oldcolvaluep2=lastcolvaluep2;   //to assign null to old location in case of relocation
	 			oldrowvaluep2=lastrowvaluep2;
	 			reset();
	 		}

	 		//PATH RIGHT FOR PLAYER 2
	 		else if (go_player2==2)
	 		{
	 			blue();
	 			printf("PLAYER 2... press ENTER to dice...\n");
     		cplayer2=getchar();
     		iplayer2=dice();
	 			printf("DICE: %d \n",iplayer2);
	 			lastrowvaluep2 = lastrowvaluep2 + iplayer2;
	 			if(lastrowvaluep2 == 5)
	 			{
	  			printf("Penalty for player 2...\n");
	  			lastrowvaluep2 = 3; 	 
	 			}
				else if ( lastrowvaluep2 == 10 )
	 			{
	 				printf("Penalty for player 2...\n");
	 				lastrowvaluep2 = 8; 	 
				}	
				else if (lastrowvaluep2 > 11)
	 			{	 
	 				//will change direction in case of overflow
        	lastcolvaluep2 = lastcolvaluep2 - (lastrowvaluep2 - 11);	 
	      	lastrowvaluep2 = 11;
					go_player2=3;   
	 			}		
	 			array2d[lastrowvaluep2][lastcolvaluep2]= '2';
	 			array2d[oldrowvaluep2][26]= ' ';
	 			oldrowvaluep2=lastrowvaluep2;    // to assign null to old location in case of relocation
	 			oldcolvaluep2=lastcolvaluep2;
	 			reset();
	 		}

	 			//PATH BOTTOM FOR PLAYER 2
	 			else if(go_player2==3)
	 			{
	 				blue();
	 				printf("PLAYER 2... press ENTER to dice...\n");
     			cplayer2=getchar();
     	 	 	iplayer2=dice();
	 		 	 	printf("DICE: %d \n",iplayer2);
			   	lastcolvaluep2 = lastcolvaluep2 - iplayer2;	
	 	     	if(lastcolvaluep2 == 18)
	  			{
	     			printf("Penalty for player 2...\n");
			 			lastcolvaluep2 = 20; 
		 			}	 
	 				else if (lastcolvaluep2 == 10)
	 	    	{
	     			printf("Penalty for player 2...\n");
		 	 			lastcolvaluep2 = 12;  
	 				}	 
	  			else if (lastcolvaluep2 < 3)
	 	    	{ 
	 	    			//will change direction in case of overflow
      			lastrowvaluep2 = lastrowvaluep2 - ( 3 - lastcolvaluep2 );	 	 
	     			lastcolvaluep2 = 3;
		   			go_player2 = 4;   //  bottom-up transitions
	  			}	
	 				array2d[lastrowvaluep2][lastcolvaluep2]= '2';
	 				array2d[11][oldcolvaluep2]= ' ';
	 				oldcolvaluep2=lastcolvaluep2;
	 				oldrowvaluep2=lastrowvaluep2;
	 				reset();
	 			}

	 		//PATH LEFT FOR PLAYER 2
	 			else if(go_player2==4)
	 			{
	 				blue();
	 				printf("\nPLAYER 2... press ENTER to dice...\n");
    			cplayer2=getchar();
    			iplayer2=dice();
	  			printf("DICE: %d \n",iplayer2);
	  			lastrowvaluep2 = lastrowvaluep2 - iplayer2;
					if(lastrowvaluep2 <= 4)
	 				{ 
	  				lastcolvaluep2 = 3;	// Pulls to starting position to end game
	   				lastrowvaluep2 = 3; // Pulls to starting position to end game
		 				go_player2 = 4;       // going right to left
		 				printf(" *** PLAYER 2 WON THE GAME *** \n");
		 				endgame = 1;
	 				}			
	 				array2d[lastrowvaluep2][lastcolvaluep2]= '2';
					array2d[oldrowvaluep2][3]= ' ';
	 				oldrowvaluep2=lastrowvaluep2;    // to assign null to old location in case of relocation
	 				oldcolvaluep2=lastcolvaluep2;
	 				reset(); 
	 				if(endgame== 1 )
						break;	
	 			}
	 			printMap(array2d,15,30);
	  	  }
		}
	}

  else
  {
	while(endgame==0)
 	{	
	   while(go_player1<5  ||go_player2<5)
   	   { 
   		  // -------------------------------- PLAYER 2 ----------------------------
	 	  //PATH TOP FOR PLAYER 2
	 	    if(go_player2==1)
	 			{
	 				blue();
	 				printf("\nPLAYER 2... press ENTER to dice...");
     			cplayer2=getchar();
     			iplayer2=dice();
	 	 			printf("DICE: %d \n",iplayer2);
	 	 			lastcolvaluep2 = lastcolvaluep2 + iplayer2;
	 				if (lastcolvaluep2 == 10)
	 				{
	  				printf("Penalty for player 2...\n");
	  				lastcolvaluep2 = 8; 	 
	 				}
	 				else if ( lastcolvaluep2 == 18   )
	 				{
	  				printf("Penalty for player 2...\n");
	  				lastcolvaluep2 = 16; 	 
	 				}
	 				else if (lastcolvaluep2 > 26)
	 				{ 
	 				//will change direction in case of overflow
      			lastrowvaluep2 = lastrowvaluep2 + lastcolvaluep2 - 26;	 
		 				if(lastrowvaluep2 == 5)
		 				{
		  				printf("Penalty for player 2...\n");
		 					lastrowvaluep2=3;
		 				}  
	    			lastcolvaluep2 = 26;
		  			go_player2=2;  // going up and down
	 				}	
	 				array2d[lastrowvaluep2][lastcolvaluep2]= '2';
	 				array2d[3][oldcolvaluep2]= ' ';
	 				oldcolvaluep2=lastcolvaluep2;   //to assign null to old location in case of relocation
	 				oldrowvaluep2=lastrowvaluep2;
	 				reset();
	 			}
	 		//PATH RIGHT FOR PLAYER 2
	 			else if (go_player2==2)
	 			{
	 			blue();
	 			printf("PLAYER 2... press ENTER to dice...\n");
     		cplayer2=getchar();
     		iplayer2=dice();
	 			printf("DICE: %d \n",iplayer2);
	 			lastrowvaluep2 = lastrowvaluep2 + iplayer2;
	 			if(lastrowvaluep2 == 5)
	 			{
	  			printf("Penalty for player 2...\n");
	  			lastrowvaluep2 = 3; 	 
	 			}
				else if ( lastrowvaluep2 == 10 )
	 			{
	 				printf("Penalty for player 2...\n");
	 				lastrowvaluep2 = 8; 	 
				}	
				else if (lastrowvaluep2 > 11)
	 			{	 
	 				//will change direction in case of overflow
        	lastcolvaluep2 = lastcolvaluep2 - (lastrowvaluep2 - 11);	
	      	lastrowvaluep2 = 11;
					go_player2=3;   // going right to left
	 			}		
	 			array2d[lastrowvaluep2][lastcolvaluep2]= '2';
	 			array2d[oldrowvaluep2][26]= ' ';
	 			oldrowvaluep2=lastrowvaluep2;    // to assign null to old location in case of relocation
	 			oldcolvaluep2=lastcolvaluep2;
	 			reset();
	 		}

	 		//PATH BOTTOM FOR PLAYER 2
			else if(go_player2==3)
	 		{
	 			blue();
	 			printf("PLAYER 2... press ENTER to dice...\n");
     		cplayer2=getchar();
     	 	iplayer2=dice();
	 		 	printf("DICE: %d \n",iplayer2);
				lastcolvaluep2 = lastcolvaluep2 - iplayer2;	
	 			if(lastcolvaluep2 == 18)
	  		{
	     		printf("Penalty for player 2...\n");
					lastcolvaluep2 = 20; 
		 		}	 
	 			else if(lastcolvaluep2 == 10)
	 			{
	     		printf("Penalty for player 2...\n");
		 	 		lastcolvaluep2 = 12;  
	 			}	 
	  		else if(lastcolvaluep2 < 3 )
	 	    {
	 			//will change direction in case of overflow 
      		lastrowvaluep2 = lastrowvaluep2 - ( 3 - lastcolvaluep2 );	 	 
	     		lastcolvaluep2 = 3;
		   		go_player2 = 4;   // bottom-up transitions
	  		}	
	 			array2d[lastrowvaluep2][lastcolvaluep2]= '2';
	 			array2d[11][oldcolvaluep2]= ' ';
	 			oldcolvaluep2=lastcolvaluep2;
	 			oldrowvaluep2=lastrowvaluep2;
	 			reset();
	 		}

	 		//PATH LEFT FOR PLAYER 2
	 		else if(go_player2==4)
	 		{
	 			blue();
	 			printf("\nPLAYER 2... press ENTER to dice...\n");
    		cplayer2=getchar();
    		iplayer2=dice();
	  		printf("DICE: %d \n",iplayer2);

	  		lastrowvaluep2 = lastrowvaluep2 - iplayer2;
				if(lastrowvaluep2 <= 4)
	 			{ 
	  			lastcolvaluep2 = 3;	// Pulls to starting position to end game
	   			lastrowvaluep2 = 3; // Pulls to starting position to end game
		 			go_player2 = 4;       // going right to left
		 			printf(" *** PLAYER 2 WON THE GAME *** \n");
		 			endgame = 1;
	 			}				
	 			array2d[lastrowvaluep2][lastcolvaluep2]= '2';
				array2d[oldrowvaluep2][3]= ' ';
	 			oldrowvaluep2=lastrowvaluep2;    // to assign null to old location in case of relocation
	 			oldcolvaluep2=lastcolvaluep2;
				reset(); 
	 		}
			//--------------------------PLAYER 1  -------------------------------
	 		//PATH TOP FOR PLAYER 1
	 		if(go_player1==1)
	 		{
	 			yellow();
	 			printf("\nPLAYER 1... press ENTER to dice...");
     		cplayer1=getchar();
     		iplayer1=dice();
		 		printf("DICE: %d \n",iplayer1);
		 		lastcolvaluep1 = lastcolvaluep1 + iplayer1;
				if(lastcolvaluep1 == 14)
	 	 		{
	 				printf("Penalty for player 1 ...\n");
 					oldcolvaluep1=14-iplayer1;
 					if(temp==1)
 					{
 						oldcolvaluep1=10;
 						temp=0;
 					}
 					lastcolvaluep1 = 12;
 					temp++;	 	 
 				}
	 
	 			if(lastcolvaluep1 > 28)
	 			{ 		
	 				//will change direction in case of overflow
      		lastrowvaluep1 = lastrowvaluep1 + lastcolvaluep1 - 28;	 
	    		lastcolvaluep1 = 28;
		 			go_player1=2;  // going up and down
	 			}	
				array2d[lastrowvaluep1][lastcolvaluep1]= '1';
				array2d[1][oldcolvaluep1]= ' ';
	 			oldcolvaluep1=lastcolvaluep1;   //to assign null to old location in case of relocation
	 			oldrowvaluep1=lastrowvaluep1;
	 			reset();
	 		}

	 		//PATH RIGHT FOR PLAYER 1
	 		else if(go_player1==2)
	 		{
	 			yellow();
	 			printf("PLAYER 1... press ENTER to dice...\n");
    		cplayer1=getchar();
    		iplayer1=dice();
	 			printf("DICE: %d \n",iplayer1);
	 			lastrowvaluep1 = lastrowvaluep1 + iplayer1;
				if(lastrowvaluep1 == 7 )
	 			{
	 	 			printf("Penalty for player 1 ...\n");
 					oldrowvaluep1=7-iplayer1;
 					if(temp==1)
 					{
 						oldrowvaluep1=5;
 						temp=0;
 					}
 					lastrowvaluep1 = 5;
 					temp++;	
 				}	
				if(lastrowvaluep1 > 13)
	 			{
	 				//will change direction in case of overflow 
      		lastcolvaluep1 = lastcolvaluep1 - (lastrowvaluep1 - 13);	  
	    		lastrowvaluep1 = 13;
		 			go_player1=3;   
				}		
	 			array2d[lastrowvaluep1][lastcolvaluep1]= '1';
	 			array2d[oldrowvaluep1][28]= ' ';
	 			oldrowvaluep1=lastrowvaluep1;   
	 			oldcolvaluep1=lastcolvaluep1;				
	 			reset();
	 		}


	 		//PATH BOTTOM FOR PLAYER 1
	 		else if(go_player1==3)
	 		{
				yellow();	 			
	 			printf("PLAYER 1... press ENTER to dice...\n");
     		cplayer1=getchar();
     		iplayer1=dice();
	 	 		printf("DICE: %d \n",iplayer1);
	 	 		lastcolvaluep1 = lastcolvaluep1 - iplayer1;
	 			if(lastcolvaluep1 == 14)
	   		{
	    		printf("Penalty for player 1...\n");
			 		lastcolvaluep1 = 16; 
		 		}
				if(lastcolvaluep1 < 1)
	 			{		 
	 				//will change direction in case of overflow
       		lastrowvaluep1 = lastrowvaluep1 - ( 1 - lastcolvaluep1 );	 	 
	     		lastcolvaluep1 = 1;
		 			go_player1 = 4;  
	 			}	
	 			array2d[lastrowvaluep1][lastcolvaluep1]= '1';
	 			array2d[13][oldcolvaluep1]= ' ';
	 			oldcolvaluep1=lastcolvaluep1;
	 			oldrowvaluep1=lastrowvaluep1;
	 			reset();
	 		}

	 		//PATH LEFT FOR PLAYER 1
	 		else if(go_player1==4)
	 		{
	 			yellow();
	 			printf("\nPLAYER 1... press ENTER to dice...\n");
      	cplayer1=getchar();
      	iplayer1=dice();
	    	printf("DICE: %d \n",iplayer1);
	    	lastrowvaluep1 = lastrowvaluep1 - iplayer1;
				if(lastrowvaluep1 <= 2)
	 			{ 
					lastcolvaluep1 = 1;	
	    		lastrowvaluep1 = 1; 
		 		 	go_player1 = 4;        
				 	printf(" *** PLAYER 1 WON THE GAME *** \n");
		 			endgame = 1;
		 			break;
	 			}		
	 			array2d[lastrowvaluep1][lastcolvaluep1]= '1';
	 			array2d[oldrowvaluep1][1]= ' ';
				oldrowvaluep1=lastrowvaluep1;    
	 			oldcolvaluep1=lastcolvaluep1;
	 			reset();
	 		}
	 		printMap(array2d,15,30);
	 		if(endgame == 1 )
			break;	
	   }
		}
  }

  return 0; 	
}	 	


