// words2.cpp - implements class Words
// (dynamic array version)
// Emma Simmons, 10/25/18


#include <cassert>
#include <string>

#include "words2.h"

using std::string;


namespace lab04_2
{
    Words::Words(unsigned int x) {
        used = 0;
        capacity = x;
	data= new string[capacity];
	
    }
    
    Words::Words(const Words &source){
	    used=source.size();
	    capacity=source.get_capacity();
	    data= new string[capacity];
            for (int i=0; i< used; i++){
		    data[i]=source[i];
	    }
	
    }
    Words& Words::operator=(const Words &source){
	
	    std::string *new_data;
	    if(this==&source)
		    return *this;
	    if(capacity != source.get_capacity()){
			    new_data= new string[source.get_capacity()];
			    delete [] data;
			    data= new_data; 
			    capacity= source.get_capacity();}

			    used=source.size();
			    for (int i=0; i< used; i++){
                           	 data[i]=source[i];
				 }	 
   return *this; 
   }



    void Words::append(string word) {
        if (used==capacity){
		std::string* bigger_array=new string[capacity*2];
		copy(data, data+used, bigger_array);
		delete [] data;
		data=bigger_array;
		capacity=capacity*2;
	}
	
        data[used] = word;
        ++used;
    }
    

    string& Words::operator[] (unsigned int index) {
        assert(index < used);
        return data[index];
    }
    
    unsigned int Words::size() const {
        return used;
    }
    
    unsigned int Words::get_capacity() const {
        return capacity;
    }
    
    string Words::operator[] (unsigned int index) const {
        assert(index < used);
        return data[index];
    }

    Words::~Words() {
    delete [] data;
    }
}


