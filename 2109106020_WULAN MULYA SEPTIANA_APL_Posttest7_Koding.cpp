#include <iostream>
#include <fstream>

using namespace std;

//prosedur untuk menampilkan judul
void judul(){
	cout << "=================================================" << endl;
	cout << "|                SELAMAT DATANG                 |" << endl;
	cout << "|                  DI PROGRAM                   |" << endl;
	cout << "|         ~ PENDATAAN PESERTA VAKSIN ~          |" << endl;
	cout << "=================================================" << endl;
}

//prosedur untuk menampilkan menu
void menu(){
	cout << "\n*************************************************" << endl;
	cout << "*                  M  E  N  U                   *" << endl;
	cout << "*************************************************" << endl;
	cout << "*		[1] Tambah Data                 *" << endl;
	cout << "*		[2] Tampilkan Data              *" << endl;
	cout << "*		[3] Ubah Data                   *" << endl;
	cout << "*		[4] Sorting/Pengurutan Data     *" << endl;
	cout << "*		[5] Searching/Pencarian Data    *" << endl;
	cout << "*		[6] Exit Program                *" << endl;
	cout << "*************************************************" << endl;
}

//deklarasi struct
struct vaksin{
	string nama,  jenis_vaksin;
	int umur, dosis;
};

//struct dengan array
vaksin batas[100];
//deklarasi variabel global
fstream dataVaksin;
int a, c, banyakdata, i;

//prosedur untuk membuka file
void bukaData(){
	//membuka file, jika tidak ada file sama sekali
	//maka dihitung sebagai membuat file
    dataVaksin.open("2109106020_WULAN MULYA SEPTIANA_APL_Posttest7_Data.txt", ios::out);
    if (!dataVaksin.is_open())
    {
    	//menghapus file sebelum membuka file, jika file ada
        dataVaksin.open("2109106020_WULAN MULYA SEPTIANA_APL_Posttest7_Data.txt", ios::trunc);
        dataVaksin.close();
    }
    //menutup file yang sudah kita buka
    dataVaksin.close();
}

void tulisData(){
    // Menulis file eksternal
    // ofstream myFile;
    dataVaksin.open("2109106020_WULAN MULYA SEPTIANA_APL_Posttest7_Data.txt", ios::out);
    for (int i = 0; i < a; i++)
	{
        dataVaksin << batas[a].nama << "," << batas[a].umur << "," << batas[a].jenis_vaksin << "," << batas[a].dosis << endl;
    }
    dataVaksin.close();
}

//prosedur untuk menambahkan data	
void tambahdata(){
	cout << "\nBanyaknya Data Yang Ingin Ditambahkan : "; cin >> banyakdata;
	dataVaksin.open("2109106020_WULAN MULYA SEPTIANA_APL_Posttest7_Data.txt", ios::out);
	//perulangan tambah data
	for(c = 0; c < banyakdata; c++){
		cout << "\nData ke-" << c+1 << endl;
		cout << "Nama Peserta\t: "; cin >> batas[a].nama;
		cout << "Umur Peserta\t: "; cin >> batas[a].umur;
		cout << "Jenis Vaksin\t: "; cin >> batas[a].jenis_vaksin;
		cout << "Dosis ke\t: "; cin >> batas[a].dosis;
		//proses menulis ke file
		dataVaksin << batas[a].nama << "," << batas[a].umur << "," << batas[a].jenis_vaksin << "," << batas[a].dosis << endl;
		cout<<"\n=========== Data Berhasil Ditambahkan ===========" << endl;
		a++;
	}
	//menutup file yang sudah kita buka
	dataVaksin.close();
}

