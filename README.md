# Student Management

A simple console-based Student Management System written in C. This program allows university administrators, professors, and students to manage courses, registrations, and profiles through a text-based menu interface!!!

Under the hood, the system uses **linked lists** as the core data structure to store dynamic records for students, professors, and courses. Each record type (`stdNode`, `profNode`, `courseNode`) is defined in `structure.h` and managed via custom allocation helpers in `creatNodes.h`. CRUD operations (Create, Read, Update, Delete) on these lists are implemented with pointer manipulations, including algorithms for:

* **Traversal**: Linear scanning of lists to locate records by ID or code.
* **Insertion/Deletion**: Inserting or deleting nodes by updating `next` pointers to maintain the integrity of singly linked lists, allowing dynamic resizing and efficient memory usage without preallocated limits.
* **File I/O Parsing**: Reading and writing text files in `readFile()` and `CrsWriteFile()` using `fscanf`/`fprintf` to serialize and rebuild lists on startup and exit.

The codebase is modularized into headers (`.h`) for data definitions and functions, and source files (`.c`) for implementations. Error checking and input validation guard against invalid IDs or duplicate entries, ensuring data integrity.

## Features

* **User Roles**:

  * **Student**: Login, view and enroll/drop courses, list taken and available courses.
  * **Professor**: Login, view assigned courses, manage course offerings.
  * **Admin**: Manage student and professor records, add/edit/delete courses, view all records.
* **Persistent Storage**: Reads initial course list from file and saves updates on exit.
* **Linked List Data Structures**: Uses linked lists for students, professors, and courses.
* **Modular Code Organization**: Separated into headers and source files:

  * `main.c` – Entry point and menu logic
  * `structure.h` – Data type definitions
  * `creatNodes.h` – Node allocation helpers
  * `functions.h` & `functions.c` – Core operations (add, edit, remove, login, file I/O)

## Prerequisites

* GCC or any C compiler supporting C99
* A terminal/console (Windows Command Prompt or Unix shell)
* `make` (optional, if you prefer a Makefile)

## Installation

1. **Clone the repository**:

   ```sh
   git clone https://github.com/mammadnet/Student-management.git
   cd Student-management
   ```

2. **Compile**:

   ```sh
   gcc -o student_mgmt main.c functions.c -std=c99
   ```

   Or, if source files are split across multiple `.c` files:

   ```sh
   gcc -o student_mgmt main.c functions.c creatNodes.c -std=c99
   ```

3. **Run**:

   ```sh
   ./student_mgmt   # On Windows: student_mgmt.exe
   ```

## Usage

Upon running, you will be presented with a Main Menu:

1. **Login Student**: Enter your student ID and password to access the student panel.
2. **Login Professor**: Enter your professor ID and password to access the professor panel.
3. **Login Admin**: Enter administrative credentials to manage all records.
4. **Exit**: Quit the program.

### Student Panel

* **Take Course**: Enroll in an available course by its code.
* **Delete Course**: Drop a previously enrolled course.
* **List of Courses Taken**: View courses you are currently enrolled in.
* **List of All Courses**: Show every course offered by the university.
* **Back to Main Menu**

### Professor Panel

* **Take Course**: Assign yourself to a course offering.
* **List of Courses Taken**: View courses you are teaching.
* **List of All Courses**: Show all university courses.
* **Back to Main Menu**

### Admin Panel

* **Student Management**:

  1. Show all students
  2. Register a new student
  3. Edit student information
  4. Remove a student
  5. Back to Admin Menu

* **Professor Management**:

  1. Register a new professor
  2. Show all professors
  3. Edit professor information
  4. Remove a professor
  5. Back to Admin Menu

* **Course Management**:

  1. Add a new course
  2. Show all courses
  3. Edit course information
  4. Remove a course
  5. Back to Admin Menu

## File Descriptions

* **main.c**: Initializes data, displays menus, and controls program flow.
* **structure.h**: Defines the `stdNode`, `profNode`, and `courseNode` structures.
* **creatNodes.h**: Provides helper functions to allocate and initialize new nodes.
* **functions.h / functions.c**: Implements operations such as `readFile()`, `CrsWriteFile()`, `addStudent()`, `takeStdCourse()`, and login checks.

## Data Persistence

* **Course File**: On startup, `readFile()` loads courses from a text file (e.g., `courses.txt`).
* **On Exit**: `CrsWriteFile()` writes any changes back to the file, preserving added or removed courses.
