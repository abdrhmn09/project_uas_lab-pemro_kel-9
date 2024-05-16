#include "header.h"

int main() {
    int pilihanlogin;
    char username[15];
    char password[15];
    char kode_barang[10];
    int exit_program = 0;
    User users[MAX_USERS];
    Barang barang[MAX_BARANG];
    int jumlah_barang = 0;
    int user_count = memuat_akun(users, MAX_USERS);

    while (!exit_program) {
        printf("1. Login\n");
        printf("2. Daftar akun\n");
        printf("3. Keluar\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &pilihanlogin);

        switch (pilihanlogin) {
            case 1:
                do {
                    printf("Masukkan username: ");
                    scanf("%s", username);
                    printf("Masukkan password: ");
                    scanf("%s", password);

                    if (cek_data_akun(username, password, users, user_count)) {
                        int pilihan;
                        do {
                            menu_utama();
                            printf("Pilih opsi (1-5): ");
                            scanf("%d", &pilihan);

                            switch (pilihan) {
                                case 1:
                                    menambahkan_barang(barang, &jumlah_barang);
                                    break;
                                case 2:
                                    menampilkan_daftar_barang();
                                    break;
                                case 3:
                                    pembayaran();
                                    break;
                                case 4:
                                    printf("Masukkan kode barang yang ingin dihapus: ");
                                    scanf("%s", kode_barang);
                                    hapus_barang(kode_barang);
                                    break;
                                case 5:
                                    break;
                                default:
                                    printf("Pilihan tidak valid. Silakan pilih kembali.\n");
                            }
                        } while (pilihan != 5);
                        break; // Keluar dari loop login untuk kembali ke menu utama
                    } else {
                        printf("Username atau password salah. Silakan coba lagi.\n");
                        break;
                    }
                } while (1);
                break;

            case 2:
                membuat_akun();
                user_count = memuat_akun(users, MAX_USERS); // memuat ulang data akun setelah membuat akun baru
                break;
            case 3:
                exit_program = 1;
                printf("Terima kasih, sampai jumpa!\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan pilih kembali.\n");
        }
    }

    return 0;
}