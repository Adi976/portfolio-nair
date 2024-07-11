#include <stdio.h>
#include<stdlib.h>
int main()
{
/*int x = 0;
if(! x)
{
printf("Hello");
}
else
{
printf("%d",(!x));
printf("hai");
}
int x = 0, y = 0;
if( x )
{
printf("Hello");
}
if( ! x && ! y )
printf("hey");
else 
printf("fine");

int n;
printf("Enter the number of rows for the pascals triangle\n");
scanf("%d",&n);
for(int i=1;i<=n;i++)
{
    for(int j=0;j<n-i;j++)
    {
        printf(" ");
    }
    for(int k=1;k<=i;k++)
    {
        printf("%d",k);
    }
    for(int l=i-1;l>=1;l--)
    {
        printf("%d",l);
    }
    printf("\n");
}

int a[30],i,num,key,low,mid,high;//Variables declaration
printf("\n Enter the Number of Elements");
scanf("%d",&num); //Read num
printf("\n Enter the Elements in Sorted Order : ");
for(i=0;i<num;i++)
scanf("%d",&a[i]);
printf("\nEnter the key element to be searched\n");
scanf("%d",&key); //Read key
low=0;//Assigning low to 0
high=num-1; // Assigning high to n-1
while(low<=high)
{
mid=(low + high)/2; //Find out mid value
if(a[mid]==key) //Compare a[mid] with key
{
printf("element %d is found at %d position:",key,mid+1);
exit(0); //Exit from the program
}
else if(a[mid]>key)
high=mid-1;
else
low=mid+1;
}
printf("UNSUCCESSFULL SEARCH\n");

char ary[]="RNSIT CSE";
printf("%s",ary);

Sure! Here are the details of each of the escape sequences with examples:

- `\b`: Backspace (ASCII code 08)
  - This escape sequence moves the cursor back one character position. 
  It is often used to remove the last character from a string.
  - Example: `"Hello\bWorld"` will output `"HellWorld"`.
- `\t`: Horizontal tab (ASCII code 09)
  - This escape sequence moves the cursor to the next tab stop. It is often used to align text in columns.
  - Example: `"Name\tAge\tGender\nJohn\t25\tMale\nJane\t30\tFemale"` will output:

    ```
    Name    Age     Gender
    John    25      Male
    Jane    30      Female
    ```
- `\r`: Carriage return (ASCII code 13)
  - This escape sequence moves the cursor to the beginning of the current line.
   It is often used to overwrite text on the same line.
  - Example: `"Hello\rWorld"` will output `"World"`.
- `\n`: Newline (ASCII code 10)
  - This escape sequence moves the cursor to the beginning of the next line. 
  It is often used to start a new line of text.
  - Example: `"Hello\nWorld"` will output:

    ```
    Hello
    World
    ```


int i = 0;
//printf("Hello");
char s[4] = {'\b', '\t', '\r', '\n'};
for(i = 0;i<4;i++){
printf("%c", s[i]);
printf("%d",48+i);
}
*/

return 0;
}
