#include <iostream>
#include <limits>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cctype>

using namespace std;
// int i = 0;

struct produk{
    string namaProduk, kategori;
    int harga;
};

struct barangDiKeranjang{
    produk barang;
    int jumlahBarang, hargaTotal;
};

unordered_map<int, produk> daftarProduk = {
    {1, produk{"Smartphone Samsung Galaxy S23", "Elektronik", 12000000}},
    {2, produk{"Laptop ASUS ROG Zephyrus G14", "Elektronik", 25000000}},
    {3, produk{"TV LED LG 43 Inch", "Elektronik", 6500000}},
    {4, produk{"Earbuds Apple AirPods Pro", "Elektronik", 3500000}},
    {5, produk{"Kamera DSLR Canon EOS 90D", "Elektronik", 17000000}},
    {6, produk{"Sepeda MTB Polygon", "Fitness", 5000000}},
    {7, produk{"Dumbbell 5kg", "Fitness", 200000}},
    {8, produk{"Matras Yoga", "Fitness", 250000}},
    {9, produk{"Mesin Elliptical", "Fitness", 7500000}},
    {10, produk{"Resistance Band", "Fitness", 100000}},
    {11, produk{"Serum Wajah Vitamin C", "Kecantikan", 150000}},
    {12, produk{"Masker Wajah Aloe Vera", "Kecantikan", 75000}},
    {13, produk{"Lipstik Matte L'Oréal", "Kecantikan", 120000}},
    {14, produk{"Parfum Chanel", "Kecantikan", 2500000}},
    {15, produk{"Sabun Cuci Muka Himalaya", "Kecantikan", 35000}},
    {16, produk{"Roti Tawar Serba Roti", "Konsumsi", 15000}},
    {17, produk{"Kopi Arabica 100g", "Konsumsi", 50000}},
    {18, produk{"Mie Instan", "Konsumsi", 5000}},
    {19, produk{"Susu UHT Indomilk 1 Liter", "Konsumsi", 18000}},
    {20, produk{"Teh Kotak Sosro 500ml", "Konsumsi", 7500}}
};

void tampilkanProduk(){
    cout << left << setw(5)  << "ID" << 
            left << setw(35) << "Produk" <<
            left << setw(15) << "Kategori" <<
            left << setw(10) << "Harga" << endl;
    cout << setfill('-') << setw(65) << "-" << setfill(' ') << endl;

    for (int i = 1; i <= 20; i++){
        cout << left << setw(5) << i << 
                left << setw(35) << daftarProduk[i].namaProduk << 
                left << setw(15) << daftarProduk[i].kategori << 
                left << setw(10) << daftarProduk[i].harga << endl;
    }
}

void sortirProdukBerdasarkanKategori() {
    system("cls");
    string kategori;
    cout << "Masukkan kategori (Elektronik, Fitness, Kecantikan, Konsumsi): ";
    cin >> kategori;

    vector<pair<int, produk>> produkUrut;

    for (const auto& item : daftarProduk) {
        if (item.second.kategori == kategori) {
            produkUrut.push_back(item);
        }
    }

    sort(produkUrut.begin(), produkUrut.end(),
         [](const pair<int, produk>& a, const pair<int, produk>& b) {
             return a.first < b.first;
         });

    if (!produkUrut.empty()) {
        cout << "\nDaftar produk dalam kategori '" << kategori << "'\n";
        cout << left << setw(5) << "ID"
             << left << setw(30) << "Nama Produk"
             << left << setw(15) << "Kategori"
             << left << setw(10) << "Harga" << endl;
        cout << string(60, '=') << endl;

        for (const auto& item : produkUrut) {
            cout << left << setw(5) << item.first
                 << left << setw(30) << item.second.namaProduk
                 << left << setw(15) << item.second.kategori
                 << left << setw(10) << item.second.harga << endl;
        }
    } else {
        cout << "\nKategori yang Anda masukkan tidak ditemukan atau kosong.\n";
    }

    system("pause");
}

