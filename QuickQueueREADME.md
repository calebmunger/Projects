# QuickQueue Template Class

## Description
This assignment implements a template class `QuickQueue<T>` that provides queue functionality for any data type. The queue uses dynamic memory allocation to manage its elements and demonstrates
essential C++ concepts like templates, dynamic memory management, and the rule of three.

---

## Features
1. **Template Class**: `QuickQueue<T>` supports any data type.
2. **Two Template Functions**:
   - **`Enqueue`**: Adds an element to the queue.
   - **`Dequeue`**: Removes an element from the queue and returns it to the caller.
3. **Dynamic Memory Management**:
   - Internal storage is managed as a double pointer of type `T` (not using STL containers).
4. **Rule of Three**:
   - Correct implementation of copy constructor, assignment operator, and destructor to handle dynamic memory.
5. **Driver Program**:
   - Demonstrates `QuickQueue<T>` functionality with two different types.
   - Adds and removes five items from each queue.

---

## Class Structure
### `QuickQueue<T>`:
- **Member Variables**:
  - A double pointer (`T**`) for storing the queue elements.
  - Additional variables for tracking the size and capacity of the queue.
- **Member Functions**:
  - `Enqueue(T element)`: Adds an element to the queue.
  - `Dequeue() -> T`: Removes and returns the first element of the queue.
  - Rule of Three:
    - Copy Constructor.
    - Assignment Operator.
    - Destructor.

---
