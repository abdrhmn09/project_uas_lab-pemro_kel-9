#include <stdio.h> // Menyertakan pustaka standar input/output
#include <string.h> // Menyertakan pustaka string untuk manipulasi string

#define MAX_LENGTH 100 // Mendefinisikan panjang maksimum untuk baris dalam file
#define MAX_USERS 100 // Mendefinisikan jumlah maksimum pengguna yang dapat dimuat

typedef struct {
    char username[15]; // Mendefinisikan struktur User dengan anggota username
    char password[15]; // Mendefinisikan struktur User dengan anggota password
} User;

int memuat_akun(User users[], int max_users) {
    FILE *file = fopen("data_akun.txt", "r"); // Membuka file data_akun.txt untuk dibaca
    if (file == NULL) {
        printf("Tidak dapat membuka file data_akun.txt\n"); // Jika file tidak dapat dibuka, cetak pesan kesalahan
        return 0; // Mengembalikan 0 untuk menunjukkan tidak ada pengguna yang dimuat
    }

    char line[MAX_LENGTH]; // Menyiapkan buffer untuk membaca baris dari file
    int count = 0; // Menginisialisasi penghitung pengguna yang dimuat

    while (fgets(line, sizeof(line), file) && count < max_users) {
        if (sscanf(line, "%[^:]:%s", users[count].username, users[count].password) == 2) {
            count++; // Jika berhasil membaca username dan password, tambahkan ke array dan tingkatkan penghitung
        }
    }

    fclose(file); // Menutup file setelah selesai membaca
    return count; // Mengembalikan jumlah pengguna yang dimuat
}

int cek_data_akun(const char *username, const char *password, User users[], int user_count) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            return 1; // Jika username dan password cocok, kembalikan 1 (berhasil)
        }
    }
    return 0; // Jika tidak ditemukan kecocokan, kembalikan 0 (gagal)
}

void membuat_akun() {
    char username[15]; // Menyiapkan buffer untuk username
    char password[15]; // Menyiapkan buffer untuk password

    printf("Buat username: ");
    scanf("%s", username); // Meminta input username dari pengguna
    printf("Buat password: ");
    scanf("%s", password); // Meminta input password dari pengguna

    FILE *file = fopen("data_akun.txt", "a"); // Membuka file data_akun.txt untuk ditulis (menambah)
    if (file == NULL) {
        printf("Tidak dapat membuka file data_akun.txt\n"); // Jika file tidak dapat dibuka, cetak pesan kesalahan
        return; // Keluar dari fungsi jika gagal membuka file
    }

    fprintf(file, "%s:%s\n", username, password); // Menulis username dan password ke file
    fclose(file); // Menutup file setelah selesai menulis

    printf("Username dan password telah disimpan.\n"); // Memberitahu pengguna bahwa akun telah disimpan
    getchar(); // Mengonsumsi karakter newline sebelum masuk ke getchar() berikutnya
    getchar(); // Menunggu pengguna menekan 'Enter' untuk melanjutkan
}