//prosedur untuk menamampilkan data
void tampildata(){
	int i;		//deklarasi variabel
	dataVaksin.open("2109106020_WULAN MULYA SEPTIANA_APL_Posttest7_Data.txt", ios::in | ios::out);
	//perulangan tampilkan data
	for(i = 0; i < a; i++){
		//proses membaca file
		dataVaksin >> batas[a].nama >> batas[a].umur >> batas[a].jenis_vaksin >> batas[a].dosis;
		cout << "\nData ke-" << i+1 << endl;
		cout << "Nama Peserta\t: " << batas[i].nama << endl;
		cout << "Umur Peserta\t: " << batas[i].umur << endl;
		cout << "Jenis Vaksin\t: " << batas[i].jenis_vaksin << endl;
		cout << "Dosis ke\t: " << batas[i].dosis << endl;
	}
	//menutup file yang sudah kita buka
	dataVaksin.close();
}

//prosedur untuk mengubah data
void ubahdata(){
	int dataperubahan, ubah;		//deklarasi variabel
	dataVaksin.open("2109106020_WULAN MULYA SEPTIANA_APL_Posttest7_Data.txt", ios::in | ios::out);
	cout << "\nData Ke Berapa Yang Ingin Diubah : "; cin >> dataperubahan;
	ubah = dataperubahan-1;
	cout << "\nSILAHKAN MASUKKAN DATA BARU!!" << endl;
	cout << "Nama Peserta\t: "; cin >> batas[ubah].nama;
	cout << "Umur Peserta\t: "; cin >> batas[ubah].umur;
	cout << "Jenis Vaksin\t: "; cin >> batas[ubah].jenis_vaksin;
	cout << "Dosis ke\t: "; cin >> batas[ubah].dosis;
	dataVaksin.close();
	cout<<"\n============= Data Berhasil Diubah =============" << endl;
}	

//prosedur untuk menghapus file external
void hapusfile(){
	if (remove("2109106020_WULAN MULYA SEPTIANA_APL_Posttest7_Data.txt") == 0)
		cout << "\n********* File External Berhasil Dihapus *********" << endl;
	else
		cout << "\n******* File External Tidak Dapat Dihapus *******" << endl;
}

//prosedur metode InsertionSort variabel umur secara ascending
void sort_umur(){
	//menampilkan data sebelum disorting
	cout << "\n:::::::::::: Data Sebelum Disorting ::::::::::::" << endl;
	cout << "************************************************" << endl;
	tampildata();
	//perulangan untuk mengakses data
    for(int i = 1; i < a; i++)
    {
        int key = i;
        //perulangan untuk menukar posisi data yang akan ditukar
        while(batas[key].umur < batas[key-1].umur && key > 0)
        {
            swap(batas[key], batas[key-1]);
            key--;
        }
    }
    //menampilkan data setelah disorting
    cout << "\n:::: Data Setelah Disorting Dengan Metode Insertion Sort ::::" << endl;
	cout << "*************************************************************" << endl;
    tampildata();
}

//prosedur metode InsertionSort variabel dosis secara ascending
void sort_dosis(){
	//menampilkan data sebelum disorting
	cout << "\n:::::::::::: Data Sebelum Disorting ::::::::::::" << endl;
	cout << "************************************************" << endl;
	tampildata();
	//perulangan untuk mengakses data
    for(int i = 1; i < a; i++)
    {
        int key = i;
        //perulangan untuk menukar posisi data yang akan ditukar
        while(batas[key].dosis < batas[key-1].dosis && key > 0)
        {
            swap(batas[key], batas[key-1]);
            key--;
        }
    }
    //menampilkan data setelah disorting
    cout << "\n:::: Data Setelah Disorting Dengan Metode Insertion Sort ::::" << endl;
	cout << "*************************************************************" << endl;
    tampildata();
}

//fungsi metode Sequential Search variabel nama peserta
int search_nama(int banyakdata){
	//deklarasi variabel
    string kunci;
    int cocok;
    
    // input nama yang ingin dicari
	cout << "Masukkan Nama Yang Ingin Anda Cari : ";
    fflush(stdin);
    getline(cin, kunci);
    
    //perulangan metode sequential search
    for(i = 0; i < banyakdata; i++){
        if (batas[i].nama == kunci){
        	cocok = true;
        	break;
        }
    }
    //untuk menampilkan jika data ditemukan
    if (cocok == 1){
        cout << "\n-------------------------------------------------" << endl;
        cout << "                  Data Ditemukan" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "Nama Peserta\t: " << batas[i].nama << endl;
        cout << "Umur Peserta\t: " << batas[i].umur << endl;
        cout << "Jenis Vaksin\t: " << batas[i].jenis_vaksin << endl;
        cout << "Dosis ke\t: " << batas[i].dosis << endl;
        cout << "-------------------------------------------------" << endl;
   }
   //untuk menampilkan jika data tidak ditemukan
	else{
		cout << "\n-------------------------------------------------" << endl;
		cout << "       Data Yang Anda Cari Tidak Ditemukan" << endl;
		cout << "-------------------------------------------------" << endl;
	}	
    return 0;
}
	
