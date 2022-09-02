#include <stdio.h>
void red () {
  printf("\033[1;31m");
}

void reset () {
  printf("\033[0m");
}
void coefficient(int a,int b,int c)
{
	printf("Please enter the coefficient for the following equation: x = a * (y * y) + b * y + c");
	printf("\n\na:");
	scanf("%d",&a);
	printf("b:");
	scanf("%d",&b);
	printf("c:");
	scanf("%d",&c);

	FILE *coefficient = fopen("coefficients.txt","w+");
	fprintf(coefficient, "%d\n%d\n%d\n",a,b,c);
	printf("\ncoefficients.txt file has been created");
}

void draw_graph()
{
	int a , b , c;												
	FILE *read=fopen("coefficients.txt","r");         		//coeffcients in txt file
	
	if(read==NULL)
	{
		printf("The file with this name does not exist.");
		
	}
	else
	{
		fscanf(read,"%d %d %d",&a,&b,&c);
			
	}
	fclose(read);
	int x ,  y =15;

	do
	{	
		x=((a*(y*y))+(b*y)+c);           // Since the value on our x line is 50 at most, the part that will ensure that the value does not exceed 50 as a result of the equation
		if(x>50)
		{
			y--;	
		}

	}while(x>50);

	
	int y_top=y;
	int x_top=x; 
	
	

	
	int control = 0 , number = -50 ,control1=2 , number1=15;   //variables to use to specify the numbers on the axes in the chart
	for(int i=0 ; i<33 ; i++)  // line
	{
		for(int j=0 ; j<125 ; j++) // column
		{
			if((x<=50 && x>=-50)&&(y<=15 && y>=-15))      //where the y-axis is positive, the equation is plotted, but it does not draw some of it correctly
			{
				if(x>0)
				{
					if(i==y_top+2 && j==(x*2)+15)
					{		
						printf("#");
						y--;
						x=((a*(y*y))+(b*y)+c);
						y_top++;
					}
				}
				else if(x<0)
				{

				}
					
			}
			if(i==16)  // drawing x plane
			{
				if(j==0)
				{
					printf("<");
					  //  the beginning of the x line

				}
				else if(j==124)
				{
					printf(">");
					  // end of x line
				}
				else
				{
					printf("-");		// remainder
					
				}
			}


			else if(i==17)  // writing x plane's numbers
			{
				
				if(j==control)			
				{
					if(number<51)   
					{
						red();
						printf("%d",number);

						reset();
							
					}		
					control+=10;
					number+=10;	
				}

				else if(j==52)
				{
					printf("|");
					
				}
				
				else if (i==y_top+2 && j==(x*2)+15)
							{
								/* code */
							}			
				else
				{
					printf(" ");
					
				}
			}

			else if (i==control1)  // writing y plane's numbers
			{	

				if(j==58)
				{	
					
					if(number1>5)
					{	
						red();
						printf("%d  ",number1);
						reset();
					
						printf("|");
					}
					else if(number1<-5)
					{
						red();
						printf("%d ",number1);
						
						reset();
						
						printf("|");
						
					}
					else if(number1==5)
					{
						red();
						printf("%d   ",number1);
						reset();
						
						printf("|");
						 
					}					
				}
				else if(j==124)
				{
					control1+=5;
					number1-=5;
				}
				else
				{
					printf(" ");
					
				}
				if(control1==17)
				{
					control1+=5;
					number1-=5;	
				}
			}
			else     // drawing y plane
			{	
				if(i==0 && j==48)
				{
					printf("^");
					
				}
				else if(j==62)
				{
					printf("|");
				}
				else
				{
					printf(" ");
				}
			}		
		}
		printf("\n");

	}
}

