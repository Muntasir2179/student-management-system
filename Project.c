#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

void AddStudent();
void AddParent();
void ViewParent();
void AddStudentMarks();
void ViewStudentMarks();
void StudentList();
void PassedStudent();
void ProbationStudent();
void StudentInformation();
void SearchStudent();
void EditStudent();
void DeleteStudent();
void AdminMenu();
void MainMenu();
void StudentLoginInfo(char *);
int AdminLogin();
void StudentLogin();

struct student
{
    char name[50];
    char id[20];
    char pass[30];
    char dept[30];
    char credit[10];
    char cgpa[10];
    char probation[10];
    char phone[20];
    char address[50];
};

struct parent
{
    char id[20];
    char fathers_name[50];
    char fathers_phone[20];
    char mothers_name[50];
    char mothers_phone[20];
};

struct marks
{
    char name[50];
    char id[20];
    float quiz;
    float mid;
    float fin;
};

struct student std;
struct parent prnt;
struct marks mark;

char LoginID[50];
char LoginPassword[30];


void AddStudent()
{
    system("cls");
    printf("\n\t\t\t\t\t---------------------------------------\n");
    printf("\t\t\t\t\t----    Add Student Information    ----\n");
    printf("\t\t\t\t\t---------------------------------------\n");

    int n;
    char dp[30];

    FILE *fp;

    fp = fopen("StudentData.txt","ab+");
    if(fp == NULL)
    {
        printf("File not found.");
        exit(1);
    }
    else
    {
        printf("\n\tEnter Student Details: ");

        printf("\n\n\tEnter name            : ");
        gets(std.name);
        fflush(stdin);

        printf("\n\tEnter Student ID      : ");
        gets(std.id);
        fflush(stdin);

        printf("\n\tEnter Password        : ");
        gets(std.pass);
        fflush(stdin);

        printf("\n\tEnter Department      : ");
        gets(dp);
        strupr(dp);
        strcpy(std.dept , dp);
        fflush(stdin);

        printf("\n\tEnter Credit          : ");
        gets(std.credit);
        fflush(stdin);

        printf("\n\tEnter C.G.P.A.        : ");
        gets(std.cgpa);
        fflush(stdin);

        printf("\n\tEnter Probation       : ");
        gets(std.probation);
        fflush(stdin);

        printf("\n\tEnter Phone No.       : ");
        gets(std.phone);
        fflush(stdin);

        printf("\n\tEnter address         : ");
        gets(std.address);
        fflush(stdin);

        fwrite(&std,sizeof(std),1,fp);

        printf("\n\n\n\tThe record is successfully added");
    }

    fclose(fp);

AGAIN:

    printf("\n\n\tEnter 1 to Add again and 0 to go to AdminMenu: ");
    scanf("%d",&n);
    fflush(stdin);
    if(n==1)
    {
        AddStudent();
    }
    else if(n==0)
    {
        AdminMenu();
    }
    else
    {
        printf("\n\tInvalid Choice.");
        goto AGAIN;
    }
}

void AddParent()
{
    system("cls");
    printf("\n\t\t\t\t\t---------------------------------------\n");
    printf("\t\t\t\t\t-------     Check Student ID    -------\n");
    printf("\t\t\t\t\t---------------------------------------\n");

    FILE *fpt;
    char stdid[20];
    int flag = 0, n;

    printf("\n\tEnter student ID: ");
    gets(stdid);
    fflush(stdin);

    fpt = fopen("StudentData.txt","rb+");
    if(fpt == NULL)
    {
        printf("File not found.");
        exit(1);
    }

    while(fread(&std,sizeof(std),1,fpt) == 1)
    {
        if(strcmp(stdid, std.id)==0)
        {
            flag++;
        }
    }
    fclose(fpt);

    if(flag != 0)
    {
        printf("\n\n\tThe student ID is in the student information.");
        printf("\n\n\tPress any key to continue: ");
        getch();

        system("cls");
        printf("\n\t\t\t\t\t---------------------------------------\n");
        printf("\t\t\t\t\t----    Add Parent Information     ----\n");
        printf("\t\t\t\t\t---------------------------------------\n");

        FILE *fp;

        fp = fopen("ParentData.txt","ab+");

        if(fp == NULL)
        {
            printf("File not found.");
            exit(1);
        }

        else
        {
            fflush(stdin);
            printf("\n\tEnter student ID            : ");
            gets(prnt.id);

            fflush(stdin);
            printf("\n\tEnter father's name         : ");
            gets(prnt.fathers_name);

            fflush(stdin);
            printf("\n\tEnter father's phone number : ");
            gets(prnt.fathers_phone);

            fflush(stdin);
            printf("\n\tEnter mother's name         : ");
            gets(prnt.mothers_name);

            fflush(stdin);
            printf("\n\tEnter mother's phone number : ");
            gets(prnt.mothers_phone);

            fwrite(&prnt,sizeof(prnt),1,fp);

            printf("\n\n\tThe record is successfully added.");
        }

        fclose(fp);

AGAIN:

        printf("\n\n\tEnter 1 to Add again and 0 to go to AdminMenu: ");
        scanf("%d",&n);
        fflush(stdin);
        if(n==1)
        {
            AddParent();
        }
        else if(n==0)
        {
            AdminMenu();
        }
        else
        {
            printf("\n\tInvalid Choice.");
            goto AGAIN;
        }
    }

    else
    {
        printf("\n\tThis student ID is not in student information.");
CHECK:
        printf("\n\n\tEnter 1 to add again or 0 to go to AdminMenu: ");
        scanf("%d",&n);
        fflush(stdin);

        if(n==1)
        {
            AddParent();
        }
        else if(n==0)
        {
            AdminMenu();
        }
        else
        {
            printf("\n\tInvalid choice.");
            goto CHECK;
        }
    }
}

