/*#include <stdio.h>
int main()
{
char s[30];
int n,l,u,mid;
printf("Enter the number of words to be entered\n");
scanf("%d",&n);
printf("Enter the words\n");
for(int i=0;i<n;i++)
{
    scanf("%c",&s[i]);
}
printf("%s",s);


char ary[] = "RNSIT CSE";
printf("%s", ary);
For example, if you print the string "Hello\rWorld" to the console, the cursor will move back to the beginning
of the line after printing "Hello", and then "World" will overwrite "Hello", resulting in the output "World".
*/

/*
 int i = 0;
 printf("Hello");
 char s[4] = {'\b', '\t', '\r', '\n'};
 for (i = 0; i < 4; i++)
 {
     printf("%c", s[i]);
     printf("CCCC");
 }
 */
/*
int i = 0;
char s[4] = {'\0', '\0', '\0', '\0'};
for(i = 0;i<4;i++)
{
    printf("%c", s[i]);
}
 */

/* Sine series 
#include <stdio.h>
#include <math.h>
#define PI 3.142
    int main()
    {
        int i, degree;
        float x, sum = 0, term, nume, deno;
        printf("Enter the angle in degree\n");
        scanf("%d", &degree);
        x = degree * (PI / 180); // converting degree into radian
        nume = x;
        deno = 1;
        i = 2;
        do
        { // calculating the sine value.
            term = nume / deno;
            nume = -nume * x * x;
            deno = deno * i * (i + 1);
            sum = sum + term;
            i = i + 2;
        } // Accurate to 4 decimal point digits
        while (fabs(term) >= 0.00001);
        printf("The sine of %d is %.3f\n", degree, sum);
        printf("The sine function of %d is %.3f", degree, sin(x));
    }
    */
   #include <stdio.h>
#include <math.h>
#define PI 3.14159265 // Use a more accurate value for PI

int main() {
    int i, degree;
    float x, sum = 1.0, term, nume = 1.0, deno = 1.0; // Initialize sum to 1.0 for cos(0)

    printf("Enter the angle in degree\n");
    scanf("%d", &degree);
    x = degree * (PI / 180); // Convert degree to radian

    // Calculate the Taylor series for cosine
    for (i = 2; i <= 10; i += 2) { // Calculate up to the 10th term
        nume = -nume * x * x;
        deno = deno * i * (i - 1);
        term = nume / deno;
        sum += term;
    }

    printf("The cosine of %d is %.3f\n", degree, sum);
    printf("The cosine function of %d is %.3f", degree, cos(x));

    return 0;
}

