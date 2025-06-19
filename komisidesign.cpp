#include <iostream>
#include <string>

using namespace std;

//Struktur untuk menyimpan data order di dalam bentuk linked list
struct Order {
    int id;
    string namaKlien;
    string jenisDesain;
    string deskripsi;
    float harga;
    Order* next;
};

// Variabel global untuk menyimpan semua order
vector<Order> daftarOrder;
int nextId = 1;

    int main() {
        
    return 0;
}