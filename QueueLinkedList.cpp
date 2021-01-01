using namespace std;

#include<iostream>
#include<stdio.h>
#include<conio.h>

class Queue
{
    private:
        struct node
        {
            int item;
            node *next;
        } *front, *rear;
    
    public:
        Queue()
        {
            front = NULL;
            rear = NULL;
        }

        void displayqueue()
        {
            if(front == NULL)
            {
                cout<<"List is empty";
            }
            else
            {
                node *t = front;

                while(t!=NULL)
                {
                    cout<<" "<<t->item;

                    t=t->next;
                }
            }
            
        }
        int count()
        {
            int c = 0;

            if(front == NULL)
            {
                return(c);
            }
            else
            {
                node *t;
                t=front;

                while(t != NULL)
                {
                    t = t->next;
                    c++;
                }
                

                return(c);
            }

        }

        int isempty()
        {
            if(front == NULL)
           
                return(1);
            
            return(false);
            
        }
            
    
        int getfirst()
        {
            if(front == NULL)
            {
                return(-1);
            }
            else
            {
                return(front->item);
            }

        }

        int remove()
        {
            if(front==NULL)
            {
                return (0);
            }

            if(front == rear)
            {
                delete front;
                front = rear = NULL;

                return (1);
            }
            else
            {
                node *temp;
                temp = front;

                front = front->next;

                delete temp;

                return(1);
            }
            
        }

        void insert(int data)
        {
            node *n = new node();
            n->item = data;
            n->next = NULL;

            if(rear == NULL)
            {
                front = rear = n;
            }
            else
            {
                rear->next = n;
                rear = n;
            }
            
        }
};

int main()
{

        Queue list1;

        list1.insert(50);
        list1.insert(20);
        list1.insert(30);
        list1.insert(40);

        list1.displayqueue();
        cout<<"no. of node is: "<<list1.count()<<endl;
        list1.remove();
        list1.displayqueue();

        cout<<"no. of node is: "<<list1.count()<<endl;

        cout<<"First element is : "<<list1.getfirst()<<endl;

        cout<<"list is empty or not : "<<list1.isempty()<<endl;
        


}