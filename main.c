#include <stdio.h>
#include <stdlib.h>

struct node{
int clinic_number;
char f_name[20];
char l_name[20];
char age[10];
char id[20];
char adrs[30];
struct node* next;
};

struct node* header=NULL;


void menu();
void new_patient();
void delet();
void check_id();
void display_all_patients();

int main()
{
    int num,h=0;


   while(1){
    char option[10];
    menu();
    scanf("%s",option);
    while(option[h]!='\0'){
    if ( isdigit ( option[h] ))h++;
   else{
        printf ( "wrong! you must enter a number from 1 to 4 :\n" );
   h=0;
   return main();
   }

}
    long x = strtol(option,NULL, 0);
    if(x==1)new_patient(&header);
    else if(x==2){
        printf("\nplease enter your clinic number to delete it : ");
        scanf("%d",&num);
        delet(&header,num);
    }
    else if(x==3)check_id(header);
    else if(x==4){display_all_patients(header);}
    else{
    printf("please enter a valid number\n\n");
}

}
}

menu(){
    printf("\nhello check our menu:- \n\n");
printf(" 1- new patient\n 2- delete your id \n 3- check your id \n 4- display all patients id alphabetically\n\n");
printf("please choose your option : \n");

}
new_patient(struct node** head){

struct node* original_header=*head;
struct node* new_node=(struct node*)malloc(sizeof(struct node));
int i=0,j=0,k=0,l=0;


printf("please enter your information\n\n");

printf("please enter your id (numbers only) : ");
scanf("%s",new_node->id);

while(((new_node->id)[k])!='\0'){
    if ( isdigit ( (new_node->id)[k] ) );
   else{
        printf ( "\nEntered characters is not numerical\nplease enter numbers only :\n" );
   k=-1;
   scanf("%s",new_node->id);
   }
   k++;
}

while(original_header!=NULL){
long y = strtol(original_header->id,NULL, 0);
long z = strtol(new_node->id,NULL, 0);
if(y==z){
    printf("\nthis id is already registered!\n\n");
    return;
}
  else original_header=original_header->next;
}

printf("enter your first name : ");
scanf("%s",new_node->f_name);
    while((new_node->f_name)[i]!='\0'){
    if ( isalpha ( (new_node->f_name)[i] ) );
   else{
        printf ( "\nyour first name must be alphabetically only :\n" );
   i=-1;
   scanf("%s",new_node->f_name);
   }
   i++;
}

printf("enter your last name : ");
scanf("%s",new_node->l_name);
    while((new_node->l_name)[j]!='\0'){
    if ( isalpha ( (new_node->l_name)[j] ) );
   else{
        printf ( "\nyour last name must be alphabetically only :\n" );
   j=-1;
   scanf("%s",new_node->l_name);
   }
   j++;
}

printf("please enter your age (numbers only) :");
scanf("%s",(new_node->age));
while(((new_node->age)[l])!='\0'){
    if ( isdigit ( (new_node->age)[l] ) );
   else{
        printf ( "\nEntered characters is not numerical\nplease enter numbers only :\n" );
   l=-1;
   scanf("%s",new_node->age);
   }
   l++;
}

printf("enter your address : ");
scanf("%s",new_node->adrs);

if(*head==NULL){new_node->clinic_number=1;}
else{
        new_node->clinic_number=((*head)->clinic_number)+1;
}

new_node->next=*head;
*head=new_node;
printf("\nyour id is registered with clinic number %d \n\n",new_node->clinic_number);
}

delet(struct node** head,int clinicNumber){
    if (clinicNumber>(*head)->clinic_number){
        printf("\nthis id is not registered\n\n");
    }
    else{
    struct node* temp;
      if(clinicNumber==(*head)->clinic_number){
        temp=*head;
        *head=(*head)->next;
        free(temp);
        printf("\nyour id is successfully deleted\n\n");
      }
      else if(clinicNumber==((*head)->clinic_number)-1){
        temp=(*head)->next;
        (*head)->next=temp->next;
        free(temp);
        printf("\nyour id is successfully deleted\n\n");

      }
      else {
            delet(&((*head)->next),clinicNumber);
    }
    }
}


void check_id(struct node* front){
    int id,test=0;

if(front==NULL){
    printf("\nthere is no patients in the list\n\n");
    }
    else{
            printf("\nplease enter your id to check if it is exist :");
            scanf("%d",&id);
    struct node* check=front;
while(check!=NULL){
        long x = strtol(check->id,NULL, 0);
  if(id==x){
printf("\nthis id is for patient %s %s \n the patient is %s years old\nand his address is %s\n\n",check->f_name,check->l_name,check->age,check->adrs);
test=1;
break;
}
  else{
    check=check->next;
}
    }
if(test==0)printf("\nthis id is not registered\n\n");
}
}



display_all_patients(struct node* top){
char test,test2;
if(top==NULL){
    printf("\nthere is no patient in the list\n\n");
}
else{
printf("the patients in alphabetically order are :\n\n");
for(test='a';test<='z';test++){
for(test2='a';test2<='z';test2++){
struct node* view=top;
while(view!=NULL){
    if((view->f_name[0])==test && (view->l_name[0])==test2){
        printf("- %s %s\n",view->f_name,view->l_name);
    }
    view=view->next;
}
}
}
}
printf("\n");
}
