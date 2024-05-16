#include "header.h" // Mengimpor file header.c yang berisi deklarasi fungsi dan struktur data yang dibutuhkan.

void pembayaran() {
    FILE *pembayaran_file = fopen("pembayaran.txt", "w"); // Membuka file pembayaran.txt untuk ditulis.
    if (pembayaran_file == NULL) {
        printf("Gagal membuka file.\n"); // Jika file gagal dibuka, cetak pesan kesalahan dan keluar dari fungsi.
        return;
    }

    Barang barang[MAX_BARANG]; // Mendeklarasikan array barang untuk menyimpan data barang.
    int jumlah_barang;

    // Memuat data barang dari file
    muat_data(barang, &jumlah_barang); // Memanggil fungsi muat_data untuk memuat data barang dari file ke dalam array barang.

    // Menampilkan daftar barang
    printf("\nDaftar Barang:\n");
    for (int i = 0; i < jumlah_barang; i++) {
        printf("| %-14s | %-23s | %-13d | %-11d |\n", 
                barang[i].kode_barang, barang[i].nama_barang, 
                barang[i].harga_barang, barang[i].jumlah_stok); // Mencetak daftar barang yang tersedia.
    }

    // Menerima pembayaran
    printf("\nMasukkan pembelian (kode_barang jumlah), pisahkan dengan spasi (tekan 0 untuk selesai):\n");
    int total_harga = 0;
    fprintf(pembayaran_file, "+----------------+-------------------------+---------------+--------+--------+\n");
    fprintf(pembayaran_file, "| Kode Barang    | Nama Barang             | Harga Barang  | Jumlah | Total  |\n");
    fprintf(pembayaran_file, "+----------------+-------------------------+---------------+--------+--------+\n");

    while (1) {
        char kode_barang[15];
        int jumlah_beli;
        scanf("%s", kode_barang); // Menerima input kode barang dari pengguna.
        if (strcmp(kode_barang, "0") == 0) break; // Jika kode barang adalah "0", keluar dari loop.
        scanf("%d", &jumlah_beli); // Menerima input jumlah barang yang dibeli.

        // Proses pembelian dan pengurangan stok barang
        int found = 0; // Variabel untuk menandai apakah barang ditemukan atau tidak.
        for (int i = 0; i < jumlah_barang; i++) {
            if (strcmp(barang[i].kode_barang, kode_barang) == 0) { // Memeriksa apakah kode barang cocok dengan kode yang dimasukkan.
                if (barang[i].jumlah_stok >= jumlah_beli) { // Memeriksa apakah stok mencukupi untuk pembelian.
                    int total = barang[i].harga_barang * jumlah_beli; // Menghitung total harga barang yang dibeli.
                    total_harga += total; // Menambahkan total harga barang yang dibeli ke total harga keseluruhan.
                    barang[i].jumlah_stok -= jumlah_beli; // Mengurangi jumlah stok barang yang dibeli.
                    fprintf(pembayaran_file, "| %-14s | %-23s | %-13d | %-6d | %-6d |\n", 
                            barang[i].kode_barang, barang[i].nama_barang, 
                            barang[i].harga_barang, jumlah_beli, total); // Mencetak detail pembelian ke file.
                    found = 1; // Menandai bahwa barang ditemukan.
                    break;
                } else {
                    printf("Stok tidak mencukupi!\n"); // Jika stok tidak mencukupi, cetak pesan kesalahan.
                    found = 1; // Menandai bahwa barang ditemukan.
                    break;
                }
            }
        }

        if (!found) {
            printf("Barang tidak ditemukan!\n"); // Jika barang tidak ditemukan, cetak pesan kesalahan.
        }
    }

    fprintf(pembayaran_file, "+----------------+-------------------------+---------------+--------+--------+\n");
    fprintf(pembayaran_file, "|                                               Total Harga: %-8d |\n", total_harga); // Mencetak total harga keseluruhan ke file.
    fprintf(pembayaran_file, "+----------------------------------------------------------+--------+\n");

    fclose(pembayaran_file); // Menutup file pembayaran.txt.
    printf("Pembayaran selesai.\n");

    // Simpan data barang yang telah diperbarui
    simpan_data(barang, jumlah_barang); // Memanggil fungsi simpan_data untuk menyimpan data barang yang telah diperbarui ke file.
    // Tampilkan isi file pembayaran.txt
    printf("\nDetail Pembayaran:\n");
    FILE *pembayaran_file_read = fopen("pembayaran.txt", "r"); // Membuka file pembayaran.txt untuk dibaca.
    if (pembayaran_file_read == NULL) {
        printf("Gagal membuka file pembayaran.\n"); // Jika file gagal dibuka, cetak pesan kesalahan dan keluar dari fungsi.
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), pembayaran_file_read)) {
        printf("%s", line); // Membaca dan mencetak setiap baris dari file pembayaran.txt.
    }

    fclose(pembayaran_file_read); // Menutup file pembayaran.txt.
}
