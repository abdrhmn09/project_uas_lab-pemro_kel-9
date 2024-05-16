#include "header.h" // Menyertakan file header yang berisi deklarasi fungsi dan definisi tipe data

int main() {
    int pilihanlogin; // Variabel untuk menyimpan pilihan login dari pengguna
    char username[15]; // Array untuk menyimpan username yang dimasukkan oleh pengguna
    char password[15]; // Array untuk menyimpan password yang dimasukkan oleh pengguna
    char kode_barang[10]; // Array untuk menyimpan kode barang yang akan dihapus
    int exit_program = 0; // Variabel untuk mengendalikan loop utama program
    User users[MAX_USERS]; // Array untuk menyimpan data pengguna
    Barang barang[MAX_BARANG]; // Array untuk menyimpan data barang
    int jumlah_barang = 0; // Variabel untuk menyimpan jumlah barang yang ada
    int user_count = memuat_akun(users, MAX_USERS); // Variabel untuk menyimpan jumlah barang yang ada

    while (!exit_program) { // Loop utama program, berjalan selama exit_program tidak bernilai 1
        printf("1. Login\n");
        printf("2. Daftar akun\n");
        printf("3. Keluar\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &pilihanlogin); // Menerima input pilihan login dari pengguna

        switch (pilihanlogin) { // Memeriksa pilihan login yang dimasukkan pengguna
            case 1: // Jika pengguna memilih untuk login
                do {
                    printf("Masukkan username: ");
                    scanf("%s", username); // Menerima input username dari pengguna
                    printf("Masukkan password: ");
                    scanf("%s", password); // Menerima input password dari pengguna

                    if (cek_data_akun(username, password, users, user_count)) { // Memeriksa apakah username dan password valid
                        int pilihan; // Variabel untuk menyimpan pilihan menu utama
                        do {
                            menu_utama(); // Menampilkan menu utama
                            printf("Pilih opsi (1-5): ");
                            scanf("%d", &pilihan); // Menerima input pilihan dari pengguna

                            switch (pilihan) { // Memeriksa pilihan menu utama yang dimasukkan pengguna
                                case 1:
                                    menambahkan_barang(barang, &jumlah_barang); // Memanggil fungsi untuk menambahkan barang
                                    break;
                                case 2:
                                    menampilkan_daftar_barang(); // Memanggil fungsi untuk menampilkan daftar barang
                                    break;
                                case 3:
                                    pembayaran(); // Memanggil fungsi untuk melakukan pembayaran
                                    break;
                                case 4:
                                    printf("Masukkan kode barang yang ingin dihapus: ");
                                    scanf("%s", kode_barang); // Menerima input kode barang yang akan dihapus
                                    hapus_barang(kode_barang); // Memanggil fungsi untuk menghapus barang berdasarkan kode
                                    break;
                                case 5:
                                    break; // Keluar dari loop menu utama
                                default:
                                    printf("Pilihan tidak valid. Silakan pilih kembali.\n"); // Menampilkan pesan kesalahan
                            }
                        } while (pilihan != 5); // Loop menu utama, berjalan selama pilihan tidak sama dengan 5
                        break; // Keluar dari loop login untuk kembali ke menu utama
                    } else {
                        printf("Username atau password salah. Silakan coba lagi.\n"); // Menampilkan pesan kesalahan jika username atau password salah
                        break;
                    }
                } while (1); // Loop login, berjalan terus sampai pengguna berhasil login
                break;

            case 2: // Jika pengguna memilih untuk mendaftar akun baru
                membuat_akun(); // Memanggil fungsi untuk membuat akun baru
                user_count = memuat_akun(users, MAX_USERS); // memuat ulang data akun setelah membuat akun baru
                break;
            case 3: // Jika pengguna memilih untuk keluar
                exit_program = 1; // Mengubah nilai exit_program menjadi 1 untuk keluar dari loop utama
                printf("Terima kasih, sampai jumpa!\n"); // Menampilkan pesan selamat tinggal
                break;
            default:
                printf("Pilihan tidak valid. Silakan pilih kembali.\n"); // Menampilkan pesan kesalahan jika pilihan tidak valid
        }
    }

    return 0;
}