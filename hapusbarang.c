#include "header.h" 

void hapus_barang(const char *kode_barang) {
    FILE *file = fopen("data_barang.txt", "r"); // Membuka file data_barang.txt untuk dibaca
    if (file == NULL) { // Memeriksa apakah file berhasil dibuka
        printf("Gagal membuka file data_barang.txt\n"); // Menampilkan pesan error jika file tidak dapat dibuka
        return; // Keluar dari fungsi jika file tidak dapat dibuka
    }

    FILE *temp_file = fopen("temp_data_barang.txt", "w"); // Membuka file sementara untuk ditulis
    if (temp_file == NULL) { // Memeriksa apakah file sementara berhasil dibuka
        printf("Gagal membuat file sementara.\n"); // Menampilkan pesan error jika file sementara tidak dapat dibuka
        fclose(file); // Menutup file data_barang.txt
        return; // Keluar dari fungsi jika file sementara tidak dapat dibuka
    }

    char line[MAX_LENGTH]; // Membuat buffer untuk menyimpan baris yang dibaca
    int found = 0; // Variabel untuk menandai apakah barang ditemukan

    // Salin isi file ke file sementara kecuali baris dengan kode barang yang sesuai
    while (fgets(line, sizeof(line), file)) { // Membaca setiap baris dari file data_barang.txt
        if (strstr(line, kode_barang)) { // Memeriksa apakah baris mengandung kode barang
            found = 1; // Menandai bahwa barang ditemukan
            continue; // Lewatkan baris ini dan tidak menulis ke file sementara
        }
        fprintf(temp_file, "%s", line); // Menulis baris ke file sementara jika tidak mengandung kode barang
    }

    fclose(file); // Menutup file data_barang.txt
    fclose(temp_file); // Menutup file sementara

    // Hapus file asli dan ganti dengan file sementara
    remove("data_barang.txt"); // Menghapus file data_barang.txt
    rename("temp_data_barang.txt", "data_barang.txt"); // Mengganti nama file sementara menjadi data_barang.txt

    if (found) { // Jika barang ditemukan
        printf("Barang dengan kode %s berhasil dihapus.\n", kode_barang); // Menampilkan pesan bahwa barang berhasil dihapus
    } else { // Jika barang tidak ditemukan
        printf("Barang dengan kode %s tidak ditemukan.\n", kode_barang); // Menampilkan pesan bahwa barang tidak ditemukan
    }
}
