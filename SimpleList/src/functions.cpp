#include "include/class.h"
vector<string>item;

void List::printmenu()
{
        cout << "***********************\n";
        cout << "          Menu         \n";
        cout << "1. Print List\n";
        cout << "2. Add item\n";
        cout << "3. Delete item\n";
        cout << "4. Quit\n";
        cout << "************************\n";

    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    system("clear");
    List::printlist();
        break;
    case 2:
    system("clear");
    addItem();
        break;
    case 3:
    system("clear");
    deleteItem();
        break;
    case 4:
    exit(0);
        break;

    default:
    cout << "Option not valied";
        break;
    }
}
void List::printlist()
{
    cin.clear();
    if(int(item.size()) > 0 )
    {
    cout << "Items in the list" << endl;
    cout << endl;
    for(int i = 0; i < int(item.size()); i++)
    {
        cout << "* " << item[i] << endl;
    }
    }
    else
    {
        cout<<"Nothing in the list\n";
    }
    cout << "M - Menu  ";
    char menu;
    cin >> menu;
    if(menu == 'M' || menu =='m')
    {
    printmenu();
    }
}
void List::addItem()
{
    string additem;
    cout << "Enter Item you want to enter: ";
    cin >> additem;
    item.push_back(additem);
    cout << "Item added Successfully" << endl;
    cout << "Add more items??enter 'y' or 'n': ";
    char choice;
    cin  >> choice;
    if(choice == 'y')
    {
        addItem();
    }
    else if(choice == 'n')
    {
        printmenu();
    }
    else
    {
        cout << "invalied input try again.." << endl;
        cout << "Add more items?? enter 'y' or 'n': ";
        char choice;
        cin  >> choice;
    }
}
void List::deleteItem()
{
    if(int(item.size()) < 1)
    {
        cout<<"Nothing to delete...\n";
        printmenu();
    }
    else
    {
    for(int i = 0; i < int(item.size()); i++)
    {
    cout << i << ". " << item[i] << endl;
    }
    cout << "Enter index number of the item to delete: ";
    int delItem;
    cin >> delItem;
    item.erase(item.begin() + delItem);
    cout << item[delItem] << " has been removed successfully ";
    }
    cout << "delete more?? enter 'y' or 'n': ";
    char choice;
    cin  >> choice;
    if(choice == 'y')
    {
        deleteItem();
    }
    else if(choice == 'n')
    {
        printmenu();
    }
    {
        cout << "invalied input try again.." << endl;
        cout << "delete more?? enter 'y' or 'n': ";
        char choice;
        cin  >> choice;
    }
}
void List::readfile()
{
    string line;
    ifstream items;
    items.open("userfile/storage.txt");
    if(items.is_open())
    {
        while(getline(items,line)){}

    }

}