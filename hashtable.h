#include <iostream>
using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

const int TABLE_SIZE = 128;
 
/*
 * HashEntry Class Declaration
 */
class HashEntry{
   public:
       string key;
       string value;
       HashEntry(string key, string value);
};
 
/*
 * HashMap Class Declaration
 */
class HashMap {
   private:
		HashEntry **table;
   public:  
		HashMap();
     
		int hashFunc(string);
	   
		void insert(string, string);
      
	  
		bool search(string);
 
		void remove(string);
		
		void removeAll(void);
       
	   ~HashMap();

	long long compute_hash(string const&);
};

#endif