#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Atlet {
    string nama;
    string negara;
    string cabangOlahraga;
    int medali;
    int emas;
    int perak;
    int perunggu;
    double poin;
};

const int MAX_ATLET = 100;
Atlet daftarAtlet[MAX_ATLET];
int jumlahAtlet = 0;

// menggunakan sistem perhitungan berdasar poin tiap medali emas = 3, perak = 2, perunggu = 1 dibagi dengan total medali yang didapat
void hitungPoin(Atlet &atlet) {
    int totalMedali = atlet.emas + atlet.perak + atlet.perunggu;
    atlet.medali = totalMedali;
    if (totalMedali == 0) atlet.poin = 0;
    else atlet.poin = (atlet.emas * 3 + atlet.perak * 2 + atlet.perunggu) / (double)totalMedali;
}

void tambahAtlet() {
    int jumlahdata, cari;
    // Input jumlah atlet yang akan ditambahkan dengan validasi
    do {
        cout << "Jumlah atlet yang ingin ditambahkan: ";
        cin >> jumlahdata;

        if (cin.fail() || jumlahdata <= 0) {
            cout << "Jumlah atlet harus berupa bilangan positif!\n";
            cin.clear();
        } else {
            cin.ignore();
            break;
        }
    } while (true);

    // Cek apakah masih ada slot untuk menambah atlet
    if (jumlahAtlet + jumlahdata > MAX_ATLET) {
        cout << "Kapasitas penuh! Hanya bisa menambah " << MAX_ATLET - jumlahAtlet << " atlet lagi.\n";
        return;
    }

    // Input data atlet
    for (int i = 0; i < jumlahdata; i++) {
        cout << "\nMasukkan Data Atlet ke-" << jumlahAtlet + 1 << ":\n";

        cout << left << setw(25) << "Nama" << ": " ;
        getline(cin, daftarAtlet[jumlahAtlet].nama);
        cout << left << setw(25) << "Negara" << ": ";
        getline(cin, daftarAtlet[jumlahAtlet].negara);
        cout << left << setw(25) << "Cabang Olahraga" << ": ";
        getline(cin, daftarAtlet[jumlahAtlet].cabangOlahraga);

        // Validasi input jumlah medali
        while (true) {
            cout << left << setw(25) << "Masukkan jumlah emas" << ": ";
            cin >> daftarAtlet[jumlahAtlet].emas;
            cout << left << setw(25) << "Masukkan jumlah perak" << ": ";
            cin >> daftarAtlet[jumlahAtlet].perak;
            cout << left << setw(25) << "Masukkan jumlah perunggu" << ": ";
            cin >> daftarAtlet[jumlahAtlet].perunggu;

            if (cin.fail() || daftarAtlet[jumlahAtlet].emas < 0 || daftarAtlet[jumlahAtlet].perak < 0 || daftarAtlet[jumlahAtlet].perunggu < 0) {
                cout << "Jumlah medali tidak boleh negatif!\n";
                cin.clear();
            } else {
                cin.ignore();
                break;
            }
        }

        // Hitung poin atlet
        hitungPoin(daftarAtlet[jumlahAtlet]);
        jumlahAtlet++;
        cout << "Atlet berhasil ditambahkan!\n";
    }
}

void tampilkanAtlet() {
    if (jumlahAtlet == 0) {
        cout << "Tidak ada data atlet.\n";
        return;
    }
    cout << "\n========================================= Daftar Atlet ==========================================\n";
    cout << left << setw(4) << "No" 
         << setw(15) << "Nama" 
         << setw(15) << "Negara"
         << setw(17) << "Cabang Olahraga" 
         << setw(6) << "Emas" 
         << setw(7) << "Perak" 
         << setw(10) << "Perunggu"
         << setw(14) << "Total Medali"
         << setw(11) << "Poin" << endl;
    cout << string(97, '=') << endl;

    for (int i = 0; i < jumlahAtlet; i++) {
        cout << left << setw(4) << i + 1 
        << setw(15) << daftarAtlet[i].nama 
             << setw(15) << daftarAtlet[i].negara
             << setw(17) << daftarAtlet[i].cabangOlahraga 
             << setw(6) << daftarAtlet[i].emas 
             << setw(7) << daftarAtlet[i].perak 
             << setw(10) << daftarAtlet[i].perunggu
             << setw(14) << daftarAtlet[i].medali
        << setw(10) << fixed << setprecision(2) << daftarAtlet[i].poin << endl;
    }
    cout << string(97, '=') << "\n";
}

