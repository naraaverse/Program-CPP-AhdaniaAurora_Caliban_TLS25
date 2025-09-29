#include <bits/stdc++.h>
using namespace std;

string balik_string(string teks){   // membalik kata
    string hasil = "";
    for(int i = teks.length() - 1; i >= 0; i--){
        hasil += teks[i];
    }
    return hasil;
}

string encode(string kata){ // fungsi encode: kata asli -> sandi unik
    char huruf_awal = kata[0];  // ambil huruf pertama
    int ASCII = (int)huruf_awal;    // ubah ke kode ASCII
    
    string tanpa_vokal = "";    // hapus huruf vokal
    for (int i = 0; i < kata.length(); i++) {
        char c = kata[i];
        if (c!='a' && c!='i' && c!='u' && c!='e' && c!='o' &&   // cek eksistensi huruf vokal
            c!='A' && c!='I' && c!='U' && c!='E' && c!='O') {
            tanpa_vokal += c;
        }
    }
    string balik = balik_string(tanpa_vokal);    // balik string

    int tengah = balik.length() / 2;
    string sandi_unik = balik.substr(0, tengah) + to_string(ASCII) + balik.substr(tengah);  // menggabungkan sandi
    return sandi_unik;
}

string decode(string sandi){  // fungsi decode: sandi -> kerangka kata asli
    string angka = "";
    for (int i = 0; i < sandi.length(); i++){
        if (sandi[i] >= '0' && sandi[i] <= '9') {   // cari angka kode ASCII
            angka += sandi[i];
        }
    }

    int ASCII = stoi(angka); // ubah string angka jadi integer
    char huruf_pertama = (char)ASCII;   // ubah kode angka jadi char ASCII

    string tanpa_angka = "";
    for (int i = 0; i < sandi.length(); i++){
        if (!(sandi[i] >= '0' && sandi[i] <= '9')) {    // hapus angka dari sandi
            tanpa_angka += sandi[i];
        }
    }
    string kerangka = balik_string(tanpa_angka);    // balik kata
    return kerangka;
}

int main(){
    int pilih;
    cout << "Pilih mode (1 = Encode, 2 = Decode): ";
    cin >> pilih;

    if(pilih == 1){
        string kata;
        cout << "Masukkan kata: ";
        cin >> kata;
        cout << "Sandi unik: " << encode(kata);
    }
    else if(pilih == 2){
        string sandi;
        cout << "Masukkan sandi: ";
        cin >> sandi;
        cout << "Kerangka kata asli: " << decode(sandi);
    }
    else{
        cout << "Pilihan tidak valid!";
    }
}