void ViewParent()
{
    system("cls");
    printf("\n\t\t\t\t\t----------------------------------------\n");
    printf("\t\t\t\t\t----   Search Parent Information    ----\n");
    printf("\t\t\t\t\t----------------------------------------\n");

    char searchID[20];
    int flag = 0, n;

    FILE *fp;
    fp = fopen("ParentData.txt","rb+");
    if(fp == NULL)
    {
        printf("File not found.");
        exit(1);
    }
    else
    {
        fflush(stdin);
        printf("\n\tEnter Student ID: ");
        gets(searchID);

        while(fread(&prnt,sizeof(prnt),1,fp) == 1)
        {
            if(strcmp(prnt.id, searchID) == 0)
            {
                printf("\n\tStudent ID         :%s",prnt.id);
                printf("\n\tFather's name      :%s",prnt.fathers_name);
                printf("\n\tFather's phone No. :%s",prnt.fathers_phone);
                printf("\n\tMother's name      :%s",prnt.mothers_name);
                printf("\n\tMother's Phone No. :%s",prnt.mothers_phone);
                printf("\n\n");

                flag++;
                break;
            }

        }
    }
    fclose(fp);

    if(flag==0)
    {
        printf("\n\tStudent ID is not correct.\n\tPlease Check Your Student ID.\n\n");
    }

AGAIN:

    printf("\n\n\tEnter 1 to Search again and 0 to go to AdminMenu: ");
    scanf("%d",&n);
    fflush(stdin);
    if(n==1)
    {
        ViewParent();
    }
    else if(n==0)
    {
        AdminMenu();
    }
    else
    {
        printf("\n\tInvalid Choice.");
        goto AGAIN;
    }
}

void AddStudentMarks()
{
    system("cls");
    printf("\n\t\t\t\t\t---------------------------------------\n");
    printf("\t\t\t\t\t-------     Check Student ID    -------\n");
    printf("\t\t\t\t\t---------------------------------------\n");

    FILE *fpt;
    char stdid[20];
    int flag = 0, n;

    printf("\n\tEnter student ID: ");
    gets(stdid);
    fflush(stdin);

    fpt = fopen("StudentData.txt","rb+");
    if(fpt == NULL)
    {
        printf("File not found.");
        exit(1);
    }

    while(fread(&std,sizeof(std),1,fpt) == 1)
    {
        if(strcmp(stdid, std.id)==0)
        {
            flag++;
        }
    }
    fclose(fpt);

    if(flag != 0)
    {
        printf("\n\n\tThe student ID is in the student information.");
        printf("\n\n\tPress any key to continue: ");
        getch();
        int n;
        system("cls");
        printf("\n\t\t\t\t\t---------------------------------------\n");
        printf("\t\t\t\t\t-------    Add Student Marks    -------\n");
        printf("\t\t\t\t\t---------------------------------------\n");

        FILE *fp;
        fp = fopen("StudentMarks.txt","ab+");
        if(fp==NULL)
        {
            printf("File not found.");
            exit(1);
        }
        else
        {
            fflush(stdin);
            printf("\n\tEnter student name         : ");
            gets(mark.name);

            fflush(stdin);
            printf("\n\tEnter student ID           : ");
            gets(mark.id);

            fflush(stdin);
            printf("\n\tEnter total QUIZ marks     : ");
            scanf("%f",&mark.quiz);

            fflush(stdin);
            printf("\n\tEnter total MID exams mark : ");
            scanf("%f",&mark.mid);

            fflush(stdin);
            printf("\n\tEnter FINAL exam mark      : ");
            scanf("%f",&mark.fin);

            fwrite(&mark,sizeof(mark),1,fp);

            printf("\n\n\tRecord added successfully.");
        }
        fclose(fp);

AGAIN:

        fflush(stdin);
        printf("\n\n\tEnter 1 to Add again and 0 to go to AdminMenu: ");
        scanf("%d",&n);
        fflush(stdin);

        if(n==1)
        {
            AddStudentMarks();
        }
        else if(n==0)
        {
            AdminMenu();
        }
        else
        {
            printf("\n\tInvalid Choice.");
            goto AGAIN;
        }
    }
    else
    {
        printf("\n\tThis student ID is not in student information.");
CHECK:
        printf("\n\n\tEnter 1 to add again or 0 to go to AdminMenu: ");
        scanf("%d",&n);
        fflush(stdin);

        if(n==1)
        {
            AddStudentMarks();
        }
        else if(n==0)
        {
            AdminMenu();
        }
        else
        {
            printf("\n\tInvalid choice.");
            goto CHECK;
        }
    }
}