// Pencarian Linear
void cariAtletLinear(string key, string tipe) {
    bool ditemukan = false;
    for (int i = 0; i < jumlahAtlet; i++) {
        if ((tipe == "nama" && daftarAtlet[i].nama == key) ||
        (tipe == "negara" && daftarAtlet[i].negara == key) ||
        (tipe == "cabang" && daftarAtlet[i].cabangOlahraga == key)) {
        cout << "\nAtlet ditemukan:\n";
        cout << "Nama: " << daftarAtlet[i].nama << endl;
        cout << "Negara: " << daftarAtlet[i].negara << endl;
        cout << "Cabang Olahraga: " << daftarAtlet[i].cabangOlahraga << endl;
        cout << "Emas: " << daftarAtlet[i].emas << ", Perak: " << daftarAtlet[i].perak << ", Perunggu: " << daftarAtlet[i].perunggu << endl;
        cout << "Poin: " << fixed << setprecision(2) << daftarAtlet[i].poin << endl;
        cout << "Total Medali: " << daftarAtlet[i].medali << endl;
        ditemukan = true;
        }
    }
    if (!ditemukan) cout << "Atlet tidak ditemukan.\n";
}

void bubbleSort(bool ascending) {
    for (int i = 0; i < jumlahAtlet - 1; i++) {
        for (int j = 0; j < jumlahAtlet - i - 1; j++) {
            if ((ascending && daftarAtlet[j].medali > daftarAtlet[j + 1].medali) ||
                (!ascending && daftarAtlet[j].medali < daftarAtlet[j + 1].medali)) {
                swap(daftarAtlet[j], daftarAtlet[j + 1]);
            }
        }
    }
}

void merge(Atlet arr[], int l, int m, int r, bool ascending) {
    int n1 = m - l + 1;
    int n2 = r - m;
    Atlet L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if ((ascending && L[i].poin <= R[j].poin) ||
            (!ascending && L[i].poin >= R[j].poin)) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(Atlet arr[], int l, int r, bool ascending) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, ascending);
        mergeSort(arr, m + 1, r, ascending);
        merge(arr, l, m, r, ascending);
    }
}

int main() {
    int pilihan;
    do {
        system("cls");
        cout << "=========================";
        cout << "\n  Menu Manajemen Atlet\n";
        cout << "=========================\n";
        cout << "1. Tambah Atlet\n";
        cout << "2. Tampilkan Atlet\n";
        cout << "3. Cari Atlet\n";
        cout << "4. Sorting Atlet\n";
        cout << "0. Keluar\n";
        cout << "-------------------------\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cout << "-------------------------\n";

        switch (pilihan) {
            case 1:
                system("cls");
                tambahAtlet();
                break;
            case 2:
                system("cls");
                tampilkanAtlet();
                break;
            case 3: {
                system("cls");
                int tipe;
                string key;
                cout << "Cari berdasarkan:\n1. Nama\n2. Negara\n3. Cabang Olahraga\nPilihan: ";
                cin >> tipe;
                cin.ignore();
                cout << "Masukkan kata kunci pencarian: ";
                getline(cin, key);
                if (tipe == 1) cariAtletLinear(key, "nama");
                else if (tipe == 2) cariAtletLinear(key, "negara");
                else if (tipe == 3) cariAtletLinear(key, "cabang");
                else cout << "Pilihan tidak valid!\n";
                break;
            }
            case 4: {
                system("cls");
                int metode, urutan;
                cout << "Pilih metode sorting:\n1. Bubble Sort (berdasarkan total medali)\n2. Merge Sort (berdasarkan poin)\nPilihan : ";
                cin >> metode;
                cout << "Urutan (1 = Ascending, 2 = Descending): ";
                cin >> urutan;
                bool ascending = (urutan == 1);

                if (metode == 1) bubbleSort(ascending);
                else if (metode == 2) mergeSort(daftarAtlet, 0, jumlahAtlet - 1, ascending);
                else cout << "Metode tidak valid.\n";

                tampilkanAtlet();
                break;
            }
            case 0:
                system("cls");
                cout << "Keluar dari program.\n";
                break;
            default:
                system("cls");
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);
    return 0;
}