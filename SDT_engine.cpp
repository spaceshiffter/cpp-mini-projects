/*
PLT Assignment
Problem 20-
Design a SDT Engine such that it evaluates the expression for a given desk calculator
grammar.

*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;

float stack[100];char num[20],trexpr[1000];
int c=0;int point=0;

void fillnumfn()// default assignment in num array
{
	int i;
	for(i=0;i<20;i++)
	num[i]='/';
}

void fillstackfs()//default assignment in stack array
{
	int i;
	for(i=0;i<100;i++)
	stack[i]=99;
}

void pushstackps(char a[],int b)// fun with two arguements that pushes the elements into the stack
{
	float temp2;
	if(b==2)
	{
        c=c+1;
        fillnumfn();
	}
	else if(b==1)
	{
		temp2=atof(a);
		stack[c]=temp2;
	}
	else
	{
		temp2=atof(a);
		stack[c]=temp2;
	}
}


void printstackps()//print the elements of the stack
{
	int i;
	if(trexpr[point])
        printf("\nInput pointer:\t%c\n",trexpr[point]);
	else
        printf("\nInput pointer:\tString complete\n");
        printf("\n\nStack content:\n");
	for(i=c;i>=0;i--)
	{
		if(stack[i]!=99)
		{
            if(stack[i]==91)
            printf("\t+");
            else if(stack[i]==92)
            printf("\t-");
		else if(stack[i]==93)
            printf("\t*");
		else if(stack[i]==94)
            printf("\t/");
		else if(stack[i]==95)
            printf("\t%c",'%');
		else if(stack[i]==96)
            printf("\t^");
		else
            printf("\t%f",stack[i]);
		}
	}
	printf("\n\n");
}
void ordero(char a)// giving the precedence operator relationship
{
	int i,j,z;
	switch(a)
	{
		case '+':
			for(i=0;i<c;i++)
			{
				if(stack[i]==96)
				{
					stack[i-1]=pow(stack[i-1],stack[i+1]);
					for(j=i;j<=c;j++)
					{
						stack[j]=stack[j+2];
					}
					c=c-2;
					i=i-2;
					printstackps();
				}
			}
			for(i=0;i<c;i++)
			{
				if(stack[i]==94)
				{
					if(stack[i+1]!=0)
					stack[i-1]=stack[i-1]/stack[i+1];
					else
					{
						printf("\nDivision by zero is an error.\n");
						exit(0);
					}
					for(j=i;j<=c;j++)
					{
						stack[j]=stack[j+2];
					}
					c=c-2;
					i=i-2;
					printstackps();
				}
			}
			for(i=0;i<c;i++)
			{
				if(stack[i]==95)
				{
					float t1,t2;
					t1=ceilf(stack[i-1]);
					t2=ceilf(stack[i+1]);
					if(t1==stack[i-1] && t2==stack[i+1])
					{
                        stack[i-1]=(int)stack[i-1]%(int)stack[i+1];
                        for(j=i;j<=c;j++)
                        {
                            stack[j]=stack[j+2];
                        }
                        c=c-2;
                        i=i-2;
                        printstackps();
					}
				else
				{
					printf("\n Can't use modulus with decimal values.");
					exit(0);
				}
				}
			}
			for(i=0;i<c;i++)
			{
				if(stack[i]==93)
				{
					stack[i-1]=stack[i-1]*stack[i+1];
					for(j=i;j<=c;j++)
					{
						stack[j]=stack[j+2];
					}
					c=c-2;
					i=i-2;
					printstackps();
				}
			}
			for(i=0;i<c;i++)
			{
				if(stack[i]==92)
				{
					if(stack[i+1]>0)
                        stack[i-1]=stack[i-1]-stack[i+1];
					else
                        stack[i-1]=stack[i-1]+stack[i+1];
					for(j=i;j<=c;j++)
					{
						stack[j]=stack[j+2];
					}
					c=c-2;
					i=i-2;
					printstackps();
				}
			}
		break;
		case '-':
			for(i=0;i<c;i++)
			{
				if(stack[i]==96)
				{
					stack[i-1]=pow(stack[i-1],stack[i+1]);
					for(j=i;j<=c;j++)
					{
						stack[j]=stack[j+2];
					}
					c=c-2;
					i=i-2;
					printstackps();
				}
			}
			for(i=0;i<c;i++)
			{
				if(stack[i]==94)
				{
					if(stack[i+1]!=0)
                        stack[i-1]=stack[i-1]/stack[i+1];
					else
					{
						printf("\nDivision by zero is an error.\n");
						exit(0);
					}
					for(j=i;j<=c;j++)
					{
						stack[j]=stack[j+2];
					}
					c=c-2;
					i=i-2;
					printstackps();
				}
			}
				for(i=0;i<c;i++)
                {
                    if(stack[i]==95)
                    {
                        float t1,t2;
                        t1=ceilf(stack[i-1]);
                        t2=ceilf(stack[i+1]);
                        if(t1==stack[i-1] && t2==stack[i+1])
                        {
                            stack[i-1]=(int)stack[i-1]%(int)stack[i+1];
                            for(j=i;j<=c;j++)
                            {
                                stack[j]=stack[j+2];
                            }
                            c=c-2;
                            i=i-2;
                            printstackps();
                        }
                    else
                    {
                        printf("\n Can't use modulus with decimal values.");
                        exit(0);
                    }
                    }
                }
			for(i=0;i<c;i++)
			{
				if(stack[i]==93)
				{
					stack[i-1]=stack[i-1]*stack[i+1];
					for(j=i;j<=c;j++)
					{
						stack[j]=stack[j+2];
					}
					c=c-2;
					i=i-2;
					printstackps();
				}
			}
		break;
			case '*':
			for(i=0;i<c;i++)
			{
				if(stack[i]==96)
				{
					stack[i-1]=pow(stack[i-1],stack[i+1]);
					for(j=i;j<=c;j++)
					{
						stack[j]=stack[j+2];
					}
					c=c-2;
					i=i-2;
					printstackps();
				}
			}
			for(i=0;i<c;i++)
			{
				if(stack[i]==94)
				{
					if(stack[i+1]!=0)
                        stack[i-1]=stack[i-1]/stack[i+1];
					else
					{
						printf("\nDivision by zero is an error.\n");
						exit(0);
					}
					for(j=i;j<=c;j++)
					{
						stack[j]=stack[j+2];
					}
					c=c-2;
					i=i-2;
					printstackps();
				}
			}
			for(i=0;i<c;i++)
			{
				if(stack[i]==95)
				{
					float t1,t2;
					t1=ceilf(stack[i-1]);
					t2=ceilf(stack[i+1]);
					if(t1==stack[i-1] && t2==stack[i+1])
					{
                        stack[i-1]=(int)stack[i-1]%(int)stack[i+1];
					for(j=i;j<=c;j++)
					{
						stack[j]=stack[j+2];
					}
					c=c-2;
					i=i-2;
					printstackps();
					}
                    else
                    {
                        printf("\n Can't use modulus with decimal values.");
                        exit(0);
                    }
                }
			}
			break;
			case '%':
				for(i=0;i<c;i++)
                {
                    if(stack[i]==96)
                    {
                        stack[i-1]=pow(stack[i-1],stack[i+1]);
                        for(j=i;j<=c;j++)
                        {
                            stack[j]=stack[j+2];
                        }
                        c=c-2;
                        i=i-2;
                        printstackps();
                    }
                }
                for(i=0;i<c;i++)
                {
                    if(stack[i]==94)
                    {
                        if(stack[i+1]!=0)
                            stack[i-1]=stack[i-1]/stack[i+1];
                        else
                        {
                            printf("\nDivision by zero is an error.\n");
                            exit(0);
                        }
                        for(j=i;j<=c;j++)
                        {
                            stack[j]=stack[j+2];
                        }
                        c=c-2;
                        i=i-2;
                        printstackps();
                    }
                }
                break;
			case '/':
			for(i=0;i<c;i++)
			{
				if(stack[i]==96)
				{
					stack[i-1]=pow(stack[i-1],stack[i+1]);
					for(j=i;j<=c;j++)
					{
						stack[j]=stack[j+2];
					}
					c=c-2;
					i=i-2;
					printstackps();
				}
			}
	}
}
void evaluatest()//evaluation of the sum/sub/division/multlplication/power
{
	int i,j,y;
	int z;
	z=c/2;
	for(i=c;i>=0;i--)
	{
		if(stack[i]==91)
		{
            stack[i-1]=stack[i-1]+stack[i+1];
            for(j=i;j<20;j++)
                {
                    stack[j]=99;
                }
            c=c-2;
            printstackps();
		}
		if(stack[i]==92)
		{
			if(stack[i+1]<0)
                stack[i-1]=stack[i-1]+stack[i+1];
            else
                stack[i-1]=stack[i-1]-stack[i+1];
            for(j=i;j<20;j++)
                {
                    stack[j]=99;
                }
            c=c-2;
            printstackps();
          //  break;
		}
		if(stack[i]==93)
		{
			stack[i-1]=stack[i-1]*stack[i+1];
			for(j=i;j<20;j++)
					{
						stack[j]=99;
					}
            c=c-2;
            printstackps();
            //break;
		}
		if(stack[i]==94)
		{
			if(stack[i+1]!=0)
                stack[i-1]=stack[i-1]/stack[i+1];
			else
			{
				printf("\n Division by zero is an error.\n");
				exit(0);
			}
			for(j=i;j<20;j++)
                {
                    stack[j]=99;
                }
            c=c-2;
            printstackps();
            //break;
		}
		if(stack[i]==95)
		{
			float t1,t2;
			t1=ceilf(stack[i-1]);
			t2=ceilf(stack[i+1]);
			if(t1==stack[i-1] && t2==stack[i+1])
                stack[i-1]=(int)stack[i-1]%(int)stack[i+1];
			else
			{
				printf("\n Cannot find modulus by decimals.\n");
				exit(0);
			}
			for(j=i;j<20;j++)
					{
						stack[j]=99;
					}
            c=c-2;
            printstackps();
            //break;
		}
		if(stack[i]==96)
		{
			stack[i-1]=pow(stack[i-1],stack[i+1]);
			for(j=i;j<20;j++)
					{
						stack[j]=99;
					}
            c=c-2;
            printstackps();
            //break;
		}
	}

}
void pushstackps(char a)//pushes the elements in to array.......fun with one arguement
{
	switch(a)
	{
		case '+':
			pushstackps(num,2);
			ordero(a);
			stack[c++]=91;
			break;
		case '-':
			pushstackps(num,2);
			ordero(a);
			stack[c++]=92;
			break;
		case '*':
			pushstackps(num,2);
			ordero(a);
			stack[c++]=93;
			break;
		case '/':
			pushstackps(num,2);
			ordero(a);
			stack[c++]=94;
			break;
		case '%':
			pushstackps(num,2);
			ordero(a);
			stack[c++]=95;
			break;
		case '^':
			pushstackps(num,2);
			ordero(a);
			stack[c++]=96;
			break;
		default:
		if(a>='0'&& a<='9'||a=='.')
		{
			int i;
			for(i=0;i<20;i++)
			{
				if(num[i]=='/')
				{
                    num[i]=a;
                    if(i==0)
                        pushstackps(num,0);
                    else
                        pushstackps(num,1);
                        break;
				}
			}
			printstackps();
		}
		else
			printf("\nInvalid operator.\n");
	}
}
int main()
{
	printf("Expression to calculate:\n");
	char expr[1000];
	fillnumfn();
	fillstackfs();
	gets(expr);
	strcpy(trexpr,expr);
	int exprlen,i,flag=0,j;
	char ch,ch1;
	exprlen=strlen(expr);
	expr[exprlen]=';';
	for(i=0;i<=exprlen;i++)
	{
        ch=expr[i];
        point=i;
        if((ch>='0'&&ch<='9')||ch=='.')
        {
            pushstackps(ch);
        }
        else if(ch=='+'||ch=='*'||ch=='/'||ch=='-'||ch=='%'||ch=='^')
        {
            ch1=expr[i-1];
            if(ch1=='+'||ch1=='*'||ch1=='/'||ch1=='-'||ch1=='%'||ch1=='^')
            {
                printstackps();
                printf("\nConsecutive operators are not allowed\n");
                exit(0);
            }
            else
                pushstackps(ch);
        }
        else
        {
            pushstackps(num,2);
            evaluatest();
        }
	}
	here: evaluatest();
	printf("\nAnswer: %f",stack[0]);
	getch();
	return 0;
}
