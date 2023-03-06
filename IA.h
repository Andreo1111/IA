#pragma once
#include <exception>
//#include <cassert> // for assert()

class Bad_Range : public std::exception
{
public:
    Bad_Range();
    virtual const char* what() const noexcept override {

        return "ERROR: Bad Range";
    }
    ~Bad_Range();
};

class Bad_Length : public std::exception
{
public:
    Bad_Length();
    virtual const char* what() const noexcept override {

        return "ERROR: Bad Length";
    }
    ~Bad_Length();
};

class IntArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntArray() = default;

    IntArray(int length);

    IntArray(const IntArray& a);
 
   ~IntArray();
 
   void erase();

   int& operator[](int index);
   
   void reallocate(int newLength);
     
   void resize(int newLength);
 
   IntArray& operator=(const IntArray& a);
 
   void insertBefore(int value, int index);
 
   void remove(int index);
 
   void insertAtBeginning(int value) { insertBefore(value, 0); }

   void insertAtEnd(int value) { insertBefore(value, m_length); }

   int getLength() const { return m_length; }
};



