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
struct MetroStation* head1 = NULL;
struct MetroStation* head2 = NULL;
struct MetroStation* temp = NULL;
struct MetroStation* temp1 = NULL;

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
    struct MetroStation* station3 = createStation("Jnanabharthi",3);
    struct MetroStation* station4 = createStation("Attiguppe",4);
    struct MetroStation* station5 = createStation("Vijayanagar",5);
    struct MetroStation* station6 = createStation("Maestic",6);
    struct MetroStation* station7 = createStation("Trinity",7);
    struct MetroStation* station8 = createStation("Indranagar",8);
    struct MetroStation* station9 = createStation("Whitefield",9);

    head1 = station1;
    station1->next = station2;
    station2->prev = station1;
    station2->next = station3;
    station3->next = station2;
    station3->next = station4;
    station4->prev = station3;
    station4->next = station5;
    station5->prev = station4;
    station5->next = station6;
    station6->prev = station5;
    station6->next = station7;
    station7->prev = station6;
    station7->next = station8;
    station8->prev = station7;
    station8->next = station9;
    station9->prev = station8;
    station9->next = NULL;
}

// Function to create Green line
void CreateGreenLine() {
    struct MetroStation* gstation1 = createStation("Nagsandra",1);
    struct MetroStation* gstation2 = createStation("Goraguntepalya",2);
    struct MetroStation* gstation3 = createStation("Srirampura",3);
    struct MetroStation* gstation4 = createStation("Magestic",4);
    struct MetroStation* gstation5 = createStation("Lalbhag",5);
    struct MetroStation* gstation6 = createStation("Jaynagar",6);
    struct MetroStation* gstation7 = createStation("Bhanshankri",7);
    struct MetroStation* gstation8 = createStation("Konankunte Cross",8);
    struct MetroStation* gstation9 = createStation("Silk institute",9);

    head2 = gstation1;
    gstation1->prev = NULL;
    gstation1->next = gstation2;
    gstation2->prev = gstation1;
    gstation2->next = gstation3;
    gstation3->prev = gstation2;
    gstation3->next = gstation4;
    gstation4->prev = gstation3;
    gstation4->next = gstation5;
    gstation5->prev = gstation4;
    gstation5->next = gstation6;
    gstation6->prev = gstation5;
    gstation6->next = gstation7;
    gstation7->prev = gstation6;
    gstation7->next = gstation8;
    gstation8->prev = gstation7;
    gstation8->next = gstation9;
    gstation9->prev = gstation8;
    gstation9->next = NULL;
}

// Function to display the list of metro stations and their ticket prices
void displayStations(struct MetroStation* head) {
    temp = head;
    printf("\nList of Metro Stations:\n");
    while (temp != NULL) {
        printf("%s \n", temp->name);
        temp = temp->next;
    }
}

// Function to buy a metro ticket
void buyTicket( struct MetroStation* head) {
    char source[50], destination[50];
    float totalCost = 0.0f;

    printf("Enter source station: " );
    scanf("%s", source);
    printf("Enter destination station: ");
    scanf("%s", destination);
    

    temp = head;
    int count=0;
    // Find source and destination stations in the linked list
    while (temp != NULL) {
        if (strcmp(temp->name, source) == 0) {
            break;
        }
        temp = temp->next;
    }

    temp1 = head;
    while (temp1 != NULL) {
        if (strcmp(temp1->name, destination) == 0) {
            break;
        }
        temp1 = temp1->next;

    }
    
    if (temp->statno < temp1->statno){
        while (temp!=temp1){
            count++;
            temp=temp->next;
        }
    }
    else {
        while (temp!=temp1) {
            count++;
            temp=temp->prev;
        }
    }
 if(count==0){
        printf("\ninvalid stations\n");
        return ;
    }
    totalCost = 10*count;
    

    // Display ticket information
    printf("\nTicket Details:\n");
    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);
    printf("Total Cost: Rs.%.2f\n", totalCost);
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
        // Display menu
        printf("\nMetro Ticketing Platform Menu:\n");
        printf("Choose which Line :\n");
        printf("1. Green Line\n");
        printf("2. Purple Line\n");
        printf("3. Exit\n"); 
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: do{
        printf("1. Display Metro stations\n");
        printf("2. Buy Ticket\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);              
      switch(ch) {
             case 1:  displayStations(head2);
                             break;
             case 2: buyTicket(head2);
                           break;
             case 3: printf("Exiting the program. Thank you!\n");
                          break;
            default: printf("Invalid choice. Please try again.\n");
      } 
                         }while(ch != 3);break;
            case 2: do{
                         printf("1. Display Metro stations\n");
                         printf("2. Buy Ticket\n");
                         printf("3. Exit\n");
                         printf("Enter your choice: ");
                         scanf("%d", &ch);              
                         switch(ch) {
                            case 1:  displayStations(head1);
                                      break;
                            case 2: buyTicket(head1);
                                     break;
                            case 3: printf("Exiting the program. Thank you!\n");
                                     break;
                            default: printf("Invalid choice. Please try again.\n");
                         } 
                  }while(ch != 3);break;
            case 3:  printf("Exiting the program. Thank you!\n");
                     exit(0);

                             break;
            default:
                    printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 3);

    // Free allocated memory
    free1(head1);
    free1(head2);
    

    return 0;
}
