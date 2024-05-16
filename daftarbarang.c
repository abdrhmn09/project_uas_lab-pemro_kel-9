#include "header.h"

void simpan_data(Barang barang[], int jumlah_barang) {
    FILE *file = fopen("data_barang.txt", "w"); // Membuka file data_barang.txt untuk ditulis
    if (file == NULL) { // Memeriksa apakah file berhasil dibuka
        printf("Gagal membuka file untuk menyimpan data!\n"); // Menampilkan pesan error jika file tidak dapat dibuka
        return; // Keluar dari fungsi jika file tidak dapat dibuka
    }

    // Menulis header tabel ke dalam file
    fprintf(file, "+----------------+-------------------------+---------------+-------------+\n");
    fprintf(file, "| Kode Barang    | Nama Barang             | Harga Barang  | Jumlah Stok |\n");
    fprintf(file, "+----------------+-------------------------+---------------+-------------+\n");

    // Menulis data barang ke dalam file
    for (int i = 0; i < jumlah_barang; i++) {
        fprintf(file, "| %-14s | %-23s | %-13d | %-11d |\n", 
                barang[i].kode_barang, barang[i].nama_barang, 
                barang[i].harga_barang, barang[i].jumlah_stok);
    }

    // Menulis footer tabel ke dalam file
    fprintf(file, "+----------------+-------------------------+---------------+-------------+\n");

    fclose(file); // Menutup file
}

void muat_data(Barang barang[], int *jumlah_barang) {
    FILE *file = fopen("data_barang.txt", "r"); // Membuka file data_barang.txt untuk dibaca
    if (file == NULL) { 
        *jumlah_barang = 0; // Mengatur jumlah barang menjadi 0 jika file tidak dapat dibuka
        return; 
    }

    *jumlah_barang = 0; // Mengatur jumlah barang menjadi 0
    char line[256]; // Membuat buffer untuk menyimpan baris yang dibaca
    for (int i = 0; i < 3; i++) { // Melewati header tabel
        fgets(line, sizeof(line), file);
    }

    // Membaca data barang dari file
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "+----------------+-------------------------+---------------+-------------+")) {
            break; // Berhenti membaca jika footer tabel ditemukan
        }
        sscanf(line, "| %14s | %23s | %13d | %11d |", 
               barang[*jumlah_barang].kode_barang, 
               barang[*jumlah_barang].nama_barang, 
               &barang[*jumlah_barang].harga_barang, 
               &barang[*jumlah_barang].jumlah_stok);
        (*jumlah_barang)++; // Menambah jumlah barang
    }

    fclose(file); // Menutup file
}

void menampilkan_daftar_barang() {
    FILE *file = fopen("data_barang.txt", "r"); // Membuka file data_barang.txt untuk dibaca
    if (file == NULL) { // Memeriksa apakah file berhasil dibuka
        printf("Gagal membuka file untuk menampilkan data!\n"); // Menampilkan pesan error jika file tidak dapat dibuka
        return; // Keluar dari fungsi jika file tidak dapat dibuka
    }

    char line[256]; // Membuat buffer untuk menyimpan baris yang dibaca
    printf("\nDaftar Barang:\n"); // Menampilkan judul daftar barang
    while (fgets(line, sizeof(line), file)) { // Membaca dan menampilkan setiap baris dari file
        printf("%s", line);
    }

    fclose(file); // Menutup file

    printf("\nTekan 'Enter' untuk kembali ke menu."); // Instruksi untuk kembali ke menu
    getchar(); // Menunggu pengguna menekan 'Enter'
    getchar(); // Menunggu pengguna menekan 'Enter' lagi
}
