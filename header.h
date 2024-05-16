#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100
#define MAX_USERS 100
#define MAX_BARANG 100

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

// Prototipe fungsi
void menu_utama();
void simpan_data(Barang barang[], int jumlah_barang);
void muat_data(Barang barang[], int *jumlah_barang);
void menambahkan_barang(Barang barang[], int *jumlah_barang);
void menampilkan_daftar_barang();
void hapus_barang(const char *kode_barang);
void pembayaran();
int memuat_akun(User users[], int max_users);
int cek_data_akun(const char *username, const char *password, User users[], int user_count);
void membuat_akun();