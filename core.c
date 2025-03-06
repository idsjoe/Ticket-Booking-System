#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

typedef struct {
    char name[100];
    int age;
    int id;
    int priority;
    float arrival_time;
} Process;

Process processes[MAX_PROCESSES];
int process_count = 0;

typedef struct {
    char name[100];
    int age;
    int id;
    int priority;
    float arrival_time;
} Passenger;

bool add_passengers(Passenger passengers[], int num_passengers, float arrival_time) {
    if (process_count + num_passengers > MAX_PROCESSES) {
        printf("Not enough space to add all passengers.\n");
        for (int i = 0; i < num_passengers; i++) {
            if (process_count < MAX_PROCESSES) {
                processes[process_count].age = passengers[i].age;
                processes[process_count].arrival_time = arrival_time;
                processes[process_count].id = passengers[i].id;
                processes[process_count].priority = passengers[i].priority;
                strcpy(processes[process_count].name, passengers[i].name);
                process_count++;
            } else {
                printf("No more tickets available. Sorry for inconvenience.\n");
                return false;
            }
        }
        return false;
    } else {
        for (int i = 0; i < num_passengers; i++) {
            processes[process_count].age = passengers[i].age;
            processes[process_count].arrival_time = arrival_time;
            processes[process_count].id = passengers[i].id;
            processes[process_count].priority = passengers[i].priority;
            strcpy(processes[process_count].name, passengers[i].name);
            process_count++;
        }
        return true;
    }
}

void get_passenger_details(Passenger passengers[], int num_passengers, float arrival_time) {
    for (int i = 0; i < num_passengers; i++) {
        printf("Enter Passenger Details %d:\n", i + 1);
        printf("Enter Name: ");
        scanf("%s", passengers[i].name);
        printf("Enter Age: ");
        scanf("%d", &passengers[i].age);
        printf("Enter 1 for senior citizen, 2 for student, 3 for defense: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                passengers[i].priority = 1;
                break;
            case 2:
                passengers[i].priority = 2;
                break;
            case 3:
                passengers[i].priority = 3;
                break;
            default:
                passengers[i].priority = 4;
                break;
        }
        passengers[i].arrival_time = arrival_time;
        passengers[i].id = i + 1;
    }
}

void display_passenger_list() {
    printf("Passenger List:\n");
    printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    for (int i = 0; i < process_count; i++) {
        printf("Passenger %d details:\n", i + 1);
        printf("Name: %s\n", processes[i].name);
        printf("Age: %d\n", processes[i].age);
        printf("Booking Time: %.2f\n", processes[i].arrival_time);
        switch (processes[i].priority) {
            case 1:
                printf("Category: Senior Citizen\n");
                break;
            case 2:
                printf("Category: Student\n");
                break;
            case 3:
                printf("Category: Defense\n");
                break;
            default:
                printf("Category: General\n");
                break;
        }
        printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t\n");
    }
    printf("Thank You For Travelling With Us.\n");
    printf("------------------------------------------------------------------\n");
}

int main() {
    int num_passengers;
    float arrival_time;
    bool continue_adding = true;

    while (continue_adding) {
        printf("Enter Arrival Time in float format (e.g., 10.15): ");
        scanf("%f", &arrival_time);
        printf("Enter Number of Passengers present: ");
        scanf("%d", &num_passengers);

        Passenger passengers[num_passengers];
        get_passenger_details(passengers, num_passengers, arrival_time);

        continue_adding = add_passengers(passengers, num_passengers, arrival_time);
    }

    printf("Enter 1 to view passenger details: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        display_passenger_list();
    }

    return 0;
}
