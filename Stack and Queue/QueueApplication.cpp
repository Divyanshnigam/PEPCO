
#include <iostream>
using namespace std;
const int MAX=3;

class passenger
{
    int seatno=0;
    int age;
    char psgnm[30];
    friend class Queue;

public:

    void accept()
    {

        cout<<"Enter the passenger name: "<<endl;
        cin>>psgnm;
        cout<<"Enter age:"<<endl;
        cin>>age;

        seatno+=1;
    }
};

class Queue
{

	int front,rear;
	passenger data[MAX];
	public:
		Queue()
		{
			front=-1;
			rear=0;
		}

		int isEmpty()
		{
			if(front==-1||front==rear)
				return 1;
			else
				return 0;
		}
		int isFull()
		{
			if(rear==MAX)
				return 1;
			else
				return 0;
		}

		void enqueue(passenger p)
		{
			if(isFull()==1)
			{
				cout<<"Queue is full!"<<endl;
				return;
			}
			else
			{
				if(front==-1)
					front=0;
				data[rear]=p;
				rear++;
			}
		}

		void dequeue()
		{
			if(isEmpty()==1)
			{
				cout<<"Queue is empty!"<<endl;
			}
			else
			{
			    passenger p;
				p=data[front];
				front++;

				cout<<"\n----TICKET---"<<endl;

				cout<<"Passenger name: "<<p.psgnm<<endl;
				cout<<"Age: "<<p.age<<endl;
				cout<<"Seat no. : "<<p.seatno<<endl;

				cout<<"\nPassenger booking confirmed! "<<endl;

			}
		}

		void display()
		{
            if(isEmpty()==1)
			{
				cout<<"Queue is empty!"<<endl;
			}
			else
            {
                cout<<"Waiting List: "<<endl;
                for(int i=front;i<rear;i++)
                    cout<<data[i].psgnm<<"\t";
                cout<<endl;
			}
		}

};


class applctn
{
    passenger p;
    Queue q;
public:

    void reserve_seat()
    {
        p.accept();
        q.enqueue(p);
    }

    void confirm_booking()
    {
        q.dequeue();
    }

    void display()
    {
        q.display();
    }
};

int main() {

	applctn a;
	int ch;
	cout<<"-----MENU-----"<<endl;
	cout<<"1.Reserve Seat"<<endl;
	cout<<"2.Confirm booking"<<endl;
	cout<<"3.Display queue"<<endl;
	cout<<"4.Exit"<<endl;
	cout<<"--------------"<<endl;

	while(1)
	{
		cout<<"\nEnter your choice: "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
					a.reserve_seat();
					break;
			case 2:
					a.confirm_booking();
					break;
			case 3:
					a.display();
					break;
			case 4:
					cout<<"Program closed!"<<endl;
					//exit(1);
					break;
			default:
					cout<<"Invalid choice!"<<endl;
					break;
		}
	}

	return 0;
}


/*
OUTPUT:

-----MENU-----
1.Reserve Seat
2.Confirm booking
3.Display queue
4.Exit
--------------

Enter your choice:
1
Enter the passenger name:
Ritu
Enter age:
20

Enter your choice:
1
Enter the passenger name:
Saylee
Enter age:
36

Enter your choice:
1
Enter the passenger name:
Rakesh
Enter age:
50

Enter your choice:
1
Enter the passenger name:
aakash
Enter age:
20
Queue is full!

Enter your choice:
3
Waiting List:
Ritu    Saylee  Rakesh

Enter your choice:
2

----TICKET---
Passenger name: Ritu
Age: 20
Seat no. : 1

Passenger booking confirmed!

Enter your choice:
3
Waiting List:
Saylee  Rakesh

Enter your choice:
2

----TICKET---
Passenger name: Saylee
Age: 36
Seat no. : 2

Passenger booking confirmed!

Enter your choice:
3
Waiting List:
Rakesh

Enter your choice:
2

----TICKET---
Passenger name: Rakesh
Age: 50
Seat no. : 3

Passenger booking confirmed!

Enter your choice:
2
Queue is empty!

Enter your choice:
4
Program closed!

*/
