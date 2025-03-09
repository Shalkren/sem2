#include <iostream>
#include <vector>
using namespace std;

class hash_map{
    private:
    int size;
    vector<pair<int,long long>> table;
    int midsquarefuncHash(int n){
        long long num=n*n;
        if(num<=10000){
            return int(num);
        }
        return (num-num%10000)%10000;
    }
    int getIndex(const int& key ) const{

    }
}

int main(){
    return 0;
}