#include <fstream>
#include <string>
using namespace std;

#define maxEntries 100000

struct Entry{
    string key;
    string value;
};

Entry store[maxEntries]; //aray for storing entries
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

//load database
void loadDatabase(){
    ifstream file("data.db");
    if(!file.is_open()){
        return; //no file yet
    }
    string command, key, value;
    while(file >> command >> key){ //read command and key
        getline(file, value);
        if(!value.empty() && value[0] == ' '){
            value = value.substr(1); //get rid of the space between command and other inputs
        }
        if(command == "SET"){
            setKey(key, value);
        }
    }
    file.close();
}

//save to database
void saveToDatabase(string key, string value){
    ofstream file;
    file.open("data.db", ios::app); //ios:app is for appending
    if(file.is_open()){
        file << "SET " << key << " " << value << "\n";
        file.close();
    }
}

int main(){
    //Nothing here yet
    return 0;
}
