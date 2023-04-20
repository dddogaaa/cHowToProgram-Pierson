// Fig. 11.11: fig11_11.c (Writing data randomly to a random-access file)

#include <stdio.h>

struct clientData {
    unsigned int acctNum;
    char lastName[15];
    char firstName[10];
    double balance;
};

typedef struct clientData Client; //Additionally

int main(void)
{
    FILE *cfPtr;

    cfPtr = fopen("accounts.dat","rb+");

    if(cfPtr==NULL)
    {
        puts("File could not be opened.");
    }
    else
    {
        Client aClient = {0,"","",0.0}; //whose do not use additional line, alway use 'struct clientData' instead Client.

        printf("\nEnter account number (1 to 100, 0 to end input): ");
        scanf("%d",&aClient.acctNum);
    
        while (aClient.acctNum != 0)
        {
            puts("\nEnter lastname: ");
            scanf("%s",aClient.lastName);

            puts("\nEnter firstname: ");
            scanf("%s",aClient.firstName);

            puts("\nEnter balance: ");
            scanf("%lf",&aClient.balance);

            printf("\nAdded: %d %s %s %.2lf\n",aClient.acctNum,aClient.lastName,aClient.firstName,aClient.balance);

            fseek(cfPtr, (aClient.acctNum - 1) * sizeof(Client), SEEK_SET);

            fwrite(&aClient, sizeof(Client),1,cfPtr);

            printf("\nEnter account number: ");
            scanf("%d",&aClient.acctNum);
        }
        fclose(cfPtr);
    }
    return 0;
}