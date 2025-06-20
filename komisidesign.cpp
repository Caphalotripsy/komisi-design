#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//Caphalotripsy STARTLINE
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

//Fungsi Bantuan #include <algorithm> untuk membaca string ke huruf kecil semua
string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Fungsi Bantuan memformat jenis desain jadi kapital di awal
string formatJenisDesain(string input) {
    string jenis = toLowerCase(input);

    if (jenis == "logo") return "Logo";
    else if (jenis == "poster") return "Poster";
    else if (jenis == "ilustrasi") return "Ilustrasi";
    else return input;  // Kembalikan apa adanya jika tidak dikenali
}

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
        cout << "Nomor Pesanan : " << temp->id << endl;
        cout << "Nama Klien    : " << temp->namaKlien << endl;
        cout << "Jenis Desain  : " << temp->jenisDesain << endl;
        cout << "Deskripsi     : " << temp->deskripsi << endl;
        cout << "Harga         : Rp " << temp->harga << endl;
        cout << "-------------------------------\n";
        temp = temp->next;
    }
}

// Fungsi untuk menampilkan order berdasarkan jenis desain
void tampilkanOrderByJenis(const string& jenisFormatted) {
    bool ditemukan = false;
    Order* temp = head;

    cout << "\n--- Daftar Order Jenis Desain: " << jenisFormatted << " ---\n";
    while (temp != nullptr) {
        if (temp->jenisDesain == jenisFormatted) {
            cout << "Nomor Pesanan : " << temp->id << endl;
            cout << "Nama Klien    : " << temp->namaKlien << endl;
            cout << "Deskripsi     : " << temp->deskripsi << endl;
            cout << "Harga         : Rp " << temp->harga << endl;
            cout << "-------------------------------\n";
            ditemukan = true;
        }
        temp = temp->next;
    }

    if (!ditemukan) {
        cout << "Belum ada order untuk desain " << jenisFormatted << ".\n";
    }
}

void tampilkanOrderLogo() {
    tampilkanOrderByJenis("Logo");
}

void tampilkanOrderPoster() {
    tampilkanOrderByJenis("Poster");
}

void tampilkanOrderIlustrasi() {
    tampilkanOrderByJenis("Ilustrasi");
}
//Caphalotripsy ENDLINE


//alifcdg STARTLINE
//Fungsi untuk menghapus order berdasarkan Nomor Pesanan
void hapusOrder() {
    int id;
    cout << "Masukkan Nomor Pesanan yang ingin dihapus: ";
    cin >> id;

    Order* temp = head;
    Order* prev = nullptr;

    while (temp != nullptr && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Order dengan Nomor Pesanan tersebut tidak ditemukan.\n";
        return;
    }

    if (prev == nullptr) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Order berhasil dihapus.\n";
}

// Fungsi utama
int main() {
    int pilihan;

    do {
        cout << "\n=== Menu Order Komisi Desain ===\n";
        cout << "1. Tambah Order\n";
        cout << "2. Lihat Semua Order\n";
        cout << "3. Lihat Order Desain Logo\n";
        cout << "4. Lihat Order Desain Poster\n";
        cout << "5. Lihat Order Desain Ilustrasi\n";
        cout << "6. Hapus Order\n";
        cout << "7. Keluar\n";
        cout << "Pilih menu (1-7): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahOrder();
                break;
            case 2:
                tampilkanOrder();
                break;
            case 3:
                tampilkanOrderLogo();
                break;
            case 4:
                tampilkanOrderPoster();
                break;
            case 5:
                tampilkanOrderIlustrasi();
                break;
            case 6:
                hapusOrder();
                break;
            case 7:
                cout << "Terima kasih Telah Menggunakan Aplikasi Ini.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }

    } while (pilihan != 7);

    return 0;
}
//alifcdg ENDLINE