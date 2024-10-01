# Pharmacy-Management-System

## Project Overview
The **Pharmacy Management System** is a C++ console-based application that efficiently manages a pharmacy's operations. This project leverages **Object-Oriented Programming (OOP)** principles, **Data Structures and Algorithms (DSA)** concepts like **List**, **Queue**, and **Stack**, and uses **file handling** to store information about medicines and sales receipts.

The system includes two primary interfaces:
- **Admin Menu:** Provides full control over managing medicines, viewing total receipts, and more.
- **Customer Menu:** Allows customers to buy medicines, view available medicines, and make payments.

---

## Features

### Admin Features:
- **Add Medicine:** Add new medicines to the system's inventory.
- **Delete Medicine:** Remove medicines from the system.
- **Update Medicine:** Update details like price, quantity, and description of existing medicines.
- **View Receipts:** View all sales receipts stored in the system.
- **View Customer list:** View all customer lists stored in the system.
- **File Storage:** All data is saved in files, allowing persistence even after the program exits.
- **List, Queue, Stack:** This shows that if we store in the list it looks like if we store data in a queue or stack how it looks like.

### Customer Features:
- **Buy Medicine:** Customers can browse and purchase available medicines.
- **View Medicines:** Customers can view the list of medicines with details (name, price, etc.).
- **Make Payments:** Customers can complete their transactions and generate receipts.
- **Receipt Generation:** Each transaction generates a receipt, which is also saved in a file for future reference.

---

## Key Concepts

### Data Structures:
- **List:** Used to manage the collection of medicines.
- **Queue:** sequentially manages customer orders.
- **Stack:** Used to store and access receipts using a last-in, first-out (LIFO) method.

### File Handling:
- **Data Storage:** Medicines and receipts are stored in files for persistent storage.
- **Data Retrieval:** Medicine details and receipt histories are retrieved from files when the program runs.

### OOP Concepts:
- **Classes & Objects:** The project uses classes such as `Medicine`, `Admin`, `Customer`, and `Receipt`.
- **Encapsulation & Abstraction:** Data hiding and interface-based access is used.
- **Inheritance:** Code reusability is achieved through inheritance for different roles like admin and customer.
- **Polymorphism:** Functionality differs between user roles (admin and customer) through method overriding.

---

## Technologies Used
- **C++** for core functionality, leveraging **Object-Oriented Programming** concepts.
- **Data Structures** like **List**, **Queue**, and **Stack** for efficient data management.
- **File Handling** for storing and retrieving persistent data (medicines and receipts).

---

## Project Structure

- **Classes:**
  - `Medicine`: Represents the medicines in the pharmacy.
  - `Admin`: Handles pharmacy management operations like adding, updating, and deleting medicines.
  - `Customer`: Manages customer interactions such as buying and viewing medicines.
  - `Receipt`: Generates and manages sales receipts.
  
- **File Handling:**
  - `inventory.txt`: Stores medicine information.
  - `receipt.txt`: Stores sales receipts and transaction details.

---

## How to Run:
- You must have a cpp compiler to run this program.
- Dev cpp(6.0), VS code, CLion etc.
- Not run on older versions.
# Ludo-Game-on-Graphics
