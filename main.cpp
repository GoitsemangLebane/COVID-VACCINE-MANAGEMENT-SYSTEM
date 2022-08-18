
#include<iostream> // contains functions for input/output operations (cin and cout)
#include<stdio.h> // used to print the character, string, float, integer, octal and hexadecimal values onto the output screen
#include<string.h>//Use for strcmp(),strcpy(),strlen(),etc
#include<cstdlib> // header file declares a set of general-purpose functions
#include<windows.h>
#include<conio.h>// to include some functions like clrscr(), getch()
#include<ctype.h> //take the int equivalent of one character as parameter and return an int that can either be another character or a value representing a boolean value
#include<stdlib.h>//a utility functions such as string conversion routines, memory allocation routines,random number generator,etc.
#include<vector> //to instruct the compiler to code, but to also compile vectors
#include<algorithm> // for functions of  searching, sorting, counting, manipulating
#include<fstream> //used for the reading and writing on the file system


using namespace std;   //to differentiate similar functions, classes, variables etc. with the same name available in different libraries

/*
* Function Definitions
*/
void title(void);        ;		//function for displaying the title in every class
void LoginScreen(void);        //function for authentication of user before getting access to the whole system
void sortNames(vector<string>& Patient);  //function to sort names of records according to their names in ascending order
bool  CurrentNameIsShorter(string A, string B); // function to search for what is entered


/////////////////////////////* declaring functions for all the details of the patients*///////////////////////////////////////////////////
struct Patient
{
    char names[20];
    char Id_Pass[30];
	char Reg_no[15];
	char Ess_Cat[30];
	char Pre_Stat[20];
	char Las_Test[20];
	char Workplace[20];
	char Vac[20];
	char Cen[20];
    char Address [20];

};

////////////////////////////* function with DISPLAY for displaying on the welcome screen *///////////////////////////////////////
void welcomeScreen(void)
{

	cout<<("\n\n\n\n\n\n\n\t\t\t\t*************************************************************************");
	cout<<("\n\t\t\t\t#\t\t                    COVID 19 REGISTRATION\t\t#");
	cout<<("\n\t\t\t\t#                                Department Of Health & Safety          #");
	cout<<("\n\t\t\t\t*************************************************************************");
	cout<<("\n\n\n\n\n\t\t\t\t\t\t\tPress any key to continue......\n");
	getch();
	system("cls");

}

/////////////////*function with algorithm for authenticating user to add login credentials into system to allow access*////////////////////
void LoginScreen(void)
{
int e=0	;
char Username[15];
char Password[15];
char original_Username[25]="ADMIN";
char original_Password[15]="2021";

do
{
    cout<<"\n\n\n\n\n\n\n\n\n\n";
	cout<<"\n\n\n\t\t\t\t\t\t\t\t Enter your Username and Password :)";
	cout<<"\n\n\n\t\t\t\t\t\t\t\t USERNAME:";
	cin>>(Username);

	cout<<("\n\n\n\t\t\t\t\t\t\t\t PASSWORD:");
	cin>>(Password);


	 /*compare the entered  username and password credentials with the already set/original username and password
	 *.....if the (if condition) is satisfied/passwords and usernames match, user is authorized into the system
	 *else the system prompts an error message and allows the user to attempt again
	 */
	{
	if(strcmp(Username,original_Username)==0 && strcmp(Password,original_Password)==0){
		cout<<"\n\n\n\t\t\t\t\t\t\t\t...YOU HAVE SUCCESSFULLY LOGGED IN...";


		getch();
		Patient p();
		break;
	}
	else
	{
		cout<<"\n\n\n\t\t\t\t\t\t\t\t Password is incorrect:( Try Again :)";
		e++;

		getch();
	}
	system("cls");
	title();
}}
//user only granted 3 attempts, if user enter errors more than 3 times, system exits
while(e<=2);{
	if(e>2)
	{
	cout<<("\n\n\n\t\t\t\t\t\t\t\t ERROR! You cannot login. :( :(   TRY AGAIN LATER :*");
    exit(0);
	getch();
	}

system("cls");
}
}

//////* function with TITLE DISPLAY for displaying ACROSS all screen *//////////
void title(void)
{
	cout<<("\n\n\t\t**********************************************************************************************************************");
	cout<<("\n\t\t\t\t                                    Department Of Health & Safety        ");
	cout<<("\n\t\t**********************************************************************************************************************");
}


