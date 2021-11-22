#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <time.h>

//Process for member's personal information
int Personal_data(); // Used for the personal information of members

//Process for member's Involement within the ministry
int Ministry_Involvement(); // Used for the ministry involvement of members
int JM(); //'Jobs of Members' which is called by Ministry Involvement
int MM(); //'Ministry Involvement' which is called by Ministry Involvement

//Process for attendacne
int Attendance(); //Used for the accounting of the church
int Week(); //calculations for the week
int Month(); //calculations for the month

int main()
{
	/* Option = Used for the do case structure in order for the user to select what the program should do
	start = Used to determine whether o rnot the program should be terminated*/
	int option,start; 

	puts("\n\t ================================================================\n\t");
	puts("\n\t Rehoboth Gospel Assembly Membership Program \n\t");
	
	puts("\t Welcome to the Rehoboth Gospel Assembly Membership Program automated registration and documentation program.\n");
	Sleep(1575); //Delays the program by a certain number of seconds
	puts("\n\t ================================================================\n\t");
	
	printf("\t Press 'enter' to continue__");
	getch();
	system("cls");
	
	while (start==1)
	{
		
		printf("\n ============MAIN MENU============\n");
		printf("\n\n Select an option to do:\n [1] Member information\n [2] Ministry Involvement\n"
		" [3] Attendance\n [4] Exit\n \n Selected Option: ");
		scanf("%d", &option);
		system("cls");
		
		switch (option)
		{
			case 1:Personal_data();
			break;

			case 2:Ministry_Involvement(); 
			break;

			case 3:Attendance();
			break;

			case 4:exit(1);
			
			default:printf("\n ERROR 404: Invalid option selected\n");
		}
		printf("\n\n Would you like to return to the main menu?\n [1] for YES \n [2] for NO\t \n \n Answer: ");
		scanf("%d", &start);
		system("cls");
	}
printf("\n\n ============END OF THE PROGRAM============\n\n");
return 0;
}

struct member_info
{
	int idnum[];
}CM; //CM stands for Church Members.

int Personal_data()
{
	int  family_num[10], member_count_personal=0, Bcount=0;
	char fname[50][100], lname[50][100], address[100][20], dob[50], martial_status[15];
	// fname= first name, lname= Last name, dob = date of birth, 
	//family_num = the amount of family members

	FILE *cptr; //The "c" is short for church members
	
	puts("\n ================================================================\n\t");
	puts("\n Rehoboth Gospel Assembly Membership Program - Membership Documentation \n\t");	
	puts("\n ================================================================\n\t");

	
	printf("\n Number of members being documented: ");
	scanf("%d", &member_count_personal);
	
	cptr = fopen("Documentation & Registration.txt", "a+");
	
    if (cptr==NULL) // checking if the file can be found
    {
        printf("\n File couldnt be written to!\n");
        Sleep(1000);
        return 0;
    }
	// This section is for the user to input data gathered from the church members
	for(Bcount=1; Bcount<=member_count_personal; Bcount++)
	{
		fprintf(cptr,"\n ============REPORT============\n");
		
		printf("\n \n 7-Digit ID#: ");
		scanf("%7d", &CM.idnum[Bcount]);
		
		fprintf(cptr,"\n 7-Digit ID #:  %7d\n", CM.idnum[Bcount]);
		
		fflush(stdin);	//clears the output buffer
		
		printf("\n First Name & Last Name: ");
		scanf("%[^\n]s ", fname, lname);
		fprintf(cptr,"\n First & Last name: %s \n", fname, lname);

		printf("\n Date of birth(format xx.xx.xx): ");
		scanf("%s",&dob);
		
		fprintf(cptr,"\n Date of birth:  %s\n", dob);
	
		fflush(stdin);	//clears the output buffer
		
		printf("\n Address: ");
		scanf("%[^\n]s",address);
		
		fprintf(cptr,"\n Address:  %s\n", address);

		printf("\n Martial Status?: ");
		scanf("%s", martial_status);
		
		fprintf(cptr,"\n Marital Status:  %s\n", martial_status);
		
		printf("\n # of Family members attending: ");
		scanf("%d", &family_num[Bcount]);
		
		fprintf(cptr,"\n # of Family members attending:  %d\n", family_num[Bcount]);
		
		printf("\n ****************************************** \n");
		
	}

	fclose(cptr);							
	if((fclose(cptr) != 0)) 
	{
		puts("\n Printed to the file sucessfully!\n");	
	}
		else 
			{
				printf("\n Error: File Not Closed\n");	
			}
	return 0;
	
};