//fungsi metode Sequential Search variabel umur peserta
int search_umur(int banyakdata){
	//deklarasi variabel
    int cocok, kunci;
    
    // input nama yang ingin dicari
	cout << "Masukkan Umur Yang Ingin Anda Cari : "; cin >> kunci;
    
    //perulangan metode sequential search
    for(i = 0; i < banyakdata; i++){
        if (batas[i].umur == kunci){
        	cocok = true;
        	break;
        }
    }
    //untuk menampilkan jika data ditemukan
    if (cocok == 1){
        cout << "\n-------------------------------------------------" << endl;
        cout << "                  Data Ditemukan" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "Nama Peserta\t: " << batas[i].nama << endl;
        cout << "Umur Peserta\t: " << batas[i].umur << endl;
        cout << "Jenis Vaksin\t: " << batas[i].jenis_vaksin << endl;
        cout << "Dosis ke\t: " << batas[i].dosis << endl;
        cout << "-------------------------------------------------" << endl;
   }
   //untuk menampilkan jika data tidak ditemukan
	else{
		cout << "\n-------------------------------------------------" << endl;
		cout << "       Data Yang Anda Cari Tidak Ditemukan" << endl;
		cout << "-------------------------------------------------" << endl;
	}	
    return 0;
}

//fungsi metode Sequential Search variabel jenis vaksin
int search_jenis(int banyakdata){
	//deklarasi variabel
    string kunci;
    int cocok;
    
    // input jenis vaksin yang ingin dicari
	cout << "Masukkan Jenis Vaksin Yang Ingin Anda Cari : ";
    fflush(stdin);
    getline(cin, kunci);
    
    //perulangan metode sequential search
    for(i = 0; i < banyakdata; i++){
        if (batas[i].jenis_vaksin == kunci){
        	cocok = true;
        	break;
        }
    }
    //untuk menampilkan jika data ditemukan
    if (cocok == 1){
        cout << "\n-------------------------------------------------" << endl;
        cout << "                  Data Ditemukan" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "Nama Peserta\t: " << batas[i].nama << endl;
        cout << "Umur Peserta\t: " << batas[i].umur << endl;
        cout << "Jenis Vaksin\t: " << batas[i].jenis_vaksin << endl;
        cout << "Dosis ke\t: " << batas[i].dosis << endl;
        cout << "-------------------------------------------------" << endl;
   }
   //untuk menampilkan jika data tidak ditemukan
	else{
		cout << "\n-------------------------------------------------" << endl;
		cout << "       Data Yang Anda Cari Tidak Ditemukan" << endl;
		cout << "-------------------------------------------------" << endl;
	}	
    return 0;
}

//fungsi metode Sequential Search variabel dosis vaksin
int search_dosis(int banyakdata){
	//deklarasi variabel
    int cocok, kunci;
    
    // input jenis vaksin yang ingin dicari
	cout << "Masukkan Dosis Vaksin Yang Ingin Anda Cari : "; cin >> kunci;
    
    //perulangan metode sequential search
    for(i = 0; i < banyakdata; i++){
        if (batas[i].dosis == kunci){
        	cocok = true;
        	break;
        }
    }
    //untuk menampilkan jika data ditemukan
    if (cocok == 1){
        cout << "\n-------------------------------------------------" << endl;
        cout << "                  Data Ditemukan" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "Nama Peserta\t: " << batas[i].nama << endl;
        cout << "Umur Peserta\t: " << batas[i].umur << endl;
        cout << "Jenis Vaksin\t: " << batas[i].jenis_vaksin << endl;
        cout << "Dosis ke\t: " << batas[i].dosis << endl;
        cout << "-------------------------------------------------" << endl;
   }
   //untuk menampilkan jika data tidak ditemukan
	else{
		cout << "\n-------------------------------------------------" << endl;
		cout << "       Data Yang Anda Cari Tidak Ditemukan" << endl;
		cout << "-------------------------------------------------" << endl;
	}	
    return 0;
}

