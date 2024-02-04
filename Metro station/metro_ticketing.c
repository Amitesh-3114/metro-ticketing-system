#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a metro station
struct MetroStation {
    char name[50];
    struct MetroStation* prev;
    struct MetroStation* next;
    int statno;
};
struct MetroStation *head1 = NULL,*head2 = NULL,*temp = NULL,*temp1 = NULL,*mid1=NULL,*mid2=NULL;

// Function to create a new metro station
struct MetroStation* createStation(const char* name,int n) {
    struct MetroStation* newStation = (struct MetroStation*)malloc(sizeof(struct MetroStation));
    strcpy(newStation->name, name);
    newStation->prev = NULL;
    newStation->next = NULL;
    newStation->statno=n;
    return newStation;
}

// Function to create Purple line
void CreatePurpleLine() {
    struct MetroStation* station1 = createStation("Challaghatta",1);
    struct MetroStation* station2 = createStation("Kengeri",2);
    struct MetroStation* station3 = createStation("Attiguppe",3);
    struct MetroStation* station4 = createStation("Vijayanagar",4);
    struct MetroStation* station5 = createStation("Majestic",5);
    struct MetroStation* station6 = createStation("Trinity",6);
    struct MetroStation* station7 = createStation("Indranagar",7);
    struct MetroStation* station8 = createStation("Hoodi",8);
    struct MetroStation* station9 = createStation("Hopefarm",9);
    struct MetroStation* station10 = createStation("Whitefield",10);

    head1 = station1;
    station1->next = station2;
    station2->prev = station1;
    station2->next = station3;
    station3->prev = station2;
    station3->next = station4;
    station4->prev = station3;
    station4->next = station5;
    mid1=station5;
    station5->prev = station4;
    station5->next = station6;
    station6->prev = station5;
    station6->next = station7;
    station7->prev = station6;
    station7->next = station8;
    station8->prev = station7;
    station8->next = station9;
    station9->prev = station8;
    station9->next = station10;
    station10->prev = station9;
    station10->next = NULL;
}

// Function to create Green line
void CreateGreenLine() {
    struct MetroStation* gstation1 = createStation("Nagsandra",1);
    struct MetroStation* gstation2 = createStation("Goraguntepalya",2);
    struct MetroStation* gstation3 = createStation("Srirampura",3);
    struct MetroStation* gstation4 = createStation("Mantri",4);
    struct MetroStation* gstation5 = createStation("Majestic",5);
    struct MetroStation* gstation6 = createStation("Lalbhag",6);
    struct MetroStation* gstation7 = createStation("Jaynagar",7);
    struct MetroStation* gstation8 = createStation("Bhanshankri",8);
    struct MetroStation* gstation9 = createStation("Konankunte Cross",9);
    struct MetroStation* gstation10 = createStation("Silk institute",10);

    head2 = gstation1;
    gstation1->prev = NULL;
    gstation1->next = gstation2;
    gstation2->prev = gstation1;
    gstation2->next = gstation3;
    gstation3->prev = gstation2;
    gstation3->next = gstation4;
    gstation4->prev = gstation3;
    gstation4->next = gstation5;
    mid2=gstation5;
    gstation5->prev = gstation4;
    gstation5->next = gstation6;
    gstation6->prev = gstation5;
    gstation6->next = gstation7;
    gstation7->prev = gstation6;
    gstation7->next = gstation8;
    gstation8->prev = gstation7;
    gstation8->next = gstation9;
    gstation9->prev = gstation8;
    gstation9->next = gstation10;
    gstation10->prev=gstation9;
    gstation10->next=NULL;
}


void displayMetro(){
    printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------");
     printf("\n|\t\t\t\t\t\t\t\t(PURPLE LINE)\t\t\t\t\t\t\t\t\t\t\t|");
    printf("\n|\t\t\t\t\t\t\t\t  |\t\t\t\t\t\t\t\t\t\t\t|");
    for(temp=head1;temp<mid1;temp=temp->next){
    printf("\n|\t\t\t\t\t\t\t\t  %s\t\t\t\t\t\t\t\t\t\t\t|",temp->name);
    printf("\n|\t\t\t\t\t\t\t\t  |\t\t\t\t\t\t\t\t\t\t\t|");
   }
   printf("\n");
   printf("|(GREEN LINE)-");
   for (temp=head2;temp!=NULL;temp=temp->next){
       printf("%s---",temp->name);
   }
   printf("|");
   printf("\n|\t\t\t\t\t\t\t\t  |\t\t\t\t\t\t\t\t\t\t\t|");
    for(temp=mid1->next;temp!=NULL;temp=temp->next){
    printf("\n|\t\t\t\t\t\t\t\t  %s\t\t\t\t\t\t\t\t\t\t\t|",temp->name);
    printf("\n|\t\t\t\t\t\t\t\t  |\t\t\t\t\t\t\t\t\t\t\t|");
   }
   printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------");
   printf("\n");
   printf("\n");
   
}


int DisFmid(char stat[]) {
    int a=0,b=0;
    temp=head1;
    while (temp != NULL) {
        if (strcmp(temp->name, stat) == 0) {
            a=abs(temp->statno-mid1->statno);
            return a; 
        }
        temp = temp->next;
    }

    temp1=head2;
    while (temp1 != NULL) {
        if (strcmp(temp1->name, stat) == 0) {
            b=abs(temp1->statno-mid2->statno);
            return b;
        }
        temp1 = temp1->next;
    }


}

void buyTicket() {
    char source[50], destination[50];
    float totalCost = 0.0f;

    printf("\n\nEnter source station: " );
    scanf("%s", source);
    printf("Enter destination station: ");
    scanf("%s", destination);

    if(strcmp(source,destination)==0){
        printf("Invalid inputs");
        return;
    }

    int x=DisFmid(source);
    printf("%d",x);
    int y=DisFmid(destination);
    printf("%d",y);
    int count=x+y;
    
    totalCost=10*count;

    // Display ticket information
    printf("\n\n");
    printf("**********************************************");
    printf("\n\t\tTicket Details:\n");
    printf("**********************************************");
    printf("\n\tSource: %s\n", source);
    printf("\tDestination: %s\n", destination);
    printf("\tTotal Cost: Rs.%.2f\n", totalCost);
    printf("**********************************************");
    printf("\n**********************************************");
    printf("\n\n");
}

void free1 (struct MetroStation* head) {
    temp=head;
    temp1=head;
    while(temp->next != NULL){
      temp=temp1->next;
      free(temp1);
      temp1=temp->next;
    }
}

int main() {
    int choice,ch;

    CreatePurpleLine();
    CreateGreenLine();
    
    do {
         printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
         printf("\n~~~~~~ Metro Ticketing Platform Menu ~~~~~~\n");
         printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
         printf("1. Display Metro stations\n");
         printf("2. Buy Ticket\n");
         printf("3. Exit\n");
         printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
         printf("Enter your choice: ");
         scanf("%d", &choice); 
        switch(choice) {
            case 1: printf("\n\n");
                    printf("\t\t\t\t\t\t\t\tBANGLORE METRO STATIONS :\n");
                    displayMetro();
                    printf("\n\n");
                    break;

            case 2: buyTicket();

        }

    }while(choice != 3);
    // Free allocated memory
    free1(head1);
    free1(head2);
    

    return 0;
}