void ViewStudentMarks()
{
    system("cls");
    printf("\n\t\t\t\t\t---------------------------------------\n");
    printf("\t\t\t\t\t------   Search Student Marks    ------\n");
    printf("\t\t\t\t\t---------------------------------------\n");
    int flag = 0, n;
    char searchID[20];

    FILE *fp;
    fp = fopen("StudentMarks.txt","rb+");
    if(fp==NULL)
    {
        printf("File not found.");
        exit(1);
    }

    else
    {
        printf("\n\tEnter Student ID: ");
        gets(searchID);

        while(fread(&mark,sizeof(mark),1,fp))
        {
            if(strcmp(mark.id, searchID) == 0)
            {
                flag++;
                printf("\n\tStudent name         : %s",mark.name);
                printf("\n\tStudent ID           : %s",mark.id);
                printf("\n\tTotal QUIZ exam marks: %.2f",mark.quiz);
                printf("\n\tTotal MID exam marks : %.2f",mark.mid);
                printf("\n\tFinal exam marks     : %.2f",mark.fin);
                printf("\n\n");
            }
        }
    }
    fclose(fp);

    if(flag==0)
    {
        printf("\n\tStudent ID is not correct.\n\tPlease check ID again.");
    }


AGAIN:

    printf("\n\n\tEnter 1 to search again and 0 to go to AdminMenu: ");
    scanf("%d",&n);
    fflush(stdin);

    if(n==1)
    {
        ViewStudentMarks();
    }
    else if(n==0)
    {
        AdminMenu();
    }
    else
    {
        printf("\n\tInvalid Choice.");
        goto AGAIN;
    }
}

void StudentList()
{
    printf("\n\t\t\t\t\t-------------------------------------\n");
    printf("\t\t\t\t\t----   All Student Information   ----\n");
    printf("\t\t\t\t\t-------------------------------------\n");

    int flag = 0,n;

    FILE *fp;
    fp = fopen("StudentData.txt","rb+");
    if(fp == NULL)
    {
        printf("File not found.");
        exit(1);
    }
    else
    {
        while(fread(&std,sizeof(std),1,fp) == 1)
        {
            flag++;
            printf("\n\tStudent Name   :%s",std.name);
            printf("\n\tStudent ID     :%s",std.id);
            printf("\n\tDepartment     :%s",std.dept);
            printf("\n\tCredit         :%s",std.credit);
            printf("\n\tC.G.P.A.       :%s",std.cgpa);
            printf("\n\tProbation      :%s",std.probation);
            printf("\n\tPhone No.      :%s",std.phone);
            printf("\n\tAddress        :%s",std.address);
            printf("\n\n");
        }
    }
    fclose(fp);

    if(flag==0)
    {
        printf("\n\n\n\n\t\t\t\t\tDoesn't Found Any Student Record.");
    }


AGAIN:

    printf("\n\n\tEnter 1 to Student Information Menu and 0 to go to AdminMenu: ");
    scanf("%d",&n);
    fflush(stdin);

    if(n==1)
    {
        StudentInformation();
    }
    else if(n==0)
    {
        AdminMenu();
    }
    else
    {
        printf("\n\tInvalid Choice.");
        goto AGAIN;
    }

}


void PassedStudent()
{
    printf("\n\t\t\t\t\t----------------------------------------\n");
    printf("\t\t\t\t\t----     Passed Student Details     ----\n");
    printf("\t\t\t\t\t----------------------------------------\n");


    int flag = 0, n, calculateProbation = 0;

    FILE *fp;
    fp = fopen("StudentData.txt","rb+");
    if(fp == NULL)
    {
        printf("File not found.");
        exit(1);
    }
    else
    {

        while(fread(&std,sizeof(std),1,fp) == 1)
        {
            calculateProbation = atoi(std.probation);
            if(calculateProbation == 0)
            {
                printf("\n\tStudent Name   :%s",std.name);
                printf("\n\tStudent ID     :%s",std.id);
                printf("\n\tDepartment     :%s",std.dept);
                printf("\n\tCredit         :%s",std.credit);
                printf("\n\tC.G.P.A.       :%s",std.cgpa);
                printf("\n\tProbation      :%s",std.probation);
                printf("\n\tPhone No.      :%s",std.phone);
                printf("\n\tAddress        :%s",std.address);
                printf("\n\n");

                flag++;
            }
        }
    }
    fclose(fp);

    if(flag==0)
    {
        printf("\n\tPassed Student Details not found.\n\n");
    }

AGAIN:

    printf("\n\n\tEnter 1 to Student Information Menu and 0 to go to AdminMenu: ");
    scanf("%d",&n);
    fflush(stdin);

    if(n==1)
    {
        StudentInformation();
    }
    else if(n==0)
    {
        AdminMenu();
    }
    else
    {
        printf("\n\tInvalid Choice.");
        goto AGAIN;
    }

}

