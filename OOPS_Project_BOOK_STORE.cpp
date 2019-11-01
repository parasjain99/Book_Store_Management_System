#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
#include<string.h>

using namespace std;



int StrCmp(string a, string b){
	if(a.length()!=b.length())
		return 0;
	else{
		for(int i=0;i<b.length();i++){
			if(toupper(a[i])!=toupper(b[i]))
				return 0;
		}
	}
	return 1;
}
int Search(char a[], char b[]){
//	if(strlen(a)!=strlen(b))
//		return 1;
//	else{J. K. Rowling
		for(int i=0;i<strlen(b);i++){
			if(toupper(a[i])!=toupper(b[i]))
				return 1;
		}
//	}
	return 0;
}

class date{public:
	int d, m, y;
};
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

//	Function Definition

// 1. Sell Book function
class SellBook{
	public:
		void sellBook(){
			int n,id,total=0;
			cout<<"How many books you want to sell: ";
			cin>>n;
			for(int i=1;i<=n;i++){
				cout<<"Enter Id of book "<<i<<": ";
				cin>>id;
				fstream f1,f2;
				Book b1;
				f1.open("book_info1.dat",ios::binary|ios::in);
				f2.open("temp.dat",ios::binary|ios::out);
				while(f1.read((char*)&b1,sizeof(b1))){
					if(b1.bookId==id){
						b1.quantity-=1;
						cout<<"\nUpdated details of "<<"'"<<b1.name<<"'"<<": "<<endl;
						cout<<"Quantitly left: "<<b1.quantity<<endl;
						cout<<"Selling Price: "<<b1.sp<<endl<<endl;
						total+=b1.sp;
					}
					f2.write((char*)&b1,sizeof(b1));
				}
				f1.close();
				f2.close();
				remove("book_info1.dat");
				rename("temp.dat","book_info1.dat");
			}
			cout<<"Total amount: "<<total<<endl;
			cout<<"GST: "<<0.12*(float)total<<endl;
			cout<<"Total payable amount: "<<total+(0.12*(float)total)<<endl<<endl;
		}
		
};

// Find Book

//2.1 using category..
class FindCat{
	public:
		void findCat(char s[]){
			Book b1;
			int count=0;
			fstream f1;
			f1.open("book_info1.dat",ios::binary|ios::in);
			cout<<endl<<"Books available: \n\n";
			while(f1.read((char*)&b1,sizeof(b1))){
				if((!Search(b1.category,s))&&b1.quantity!=0){
					count++;
					cout<<count<<".  "<<"Name: "<<b1.name<<endl<<"     Author: "<<b1.author<<endl<<"     Category: "<<b1.category<<endl<<"     Shelf No. : "<<b1.shelfNo<<endl<<"     Price: "<<b1.sp<<endl<<"\n"<<endl;
					
				}
			}
			if(count==0)
				cout<<"<Empty set>\n"<<endl;
			f1.close();
		}
		
};


//2.2 using name..
class FindName{
	public:
	void findName(char s[]){
		//public:
		Book b1;
		fstream f1;
		int count=0;
		f1.open("book_info1.dat",ios::binary|ios::in);
		cout<<endl<<"Books available: \n\n";
		while(f1.read((char*)&b1,sizeof(b1))){
			if(!Search(b1.name,s)){
				count++;
				cout<<count<<".  "<<"Name: "<<b1.name<<endl<<"      Author: "<<b1.author<<endl<<"      Category: "<<b1.category<<endl<<"      Shelf No. : "<<b1.shelfNo<<endl<<"      Price: "<<b1.sp<<endl<<"\n"<<endl;
				if(b1.quantity==0){
					cout<<"      Next arrival date: "<<b1.next_arr.d<<"-"<<b1.next_arr.m<<"-"<<b1.next_arr.y<<endl<<endl;
				}
			}
		}
		if(count==0)
			cout<<"Not found\n\n";
		f1.close();
	}
};