// Fungsi sortir berdasarkan harga
void sortirProdukBerdasarkanHarga() {
    system("cls");
    vector<pair<int, produk>> produkVector(daftarProduk.begin(), daftarProduk.end());

    cout << "Urutkan harga (1 untuk termurah, 2 untuk termahal): ";
    int pilihan;
    cin >> pilihan;

    if (pilihan == 1) {
        sort(produkVector.begin(), produkVector.end(),
             [](const pair<int, produk>& a, const pair<int, produk>& b) {
                 return a.second.harga < b.second.harga;
             });
    } else if (pilihan == 2) {
        sort(produkVector.begin(), produkVector.end(),
             [](const pair<int, produk>& a, const pair<int, produk>& b) {
                 return a.second.harga > b.second.harga;
             });
    } else {
        cout << "Pilihan tidak valid!" << endl;
        system("pause");
        return;
    }

    cout << left << setw(5) << "ID" 
         << left << setw(30) << "Produk"
         << left << setw(13) << "Kategori" 
         << left << setw(7) << "Harga" << endl;
    cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;

    for (const auto& item : produkVector) {
        cout << left << setw(5) << item.first
             << left << setw(30) << item.second.namaProduk
             << left << setw(13) << item.second.kategori
             << left << setw(7) << item.second.harga << endl;
    }

    system("pause");
}

void lihatProduk() {
    system("cls");
    cout << "Pilih cara untuk melihat produk:" << endl;
    cout << "1. Tampilkan semua produk" << endl;
    cout << "2. Sortir berdasarkan kategori" << endl;
    cout << "3. Sortir berdasarkan harga" << endl;
    cout << "Pilihan Anda: ";
    int pilihan;
    cin >> pilihan;

    if (pilihan == 1) {
        tampilkanProduk();
        system("pause");
    } else if (pilihan == 2) {
        sortirProdukBerdasarkanKategori();
    } else if (pilihan == 3) {
        sortirProdukBerdasarkanHarga();
    } else {
        cout << "Pilihan tidak valid!" << endl;
        system("pause");
    }
}

void tambahProdukKeKeranjang(barangDiKeranjang (&keranjang)[20], short idBarang, short (&jumlahBarangDiKeranjang)){
    if(idBarang < 1 || idBarang > 20){
        system("cls");
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "==============================" << endl;
        cout << "Produk tidak ditemukan!" << endl;
        cout << "==============================" << endl << endl;
        return;
    }

    bool ditemukan = false;
    int jumlahBarang, i = 0;

    for(i; i < jumlahBarangDiKeranjang; i++){
        if(keranjang[i].barang.namaProduk == daftarProduk[idBarang].namaProduk){
            ditemukan = true;
            break;
        }
    }

    cout << "Masukkan Jumlah Barang: ";
    cin >> jumlahBarang;
    if(ditemukan){
        keranjang[i].jumlahBarang += jumlahBarang;
        keranjang[i].hargaTotal = keranjang[i].jumlahBarang * keranjang[i].barang.harga;
    }else{
        keranjang[jumlahBarangDiKeranjang].barang.namaProduk = daftarProduk[idBarang].namaProduk;
        keranjang[jumlahBarangDiKeranjang].barang.kategori = daftarProduk[idBarang].kategori;
        keranjang[jumlahBarangDiKeranjang].barang.harga = daftarProduk[idBarang].harga;
        keranjang[jumlahBarangDiKeranjang].jumlahBarang = jumlahBarang;
        keranjang[jumlahBarangDiKeranjang].hargaTotal = keranjang[jumlahBarangDiKeranjang].jumlahBarang * keranjang[jumlahBarangDiKeranjang].barang.harga;
        jumlahBarangDiKeranjang++;
    }

    system("cls");
    cout << "========================================================================" << endl;
    cout << jumlahBarang << " " << keranjang[i].barang.namaProduk << " berhasil ditambahkan ke keranjang." << endl;
    cout << "========================================================================" << endl << endl;
}

void cariProdukBerdasarkanId(short idBarang){
    if(idBarang < 1 || idBarang > 20){
        system("cls");
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "==============================" << endl;
        cout << "Produk tidak ditemukan!" << endl;
        cout << "==============================" << endl << endl;
        return;
    }

    cout << "Nama produk: " << daftarProduk[idBarang].namaProduk << endl;
    cout << "Kategori: " << daftarProduk[idBarang].kategori << endl;
    cout << "Harga: " << daftarProduk[idBarang].harga << endl << endl;
}

