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

// Fungsi untuk menampilkan semua order
void tampilkanOrder() {
    if (head == nullptr) {
        cout << "Belum ada order yang masuk.\n";
        return;
    }

    cout << "\n--- Daftar Order Komisi Desain ---\n";
    Order* temp = head;
    while (temp != nullptr) {
        cout << "ID: " << temp->id << endl;
        cout << "Nama Klien: " << temp->namaKlien << endl;
        cout << "Jenis Desain: " << temp->jenisDesain << endl;
        cout << "Deskripsi: " << temp->deskripsi << endl;
        cout << "Harga: Rp " << temp->harga << endl;
        cout << "-------------------------------\n";
        temp = temp->next;
    }
}
// Variabel global untuk menyimpan semua order
vector<Order> daftarOrder;
int nextId = 1;

    int main() {

    return 0;
}