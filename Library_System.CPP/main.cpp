#include <iostream>

#include<algorithm>
using namespace std;
   const int Max=100 ;
        int adder = 0 ;
        int cont = 0 ;
        int add_borrow=0 ;

  struct book{
   int id ;
   string name_book ;
   int quantity ;
   int borrowed ;
   book(){
    id=0 ;  name_book=""; quantity=0; borrowed=0 ;

   }
   void Read(){
       cout<<"Enter book info : id & name & quantity \n ";
       cin >> id >> name_book >> quantity ; borrowed=0 ;
       return ;
   }
 void print(){

        cout<<"Id book = "<<id <<"  Name book= "<< name_book<<" total_quantity = " << quantity ;
       cout<<" total_borrowed = "<< borrowed <<"\n";
 }

 void search_book(string str ){
     int str_len = str.size();
     if( str == name_book.substr(0 , str_len ) )
        cout<<name_book<<"\n";
     return ;
 }

 void print_id(){
     cout<<id<<endl;
 }

  };

  book book_arr[Max] ;
//----------------------------------------------------------------------------------

 struct user{
    string name ;
    int id_user ;
    user(){
    name=" ";
     id_user =0  ;
    }
 void Read_user(){
     cin >> name >> id_user ;
    }
 void print_the_users(){
    cout<<"Name :"<<name<<"  Id ="<<id_user ;
    }



   };

 //------------------------------------------------------------------------------------------
user user_arr[Max] ;

 struct  borrow_return {

 string name_user ;
 string name_book ;

 borrow_return(){
  name_user =" " ;
  name_book =" ";
 }

 void add( string name_us ,string  name_bo ){
 name_user = name_us ;
 name_book = name_bo ;
 }

 void print_book(){
    cout<<name_book ;
 }



 };

 borrow_return borr_arr[Max];
 //----------------------------------------------------------------------------------------


 void user_borrow_book(){
     cout<<"Enter The Name user & Name book \n" ;
  string name_us ;
  string name_bo ;
 cin >>name_us >> name_bo ;
  bool ch= true ;
  int z=0 ;

 for( int i=0 ; i < cont ; i++ ){
    if( user_arr[i].name == name_us )
        ch= false ;
 }
  if( ch == true|| cont==0 ){
         cout<<" The name user is not There in the system \n  "<<cont<<"\n";
          return ;
  }

  for( int i=0 ; i < adder ; i++){
      if( book_arr[i].name_book == name_bo )
        z=i ;
        ch= false ;
 }
   if( ch == true || adder== 0 ){
            cout<<" The name BOOK is not There in the system \n";
             return ;
   }

   if(  book_arr[z].quantity  <=   book_arr[z].borrowed  ){
    cout<<" The library is empty now from book "<<name_bo<<"\n";
     return ;
   }
    book_arr[z].borrowed+=1 ;
    borr_arr[add_borrow++].add( name_us , name_bo ) ;

    return ;
  }

 void user_return_book(){

 cout<<"Enter the name USER & name BOOK \n";
 string user , book ;
 cin >> user >> book ;

 bool ch= false ;
 for( int i=0 ; i < add_borrow ; i++ ){
    if( borr_arr[i].name_user == user && borr_arr[i].name_book == book ){
        ch=true ;
        book_arr[i].borrowed-- ;
        for( int j=i+1 ; j < add_borrow ; j++ ){
             borr_arr[j-1].name_user =  borr_arr[j].name_user ;
             borr_arr[j-1].name_book = borr_arr[j].name_book ;
        }
        if( ch == true ){
             add_borrow-- ;


        }
    }

 }

 }

  void add_user(){
    cout<<" Enter the Name & Id to user \n";
    user_arr[cont++].Read_user() ;
  }

  void  print_users(){                                             // work Here
     for( int j=0 ; j < cont ; j++ ){
       user_arr[j].print_the_users();
       for( int j=0 ; j < add_borrow ; j++){
       if(  user_arr[j].name ==  borr_arr[j].name_user )
        cout<< "  borrowed book : " ;
          borr_arr[j].print_book();
       }
        cout<<"\n";
    }

   cout<<"\n";
  }

   int choice(){
    int n ;
   cout<<" 1 ) add book . \n";
   cout<<" 2 ) search book by prefix . \n" ;
   cout<<" 3 ) print who borrowed book by name .\n" ;
   cout<<" 4 ) Print library by id .\n ";
   cout<<"5 ) print library by name .\n ";
   cout<<"6 ) add used .\n" ;
   cout<<" 7 ) user borrowed book .\n" ;
   cout<<" 8 ) user return book.\n" ;
   cout<<" 9 ) print users.\n ";
   cout<<"10) Exit .\n";

   cout<<"Enter your menu choice[ 1 - 10 ] .\n" ;
   cin >> n ;

   if(  n <= 0 ||  n  > 10   ){
        cout<< "       The number is false \n\n\n  " ;
    choice() ;

   }
     return n ;
   }

 void print_users_borrow_book(){
  cout<<"Enter the name book : \n" ;
    string s ;
    cin >> s ;
     for( int i=0 ; i < add_borrow ; i++ ){
    if( borr_arr[i].name_book ==  s  )
        cout<<borr_arr[i].name_user<<"\n";
 }
    return ;

 }
  void add_book(){


   book_arr[adder++].Read();
}

void  Print_library_by_id(){

 for( int i=0 ; i < adder ; i++ ){
    for( int j= i ; j < adder ; j++ ){
        if( book_arr[i].id  >  book_arr[j].id )
        swap( book_arr[i] , book_arr[j] ) ;
    }
 }
 cout<<"------------------\n";
 for( int i=0 ; i < adder ; i++){

  book_arr[i].print();
 }
 cout<<"------------------\n";
   return ;
}
void Print_library_by_name(){

 for( int i=0 ; i < adder ; i++ ){
    for( int j= i ; j < adder ; j++ ){
        if( book_arr[i].name_book  >  book_arr[j].name_book )
        swap( book_arr[i] , book_arr[j] ) ;
    }
 }
 cout<<"------------------\n";
 for( int i=0 ; i < adder ; i++){

  book_arr[i].print();
 }
 cout<<"------------------\n";
   return ;
}

 void search_book_by_prefix() {

 cout<<"\n\n";
 cout<<"Enter the name of book \n" ;
 string s ;
 cin >> s ;
 for(int i=0 ; i < adder ; i++ )
     book_arr[i].search_book( s );

     return ;
 }

void hospital_system() {
      while( true ){
      int x = choice() ;
      if( x == 1)
      add_book();
      else if( x == 2)
      search_book_by_prefix() ;
      else if( x== 4)
      Print_library_by_id();
      else if( x==5 )
      Print_library_by_name();
      else if(x == 6)
        add_user();
      else if( x == 9 )
        print_users();
        else if( x == 10)
            break;
        else if( x== 7)
        user_borrow_book();
        else if(x == 3)
            print_users_borrow_book();
            else if( x == 8)
                user_return_book();

       }
   }


int main()
{

  hospital_system();
    return 0;
}
