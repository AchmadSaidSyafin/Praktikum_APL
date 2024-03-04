#include <iostream>
#include <string>

using namespace std;

void km_per_hour_to_other() {
    double km_per_hour;
    cout << "Masukkan kecepatan dalam Kilometer per jam: ";
    cin >> km_per_hour;

    int choice;
    cout << "==== Pilih konversi yang diinginkan ====\n";
    cout << "1. Konversi ke Centimeter per detik\n";
    cout << "2. Konversi ke Meter per detik\n";
    cout << "3. Konversi ke Mil per jam\n";
    cout << "Masukkan pilihan (1/2/3): ";
    cin >> choice;

    switch(choice) {
        case 1:
            cout << km_per_hour << " Kilometer per jam = " << km_per_hour * 27.7778 << " Centimeter per detik\n";
            break;
        case 2:
            cout << km_per_hour << " Kilometer per jam = " << km_per_hour * 0.277778 << " Meter per detik\n";
            break;
        case 3:
            cout << km_per_hour << " Kilometer per jam = " << km_per_hour / 1.60934 << " Mil per jam\n";
            break;
        default:
            cout << "Pilihan tidak valid\n";
    }
}

void cm_per_second_to_other() {
    double cm_per_second;
    cout << "Masukkan kecepatan dalam Centimeter per detik: ";
    cin >> cm_per_second;

    int choice;
    cout << "==== Pilih konversi yang diinginkan ====\n";
    cout << "1. Konversi ke Kilometer per jam\n";
    cout << "2. Konversi ke Meter per detik\n";
    cout << "3. Konversi ke Mil per jam\n";
    cout << "Masukkan pilihan (1/2/3): ";
    cin >> choice;

    switch(choice) {
        case 1:
            cout << cm_per_second << " Centimeter per detik = " << cm_per_second * 0.036 << " Kilometer per jam\n";
            break;
        case 2:
            cout << cm_per_second << " Centimeter per detik = " << cm_per_second * 0.01 << " Meter per detik\n";
            break;
        case 3:
            cout << cm_per_second << " Centimeter per detik = " << cm_per_second * 0.0223694 << " Mil per jam\n";
            break;
        default:
            cout << "Pilihan tidak valid\n";
    }
}

void m_per_second_to_other() {
    double m_per_second;
    cout << "Masukkan kecepatan dalam Meter per detik: ";
    cin >> m_per_second;

    int choice;
    cout << "==== Pilih konversi yang diinginkan ====\n";
    cout << "1. Konversi ke Kilometer per jam\n";
    cout << "2. Konversi ke Centimeter per detik\n";
    cout << "3. Konversi ke Mil per jam\n";
    cout << "Masukkan pilihan (1/2/3): ";
    cin >> choice;

    switch(choice) {
        case 1:
            cout << m_per_second << " Meter per detik = " << m_per_second * 3.6 << " Kilometer per jam\n";
            break;
        case 2:
            cout << m_per_second << " Meter per detik = " << m_per_second * 100 << " Centimeter per detik\n";
            break;
        case 3:
            cout << m_per_second << " Meter per detik = " << m_per_second * 2.23694 << " Mil per jam\n";
            break;
        default:
            cout << "Pilihan tidak valid\n";
    }
}

void miles_per_hour_to_other() {
    double miles_per_hour;
    cout << "Masukkan kecepatan dalam Mil per jam: ";
    cin >> miles_per_hour;

    int choice;
    cout << "==== Pilih konversi yang diinginkan ====\n";
    cout << "1. Konversi ke Kilometer per jam\n";
    cout << "2. Konversi ke Centimeter per detik\n";
    cout << "3. Konversi ke Meter per detik\n";
    cout << "Masukkan pilihan (1/2/3): ";
    cin >> choice;

    switch(choice) {
        case 1:
            cout << miles_per_hour << " Mil per jam = " << miles_per_hour * 1.60934 << " Kilometer per jam\n";
            break;
        case 2:
            cout << miles_per_hour << " Mil per jam = " << miles_per_hour * 44.7 << " Centimeter per detik\n";
            break;
        case 3:
            cout << miles_per_hour << " Mil per jam = " << miles_per_hour * 0.44704 << " Meter per detik\n";
            break;
        default:
            cout << "Pilihan tidak valid\n";
    }
}

bool login() {
    string nama, nim;
    cout <<"==== SELAMAT DATANG ====" <<endl;
    cout << "Masukkan Nama Anda: ";
    cin >> nama;
    cout << "Masukkan NIM Anda: ";
    cin >> nim;
    return (nama == "Avin" && nim == "087"); //Nama dan Nim yang benar
}

int main() {
    int jumlah_login_salah = 0;
    char ulangi;

    do {
        bool berhasil_login = login();
        if (berhasil_login) {
            cout << "Login berhasil!" << endl;
            break;
        } else {
            cout << "Nama atau NIM yang anda masukkan salah!" << endl;
            jumlah_login_salah++;
            if (jumlah_login_salah == 3) {
                cout << "Anda sudah 3 kali salah login. Program berhenti." << endl;
                return 0;
            }
        }
        cout << "Apakah Anda ingin mencoba login lagi? (y/n): ";
        cin >> ulangi;
    } while (ulangi == 'y' || ulangi == 'Y');

    do {
        int choice;
        cout << "=========== Menu ============\n";
        cout << "1. Konversi Kilometer per jam\n";
        cout << "2. Konversi Centimeter per detik\n";
        cout << "3. Konversi Meter per detik\n";
        cout << "4. Konversi Mil per jam\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan (1/2/3/4/5): ";
        cin >> choice;

        switch(choice) {
            case 1:
                km_per_hour_to_other();
                break;
            case 2:
                cm_per_second_to_other();
                break;
            case 3:
                m_per_second_to_other();
                break;
            case 4:
                miles_per_hour_to_other();
                break;
            case 5:
                cout << "Program Berhenti\n";
                return 0;
            default:
                cout << "Pilihan tidak valid\n";
        }

        cout << "Apakah Anda ingin melakukan konversi lagi? (y/n): ";
        cin >> ulangi;
    } while (ulangi == 'y' || ulangi == 'Y');

    return 0;
}
