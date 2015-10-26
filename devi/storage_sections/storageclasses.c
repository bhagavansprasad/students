
                            Storage classes in c 

In c there are four types of storage class. They are:
1. auto
2. register
3. static
4. extern
Storage class is modifier or qualifier of data types which decides:

1.In which area of memory a particular variable will be stored?   
2. What is scope of variable?
3. What is visibility of variable? 

Visibility of a variable in c:

    Visibility means accessibility. Up to witch part or area of a program, we can access a variable, that area or part is known as visibility of that variable. For example: In the following figure yellow color represents visibility of variable a.



Scope of a variable in c:

    Meaning of scope is to check either variable is alive or dead. Alive means data of a variable has not destroyed from memory. Up to which part or area of the program a variable is alive, that area or part is known as scope of a variable. In the above figure scope of variable a represented outer red box i.e. whole program. 
Note: If any variable is not visible it may have scope i.e. it is alive or may not have scope. But if any variable has not scope i.e. it is dead then variable must not to be visible. 
There are four type of scope in c:

1. Block scope.
2. Function scope.
3. File scope.
3. Program scope.

Block scope:

    In c block is represented area between opening curly bracket i.e. {and closing curly bracket i.e.}. Example of blocks in c.


In the c code there are three blocks shown in yellow color. In the above code one more block which is main function block. If a variable or function has scope only within the scope where it has declared then scope of variable or function is called as block scope and if a variable or function is visible is only within a block where it has declared then that variable or function is called as block visible.   

Function block: 

A block of function body has special name, function block. From storage class point of view there is not any difference between function block and any other blocks in c. Because there is not any modifiers of storage class group which has function block. Importance of function block can understand when we deal with goto statement. Label of goto statement has function block scope. Label of particular goto statement is not visible in another function. For example:

#include<stdio.h> 
void display();
int main(){
    printf("In MAIN");    
    goto xyz;
    return 0;
}
void display(){
    xyx:;
    printf("In DISPLay");
}

Output: Compilation error

File scope:

    If any variable or function has scope only within a file where it has declared then scope of variable or function is known file scope. If any variable or function is visible only within a file where it has declared then visibility of that variable or function is called file visible. 

Program scope:

    If any variable or function has scope whole of the program, program may contain one or more files then scope of variable or function is known program scope. If any variable or function which is visible in the whole program, program may contain one or more file then variable or function, that variables or functions are called as program visible.
Scope and visibility of storage class:



auto storage class in c 
auto:

Automatic variables or auto variables are default storage class of local variable. An auto variable cannot be declared globally. (Why?)

Properties of auto storage class.

(1) Default initial value of auto variable is garbage. For example:

#include<stdio.h>
int main(){
    int i;
    auto char c;
    float f;
    printf("%d  %c  %f",i,c,f);
    return 0;
} 

Output: Garbage Garbage Garbage

(2)Visibility of auto variable is within the block where it has declared. For examples:
(a)
#include<stdio.h>
int main(){
    int a=10;
    {
         int a=20;
         printf("%d",a);
    }
    printf(" %d",a);
    return 0;
} 
Output: 20 10
Explanation: Visibility of variable a which has declared inside inner has block only within that block.
(b) 
#include<stdio.h>
int main(){
    {
         int a=20;
         printf("%d",a);
    }
    printf(" %d",a); // a is not visible here
    return 0;
} 

Output: Compilation error
Explanation: Visibility of variable a which has declared inside inner block has only within that block.

Question: What will be output of following c code?

#include<stdio.h>
int main(){
    int a=0;
    {
         int a=10;
         printf("%d",a);
         a++;
         {
             a=20;
         }
         {
             printf(" %d",a);
             int a=30; {a++;}
             printf(" %d",a++);
         }
         printf(" %d",a++);
    }
    printf(" %d",a); 
    return 0;
} 

(3) Scope of auto variable is within the block where it has declared. For example:

(a)
#include<stdio.h>
int main(){
    int i;
    for(i=0;i<4;i++){
         int a=20;
         printf("%d",a);
         a++;
    }
    return 0;
} 

