#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Struktur data untuk roti
struct Roti {
    string nama;
    int harga;
};

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << "=========== Menu Toko Roti Mak Iwan ===========" << endl;
    cout << "1. Tampilkan Semua Roti" << endl;
    cout << "2. Tambah Roti Baru" << endl;
    cout << "3. Ubah Harga Roti" << endl;
    cout << "4. Hapus Roti" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih opsi (1-5): ";
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

void tambahRoti(vector<Roti>& daftarRoti) {
    Roti roti;
    cout << "Masukkan nama roti: ";
    cin.ignore();
    getline(cin, roti.nama);
    cout << "Masukkan harga roti: ";
    cin >> roti.harga;
    daftarRoti.push_back(roti);
    cout << "Roti berhasil ditambahkan." << endl;
}

void ubahHargaRoti(vector<Roti>& daftarRoti) {
    string namaRoti;
    int hargaBaru;
    cout << "Masukkan nama roti yang ingin diubah harganya: ";
    cin.ignore();
    getline(cin, namaRoti);
    cout << "Masukkan harga baru: ";
    cin >> hargaBaru;
    for (Roti& roti : daftarRoti) {
        if (roti.nama == namaRoti) {
            roti.harga = hargaBaru;
            cout << "Harga roti berhasil diubah." << endl;
            return;
        }
    }
    cout << "Roti tidak ditemukan." << endl;
}

void hapusRoti(vector<Roti>& daftarRoti) {
    string namaRoti;
    cout << "Masukkan nama roti yang ingin dihapus: ";
    cin.ignore();
    getline(cin, namaRoti);
    for (auto iter = daftarRoti.begin(); iter != daftarRoti.end(); ++iter) {
        if (iter->nama == namaRoti) {
            iter = daftarRoti.erase(iter);
            cout << "Roti berhasil dihapus." << endl;
            return;
        }
    }
    cout << "Roti tidak ditemukan." << endl;
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
                tambahRoti(daftarRoti);
                break;
            case 3:
                ubahHargaRoti(daftarRoti);
                break;
            case 4:
                hapusRoti(daftarRoti);
                break;
            case 5:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }

    } while (pilihan != 5);

    return 0;
}