/*
main function where the for program will starts and ends.
*/
int main()
{
    void welcomeScreen(void); // compiler runs this function first too display the WELCOME SCREEN FIRST
{
	cout<<("\n\n\n\n\n\n\n\t\t\t\t************************************************************************************************");
	cout<<("\n\t\t\t\t|\t\t\t\                  COVID 19 REGISTRATION\t\t                       |");
	cout<<("\n\t\t\t\t| \t                               Department Of Health & Safety                           |");
	cout<<("\n\t\t\t\t************************************************************************************************");
	cout<<("\n\n\n\n\n\t\t\t\t\t\t\t\tPress any key to continue......\n");
	getch();
	system("cls");
    title();
    LoginScreen();
}

     /*
     *hold all the data types of patient
     *to store data of members for declared functions of Patient for initialization
     */
     struct Patient p;
     title();  //calls title function to show title display.
     FILE *fp;  //file pointer is just to store the composite information about a file subject to manipulation.
     char c;
     int ch;    //for storing choice of the switch cases

     //for displaying the MAINMENU of the system
     while(1)
     {
         cout<<"\n\n\n\n\n\n\n\n\n\n";
          cout<<"\n\n\n\t\t\t\t\t\t\t\t        MAIN MENU";
          cout<<"\n\n\n\t\t\t\t\t\t\t\t 1. CAPTURE PATIENT RECORDS";
          cout<<"\n\n\n\t\t\t\t\t\t\t\t 2. VIEW UNSORTED DATA";
          cout<<"\n\n\n\t\t\t\t\t\t\t\t 3. SORT RECORDS";
          cout<<"\n\n\n\t\t\t\t\t\t\t\t 4. SEARCH RECORDS";
          cout<<"\n\n\n\t\t\t\t\t\t\t\t 5. EXIT";
          cout<<"\n\n\n\t\t\t\t\t\t\t\t Enter Your Choice : ";
          cin>>ch; //store data of the chosen label

          switch(ch) //corresponding statements after the matching label are executed.
          {
               case 1:
                   system("cls");
	                 title();
                    fp=fopen("Patient.txt","ab");  //file to store data ** is created for first time and input data can be written to it
                    while (1)
                    {
                         cout<<"\n\n\n\n\n\n\n\n\n\n";
                         cout<<"\n Enter Patient names   :  ";
                         cin>>p.names;
                         fflush(stdin);   // to flush output buffers.
                         cout<<"\n Enter Identification no.   :  ";
                         cin>>p.Id_Pass;
                         fflush(stdin);
                         cout<<"\n Enter Registration no.   :  ";
                         cin>>p.Reg_no;
                         fflush(stdin);
                         cout<<"\n Essential Category   :  ";
                         cin>>p.Ess_Cat;
                         fflush(stdin);
                         cout<<"\n Enter Previous Status   :  ";
                         cin>>p.Pre_Stat;
                         fflush(stdin);
                         cout<<"\n Enter Last Test   :  ";
                         cin>>p.Las_Test;
                         fflush(stdin);
                         cout<<"\n Enter Workplace   :  ";
                         cin>>p.Workplace;
                         fflush(stdin);
                         cout<<"\n Enter Vaccine   :  ";
                         cin>>p.Vac;
                         fflush(stdin);
                         cout<<"\n Enter Center  :  ";
                         cin>>p.Cen;
                         fflush(stdin);
                         cout<<"\n Enter Address   :  ";
                         cin>>p.Address;
                         fflush(stdin);



                         fwrite(&p,sizeof(p),1,fp); //  writes the value of variable "p" to the file "fp".
                         fflush(stdin);
                         cout<<"\n\n ADD ANOTHER RECORD?(Y/N) : ";
                         cin>>c;
                         if(c=='n' || c=='N')
                              break;
                    }
                    fclose(fp); //close file fp
                    Patient(); //returns to class patient
                    system("cls");
                    break;

               case 2:
                     int row;
	                 system("cls");
	                 title();
                   system("cls");
                   title();
                    fp=fopen("Patient.txt","rb"); //file already created and exists, this opens the file
                    while (fread(&p,sizeof(p),1,fp)) // This reads float data from the file fp from Patient and stores it in p.
                    {
                         while(1)
                         {

                             cout<<"\n\n\n\n\n\n\n\n\n\n";
                              cout<<"\n\t\t\t\t\t\t\t\t Patient names     : "<<p.names;
                              cout<<"\n\t\t\t\t\t\t\t\t Identification no : "<<p.Id_Pass;
                              cout<<"\n\t\t\t\t\t\t\t\t Registration no.  : "<<p.Reg_no;
                              cout<<"\n\t\t\t\t\t\t\t\t Essential Category: "<<p.Ess_Cat;
                              cout<<"\n\t\t\t\t\t\t\t\t Previous Status   : "<<p.Pre_Stat;
                              cout<<"\n\t\t\t\t\t\t\t\t Last Test Date    : "<<p.Las_Test;
                              cout<<"\n\t\t\t\t\t\t\t\t Workplace         : "<<p.Workplace;
                              cout<<"\n\t\t\t\t\t\t\t\t Vaccine           : "<<p.Vac;
                              cout<<"\n\t\t\t\t\t\t\t\t Center            : "<<p.Cen;
                              cout<<"\n\t\t\t\t\t\t\t\t Address           : " <<p.Address << endl;
                              break;
                         }

                    }
                    fclose(fp);
                    getche();
                    system("cls");
                    Patient(), title();
                    break;

               case 3:
                   {
                       system("cls");
                       title();
                   Patient *s,s1;  // declare two variables one for n number of records and other for the records.
                   FILE *fp;
                   int i, j;
                   fp = fopen("Patient.txt","r");  //open the fp file in read mode.
                   fseek(fp,0,SEEK_END); // to determine how many records are there and then the cursor will be sent to the end.
                   int n = ftell(fp)/sizeof(Patient);  //calculate the number of records ** function will get number of records
                   s = (Patient *)calloc(n,sizeof(Patient)); //allocate the memory to s ** write all the data into s

                   rewind(fp);  //cursor will be sent to the first position to the beginning
                   for (i=0;i<n;i++) //read data into s
                    fread(&s[i],sizeof(Patient),1,fp); //read all the data into s of i ** s[i] variable

                   for (i=0;i<n;i++)  //loop for sorting the data
                   {
                       for (j=i+1;j<n;j++)
                       {
                           if(strcmp(s[i].names,s[j].names)>0) //compare strings of the records by name ** if s[i] is greater than s[j] then the names will be n ascending order
                           {
                               s1 =  s[i];
                               s[i] = s[j];
                               s[j] = s1;
                           }
                       }
                   }

                   for (i=0;i<n;i++)  // print the names in ascending order ** all data will be displayed ** the data is available now in s[i]
                   {
                       cout<<"\n\n\n\n\n\n\n\n\n\n";
                       cout<<"\n\t\t\t\t\t\t\t\t Patient names     : "<<s[i].names<<endl;
                       cout<<"\n\t\t\t\t\t\t\t\t Identification no : "<<s[i].Id_Pass<<endl;
                       cout<<"\n\t\t\t\t\t\t\t\t Registration no.  : "<<s[i].Reg_no<<endl;
                       cout<<"\n\t\t\t\t\t\t\t\t Essential Category: "<<s[i].Ess_Cat<<endl;
                       cout<<"\n\t\t\t\t\t\t\t\t Previous Status   : "<<s[i].Pre_Stat<<endl;
                       cout<<"\n\t\t\t\t\t\t\t\t Last Test Date    : "<<s[i].Las_Test<<endl;
                       cout<<"\n\t\t\t\t\t\t\t\t Workplace         : "<<s[i].Workplace<<endl;
                       cout<<"\n\t\t\t\t\t\t\t\t Vaccine           : "<<s[i].Vac<<endl;
                       cout<<"\n\t\t\t\t\t\t\t\t Center            : "<<s[i].Cen<<endl;
                       cout<<"\n\t\t\t\t\t\t\t\t Address           : "<<s[i].Address<<endl;
                   }
                   fclose(fp); //close the file
                    getch();
                    system("cls");
                    title();
                    break;}
                case 4:
                {

                   system("cls");
                   title();
                   char pname[20];  //declare variable to store the searched name
                   FILE *fp;
                   fp = fopen("Patient.txt","rb");

                   cout<<"\n\n\n\t\t\t\t\t\t\t\tENTER THE PATIENT NAME YOU WANT TO SEARCH: ";
                   cin>>pname;  // searched name will be stored here

                   while (fread(&p,sizeof(Patient),1,fp))  // // This reads float data from the file fp from Patient and stores it in Patient.
                   {

                      /*
                      *program will compare the two strings pname and p.names
                      *This function compares strings character by character
                      * if the data in the two strings is the same, it will return 0(the value on both strings)
                      */
                       if(strcmp(pname,p.names)==0){
                           while(1) // runs when the condition is true, and loop is infinite ** terminates itself when the condition is not satisfied
                           {
                       cout<<"\n\n\n\n\n\n\n\n\n\n";
                       cout<<"\n\t\t\t\t\t\t\t\t Patient names     : "<<p.names<<endl;
                       cout<<"\n\t\t\t\t\t\t\t\t Identification no : "<<p.Id_Pass<<endl;
                       cout<<"\n\t\t\t\t\t\t\t\t Registration no.  : "<<p.Reg_no<<endl;
                       cout<<"\n\t\t\t\t\t\t\t\t Essential Category: "<<p.Ess_Cat<<endl;
                       cout<<"\n\t\t\t\t\t\t\t\t Previous Status   : "<<p.Pre_Stat<<endl;
                       cout<<"\n\t\t\t\t\t\t\t\t Last Test Date    : "<<p.Las_Test<<endl;
                       cout<<"\n\t\t\t\t\t\t\t\t Workplace         : "<<p.Workplace<<endl;
                       cout<<"\n\t\t\t\t\t\t\t\t Vaccine           : "<<p.Vac<<endl;
                       cout<<"\n\t\t\t\t\t\t\t\t Center            : "<<p.Cen<<endl;
                       cout<<"\n\t\t\t\t\t\t\t\t Address           : "<<p.Address<<endl;
                               break;
                           }

                       }
                   }


                     fclose(fp);
	                getch();
                    system("cls");
                    title();
                    break;
                    }
               case 5:
                    {
                    system("cls");
                    title();
                    cout<<("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tSTAY SAFE! :)");
	                getch();
	                system("cls");

                    }
               default:
                    exit(0); // exit the program
          }
     }
     return 0;
}




