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

// Pointer head linked list
Order* head = nullptr;
int nextId = 1;

// Fungsi untuk membuat node baru dan menambahkannya ke linked list
void tambahOrder() {
    Order* newOrder = new Order;
    newOrder->id = nextId++;
    cin.ignore();
    cout << "Nama Klien: ";
    getline(cin, newOrder->namaKlien);
    cout << "Jenis Desain (logo/poster/ilustrasi/dll): ";
    getline(cin, newOrder->jenisDesain);
    cout << "Deskripsi Singkat: ";
    getline(cin, newOrder->deskripsi);
    cout << "Harga (Rp): ";
    cin >> newOrder->harga;
    newOrder->next = nullptr;

    // Tambah ke akhir linked list
    if (head == nullptr) {
        head = newOrder;
    } else {
        Order* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newOrder;
    }

    cout << "Order berhasil ditambahkan!\n";
}

// Variabel global untuk menyimpan semua order
vector<Order> daftarOrder;
int nextId = 1;

    int main() {

    return 0;
}