void tampilkanBarangDiKeranjang(barangDiKeranjang (&keranjang)[20], short (&jumlahBarangDiKeranjang)){
    system("cls");
    int harusDibayar = 0;
    // cek apakah keranjang kosong
    if (jumlahBarangDiKeranjang == 0) {
        cout << "=====================================" << endl;
        cout << "Keranjang belanja Anda masih kosong." << endl;
        cout << "=====================================" << endl << endl;
        return;
    }

    // untuk menampilkan header tabel
    cout << left << setw(5)  << "No" <<
            left << setw(35) << "Produk" <<
            left << setw(12) << "Harga" <<
            left << setw(10) << "Jumlah" <<
            left << setw(15) << "Harga Total" << endl;
    cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;

    // untuk menampilkan nomor, nama produk, harga, jumlah barang, dan total harga
    for (int i = 0; i < jumlahBarangDiKeranjang; i++) {
        harusDibayar += keranjang[i].hargaTotal;
        cout << left << setw(5) << i + 1 <<
                left << setw(35) << keranjang[i].barang.namaProduk <<
                left << setw(12) << keranjang[i].barang.harga <<
                left << setw(10) << keranjang[i].jumlahBarang <<
                left << setw(15) << keranjang[i].hargaTotal << endl;
    }

    cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
    cout << left << setw(62) << "Harus Dibayar " <<
            left << setw(15) << harusDibayar << endl;
    cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl << endl;
}

void hapusBarangDariKeranjang(barangDiKeranjang (&keranjang)[20], short idBarang, short (&jumlahBarangDiKeranjang)) {
    if(idBarang < 1 || idBarang > 20){
        system("cls");
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "==============================" << endl;
        cout << "Produk tidak ditemukan!" << endl;
        cout << "==============================" << endl << endl;
        return;
    }

    // false karena di awal barang belum ditemukan
    bool ditemukan = false;
    for (int i = 0; i < jumlahBarangDiKeranjang; i++) {
        // cek apakah nama produk pada keranjang[i] = nama produk pada daftarproduk[idBarang]
        if (keranjang[i].barang.namaProduk == daftarProduk[idBarang].namaProduk) {
            if(i == jumlahBarangDiKeranjang - 1){
                keranjang[i] = {};
            }else{
                for(int j = i; j < jumlahBarangDiKeranjang - 1; j++){
                    keranjang[j] = keranjang[j + 1];
                    keranjang[j + 1] = {};
                }
            }
            // satu barang dihapus, berarti jumlah total barang di keranjang juga harus berkurang
            jumlahBarangDiKeranjang--;
            // idBarang berhasil ditemukan dan dihapus
            ditemukan = true;
            system("cls");
            cout << "==================================================================" << endl;
            cout << daftarProduk[idBarang].namaProduk << " telah dihapus dari keranjang." << endl;
            cout << "==================================================================" << endl << endl;
            break;
        }
    }

    if (!ditemukan) {
        system("cls");
        cout << "================================================================" << endl;
        cout << "Barang dengan ID " << idBarang << " tidak ditemukan di keranjang belanja." << endl;
        cout << "================================================================" << endl << endl;
    }
}