void ProbationStudent()
{
    printf("\n\t\t\t\t\t----------------------------------------\n");
    printf("\t\t\t\t\t----   Probation Student Details    ----\n");
    printf("\t\t\t\t\t----------------------------------------\n");

    int flag = 0, n, calculateProbation = 0;

    FILE *fp;
    fp = fopen("StudentData.txt","rb+");
    if(fp == NULL)
    {
        printf("File not found.");
        exit(1);
    }
    else
    {

        while(fread(&std,sizeof(std),1,fp) == 1)
        {
            calculateProbation = atoi(std.probation);
            if(calculateProbation > 0)
            {
                printf("\n\tStudent Name   :%s",std.name);
                printf("\n\tStudent ID     :%s",std.id);
                printf("\n\tDepartment     :%s",std.dept);
                printf("\n\tCredit         :%s",std.credit);
                printf("\n\tC.G.P.A.       :%s",std.cgpa);
                printf("\n\tProbation      :%s",std.probation);
                printf("\n\tPhone No.      :%s",std.phone);
                printf("\n\tAddress        :%s",std.address);
                printf("\n\n");

                flag++;
            }

        }
    }
    fclose(fp);

    if(flag==0)
    {
        printf("\n\tProbation Student Details not found.\n\n");
    }

AGAIN:

    printf("\n\n\tEnter 1 to Student Information Menu and 0 to go to AdminMenu: ");
    scanf("%d",&n);
    fflush(stdin);

    if(n==1)
    {
        StudentInformation();
    }
    else if(n==0)
    {
        AdminMenu();
    }
    else
    {
        printf("\n\tInvalid Choice.");
        goto AGAIN;
    }

}



void StudentInformation()
{
    int ListChoice;

    system("cls");
    printf("\n\t\t\t\t\t----------------------------------------\n");
    printf("\t\t\t\t\t------  All Student Information  -------\n");
    printf("\t\t\t\t\t----------------------------------------\n");
    printf("\n\t\t\t\t\t1. View All Student List.");
    printf("\n\n\t\t\t\t\t2. View Passed Student List.");
    printf("\n\n\t\t\t\t\t3. View Probation Student List.");
    printf("\n\n\t\t\t\t\t4. Back To Admin Menu.");
    printf("\n\n\n\t\t\t\t\tEnter your choice: ");
    scanf("%d",&ListChoice);

    switch(ListChoice)
    {
    case 1:
    {
        system("cls");
        StudentList();
        getch();
        break;
    }
    case 2:
    {
        system("cls");
        PassedStudent();
        getch();
        break;
    }
    case 3:
    {
        system("cls");
        ProbationStudent();
        getch();
        break;
    }
    case 4:
    {
        AdminMenu();
    }
    default:
    {
        printf("Invalid Choice.");
    }
    }

}



void SearchStudent()
{
    system("cls");
    printf("\n\t\t\t\t\t----------------------------------------\n");
    printf("\t\t\t\t\t----   Search Student Information   ----\n");
    printf("\t\t\t\t\t----------------------------------------\n");

    char searchID[20];
    int flag = 0, n;

    FILE *fp;
    fp = fopen("StudentData.txt","rb+");
    if(fp == NULL)
    {
        printf("File not found.");
        exit(1);
    }
    else
    {
        fflush(stdin);
        printf("\n\tEnter Student ID: ");
        gets(searchID);

        while(fread(&std,sizeof(std),1,fp) == 1)
        {
            if(strcmp(std.id, searchID) == 0)
            {
                printf("\n\tStudent Name   :%s",std.name);
                printf("\n\tStudent ID     :%s",std.id);
                printf("\n\tDepartment     :%s",std.dept);
                printf("\n\tCredit         :%s",std.credit);
                printf("\n\tC.G.P.A.       :%s",std.cgpa);
                printf("\n\tProbation      :%s",std.probation);
                printf("\n\tPhone No.      :%s",std.phone);
                printf("\n\tAddress        :%s",std.address);
                printf("\n\n");

                flag++;
                break;
            }

        }
    }
    fclose(fp);

    if(flag==0)
    {
        printf("\n\tStudent ID not found.\n\tPlease Check Your Student ID.\n\n");
    }

AGAIN:

    printf("\n\n\tEnter 1 to Search again and 0 to go to AdminMenu: ");
    scanf("%d",&n);
    fflush(stdin);
    if(n==1)
    {
        SearchStudent();
    }
    else if(n==0)
    {
        AdminMenu();
    }
    else
    {
        printf("\n\tInvalid Choice.");
        goto AGAIN;
    }
}


