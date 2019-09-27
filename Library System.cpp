/******** 
Program: That keeps a record of all the books that it has in stock in a library
********/
#define _CRT_SECURE_NO_WARNINGS
#define bool int
#define false 0
#define true (!false)

//Libraries
#include <stdio.h>
#include <stdlib.h> 

//Preprocessor Variable
#define SIZE 9              //size of the books
#define SIZE2 30            //size of the characters

//Stucture template for data part of a LinearNode
struct data 
{
  //variables
  int bookID;           //unique ID for each book
  char bookName[SIZE2]; // book name
  char author;          //author of each book
  int yearOfPublication;//year of publication
  bool status = false;  //indicates the status of each book(ie; loaned out or not)
  char customerName;    //name of each customer
  int numOfLoan = 0;    //number of times the book has been loaned  out
};

//Stucture template for one node
struct LinearNode
 {
	struct data *element;
	struct LinearNode *next;
};


// Function prototypes
void menu();            //menu option that displays all the options
void addABook();        //adding a book to the library
void takeOutABook();    //allows to take out a book from the library
void returnABook();     //returns a book to the library
void deleteABook();     // delete a book from stock
void deleteANode(int);   //deletes a node(linked list part)
void viewAllBooks();        //view all books from the library
void viewASpecificBook();   //view a specific book from the library
void mostPopularBooks();    //allows to view the most popular books from the library
void leastPopularBooks();
void createAnAccount();       //my extra added function to the system, which allows customers to create an account 
bool isEmpty();               //shows us if there are no books in the library 

/* This text file saves a series of name and ages to a text file */
void inputDataAndSave(FILE *);
void getFromFileAndDisplay(FILE *);

// Global Variables
struct LinearNode *front = NULL;
struct LinearNode *last = NULL;

//Main Method
int main()
{
    /**********FILE HANDLING******************/
		FILE *fp;
	
   
    
    fp = fopen("z:books.dat", "r");  //open a text file for reading - this will give an error if no file
	if (fp == NULL)                  //if the file doesn't already exist, ask user to input
           inputDataAndSave(fp);     //values and immediately save to the file
	else  
		getFromFileAndDisplay(fp);  //othewise copy the values from the file and display.
		
    getchar();
    getchar();
	
	menu();  //call the menu method to execute
}

/**********INPUTS DATA AND SAVES ONTO A FILE******************/
void inputDataAndSave(FILE *fp) {
     char bookName[SIZE2];
     int yearOfPublication;
	
	 printf("Data file doesn't exist, so you must create the data yourself\n");
     fp = fopen("z:books.dat", "w"); //create the file and open for writing.
     
     for (int i=0; i< MAX; i++)
	 {
           printf("Enter book name : ");  //asks user for the book name 
           scanf("%s", bookName);     
           printf("Enter year of publication: ");  //asks user for the book's year of publication 
           scanf("%d", &yearOfPublication);
           fprintf(fp, "%s %d\n", bookName, yearOfPublication);  //prints both the book name and year of publication back to the screen
     }
     fclose(fp);  //closes the file
}

/**********READS INFORMATION FROM FILE AND DISPLAYS THE INFORMATION******************/
void  getFromFileAndDisplay(FILE *fp)
{
      char bookName[SIZE2];
     int yearOfPublication;
     
     	 printf("Data file does exist, so no need to create the data \n");
      while (fscanf(fp, "%s%d", bookName, &yearOfPublication)!=EOF)  
      {
            printf("Name of book = %s year of publication = %d\n", bookName, yearOfPublication);
      }
          
      fclose(fp);   //after reading from file the stream is closed 
      
}


/**********MENU OPTION******************/
void menu()
{
	int option;
	do{       //do-while loop until user hits 9 to exit the system
	
	printf("1.Add a new book to the library \n");
        printf("2.Allow customer to take out a book \n");
        printf("3.Allow customer to return a book \n");
        printf("4.Delete an old book from stock \n");
        printf("5.View all books \n");
        printf("6.View a specific book \n");
        printf("7.View details of most popular and least popular books \n");
        printf("8.Extra fuction \n");
        printf("9.Exit the System \n");
        
        printf("choose option");
        scanf("The option you have choosen is %d", option);
        
         if (option == 1)
        { 
            addABook();  //add a book method is called when option 1 is picked
           
        }
        else if (option == 2)
        {
            takeOutABook();  //take out a book method is called when option 2 is picked
             
        }
        else if (option == 3)
        {
            returnABook();   //return a book method is called when option 3 is picked
           
        }
        else if (option == 4)
        {
            deleteABook();  //delete a book method is called when option 4 is picked 
           
        }
        else if (option == 5)
        {
            viewAllBooks();   //view all books method is called when option 5 is picked
			
        }
        else if (option == 6)
        {
            viewASpecificBook();  //view a specific book method is called when option 6 is picked
           
           
        }
        else if (option == 7)
        {
            mostPopularBooks();  //view most book method is called when option 7 is picked
			leastPopularBooks();  //view least book method is called when option 7 is picked
           
        }
        else if (option == 8)
        {
			createAnAccount();       //create an account in the library method is called when option 8 is picked
            
            
        }
		} while( option != 9  );  //user exists the system when option 9 is picked
         

   }

        