Output: 20 20 20 20
Explanation: Variable declared inside the for loop block has scope only within that block. After the first iteration variable a becomes dead and it looses its incremented value. In second iteration variable a is again declared and initialized and so on. 

(b)
#include<stdio.h>
int main(){
    int i=0;
    {
         auto int a=20;
         XYZ:;
         printf("%d",a);
         a++;
         i++; 
    }
    if (i<3)
         goto xyz;
    return 0;
} 

Output: Compilation error.
Explanation: Variable a which declared inside inner block has scope only within that block. Ones program control comes out of that block variable will be dead. If with the help of goto statement we will go to inside that inner block in the printf statement complier will not known about variable a because it has been destroyed already. Hence complier will show an error message: undefined symbol a. But if you will write goto statement label before the declaration of variable then there is not any problem because variable a will again declared and initialize. 

#include<stdio.h>
int main(){
    int i=0;
    {
         XYZ:;
         auto int a=20;
         printf("%d",a);
         a++;
         i++; 
    }
    if (i<3)
         goto xyz;
    return 0;
} 

Output: 20 20 20

(4) From above example it is clear auto variable initialize each time.
(5)An auto variable gets memory at run time.

static variable in c 

static keyword in c:

    Keyword static is used for declaring static variables in c. This modifier is used with all data types like int, float, double, array, pointer, structure, function etc.

Important points about static keyword:

1. It is not default storage class of global variables. For example, analyze the following three programs and its output.

(a)

#include<stdio.h>
int a;
int main(){
    printf("%d",a);
    return 0;
}

Output: 0

(b)
#include<stdio.h>
static int a;
int main(){
    printf("%d",a);
    return 0;
}

Output: 0

(c)
#include<stdio.h>
extern int a;
int main(){
    printf("%d",a);
    return 0;
}
Output: Compilation error

At first glance if you will observe the output of above three codes you can say default storage class of global variable is static. But it is not true. Why? Read extern storage class.

2. Default initial value of static integral type variables are zero otherwise null. For example:

#include <stdio.h>
static char c;
static int i; 
static float f;
static char *str;   
int main(){
    printf("%d %d %f %s",c,i,f,str);
    return 0;
} 

Output: 0 0 0.000000 (null)

3. A same static variable can be declared many times but we can initialize at only one time. For example:

(a)
#include <stdio.h>
static int i;        //Declaring the variable i.
static int i=25;     //Initializing the variable.
static int i;        //Again declaring the variable i.
int main(){
    static int i;    //Again declaring the variable i.
    printf("%d",i);
    return 0;
} 

Output: 25

(b)
#include <stdio.h> 
static int i;        //Declaring the variable
static int i=25;     //Initializing the variable
int main(){
         printf("%d",i);
    return 0;
} 
static int i=20;     //Again initializing the variable

Output: Compilation error: Multiple initialization variable i.

4. We cannot write any assignment statement globally. For example:
#include <stdio.h> 
static int i=10;   //Initialization statement
i=25;              //Assignment statement
int main(){
    printf("%d",i);
    return 0;
} 
             
Output: Compilation error

Note: Assigning any value to the variable at the time of declaration is known as initialization while assigning any value to variable not at the time of declaration is known assignment.

(b)
#include <stdio.h> 
static int i=10;
int main(){
    i=25;       //Assignment statement
    printf("%d",i);
    return 0;
}

Output: 25

(5) A static variable initializes only one time in whole program. For example:

#include <stdio.h> 
static int i=10;
int main(){
    i=5;
    for(i=0;i<5;i++){
         static int a=10; //This statement will execute 
                          //only time.
         printf("%d",a++);//This statement will execute 
                          //five times.
    }   
    return 0;
}

Output: 10 11 12 13 14

(6)If we declared static variable locally then its visibility will within a block where it has declared. For example:

#include<stdio.h>
int main(){
    {                        
         static int a=5;      
         printf("%d",a);
    }                        
    //printf("%d",a);   variable a is not visible here.
    return 0;    
}