void EditStudent()
{
    system("cls");
    printf("\n\t\t\t\t\t----------------------------------------\n");
    printf("\t\t\t\t\t-----   Edit Student Information   -----\n");
    printf("\t\t\t\t\t----------------------------------------\n");

    char searchID[20] , dp[30];
    int flag = 0, n;

    FILE *fp;
    fp = fopen("StudentData.txt","rb+");
    if(fp == NULL)
    {
        printf("File not found.");
        exit(1);
    }
    else
    {
        fflush(stdin);
        printf("\n\tEnter Student ID: ");
        gets(searchID);

        while(fread(&std,sizeof(std),1,fp) == 1)
        {
            if(strcmp(std.id, searchID) == 0)
            {
                printf("\n\tStudent Name   :%s",std.name);
                printf("\n\tStudent ID     :%s",std.id);
                printf("\n\tPassword       :%s",std.pass);
                printf("\n\tDepartment     :%s",std.dept);
                printf("\n\tCredit         :%s",std.credit);
                printf("\n\tC.G.P.A.       :%s",std.cgpa);
                printf("\n\tProbation      :%s",std.probation);
                printf("\n\tPhone No.      :%s",std.phone);
                printf("\n\tAddress        :%s",std.address);
                printf("\n\n");

                printf("\n\tEnter New Details: ");

                printf("\n\n\n\tEnter name            : ");
                gets(std.name);
                fflush(stdin);

                printf("\n\tEnter Student ID      : ");
                gets(std.id);
                fflush(stdin);

                printf("\n\tEnter Password        : ");
                gets(std.pass);
                fflush(stdin);

                printf("\n\tEnter Department      : ");
                gets(dp);
                strupr(dp);
                strcpy(std.dept , dp);
                fflush(stdin);

                printf("\n\tEnter Credit          : ");
                gets(std.credit);
                fflush(stdin);

                printf("\n\tEnter C.G.P.A.        : ");
                gets(std.cgpa);
                fflush(stdin);

                printf("\n\tEnter Probation       : ");
                gets(std.probation);
                fflush(stdin);

                printf("\n\tEnter Phone No.       : ");
                gets(std.phone);
                fflush(stdin);

                printf("\n\tEnter address         :");
                gets(std.address);
                fflush(stdin);

                fseek(fp,-sizeof(std),SEEK_CUR);

                fwrite(&std,sizeof(std),1,fp);

                flag++;

                printf("\n\n\tDetail Edited Successfully.");
                break;
            }
        }
    }

    fclose(fp);

    if(flag==0)
    {
        printf("\n\tStudent ID not found.\n\tPlease Check Student ID.\n\n");
        getch();
        EditStudent();
    }

AGAIN:

    printf("\n\n\tEnter 1 to Edit again and 0 to go to AdminMenu: ");
    scanf("%d",&n);
    fflush(stdin);
    if(n==1)
    {
        EditStudent();
    }
    else if(n==0)
    {
        AdminMenu();
    }
    else
    {
        printf("\n\tInvalid Choice.");
        goto AGAIN;
    }

}