//2.3 using author..
class FindAuthor{
	public:
		void findAuthor(char s[]){
			Book b1;
			int count=0;
			fstream f1;
			f1.open("book_info1.dat",ios::binary|ios::in);
			cout<<endl<<"Books available: \n\n";
			while(f1.read((char*)&b1,sizeof(b1))){
				if((!Search(b1.author,s))&&b1.quantity!=0){
					count++;
					cout<<count<<".  "<<"Name: "<<b1.name<<endl<<"    Author: "<<b1.author<<endl<<"    Category: "<<b1.category<<endl<<"    Shelf No. : "<<b1.shelfNo<<endl<<"    Price: "<<b1.sp<<endl<<"\n"<<endl;
				}
			}
			if(count==0)
				cout<<"<Empty set>\n\n";
			f1.close();
		}
};


//2.4 using shelfNo..
class FindShelf{
	public:
		void findShelf(int i){
			Book b1;
			int count=0;
			fstream f1;
			f1.open("book_info1.dat",ios::binary|ios::in);
			cout<<"Books available in shelf "<<i<<" are: \n\n";
			while(f1.read((char*)&b1,sizeof(b1))){
				if(b1.shelfNo==i&&b1.quantity!=0){
					count++;
					cout<<count<<".  "<<"Name: "<<b1.name<<endl<<"    Author: "<<b1.author<<endl<<"    Category: "<<b1.category<<endl<<"    Price: "<<b1.sp<<endl<<"\n"<<endl;
				}
			}
			if(count==0)
				cout<<"<Empty set>\n\n";
			f1.close();
		}
};


//2. Find book function
class FindBook: public FindCat, public FindName, public FindAuthor, public FindShelf{
	public:
		vector<string> cat,auth;
		void findBook(){
			int c,i;
			char s[100];
			cout<<"1. Find book by Category\n2. Find book by Name\n3. Find book by Author's Name\n4. Find book by shelf no.\n";
			cin>>c;
			switch(c){
				case 1:{
					cout<<"Categories:\n";
					for(int i=0;i<cat.size();i++){
						cout<<cat[i]<<endl;
					}
					cout<<"\nEnter category of the book: ";
					cin>>s;
					findCat(s);
					break;
				}
				case 2:{
					cin.ignore(256,'\n');
					cout<<"Enter name of the book: ";
					gets(s);
					findName(s);
					break;
				}
				case 3:{
					cout<<"Authors:\n\n";
					for(int i=0;i<auth.size();i++){
						cout<<i<<") "<<auth[i]<<endl;
					}
					cin.ignore(256,'\n');
					cout<<"\nEnter the Author's name: ";
					gets(s);
					findAuthor(s);
					break;
				}
				case 4:{
					cout<<"Enter Shelf No. : ";
					cin>>i;
					findShelf(i);
					break;
				}
				default:{
					cout<<"Enter a valid choice.\n";
					//findBook();
					break;
				}
			}
		}
		
};


//3.1 addold..
class AddOld{
	public:
		int addOld(int id){
			int q,flag=0;
			cout<<"Enter quantity of the book: ";
			cin>> q;
			fstream f1,f2;
			f1.open("book_info1.dat",ios::binary|ios::in);
			f2.open("temp.dat",ios::binary|ios::out);
			Book b1;
			while(f1.read((char*)&b1,sizeof(b1))){
				if(b1.bookId==id){
					flag=1;
					b1.quantity+=q;
					cout<<"\nUpdated details of "<<"'"<<b1.name<<"'"<<": "<<endl;
					cout<<"Quantitly left: "<<b1.quantity<<endl;
					cout<<"Cost Price: "<<b1.cp*q<<endl<<endl;
				}
				f2.write((char*)&b1,sizeof(b1));
			}
			f1.close();
			f2.close();
			remove("book_info1.dat");
			rename("temp.dat","book_info1.dat");
			if(flag==0){
				cout<<"\nThis book is not already listed.\nFirst list the book.\n\n";
			}
			return flag;
		}
		
};


