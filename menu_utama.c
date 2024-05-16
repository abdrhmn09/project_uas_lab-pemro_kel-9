#include "header.h" // Menyertakan file header "header.h" yang berisi deklarasi fungsi dan definisi lain yang diperlukan

// Fungsi untuk menampilkan menu pilihan
void menu_utama() { // Deklarasi dan definisi fungsi bernama menu_utama yang tidak menerima argumen dan tidak mengembalikan nilai (void)
    printf("\n=== MENU ===\n"); // Mencetak judul menu ke layar dengan garis pembatas atas
    printf("1. Menambahkan menu\n"); // Mencetak opsi pertama: Menambahkan menu
    printf("2. Daftar Menu\n"); // Mencetak opsi kedua: Daftar Menu
    printf("3. Pembayaran\n"); // Mencetak opsi ketiga: Pembayaran
    printf("4. Hapus barang\n"); // Mencetak opsi keempat: Hapus barang
    printf("5. Kembali\n"); // Mencetak opsi kelima: Kembali
    printf("=============\n"); // Mencetak garis pembatas bawah menu
}