#include<iostream>
using namespace std;
#include<stdio.h>
/*int main()
{
    char c[100];
    int i;
    gets(c);
    for(i=0;c[i]!='\0';++i);

    cout<<i;

}*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

void printmenu();
void printlist(char *s[],int *a);
void insertname(char *s[],int *a);
void deletename(char *s[],int *a);
int main()
{
 char *str[20],name[20];
 int *n,m,length,i,choice;
 printf("enter size:");
 scanf("%d",&m);
 n=&m;
 for(i=0;i<*n;i++)
 {
     printf("Enter %d name:",i+1);
     scanf("%s",name);
     length=strlen(name);
     *(str+i)=(char*)malloc(length+1);
     strcpy(*(str+i),name);
 }
 do
{
     printmenu();
     printf("Enter your choice:");
     scanf("%d",&choice);
     switch(choice)
     {
         case 1:
             printf("\nThe names in the list are:\n");
             printlist(str,n);
             break;
         case 2:
             insertname(str,n);
             printf("\nList after inserting a name is:\n");
             printlist(str,n);
             break;
         case 3:
             deletename(str,n);
             break;
         case 4:
            break;
         default:
             printf("\nInvalid user option");
             break;
     }

 }
 while(choice!=4);
}
void printmenu()
{
     printf("\tChoose any one of the following\n");
     printf("\t Enter 1 To Print the list of names\n ");
     printf("\t Enter 2 To Insert a student name into list\n");
     printf("\t Enter 3 To Delete a student name from the list\n");
     printf("\t Enter 4 To Exit.\n");

}
void printlist(char *s[],int *a)
{
    int i;
    printf("\n\No.\tName\n");
    for(i=0;i<*a;i++)
    {
        printf("%d \t%s\n",i+1,*(s+i));
    }
}

void insertname(char *s[],int *a)
{
    int pos,i;
    char name[20];
    printf("Enter a name to be inserted:");
    scanf("%s",name);
    printf("Enter a position where the name will be inserted:");
    scanf("%d",&pos);

    for(i=*a-1;i>=pos-1;i--)
        {
            strcpy(*(s+i+1),*(s+i));
            strcpy(*(s+pos-1),name);
            (*a)++;
        }
    printf("\nGiven name is inserted successfully");
}

void deletename(char *s[],int *a)
{
    int pos,i,j,flag=0;
    char name[20];
    printf("Enter a name to be deleted:");
    scanf("%s",name);
    for(i=0;i<*a;i++)
    {
        if(strcmp(name,*(s+i))==0)
        {
            flag=1;
            for(j=i;j<*a-1;j++)
            strcpy(*(s+j),*(s+j+1));
            (*a)--;
        }
    }
 if(flag==1)
 {
     printf("\nGiven name is deleted successfully");
     printf("\nList after deleting a name is:\n");
     printlist(s,a);
 }
 else
     printf("\nGiven name is not found in the list\n.");

}

