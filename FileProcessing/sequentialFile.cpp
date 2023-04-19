//This program creates a simple dues collection application to better understand sequential file operations.

#include <stdio.h>

struct node {
    int aptNum;
    char name[20];
    char surname[20];
    char date[10];
    float amount;
};

typedef struct node Apartment;

void takeRegistry(Apartment *p );
void newRegistry(FILE *file, Apartment apt);
void allRegistries(FILE *file, Apartment apt);
void theRegistry(FILE *file,Apartment apt);
void showDebtors(FILE *file,Apartment apt);
void updateRegistry(FILE *file, Apartment apt);
void deleteRegistry(FILE *file, Apartment apt);

int main(void)
{
    FILE *afPtr;

    Apartment apt;
    int processNum;
    int control = 1;

    while (control)
    {
    puts("\nProcess Menu");
    puts("1 - Add new registry");
    puts("2 - Show all registries");
    puts("3 - Show spesific registry");
    puts("4 - Show debtors");
    puts("5 - Update registry");
    puts("6 - Delete registry");
    puts("7 - Exit");

    printf("\nSelect process: ");
    scanf("%d",&processNum);


    switch(processNum)
    {
        case 1:
        {
            takeRegistry(&apt);
            newRegistry(afPtr,apt);
            break;
        }
        case 2:
        {
            allRegistries(afPtr,apt);
            break;
        }
        case 3:
        {
            theRegistry(afPtr,apt);
            break;
        }
        case 4:
        {
            showDebtors(afPtr,apt);
            break;
        }
        case 5:
        {
            updateRegistry(afPtr, apt);
            break;
        }
        case 6:
        {
            deleteRegistry(afPtr, apt);
            break;
        }
        case 7:
        {
            control = 0;
            puts("\nClosing ...\n");
            break;
        }
    }
}
   
return 0;
}

void takeRegistry(Apartment *p )
{
    printf("\nApartment No: ");
    scanf("%d", &p->aptNum);

    printf("Name: ");
    scanf("%s", p->name);

    printf("Surname: ");
    scanf("%s", p->surname);

    printf("Date (dd.mm.yyyy): ");
    scanf("%s", p->date);

    printf("Amount: ");
    scanf("%f", &p->amount);
}

void newRegistry(FILE *file, Apartment apt)
{
    file = fopen("clients.txt","a");

    if (file == NULL)
    {
        puts("\nFile could not be opened.");
    }
    else
    {
        fprintf(file, "%d %s %s %s %.2f\n", apt.aptNum, apt.name, apt.surname, apt.date, apt.amount);

        printf("\nNew registry added: %d %s %s %s %.2f\n",apt.aptNum, apt.name, apt.surname, apt.date, apt.amount);
    }
    fclose(file);
}

void allRegistries(FILE *file,Apartment apt)
{
    file = fopen("clients.txt","r");

    if(file == NULL)
    {
        puts("\nFile could not be opened.");
    }
    else
    {
        printf("\n%-8s%-8s%-10s%-14s%-10s\n\n","No","Name","Surname","Date","Amount");
        fscanf(file,"%d %s %s %s %f",&apt.aptNum,apt.name,apt.surname,apt.date,&apt.amount);
        while(!feof(file))
        {
            printf("%d \t%s \t%s \t  %s \t%.2f\n",apt.aptNum,apt.name,apt.surname,apt.date,apt.amount);
            fscanf(file,"%d %s %s %s %f",&apt.aptNum,apt.name,apt.surname,apt.date,&apt.amount);
        }
        fclose(file);
    }
}

void theRegistry(FILE *file,Apartment apt)
{
    int theAptNum;
    int found = 0;

    printf("\nEnter the apartment number you want to view: ");
    scanf("%d",&theAptNum);
    
    file = fopen("clients.txt","r");

    if (file==NULL)
    {
        puts("\nFile could not be opened.");
    }
    else
    {
        
        fscanf(file,"%d %s %s %s %f",&apt.aptNum,apt.name,apt.surname,apt.date,&apt.amount);

        while(!feof(file))
        {
            if(apt.aptNum == theAptNum)
            {
                printf("\n%-8s%-8s%-10s%-14s%-10s\n\n","No","Name","Surname","Date","Amount");
                printf("%d \t%s \t%s \t  %s \t%.2f\n",apt.aptNum,apt.name,apt.surname,apt.date,apt.amount);
                found = 1;
                break;
            }
            fscanf(file,"%d %s %s %s %f",&apt.aptNum,apt.name,apt.surname,apt.date,&apt.amount);
        }

        if (!found)
        {
            printf("\nThe owner of apartment number %d has not paid their maintenance fees.\n",theAptNum);
        }

    fclose(file);
    }
}

void showDebtors(FILE *file,Apartment apt)
{
    int found = 0;

    file = fopen("clients.txt","r");

    if(file == NULL)
    {
        puts("File could not be opened.");
    }
    else
    {
        fscanf(file,"%d %s %s %s %f",&apt.aptNum,apt.name,apt.surname,apt.date,&apt.amount);
        while(!feof(file))
        {
            if(apt.amount < 0)
            {
                if (found==0)
                {
                printf("\n%-8s%-8s%-10s%-14s%-10s\n\n","No","Name","Surname","Date","Amount");
                printf("%d \t%s \t%s \t  %s \t%.2f\n",apt.aptNum,apt.name,apt.surname,apt.date,apt.amount);
                found = 1;
                }
                else
                {
                printf("%d \t%s \t%s \t  %s \t%.2f\n",apt.aptNum,apt.name,apt.surname,apt.date,apt.amount);
                }
            }
            fscanf(file,"%d %s %s %s %f",&apt.aptNum,apt.name,apt.surname,apt.date,&apt.amount);
        }
        if(!found)
        {
            puts("\nThere is no debtors.");
        }

    fclose(file);
    }
}

