#include<iostream>
#include <bits/stdc++.h>
using namespace std;

struct node{
  int roll_no;
	string Name;
	string Dept;
	int Marks;
	node* next;
  node(int roll,string name,string dept,int marks){
    roll_no=roll;
    Name=name;
    Dept=dept;
    Marks=marks;
    next=NULL;
  }
};

bool check_isexist(int roll,node *head)
{
  if (head==NULL) {
    return false;
  }
  node *temp=head;
  while (temp!=NULL) {
    if(temp->roll_no==roll){
      return true;
    }
    temp=temp->next;
  }
  return false;

}

node *insert_data(node *head,int roll,string name,string dept,int marks)
{
  if (check_isexist(roll,head)) {
    cout<<"Sorry this student's record is already exist in system."<<endl;
    cout<<endl;
    return 0;
  }
  node *temp = new node(roll,name,dept,marks);
  if (head==NULL) {
    return temp;
  }
  node *curr = head;
  while(curr->next!=NULL)
  {
    curr=curr->next;
  }
  curr->next=temp;
  return head;
}

node *Delete_Record(node *head, int roll)
{
  if(head==NULL)
  {
    cout<<"There is no Record to delete"<<endl;
    cout<<endl;
    return NULL;
  }
  if(head->next==NULL)
  {
    delete head;
    cout<<endl;
    return NULL;
  }
  node *curr = head;
  node *temp=curr;
  while (curr->roll_no!=roll) {
    temp=curr;
    curr=curr->next;
  }
  temp->next=curr->next;
  delete curr;
  return head;
}

int Search_record(node *head,int roll_n)
{
  if (head == NULL) {
    cout<<"There is no record of any student to search."<<endl;
    return 0;
  }
  node *curr=head;
  while(curr->roll_no!=roll_n)
  {
    curr=curr->next;
  }
  if (curr==NULL) {
    cout<<"Sorry roll no. "<<roll_n<<"does not exist"<<endl;
    return 0;
  }
  cout<<endl;
  cout<<"Student name : "<<curr->Name<<endl;
  cout<<"Roll no. : "<<curr->roll_no<<endl;
  cout<<"Marks : "<<curr->Marks<<endl;
  cout<<"Department : "<<curr->Dept<<endl;
}

void topper_of_class(node *head)
{
  if (head == NULL) {
    cout<<endl;
    cout<<"Sorry there is no data in database as list is empty"<<endl;
    cout<<endl;
  }
  node *curr=head;
  node *temp=curr;
  int max=curr->Marks;
  while(curr!=NULL)
  {
    if(curr->Marks >= max){
      max=curr->Marks;
      temp=curr;
    }
    curr=curr->next;
  }
  cout<<"Topper name : "<<temp->Name<<endl;
  cout<<"Roll no. : "<<temp->roll_no<<endl;
  cout<<"Department : "<<temp->Dept<<endl;
  cout<<"Marks : "<<temp->Marks<<endl;
}

void show_list(node *head)
{
  if (head==NULL) {
    cout<<endl;
    cout<<"List is empty"<<endl;
    cout<<endl;
  }
  node *temp=head;
  cout<<endl;
  cout<<"NAME"<<"    ROLL_NO    "<<"    DEPARTMENT     "<<"    MARKS          "<<endl;
  while (temp!=NULL) {
    cout<<temp->Name<<"       "<<temp->roll_no<<"           "<<temp->Dept<<"           "<<temp->Marks<<endl;
    temp=temp->next;
  }
  cout<<endl;
}

int main()
{
  int roll_no;
  string Name;
  string Dept;
  int Marks;
  node *head = NULL;
  cout<<"================Welcome to student data management system======================"<<endl;
  cout<<endl;
    while (true) {
  cout<<"----------------------------------------------------"<<endl;
  cout<<"Select what you want to do"<<endl;
  cout<<"1. Create a Record of student."<<endl;
  cout<<"2. Want to Delete any record."<<endl;
  cout<<"3. Want to Search any record."<<endl;
  cout<<"4. Want to see all student data."<<endl;
  cout<<"5. Want to see who is topper in class."<<endl;
  cout<<"6. Exit"<<endl;
  cout<<endl;
  int choice;
  cout<<"What you want to do enter number accordingly : ";
  cin>>choice;
  if (choice == 1) {
    cout<<"Enter student name : ";
    cin>>Name;
    cout<<"Enter Rollno. of student : ";
    cin>>roll_no;
    cout<<"Enter Department of student : ";
    cin>>Dept;
    cout<<"Enter total marks of the student : ";
    cin>>Marks;
    head=insert_data(head,roll_no,Name,Dept,Marks);
    cout<<"New record inserted Successfully"<<endl;
    cout<<endl;
  }else if(choice == 2){
    cout<<"Enter the roll no. you want to delete : ";
    int del_roll;
    cin>>del_roll;
    head=Delete_Record(head,del_roll);
    cout<<"Roll no. "<<del_roll<<" deleted Successfully "<<endl;
    cout<<endl;
  }else if(choice==3){
    int roll_no;
    cout<<"Enter student's roll no. that you want to search : ";
    cin>>roll_no;
    Search_record(head,roll_no);
  }else if(choice == 4){
    show_list(head);
  }else if(choice==5){
    topper_of_class(head);
  }else if (choice == 6) {
    exit(0);
  }else{
    cout<<"You have choicen Invalid Number please choice valid number"<<endl;
  }
}
}
