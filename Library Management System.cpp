#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class library{
string name, author,id, search;
fstream file;
public:
void display_book();
void add_book();
void extract_book();
};

void library :: display_book(){
    file.open("libraryData.txt", ios :: in);
    if(!file.is_open())
 {
      cout<<"No data found...."<<endl;
  }

  else 
  {
       while(getline(file, id) && getline(file, name) && getline(file, author))
   {
    cout<<"Id: "<<id<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Author: "<<author<<endl;
   }
  }
file.close(); 

}

void library :: add_book(){
cin.ignore();
cout<<"Enter the Id: "<<endl;
getline(cin, id);
cout<<"Enter the name of book: "<<endl;
getline(cin, name);
cout<<"Enter the name of author: "<<endl;
getline(cin,author);

file.open("libraryBook.txt", ios :: out | ios :: app);
if(file.is_open())
{
file<<id<<endl<<name<<endl<<author<<endl;
file.close();
cout<<"Book added successfully...."<<endl;
}
else 
{
    cout<<"Error in opening file....."<<endl;
}
}

void library :: extract_book(){
cin.ignore();
cout<<"Enter the Id to extract the book: "<<endl;
getline(cin, search);

file.open("libraryData.txt", ios:: in);
if(!file.is_open())
{
    cout<<"No data found....."<<endl;
}

bool found=false;
while(getline(file, id) && getline(file, name) && getline(file, author))
if(search==id)
{
    cout<<"Book Found..."<<endl;
    cout<<"Id: "<<id<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Author: "<<author<<endl;

    found=true;
    break;
}
if(!found)
{
    cout<<"Book with Id "<<search<<"not found."<<endl;
}
file.close();
}

int main(){
    library book;
    int choice;
    while(true)
    {
    cout<<"--------------------------"<<endl;
    cout<<"1. Display all the books"<<endl;
    cout<<"2. Add a book"<<endl;
    cout<<"3. Extract a book"<<endl;
    cout<<"4. Exit"<<endl;
   cin>>choice;
    switch(choice)
    {
   case 1:
   book.display_book();
   break;
   case 2:
   book.add_book();
   break;
    case 3:
   book.extract_book();
   break; 
   case 4:
   cout<<"Exiting...."<<endl;
   return 0;

   default:
   cout<<"Invalid choice. Please enter a valid option...."<<endl;
    }
    }
   return 0;
}
