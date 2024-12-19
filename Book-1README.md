# Book Simulation Assignment

## Description
This program simulates a book by managing a dynamically allocated array of `Page` objects. The `Book` class provides CRUD (Create, Read, Update, Delete) functionality for managing pages and
ensures proper memory management through the rule of three.

---

## Features

### Page Class
- **Data Members**:
  - `int PageNumber`: Represents the page number.
  - `string Contents`: Represents the content of the page.
- **Insertion Operator Overload (`<<`)**:
  - Prints the page in the format: `<PageNumber><Symbol> <Contents>`.

### Book Class
- **Data Members**:
  - A dynamically allocated array of `Page` objects.
- **CRUD Operations**:
  1. **Create**: Adds a new page to the book with:
     - Automatically assigned `PageNumber`.
     - Growth algorithm to increase the capacity dynamically.
  2. **Read**: Prints all pages in the book using the insertion operator.
  3. **Update**: Allows the user to update the content of a page by specifying its page number.
  4. **Delete**: Removes a page by page number and renumbers subsequent pages to maintain sequence.
- **Rule of Three**:
  - **Destructor**: Ensures proper cleanup of dynamically allocated memory.
  - **Copy Constructor**: Creates a deep copy of a `Book` object.
  - **Assignment Operator**: Performs a deep copy during assignment.

---

## Main Program
- **Dynamic Array Initialization**:
  - Starts with three `Page` objects.
- **User Menu**:
  - **Add Page**: Creates a new page and demonstrates the growth algorithm.
  - **Print Pages**: Displays all pages in the book using the overloaded insertion operator.
  - **Update Page**: Updates the contents of a specific page by page number.
  - **Delete Page**: Deletes a page by page number and renumbers subsequent pages.
