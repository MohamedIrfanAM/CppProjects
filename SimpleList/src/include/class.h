#include<iostream>
#include<vector>
#include<stdlib.h>
#include<fstream>
using namespace std;

class List
{
    public:
    List()
    {
        //Constructor
    }
    ~List()
    {
        //destructor
    }
    string name;
    void printmenu();
    void printlist();
    void addItem();
    void deleteItem();
    void readfile();
};


