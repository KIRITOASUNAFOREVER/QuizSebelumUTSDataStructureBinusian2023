#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct data{
	char nama[100];
	char ticketID[100];
	data *next,*prev;
}*head,*tail,*current;

void pushTail(char nama[],char ticketID[])
{
	current = (data*)malloc(sizeof(struct data));
	
	strcpy(current->nama,nama);
	strcpy(current->ticketID,ticketID);
	current->next=current->prev=NULL;
	
	if(head==NULL)
	{
		head=tail=current;
	}
	else
	{  
        current->prev=tail;
		  tail->next=current;
		  tail=current;
	}
}

int isUnique(char tkID[],int penanda)
{
        data *temp = head;
        while(temp!=NULL)
        {
            if(strcmp(temp->ticketID, tkID)==0)
            {
                penanda  = 1;
                break;
            }
            temp=temp->next;
        }
    return penanda;
}

void popHead()
{
	if(head==NULL)
	{
		printf("Data not found!\n");getchar();
	}
	else if(head==tail)
	{
	    printf("%s enter the concert hall",head->nama);getchar();
		head=tail=NULL;
		free(current);
	}
	else
	{
	     printf("%s enter the concert hall",head->nama);getchar();
	        head=head->next;
			head->prev=NULL;
			free(current);
	}
}

void popHeadAll()
{
	if(head==NULL)
	{
		printf("Data not found!\n");getchar();
	}
	else if(head==tail)
	{
		head=tail=NULL;
		free(current);
	}
	else
	{
	    head=head->next;
		head->prev=NULL;
		free(current);
	}
}
void popAll(){
	while(head!=NULL){
		popHeadAll();
	}
}

void search(char ticketID[])  
{  
    current = (data*)malloc(sizeof(struct data));
    int i=0,flag; 
    
    current = head;   
    if(current == NULL)  
    {  
        printf("\nEmpty Data\n");  
        getchar();
    }  
    else  
    {   
        while (current!=NULL)  
        {  
            if(strcmp(current->ticketID,ticketID)==0)  
            {  
                printf("Queue Number: %d ",i+1);getchar();
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            current = current->next;  
        }  
        if(flag==1)  
        {  
            printf("There's no item to search, please insert new data\n");  
            getchar();
        }  
    }
}

int ada(char friendTicketID[],int check)  
{  
    current = (data*)malloc(sizeof(struct data));
    int i=0,flag; 
    
    current = head;   
    if(current == NULL)  
    {  
        printf("\nEmpty Data\n");  
        getchar();
    }  
    else  
    {   
        while (current!=NULL)  
        {  
            if(strcmp(current->ticketID,friendTicketID)==0)  
            {  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            current = current->next;  
        }  
        return flag;
    }
}

int edit(char ticketID[],int check)
{
    current = (data*)malloc(sizeof(struct data));
    int flag; 
    
    current = head;   
    if(current == NULL)  
    {  
        printf("\nEmpty Data\n");  
        getchar();
    }  
    else  
    {   
        while (current!=NULL)  
        {  
            if(strcmp(current->ticketID,ticketID)==0)  
            {  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }   
            current = current->next;  
        }  
    }
    return flag;
}

void view()
{
	current=head;
	
	if(current==NULL)
	{
		printf("\nNo Data\n");
	}
	else
	{
		while(current!=NULL)
		{
			printf("%-25s %-5s\n",current->nama,current->ticketID);
			current=current->next;
		}
	}
}
void pilihan()
{
    printf("\n\n\n\n");
        printf("\n1. Register New Audience\n");
        printf("2. Enter the Concert Hall\n");
        printf("3. Search Queue Number\n");
        printf("4. Update Audience Data\n");
        printf("5. Exit\n");
        printf("Input : ");
}
void menu()
{
    system("cls");
    printf("=====================\n");
        printf("FT World Tour Concert\n");
        printf("=====================");
        printf("\n\n");
        printf("\tName\t\tTicketID\n");
        printf("=================================\n");
        view();
}

int main()
{
    int input;
    char name[100];
    char ticketID[10];
    char haveFriend[5];
    char friendTicketID[10];
    int check = 0;
    int status =0;
    
    do{
        system("cls");
        menu();
        pilihan();
        
        scanf("%d",&input);getchar();
        
        switch(input){
            case 1:
                system("cls");
                menu();printf("\n\n\n");
                do{
                    printf("Audience Name [2-20 characters]: ");
                    scanf("%[^\n]",name);fflush(stdin);
                }while(strlen(name) <  2 || strlen(name) > 20);
                
                do{
                    printf("Ticket ID [Unique 5 digits number]: ");
                    scanf("%s",ticketID);
                    check = isUnique(ticketID,0);     
                }while(strlen(ticketID)!=5 || check==1);
                
                do{
                    printf("Do you have a friend in the queue [yes/no]? ");
                    scanf("%s",haveFriend);
                }while(strcmp(haveFriend,"yes")!=0 && strcmp(haveFriend,"no")!=0);
                
                if(strcmp(haveFriend,"yes")==0 && head!=NULL)
                {
                    do{
                        printf("Friend's Ticket ID [5 digits number]: ");
                        scanf("%s",friendTicketID);
                        status = ada(friendTicketID,0);
                    }while(strlen(friendTicketID)!=5 || status==1);
                        
                    pushTail(name,ticketID);
                }
                else
                {
                    if(head==NULL && strcmp(haveFriend,"yes")==0)
                    {
                        printf("No Data Avaiable, You are the First Customer\n");
                    }
                    pushTail(name,ticketID);
                }
                printf("ADD DATA SUCCESS !!!");
                getchar();getchar();
            break;
            case 2:
                popHead();
            break;
            case 3:
                system("cls");
                menu();printf("\n\n\n");
                current = head;
			    if(current==NULL)
			    {
			         printf("There's no item to search, please insert new data\n");  
                    getchar();
                }
                else
                {
                    printf("Ticket ID [5 digits number]: ");  
                    scanf("%s",&ticketID);  fflush(stdin);
    			    search(ticketID);     
                } 
            break;
            case 4:
                system("cls");
                menu();printf("\n\n\n");
                current = head;
			    if(current==NULL)
			    {
			         printf("There's no item to update, please insert new data\n");  
                    getchar();
                }
                else
                {
                     printf("Ticket ID [5 digits number]: ");    
                    scanf("%s",&ticketID);  fflush(stdin);
                    int check = edit(ticketID,0);
                    if(check==0)
                    {
                        do{
                            printf("Audience Name [2-20 characters]: ");
                            scanf("%[^\n]",name);fflush(stdin);
                        }while(strlen(name) <  2 || strlen(name) > 20);
                        strcpy(current->nama,name);
                        printf("UPDATE DATA SUCCESS !!!"); getchar();
                    }
                    else
                    {
                        printf("TicketID yang ingin diganti tidak ditemukan\n");
                        getchar();
                    }
                }    
            break;
            case 5:
                popAll();
                break;
        }
    }while(input < 1 || input > 5 || input!=5);
    
	return 0;
}
