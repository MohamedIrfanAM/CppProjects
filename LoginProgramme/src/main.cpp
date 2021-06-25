#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<fstream>
#include<sstream>

using namespace std;

class app
{
    private:
    public:
    string usernameAttempt;
    string passwordAttempt;
    string user_filePath = "users.dat";
    string p_filePath = "password.dat";

};

long long encrypt(int eChar)
{
    return powf(eChar,5) * 5 -9989565 ;
}
int decrypt(long long eChar)
{
    return powf((eChar + 9989565)/ 5 ,1/5.f);

}
int getlatID(const char* filename)
{
    fstream idfinder;
    idfinder.open(filename,ios:: in);
    idfinder.seekg(0,ios::end);
    string s;
    int id;
    if(idfinder.tellg() != 0)
    {
        for(int i = -1; s.find('#')==string::npos; i--)
        {
            idfinder.seekg(i , ios::end);
            idfinder >> s;
        }
        s.erase(0,4);
        idfinder.close();
        istringstream(s) >> id;
    }
    else
    {
        id = 0;
    }

    return id;
}
void savefile(string userdata,const char* filename )
{
    fstream userfile;
    userfile.open(filename , ios::app);
    userfile.seekg(0,ios::end);
    if(userfile.tellg() != 0)
    {
        userfile << "\n";
    }
    for(int i =0; i < int(userdata.length()); i++)
    {
        userfile << encrypt(userdata[i]) << "\n";
    }
    userfile << "#ID:" << getlatID(filename)+1 ;
    return;
}
int checkfile(string p_filename , string attempt)
{
    fstream userdata;
    userdata.open(p_filename, ios::in);
    long long line;
    string currentChar;
    string name;
    while(1)
    {
        userdata >> currentChar;
        if(currentChar.find("#ID:")== string::npos)
        {
            istringstream(currentChar) >> line;
            name += (char)decrypt(line);
        }
        else
        {
            if(name == attempt)
            {
                int id;
                currentChar.erase(0,4);
                istringstream(currentChar)>> id;
                userdata.close();
                return id;
            }
            else
            {
                currentChar.clear();
                name.clear();
            }
        }
        if(userdata.peek()==EOF)
        {
        return 0;
        }
    }
}
void passwordcheck(int pswdID)
{
    app pswdcheck;
    cout << "Password:";
    cin >> pswdcheck.passwordAttempt;
    if(checkfile("passwords.dat",pswdcheck.passwordAttempt) == pswdID)
    {
        cout << "Access Granded" << endl;
    }
    else
    {
        cout << "Password is incorrect try again" << endl;
        passwordcheck(pswdID);
    }
}
void login()
{
    app mLogin;
    mLogin.usernameAttempt.clear();
    int userID;
    cout << "********M Login Programme**********\n";
    cout << "Enter Your Username: ";
    getline(cin,mLogin.usernameAttempt);
    if(checkfile("users.dat",mLogin.usernameAttempt) != 0)
    {
        userID = checkfile("users.dat",mLogin.usernameAttempt);
        passwordcheck(userID);
    }
    else
    {
        cout << "Username not found.. do you want to add this user?(y or n): " ;
        char choice;
        cin >> choice;
        if(choice == 'y')
        {
            string password;
            savefile(mLogin.usernameAttempt,"users.dat");
            cout << "Set your password: ";
            cin >> password;
            savefile(password,"passwords.dat");
            system("clear");
            cout << "Login with your username and password.." << endl;
            cout << "Enter Your Username: ";
            cin >> mLogin.usernameAttempt;
            if(checkfile("users.dat",mLogin.usernameAttempt) != 0)
            {
                userID = checkfile("users.dat",mLogin.usernameAttempt);
                passwordcheck(userID);
            }
        }
        if(choice == 'n')
        {
            return;
        }
    }
}
int main()
{

    system("clear");
    login();
    return 0;
}