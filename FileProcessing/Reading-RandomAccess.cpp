// Fig. 11.14: fig11_14.c (Reading a random-access file sequentially)

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

    cfPtr = fopen("accounts.dat","rb");

    if(cfPtr==NULL)
    {
        puts("File could not be opened.");
    }
    else
    {
        printf("\n%-6s%-16s%-11s%10s\n","Acct","Last Name","First Name","Balance");

        while(!feof(cfPtr))
        {
            Client aClient = {0,"","",0.0}; //whose do not use additional line, alway use struct clientData instead Client.

            int result = fread(&aClient,sizeof(Client),1,cfPtr);

            if (result!=0 && aClient.acctNum != 0)
            {
                printf("%-6d%-16s%-11s%10.2f\n",aClient.acctNum,aClient.lastName,aClient.firstName,aClient.balance);
            }
        }
        fclose(cfPtr);
    }
    return 0;
}       