/*
    “PROJECT ON :
      STUDENTS RECORD SYSTEM USING LINKED LIST DATA STRUCTURE.”

                                                        BY : 17CO04 - PRANALI PRAKASH KOKATE
                                                               : 17CO10 - ALFINA MOHAMMED SAYYED
                                                               : 17CO09 - RAHEMAT LAZIM SAYYAD  


      This is the project to collect the record of the students. The project is implemented by using 
      Linked Lists. We have taken the first name, last name, rollno, pointer ,department of the 
      student as the input.
       We have user defined functions such as : insert, delete, display, edit ,search etc.
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

typedef struct STUDENT                                                       //defining structure
{
char fname[50];                                                                  //First name of the student
char lname[50];                                                                  //Last name of the student
int rollno;                                                                           //Roll no. of the student
float pointer;                                                                         //Pointer of the student
char dept[10];                                                                     //Department of the student
struct STUDENT *next;                                                     //Self referential structure
}node;

node *create( node *head)                                                //Function to create a node
{
   node *p,*temp;
   p=(node*)malloc(sizeof(node));                     //dynamic memory allocation for new node
   if(p==NULL)                                                 // checking whether memory is allocated or not
{
  printf("\n NOT ENOUGH MEMORY ");
   return head;		}
else                                                                      //Taking info of the student from user
{
printf("\nENTER THE FIRST NAME OF THE STUDENT: ");
scanf("%s",p->fname);
printf("\nENTER THE LAST NAME  OF THE STUDENT: ");
scanf("%s",p->lname);
printf("\nENTER STUDENT ROLL NO: ");
scanf("%d",&p->rollno);
printf("\nENTER STUDENT POINTER: ");
scanf("%f",&p->pointer);
printf("\nENTER THE DEPARTMENT: ");
scanf("%s",p->dept);
p->next=NULL;
printf("\n\t\tINFO ADDED SUCCESSFULLY\n\n");
}
if(head==NULL)
head=p;                                                     //The new node is the first node in the LL
else
{
temp=head;                
while(temp->next!=NULL)                                              //while loop for traversing
temp=temp->next;                                                   
temp->next=p;
	}
return head;
}

node *display(node *head)                       //Function to display the info of the students
{
  node *temp;
   temp=head;
 if(head!=NULL)                                               //checking whether LL is empty
{
  printf("INFO OF STUDENTS:\n");
  printf("\nFIRST NAME\tLAST NAME\tROLL NO\t\tPOINTER\t\tDEPARTMENT\t");
  while(temp!=NULL)
{
printf("\n%s\t\t%s\t\t%d\t\t%f\t%s",temp->fname,temp->lname,temp->rollno,temp->pointer,temp->dept);
temp=temp->next;
}
 }
 else
 {
printf("NO RECORDS AVAILABLE. ");
}
return head;
}

node *insertAfter(node *head)                         //Function to insert a node after a node
{
int key;
node *p,*temp;
printf("\n\nENTER THE ROLL NO AFTER WHICH YOU WANT TO INSERT THE INFO:  ");
scanf("%d",&key);
temp=head;
while(temp!=NULL && temp->rollno!=key)               //Traversing to find given Roll no.
{
temp=temp->next;
}
if(temp==NULL)
printf("\n\nROLL NO DOES NOT EXIST\n");

else
{
p=(node *)malloc(sizeof(node));            
if(p==NULL)                                                          //if memory not allocated by the OS 
{
printf("\n NOT ENOUGH MEMORY");
return head;
}
 else
{
 printf("\nENTER THE FIRST NAME OF THE STUDENT: ");
scanf("%s",p->fname);
printf("\nENTER THE LAST NAME  OF THE STUDENT: ");
scanf("%s",p->lname);
printf("\nENTER STUDENT ROLL NO: ");
scanf("%d",&p->rollno);
printf("\nENTER STUDENT POINTER: ");
scanf("%f",&p->pointer);
printf("\nENTER THE DEPARTMENT: ");
scanf("%s",p->dept);
p->next=NULL;
//printf("\n\t\tINFO ADDED SUCCESSFULLY\n\n");
temp=head;
while(temp!=NULL && temp->rollno!=key)               //Traversing to find given Roll no.
{
temp=temp->next;
}
if(temp!=NULL)
{
p->next=temp->next;
temp->next=p;
printf("\n\t\tINFO ADDED SUCCESSFULLY\n\n");
}
else
{
temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
temp->next=p;
printf("\n\t\tINFO ADDED SUCCESSFULLY\n\n");
}
}
}
}
return head;
}

node *delete(node *head )                                   //To remove the given node(Record)
{
 node *temp,*prev;
int key;
printf("\nENTER THE STUDENT ROLL NO YOU WANT TO DELETE: "); 
scanf("%d",&key);
temp=head;
if(head!=NULL)
{
if(head->next!=NULL)
{
while( temp!=NULL  && temp->rollno!=key)             //Traversing to find given Roll No.
{
prev=temp;
temp=temp->next;
}
if(temp==NULL)
{
printf("\n\nCANNOT DELETE....ROLL NO DOES NOT EXIST\n");	
}
else
{
prev->next=temp->next;
temp->next=NULL;
free(temp);
printf("DELETED SUCCESSFULLY\n\n");
}                                                                                    //freeing temp
}
else
{
head=NULL;                                                                //when the only node in the LL is deleted
free(temp);
printf("DELETED SUCCESSFULLY\n\n");
}

}
else
{
printf("EMPTY RECORD\n");
}
return head;
}

void search(node *head)                                                  //Function to search node(Record)
{
node *temp;
temp=head;
int key;
printf("\nENTER THE ROLL NO: ");                         //Taking roll no of student from user
scanf("%d",&key);
while(temp!=NULL && temp->rollno!=key)              //Traversing to find given Roll no.
temp=temp->next;
if(temp==NULL)
printf("\n\nSTUDENT ROLL NO NOT FOUND\n");
else                                             // checking whether the roll no is equal to key
{
 printf("\nINFO FOUND:\n");
printf("\nFIRST NAME\tLAST NAME\tROLL NO\t\tPOINTER\t\tDEPARTMENT\t");
printf("\n%s\t\t%s\t\t%d\t\t%f\t%s",temp->fname,temp->lname,temp->rollno,temp->pointer,temp->dept);
}
}

node * edit(node *head)                                                   //Function to edit any record
{
node *p,*temp,*prev;
int key;
temp=head;
printf("\n\nENTER THE ROLL NO YOU WANT TO EDIT: ");
scanf("%d",&key);
while(temp!=NULL && temp->rollno!=key)                                //loop for traversing
{
 prev=temp;
 temp=temp->next;
}
if(temp==NULL)
{
printf("\n\nROLL NO DOES NOT EXIST\n\n");	
}
else
{
p=(node *)malloc(sizeof(node));
if(p==NULL)                                                                //if memory not allocated by OS
{
    printf("NOT ENOUGH MEMORY");
}
else
{
printf("\n\nENTER THE NEW INFO: ");
printf("\nENTER THE FIRST NAME OF THE STUDENT: ");
scanf("%s",p->fname);
printf("\nENTER THE LAST NAME  OF THE STUDENT: ");
scanf("%s",p->lname);
printf("\nENTER STUDENT ROLL NO: ");
scanf("%d",&p->rollno);
printf("\nENTER STUDENT POINTER: ");
scanf("%f",&p->pointer);
printf("\nENTER THE DEPARTMENT: ");
scanf("%s",p->dept);
p->next=NULL;
if(temp==head)                                                        //if there exists only one node in the LL
{
head=p;
p->next=NULL;
free(temp);
}
else                                                                      //if there are multiple nodes in the linked list
{
if(temp->rollno==key)                                                     
p->next=temp->next;
prev->next=p;
temp->next=NULL;
free(temp);
}
printf("\n\nINFO EDITED SUCCESSFULLY");
}
}
return head;
}

 int main()                                                                                  //Main function
{
int ch;
node *h;
h=NULL;                                                                           //initializing head as NULL
while(1)
{
printf("\n---------------------------------------------------------------------------------------------");
printf("\n\t\t\t\tANJUMAN-I-ISLAM'S KALSEKAR TECHNICAL CAMPUS\n");
printf("\t\t\t\t\t\tNEW PANVEL\n");
printf("----------------------------------------------------------------------------------------------\n\n");
printf("\t\t\t----------------STUDENT RECORDS--------------\n\n");
printf("\t1.ADDING A NEW RECORD\n");
printf("\t2.DISPLAYING THE RECORD\n");
printf("\t3.INSERTING A RECORD AFTER AN ANOTHER RECORD\n");
printf("\t4.DELETING ANY RECORD\n");
printf("\t5.SEARCH ANY STUDENT'S RECORD\n");
printf("\t6.EDITING RECORDS\n");
printf("\t7.EXIT\n");
printf("\nENTER YOUR CHOICE: ");                             //Taking input from user
scanf("%d",&ch);
switch(ch)
{
    case 1:
    h=create(h);                                                                      //Call to the function create
    break;
    case 2:
    display(h);                                                                         //Call to the function display
    break;
    case 3:
    h=insertAfter(h);                                                                   //Call to the function insertAfter
    break;
    case  4:
    h=delete(h);                                                                        //Call to the function delete
    break;
    case 5:
    search(h);                                                                           //Call to the function search
    break;
    case 6:
    h=edit(h);                                                                          //Call to edit function
    break;
    case 7:
     exit(0);
    break;
    default:
    printf("\n\tENTER VALID OPTION\n");
   }
}
return 0;
}

/*
 CONCLUSION:  
 The aim of the project was to create a student record through which the user is allowed to insert,
 delete, edit, search and display the records of the students. To arrange the students data is       
 very important in colleges. So with the help of this project, the user is able to use all the functions 
 on the student record. 
 Thus ,with the help of this project we understood the implementation of Linked List data structure .
 At the end of this project we are able to  insert, delete, edit, search and display the records of the students.
  
 
  OUTPUT:

---------------------------------------------------------------------------------------------
                                ANJUMAN-I-ISLAM'S KALSEKAR TECHNICAL CAMPUS
                                                NEW PANVEL
----------------------------------------------------------------------------------------------

                        ----------------STUDENT RECORDS--------------

        1.ADDING A NEW RECORD
        2.DISPLAYING THE RECORD
        3.INSERTING A RECORD AFTER AN ANOTHER RECORD
        4.DELETING ANY RECORD
        5.SEARCH ANY STUDENT'S RECORD
        6.EDITING RECORDS
        7.EXIT

ENTER YOUR CHOICE: 1

ENTER THE FIRST NAME OF THE STUDENT: Pranali

ENTER THE LAST NAME  OF THE STUDENT: Kokate

ENTER STUDENT ROLL NO: 4

ENTER STUDENT POINTER: 8.07

ENTER THE DEPARTMENT: Computers

                INFO ADDED SUCCESSFULLY


---------------------------------------------------------------------------------------------
                                ANJUMAN-I-ISLAM'S KALSEKAR TECHNICAL CAMPUS
                                                NEW PANVEL
----------------------------------------------------------------------------------------------

                        ----------------STUDENT RECORDS--------------

        1.ADDING A NEW RECORD
        2.DISPLAYING THE RECORD
        3.INSERTING A RECORD AFTER AN ANOTHER RECORD
        4.DELETING ANY RECORD
        5.SEARCH ANY STUDENT'S RECORD
        6.EDITING RECORDS
        7.EXIT

ENTER YOUR CHOICE: 1

ENTER THE FIRST NAME OF THE STUDENT: Alfina

ENTER THE LAST NAME  OF THE STUDENT: Sayyed

ENTER STUDENT ROLL NO: 10

ENTER STUDENT POINTER: 8.70

ENTER THE DEPARTMENT: Mechanical

                INFO ADDED SUCCESSFULLY


---------------------------------------------------------------------------------------------
                                ANJUMAN-I-ISLAM'S KALSEKAR TECHNICAL CAMPUS
                                                NEW PANVEL
----------------------------------------------------------------------------------------------

                        ----------------STUDENT RECORDS--------------

        1.ADDING A NEW RECORD
        2.DISPLAYING THE RECORD
        3.INSERTING A RECORD AFTER AN ANOTHER RECORD
        4.DELETING ANY RECORD
        5.SEARCH ANY STUDENT'S RECORD
        6.EDITING RECORDS
        7.EXIT

ENTER YOUR CHOICE: 3


ENTER THE ROLL NO AFTER WHICH YOU WANT TO INSERT THE INFO:  4

ENTER THE FIRST NAME OF THE STUDENT: Rehamat

ENTER THE LAST NAME  OF THE STUDENT: Sayyad

ENTER STUDENT ROLL NO: 9

ENTER STUDENT POINTER: 7.8

ENTER THE DEPARTMENT: Extc

                INFO ADDED SUCCESSFULLY


                INFO ADDED SUCCESSFULLY


---------------------------------------------------------------------------------------------
                                ANJUMAN-I-ISLAM'S KALSEKAR TECHNICAL CAMPUS
                                                NEW PANVEL
----------------------------------------------------------------------------------------------

                        ----------------STUDENT RECORDS--------------

        1.ADDING A NEW RECORD
        2.DISPLAYING THE RECORD
        3.INSERTING A RECORD AFTER AN ANOTHER RECORD
        4.DELETING ANY RECORD
        5.SEARCH ANY STUDENT'S RECORD
        6.EDITING RECORDS
        7.EXIT

ENTER YOUR CHOICE: 1

ENTER THE FIRST NAME OF THE STUDENT: Ayesha

ENTER THE LAST NAME  OF THE STUDENT: Sayyad

ENTER STUDENT ROLL NO: 2

ENTER STUDENT POINTER: 8

ENTER THE DEPARTMENT: Civil

                INFO ADDED SUCCESSFULLY


---------------------------------------------------------------------------------------------
                                ANJUMAN-I-ISLAM'S KALSEKAR TECHNICAL CAMPUS
                                                NEW PANVEL
----------------------------------------------------------------------------------------------

                        ----------------STUDENT RECORDS--------------

        1.ADDING A NEW RECORD
        2.DISPLAYING THE RECORD
        3.INSERTING A RECORD AFTER AN ANOTHER RECORD
        4.DELETING ANY RECORD
        5.SEARCH ANY STUDENT'S RECORD
        6.EDITING RECORDS
        7.EXIT

ENTER YOUR CHOICE: 2
INFO OF STUDENTS:

FIRST NAME      LAST NAME       ROLL NO         POINTER         DEPARTMENT
Pranali                 Kokate               4                      8.070000        Computers
Rehamat             Sayyad               9                      7.800000        Extc
Alfina                  Sayyed               10                     8.700000        Mechanical
Ayesha                Sayyad               2                       8.000000        Civil
---------------------------------------------------------------------------------------------
                                ANJUMAN-I-ISLAM'S KALSEKAR TECHNICAL CAMPUS
                                                NEW PANVEL
----------------------------------------------------------------------------------------------

                        ----------------STUDENT RECORDS--------------

        1.ADDING A NEW RECORD
        2.DISPLAYING THE RECORD
        3.INSERTING A RECORD AFTER AN ANOTHER RECORD
        4.DELETING ANY RECORD
        5.SEARCH ANY STUDENT'S RECORD
        6.EDITING RECORDS
        7.EXIT

ENTER YOUR CHOICE: 4

ENTER THE STUDENT ROLL NO YOU WANT TO DELETE: 2
DELETED SUCCESSFULLY


---------------------------------------------------------------------------------------------
                                ANJUMAN-I-ISLAM'S KALSEKAR TECHNICAL CAMPUS
                                                NEW PANVEL
----------------------------------------------------------------------------------------------

                        ----------------STUDENT RECORDS--------------

        1.ADDING A NEW RECORD
        2.DISPLAYING THE RECORD
        3.INSERTING A RECORD AFTER AN ANOTHER RECORD
        4.DELETING ANY RECORD
        5.SEARCH ANY STUDENT'S RECORD
        6.EDITING RECORDS
        7.EXIT

ENTER YOUR CHOICE: 5

ENTER THE ROLL NO: 4

INFO FOUND:

FIRST NAME      LAST NAME       ROLL NO         POINTER         DEPARTMENT
Pranali                Kokate                4                      8.070000        Computers
---------------------------------------------------------------------------------------------
                                ANJUMAN-I-ISLAM'S KALSEKAR TECHNICAL CAMPUS
                                                NEW PANVEL
----------------------------------------------------------------------------------------------

                        ----------------STUDENT RECORDS--------------

        1.ADDING A NEW RECORD
        2.DISPLAYING THE RECORD
        3.INSERTING A RECORD AFTER AN ANOTHER RECORD
        4.DELETING ANY RECORD
        5.SEARCH ANY STUDENT'S RECORD
        6.EDITING RECORDS
        7.EXIT

ENTER YOUR CHOICE: 6


ENTER THE ROLL NO YOU WANT TO EDIT: 9


ENTER THE NEW INFO:
ENTER THE FIRST NAME OF THE STUDENT: Rehamat

ENTER THE LAST NAME  OF THE STUDENT: Sayyad

ENTER STUDENT ROLL NO: 9

ENTER STUDENT POINTER: 8

ENTER THE DEPARTMENT: Electrical


INFO EDITED SUCCESSFULLY
---------------------------------------------------------------------------------------------
                                ANJUMAN-I-ISLAM'S KALSEKAR TECHNICAL CAMPUS
                                                NEW PANVEL
----------------------------------------------------------------------------------------------

                        ----------------STUDENT RECORDS--------------

        1.ADDING A NEW RECORD
        2.DISPLAYING THE RECORD
        3.INSERTING A RECORD AFTER AN ANOTHER RECORD
        4.DELETING ANY RECORD
        5.SEARCH ANY STUDENT'S RECORD
        6.EDITING RECORDS
        7.EXIT

ENTER YOUR CHOICE: 2
INFO OF STUDENTS:

FIRST NAME      LAST NAME       ROLL NO         POINTER         DEPARTMENT
Pranali                Kokate                4                      8.070000        Computers                                                                                                   
Rehamat            Sayyad                9                      8.000000        Electrical
Alfina                  Sayyed                10                    8.700000        Mechanical
---------------------------------------------------------------------------------------------
                                ANJUMAN-I-ISLAM'S KALSEKAR TECHNICAL CAMPUS
                                                NEW PANVEL
----------------------------------------------------------------------------------------------

                        ----------------STUDENT RECORDS--------------

        1.ADDING A NEW RECORD
        2.DISPLAYING THE RECORD
        3.INSERTING A RECORD AFTER AN ANOTHER RECORD
        4.DELETING ANY RECORD
        5.SEARCH ANY STUDENT'S RECORD
        6.EDITING RECORDS
        7.EXIT

ENTER YOUR CHOICE: 7

*/
