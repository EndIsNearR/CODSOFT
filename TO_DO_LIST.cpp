#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

class Node
{
public:
    string task;
    int count;
    bool comp;
    Node* next;
    
    Node()
    {
        next = NULL;
        count = 0;
        comp = false;
    }
};

class LinkedList
{
private:
    Node* head;
    Node* tail;
    int size;
public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    void insert(string tsk)
    {
        size++;
        Node* temp = new Node;
        temp->task = tsk;
        temp->count = size;
        
        if(head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    
    void remove(int num)
    {
        if (num < 1 || num > size) {
            cout << "Invalid task number." << endl;
            return;
        }

        size--;

        if (num == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (size == 0) {
                tail = nullptr;
            }
        } else {
            int count = 1;
            Node* previous = head;
            Node* current = head->next;

            while (count < num - 1) {
                previous = current;
                current = current->next;
                count++;
            }

            previous->next = current->next;
            delete current;

            if (num == size) {
                tail = previous;
            }
        }
    }
    
    void display()
    {
        Node* temp = head;
        if(temp == NULL)
        {
            cout << "No tasks in the list." << endl;
        }
        else
        {
           
            for(int i=0; i<size; i++)
            {
                
                cout  << i+1 << "  " <<left<<setw(30)<< temp->task;
                if(temp->comp)
                {
                    cout << "(COMPLETED)" << endl;
                }
                else
                {
                    cout << "Pending" << endl;
                }
                
                temp = temp->next;
            }
        }
    }
    
    Node* gethead()
    {
        return head;
    }
    
    void completion(int num)
    {
        Node* temp = head;
        
        for(int i=0; i<num-1; i++)
        {
            temp = temp->next;
        }
        
        temp->comp = true;
    }
};

int main()
{
    cout << setw(40) << setfill(' ') << " " << endl;
    cout << "WELCOME TO BASIC TASK MANAGER\n";
    cout << setw(40) << setfill(' ') << " " << endl;

    int choice = 0, num = 0;
    LinkedList l;
    string st;

    do
    {
        cout << "\nPlease choose from the following options:" << endl;
        cout << "1- Input Task\n2- View Task List\n3- Mark Completion\n4- Remove Task\n5- Exit\n";
        cin >> choice;
        
        cin.ignore();
        switch (choice)
        {
            case 1:
                cout << "Please enter the task: ";
                getline(cin, st);
                l.insert(st);
                cout << "Task added successfully!" << endl;
                break;

            case 2:
                cout << "\nTask List:\n";
                l.display();
                break;

            case 3:
                if(l.gethead())
                {
                    cout << "\nMark Task as Completed:\n";
                    l.display();
                    cout << "Enter the task number to mark as completed: ";
                    cin >> num;
                    l.completion(num);
                    cout << "Task marked as completed!" << endl;
                }
                else
                {
                    cout << "No tasks in the list yet." << endl;
                }
                break;

            case 4:
                if(l.gethead())
                {
                    cout << "\nRemove Task:\n";
                    l.display();
                    cout << "Enter the task number to be removed: ";
                    cin >> num;
                    l.remove(num);
                    cout << "Task removed successfully!" << endl;
                }
                else
                {
                    cout << "No tasks in the list yet." << endl;
                }
                break;

            case 5:
                cout << "Exiting the task manager. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != 5);

    return 0;
}
