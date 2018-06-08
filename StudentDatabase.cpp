#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>
#include <string>
using namespace std;
class Student { //base class
    protected:
        string name; //string object
        int roll;
        string sub;
};
class Data: protected Student { //sub-class
    protected:
        string subCode;
        int iMark;
        int uMark;
        Data* next;
    public:
        void setData(string name, int roll, string sub, string subCode, int iMark, int uMark) {
            this->name = name;
            this->roll = roll;
            this->sub = sub;
            this->subCode = subCode;
            this->iMark = iMark;
            this->uMark = uMark;
        }
        void setNext(Data* next) {
            this->next = next;
        }
        void printData() {
            cout<<roll<<setw(10)<<name<<setw(20+(20-name.size()))<<sub<<setw(15)<<subCode<<setw(15)<<iMark<<setw(15)<<uMark<<setw(1)<<endl;
        }
        Data* nextf() {
            return next;
        }
        int rollf() {
            return roll;
        }
        bool match(int roll) {
            if(this->roll == roll)
                return true;
            else
                return false;
        }
};

class List {
    private:
        Data* head;
    public:
        List() {
            head = NULL;
        }
        void display() {
            Data* temp = head; //set cursor to the first Data
            if(temp == NULL) {  //if the list is empty
                cout<<"EMPTY"<<endl;
                return;
            }
            if(temp->nextf() == NULL) { //if the list has only one element
                temp->printData();
            }
            else {
                do {
                    temp->printData();
                    temp = temp->nextf();
                }
                while(temp != NULL);
            }
            
        }
        void append(string name, int roll, string sub, string subCode, int iMark, int uMark) {
            Data *newData = new Data();
            newData->setData(name, roll, sub, subCode, iMark, uMark); //inserting value to the new object
            newData->setNext(NULL); //set the next of the new object to null
            
            Data* temp = head; //setting the cursor to the beginning of the list
            if(temp != NULL) {  //List is not empty
                while(temp->nextf() != NULL) {   //parsing the cursor to the end of the list
                    temp = temp->nextf();
                }
                temp->setNext(newData);
            }
            else //if it is the first Data in the list
                head = newData;
            
        }
        void detach(int roll) {
            Data* temp = head; //setting the cursor to the beginning of the list
            if(temp == NULL) //if list is empty
                return;
            if(temp->nextf() == NULL) { //if list has only one Data.
                delete temp;
                head = NULL;
                return;
            }
            if(temp == head && temp->rollf() == roll) {
                head = temp->nextf();
                delete temp;
                return;
            }
            else {
                Data* prev;
                do {
                    if(temp->rollf() == roll)
                        break;
                    prev = temp;
                    temp = temp->nextf();
                }
                while(temp != NULL);
                prev->setNext(temp->nextf());
                delete temp;
            }
        }
        bool search(int roll) {
            Data* temp = head;
            if(temp == NULL) {
                cout<<"EMPTY"<<endl;
                return false;
            }
            if(temp->nextf() == NULL) { //if the list has only one element
                return temp->match(roll);
            }
            else {
                do {
                    if(temp->match(roll)) {
                        return true;
                        break;
                    }
                    else
                        temp = temp->nextf();
                }
                while(temp != NULL);
                return false;
            }
        }
};

int size(char* str1) {
	int i = 0;
	while(1) {
		if(str1	[i] == '\0')
			break;
		i++;
	}
	return i;
}

