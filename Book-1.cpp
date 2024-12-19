#include "Book.h"

Page::Page()
{

}

int Page::getPageNumber() const 
{
    return PageNumber;
}

void Page::setPageNumber(int pageNumber) 
{
    PageNumber = pageNumber;
}

string Page::getContents() const 
{
    return Contents;
}

void Page::setContents(const string& contents) 
{
    Contents = contents;
}

ostream& operator<<(ostream& os, const Page& page) 
{
    os << page.PageNumber << ". " << page.Contents;
    return os;
}

void addPage(Page*& book, int& size, const string& content) 
{
    Page* newBook = new Page[size + 1];
    for (int i = 0; i < size; ++i) 
    {
        newBook[i] = book[i];
    }
    newBook[size].setPageNumber(size + 1);
    newBook[size].setContents(content);
    delete[] book;
    book = newBook;
    ++size;
}

void printPages(const Page* book, int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        cout << book[i] << endl;
    }
    cout << endl;
}

void updatePage(Page* book, int size, int pageNumber, const string& newContent) 
{
    for (int i = 0; i < size; ++i) 
    {
        if (book[i].getPageNumber() == pageNumber) 
        {
            book[i].setContents(newContent);
            return;
        }
    }
    cout << "Page not found!" << endl;
}

void deletePage(Page*& book, int& size, int pageNumber) 
{
    if (size == 0) return;
    Page* newBook = new Page[size - 1];
    int newIndex = 0;
    for (int i = 0; i < size; ++i) 
    {
        if (book[i].getPageNumber() != pageNumber) 
        {
            newBook[newIndex] = book[i];
            newBook[newIndex].setPageNumber(newIndex + 1);  
            ++newIndex;
        }
    }
    delete[] book;
    book = newBook;
    --size;
}
//Assignment #4 Definitions
Book::Book()
{
    capacity = 3;
    pages = new Page[capacity];
}
Book::~Book()
{
    delete[] pages;
}
Book& Book::operator=(const Book& other) 
{ 

    if (this != &other) 
    { 
        delete[] pages; 
        numPages = other.numPages; 
        capacity = other.capacity; 
        pages = new Page[capacity]; 

        for (int i = 0; i < numPages; ++i) 
        { 
            pages[i] = other.pages[i]; 
        } 
    } 
    return *this; 
} 

void Book::addPage(const string& content) 
{ 

    if (numPages == capacity) 
    { 
        int newCapacity = capacity * 2; 
        Page* newPages = new Page[newCapacity]; 

        for (int i = 0; i < numPages; ++i) 
        { 
        newPages[i] = pages[i]; 
        } 

        delete[] pages; 
        pages = newPages; 
        capacity = newCapacity; 
    } 

    pages[numPages].setPageNumber(numPages + 1); 
    pages[numPages].setContents(content); 
    ++numPages; 
} 

void Book::printPages() const 
{ 
    for (int i = 0; i < numPages; ++i) 
    { 
        cout << pages[i] << endl; 
    } 
    cout << endl; 
} 

void Book::updatePage(int pageNumber, const string& newContent) 
{ 
    for (int i = 0; i < numPages; ++i) 
    { 
        if (pages[i].getPageNumber() == pageNumber) 
        { 
            pages[i].setContents(newContent); 
            return; 
        } 
    } 
    cout << "Page not found!" << endl; 
} 

void Book::deletePage(int pageNumber) 
{ 
    if (numPages == 0) 
    return; 

    Page* newPages = new Page[capacity]; 
    int newIndex = 0; 

    for (int i = 0; i < numPages; ++i) 
    { 
        if (pages[i].getPageNumber() != pageNumber) 
        { 
            newPages[newIndex] = pages[i]; 
            newPages[newIndex].setPageNumber(newIndex + 1); 
            ++newIndex; 
        } 
    } 

    delete[] pages; 
    pages = newPages; 
    --numPages; 
} 
//
int main() 
{
    int size = 3;
    Page* book = new Page[size];
    for (int i = 0; i < size; ++i) 
    {
        book[i].setPageNumber(i + 1);
        book[i].setContents("Filler");
    }

    int choice, pageNumber;
    string content, newContent;
    do 
    {
        cout << "1. Add a new page\n";
        cout << "2. Print all pages\n";
        cout << "3. Update a page\n";
        cout << "4. Delete a page\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch(choice)
        {
            case 1:
                cout << "Enter content for the new page: ";
                getline(cin, content);
                addPage(book, size, content);
                break;
            case 2:
                printPages(book, size);
                break;
            case 3:
                cout << "Enter page number to update: ";
                cin >> pageNumber;
                cin.ignore(); 
                cout << "Enter new content: ";
                getline(cin, newContent);
                updatePage(book, size, pageNumber, newContent);
                break;
            case 4:
                int pageNumber;
                cout << "Enter page number to delete: ";
                cin >> pageNumber;
                deletePage(book, size, pageNumber);
                break;
            case 5:
                break;
            default:
                break;
        }
    } while (choice != 5);

    delete[] book;
    return 0;
}