Output: 5

7. If declared a static variable or function globally then its visibility will only the file in which it has declared not in the other files. For example:

(a)
#include<stdio.h>
static float a=144.0f; //global to all function
int main(){
    {                         
         printf("%d",a); //variable a is visible here.
       //printf("%d",b); variable b is not visible here.
    }                        
    printf("%d",a);   //variable a is visible here.
    //printf("%d",b);    variable b is not visible here.
    return 0;
}
static int b=5;    //Global to only calculation function
void calculation(){
    printf("%d",a);   //variable a is visible here.
    printf("%d",b);   //variable b is visible here.
}
   
(b) Consider a c program which has written in two files named as one.c and two.c: 

//one.c

#include<conio.h>
static int i=25; 
static int j=5;  

void main(){
    clrscr();
    sum();
    getch();
}

//two.c

#include<stdio.h>
extern int i; //Declaration of variable i.
extern int j; //Declaration of variable j.
/**
Above two lines will search the initialization statement of variable i and j either in two.c (if initialized variable is static or extern) or one.c (if initialized variable is extern)  
*/
extern void sum(){
    int s;
    s=i+j;
    printf("%d",s);
}

Compile and execute above two file one.c and two.c at the same time:
In Turbo c compiler

Step 1: Write above two codes in the file named as one.c and two.c (You can give any name as you like) and save it.
Step 2: In Turbo c++ IDE click on Project -> Open project menu as shown in following screen dump.




Step 3: After Clicking on open project you will get following screen:




In Open project File text field write any project name with .prj extension. In this example I am writing project name as CProject.PRJ. Now press OK button.

Step 4: After pressing OK button you will get following screen:


  

Now click on Project -> Add item menu.
Step 5: After clicking Add item you will get following screen:




In the name text field write down all c source code file one by one i.e. first write one.c and click on Add button
Then write two.c and click on Add button and so on




Step 6: At the end click on Done button. After clicking on done button you will get following screen:




At the lower part of window you can see project name, list of files you have added etc.

Step7: To compile the two files press Alt+F9 and to run the above program press Ctrl+F9 
Note: To close the project click on Project -> Close project.

Output: Compilation error: Unknown symbol i and j.

Hence we can say variable i and j which has initialized into two.c is not visible in file one.c. This example proves visibility of globally declared static variable is file.

Note: In the above example function sum which was declared and defined in two.c has also storage class extern. So we can call from other file (one.c).If it will static then we cannot call function sum since static storage class is only visible to the file where it has declared.

(8)If we static variable has declared locally or globally its scope will always whole the program. For example:

(a) //locally declaration of static variable

#include<stdio.h>
void visit();
int main(){
    int i=0;
    {                    //Opening inner block
         static int a=5;  //locally declaration
         XYZ:;            //Label of goto statement
         printf("%d  ",a);
         a++;
         i++; 
    }                     //closing inner block.    
    visit(); 
    /* printf("%d",a); Variable a is not visible here but 
    it is alive. */
    if(i<5)
             goto XYZ;
    return 0;
}
void visit(){
    
}

Output: 5 6 7 8 9

Explanation: When program control will come out of inner block where variable a has declared then outside of inner block variable a is not visible but its scope is outside the program i.e. variable a hasn’t dead .If with help of goto statement control again comes inside the inner block it prints previous incremented values which was not possible in case of auto or register variables.
(b) 

//Locally declarations of variable   
There are two c source code files:
//one.c
#include<stdio.h>
#include<conio.h>
void main(){
    int i;
    for(i=0;i<3;i++){
         {
             static int a=5;
             printf("%d\n",a);
             a++; 
         }
         visit();
    }
    getch();
}
//two.c
#include<stdio.h>
void visit(){
    printf("Don’t disturb, I am learning storage class");
    /* printf("%d",a); Variable a is not visible here but 
    It is alive. */
}

Now compile and execute both files together:
Output:
5
disturb, I am learning storage class
6
disturb, I am learning storage class
7
disturb, I am learning storage class

