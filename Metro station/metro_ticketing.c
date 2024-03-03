#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Structure to represent a metro station
struct MetroStation {
    char name[50];
    struct MetroStation* next;
    int statdis;
};
struct MetroStation *head1 = NULL,*head2 = NULL,*temp =NULL,*temp1 = NULL,*mid1= NULL,*mid2=NULL,*tail1=NULL,*tail2=NULL;

struct MainNode{
    int dis;
    struct MetroStation *link1;
    struct MetroStation *link2;
};


// Function to create a new metro station
struct MetroStation* createStation(const char* name,int n) {
    struct MetroStation* newStation = (struct MetroStation*)malloc(sizeof(struct MetroStation));
    strcpy(newStation->name, name);
    newStation->next = NULL;
    newStation->statdis=n;
    return newStation;
}

// Function to create Purple line
void CreatePurpleLine() {
    struct MetroStation* station1 = createStation("Challaghatta",10);
    struct MetroStation* station2 = createStation("Kengeri",20);
    struct MetroStation* station3 = createStation("Attiguppe",30);
    struct MetroStation* station4 = createStation("Vijayanagar",40);
    struct MetroStation* station5 = createStation("Majestic",50);
    struct MetroStation* station6 = createStation("Trinity",60);
    struct MetroStation* station7 = createStation("Indranagar",70);
    struct MetroStation* station8 = createStation("Hoodi",80);
    struct MetroStation* station9 = createStation("Hopefarm",90);
    struct MetroStation* station10 = createStation("Whitefield",100);

    head1 = station1;
    station1->next = station2;
    station2->next = station3;
    station3->next = station4;
    station4->next = station5;
    mid1=station5;
    station5->next = station6;
    station6->next = station7;
    station7->next = station8;
    station8->next = station9;
    station9->next = station10;
    station10->next = NULL;
    tail1=station10;
}

// Function to create Green line
void CreateGreenLine() {
    struct MetroStation* gstation1 = createStation("Nagsandra",10);
    struct MetroStation* gstation2 = createStation("Goraguntepalya",20);
    struct MetroStation* gstation3 = createStation("Srirampura",30);
    struct MetroStation* gstation4 = createStation("Mantri",40);
    struct MetroStation* gstation5 = createStation("Majestic",50);
    struct MetroStation* gstation6 = createStation("Lalbhag",60);
    struct MetroStation* gstation7 = createStation("Jaynagar",70);
    struct MetroStation* gstation8 = createStation("Bhanshankri",80);
    struct MetroStation* gstation9 = createStation("KonankunteCross",90);
    struct MetroStation* gstation10 = createStation("SilkInstitute",100);

    head2 = gstation1;
    gstation1->next = gstation2;
    gstation2->next = gstation3;
    gstation3->next = gstation4;
    gstation4->next = gstation5;
    mid2=gstation5;
    gstation5->next = gstation6;
    gstation6->next = gstation7;
    gstation7->next = gstation8;
    gstation8->next = gstation9;
    gstation9->next = gstation10;
    gstation10->next=NULL;
    tail2=gstation10;
}


int countStations(struct MetroStation **head,struct MetroStation **tail) {
    int count=0;
    temp=*head;
    while(temp != *tail){
        count++;
        temp=temp->next;
    }
    return count;
}

void AddStation(char name[20],int dis,struct MetroStation** head,struct MetroStation** tail,int n) {
    struct MetroStation* newStation=createStation(name,dis);
    temp=*head;
    if (n==0) {
        newStation->next=*head;
        *head=newStation;
        printf("\nnew station: %s is added at %dth position.",name,n);
    }
    else if (n==countStations(head,tail)) {
        (*tail)->next=newStation;
        *tail=newStation;
        printf("\nnew station: %s is added at %dth position.",name,n);
    }
    else if (n<countStations(head,tail) && n>0 ) {
        temp=*head;
        int pos =1;
        while (pos<n-1){
            pos++;
            temp=temp->next;
        }
        temp1=temp->next;
        newStation->next=temp1;
        temp->next=newStation;
        printf("\nnew station: %s is added at %dth position.",name,n);
    }
    return;
}

void newStationDetails(struct MetroStation** head,struct MetroStation** tail) {
    int pos;
    int dis ,n;
    char name[30];
    printf("enter the new station name: ");
    scanf("%s",name);
    printf("enter the distance of station : ");
    scanf("%d",&dis);
    printf("\nInsert station at the position: ");
    printf("\n1.At First \n2.In Middle \n3.At end \n4.Exit");
    printf("\nEnter your choice : "); 
    scanf("%d",&pos);
    switch (pos) {
        case 1: AddStation(name,dis,head,tail,0);
                break;
        case 2: printf("\nenter the index: ");
                scanf("%d",&n);
                AddStation(name,dis,head,tail,n);
                break;
        case 3: AddStation(name,dis,head,tail,countStations(head,tail));
                break;
        default : printf("Enter valid input");
                  break;
    }
    return;
}