void DeleteStudent()
{
    system("cls");
    printf("\n\t\t\t\t\t----------------------------------------\n");
    printf("\t\t\t\t\t----   Delete Student Information   ----\n");
    printf("\t\t\t\t\t----------------------------------------\n");

    char searchID[20];
    int flag = 0, flagp = 0, flagm = 0, n;

    FILE *fp, *fpp, *fpm;

    fp = fopen("StudentData.txt","rb");
    fpp = fopen("ParentData.txt","rb");
    fpm = fopen("StudentMarks.txt","rb");

    if(fp == NULL)
    {
        printf("File not found.");
        exit(1);
    }
    else
    {
        FILE *fpt , *fppt, *fpmt;
        fpt = fopen("TempData.txt","wb");
        if(fpt == NULL)
        {
            printf("File not found.");
            exit(1);
        }

        fflush(stdin);
        printf("\n\tEnter Student ID: ");
        gets(searchID);

        while(fread(&std,sizeof(std),1,fp) == 1)
        {
            if(strcmp(std.id, searchID) != 0)
            {
                fwrite(&std,sizeof(std),1,fpt);
            }
            else
            {
                printf("\n\tStudent Name   :%s",std.name);
                printf("\n\tStudent ID     :%s",std.id);
                printf("\n\tDepartment     :%s",std.dept);
                printf("\n\tCredit         :%s",std.credit);
                printf("\n\tC.G.P.A.       :%s",std.cgpa);
                printf("\n\tProbation      :%s",std.probation);
                printf("\n\tPhone No.      :%s",std.phone);
                printf("\n\tAddress        :%s",std.address);
                printf("\n\n");

                printf("\n\tStudent's record deleted successfully.\n\n");
                flag++;
            }
        }

        fclose(fpt);

        fppt = fopen("TempParent.txt","wb");
        if(fppt == NULL)
        {
            printf("File not found.");
            exit(1);
        }

        while(fread(&prnt,sizeof(prnt),1,fpp) == 1)
        {
            if(strcmp(prnt.id, searchID) != 0)
            {
                fwrite(&prnt,sizeof(prnt),1,fppt);
            }
            else
            {
                printf("\n\tStudent ID         :%s",prnt.id);
                printf("\n\tFather's name      :%s",prnt.fathers_name);
                printf("\n\tFather's phone No. :%s",prnt.fathers_phone);
                printf("\n\tMother's name      :%s",prnt.mothers_name);
                printf("\n\tMother's Phone No. :%s",prnt.mothers_phone);
                printf("\n\n");

                printf("\n\tParents record deleted successfully.\n\n");
                flagp++;
            }
        }
        fclose(fppt);

        fpmt = fopen("TempMarks.txt","wb");
        if(fpmt == NULL)
        {
            printf("File not found.");
            exit(1);
        }

        while(fread(&mark,sizeof(mark),1,fpm) == 1)
        {
            if(strcmp(mark.id, searchID) != 0)
            {
                fwrite(&mark,sizeof(mark),1,fpmt);
            }
            else
            {
                printf("\n\tStudent name         : %s",mark.name);
                printf("\n\tStudent ID           : %s",mark.id);
                printf("\n\tTotal QUIZ exam marks: %.2f",mark.quiz);
                printf("\n\tTotal MID exam marks : %.2f",mark.mid);
                printf("\n\tFinal exam marks     : %.2f",mark.fin);
                printf("\n\n");

                printf("\n\tMarks record deleted successfully.\n\n");
                flagm++;
            }
        }
        fclose(fpmt);

    }

    fclose(fp);
    fclose(fpp);
    fclose(fpm);

    remove("StudentData.txt");
    rename("TempData.txt","StudentData.txt");

    remove("ParentData.txt");
    rename("TempParent.txt","ParentData.txt");

    remove("StudentMarks.txt");
    rename("TempMarks.txt","StudentMarks.txt");

    if(flag==0 && flagp == 0 && flagm == 0)
    {
        printf("\n\tStudent ID not found.\n\tSo Delete Operation Can't Happened.\n\n");
    }
    else
    {
        if(flag == 0)
            printf("\n\tStudent data not found.\n\tSo delete operation can't happened.\n\n");
        if(flagp == 0)
            printf("\n\tParent data not found.\n\tSo delete operation can't happened.\n\n");
        if(flagm == 0)
            printf("\n\tStudent's mark data not found.\n\tSo delete operation can't happened.\n\n");
    }

AGAIN:

    printf("\n\n\tEnter 1 to Delete again and 0 to go to AdminMenu: ");
    scanf("%d",&n);
    fflush(stdin);
    if(n==1)
    {
        DeleteStudent();
    }
    else if(n==0)
    {
        AdminMenu();
    }
    else
    {
        printf("\n\tInvalid Choice.");
        goto AGAIN;
    }

}



void StudentLogin()
{
    system("cls");

    printf("\n\t\t\t\t\t--------------------------------------\n");
    printf("\t\t\t\t\t-----     Student Login Menu     -----\n");
    printf("\t\t\t\t\t--------------------------------------\n");

    printf("\n\n\t\t\t\t\tEnter Your ID : ");
    gets(LoginID);
    fflush(stdin);

    printf("\n\n\t\t\t\t\tEnter Password: ");
    gets(LoginPassword);
    fflush(stdin);

    FILE *fpt;
    int flag = 0, n;

    fpt = fopen("StudentData.txt","rb+");

    if(fpt == NULL)
    {
        printf("File not found.");
        exit(1);
    }

    while(fread(&std,sizeof(std),1,fpt) == 1)
    {
        if(strcmp(std.id, LoginID)==0 && strcmp(std.pass, LoginPassword)==0 )
        {
            flag++;
        }
    }

    fclose(fpt);

    if(flag != 0)
    {
        StudentLoginInfo(LoginID);
    }
    else
    {
        printf("\n\t\t\t\t\tID or Password Doesn't Match.\n\t\t\t\t\tPlease Enter Correct Info.");

AGAIN:

        printf("\n\n\t\t\t\t\tEnter 1 to Login again and 0 to Main Menu: ");
        scanf("%d",&n);
        fflush(stdin);

        if(n==1)
        {
            StudentLogin();
        }
        else if(n==0)
        {
            MainMenu();
        }
        else
        {
            printf("\n\n\t\t\t\t\tInvalid Choice.");
            goto AGAIN;
        }
    }

}

