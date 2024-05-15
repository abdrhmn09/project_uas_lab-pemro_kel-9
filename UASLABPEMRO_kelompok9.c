#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100
#define MAX_USERS 100

typedef struct {
    char kode_barang[10];
    char nama_barang[50];
    int harga_barang;
    int jumlah_stok;
} Barang;

typedef struct {
    char username[15];
    char password[15];
} User;

// Fungsi untuk menampilkan menu pilihan
void menu_utama() {
    printf("\n=== MENU ===\n");
    printf("1. Menambahkan menu\n");
    printf("2. Daftar Menu\n");
    printf("3. Pembayaran\n");
    printf("4. Kembali\n");
    printf("=============\n");
}

// Fungsi untuk pilihan 1
void menambahkan_barang() {
    printf("silahkan melakukan penambahan barang.\n");
    printf("Tekan 'Enter' untuk kembali ke menu.");
    getchar(); // Mengonsumsi karakter newline sebelum masuk ke getchar()
    getchar(); // Menunggu pengguna menekan 'Enter'
}

// Fungsi untuk pilihan 2
void menampilkan_daftar_barang() {
    printf("Tekan 'Enter' untuk kembali ke menu.");
    getchar(); // Mengonsumsi karakter newline sebelum masuk ke getchar()
    getchar(); // Menunggu pengguna menekan 'Enter'
}

// Fungsi untuk pilihan 3
void pembayaran() {
    printf("total pembayaran.\n");
    printf("silahkan memilih menu.\n");
    printf("Tekan 'Enter' untuk kembali ke menu.");
    getchar(); // Mengonsumsi karakter newline sebelum masuk ke getchar()
    getchar(); // Menunggu pengguna menekan 'Enter'
}

int memuat_akun(User users[], int max_users) {
    FILE *file = fopen("data_akun.txt", "r");
    if (file == NULL) {
        printf("Tidak dapat membuka file data_akun.txt\n");
        return 0;
    }

    char line[MAX_LENGTH];
    int count = 0;

    while (fgets(line, sizeof(line), file) && count < max_users) {
        if (sscanf(line, "%[^:]:%s", users[count].username, users[count].password) == 2) {
            count++;
        }
    }

    fclose(file);
    return count;
}

int cek_data_akun(const char *username, const char *password, User users[], int user_count) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            return 1;
        }
    }
    return 0;
}

void membuat_akun() {
    char username[15];
    char password[15];

    printf("Buat username: ");
    scanf("%s", username);
    printf("Buat password: ");
    scanf("%s", password);

    FILE *file = fopen("data_akun.txt", "a");
    if (file == NULL) {
        printf("Tidak dapat membuka file data_akun.txt\n");
        return;
    }

    fprintf(file, "%s:%s\n", username, password);
    fclose(file);

    printf("Username dan password telah disimpan.\n");
    getchar(); // Mengonsumsi karakter newline sebelum masuk ke getchar()
    getchar(); // Menunggu pengguna menekan 'Enter'
}

int main() {
    int pilihanlogin;
    char username[15];
    char password[15];
    int exit_program = 0;
    User users[MAX_USERS];
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
                            printf("Pilih opsi (1-4): ");
                            scanf("%d", &pilihan);

                            switch (pilihan) {
                                case 1:
                                    menambahkan_barang();
                                    break;
                                case 2:
                                    menampilkan_daftar_barang();
                                    break;
                                case 3:
                                    pembayaran();
                                    break;
                                case 4:
                                    printf("Terima kasih, sampai jumpa!\n");
                                    break;
                                default:
                                    printf("Pilihan tidak valid. Silakan pilih kembali.\n");
                            }
                        } while (pilihan != 4);
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