struct ministry_info
{
	int skill,job_num[50], job_count; 
	char job_name[][5], aom[][5]; //AOM = area of ministry, job_num = number of jobs, job_name = name of job.
}MI;

int Ministry_Involvement() 
{
	//MI = Ministry involvement, ocount = A simple counter
	int MIans, Wcount=0,member_count_MI=0, ocount=0, MIoption;

	FILE *miiptr;
	FILE *mioptr;

	puts("\n ================================================================\n\t");
	puts("\n Rehoboth Gospel Assembly Membership Program - Ministry Involement \n\t");	
	puts("\n ================================================================\n\t");	
	
	puts("\n 1. Occupation\n \n 2. Area Of Ministry\n ");

	printf("\n Members being documented: ");
	scanf("%d",&member_count_MI);

	printf("\n Choose which section you would like to access\n \n Selected Option: ");
	scanf("%d",&MIoption);

	system("cls");

	for(ocount=1; ocount<=member_count_MI; ocount++)
	{
		if (MIoption == 1)
		{
			puts("\n\t======MEMBER JOB INFORMATION========\n");
			JM();
		}
			if (MIoption == 2)
			{
				puts("\n\t======MEMBER MINISTRY INVOLVEMENT========\n");
				MM();	
    		}
	system("cls");
	}	

    if (miiptr || mioptr == NULL) // checks if the file can't be found
    {
        printf(" File(s) couldnt be written to\n OR\n Go create the file(s)!\n");
        Sleep(1000);
        return 0;
    }			

	printf("\n Select an option for which Involvement should be printed: \n (JOB = 4, INVOLVEMENT = 5): ");
	scanf("%d", &MIans);
				
		if (MIans == 4)
		{	
			mioptr = fopen("Ministry Involvement - Occupation.txt", "a+");

			fprintf(mioptr,"\n ============REPORT============\n");
			 
			fprintf(mioptr,"\n ***MEMBER JOB INFORMATION***\n");
			
			fprintf(mioptr,"\n Individual's ID#: %d\n",CM.idnum[Wcount]); 
			
			fprintf(mioptr,"\n Individual's jobs/occupation: %s\n",MI.job_name[Wcount]);
			
			fprintf(mioptr,"\n # of jobs: %d\n",MI.job_num[Wcount]); 
			
			fflush(stdout);	
			
			fclose(mioptr);		
		}
			else if(MIans == 5)
			
			{
				miiptr = fopen("Ministry Involvement - Involvment.txt", "a+");
				
				fprintf(miiptr,"\n ============REPORT============\n\n"); 
				
				fprintf(miiptr,"\n ***MINISTRY INFORMATION***\n");
				
				fprintf(miiptr,"\n Individual's ID#: %d\n",CM.idnum[Wcount]); 
				
				fprintf(miiptr,"\n Area of ministry: %s\n",MI.aom[Wcount]);
				
				fclose(miiptr);
			}
				else
					{
						printf("\n ERROR 404: Invalid Option!");
						return 0;
					}
					
								
	if((fclose(miiptr) || (mioptr) != 0)) 
	{
		puts("\n Printed to the file sucessfully! \n");	
	}
		else 
			{
				printf("\n Error: File Not Closed\n");	
			}
	return 0;
}

int JM()
{
	int JMo=0; 
	
	printf("\n 7-Digit ID#: ");
	scanf("%7d", &CM.idnum[JMo]);
			
	printf("\n Does the user have a job? (Yes = 1, No = 2): ");
	scanf("%d", &MI.skill);

	if (MI.skill==1)
	{
		printf("\n Total number of jobs: ");
		scanf("%d", &MI.job_num[JMo]);
		
		fflush(stdin);
					
		printf("\n Enter the [%d] job(s) name: ",MI.job_num[JMo]);
			
		scanf("%[^\n]s ", MI.job_name[JMo]);  	
	}
		else if (MI.skill==2)
		{
			printf("\n ID#: %d does not have a job",CM.idnum[JMo]);
	 	}
	 	
	 		else
	 		{
				printf("Error 404: Invalid Option Selcted!");
			}
}