void StudentLoginInfo (char *LoginID)
{
    system("cls");
    int n;
    printf("\n\t\t\t\t\t----------------------------------------\n");
    printf("\t\t\t\t\t----       Student Information      ----\n");
    printf("\t\t\t\t\t----------------------------------------\n");

    FILE *fp,*fpp,*fpm;

    fp = fopen("StudentData.txt","rb+");
    if(fp == NULL)
    {
        printf("File not found.");
        exit(1);
    }
    else
    {
        while(fread(&std,sizeof(std),1,fp) == 1)
        {
            if(strcmp(std.id, LoginID) == 0)
            {
                printf("\n\tStudent Name   :%s",std.name);
                printf("\n\tStudent ID     :%s",std.id);
                printf("\n\tDepartment     :%s",std.dept);
                printf("\n\tCredit         :%s",std.credit);
                printf("\n\tC.G.P.A.       :%s",std.cgpa);
                printf("\n\tProbation      :%s",std.probation);
                printf("\n\tPhone No.      :%s",std.phone);
                printf("\n\tAddress        :%s",std.address);
                printf("\n\n");

                break;
            }
        }
    }
    fclose(fp);


    printf("\n\t\t\t\t\t----------------------------------------\n");
    printf("\t\t\t\t\t----       Parent's Information      ----\n");
    printf("\t\t\t\t\t----------------------------------------\n");

    fpp = fopen("ParentData.txt","rb+");
    if(fpp == NULL)
    {
        printf("File not found.");
        exit(1);
    }
    else
    {

        while(fread(&prnt,sizeof(prnt),1,fpp) == 1)
        {
            if(strcmp(prnt.id, LoginID) == 0)
            {
                // printf("\n\tStudent ID         :%s",prnt.id);
                printf("\n\tFather's name      :%s",prnt.fathers_name);
                printf("\n\tFather's phone No. :%s",prnt.fathers_phone);
                printf("\n\tMother's name      :%s",prnt.mothers_name);
                printf("\n\tMother's Phone No. :%s",prnt.mothers_phone);
                printf("\n\n");

                break;
            }
        }
    }
    fclose(fpp);


    printf("\n\t\t\t\t\t----------------------------------------\n");
    printf("\t\t\t\t\t----          Student Marks         ----\n");
    printf("\t\t\t\t\t----------------------------------------\n");

    fpm = fopen("StudentMarks.txt","rb+");
    if(fpm==NULL)
    {
        printf("File not found.");
        exit(1);
    }

    else
    {
        while(fread(&mark,sizeof(mark),1,fpm))
        {
            if(strcmp(mark.id, LoginID) == 0)
            {
                //printf("\n\tStudent name         : %s",mark.name);
                //printf("\n\tStudent ID           : %s",mark.id);
                printf("\n\tTotal QUIZ exam marks: %.2f",mark.quiz);
                printf("\n\tTotal MID exam marks : %.2f",mark.mid);
                printf("\n\tFinal exam marks     : %.2f",mark.fin);
                printf("\n\n");
            }
        }
    }
    fclose(fpm);

AGAIN:

    printf("\n\n\tEnter 1 to Student Login Menu and 0 to go to Main Menu: ");
    scanf("%d",&n);
    fflush(stdin);
    if(n==1)
    {
        StudentLogin();
    }
    else if(n==0)
    {
        MainMenu();
    }
    else
    {
        printf("\n\tInvalid Choice.");
        goto AGAIN;
    }
}


int AdminLogin()
{
    system("cls");
    int n;

    printf("\n\t\t\t\t\t---------------------------------------\n");
    printf("\t\t\t\t\t-----       Admin Login Menu      -----\n");
    printf("\t\t\t\t\t---------------------------------------\n");

    char idAdmin[30], passAdmin[30];

    printf("\n\n\t\t\t\t\tEnter Admin ID : ");
    gets(idAdmin);
    fflush(stdin);

    printf("\n\n\t\t\t\t\tEnter Password : ");
    gets(passAdmin);
    fflush(stdin);

    if(strcmp(idAdmin,"a")==0 && strcmp(passAdmin,"a")==0 )
    {
        return 1;
    }
    else
    {
        printf("\n\n\t\t\t\t\tID or Password Doesn't Match.\n\n\t\t\t\t\tPlease Enter Correct Info.");

AGAIN:

        printf("\n\n\t\t\t\t\tEnter 1 to go to Admin Login Menu and 0 to Main Menu: ");
        scanf("%d",&n);
        fflush(stdin);

        if(n==1)
        {
            AdminLogin();
        }
        else if(n==0)
        {
            MainMenu();
        }
        else
        {
            printf("\n\n\t\t\t\t\tInvalid Choice.");
            goto AGAIN;
        }
    }

}





