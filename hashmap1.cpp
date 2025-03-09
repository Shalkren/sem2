#include <iostream>
#include <vector>
#include <string>
using namespace std;

class hash_map{
    private:
    int size;
    const double loadFactor = 0.75;
    int count=0;
    vector<pair<int,int>> table;
    int midsquarefuncHash(int key){
        long long squared = static_cast<long long>(key) * key;
        string squaredStr = to_string(squared);
        int length = squaredStr.length();
        int start = (length - size) / 2;
        int end = start + size;
        if (length < size) {
            squaredStr.insert(0, size - length, '0');
            start = 0;
            end = size;
        }
        string midDigits = squaredStr.substr(start, size);
        int hashValue = stoi(midDigits);
    
        return hashValue;
    }
    int getIndex(const int& key){
        int h = midsquarefuncHash(key);
        int i = h % size;
        while (true) {
            if (table[i].first == key && table[i].second == h) {
                return i;
            }
            if (table[i].first == -1) {
                return -1;
            }
            i = (i + 1) % size;
            if (i == h % size) break;
        }
        return -1;
    }
    int getIndex1(const int& key) {
        int h = midsquarefuncHash(key);
        int i = h % size;
        int startIndex = i;
        do{
            if (table[i].first == key) {
                return i;
            }
            if (table[i].first == -1 && table[i].second == -1) {
                return i;
            }
            i = (i + 1) % size;
        }while (i != h % size); 
        rehash();
        return getIndex1(key);
    }
    bool brehash() {
        return count / size >= loadFactor;
    }
    void rehash() {
        int newSize = size * 2;
        vector<pair<int, int>> newTable(newSize, {-1, -1});
        for (const auto& entry : table) {
            if (entry.first != -1) {
                int h = midsquarefuncHash(entry.first);
                int i = h % newSize;
                while (newTable[i].first != -1) {
                    i = (i + 1) % newSize;
                }
                newTable[i] = entry;
            }
        }
        table = move(newTable);
        size = newSize;
    }
    public:
    // Конструкторы
    hash_map(int initSize = 8) : size(initSize), table(initSize, {-1, -1}) {}
    ~hash_map(){}

    // Основные операции
    void insert(const int& key){
        if (brehash()) {
            rehash();
        }
        int h = midsquarefuncHash(key);
        int index = getIndex1(key);
        table[index] = {key, h};
        count++;
    } // Вставка элемента
    bool remove(const int& key) {
        int index = getIndex(key);
        if (index>=0 && table[index].first == key) {
            table[index] = {-1, -1};
            count--;
            return true;
        }
        return false;
    } // Удаление элемента
    bool find(const int& key){
        return getIndex(key) != -1;
    } // Поиск элемента
    void clear(){
        for(int i=0;i<size;i++){
            table[i]={-1,-1};
        }
        count=0;
    }// Очистка таблицы

    // Дополнительные методы
    int hsize() const{
        return count;
    } // Количество элементов в таблице
    bool isEmpty() const{
        if(count==0){
            return true;
        }
        return false;
    } // Проверка на пустоту
    void print() const{
        if(isEmpty()){
            return;
        }
        for(auto& x : table){
            if(x.second!=-1){
                cout<<"key: "<<x.first<<" value: "<<x.second<<"\n";
            }
        }
    } // Вывод таблицы

};

int main(){
    hash_map a(4);
    for(int i=0;i<15;i++){
        a.insert(i);
    }
    a.print();
    return 0;
}
