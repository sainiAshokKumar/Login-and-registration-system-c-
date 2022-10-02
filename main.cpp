#include<iostream>
#include<fstream>
#include<string>

using namespace std;
bool IsLoggedIn()
{
    string username,passward,un,pw;

   cout<<"Enter username: "; cin>>username;
   cout<<"Enter passward: "; cin>>passward;

   ifstream read("c:\\" + username + ".txt");
   getline(read, un);
   getline(read, pw);

   if (un == username && pw == passward)
   {
       return true;
   }
   else
   {
       return false;
   }
}

int main()
{
   int choice;
   cout << "1: register\n2: Login\nyour choice: "; cin >> choice;
   if(choice == 1)
   {
       string username, passward;

       cout << "select a username: ";cin >> username;
       cout << "select a passward: ";cin >> passward;

       ofstream file;
       file.open("c:\\" + username + ".txt");
       file << username << endl << passward;
       file.close();

       main();
   } 
   else if (choice == 2)
   {
       bool status = IsLoggedIn();

       if (!status)
       {
           cout << "False Login!" << endl;
           system("PAUSE");
           return 0;

       }
      
      else
      {
          cout << "succesfully logged in!" << endl;
          system("PAUSE");
          return 1;
      } 
   }
}