void hitungBiayaPengiriman() {
    const int INF = numeric_limits<int>::max();
    const int jumlahTitik = 10;
    vector<vector<pair<int, int>>> graph(jumlahTitik);

    //peta
    graph[0] = {{2, 7}, {3, 4}, {6, 4}, {8, 5}};
    graph[2] = {{1, 5}};
    graph[6] = {{1, 4}, {5, 11}, {4, 2}};
    graph[8] = {{5, 10}};
    graph[5] = {{4, 9}, {7, 8}, {9, 3}};
    graph[4] = {{7, 7}};
    graph[9] = {{7, 4}};

    //input lokasi
    int tujuan;
    cout << "Masukkan nomor titik tujuan (1-9): ";
    cin >> tujuan;

    if (tujuan <= 0 || tujuan >= jumlahTitik) {
        cout << "Titik tujuan tidak valid! Masukkan angka antara 1-9." << endl;
        system("pause");
        return;
    }

    vector<int> jarak(jumlahTitik, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    jarak[0] = 0;
    pq.push({0, 0}); // {jarak, node}

    while (!pq.empty()) {
        int jarakSaatIni = pq.top().first;
        int nodeSaatIni = pq.top().second;
        pq.pop();

        if (jarakSaatIni > jarak[nodeSaatIni]) continue;

        for (auto& tetangga : graph[nodeSaatIni]) {
            int tetanggaNode = tetangga.first;
            int bobot = tetangga.second;

            if (jarak[nodeSaatIni] + bobot < jarak[tetanggaNode]) {
                jarak[tetanggaNode] = jarak[nodeSaatIni] + bobot;
                pq.push({jarak[tetanggaNode], tetanggaNode});
            }
        }
    }

    //tampilkan biayanya
    if (jarak[tujuan] == INF) {
        cout << "Tidak ada jalur yang tersedia ke titik tujuan." << endl;
    } else {
        int biayaPengiriman = jarak[tujuan] * 3000;
        cout << "Jarak ke titik tujuan: " << jarak[tujuan] << " km" << endl;
        cout << "Biaya pengiriman: Rp. " << biayaPengiriman << endl;
    }
    system("pause");
}

int main(){
    short idBarang, pilihanUser, jumlahBarangDiKeranjang = 0;
    // Jumlah barang di keranjang maksimal 20
    barangDiKeranjang keranjang[20];

    do {
        system("cls");
        cout << "============================================" << endl;
        cout << "Selamat Datang di Toko LuckySeven" << endl;
        cout << "============================================" << endl;
        cout << "Silahkan pilih fitur yang ingin digunakan." << endl;
        cout << "1. Lihat Produk" << endl;
        cout << "2. Tambah Produk ke Keranjang Belanja" << endl;
        cout << "3. Cari Produk" << endl;
        cout << "4. Lihat Daftar Barang di Keranjang" << endl;
        cout << "5. Hapus Barang dari Keranjang" << endl;
        cout << "6. Hitung Biaya Pengiriman" << endl;
        cout << "7. Bayar" << endl;
        cout << "8. Lihat Riwayat Pembayaran" << endl;
        cout << "9. Lihat Detail Transaksi" << endl;
        cout << "10. Keluar" << endl;
        cout << endl << "Pilihan anda: ";
        cin >> pilihanUser;

        if(pilihanUser == 1){
            lihatProduk();
        }else if(pilihanUser == 2){
            tambahLagi:
            system("cls");
            char tambahLagi;
            tampilkanProduk();
            cout << endl << "Masukkan ID Barang: ";
            cin >> idBarang;
            tambahProdukKeKeranjang(keranjang, idBarang, jumlahBarangDiKeranjang);

            cout << "Mau tambah lagi [y/n]: ";
            cin >> tambahLagi;
            if(tambahLagi == 'y' || tambahLagi == 'Y'){
                goto tambahLagi;
            }
        }else if(pilihanUser == 3){
            cariLagi:
            system("cls");
            char cariLagi;
            cout << "Masukkan ID Barang: ";
            cin >> idBarang;
            cariProdukBerdasarkanId(idBarang);

            cout << "Mau cari lagi [y/n]: ";
            cin >> cariLagi;
            if(cariLagi == 'y' || cariLagi == 'Y'){
                goto cariLagi;
            }
        }else if(pilihanUser == 4){
            tampilkanBarangDiKeranjang(keranjang, jumlahBarangDiKeranjang);
            system("pause");
        }else if(pilihanUser == 5){
            hapusLagi:
            system("cls");
            char hapusLagi;
            tampilkanProduk();
            cout << endl << "Masukkan ID Barang: ";
            cin >> idBarang;
            hapusBarangDariKeranjang(keranjang, idBarang, jumlahBarangDiKeranjang);

            cout << "Mau hapus lagi [y/n]: ";
            cin >> hapusLagi;
            if(hapusLagi == 'y' || hapusLagi == 'Y'){
                goto hapusLagi;
            }
        }else if(pilihanUser == 6){
            hitungBiayaPengiriman();
        }else if(pilihanUser == 7){

        }else if(pilihanUser == 8){

        }else if(pilihanUser == 9){

        }else{
            if(pilihanUser != 10){
                system("cls");
                // Memeriksa apakah input gagal (tipe data tidak sesuai)
                if(cin.fail()){
                    // Menghapus state kesalahan sehingga cin dapat digunakan kembali
                    cin.clear();
                    // Menghapus sisa input di buffer untuk menghindari perulangan membaca input yang sama
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "==================================" << endl;
                cout << "Masukkan pilihan yang valid." << endl;
                cout << "==================================" << endl;
                pilihanUser = 0;
                system("pause");
            }
        }
    } while (pilihanUser != 10);

    system("cls");
    cout << "===========================================" << endl;
    cout << "Terima kasih telah mengunjungi toko kami." << endl;
    cout << "===========================================" << endl;
    cout << endl;

    return 0;
}