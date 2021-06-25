#include"include/class.h"

int main(int argc, char* argv[])
{
    if(argc > 0)
    {
    List simpleList;
    string name(argv[1]);
    //simpleList.printmenu();
    ifstream items;
    items.open("userfile/storage.txt");
    if(items.is_open())
    {
        string line;
        while(getline(items,line,'\n'))
        {
         if(line.front() == '#')
         {
            cout << line << endl;
         }
         else
         {
             {
                 cout << "user not found" << endl;
             }
         }
         
        }
    }

    }
    else
    {
        cout << "Username not supplied exiting the programme";
    }

}