//fungsi utama program	
int main(){
	bukaData();		//memanggil prosedur
	tulisData();	//memanggil prosedur
	judul();	//memanggil prosedur
	awal:
	menu();		//memanggil prosedur

	//deklarasi variabel
	int pilih, pilihvariabel;
	char keluar;
	
	//percabangan pilihan menu
	cout << "\nMasukkan Pilihan : "; cin >> pilih;
	if(pilih==1){
		tambahdata(); goto awal;
	}
	else if(pilih==2){
		tampildata(); goto awal;
	}
	else if(pilih==3){
		ubahdata(); goto awal;
	}
	else if(pilih==4){
		int pilihvariabel;
		//tampilan menu variabel yang ingin disorting
		cout << "\nApa Yang Ingin Anda Sorting?" << endl;
		cout << "[1] Sorting Umur Peserta" << endl;
		cout << "[2] Sorting Dosis" << endl;
		cout << "\nMasukkan Pilihan Anda [1/2] : "; cin >> pilihvariabel;
		cout << endl;
		//percabangan pilihan variabel yang ingin disorting
		if(pilihvariabel==1){
			sort_umur(); goto awal;
		}		
		else if(pilihvariabel==2){
			sort_dosis(); goto awal;
		}
		else{
			cout << "\n------ Pilihan Yang Anda Masukkan Salah !!! ------" << endl; goto awal;
		}
	}
	else if(pilih==5){
		int pilihvariabel;
		//tampilan menu variabel yang ingin disearching
		cout << "\nApa Yang Ingin Anda Searching?" << endl;
		cout << "[1] Searching Nama Peserta" << endl;
		cout << "[2] Searching Umur Peserta" << endl;
		cout << "[3] Searching Jenis Vaksin" << endl;
		cout << "[4] Searching Dosis" << endl;
		cout << "\nMasukkan Pilihan Anda [1/2/3/4] : "; cin >> pilihvariabel;
		cout << endl;
		//percabangan pilihan variabel yang ingin disearching
		if(pilihvariabel==1){
			search_nama(sizeof(batas[a]).nama); goto awal;
		}		
		else if(pilihvariabel==2){
			search_umur(sizeof(batas[a]).umur); goto awal;
		}
		else if(pilihvariabel==3){
			search_jenis(sizeof(batas[a]).jenis_vaksin); goto awal;
		}
		else if(pilihvariabel==4){
			search_dosis(sizeof(batas[a]).dosis); goto awal;
		}
		else{
			cout << "\n------ Pilihan Yang Anda Masukkan Salah !!! ------" << endl; goto awal;
		}
	}
	else if(pilih==6){
    cout << "\nApakah Anda Yakin Keluar Dari Program?? [y/n] : "; cin >> keluar;
    cout << endl;
    	if(keluar=='y'||keluar=='Y'){
    		hapusfile();
			cout << "\n========= ANDA TELAH KELUAR DARI PROGRAM =========" << endl;
			cout << "=== Terima Kasih Telah Menggunakan Program ^_^ ===" << endl;
		}
    	else if(keluar=='n'||keluar=='N'){
			goto awal;
		}
		else{
			cout << "\n------ Pilihan Yang Anda Masukkan Salah !!! ------" << endl; goto awal;
		}
	}
	else{
		cout << "\n-------- Pilihan Yang Anda Masukkan Salah !!! --------" << endl;
		cout << "\nSilahkan Masukkan Pilihan Dengan Benar [1/2/3/4/5/6/7]" << endl; goto awal;
	}
}
