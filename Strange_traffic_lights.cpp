#include <iostream>
using namespace std;

int main(){
    int detik;
    cin >> detik;

    // menghitung posisi warna lampu berdasarkan siklus 103 detik
    // ditambah 79 karena lampu tidak dimulai dari detik 1
    int warna = (detik + 79) % 103; 

    if (warna >= 1 && warna <= 20){ // range 1-20 warna lampu hijau
        cout << "Lampu menunjukkan warna hijau";
    }
    else if (warna >= 21 && warna <= 23) {  // range 21-23 warna lampu kuning
        cout << "Lampu menunjukkan warna kuning";
    }
    else{   // selain itu warna lampu merah
        cout << "Lampu menunjukkan warna merah";
    }
}
