#include "MyFuns.cpp"

class Book{public:
	int cp, sp, yop, edition, quantity, shelfNo, bookId;
	char name[100], author[100], category[100];
	date prev_arr, next_arr;
	void getdata();
	void getdata(int tempid);
	void calcSP();
	//void purchase();
	void showDetails();
	//friend void findBook();
};

void Book::getdata(){
	cin.ignore(256,'\n');
	cout<<"Enter category of the Book: ";
	gets(category);
	cout<<"Enter name of the Book: ";
	//cin.ignore(256,'\n');
	gets(name);
	//cin.ignore(256,'\n');
	cout<<"Enter the Author's name: ";
	gets(author);
	cout<<"Enter Book Id: ";
	cin>>bookId;
	cout<<"Enter the year of publication: ";
	cin>>yop;
	cout<<"Enter the edition: ";
	cin>>edition;
	cout<<"Enter the cost price: ";
	cin>>cp;
	cout<<"Enter the selling price: ";
	cin>>sp;
	cout<<"Enter the shelf no.: ";
	cin>>shelfNo;
	cout<<"Enter the quantity: ";
	cin>>quantity;
	cout<<"Enter the Stock arrival date in the format dd mm yy: ";
	cin>>prev_arr.d>>prev_arr.m>>prev_arr.y;
	cout<<"Enter the next stock arrival date in the format dd mm yy: ";
	cin>>next_arr.d>>next_arr.m>>next_arr.y;
	cin.ignore(256,'\n');
}

void Book::getdata(int tempid){
	cin.ignore(256,'\n');
	cout<<"Enter category of the Book: ";
	gets(category);
	cout<<"Enter name of the Book: ";
	//cin.ignore(256,'\n');
	gets(name);
	//cin.ignore(256,'\n');
	cout<<"Enter the Author's name: ";
	gets(author);
//	cout<<"Enter Book Id: ";
//	cin>>bookId;
	bookId=tempid;
	cout<<"Enter the year of publication: ";
	cin>>yop;
	cout<<"Enter the edition: ";
	cin>>edition;
	cout<<"Enter the cost price: ";
	cin>>cp;
	cout<<"Enter the selling price: ";
	cin>>sp;
	cout<<"Enter the shelf no.: ";
	cin>>shelfNo;
	cout<<"Enter the quantity: ";
	cin>>quantity;
	cout<<"Enter the previous stock arrival date in the format dd mm yy: ";
	cin>>prev_arr.d>>prev_arr.m>>prev_arr.y;
	cout<<"Enter the next stock arrival date in the format dd mm yy: ";
	cin>>next_arr.d>>next_arr.m>>next_arr.y;
	cin.ignore(256,'\n');
}

void Book::showDetails(){
	cout<<"Category of the Book: ";
	cout<<category<<endl;
	cout<<"Name of the Book: ";
	cout<<name<<endl;
	cout<<"Author's name: ";
	cout<<author<<endl;
	cout<<"Book Id: ";
	cout<<bookId<<endl;
	cout<<"Cost price: ";
	cout<<cp<<endl;
	cout<<"Selling price: ";
	cout<<sp<<endl;
	cout<<"Year of publication: ";
	cout<<yop<<endl;
	cout<<"Edition: ";
	cout<<edition<<endl;
	cout<<"Shelf no.: ";
	cout<<shelfNo<<endl;
	cout<<"Quantity: ";
	cout<<quantity<<endl;
	cout<<"Previous stock arrival date: ";
	cout<<prev_arr.d<<"-"<<prev_arr.m<<"-"<<prev_arr.y<<endl;
	cout<<"Next stock arrival date: ";
	cout<<next_arr.d<<"-"<<next_arr.m<<"-"<<next_arr.y<<endl;
}

