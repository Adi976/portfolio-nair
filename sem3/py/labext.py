'''1.a) Write a python program to find the best of two 
test average marks out of three test’s marks 
accepted from the user. 

num1=(int)(input("Enter 1st Test Marks:"))
num2=(int)(input("Enter 2nd Test Marks:"))
num3=(int)(input("Enter 3rd Test Marks:"))

Minimum=min(num1,num2,num3) 
sum=num1+num2+num3-Minimum 
Avg=sum/2 

arr=[num1,num2,num3]
arr.sort(reverse=True)
avgMarks=(arr[0]+arr[1])/2
print("Best of two:",avgMarks)
'''

'''
b) Develop a Python program to check whether a 
given number is palindrome or not and also count 
the number of occurrences of each digit in the input 
number.

num = int(input("Enter a number:"))

def palin(num):
    pal = 0
    while(num > 0):
        pal = pal * 10 + num % 10
        num //= 10
    return pal

rev = palin(num)
if rev == num:
    print("Palindrome Number")
else:
    print("Not Palindrome Number")
 
#2nd Approach

def is_palindrome(s):
    return s == s[::-1]

# Example usage:
word = "radar"
if is_palindrome(word):
    print(f"{word} is a palindrome.")
else:
    print(f"{word} is not a palindrome.")
'''

'''2.a) Defined as a function F as Fn = Fn-1 + Fn-2. 
Write a Python program which accepts a value for 
N (where N >0) as input and pass this value to the 
function. Display suitable error message if the 
condition for input value is not followed.

def Fibonacci(n): 
    if n==1: 
        return 0 
    elif n==2: 
        return 1 
    else: 
        return (Fibonacci(n-1)+Fibonacci(n-2)) 
 
 
num=int(input("Enter the number\n")) 
if num>0: 
    res=Fibonacci(num) 
    print("Fibonacci of ", num ,"is",res) 
else: 
    print("Error in the  input") 
 
b) Develop a python program to convert binary to 
decimal, octal to hexadecimal using functions. 


def bin2dec(bin): 
    l=len(bin) 
    dec=0 
    for i in range(l): 
        dec+=int(bin[i])*(2**(l-i-1)) 
    return dec 
 
def oct2hex(oct): 
    l=len(oct) 
    dec=0 
    for i in range(l): 
        dec+=int(oct[i])*(8**(l-i-1)) 
    hexa=['0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'] 
    octhex=' ' 
    while dec>0: 
       rem=dec%16 
       octhex=hexa[rem]+octhex 
       dec=dec//16 
    return octhex 

bin=input("Enter the Binary Number:") 
print("Binary to Decimal is",bin2dec(bin)) 
oct=input("Enter the octal Number:") 
print("Octal to Decimal is",oct2hex(oct)) 
  
3.a) Write a Python program that accepts a sentence 
and find the number of words, digits, uppercase 
letters and lowercase letters. 

sentence = input("Enter a sentence : ") 
digCnt = upCnt = loCnt =wordcnt=0 
wordcont=sentence.split() 
 
for ch in sentence: 
    if ch>='0' and ch<='9': 
        digCnt += 1 
    if ch>='A'and ch<='Z': 
        upCnt += 1 
    if ch>='a' and ch<='z': 
        loCnt += 1 
 
print("This sentence has\n") 
print("words: ", len(wordcont),"\n" "digits",digCnt, ) 
print("upper case letters",upCnt, "\n" "lower case letters ",loCnt)

  
b) Write a Python program to find the string 
similarity between two given strings 
 
 def compare(s,p): 
    count=0 
    n=min(len(s),len(p)) 
    for i in range(n): 
        if s[i]==p[i]: 
            count+=1 
    return count
     
s1 = input("Enter String 1 \n") 
s2 = input("Enter String 2 \n") 
mx=max(len(s1),len(s2)) 
count=compare(s1,s2) 
similarity=count/mx*100 
print ("Total number letter matched is",count) 
print("simirality between two string is",similarity) 
  
4.  
a) Write a Python program to Demonstrate how to 
Draw a Bar Plot using Matplotlib. 
b) Write a Python program to Demonstrate how to 
Draw a Scatter Plot using Matplotlib. 
  
5.  
a) Write a Python program to Demonstrate how to 
Draw a Histogram Plot using Matplotlib. 
b) Write a Python program to Demonstrate how to 
Draw a Pie Chart using Matplotlib. 
  
6.  
a) Write a Python program to illustrate Linear 
Plotting using Matplotlib. 
b) Write a Python program to illustrate liner 
plotting with line formatting using Matplotlib. 
  
7.  Write a Python program which explains uses of 
customizing seaborn plots with Aesthetic functions. 
  
8.  
Write a Python program to explain working with 
bokeh line graph using Annotations and Legends. 
 
a) Write a Python program for plotting different 
types of plots using Bokeh. 
 
  
9.  Write a Python program to draw 3D Plots using 
Plotly Libraries. 
  
10.  
a) Write a Python program to draw Time Series 
using Plotly Libraries. 
b) Write a Python program for creating Maps using 
Plotly Libraries. '''