void draw_graph2()
{

	int a , b , c;												
	FILE *read=fopen("coefficients.txt","r");         		//coeffcients in txt file
	FILE *write=fopen("graph.txt","w");
	if(read==NULL)
	{
		printf("The file with this name does not exist.");
		
	}
	else
	{
		fscanf(read,"%d %d %d",&a,&b,&c);
			
	}
	fclose(read);
	int x ,  y =15;

	do
	{	
		x=((a*(y*y))+(b*y)+c);           // Since the value on our x line is 50 at most, the part that will ensure that the value does not exceed 50 as a result of the equation
		if(x>50)
		{
			y--;	
		}

	}while(x>50);

	
	int y_top=y;
	int x_top=x; 
	
	

	
	int control = 0 , number = -50 ,control1=2 , number1=15;   //variables to use to specify the numbers on the axes in the chart
	for(int i=0 ; i<33 ; i++)  // line
	{
		for(int j=0 ; j<125 ; j++) // column
		{
			if((x<=50 && x>=-50)&&(y<=15 && y>=-15))      //where the y-axis is positive, the equation is plotted, but it does not draw some of it correctly
			{
				if(x>0)
				{
					if(i==y_top+2 && j==(x*2)+15)  
					{		
						fprintf(write,"#");
						y--;
						x=((a*(y*y))+(b*y)+c);
						y_top++;
					}
				}
				else if(x<0)
				{

				}
					
			}
			
			if(i==16)  // drawing x plane
			{
				if(j==0)
				{
					
					fprintf(write,"<");  //  the beginning of the x line

				}
				else if(j==124)
				{
					
					fprintf(write,">");  // end of x line
				}
				else
				{
							// remainder
					fprintf(write,"-");
				}
			}


			else if(i==17)  // writing x plane's numbers
			{
				
				if(j==control)			
				{
					if(number<51)   
					{
					
						fprintf(write,"%d",number);							
					}		
					control+=10;
					number+=10;	
				}

				else if(j==52)
				{
					
					fprintf(write,"|");
				}
							
				else
				{
					
					fprintf(write," ");
				}
			}

			else if (i==control1)  // writing y plane's numbers
			{	

				if(j==58)
				{	
					
					if(number1>5)
					{	
						fprintf(write,"%d  ",number1);
						fprintf(write,"|");
					}
					else if(number1<-5)
					{
						fprintf(write,"%d ",number1);
						fprintf(write,"|");
					}
					else if(number1==5)
					{
						fprintf(write,"%d   ",number1);
						fprintf(write,"|"); 
					}					
				}
				else if(j==124)
				{
					control1+=5;
					number1-=5;
				}
				else
				{
					fprintf(write," ");
				}
				if(control1==17)
				{
					control1+=5;
					number1-=5;	
				}
			}
			else     // drawing y plane
			{	
				if(i==0 && j==48)
				{
					fprintf(write,"^");
				}
				else if(j==62)
				{
					fprintf(write,"|");
				}
				else
				{
					fprintf(write," ");
				}
			}		
		}
		
		fprintf(write,"\n");
	}

	printf("Coefficients has been read from the coefficient file.\n");
	printf("The graph of x = %d * (y*y) + %d * y + %d",a,b,c);
}

int main()
{
	int select;
	int a,b,c;
	printf("Select an operation..\n");
	printf("0 -> Enter the coefficient.\n");
	printf("1 -> Draw the graph\n");
	printf("2 -> Print the graph into a.txt file.\n");
	printf("3 -> Exit\n");

	printf("Choice : ");
	scanf("%d",&select);
	printf("\n");
	while (select<0 && select>3)
	{
		printf("Select numbers from 1 to 4 for selection");
		scanf("%d",select);
	}

	if(select==0)
	{
		coefficient(a,b,c);  // entered the coefficient
	}
	else if(select==1)
	{
		draw_graph();  // drawing the graph

	}
	else if(select==2)
	{
		draw_graph2();  //drawing the graph in graph.txt
		
	}
	else if(select==3)  // exit program.
 	{	 
		
	}
	return 0;
}