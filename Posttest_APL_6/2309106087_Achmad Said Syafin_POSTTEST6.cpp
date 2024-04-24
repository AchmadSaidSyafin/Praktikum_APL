#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
using namespace std;

// Struktur data untuk roti
struct Roti {
    string nama;
    int harga;
};

// Struktur data untuk pesanan
struct Pesanan {
    string namaRoti;
    int jumlah;
};

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << "=========== Menu Toko Roti Mak Iwan ===========" << endl;
    cout << "1. Tampilkan Semua Roti" << endl;
    cout << "2. Tambah Roti Baru" << endl;
    cout << "3. Ubah Harga Roti" << endl;
    cout << "4. Hapus Roti" << endl;
    cout << "5. Pesan" << endl;
    cout << "6. Keluar" << endl;
    cout << "7. Diurut dari A-Z" << endl;
    cout << "8. Diurt dari angka terbesar" << endl;
    cout << "9. Diurut dari Z-A" << endl;
    cout << "10. Cari dari A-Z" << endl;
    cout << "11. Cari dari Z-A" << endl;
    cout << "Pilih opsi (1-11): ";
}

// Fungsi untuk mengurutkan nama roti secara ascending
void sortNamaRotiAscending(vector<Roti>& daftarRoti) {
    sort(daftarRoti.begin(), daftarRoti.end(), [](const Roti& a, const Roti& b) {
        return a.nama < b.nama;
    });
}

// Fungsi untuk mengurutkan harga roti secara descending
void sortHargaRotiDescending(vector<Roti>& daftarRoti) {
    sort(daftarRoti.begin(), daftarRoti.end(), [](const Roti& a, const Roti& b) {
        return a.harga > b.harga;
    });
}

// Fungsi untuk mengurutkan nama roti secara descending
void sortNamaRotiDescending(vector<Roti>& daftarRoti) {
    sort(daftarRoti.begin(), daftarRoti.end(), [](const Roti& a, const Roti& b) {
        return a.nama > b.nama;
    });
}

void searchNamaRotiAscending(const vector<Roti>& daftarRoti, const string& namaRoti) {
    auto iter = find_if(daftarRoti.begin(), daftarRoti.end(), [&](const Roti& roti) {
        return roti.nama == namaRoti;
    });
    if (iter != daftarRoti.end()) {
        cout << "Roti ditemukan: " << iter->nama << ", Harga: " << iter->harga << endl;
    } else {
        cout << "Roti tidak ditemukan." << endl;
    }
}

void searchNamaRotiDescending(const vector<Roti>& daftarRoti, const string& namaRoti) {
    auto iter = find_if(daftarRoti.rbegin(), daftarRoti.rend(), [&](const Roti& roti) {
        return roti.nama == namaRoti;
    });
    if (iter != daftarRoti.rend()) {
        cout << "Roti ditemukan: " << iter->nama << ", Harga: " << iter->harga << endl;
    } else {
        cout << "Roti tidak ditemukan." << endl;
    }
}

void tampilkanSemuaRoti(const vector<Roti>& daftarRoti) {
    if (daftarRoti.empty()) {
        cout << "Tidak ada roti tersedia." << endl;
        return;
    }
    cout << "=========== Daftar Roti ===========" << endl;
    for (const Roti& roti : daftarRoti) {
        cout << "Nama: " << roti.nama << ", Harga: " << roti.harga << endl;
    }
}

void tambahRoti(vector<Roti>* daftarRoti) {
    Roti roti;
    cout << "Masukkan nama roti: ";
    cin.ignore();
    getline(cin, roti.nama);
    cout << "Masukkan harga roti: ";
    cin >> roti.harga;
    daftarRoti->push_back(roti);
    cout << "Roti berhasil ditambahkan." << endl;
}