int MM()
{
	int JMi = 0;
	
	printf("\n 7-Digit ID#: ");
	scanf("%7d", &CM.idnum[JMi]);
	
	fflush(stdin);
	
	printf("\n Which Area of Ministry this the person aparat of?\n [1] Music Ministry\n [2] Dance Ministry\n [3] Mini-Sermon\n "
	"[4] Instrumental\n [5] Multimedia Department\n \n Typed Option: ");
	scanf("%[^\n]s", &MI.aom[JMi]);			
}


int Attendance() 
{
	int AToption,week_count,week_attendance[5],week_attendance_total=0; 

	FILE *attendptr;
	
	puts("\n ===========================================================\t");
	puts("\n                       ATTENDANCE                         \n");	

	printf ("\n Documentation for: \n \n [1] Week \n [2] Month\n \n Selected option: ");
	scanf("%d", &AToption); 
		
		if (AToption==1)
			{
				Week();
			}
				else if (AToption==2)
				{
					Month();
				}
					else
					{
						puts ("\n ERROR 404: Invalid Option Selected! \n");
						return 0;
					}
					
							
	if((fclose(attendptr) != 0)) 
	{
		puts("\n Printed to the file sucessfully! \n");	
	}
		else 
			{
				printf("\n Error: File Not Closed\n");	
			}
	return 0;	
}


int Week()
{
	int wcount,week_count,week_attendance[5],week_attendance_total=0;
	char event_type[50];

	//Used to get the  current time from the system	
	SYSTEMTIME str_t;
	GetSystemTime(&str_t);
	
	FILE *attendptr;
	
	fflush(stdin);
	
	printf("\n Which meeting/event are you documenting for ?: ");	
	scanf("%[^\n]s", event_type);	

	//Accepts the total number of weeks the user wants to add
	printf("\n How many weeks you want to add?: ");
	scanf("%d", &week_count);
	
		for (wcount = 1; wcount <= week_count; wcount++)
  		{
  			printf("\n Week[%d]'s Attendance: ", wcount);
  			
    		scanf("%d", &week_attendance[wcount]);
   	 		
   	 		//Calculations for the total number person attending church weekly
			week_attendance_total += week_attendance[wcount];
		}
		
	system("cls");
	
	printf("\n Month's Total = %d\n", week_attendance_total);

	printf("\n Month's event = %s\n", event_type);	
	
	attendptr = fopen("Attendance.txt", "a+");
		
	fprintf(attendptr,"\n ========MONTH'S TOTAL FOR %s======\n", event_type);	
			
	fprintf(attendptr,"\n Month's Total = %d\n", week_attendance_total);
		
	fprintf(attendptr,"\n Year: %d \n Month: %d \n Date: %d\n",str_t.wYear,str_t.wMonth,str_t.wDay);
	
	fclose(attendptr);
}

int Month()
{
	
	int mcount,month_count,months_attendance[13],month_total=0;

	//Used to get the  current time from the system
	SYSTEMTIME str_t;
	GetSystemTime(&str_t);

	FILE *attendptr;
	
	//Accepts the total number of months the user wants to add				
	printf("\n How many months do you want to add?: ");
	scanf("%d", &month_count);

		for (mcount = 1; mcount <= month_count; mcount++)
  		{
			printf("\n Month[%d]'s Attendance: ", mcount);
  			
    		scanf("%d", &months_attendance[mcount]);
    		
    	//Calculations for the total number person attending church monthly
			month_total = month_total + months_attendance[mcount];
		}
		system("cls");
		
		attendptr = fopen("Attendance.txt", "a+");

		printf("\n Month Total = %d\n", month_total);
		
		fprintf(attendptr,"\n ========MONTH'S TOTAL======\n");
				
		fprintf(attendptr,"\n Month's Total = %d\n", month_total);
		
		fprintf(attendptr,"\n Year: %d \n Month: %d \n Date: %d\n",str_t.wYear,str_t.wMonth,str_t.wDay);
		
		fclose(attendptr);
}
