#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure for storing person details
typedef struct {
    int id;
    char name[50];
    int age;
} Person;

#define MAX_RECORDS 100 // Define the maximum number of records in the database

Person database[MAX_RECORDS]; // Array to store person records
int record_count = 0; // Counter for the number of records in the database

// Function to add a new person to the database
void addPerson(Person p) {
    if (record_count < MAX_RECORDS) {
        database[record_count++] = p; // Add new person if database is not full
    } else {
        printf("Database is full!\n"); // Notify when the database is full
    }
}

// Function to update a person's information in the database
void updatePerson(int id, Person new_data) {
    for (int i = 0; i < record_count; i++) {
        if (database[i].id == id) {
            database[i] = new_data; // Update the person's data if ID matches
            return;
        }
    }
    printf("Person with ID %d not found.\n", id); // Notify if ID not found
}

// Function to delete a person from the database
void deletePerson(int id) {
    int i;
    for (i = 0; i < record_count; i++) {
        if (database[i].id == id) {
            break; // Find the person with the matching ID
        }
    }
    if (i < record_count) {
        for (int j = i; j < record_count - 1; j++) {
            database[j] = database[j + 1]; // Shift records to delete the person
        }
        record_count--; // Decrease the record count
    } else {
        printf("Person with ID %d not found.\n", id); // Notify if ID not found
    }
}

// Function to save the current state of the database to a file
void saveToFile() {
    FILE *file = fopen("database.dat", "wb"); // Open file in write-binary mode
    if (file == NULL) {
        printf("Error opening file for writing.\n"); // Error handling for file opening
        return;
    }
    fwrite(&record_count, sizeof(int), 1, file); // Write the number of records
    fwrite(database, sizeof(Person), record_count, file); // Write the database records
    fclose(file); // Close the file
}

// Function to load the database from a file
void loadFromFile() {
    FILE *file = fopen("database.dat", "rb"); // Open file in read-binary mode
    if (file == NULL) {
        printf("Error opening file for reading. Starting with an empty database.\n"); // Error handling for file opening
        record_count = 0;
        return;
    }
    fread(&record_count, sizeof(int), 1, file); // Read the number of records
    fread(database, sizeof(Person), record_count, file); // Read the database records
    fclose(file); // Close the file
}

#define ID_WIDTH 6 // Width for ID column in the output
#define NAME_WIDTH 30 // Width for Name column in the output
#define AGE_WIDTH 5 // Width for Age column in the output

// Function to print a person's information in a formatted way
void printPerson(Person p) {
    printf("%-*d%-*s%-*d\n", ID_WIDTH, p.id, NAME_WIDTH, p.name, AGE_WIDTH, p.age);
}

// Function to search and print persons by their name
void searchByName(char *name) {
    int found = 0;
    for (int i = 0; i < record_count; i++) {
        if (strcmp(database[i].name, name) == 0) {
            printPerson(database[i]); // Print person if name matches
            found = 1;
        }
    }
    if (!found) {
        printf("No person found with the name %s.\n", name); // Notify if no match found
    }
}

// Function to search and print persons by their ID
void searchByID(int id) {
    int found = 0;
    for (int i = 0; i < record_count; i++) {
        if (database[i].id == id) {
            printPerson(database[i]); // Print person if ID matches
            found = 1;
            break; // Stop search after finding the first match
        }
    }
    if (!found) {
        printf("No person found with the ID %d.\n", id); // Notify if no match found
    }
}

// Function to print the header of the person list
void printHeader() {
    printf("%-*s%-*s%-*s\n", ID_WIDTH, "ID", NAME_WIDTH, "Name", AGE_WIDTH, "Age");
    printf("%-*s%-*s%-*s\n", ID_WIDTH, "----", NAME_WIDTH, "----------------------------", AGE_WIDTH, "---");
}

// Function to list all persons in the database
void listAll() {
    printHeader();
    for (int i = 0; i < record_count; i++) {
        printPerson(database[i]); // Print each person's details
    }
}

// Main function to run the program
int main() {
    int choice, id;
    char searchName[50];
    Person p;

    loadFromFile(); // Load existing database from file

    while (1) {
        printf("\nSimple Database:\n");
        printf("1. Add Person\n");
        printf("2. List All Persons\n");
        printf("3. Update Person\n");
        printf("4. Delete Person\n");
        printf("5. Save and Exit\n");
        printf("6. Search by Name\n");
        printf("7. Search by ID\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID, Name, Age: ");
                scanf("%d %s %d", &p.id, p.name, &p.age);
                addPerson(p); // Add a new person to the database
                break;
            case 2:
                listAll(); // List all persons in the database
                break;
            case 3:
                printf("Enter ID to update: ");
                scanf("%d", &id);
                printf("Enter new Name, Age: ");
                scanf("%s %d", p.name, &p.age);
                p.id = id;
                updatePerson(id, p); // Update a person's details
                break;
            case 4:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deletePerson(id); // Delete a person from the database
                break;
            case 5:
                saveToFile(); // Save the database to a file and exit
                return 0;
            case 6:
                printf("Enter Name to search: ");
                scanf("%s", searchName);
                searchByName(searchName); // Search for a person by name
                break;
            case 7:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                searchByID(id); // Search for a person by ID
                break;
            default:
                printf("Invalid choice. Please try again.\n"); // Handle invalid choices
        }
    }
    return 0; // End of the program
}