void AdminMenu()
{
        int n, choice;

        while(1)
        {
            system("cls");

            printf("\n\t\t\t\t\t---------------------------------------\n");
            printf("\t\t\t\t\t---------      Admin MENU      --------\n");
            printf("\t\t\t\t\t---------------------------------------\n");

            printf("\n\n\t\t\t\t\t1. Add Student Details.");
            printf("\n\n\t\t\t\t\t2. View Student List.");
            printf("\n\n\t\t\t\t\t3. Search Student.");
            printf("\n\n\t\t\t\t\t4. Edit Student details.");
            printf("\n\n\t\t\t\t\t5. Delete Student Details.");
            printf("\n\n\t\t\t\t\t6. Add parent Details.");
            printf("\n\n\t\t\t\t\t7. Search parent Details.");
            printf("\n\n\t\t\t\t\t8. Add student marks.");
            printf("\n\n\t\t\t\t\t9. View student marks.");
            printf("\n\n\t\t\t\t\t10. Logout.");

            printf("\n\n\t\t\t\t\tEnter your choice: ");
            scanf("%d",&choice);

            fflush(stdin);

            switch(choice)
            {
            case 1:
            {
                system("cls");
                AddStudent();
                getch();
                break;
            }
            case 2:
            {
                StudentInformation();
            }
            case 3:
            {
                system("cls");
                SearchStudent();
                getch();
                break;
            }
            case 4:
            {
                system("cls");
                EditStudent();
                getch();
                break;
            }
            case 5:
            {
                system("cls");
                DeleteStudent();
                getch();
                break;
            }
            case 6:
            {
                system("cls");
                AddParent();
                getch();
                break;
            }
            case 7:
            {
                system("cls");
                ViewParent();
                getch();
                break;
            }
            case 8:
            {
                system("cls");
                AddStudentMarks();
                getch();
                break;
            }
            case 9:
            {
                system("cls");
                ViewStudentMarks();
                getch();
                break;
            }
            case 10:
            {
                MainMenu();

            }
            default:
            {
                system("cls");
                printf("\n\n\n\n\t\t\t\t\tInvalid Choice.");
AGAIN:

                printf("\n\n\t\t\t\t\tEnter 1 to go to Admin Menu and 0 to Main Menu: ");
                scanf("%d",&n);
                fflush(stdin);
                if(n==1)
                {
                    AdminMenu();
                }
                else if(n==0)
                {
                    MainMenu();
                }
                else
                {
                    printf("\n\n\t\t\t\t\tInvalid Choice.");
                    goto AGAIN;
                }
            }
            }
        }
}


void MainMenu()
{
    int n, choice, adminReturn = 0;

    while(1)
    {
        system("cls");

        printf("\n\t\t\t\t\t---------------------------------------\n");
        printf("\t\t\t\t\t---------      Main MENU      ---------\n");
        printf("\t\t\t\t\t---------------------------------------\n");

        printf("\n\n\t\t\t\t\t     ****************************");
        printf("\n\n\t\t\t\t\t     **  1. Login As Admin.    **");
        printf("\n\n\t\t\t\t\t     **  2. Login As Student.  **");
        printf("\n\n\t\t\t\t\t     **  3. Exit.              **");
        printf("\n\n\t\t\t\t\t     ****************************");
        printf("\n\n\t\t\t\t\t\tEnter your choice: ");
        scanf("%d",&choice);

        fflush(stdin);

        switch(choice)
        {
        case 1:
        {

            adminReturn = AdminLogin();

            if(adminReturn == 1)
            {
                AdminMenu();
            }

        }
        case 2:
        {
            StudentLogin();
        }
        case 3:
        {
            printf("\n\n\n\n\t\t\t\t\tExiting The program.......\n\n");
            exit(0);
        }
        default:
        {
            system("cls");
            printf("\n\n\n\n\t\t\t\t\tInvalid Choice.");
AGAIN:
            printf("\n\n\t\t\t\t\tEnter 1 to go to Main Menu and 0 to exit: ");
            scanf("%d",&n);
            fflush(stdin);

            if(n==1)
            {
                MainMenu();
            }
            else if(n==0)
            {
                printf("\n\n\n\n\t\t\t\t\tprogram is exiting......\n\n");
                exit(0);
            }
            else
            {
                printf("\n\n\t\t\t\t\tInvalid Choice.");
                goto AGAIN;
            }
        }
        }
    }
}

void display()
{
    printf("\n\n\n\n\n\n\n\n\n\n\t\t                  ---------------------------------------------------\n\n");
    printf("\t\t\t        --------  STUDENT DATABASE MANAGEMENT  SYSTEM  --------     \n\n");
    printf("\t\t                  ---------------------------------------------------\n\n");

    printf("\t\t\t                      Press any key to continue");
}

void main()
{
    display();
    getch();
    //AdminMenu();
    MainMenu();
}