bool isEqual(char* str1, char* str2) {
	int i=0;
	int n1 = size(str1);
	if(size(str1) != size(str2))
		return false;
	else
		for(i=0; i<n1; i++) {
			if(str1[i] != str2[i]) {
				return false;
			}
		}
	return true;
}
void menu() {
	printf("\033[1;33m********************************************************************************************************************\033[0m\n");
	printf("\033[1;33m**                                Author: Tejeswar Tripathy - Emp ID: 396606                                      **\033[0m\n");
	printf("\033[1;33m********************************************************************************************************************\033[0m\n");
	printf("\033[1;33m********************************************************************************************************************\033[0m\n");
	printf("\033[1;33m**                                             INSTRUCTION                                                        **\033[0m\n");
	printf("\033[1;33m********************************************************************************************************************\033[0m\n");
	printf("\033[1;33m** append   - To append a node to the list. (See: help append)                                                    **\033[0m\n");
	printf("\033[1;33m** display  - To print the entire list on the screen. (See: help display)                                         **\033[0m\n");
	printf("\033[1;33m** delete   - To delete a particular node using the roll number. (See: help delete)                               **\033[0m\n");
	printf("\033[1;33m** search   - To search a particular node using the roll number. (See: help search)                               **\033[0m\n");
	printf("\033[1;33m** help <command>   - To see instruction and example of a particular command  (eg:  help append)                  **\033[0m\n");
	printf("\033[1;33m**               KEEP IN MIND. ONE WRONG COMMAND MAY TERMINATE THE APPLICATION                                    **\033[0m\n");
	printf("\033[1;33m********************************************************************************************************************\033[0m\n");
}
#pragma GCC diagnostic ignored "-Wwrite-strings"
int main() {
    menu();
    string name;
    string sub;
    string subCode;
    int iMark;
    int uMark;
    int roll;
    char comma;
    List *list = new List();
    char* command = new char[30];

    while(1) {
        cout<<">>> ";
        int trigger;
        scanf("%s", command);
        if(isEqual(command, "append")) {
            trigger = 1;            
        }
        else if(isEqual(command, "display")) {
            trigger = 2;
        }
        else if(isEqual(command, "delete")) {
            trigger = 3;
        }
        else if(isEqual(command, "search")) {
            trigger = 4;
        }
        else if(isEqual(command, "help")) {
            trigger = 5;
        }
        else if(isEqual(command, "exit")) {
            break;
        }
        else {
            cout<<"\033[1;31mError: \033[0mIncorrect Command"<<endl<<"\033[1;31m*****PROGRAM TERMINATED*****\033[0m"<<endl;
            break;
        }
        switch(trigger) {
            case 1:
                    cin>>roll>>comma;
                    getline(cin, name, ',');
                    getline(cin, sub, ',');
                    getline(cin, subCode, ',');
                    cin>>iMark>>comma;
                    cin>>uMark;
                    list->append(name, roll, sub, subCode, iMark, uMark);
                    break;
            case 2:
                    list->display();
                    break;
            case 3:
                    int droll;
                    cin>>droll;
                    if(list->search(droll))
                        list->detach(droll);
                    else
                        cout<<"NOT FOUND"<<endl;
                    break;
            case 4:
                    int sroll;
                    cin>>sroll;
                    if(list->search(sroll))
                        cout<<"FOUND"<<endl;
                    else
                        cout<<"NOT FOUND"<<endl;
                    break;
            case 5:
                    char* cname = new char[50];
                    scanf("%s",cname);
                    if(isEqual(cname, "append")) {
                        cout<<endl<<"\033[1;34mappend\033[0m"<<endl<<endl;
                        cout<<"\033[21;34m\tappend Firstname Lastname , (int)#Roll , Subject , Subject_Code , (int)Internal_mark , (int)University_mark\033[0m"<<endl;
                        cout<<"\033[21;34m\t[Note: Use space comma space in between each elements while enetering the value.]\033[0m"<<endl;
                        cout<<"\033[1;32m\tExample:"<<endl<<"\t\tappend 21 , Tejeswar Tripathy , C Plus Plus , CPP123 , 80 , 90\033[0m"<<endl;
                    }
                    else if(isEqual(cname, "display")) {
                        cout<<endl<<"\033[1;34mdisplay\033[0m"<<endl<<endl;
                        cout<<"\033[21;34m\tTo show the table\033[0m"<<endl;
                    }
                    if(isEqual(cname, "delete")) {
                        cout<<endl<<"\033[1;34mdelete\033[0m"<<endl<<endl;
                        cout<<"\033[21;34m\tdelete (int)#Roll\033[0m"<<endl;
                        cout<<"\033[21;34m\t[Note: Use integer value only.]\033[0m"<<endl;
                        cout<<"\033[1;32m\tExample:"<<endl<<"\t\tdelete 21\033[0m"<<endl;
                    }
                    if(isEqual(cname, "search")) {
                        cout<<endl<<"\033[1;34msearch\033[0m"<<endl<<endl;
                        cout<<"\033[21;34m\tsearch (int)#Roll\033[0m"<<endl;
                        cout<<"\033[21;34m\t[Note: Use integer value only.]\033[0m"<<endl;
                        cout<<"\033[1;32m\tExample:"<<endl<<"\t\tsearch 21\033[0m"<<endl;
                    }
        }        
    }
    return 0;
}