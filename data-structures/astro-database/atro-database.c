#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define FILE_NAME "observation_log.dat"
#define MAX_NAME_LEN 49
#define MAX_COORD_LEN 29
#define MAX_NOTES_LEN 199

// Structure to represent an astronomical observation
typedef struct {
    int id;                             // Unique identifier for the observation
    char name[MAX_NAME_LEN + 1];        // Name of the celestial object
    char coordinates[MAX_COORD_LEN + 1];// Coordinates of the celestial object
    char notes[MAX_NOTES_LEN + 1];      // Additional notes about the observation
} CelestialObject;

// Function Prototypes
void writeObject(FILE *file, CelestialObject object);
CelestialObject readObject(FILE *file, int id);
void updateObject(FILE *file, int id, CelestialObject newObject);
void printMenu();
FILE* openFile(const char *fileName, const char *mode);
void removeNewline(char *str);
void handleInputError();

int main() {
    FILE *file = openFile(FILE_NAME, "r+b");

    int choice;
    char inputBuffer[256]; // Buffer for storing user input
    while (1) {
        printMenu();
        fgets(inputBuffer, sizeof(inputBuffer), stdin);
        if (sscanf(inputBuffer, "%d", &choice) != 1) {
            handleInputError();
            continue;
        }

        // Handle user choices
        if (choice == 4) {
            fclose(file);
            printf("Database saved and program exited.\n");
            break;
        } else if (choice == 5) {
            fclose(file);
            file = openFile(FILE_NAME, "r+b");
        } else if (choice >= 1 && choice <= 3) {
            CelestialObject obj, newObj;
            printf("Enter ID: ");
            fgets(inputBuffer, sizeof(inputBuffer), stdin);
            if (sscanf(inputBuffer, "%d", &obj.id) != 1) {
                handleInputError();
                continue;
            }

            if (choice == 1) {
                // Add a new observation
                printf("Enter Name, Coordinates (RA:HH:MM:SS, Dec:DD:MM:SS), Notes:\n");
                fgets(obj.name, MAX_NAME_LEN, stdin);
                removeNewline(obj.name);
                fgets(obj.coordinates, MAX_COORD_LEN, stdin);
                removeNewline(obj.coordinates);
                fgets(obj.notes, MAX_NOTES_LEN, stdin);
                removeNewline(obj.notes);
                writeObject(file, obj);
            } else if (choice == 2) {
                // View an existing observation
                obj = readObject(file, obj.id);
                if (obj.id != 0) {
                    printf("Observation found: ID=%d, Name=%s, Coordinates=%s, Notes=%s\n", obj.id, obj.name, obj.coordinates, obj.notes);
                } else {
                    printf("Observation not found.\n");
                }
            } else if (choice == 3) {
                // Update an existing observation
                printf("Enter new Name, Coordinates (RA:HH:MM:SS, Dec:DD:MM:SS), Notes:\n");
                fgets(newObj.name, MAX_NAME_LEN, stdin);
                removeNewline(newObj.name);
                fgets(newObj.coordinates, MAX_COORD_LEN, stdin);
                removeNewline(newObj.coordinates);
                fgets(newObj.notes, MAX_NOTES_LEN, stdin);
                removeNewline(newObj.notes);
                newObj.id = obj.id;
                updateObject(file, obj.id, newObj);
            }
        } else {
            handleInputError();
        }
    }

    return 0;
}

// Writes a CelestialObject to the end of the file
void writeObject(FILE *file, CelestialObject object) {
    fseek(file, 0, SEEK_END);
    if (fwrite(&object, sizeof(CelestialObject), 1, file) != 1) {
        perror("Error writing object to file");
        exit(EXIT_FAILURE);
    }
}

// Reads a CelestialObject from the file based on its ID
CelestialObject readObject(FILE *file, int id) {
    CelestialObject object;
    fseek(file, 0, SEEK_SET);
    while (fread(&object, sizeof(CelestialObject), 1, file) == 1) {
        if (object.id == id) {
            return object;
        }
    }
    if (ferror(file)) {
        perror("Error reading from file");
        exit(EXIT_FAILURE);
    }
    return (CelestialObject){0, "", "", ""};
}

// Updates a CelestialObject in the file based on its ID
void updateObject(FILE *file, int id, CelestialObject newObject) {
    CelestialObject object;
    fseek(file, 0, SEEK_SET);
    long pos;
    while ((pos = ftell(file)) >= 0 && fread(&object, sizeof(CelestialObject), 1, file) == 1) {
        if (object.id == id) {
            fseek(file, pos, SEEK_SET);
            if (fwrite(&newObject, sizeof(CelestialObject), 1, file) != 1) {
                perror("Error updating object in file");
                exit(EXIT_FAILURE);
            }
            break;
        }
    }
    if (ferror(file)) {
        perror("Error updating file");
        exit(EXIT_FAILURE);
    }
}

// Displays the main menu to the user
void printMenu() {
    printf("\nAstrophysics Observation Log\n");
    printf("1. Add Observation\n");
    printf("2. View Observation\n");
    printf("3. Update Observation\n");
    printf("4. Save and Exit\n");
    printf("5. Load Database\n");
    printf("Enter your choice: ");
}

// Opens a file; creates it if it doesn't exist
FILE* openFile(const char *fileName, const char *mode) {
    FILE *file = fopen(fileName, mode);
    if (file == NULL) {
        file = fopen(fileName, "w+b");
        if (file == NULL) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
    }
    return file;
}

// Removes the newline character from the end of a string, if present
void removeNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Handles invalid input by clearing the stdin buffer and printing an error message
void handleInputError() {
    // Clear stdin buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    printf("Invalid input. Please try again.\n");
}
