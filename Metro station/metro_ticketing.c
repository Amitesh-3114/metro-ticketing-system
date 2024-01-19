#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a metro station
struct MetroStation {
    char name[50];
    float ticketPrice;
    struct MetroStation* next;
};

// Function to create a new metro station
struct MetroStation* createStation(const char* name, float ticketPrice) {
    struct MetroStation* newStation = (struct MetroStation*)malloc(sizeof(struct MetroStation));
    strcpy(newStation->name, name);
    newStation->ticketPrice = ticketPrice;
    newStation->next = NULL;
    return newStation;
}

// Function to display the list of metro stations and their ticket prices
void displayStations(struct MetroStation* head) {
    printf("\nList of Metro Stations:\n");
    while (head != NULL) {
        printf("%s - $%.2f\n", head->name, head->ticketPrice);
        head = head->next;
    }
}

// Function to buy a metro ticket
void buyTicket(struct MetroStation* head) {
    char source[50], destination[50];
    float totalCost = 0.0;

    printf("\nEnter source station: ");
    scanf("%s", source);
    printf("Enter destination station: ");
    scanf("%s", destination);

    struct MetroStation* current = head;

    // Find source and destination stations in the linked list
    while (current != NULL) {
        if (strcmp(current->name, source) == 0 || strcmp(current->name, destination) == 0) {
            totalCost += current->ticketPrice;
        }
        current = current->next;
    }

    // Display ticket information
    printf("\nTicket Details:\n");
    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);
    printf("Total Cost: $%.2f\n", totalCost);
}

int main() {
    // Creating metro stations
    struct MetroStation* station1 = createStation("Station A", 2.50);
    struct MetroStation* station2 = createStation("Station B", 3.00);
    struct MetroStation* station3 = createStation("Station C", 2.75);

    // Building the linked list of metro stations
    station1->next = station2;
    station2->next = station3;

    int choice;

    do {
        // Display menu
        printf("\nMetro Ticketing Platform Menu:\n");
        printf("1. Display Metro Stations\n");
        printf("2. Buy Ticket\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayStations(station1);
                break;
            case 2:
                buyTicket(station1);
                break;
            case 3:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 3);

    // Free allocated memory
    free(station1);
    free(station2);
    free(station3);

    return 0;
}