void displayMetro(){
    printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------");
    printf("\n|\t\t\t\t\t\t\t\t(PURPLE LINE)\t\t\t\t\t\t\t\t\t\t|");
    printf("\n|\t\t\t\t\t\t\t\t  |\t\t\t\t\t\t\t\t\t\t\t|");
    for(temp=head1;temp!=mid1;temp=temp->next){
    printf("\n|\t\t\t\t\t\t\t\t  %s\t\t\t\t\t\t\t\t\t\t|",temp->name);
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
    printf("\n|\t\t\t\t\t\t\t\t  %s\t\t\t\t\t\t\t\t\t\t|",temp->name);
    printf("\n|\t\t\t\t\t\t\t\t  |\t\t\t\t\t\t\t\t\t\t\t|");
   }
   printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------");
   printf("\n");
   printf("\n");
   
}


int CalculatePrice(char source[],char destination[]){
    int ps1=0,pd2=0,gs1=0,gd2=0,a=0,b=0;

    //finding source station
    //check purple line
    temp=head1;
    while (temp != NULL) {
        if (strcmp(temp->name,source) == 0) {
            ps1=temp->statdis;
            break; 
        }
        temp = temp->next;
    }

    //check green line
    temp1=head2;
    while (temp1 != NULL) {
        if (strcmp(temp1->name,source) == 0) {
            gs1=temp1->statdis;
            break; 
        }
        temp1 = temp1->next;
    }

    //finding destination station
    //check purple line
    temp=head1;
    while (temp != NULL) {
        if (strcmp(temp->name,destination) == 0) {
            pd2=temp->statdis;
            break; 
        }
        temp = temp->next;
    }

    //check greenline
    temp1=head2;
    while (temp1 != NULL) {
        if (strcmp(temp1->name,destination) == 0) {
            gd2=temp1->statdis;
            break; 
        }
        temp1 = temp1->next;
    }

    //calucalte price
    int x=mid1->statdis;
    int y=mid2->statdis;

    //if stations on either side of majestic - purple
    if (ps1 !=0 && pd2 !=0 && ((ps1<x && pd2<x) || (ps1>x && pd2>x) || (ps1>x && pd2<x) || (ps1<x && pd2>x))){
        a=abs(pd2-ps1);
        return a;
    }
    //if stations on either side of majestic - green
    else if (gs1 !=0 && gd2 !=0 && ((gs1<y && gd2<y) || (gs1>y && gd2>y) || (gs1>y && gd2<y) || (gs1<y && gd2>y))){
        b=abs(gd2-gs1);
        return b;
    }
    //if stations on both lines 
    else if (ps1 !=0 && gd2 !=0){
        a=abs(x-ps1);
        b=abs(y-gd2);
        return a+b;
    }
    else if (gs1 !=0 && pd2 !=0){
        a=abs(x-pd2);
        b=abs(y-gs1);
        return a+b;
    }
   return 0;
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

    int count = CalculatePrice(source,destination);
    totalCost=0.8*count;

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
    int choice,ch,c;
    char p[20];

    struct MainNode* mnode = (struct MainNode*)malloc(sizeof(struct MainNode));
    mnode->dis=0;
    mnode->link1=head1;
    mnode->link2=head2;
    CreatePurpleLine();
    CreateGreenLine();
    
    printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n~~~~~~ Metro Ticketing Platform Menu ~~~~~~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("1. Admin\n");
    printf("2. User\n");
    printf("3. Exit\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Enter your choice: ");
    scanf("%d", &c);

    //if the person is an admin
    if (c==1){
        printf("enter password:");
        scanf("%s",p);
        if(strcmp(p,"sashurocks")==0){

        do {
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            printf("\n~~~~~~ Metro Ticketing Platform Menu ~~~~~~\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("1. Display Metro stations\n");
            printf("2. Buy Ticket\n");
            printf("3. Add Stations\n");
            printf("4. Exit\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Enter your choice: ");
            scanf("%d", &choice); 
            switch (choice) {
                case 1: printf("\n\n");
                        printf("\t\t\t\t\t\t\t\tBANGLORE METRO STATIONS :\n");
                        displayMetro();
                        printf("\n\n");
                        break;

                case 2: buyTicket();
                        break;

                case 3: do{
                            printf("\n~~~Adding Stations~~~");
                            printf("\n1.Purple line");
                            printf("\n2.Green line"); 
                            printf("\n3.Back");
                            printf("\n~~~~~~~~~~~~~~~~~~~~~~");
                            printf("\nEnter choice: ");
                            scanf("%d",&ch);

                            switch(ch){
                                    case 1: newStationDetails(&head1,&tail1);
                                            break;
                                    case 2: newStationDetails(&head2,&tail2);
                                            break;
                                    }
                            }while(ch!=3);

                        }       

           }while(choice != 4);
    }else {
        printf("login failed");
        }
    }

    //if the person is user 
    else if (c==2)
    {
        do {
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            printf("\n~~~~~~ Metro Ticketing Platform Menu ~~~~~~\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("1. Display Metro stations\n");
            printf("2. Buy Ticket\n");
            printf("3. Exit\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Enter your choice: ");
            scanf("%d", &choice); 
            switch (choice) {
                            case 1: printf("\n\n");
                                    printf("\t\t\t\t\t\t\t\tBANGLORE METRO STATIONS :\n");
                                    displayMetro();
                                    printf("\n\n");
                                    break;

                            case 2: buyTicket();
                                    break;
                        }


            }while(choice != 3);
    }
    


    // Free allocated memory
    free1(head1);
    free1(head2);
    
    return 0;
}