Explanation: When control goes to another file and comes even that variable didn’t dead and it prints previous incremented value.
Note: In both examples if you will declare static variable globally you will get same output.


9. A static variables or functions have internal linkage. An internal linkage variables or functions are visible to the file where it has declared. 












register storage class in c 
A register storage class is very similar to auto storage class except one most important property. All register variable in c stores in CPU not in the memory. 

Important points about register storage class

(1)In following declaration:

    register int a;

We are only requesting not forcing to compiler to store variable a in CPU. Compiler will decide where to store in the variable a.

(2)A register variable execute faster than other variables because it is stored in CPU so during the execution compiler has no extra burden to bring the variable from memory to CPU.

(3)Since a CPU have limited number of register so it is programmer responsibility which variable should declared as register variable i.e. variable which are using many times should declared as a register variable.

(4) We cannot dereference register variable since it has not any memory address. For example:
      
(a)
#include<stdio.h>
int main(){
    register int a=10;
    int *p;
    p=&a;
    printf("%u",p);
}

Output: Compilation error

(b) 
#include<stdio.h>
int main(){
    register int a,b;
    scanf("%d%d",&a,&b);
    printf("%d  %d",a,b);
}

Output: Compilation error

(5) Default initial value of register variable is garbage.

(6)Scope and visibility of register variable is block.
(7)





extern keyword in c 
Keyword extern is used for declaring extern variables in c. This modifier is used with all data types like int, float, double, array, pointer, structure, function etc. 

Important points about extern keyword:

1. It is default storage class of all global variables as well all functions. For example, Analyze following two c code and its output:

(a)
#include <stdio.h>
int i;    //By default it is extern variable
int main(){
    printf("%d",i);
    return 0;
} 

Output: 0 

(b)

#include <stdio.h>
extern int i;    //extern variable
int main(){
    printf("%d",i);
    return 0;
}

Output: Compilation error, undefined symbol i.

Question: In Both program variable i is extern variable. But why output is different? Read second and third points.

(c)

#include <stdio.h>
void sum(int,int) //By default it is extern.
int main(){
    int a=5,b=10;
    sum(a,b);
    return 0;
}
void sum(int a,int b){
    printf("%d”",a+b);
}

Output: 15

2. When we use extern modifier with any variables it is only declaration i.e. memory is not allocated for these variable. Hence in second case compiler is showing error unknown symbol i. To define a variable i.e. allocate the memory for extern variables it is necessary to initialize the variables. For example:

#include <stdio.h>
extern int i=10;    //extern variable
int main(){
    printf("%d",i);
    return 0;
} 

Output: 10 

3. If you will not use extern keyword with global variables then compiler will automatically initialize with default value to extern variable.

4. Default initial value of extern integral type variable is zero otherwise null. For example:

#include <stdio.h>
char c;
int i; 
float f;
char *str;   
int main(){
    printf("%d %d %f %s",c,i,f,str);
    return 0;
} 

Output: 0 0 0.000000 (null)

5. We cannot initialize extern variable locally i.e. within any block either at the time of declaration or separately. We can only initialize extern variable globally. For example:

(a)
#include <stdio.h> 
int main(){
extern int i=10; //Try to initialize extern variable 
                 //locally.
    printf("%d",i);
    return 0;
} 
Output: Compilation error: Cannot initialize extern variable.

(b)
#include <stdio.h> 
int main(){
    extern int i; //Declaration of extern variable i.
    int i=10;     //Try to locally initialization of 
                  //extern variable i.
    printf("%d",i);
    return 0;
} 

Output: Compilation error: Multiple declaration of variable i.

6. If we declare any variable as extern variable then it searches that variable either it has been initialized or not. If it has been initialized which may be either extern or static* then it is ok otherwise compiler will show an error. For example:

(a)
#include <stdio.h> 
int main(){
    extern int i; //It will search the initialization of 
                  //variable i. 
    printf("%d",i);
    return 0;
} 
int i=20;    //Initialization of variable i.

