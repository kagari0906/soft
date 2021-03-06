/* ex3 */
#include <iostream>
using namespace std;

class person{
public:
  string address;
  string name;
};

class addressbook{
  person friends[100];
  int numberOfFriends;
public:
  addressbook();
  void listFriends();
  void addFriend(string name,string address);
  void find(string query);
};

// constructor                                                                                                                                                
addressbook::addressbook(){
  numberOfFriends = 0;
}

void addressbook::addFriend(string n,string a){
  friends[numberOfFriends].name = n;
  friends[numberOfFriends].address = a;
  numberOfFriends++;
}

void addressbook::listFriends(){
  for(int i = 0; i < numberOfFriends; i++){
    cout << friends[i].name << " : ";
    cout << friends[i].address << "\n";
  }
}

void addressbook::find(string q){
  for(int i = 0; i < numberOfFriends; i++){
    if(friends[i].name == q){
      cout << friends[i].name << " : ";
      cout << friends[i].address << "\n";
      break;
    }
    if(i == numberOfFriends-1){
      cout << "return no_one\n";
      break;
    }
  }
}

int main()
{
  addressbook abook;
  string name;
  string address;
  string query;

  while(1){
  cout << "住所録に登録する名前を入力してください(終了するには quit と入力してください):";
  cin >> name;
  if(name == "quit"){break;}
  cout << "住所録に登録する住所を入力してください：";
  cin >> address;
  //  cout << "name.length() = " << name.length() << "\n";                                                                                                    
  abook.addFriend(name,address);
}

  cout << "検索する氏名を入力してください: ";
  cin >> query;

  cout << "\n名前リスト:\n";
  abook.find(query);
}

