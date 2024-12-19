#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
using namespace std;

class Page 
{
    friend ostream& operator<<(ostream& os, const Page& page);
private:
    int PageNumber;
    string Contents;

public:
    Page();
    int getPageNumber() const;
    void setPageNumber(int pageNumber);
    string getContents() const;
    void setContents(const string& contents);

    void addPage(Page*& book, int& size, const string& content);
    void printPages(const Page* book, int size);
    void updatePage(Page* book, int size, int pageNumber, const string& newContent);
    void deletePage(Page*& book, int& size, int pageNumber);
};
//Assignment #4 code
class Book 
{ 
    private: 
        Page* pages; 
        int numPages; 
        int capacity; 

    public: 
        Book(); 
        ~Book(); 
        Book(const Book& other); 
        Book& operator=(const Book& other); 
  

        void addPage(const string& content); 
        void printPages() const; 
        void updatePage(int pageNumber, const string& newContent); 
        void deletePage(int pageNumber); 
}; 

#endif 