#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define XOR_KEY 'X' // Simple encryption key

typedef struct {
    int id;
    char name[50];
    float grade;
} Student;

Student db[MAX_STUDENTS];
int student_count = 0;

// Feature 1: Add Student
void addStudent(int id, const char* name, float grade) {
    if (student_count < MAX_STUDENTS) {
        db[student_count].id = id;
        strncpy(db[student_count].name, name, 49);
        db[student_count].grade = grade;
        student_count++;
        printf("[+] Student %s added successfully.\n", name);
    } else {
        printf("[-] Database is full!\n");
    }
}

// Feature 2: Secure Data at Rest (XOR Encryption)
void saveEncryptedData() {
    FILE *file = fopen("secure_data.dat", "wb");
    if (!file) {
        printf("[-] Error opening file.\n");
        return;
    }
    
    for (int i = 0; i < student_count; i++) {
        Student encrypted = db[i];
        // Encrypt the name
        for (int j = 0; j < strlen(encrypted.name); j++) {
            encrypted.name[j] ^= XOR_KEY;
        }
        fwrite(&encrypted, sizeof(Student), 1, file);
    }
    fclose(file);
    printf("[🔐] Data saved and encrypted successfully.\n");
}

// Feature 3: Interoperability (Export to SQL)
void exportToSQL() {
    FILE *file = fopen("export.sql", "w");
    if (!file) {
        printf("[-] Error creating SQL file.\n");
        return;
    }
    
    fprintf(file, "-- Auto-generated SQL Export\n");
    fprintf(file, "CREATE TABLE IF NOT EXISTS students (id INT PRIMARY KEY, name VARCHAR(50), grade FLOAT);\n\n");
    
    for (int i = 0; i < student_count; i++) {
        fprintf(file, "INSERT INTO students (id, name, grade) VALUES (%d, '%s', %.2f);\n", 
                db[i].id, db[i].name, db[i].grade);
    }
    fclose(file);
    printf("[💾] SQL Export generated successfully (export.sql).\n");
}

int main() {
    printf("--- Secure Student DB Init ---\n");
    
    // Simulating user input
    addStudent(101, "Dogukan Agca", 95.5);
    addStudent(102, "John Doe", 88.0);
    
    saveEncryptedData();
    exportToSQL();
    
    printf("--- Operation Completed ---\n");
    return 0;
}
