#include "header.h"

void menambahkan_barang(Barang barang[], int *jumlah_barang) {
    char lanjut; // Variabel untuk menyimpan pilihan pengguna apakah ingin melanjutkan

    do {
        if (*jumlah_barang >= MAX_BARANG) { // Cek apakah jumlah barang sudah mencapai kapasitas maksimum
            printf("Kapasitas barang penuh!\n"); // Tampilkan pesan jika kapasitas penuh
            break;
        }

        printf("Masukkan kode barang: ");
        scanf("%s", barang[*jumlah_barang].kode_barang);
        printf("Masukkan nama barang: ");
        scanf("%s", barang[*jumlah_barang].nama_barang);
        printf("Masukkan harga barang: ");
        scanf("%d", &barang[*jumlah_barang].harga_barang);
        printf("Masukkan jumlah stok: ");
        scanf("%d", &barang[*jumlah_barang].jumlah_stok);

        (*jumlah_barang)++; // Menambahkan jumlah barang yang terdaftar
        printf("Barang berhasil ditambahkan!\n");

        // Simpan data ke file dalam bentuk tabel
        simpan_data(barang, *jumlah_barang);

        printf("Ingin menambahkan barang lagi? (y/t): ");
        scanf(" %c", &lanjut); // Spasi sebelum %c untuk menghindari masalah input buffer
        
        if (lanjut != 'y' && lanjut != 'Y') // Jika bukan 'y' atau 'Y', keluar dari loop
            break;
    } while (1); // Loop terus menerus sampai break

    printf("Tekan 'Enter' untuk kembali ke menu.");
    getchar(); // Mengonsumsi karakter newline sebelum masuk ke getchar()
    getchar(); // Menunggu pengguna menekan 'Enter'
}