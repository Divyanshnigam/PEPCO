#include<iostream>
#include<cstring>
#include"hastable.h"
using namespace std;
int main()
{
	Hashtable<int> price_menu;
	price_menu.insert("Burger",120);
	price_menu.insert("Pepsi",20);
	price_menu.insert("BurgerPizza",150);
	price_menu.insert("Noodles",25);
	price_menu.insert("Coke",40);
	price_menu.print();
	return 0;
}
/*
o/p:

Bucket 0->
Bucket 1->
Bucket 2->Noodles->
Bucket 3->Burger->
Bucket 4->Coke->Pepsi->
Bucket 5->BurgerPizza->
Bucket 6->
*/
