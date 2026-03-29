# 🛡️ Secure Student Database Management (C)

A low-level, memory-efficient student record management system written in **C**. This project demonstrates core backend principles, including memory management, data encryption at rest, and database interoperability.

### 🚀 Key Features
- **Low-Level Memory Management:** Utilizes C `struct`s and pointers for efficient data handling.
- **Data Encryption at Rest:** Implements an XOR encryption algorithm to secure sensitive student records before saving them to the local disk.
- **SQL Interoperability:** Features an export module that dynamically generates a `.sql` file containing `INSERT` statements, allowing seamless migration to relational databases (Oracle SQL / PostgreSQL).

### 🛠️ Technologies & Concepts
- **Language:** C
- **Security:** XOR Encryption, Secure File I/O
- **Database:** SQL Query Generation

### ⚙️ How to Compile and Run
This project uses standard C libraries and can be compiled with GCC:

```bash
gcc main.c -o secure_db
./secure_db
