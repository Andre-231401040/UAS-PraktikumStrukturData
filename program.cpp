#include <iostream>
#include <limits>
#include <unordered_map>

using namespace std;

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

void tambahProdukKeKeranjang(){

}

void cariProdukBerdasarkanId(){

}

void tampilkanBarangDiKeranjang(){

}

int main(){
    short pilihanUser;
    // Anggap jumlah barang di keranjang maksimal 100
    barangDiKeranjang keranjang[100];

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

        }else if(pilihanUser == 2){
            tambahProdukKeKeranjang();
        }else if(pilihanUser == 3){
            cariProdukBerdasarkanId();
        }else if(pilihanUser == 4){
            tampilkanBarangDiKeranjang();
        }else if(pilihanUser == 5){
            
        }else if(pilihanUser == 6){

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
                cout << "Masukkan pilihan yang valid" << endl;
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