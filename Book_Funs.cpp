#include "Class_Book.cpp"

//	Class Book Function Definition
// 1. list book function
// 2. Sell Book function
// 3. Find book function
// 4. Refill stock function

//1. list book function
class ListBooks{
	public:	
		void listBooks(){
			fstream f;
			Book b1;
			f.open("book_info1.dat",ios::binary|ios::in);
			int i=1;
			cout<<"\nBooks available: \n\n";
			while(f.read((char*)&b1,sizeof(b1))){
				cout<<i<<".  "<<"Book id: "<<b1.bookId<<endl<<"      Name: "<<b1.name<<endl<<"      Author: "<<b1.author<<endl<<"      Category: "<<b1.category<<endl<<"      Shelf No. : "<<b1.shelfNo<<endl<<"      Price: "<<b1.sp<<endl<<"\n"<<endl;
				i++;
			}
		}		
};

// 1. Sell Book function
class SellBook{
	public:
		void sellBook(){
			int n,id,total=0;
			cout<<"How many books you want to sell: ";
			cin>>n;
			for(int i=1;i<=n;i++){
				cout<<"Enter Id of book no. "<<i<<": ";
				cin>>id;
				fstream f1,f2;
				Book b1;
				f1.open("book_info1.dat",ios::binary|ios::in);
				f2.open("temp.dat",ios::binary|ios::out);
				while(f1.read((char*)&b1,sizeof(b1))){
					if(b1.bookId==id){
						if(b1.quantity<1){
							cout<<"  Empty Stock\n";
							id=-1;
							cout<<"  Next arrival date: "<<b1.next_arr.d<<"-"<<b1.next_arr.m<<"-"<<b1.next_arr.y<<endl<<endl;
						}
						else{
							b1.quantity-=1;
							cout<<"\nUpdated details of "<<"'"<<b1.name<<"'"<<": "<<endl;
							cout<<"Quantitly left: "<<b1.quantity<<endl;
							cout<<"Selling Price: "<<b1.sp<<endl<<endl;
							total+=b1.sp;
							id=-1;
						}
					}
			
					f2.write((char*)&b1,sizeof(b1));
				}
				f1.close();
				f2.close();
				remove("book_info1.dat");
				rename("temp.dat","book_info1.dat");
				if(id!=-1){
					cout<<"\n<Error> This Book Id doesn't exist\n\n";
					i--;
				}
			}
			cout<<"Total amount of "<<n<<" books: "<<total<<endl;
			cout<<"GST: "<<0.12*(float)total<<endl;
			cout<<"Total payable amount: "<<total+(0.12*(float)total)<<endl<<endl;
		}
		
};

//3 Find Book

//3.1 using category..
class FindCat{
	public:
		vector<string> cat;
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


//3.2 using name..
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


//3.3 using author..
class FindAuthor{
	public:
		vector<string> auth;
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


//3.4 using shelfNo..
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


//3. Find book function
class FindBook: public FindCat, private FindName, protected FindAuthor, public FindShelf{
	public:
//		vector<string> cat,auth;
		void findBook(){
			int c,i;
			char s[100];
			cout<<"1. Find book by Category\n2. Find book by Name\n3. Find book by Author's Name\n4. Find book by shelf no.\n";
			cin>>c;
			switch(c){
				case 1:{
					cout<<"Categories:\n";
					for(int i=0;i<cat.size();i++){
						cout<<"  "<<cat[i]<<endl;
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
//					cout<<"Authors:\n\n";
//					for(int i=0;i<auth.size();i++){
//						cout<<i<<") "<<auth[i]<<endl;
//					}
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

//4 refill stock

//4.1 addold..
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
					cout<<"Cost Price of the stock: "<<b1.cp*q<<endl<<endl;
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


//4.2 addNew..
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


//4 Refill stock function
class RefillStock: protected AddOld, private AddNew{
	public:
		void refillStock(){
			int x,n,id,cost=0;
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