/**********1.ADD A BOOK TO THE LIBRARY******************/
// Each new book is added to the list
void addABook() {	

	printf("<<<<ADD A BOOK TO THE LIBRARY>>>> \n");

	int aNumber;
	struct LinearNode *aNode;
	struct data *anElement;
	

	// add SIZE books to the list
      for (int i=0; i<SIZE; i++) {
	    //Create space for data part of book
        anElement = (struct data *)malloc(sizeof(struct data));
		
		if (anElement == NULL)
    		printf("Error - no space for the new element\n");  //if the space for the element is empty a message is displayed indicating no space for new element
		else                                   //user is asked to enter details of tthe book if space is currently available
		{
			
                    
		    //Input the ID for the book 
                    printf("Enter the book identifier: \n");
		            scanf("%d",  &anElement->bookID);  //prints the book ID, anElement->bookID accesses the bookID
		            
                    
                    //Input the name of the book
                    printf("Enter the book name: \n");
                    scanf("%s", &anElement->bookName);  //prints the book name, anElement->bookID accesses the bookName
                    
                    //Input the author of the book 
                    printf("Enter the author of the book: \n");
                    scanf("%s", &anElement->author);    //prints the book author, anElement->bookID accesses the book author
             
                    //Input the year of publication
                    printf("Enter the year of publication of the book: \n");
                    scanf("%d", &anElement->yearOfPublication);  //prints the book's year of publication, anElement->bookID accesses the book year of publication
                    if (aNumber == current->element->bookID && current-> element->yearOfPublication < 2008)   //checks if year of publication is not older than the year 2008
                    printf("Year of publication cannot be older than the year 2008");
                    

		    // create space for new book that will contain data
		    aNode = (struct LinearNode *)malloc(sizeof(struct LinearNode));

	      if (aNode == NULL)
		     	printf("Error - no space for the new book\n");  //if the space for the element is empty a message is displayed indicating no space for new element
		  else {             //else the new element is added to the end of the list
		        // add data part to the node
		       	aNode->element = anElement;
			    aNode->next = NULL;
			    
			     //add node to end of the list
			    if (isEmpty())  
			    {
				   front = aNode;
				   last = aNode;
                }
			    else {
				     last->next = aNode;
				     last = aNode;   //last node becomes new node
		 } //end else
           }//end else
        }//end else 
      }//end for
} //end addABook
    

/**********2.TAKE OUT A BOOK FROM LIBRARY******************/
   void takeOutABook()
{
	printf("<<<<TAKE A BOOK OUT>>>> \n");

	int idBook; 
    printf("Enter the book ID for the book want to take out from the library - \n"); //asks user to input the book ID
    scanf("%d", &idBook);    //prints out by accessing the book ID
    
	struct LinearNode *current;

        printf("\n");
	if (isEmpty())           //isEmpty() checks to see if the list of books are empty
		printf("Error - Sorry there are no books in the list\n");
	 else {
			current = front;
			while (current != NULL) {
				if(current->element->bookID == idBook && current->element->status ==1)     //checks using the bookID and status to see if the book is currently available(status = 0) or unavailable(ststus = 1)
				{	
				printf("Sorry the book isn't currently in stock, please try again at a later time");  //prints message when status = 1, ie; book is out of stock
				
				break;  //if the book has already been taken out, breaks off from the statement
				
			} 
				else if  (current->element->bookID == idBook && current->element->status ==0)   //when status equals to 0(available)
				{
					printf("The book is available in the library stock");      //message is printed saying that the  book is available in stock
					printf("To return back the book, enter the customer name: ") //message pops up asking for the customer's name who wish to the book out
				    scanf("%s", &current->element->customerName);                 //accesses and prints out the customer name
				    current->element->numOfLoan++;    //increase the nummber of loan variable by one as now book is being borrowed
				    current->element->status = 1;     //assigns status to 1 (unavailable)
				    break;  //breaks off when book has been borrowed 
			}
			current=current->next;
			} //end while
  
    }//end else
}