//3.2 addNew..
class AddNew{
	public:
		int addNew(int temp){
			Book b1;
			int error=0;
			fstream f;
			f.open("book_info1.dat",ios::binary|ios::in);
			while(f.read((char*)&b1,sizeof(b1))){
				if(b1.bookId==temp){
					error=1;
					break;
				}
			}
			f.close();
			if(error==0){
				b1.getdata(temp);
				f.open("book_info1.dat",ios::binary|ios::app);
				f.write((char*)&b1,sizeof(b1));
				cout<<endl<<"New book details: \n\n";
				b1.showDetails();
				cout<<endl;
				f.close();
//				listcat();
//				listauth();
			}
			else
				cout<<"\nThis id already exist.\n\n";
			return error;
		}
};


//3 Refill stock function
class RefillStock: public AddOld, public AddNew{
	public:
		void refillStock(){
			int x,n,id;
			cout<<"Enter no. of Lotts: ";
			cin>>n;
			while(n--){
			
				cout<<"1. For already listed book\n2. For new listing\n";
				cin>>x;
				switch(x){
					case 1:{
						cout<<"Enter book id: ";
						cin>>id;
						int temp = addOld(id);
						if(temp==0)
							n++;
						break;
					}
					case 2:{
						int temp;
						cout<<"Enter book id:\n";
						cin>>temp;
						addNew(temp);
						if(temp==1)
							n++;
						break;
					}
					default:{
						cout<<"Enter a valid choice.\n";
						n++;
						break;
					}
				}
			}
		}
};


//4. list book function
class ListBooks{
	public:
		void listBooks(){
			fstream f;
			f.open("book_info1.dat",ios::binary|ios::in);
			Book b1;
			int i=1;
			cout<<"\nBooks available: \n\n";
			while(f.read((char*)&b1,sizeof(b1))){
				cout<<i<<".  "<<"Book id: "<<b1.bookId<<endl<<"      Name: "<<b1.name<<endl<<"      Author: "<<b1.author<<endl<<"      Category: "<<b1.category<<endl<<"      Shelf No. : "<<b1.shelfNo<<endl<<"      Price: "<<b1.sp<<endl<<"\n"<<endl;
				i++;
			}
		}
		
};
//check updated book while running

class Options: protected SellBook, protected FindBook , public ListBooks, private RefillStock{
	public:
		void listcat(){
			fstream f;
			string s;
			Book b1;
			f.open("book_info1.dat",ios::binary|ios::in);
			while(f.read((char*)&b1,sizeof(b1))){
				s=b1.category;
				int flag=0;
				for(int i=0;i<cat.size();i++){
					if(StrCmp(s,cat[i])){
						flag=1;
						break;
					}
				}
				if(flag==0){
					cat.push_back(s);
				}
			}
			sort(cat.begin(),cat.end());	
		}
	void listauth(){
		fstream f;
		string s;
		Book b1;
		f.open("book_info1.dat",ios::binary|ios::in);
		while(f.read((char*)&b1,sizeof(b1))){
			s=b1.author;
			int flag=0;
			for(int i=0;i<auth.size();i++){
				if(StrCmp(s,auth[i])){
					flag=1;
					break;
				}
			}
			if(flag==0){
				auth.push_back(s);
			}
		}
		sort(auth.begin(),auth.end());	
	}
	Options(){
		listauth();
		listcat();
	}
	void run(){
		
		Book b;
		int x=1;
		char c;
		cout<<"\nBOOK STORE MANAGEMENT SYSYTEM\n\n";
		cout<<"Welcome Ma'am,\n\n";
		while(x){
			listcat();
			listauth();
			cout<<"1. Sell a book\n2. Find a book\n3. Refill Stock\n4. To list all books\n5. To exit\n";
	//		cin.ignore(256,'\n');

			cin>>c;
			switch(c){
				case '1':{
					sellBook();
					break;
				}
				case '2':{
					findBook();
					break;
				}
				case '3':{
					refillStock();
					break;
				}
				case '4':{
					listBooks();
					break;
				}
				case '5':{
					x=0;	
					break;
				}
				default:{
					cout<<"Enter a valid choice.\n";
					break;
				}
			}
		}
	}
}; 
//char cat[100][100];

int main(){
	Options a;
	a.run();
	
}

