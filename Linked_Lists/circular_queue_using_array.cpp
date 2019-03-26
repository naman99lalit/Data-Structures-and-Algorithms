#include <iostream>
using namespace std;

class circular_queue
{
    private:
        int *cir_array;
        int front, rear, size;
    public:
        circular_queue(int s)
        {
            cir_array = new int[s];
            front = -1;
            rear = -1;
            size=s;
        }
        void insert(int value)
        {
            if(((rear==(size-1))&&(front==0))||(front==rear+1))
            {
                cout<<"Queue is full\n";
            }
            else if(front==-1)
            {
                front=0;
                rear=0;
               cir_array[rear]=value; 
            }
            else if(front!=0&&rear==(size-1))
            {
                rear=0;
                cir_array[rear]=value;
            }
            else
            {
                rear++;
                cir_array[rear]=value;
            }
        }
        void deleteq()
        {
            if(front==-1)
            {
                cout<<"Queue is empty\n";
            }
            int delete_value=cir_array[front];
            cir_array[front]=-1;
            if(front==(size-1))
            {
                front=0;
            }
            else if(front==rear)
            {
                front=rear=-1;
            }
            else
            {
                front++;
            }
            cout<<"The deleted value from the queue is "<<delete_value<<endl;
        }
        void display()
        {
            if(front==-1)
            {
                cout<<"Queue is empty\n";
            }
            else if(rear<front)
            {
                for(int i=front;i<size;i++)
                {
                    cout<<cir_array[i]<<" ";
                }
                for(int j=0;j<=rear;j++)
                {
                    cout<<cir_array[j]<<" ";
                }
            }
            else
            {
                for(int i=front;i<=rear;i++)
                {
                    cout<<cir_array[i]<<" ";
                }
            }
            cout<<endl;
        }
};
int main() 
{
    int i,j,k,size;
    cout<<"Enter the size of the queue\n";
    cin>>size;
    circular_queue cq(size);
    int element;
    char ch;
    while(1)
    {
        cout<<"Press 1 to insert an element in the circular queue\n"<<"Press 2 to delete an element from the circular queue\n"<<"Press 3 to display the circular queue\n"<<"Press 4 to exit\n";
        cin>>ch;
        if(ch=='1')
        {
            cout<<"Enter the element\n";
            cin>>element;
            cq.insert(element);
        }
        else if(ch=='2')
        {
            cq.deleteq();
        }
        else if(ch=='3')
        {
            cq.display();
        }
        else
        {
            break;
        }
    }
    return 0;
}