/**********3.RETURN BACK A BOOK TO THE LIBRARY******************/
 void returnABook(int aNumber)
{
	printf("<<<<RETURN A BOOK BACK TO THE LIBRARY>>>> \n");

	int idBook;  //local variable for the book ID 
    printf("Enter the book ID for the book you wish to return to the library - \n");   //asks user to input the book ID
    scanf("%d", &idBook);    //prints out by accessing the book ID
    
	struct LinearNode *current;

        printf("\n");
	if (isEmpty())
		printf("Error - Sorry there are no books in the list\n");   //isEmpty() checks to see if the list of books are empty
	 else {
			current = front;
			while (current != NULL) {
				if(current->element->bookID == idBook && current->element->status ==1)   //checks using the bookID and status to see if the book is currently available(status = 0) or unavailable(ststus = 1)
				{	
				printf("The book was being borrowed");                  //message is printed saying that the  book was being borrowed
				printf("To return back the book, enter the customer name: ")  //message pops up asking for the customer's name who wish to the return the book
				scanf("%s", &current->element->customerName);      //accesses and prints out the customer name
				current->element->numOfLoan--;        //decrease the nummber of loan variable by one as now book is being bought back
				current->element->status = 0;         //assigns status to 0 (available)
				break;   //if the book has been returned back, breaks off from the statement
				
			}
				else if  (current->element->bookID == idBook && current->element->status ==0) //when status equals to 0(available)
				{
					printf("The had been already returned to the library ");   //messsage prints out saying that the book has been returned already
				    break;  //if the book has been already in stock, breaks off from the statement
			}
			current=current->next;
			} //end while
    }//end else
  
}


/**********4.DELETE AN OLD BOOK FROM THE LIBRARY******************/
 void deleteABook()
{
	printf("<<<<DELETE A BOOK>>>> \n");

   int idBook;   //local varable for the book ID
   printf("Enter the book ID for the book you want to remove from the library stock- \n");
   scanf("%d", &idBook);       //accesses and prints out the idBook
   deleteANode(idBook);       //calls the deleteANode method which sets out on how to remove an element from the list
}

 void deleteANode(int aNumber)
{
    struct LinearNode *current, *previous;
	bool notFound = true;

     printf("\n");
	if (isEmpty())                 //isEmpty() checks to see if the list of books are empty
		printf("Error - there are no books in the list\n");
	else  {
			current = previous = front;

			while (notFound && current != NULL) {

                                //checks to see if the book ID and if the book's year of publication is older than 2010
				if (aNumber == current->element->bookID && current-> element->yearOfPublication >= 2010)
					notFound = false;       
				else {
						previous = current;
						current = current->next;
				}//end else
			} //end while

			if (notFound)
				printf("Error - there is not such book with that value %d\n", aNumber);   //if the book picked to delete is not found, appropriate message is shown
			else  {
				if (current == front) { //delete front node
					front = front->next;
					free(current);
				} //end else
				else if (current == last) {//delete last node
                     free(current);
                     previous->next = NULL;    //sets the next variable to null
                     last = previous;
                 }
				else {          //delete node in middle of list
						previous ->next= current->next;
						free(current);
				} //end else
				printf("Node with value %d has been deleted\n", aNumber);
			}//end else
		}//end else

}

/**********5.VIEW ALL BOOKS FROM THE LIBRARY******************/
 void viewAllBooks()
{
	printf("<<<<VIEW ALL BOOKS DETAILS>>>> \n");

	struct LinearNode *current;

        printf("\n");
	if (isEmpty())         //isEmpty() checks to see if the list of books are empty
		printf("Error - there are no books in the list\n");
	 else {
			current = front;
			while (current != NULL) {        //while the current element is not equal to null
			   //the book ID, name, author, year of publication is printed out
				printf("Book ID is %d\n", current->element->bookID);
				printf("Book name is %s\n", current->element->bookName);
				printf("Book author is %s\n", current->element->author);
				printf("Book year is %d\n", current->element->yearOfPublication);
				
				current=current->next;
			} //end while
    }//end else
} //end viewAllBooks



/**********6.VIEW A SPECIFIC BOOK FROM THE LIBRARY******************/
 void viewASpecificBook()
{
	printf("<<<<VIEW A SPECIFIC BOOK DETAILS>>>> \n");

    int idBook; 
    printf("Enter the book ID for the book you want view specifically from the library stock- \n");    //asks user to input the book ID for which they want to view 
    scanf("%d", &idBook);                         //book ID is printed out
    
	struct LinearNode *current;

        printf("\n"); 
	if (isEmpty())               //isEmpty() checks to see if the list of books are empty
		printf("Error - there are no books in the list\n");
	 else {
			current = front;
			while (current != NULL) {
				if(current->element->bookID == idBook)        //checks to see if the idBook entered by the user exists in the list of books
				{	
				//if yes, then the book ID, name, author and year of publication of that specific book is printed out
				printf("Book ID is %d\n", current->element->bookID);
				printf("Book name is %s\n", current->element->bookName);
				printf("Book author is %s\n", current->element->author);
				printf("Book year is %d\n", current->element->yearOfPublication);
				
				break;   //breaks out the statement when the specific book has been viewed as per request from the user
			}
			current=current->next;
			} //end while
    }//end else

}


