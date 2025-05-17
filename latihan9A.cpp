#include <iostream>
#include <string>
using namespace std;

class Dosen;
class Staff;


class Mahasiswa {
private:
    string nama;
    string NIM;
    float nilai;

public:
    Mahasiswa(string n, string nim) : nama(n), NIM(nim), nilai(0.0) {}

   
    friend class Dosen;
};


class Dosen {
private:
    string nama;
    string NIDN;
    string pangkat;
    float gaji;

public:
    Dosen(string n, string nidn, string p, float g) : nama(n), NIDN(nidn), pangkat(p), gaji(g) {}

  
    void beriNilai(Mahasiswa *m, float nilai) {
        m->nilai = nilai;
    }

   
    friend class Staff;
};

class Staff {
private:
    string nama;
    string IDStaff;
    float gaji;

public:
    Staff(string n, string id, float g) : nama(n), IDStaff(id), gaji(g) {}

  
    void ubahPangkat(Dosen *d, string pangkatBaru) {
        d->pangkat = pangkatBaru;
    }

   
    friend void LihatGajiStaff(Staff *s);
};


void LihatGajiStaff(Staff *s) {
    cout << "Gaji Staff " << s->nama << " adalah: " << s->gaji << endl;
}


int main() {
   
    Mahasiswa mhs("Budi", "123456");
    
  
    Dosen dsn("Dr. Ahmad", "98765", "Lektor", 15000000);

    Staff stf("Aziz", "AZ123", 5000000);

    dsn.beriNilai(&mhs, 85.5);
    cout << "Nilai mahasiswa Budi setelah dinilai oleh Dr. Ahmad: 85.5" << endl;

    stf.ubahPangkat(&dsn, "Lektor Kepala");
    cout << "Pangkat dosen setelah diubah oleh staff: Lektor Kepala" << endl;
    LihatGajiStaff(&stf);

    return 0;
}