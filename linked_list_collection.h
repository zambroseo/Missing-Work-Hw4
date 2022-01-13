# ifndef LINKED_LIST_COLLECTION_H
# define LINKED_LIST_COLLECTION_H

# include <vector>
# include <algorithm>
# include <iostream>
# include "collection.h"


template < typename K , typename V >
class LinkedListCollection : public Collection <K ,V >
{
 public :

// create an empty linked list
LinkedListCollection ();

// copy a linked list
LinkedListCollection(const LinkedListCollection <K ,V >& rhs );

// assign a linked list
LinkedListCollection <K ,V >& operator=( const LinkedListCollection <K ,V >& rhs );

// delete a linked list
 ~ LinkedListCollection ();

// insert a key - value pair into the collection
void insert(const K& key , const V& val );

// remove a key - value pair from the collection
void remove(const K& key );

// find the value associated with the key
bool find(const K& key , V& val ) const ;

// find the keys associated with the range
void find(const K& k1 , const K& k2 , std :: vector <K>& keys ) const ;

// return all keys in the collection
void keys(std :: vector <K >& keys ) const ;

// return collection keys in sorted order
void sort(std :: vector <K >& keys ) const ;

// return the number of keys in collection
int size() const ;

  private:
// linked list node structure
struct Node {
 K key ;
 V value ;
 Node* next ;
};

 Node* head ; // pointer to first list node
 Node* tail ; // pointer to last list node
 int length ; // number of linked list nodes in list
};



template<typename K, typename V>
LinkedListCollection<K, V>::LinkedListCollection()
{
 head = nullptr;
 tail = nullptr;
 length = 0;
}

template<typename K, typename V>
LinkedListCollection<K, V>::
LinkedListCollection(const LinkedListCollection<K, V>& rhs)
{
 Node* cur=rhs.head;
 while(cur != nullptr)
 {
   this->insert(cur->key, cur->value);
   cur=cur->next;
 }
}

template<typename K, typename V>
LinkedListCollection<K, V>& LinkedListCollection<K, V>
::operator=(const LinkedListCollection<K, V>& rhs)
{
 Node* temp=head;
 if(this == &rhs)
   return *this;
 while(temp->next!= nullptr)
 {
  head=head->next;
  delete temp;
  temp=head;
  length--;
 }
 temp=rhs.head;
 while(temp != nullptr)
 {
  this->insert(temp->key, temp->value);
  temp=temp->next;
 }
 return *this;
}

template<typename K, typename V>
LinkedListCollection<K, V>::~LinkedListCollection()
{
 Node* temp=head;
 while(temp != nullptr)
 {
  Node* next=temp->next;
  delete temp;
  temp=next;
 }
 head=nullptr;
}

template<typename K, typename V>
void LinkedListCollection<K, V>::insert(const K& key, const V& val)
{
 Node* ins=new Node;
 ins->key=key;
 ins->value=val;

 if(length == 0)
 {
  head=ins;
  tail=ins;
  ins->next=nullptr;
  this->length++;
 }
 else
 {
  tail->next=ins;
  ins->next=nullptr;
  tail=ins;
  length++;
 }
}

template<typename K, typename V>
void LinkedListCollection<K, V>::remove(const K& key)
{
 Node* prev=new Node;
 Node* cur=head;

 while(cur != nullptr)
 {
  if(cur->key == key)
  {
   prev->next=cur->next;
   delete cur;
   this->length--;
  }
  else
  {
   prev=cur;
   cur=cur->next;
  }
 }
}

template<typename K, typename V>
bool LinkedListCollection<K, V>::find(const K& key, V& val) const
{
 Node* temp=head;
 while(temp != nullptr)
 {
  if(temp->key == key)
  {
   val=temp->value;
   return true;
  }
  else {
    temp=temp->next;
  } 
 }
  return false;
}

template<typename K, typename V>
void LinkedListCollection<K, V>::find(const K& k1, const K& k2, std::vector<K>& keys) const
{
 Node* temp=head;
 while(temp != nullptr)
 {
  if(temp->key >= k1 && temp->key <= k2) {
   keys.push_back(temp->key);
  }
  temp=temp->next;
 }
}

template<typename K, typename V>
void LinkedListCollection<K, V>::keys(std::vector<K>& keys) const
{
 Node* cur=head;
 while(cur != nullptr)
 {
  keys.push_back(cur->key);
  cur=cur->next;
 }
}

template < typename K , typename V >
void LinkedListCollection <K ,V >:: sort( std :: vector <K >& keys ) const
{
 Node* ptr=head ;
 while(ptr != nullptr) 
 {
  keys.push_back(ptr->key);
  ptr=ptr->next ;
 }
 std :: sort(keys.begin() , keys.end());
}

template < typename K , typename V >
int LinkedListCollection<K,V> :: size() const{
  return length;
}


#endif
