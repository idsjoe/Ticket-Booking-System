#include <stdio.h>
#include <string.h>
int count=0,max=10;
struct process
{
    char name[100];  // Character array to store the name of the process (up to 100 characters).
    int age;  // Integer to store the age of the process.
    int id;   // Integer to store the unique ID of the process.
    int priority;  // Integer to store the priority of the process.
    float arrival_time; // Floating-point number to store the arrival time of the process.
}p[10]; // An array 'p' of 10 'process' structures to hold information for 10 processes.

// Define a local struct named 'Details' to store passenger information.
int getdetails(int pass,float at)
{
    struct Details
    {
        char name[100];  // Character array to store the name of the passenger (up to 100 characters).
        int age;
        int id;
        int priority;
        float arrival_time;
    }p1[pass];  // Create an array 'p1' of 'Details' structures with a size of 'pass'.

    for(int i=0;i<pass;i++)
    {
        printf("Enter Passenger Details : \n");
        printf("Enter Name : ");
        scanf("%s",p1[i].name);
        printf("Enter Age : ");
        scanf("%d",&p1[i].age);
        printf("Enter 1 senior citizen , 2 student , 3 for defense : ");
        int choice;
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:p1[i].priority=1;break;
            case 2:p1[i].priority=2;break;
            case 3:p1[i].priority=3;break;
            default:p1[i].priority=4;break;
        }
        p1[i].arrival_time=at;
        p1[i].id=i+1;
    }
    if((count+pass)<=max)
    {
        for(int i=count;i<count+pass;i++)
        {
            // Copy the 'name' field from 'p1[i]' to 'p[i]' using strcpy, as we can't assign character arrays directly.
            // p[i].name=p1[i].name;
            strcpy(p[i].name,p1[i].name);
            // Copy other fields from 'p1[i]' to 'p[i]'.
            p[i].age=p1[i].age;
            p[i].arrival_time=p1[i].arrival_time;
            p[i].priority=p1[i].priority;
            p[i].id=p1[i].id;
        }
        count+=pass;  // Updating the 'count' variable to account for the newly added passengers.
        return 1;
    }
    else
    {
        // This block of code executes when there is not enough space in the 'p' array to add 'pass' passengers.
        for(int i=0;i<pass;i++)
        {
            if(count<max)
            {
                // This loop processes each passenger from 'p1' when there is space in 'p'.
            for(int j=i;j<pass;j++)
            {
                if(p1[i].priority==1)
                {
                     // If the priority of the passenger is 1 (senior citizen), copy their details to 'p'.
                    //p[count].name=p1[i].name;
                    strcpy(p[count].name,p1[i].name);
                    p[count].age=p1[i].age;
                    p[count].arrival_time=p1[i].arrival_time;
                    p[count].priority=p1[i].priority;
                    p[count].id=p1[i].id;
                    count++;  // Incrementing 'count' to keep track of the number of passengers in 'p'.
                    break; // Exit the loop since one passenger has been added.
                }
                else if(p1[i].priority>1 && p1[j].priority==1)
                {
                    // This condition checks if the priority of the current passenger in 'p1' is greater than 1
                   // and if the priority of the passenger at position 'j' in 'p1' is equal to 1.

                    //p[count].name=p1[j].name;
                    strcpy(p[count].name,p1[j].name);
                    p[count].age=p1[j].age;
                    p[count].arrival_time=p1[j].arrival_time;
                    p[count].priority=p1[j].priority;
                    p[count].id=p1[j].id;
                    count++;
                    break;
                }
                else if(p1[i].priority==2)
                {
                    // This condition checks if the priority of the current passenger in 'p1' is equal to 2.
                    //p[count].name=p1[i].name;
                    strcpy(p[count].name,p1[i].name);
                    p[count].age=p1[i].age;
                    p[count].arrival_time=p1[i].arrival_time;
                    p[count].priority=p1[i].priority;
                    p[count].id=p1[i].id;
                    count++;  // Incrementing 'count' to keep track of the number of passengers in 'p'.
                    break;    // Exit the loop since one passenger has been added.
                }
                else if(p1[i].priority>2 && p[j].priority==2)
                {
                    // This condition checks if the priority of the current passenger in 'p1' is greater than 2
                   // and if the priority of the passenger at position 'j' in 'p1' is equal to 2.
                    //p[count].name=p1[j].name;
                    strcpy(p[count].name,p1[j].name);
                    p[count].age=p1[j].age;
                    p[count].arrival_time=p1[j].arrival_time;
                    p[count].priority=p1[j].priority;
                    p[count].id=p1[j].id;
                    count++; // Incrementing 'count' to keep track of the number of passengers in 'p'.
                    break;   // Exit the loop since one passenger has been added.
                }
                else if(p[i].priority==3)
                {
                    // This condition checks if the priority of the current passenger in 'p1' is equal to 3.
                    //p[count].name=p1[i].name;
                    strcpy(p[count].name,p1[i].name);
                    p[count].age=p1[i].age;
                    p[count].arrival_time=p1[i].arrival_time;
                    p[count].priority=p1[i].priority;
                    p[count].id=p1[i].id;
                    count++;  // Incrementing 'count' to keep track of the number of passengers in 'p'.
                    break;    // Exit the loop since one passenger has been added.
                }
                else if(p[i].priority>3 && p[j].priority==3)
                {
                    // This condition checks if the priority of the current passenger in 'p1' is greater than 3
                   // and if the priority of the passenger at position 'j' in 'p1' is equal to 3.
                    //p[count].name=p1[j].name;
                    strcpy(p[count].name,p1[j].name);
                    p[count].age=p1[j].age;
                    p[count].arrival_time=p1[j].arrival_time;
                    p[count].priority=p1[j].priority;
                    p[count].id=p1[j].id;
                    count++;  // Increment 'count' to keep track of the number of passengers in 'p'.
                    break;     // Exit the loop since one passenger has been added.
                }
                else if(p[i].priority>3)
                {
                    // This condition checks if the priority of the current passenger in 'p1' is greater than 3.
                    //p[count].name=p1[i].name;
                    strcpy(p[count].name,p1[i].name);
                    p[count].age=p1[i].age;
                    p[count].arrival_time=p1[i].arrival_time;
                    p[count].priority=p1[i].priority;
                    p[count].id=p1[i].id;
                    count++;  // Increment 'count' to keep track of the number of passengers in 'p'.
                    break;     // Exit the loop since one passenger has been added.
                }
                else
                {
                     // This code block is executed if none of the previous conditions were met.(for general)
                    //p[count].name=p1[j].name;
                    strcpy(p[count].name,p1[j].name);
                    p[count].age=p1[j].age;
                    p[count].arrival_time=p1[j].arrival_time;
                    p[count].priority=p1[j].priority;
                    p[count].id=p1[j].id;
                    count++;
                    break;
                }
            }
            }
            else
            {
                printf("No more tickets available . Sorry for inconvenience\n");
            }
        }
        return -1;
    }
}
void display()
{
    int precision = 2;
    printf("Passenger List :\n");
    printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    for(int i=0;i<max;i++)
    {
        printf("Passenger %d details:\n",i+1);
        printf("Name : %s\n",p[i].name);
        printf("Age : %d\n",p[i].age);
        printf("Booking Time : %.*f\n",precision,p[i].arrival_time);
        if(p[i].priority==1)
        {
            printf("Category : Senior Citizen\n");
        }
        else if(p[i].priority==2)
        {
            printf("Category : Student\n");
        }
        else if(p[i].priority==3)
        {
            printf("Category : Defense\n");
        }
        else
        {
            printf("Category : General\n");
        }
        printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t\n");
    }
    printf("Thank You For Travelling With Us.\n");
    printf("------------------------------------------------------------------\n");
}

// Initialization
int main()
{
    int n=1,pass;
    float at;
     // Taking User Input:
    while(n!=0)
    {
        printf("Enter Arrival Time in float format (Ex:Ten Fifteen - 10.15) : ");
        scanf("%f",&at);  // Prompt the user to enter the arrival time and store it in 'at'.
    printf("Enter No of Passengers present : ");
        printf("Enter No of Passengers present : ");
        scanf("%d",&pass);  // Prompt the user to enter the number of passengers and store it in 'pass'.
        int i = getdetails(pass,at);  // Call the 'getdetails' function to process passenger details and store the return value in 'i'.

        if(i==-1)
            n=0;    // If 'getdetails' returns -1, set 'n' to 0 to exit the loop.
    }
    printf("Enter 1 to view passenger details : ");
    int get;  // Prompt the user to enter a choice to view passenger details.
    scanf("%d",&get);
    if(get==1)  // If the user's choice is 1, call the 'display' function to view passenger details.
        display();
    return 0; // Return 0 to indicate successful execution of the program.
}
