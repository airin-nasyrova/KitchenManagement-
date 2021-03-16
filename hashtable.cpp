using namespace std;

#include<iostream>
#include "hashtable.h"

HashEntry::HashEntry(string key, string value) : key(key), value(value) {}
 
HashMap::HashMap() {
   table = new HashEntry * [TABLE_SIZE];
   for (int i = 0; i< TABLE_SIZE; i++)
   {
	   table[i] = NULL;
   }
}
     
HashMap::~HashMap() {
   for (int i = 0; i < TABLE_SIZE; i++) {
	   if (table[i] != NULL)
		   delete table[i];
	   delete[] table;
   }
}
int HashMap::hashFunc(string key) {
   return compute_hash(key) % TABLE_SIZE;
}
	   
void HashMap::insert(string key, string value) {
   int hash = hashFunc(key);
   while (table[hash] != NULL && table[hash]->key != key)
   {
	   cout << "\n**********" << "\nCollision!" << "\n***********" << endl;
	   hash++;
   }
   if (table[hash] != NULL)
	   delete table[hash];
   table[hash] = new HashEntry(key, value);
}
      
	  
bool HashMap::search(string key) {
	int  hash = hashFunc(key);
	while (table[hash] != NULL && table[hash]->key != key) {
		hash++;
	}
	if (table[hash] == NULL) {
		return false;
	} else {
		return true;
	}
}
 
void HashMap::remove(string key) {
	int hash = hashFunc(key);
	while (table[hash] != NULL) {
		if (table[hash]->key == key) {
			break;
		} else hash++;
	}
	if (table[hash] == NULL) {
	   cout<<"No Element found at key "<<key<<endl;
	   return;
	   }
	else {
	   delete table[hash];
	}
	cout<<"Element Deleted"<<endl;
}

void HashMap::removeAll(void) {
	for (int i = 0; i< TABLE_SIZE; i++) {
	   table[i] = NULL;
   }
}
       

long long HashMap::compute_hash(string const& s) {
	const int p = 31;
	const int m = 1e9 + 9;
	long long hash_value = 0;
	long long p_pow = 1;
	for (char c : s) {
		hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
		p_pow = (p_pow * p) % m;
	}
	return hash_value;
}