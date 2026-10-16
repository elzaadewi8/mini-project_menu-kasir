#include <iostream>
using namespace std;

int main() {
    // ===== LOGIN =====
    string passwordBenar = "kantin123";
    string passwordInput;
    int percobaan = 0;
    bool loginBerhasil = false;

    while (percobaan < 3) {
        cout << "Masukkan password: ";
        cin >> passwordInput;

        if (passwordInput == passwordBenar) {
            loginBerhasil = true;
            cout << "Login berhasil!\n\n";
            break;
        } else {
            percobaan++;
            cout << "Password salah! Percobaan ke-" << percobaan << endl;
        }
    }

    // ===== MENU KANTIN =====
    if (loginBerhasil) {
        int saldo = 20000;
        int pilihanMenu;
        int isiSaldo, hargaMakanan;
        int totalMasuk = 0;
        int totalKeluar = 0;
        char ulangMenu = 'y';
        bool biayaDiproses = false;

        do {
            cout << "\n===== MENU KANTIN =====\n";
            cout << "1. Lihat Saldo\n";
            cout << "2. Isi Saldo\n";
            cout << "3. Beli Makanan\n";
            cout << "4. Laporan Transaksi\n";
            cout << "5. Biaya Layanan\n";
            cout << "6. Keluar\n";
            cout << "Pilih menu (1-6): ";
            cin >> pilihanMenu;

            switch (pilihanMenu) {

            case 1:
                cout << "Saldo saat ini: Rp. " << saldo << endl;
                break;

            case 2:
                cout << "Masukkan nominal isi saldo: Rp. ";
                cin >> isiSaldo;

                if (isiSaldo >= 10000) {
                    saldo += isiSaldo;
                    totalMasuk += isiSaldo;
                    cout << "Isi saldo berhasil.\n";
                } else {
                    cout << "Minimal isi saldo Rp. 10.000\n";
                }
                break;

            case 3:
                cout << "Masukkan harga makanan: Rp. ";
                cin >> hargaMakanan;

                if (hargaMakanan > saldo) {
                    cout << "Saldo tidak cukup!\n";
                } else {
                    saldo -= hargaMakanan;
                    totalKeluar += hargaMakanan;
                    cout << "Pembelian berhasil.\n";
                }
                break;

            case 4:
                cout << "\n===== LAPORAN =====\n";
                cout << "Total uang masuk  : Rp. " << totalMasuk << endl;
                cout << "Total uang keluar : Rp. " << totalKeluar << endl;
                cout << "Saldo akhir       : Rp. " << saldo << endl;
                break;

            case 5:
                if (!biayaDiproses) {
                    saldo -= 2000;
                    biayaDiproses = true;
                    cout << "Biaya layanan Rp. 2.000 dipotong.\n";
                } else {
                    cout << "Biaya layanan sudah diproses.\n";
                }
                break;

            case 6:
                cout << "Terima kasih telah menggunakan sistem kantin.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
            }

            if (pilihanMenu != 6) {
                cout << "\nKembali ke menu? (y/t): ";
                cin >> ulangMenu;
            }

        } while (ulangMenu == 'y' || ulangMenu == 'Y');

    } else {
        cout << "\nAkses ditolak! Salah password 3 kali.\n";
    }

    return 0;
}