void updateRegistry(FILE *file, Apartment apt)
{
    FILE *tempFile;
    int flag = 0;
    int updatedAptNum;
    Apartment updatedApt;

    printf("\nEnter the apartment number you want to update: ");
    scanf("%d",&updatedAptNum);
    
    file = fopen("clients.txt","r");
    tempFile = fopen("tmpClients.txt","w");

    if (tempFile == NULL)
    {
        puts("tmpClients.txt could not be opened.");
    }
    else
    {
        if(file==NULL)
        {
          puts("clients.txt could not be opened.");
        }
        else
        {
            fscanf(file,"%d %s %s %s %f",&apt.aptNum,apt.name,apt.surname,apt.date,&apt.amount);
            while(!feof(file))
            {
                if(apt.aptNum == updatedAptNum)
                {
                    flag = 1;
                    printf("\nThe data to be changed: %d %s %s %s %.2f\n",apt.aptNum,apt.name,apt.surname,apt.date,apt.amount);

                    printf("\nApartment No: %d\n",updatedAptNum);
                    
                    updatedApt.aptNum = updatedAptNum;

                    printf("Name: ");
                    scanf("%s", updatedApt.name);

                    printf("Surname: ");
                    scanf("%s", updatedApt.surname);

                    printf("Date (dd.mm.yyyy): ");
                    scanf("%s", updatedApt.date);

                    printf("Amount: ");
                    scanf("%f", &updatedApt.amount);

                    printf("\nUpdated data: %d %s %s %s %.2f\n",updatedApt.aptNum,updatedApt.name,updatedApt.surname,updatedApt.date,updatedApt.amount);

                    fprintf(tempFile,"%d %s %s %s %.2f\n",updatedApt.aptNum,updatedApt.name,updatedApt.surname,updatedApt.date,updatedApt.amount);
                }
                else
                {
                    fprintf(tempFile,"%d %s %s %s %.2f\n",apt.aptNum,apt.name,apt.surname,apt.date,apt.amount);
                }
                fscanf(file,"%d %s %s %s %f",&apt.aptNum,apt.name,apt.surname,apt.date,&apt.amount);
            }
            fclose(file);
            fclose(tempFile);
            
            if ( flag != 1)
            {
                printf("The apartment number has not been found in the file.\n");
            }
            else
            {
                file = fopen("clients.txt","w");
                tempFile = fopen("tmpClients.txt","r");

                fscanf(tempFile,"%d %s %s %s %f",&apt.aptNum,apt.name,apt.surname,apt.date,&apt.amount);

                while(!feof(tempFile))
                {
                    fprintf(file,"%d %s %s %s %f\n",apt.aptNum,apt.name,apt.surname,apt.date,apt.amount);
                    fscanf(tempFile,"%d %s %s %s %f",&apt.aptNum,apt.name,apt.surname,apt.date,&apt.amount);
                }

            }
            fclose(tempFile);
            tempFile = fopen("tmpClients.txt","w");
            fclose(tempFile);
            fclose(file);
        }
    }
}

void deleteRegistry(FILE *file, Apartment apt)
{
    FILE *tempFile;
    int deletedAptNum;
    int flag = 0;

    file = fopen("clients.txt","r");
    tempFile = fopen("tmpClients.txt","w");

    printf("\nEnter the apartment number you want to delete: ");
    scanf("%d",&deletedAptNum);

    if(tempFile==NULL)
    {
        puts("tempFile could not be opened.");
    }
    else
    {
        if(file == NULL)
        {
            puts("file could not be opened.");
        }
        else
        {
            fscanf(file,"%d %s %s %s %f",&apt.aptNum,apt.name,apt.surname,apt.date,&apt.amount);
            while(!feof(file))
            {
                if(apt.aptNum == deletedAptNum)
                {
                    flag = 1;
                    printf("\nDeleted data: %d %s %s %s %.2f\n",apt.aptNum,apt.name,apt.surname,apt.date,apt.amount);
                }
                else
                {
                    fprintf(tempFile,"%d %s %s %s %.2f\n",apt.aptNum,apt.name,apt.surname,apt.date,apt.amount);
                }
                fscanf(file,"%d %s %s %s %f",&apt.aptNum,apt.name,apt.surname,apt.date,&apt.amount);
            }
            fclose(tempFile);
            fclose(file);

            if(!flag)
            {
                puts("Apartment number is not found.");
            }
            else
            {
                file = fopen("clients.txt","w");
                tempFile = fopen("tmpClients.txt","r");

                fscanf(tempFile,"%d %s %s %s %f",&apt.aptNum,apt.name,apt.surname,apt.date,&apt.amount);
                while(!feof(tempFile))
                {
                    fprintf(file,"%d %s %s %s %.2f\n",apt.aptNum,apt.name,apt.surname,apt.date,apt.amount);
                    fscanf(tempFile,"%d %s %s %s %f",&apt.aptNum,apt.name,apt.surname,apt.date,&apt.amount);
                }
            fclose(tempFile);
            fclose(file);
            }
        }
    }
}