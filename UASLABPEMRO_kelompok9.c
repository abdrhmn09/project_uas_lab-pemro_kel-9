#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi untuk menampilkan menu pilihan
void menu_utama() {
    printf("\n=== MENU ===\n");
    printf("1. Menambahkan menu\n");
    printf("2. Daftar Menu\n");
    printf("3. Pembayaran\n");
    printf("4. Keluar\n");
    printf("=============\n");
}

// Fungsi untuk pilihan 1
void menambahkan_barang() {
    printf("silahkan melakukan penambahan barang.\n");
    // Logika atau operasi untuk Pilihan 1

    // Setelah selesai dengan Pilihan 1, tunggu sampai pengguna menekan tombol 'Enter' untuk kembali ke menu
    printf("Tekan 'Enter' untuk kembali ke menu.");
    getchar(); // Mengonsumsi karakter newline sebelum masuk ke getchar()
    getchar(); // Menunggu pengguna menekan 'Enter'
}

// Fungsi untuk pilihan 2
void menampilkan_daftar_barang() {
    printf("silahkan memilih menu.\n");
    // Logika atau operasi untuk Pilihan 2

    // Setelah selesai dengan Pilihan 2, tunggu sampai pengguna menekan tombol 'Enter' untuk kembali ke menu
    printf("Tekan 'Enter' untuk kembali ke menu.");
    getchar(); // Mengonsumsi karakter newline sebelum masuk ke getchar()
    getchar(); // Menunggu pengguna menekan 'Enter'
}

// Fungsi untuk pilihan 3
void pembayaran() {
    printf("total pembayaran.\n");
    // Logika atau operasi untuk Pilihan 3

    // Setelah selesai dengan Pilihan 3, tunggu sampai pengguna menekan tombol 'Enter' untuk kembali ke menu
    printf("Tekan 'Enter' untuk kembali ke menu.");
    getchar(); // Mengonsumsi karakter newline sebelum masuk ke getchar()
    getchar(); // Menunggu pengguna menekan 'Enter'
}

int main() {
    char username[15];
    char password[15];

    do {
        printf("Masukkan username: ");
        scanf("%s", username);
        printf("\nMasukkan password: ");
        scanf("%s", password);
        int pilihan;
        // Periksa apakah input benar
        if (strcmp(username, "pegawai") != 1 && strcmp(password, "employe") != 1) {
            int pilihan;
            do {
                menu_utama(); // Menampilkan menu pilihan
                printf("Pilih opsi (1-4): ");
                scanf("%d", &pilihan);

                switch (pilihan) {
                    case 1:
                        menambahkan_barang(); // Memanggil fungsi untuk Pilihan 1
                        break;
                    case 2:
                        menampilkan_daftar_barang(); // Memanggil fungsi untuk Pilihan 2
                        break;
                    case 3:
                        pembayaran(); // Memanggil fungsi untuk Pilihan 3
                        break;
                    case 4:
                        printf("Terima kasih, sampai jumpa!\n");
                        break;
                    default:
                        printf("Pilihan tidak valid. Silakan pilih kembali.\n");
                }
            } while (pilihan != 4);
            break; // Keluar dari loop jika input valid
        } else {
            printf("Input tidak valid.\n");
        }
    } while (1);

    return 0;
}