Output: 20

(b)
#include <stdio.h> 
int main(){
extern int i; //It will search the any initialized 
              //variable i which may be static or  
              //extern.
printf("%d",i);
    return 0;
} 
extern int i=20; //Initialization of extern variable i.

Output: 20
(c)
#include <stdio.h> 
int main(){
extern int i; //It will search the any initialized 
              //variable i which may be static or  
              //extern.
    printf("%d",i);
    return 0;
} 
static int i=20; //Initialization of static variable i.


Output: 20

(d)
#include <stdio.h> 
int main(){
    extern int i;   //variable i has declared but not 
                    //initialized
    printf("%d",i);
    return 0;
} 

Output: Compilation error: Unknown symbol i.

7. A particular extern variable can be declared many times but we can initialize at only one time. For example:

(a)
extern int i; //Declaring the variable i.
int i=25;     //Initializing the variable.
extern int i; //Again declaring the variable i.
#include <stdio.h> 
int main(){
    extern int i; //Again declaring the variable i.
    printf("%d",i);
    return 0;
} 


Output: 25

(b)
extern int i; //Declaring the variable
int i=25;     //Initializing the variable
#include <stdio.h> 
int main(){
         printf("%d",i);
    return 0;
} 
int i=20; //Initializing the variable


Output: Compilation error: Multiple initialization variable i.

8. We cannot write any assignment statement globally. For example:

#include <stdio.h> 
extern int i;
int i=10;   //Initialization statement
i=25;       //Assignment statement
int main(){
    printf("%d",i);
    return 0;
} 

Output: Compilation error
Note: Assigning any value to the variable at the time of declaration is known as initialization while assigning any value to variable not at the time of declaration is known assignment.
(b)
#include <stdio.h> 
extern int i;
int main(){
    i=25;       //Assignment statement
    printf("%d",i);
    return 0;
}
int i=10;   //Initialization statement

Output: 25

9. If declared an extern variables or function globally then its visibility will whole the program which may contain one file or many files. For example consider a c program which has written in two files named as one.c and two.c: 
(a)

//one.c

#include<conio.h>
int i=25; //By default extern variable
int j=5;  //By default extern variable
/**
Above two line is initialization of variable i and j.
*/
void main(){
    clrscr();
    sum();
    getch();
}

//two.c

#include<stdio.h>
extern int i; //Declaration of variable i.
extern int j; //Declaration of variable j.
/**
Above two lines will search the initialization statement of variable i and j either in two.c (if initialized variable is static or extern) or one.c (if initialized variable is extern)  
*/
void sum(){
    int s;
    s=i+j;
    printf("%d",s);
}

Compile and execute above two file one.c and two.c at the same time:

In Turbo c compiler

Step 1: Write above two codes in the file named as one.c and two.c (You can give any name as you like) and save it.
Step 2: In Turbo c++ IDE click on Project -> Open project menu as shown in following screen dump.




Step 3: After Clicking on open project you will get following screen:





In Open project File text field write any project name with .prj extension. In this example I am writing project name as CProject.PRJ. Now press OK button.

Step 4: After pressing OK button you will get following screen:


  

Now click on Project -> Add item menu.

Step 5: After clicking Add item you will get following screen:




In the name text field write down all c source code file one by one i.e. first write one.c and click on Add button
Then write two.c and click on Add button and so on




Step 6: At the end click on Done button. After clicking on done button you will get following screen:




At the lower part of window you can see project name, list of files you have added etc.
Step7: To compile the two files press Alt+F9 and to run the above program press Ctrl+F9 

Note: To close the project click on Project -> Close project.

Output: 30

Hence we can say variable i and j which has initialized into two.c is also visible in file one.c. This example proves visibility of globally declared extern variable is program.

Note: In the above example function sum which was declared and defined in two.c has also storage class extern. So we can call from other file (one.c).If it will static then we cannot call function sum since static storage class is only visible to the file where it has declared.
10. An extern variables or functions have external linkage. An external linkage variables or functions are visible to all files. 