/**********7.VIEW THE MOST POPULAR BOOKS FROM THE LIBRARY******************/
 void mostPopularBook()
 {
	 printf("<<<<VIEW THE MOST/LEAST POPULAR BOOK IN THE LIBARY>>>> \n");

	 char bookName[SIZE2];   //list of books 
	 char element = "";      //element/book being choosen
	 int count;              //the number of times an element has been choosen

	 for (int i = 0; i < SIZE; i++)
	 {
		 char tempElement = bookName[SIZE];
		 int numOfLoan;
		 for (int j = 0; j < SIZE; j++)
		 {
			 if (current->element->bookName[j]numOfLoan)
				 count++;               //increases count variable by 1
			 if (current->element->numOfLoan > count)  //checks to see if the number of times the book has been loaned out is greater than count
			 {
				 element = tempElement;
				 count = numOfLoan;   //lets the number of times the book has been loaned out to count
			 }
		 }

		 printf("Book %s is the most popular book in the library", &element);
		 printf("It has been loaned out ", count, "times");  //prints out the most popular book and the number of times it has been taken out
		 
	 }
 }


 /**********7.2 VIEW THE LEAST POPULAR BOOKS FROM THE LIBRARY******************/
 void leastPopularBooks()
 {

	 char bookName[SIZE2];   //list of books 
	 char element = "";      //element/book being choosen
	 int count;              //the number of times an element has been choosen

	 for (int i = 0; i < SIZE; i++)
	 {
		 char tempElement = bookName[SIZE];
		 int numOfLoan;
		 for (int j = 0; j < SIZE; j++)
		 {
			 if (current->element->bookName[j]numOfLoan)
				 count--;      //decreases count variable by 1
			 if (current->element->numOfLoan < count)  //checks to see if the number of times the book has been loaned out is less than count
			 {
				 element = tempElement;
				 count = numOfLoan;   //lets the number of times the book has been loaned out to count
			 }
		 }

		 printf("Book %s is the least popular book in the library", &element);
		 printf("It has been loaned out ", count, "times");  //prints out the least popular book and the number of times it has been taken out
	 }
 }

 /**********8.CREATE A LIBRARY ACCOUNT- EXTRA FUNCTIONALITY******************/
 void createAnAccount()
 { 
	 struct LinearNode *aNode;
	 struct data *anElement;

	 char firstName, lastName;   //name of the customer who wish to create an account
	 int libraryCardNumber;      //the library card number which they already hold
	 int pinNo;                  //personal idenification number of the customer

	 printf("<<<<WELCOME, LOGIN TO YOUR LIBRARY ACCOUNT>>>> \n");

	 // add SIZE books to the list
	 for (int i = 0; i<SIZE; i++) {
		 //Create space for new customer account 
		 anElement = (struct data *)malloc(sizeof(struct data));


	 //asks user for their personal details before creating the account
	 printf("Enter your first name in the space provided below: \n");
	 scanf("%s", &anElement->firstName);

	 printf("Enter your last name in the space provided below: \n");
	 scanf("%s", &anElement->lastName);

	 printf("Enter your library card number in the space provided below: \n");
	 scanf("%s", &anElement->libraryCardNumber);

	 printf("Enter your PIN number in the space provided below: \n");
	 scanf("%s", &anElement->pinNo);

	 // create space for new account that will contain data
	 aNode = (struct LinearNode *)malloc(sizeof(struct LinearNode));

	 if (aNode == NULL)
		 printf("Error - no space for the new account\n");  //if the space for the element is empty a message is displayed indicating no space for new account
	 else {             //else the new element is added to the end of the list
						// add data part to the node
		 aNode->element = anElement;
		 aNode->next = NULL;

		 //add node to end of the list
		 if (isEmpty())
		 {
			 front = aNode;
			 last = aNode;
		 }
		 else {
			 last->next = aNode;
			 last = aNode;   //last node becomes new node

			 printf("Action successful, account has been created \n");   //appropriate message is displayed when action has been successful
		 } //end else
	 }//end else
	 }//end else 
 }//end for

 }


 /**********IS EMPTY CHECKS IF THE LIST IS EMPTY OR NOT******************/
 bool isEmpty()
 {
	 if (front == NULL)   //if the front element is NULL the sets to true
		 return true;
	 else
		 return false;    //else sets to false/ not empty
 }

