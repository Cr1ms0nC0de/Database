#include <string>
using namespace std;

#define maxEntries 100000

struct Entry {
    string key;
    string value;
};

Entry store[maxEntries];
int storeSize = 0;

//find key
int findKey(string key){
    for(int i = 0; i < storeSize; i++){
        if(store[i].key == key){
            return i;
        }
    }
    return -1;
}

//set key
void setKey(string key, string value){
    int pos = findKey(key);
    if(pos != -1){
        store[pos].value = value; //update
    }
    else{
        store[storeSize].key = key;
        store[storeSize].value = value;
        storeSize++;
    }
}
//get key
string getKey(string key){
    int pos = findKey(key);
    if(pos != -1){
        return store[pos].value;
    }
    return "";
}


int main(){
    //Nothing here yet
    return 0;
}