void ubahHargaRoti(vector<Roti>* daftarRoti) {
    string namaRoti;
    int hargaBaru;
    cout << "Masukkan nama roti yang ingin diubah harganya: ";
    cin.ignore();
    getline(cin, namaRoti);
    cout << "Masukkan harga baru: ";
    cin >> hargaBaru;
    for (Roti& roti : *daftarRoti) {
        if (roti.nama == namaRoti) {
            roti.harga = hargaBaru;
            cout << "Harga roti berhasil diubah." << endl;
            return;
        }
    }
    cout << "Roti tidak ditemukan." << endl;
}

void hapusRoti(vector<Roti>* daftarRoti) {
    string namaRoti;
    cout << "Masukkan nama roti yang ingin dihapus: ";
    cin.ignore();
    getline(cin, namaRoti);
    for (auto iter = daftarRoti->begin(); iter != daftarRoti->end(); ++iter) {
        if (iter->nama == namaRoti) {
            iter = daftarRoti->erase(iter);
            cout << "Roti berhasil dihapus." << endl;
            return;
        }
    }
    cout << "Roti tidak ditemukan." << endl;
}

void pesananRoti(vector<Roti>* daftarRoti) {
    string namaRoti;
    int jumlah;
    cout << "Masukkan nama roti yang ingin dipesan: ";
    cin.ignore();
    getline(cin, namaRoti);
    cout << "Masukkan jumlah roti yang ingin dipesan: ";
    cin >> jumlah;
    cout << endl;
    cout << "Roti yang dipesan: " << namaRoti << endl;
    cout << "Jumlah pesanan: " << jumlah << endl;
    for (Roti& roti : *daftarRoti){
        if (roti.nama == namaRoti){
            cout <<"Berhasil dipesan" << endl;
            return;
        }
    }
    cout <<"Roti tidak ditemukan" << endl;
}

int main() {
    string nama, nim;
    int percobaan = 0;
    const int maks_percobaan = 3;

    // Loop untuk melakukan login
    while (percobaan < maks_percobaan) {
        // Input nama dan NIM
        cout << "===== L O G I N =====" << endl;
        cout << "Masukkan Nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;

        // Cek login
        if (nama == "Avin" && nim == "087") {
            cout << "Login Berhasil!\n";
            break; // Keluar dari loop jika login berhasil
        } else {
            percobaan++;
            cout << "Login Gagal! Silakan coba lagi.\n";
            if (percobaan == maks_percobaan) {
                cout << "Anda telah mencoba login sebanyak 3 kali. Program berhenti.\n";
                return 0; // Berhenti program setelah 3 kali percobaan
            }
        }
    }

    vector<Roti> daftarRoti = {
        {"white bread", 5000},
        {"sweet bread", 6000},
        {"cake", 15000},
        {"donut", 3000},
        {"cookies", 4000},
        {"brownies", 7000},
        {"croissant", 10000}
    };

    int pilihan;

    do {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanSemuaRoti(daftarRoti);
                break;
            case 2:
                tambahRoti(&daftarRoti);
                break;
            case 3:
                ubahHargaRoti(&daftarRoti);
                break;
            case 4:
                hapusRoti(&daftarRoti);
                break;
            case 5:
                pesananRoti(&daftarRoti);
                break;
            case 6:
                cout << "Program selesai." << endl;
                break;
            case 7:
                sortNamaRotiAscending(daftarRoti);
                break;
            case 8:
                sortHargaRotiDescending(daftarRoti);
                break;
            case 9:
                sortNamaRotiDescending(daftarRoti);
                break;
            case 10:
                {
                    string namaRoti;
                    cout << "Masukkan nama roti yang ingin dicari: ";
                    cin.ignore();
                    getline(cin, namaRoti);
                    searchNamaRotiAscending(daftarRoti, namaRoti);
                }
                break;
            case 11:
                {
                    string namaRoti;
                    cout << "Masukkan nama roti yang ingin dicari: ";
                    cin.ignore();
                    getline(cin, namaRoti);
                    searchNamaRotiDescending(daftarRoti, namaRoti);
                }
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }

    } while (pilihan != 6);

    return 0;
}
