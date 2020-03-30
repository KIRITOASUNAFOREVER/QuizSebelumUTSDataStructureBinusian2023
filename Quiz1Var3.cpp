#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct data{
	char kata[100];
	data *next,*prev;
}*head,*tail,*current;

void pushTail(char kata[])
{
	current = (data*)malloc(sizeof(struct data));
	
	strcpy(current->kata,kata);
	current->next=current->prev=NULL;
	
	if(head==NULL)
	{
		head = tail = current;
	}
	else
	{
		current->prev=tail;
		tail->next=current;
		tail=current;
	}
}

void pushmid(char kataLama[] , char kata[]){
    current=(data*)malloc(sizeof(struct data));
	strcpy(current->kata,kata);
	current->next=current->prev=NULL;
	
	data *temp=head;
			
			while(strcmp(temp->kata,kataLama)!=0)
			{
				temp=temp->next;
			}
			if(temp->next==NULL)
			{
			    pushTail(kata);
            }
            else
            {
                if(temp==head)
			{
			    current->prev = temp;
			    current->next = temp->next;
			    current->next->prev = current;
			    current->prev->next = current;
            }
            else
            {
                current->prev=temp;
			    current->next=temp->next;
			    current->next->prev = current;
			    current->prev->next = current;
            }
            }
}

void popTail()
{
	if(head ==NULL)
	{
		printf("No Data\n");
	}
	else if(head == tail)
	{
		current=head;
		head = tail = NULL;
		free(current);
	}
	else
	{
		current=tail;
			tail=tail->prev;
			tail->next=NULL;
			free(current);
	}
}

void search(char kata[])  
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
            if(strcmp(current->kata,kata)==0)  
            {  
                printf("\n Kata %s ditemukan di indeks %d ",current->kata,i+1);getchar();
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
            printf("\nKata Tidak Ditemukan\n");  
            getchar();
        }  
    }
}

int edit(char kata[],int check)
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
            if(strcmp(current->kata,kata)==0)  
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

void popAll(){
	while(head!=NULL){
		popTail();
	}
}

void view()
{
	current = head;
	
	if(current == NULL)
	{
		printf("No Data\n");
	}
	else
	{
		while(current != NULL)
		{
			printf("%s ",current->kata);
			current = current->next;		
		}
	}
}

int main()
{
	char pilihan;
	int nilai;
	char kata[100];
	char kataLama[100];
	
	do{
		system("cls");
		printf("Simple Word Processor\n\n");
		view();printf("\n\n");
		printf("a. Type a word at the end of the sentence\n");
		printf("b. Insert a word in the middle of the sentence\n");
		printf("c. Undo typing\n");
		printf("d. Search for a word\n");
		printf("e. Edit a specific word\n");
		printf("f. Exit program\n");
		printf("Masukkan Pilihan: ");
		scanf("%c",&pilihan);fflush(stdin);
		
		switch(pilihan)
		{
			case 'a':
				printf("Masukkan kata : ");
				scanf("%[^\n]",kata);fflush(stdin);
				pushTail(kata);
			break;
			case 'b':
			    current = head;
			    if(current==NULL)
			    {
			         printf("\nEmpty Data\n");  
                    getchar();
                }
                else
                {
                    printf("Disisipkan setelah kata apa? : ");
                    scanf("%[^\n]",kataLama);fflush(stdin);
                    int check = edit(kataLama,0);
                    if(check==0)
                    {
                        printf("Masukkan Kata yang ingin disisipkan : ");
                        scanf("%s",kata);fflush(stdin);
                        pushmid(kataLama,kata);
                    }
                    else
                    {
                        printf("Kata yang ingin disisipkan tidak ditemukan\n");
                        getchar();
                    }
                }
			break;
			case 'c':
				popTail();
			break;
			case 'd':
			    printf("Masukkan Kata yang ingin Anda Cari : ");   
                scanf("%s",&kata);  fflush(stdin);
			    search(kata);   
			    break;
			case 'e':
			    current = head;
			    if(current==NULL)
			    {
			         printf("\nEmpty Data\n");  
                    getchar();
                }
                else
                {
                    printf("Masukkan Kata yang ingin Anda Ganti : ");   
                    scanf("%s",&kataLama);  fflush(stdin);
                    int check = edit(kataLama,0);
                    if(check==0)
                    {
                        printf("Ganti dengan kata apa? : ");   
                        scanf("%s",&kata);  fflush(stdin);
                        strcpy(current->kata,kata);
                    }
                    else
                    {
                        printf("Kata yang ingin diganti tidak ditemukan\n");
                        getchar();
                    }
                }
			    break;
			    case 'f':
			        popAll();
			        break;
		}
	}while(pilihan !='f');
}
