#include <iostream>
#include "mylibrary.h"
#include <conio.h>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <ctime>
#include <Tchar.h>
using namespace std;
#define MAX 500
#define TRUE 1
#define FALSE 0

// ---- Khai Bao ---- //
struct CT_HOADON{
	string MAVT;
	int soluong;
	double VAT;
	unsigned long dongia;
	struct CT_HOADON *next;
};
struct date{
	int day;
	int month;
	int year;
};
struct nodeHoaDon{
	string SoHD;
	date Ngay;
	char Loai;
	int MANV;
	CT_HOADON *CT_HD ;
};
struct HOADON{
	nodeHoaDon HoaDon;
 	struct HOADON *next;
};
struct Vat_tu{
	string maVT;
	string tenVT;
	string dVT;
	int soLuongTon;
	int TansuatN;
	int TansuatX;
};
struct VatTu{
	Vat_tu Vattu[MAX];
	int soVatTu;
};
VatTu VatTu; //Danh sach tuyen tinh.
struct nodeNhanVien{
	int maNV;
	string ho;
	string ten;
	string phai;
	struct HOADON *HoaDon = NULL;
};
struct CayNhanVien{
	nodeNhanVien nhanVien;
	struct CayNhanVien *left;
	struct CayNhanVien *right;
};
typedef struct CayNhanVien *PTRCay; // Cay nhi phan.
PTRCay cayNhanVien = NULL;
// PHAN CUA SINH VIEN: DOAN NGOC VUONG.
	// Cac ham ve do hoa,thiet lap.
void ChayChu(string k, int n, int x,int y);
void KhungKetThuc();
void KhungNhap();
void KhungTieuDe(string s);
int YN(string s);
void KhungTim(string s, int c);
void CuaSoConsole();
	// Cac ham lien quan den quan li vat tu.
int StringToInt(string s);
string IntToString(int x);
int KT_ChuSo(double x);
int Ktra_Dodai_Ma(string s);
int Ktra_Trung_MaVT(int n);
int Ktra_Chuoi(string s);
int Ktra_soLuongTon(string s);
void ChuThich_Nhap_VT(int flag);
int Search_VT(string maVT);
void Insert_VT(struct VatTu VatTu, struct Vat_tu newVatTu);
void Xoa_VT_maVT(string maVT);
void Xoa_VT(int i);
int NhapVatTu();
void LoadVatTu(int vtht);
void ChucNang_DSVT(int f);
void XemVatTu();
	// Cac ham Menu.
void MenuChinh();
void MenuCon(string menu[]);
void LoadMenu();
void Select();
	// Luu va load vao file.
void Save_Vat_Tu();
void Load_Vat_Tu();
//PHAN CUA SINH VIEN: PHAM VAN KHANH.
	// Cac ham lien quan den quan li nhan vien.
int SinhNgauNhien();
void insert_tree(PTRCay &p,nodeNhanVien a);
int Ktra_NV(string s);
void ChuThich_Loi_NV(int x);
PTRCay searchNV(PTRCay &p, int mstk);
void SavePhu();
void LoadPhu();
void taofile(char* tenfile);
void LoadNV();
int NhapNV();
void remove_case3(PTRCay &r);
int remove_tree(PTRCay &p, int x);
void SaveNV(PTRCay p);
void LoadNV();
int TimViTriNV(nodeNhanVien a[],int maNV);
void Xoa_NV_maNV(int maNV, nodeNhanVien a[]);
void Xoa_NV(int i,nodeNhanVien a[]);
void SapXepNV(nodeNhanVien a[]);
void LoadDSNV(int vtht, nodeNhanVien a[]);
void ChucNang_DSNV(int f);
void ChepMangNV(PTRCay p, nodeNhanVien a[]);
void inDSNV();
void XemNV(PTRCay nv);
void XoaNV(PTRCay &root);
	// Cac ham lien quan den quan li hoa don.
void ThoiGian();
void In_huong_dan_Nhap_HD();
void Insert_Vattu(CT_HOADON *&First, string MaVT, long dongia, int soluong);
int Ktra_trung_SHD(string s,PTRCay p);
int ktra_Vtu(string s, int &i);
int CHECK_NGAY(int ngay, int thang, int nam);
void Nhap_DS_Vattu(CT_HOADON *&First, int tinhieu,int maNV);
int CHECK_MANV(int a);
void Insert_hoadon(string MSHD, string MaNV, date Ngay, char loai,CT_HOADON *&First);
void NhapHoaDon(int tinhieu);
void Chi_Tiet_HD(HOADON *F);
HOADON* TimHD(PTRCay p, string find);
void In_Thong_Tin_Theo_SoHD(string find);
int SoSanhNgay(date a,date b);
void In_Mot_Hoa_Don();
void In_Hoa_Don(HOADON *q, date a, date b);
void Thong_Ke_Hoa_Don();
void ThongKeTanSuat();
	//Luu va load vao file.
void SaveHD();
void LoadHD();
// --- Do Hoa --- //
void Highlight_Menu(){
    SetBGColor(15);
    SetColor(0);
}
void Highlight(){
    SetBGColor(10);
    SetColor(12);
}
void Highligh_Miss(){
    SetBGColor(15);
    SetColor(12);
}
void ChonMau(){
	SetBGColor(4);
	SetColor(14);
}
void ChonMau2(){
	SetBGColor(7);
	SetColor(4);
}
void ChonMau3(){
	SetBGColor(7);
	SetColor(4);
}
void ChonMau4(){
	SetBGColor(3);
	SetColor(15);
}
void MauMacDinh(){
	SetBGColor(0);
	SetColor(15);
}
void MauNen1(){
	SetBGColor(3);
	system("cls");
}
void ChayChu(string k , int n, int x,int y){
	char chuoi[n-1];
	int doDaiThieu = n - k.size();
	for(int i = 0; i <= doDaiThieu ; i++){ k = k +" "; }
	for(int j =0 ; j < n ; j++){ chuoi[j] = k[j]; }
	while(!kbhit()){
	for(int j = n-1; j >= 0 ; j--){
			chuoi[j+1] = chuoi[j];
		}
		chuoi[0] = chuoi[n-1];
		gotoxy(x,y);
		for (int j =0 ; j < n ; j++){
			cout << chuoi[j];
		}
		Sleep(200);
	}
}	
void KhungKetThuc(){ //Xuat hien khi ket thuc chuong trinh.
	MauNen1();
	gotoxy(10,5);
	SetColor(14);
	for(int i = 10 ; i<=70 ; i++){
		if(i == 10) cout << char(201);
		else if(i==70) cout << char(187);
		else cout << char(205);
	}
	ChonMau2();
	gotoxy(30,5); cout << "   WRITTEN BY C++   ";
	ChonMau4();
	SetColor(14);
	for( int i = 6 ; i<=15 ; i++){
		gotoxy(10,i);
		if(i==15) cout << char(200);
		else cout << char(186);
		gotoxy(70,i);
		if(i==15) cout << char(188);
		else cout << char(186);
	}
	gotoxy(11,15);
	for(int i = 11 ; i<70 ; i++){
		cout << char(205);
	}
	int x = 20;
	int y = 7;
	gotoxy(x,y-1); cout << "**************************************";
	gotoxy(x,y+1); cout << "DE TAI: Chuong trinh quan li vat tu";
	gotoxy(x,y+2); cout << "Giao vien huong dan: Luu Nguyen Ky Thu";
	gotoxy(x,y+3); cout << "            Thuc hien boi:";
	gotoxy(x,y+4); cout << "*Console graphics va quan li vat tu:";
	gotoxy(x,y+5); cout << "   N14DCAT138 - Doan Ngoc Vuong";
	gotoxy(x,y+6); cout << "*Quan li nhan su va quan li hoa don:";
	gotoxy(x,y+7); cout << "   N14DCAT067 - Pham Van Khanh";
	ChayChu("MON: CAU TRUC DU LIEU VA GIAI THUAT",59,11,y);
	gotoxy(0,25);
}
void KhungNhap(){
	ChonMau4();
	gotoxy(1,5);
	for(int i = 1 ; i<= 78 ; i++){
		if( i <3)
			cout << " ";
		else if ( i> 78)
			cout << " ";
		else if( i == 3) cout << char(218);
		else if(i == 15 ||i ==45 || i== 65)	cout << char(194);
		else if(i == 78) cout << char(191);
		else cout << char(196);}
	for(int i=1;i<=14;i++){
		gotoxy(3,i+5);
		if(i==2) cout << char(195);
		else cout << char(179);
		gotoxy(78,i+5);
		if(i==2) cout << char(180);
		else cout << char(179);
		gotoxy(15,i+5);
		if(i==2) cout << char(197);
		else cout << char(179);
		gotoxy(45,i+5);
		if(i==2) cout << char(197);
		else cout << char(179);
		gotoxy(65,i+5);
		if(i==2) cout << char(197);
		else cout << char(179);
	}
	gotoxy(1,20);
	for(int i = 1 ; i<= 78 ; i++){
		if( i <3)
			cout << " ";
		else if ( i> 78)
			cout << " ";
		else if( i == 3) cout << char(192);
		else if(i == 15 || i ==45 || i== 65)	cout << char(193);
		else if(i == 78) cout << char(217);
		else cout << char(196);}
	gotoxy(1,7);
	for(int i = 1 ; i<= 78 ; i++){
		if( i <3)
			cout << " ";
		else if( i == 3)
			cout << char(195);
		else if( i== 78)
			cout << char(180);
		else if ( i> 78)
			cout << " ";
		else if(i == 15 || i ==45 || i== 65)	cout << char(197);
		else cout << char(196);}   
	gotoxy(0,25);
}
void KhungTieuDe(string s){
	SetBGColor(6);
	SetColor(14);
	int n = s.size();
	int x = (80 - n) / 2;
	gotoxy(x-1,0);
	for(int i = x-1 ; i<=(x+n+1) ; i++){
		if(i == (x-1) ) cout << char(201);
		if(i == (x+n+1)) cout << char(187);
		else cout << char(205);
	}
	gotoxy(x-1,1);
	for(int i = x-1 ; i <=(x+n+1+1) ; i++){
		if( i == (x-1)) cout << char(185);
		else if(i == (x+n+1+1) ) cout << char(204);
		else cout << " ";
	}
	gotoxy(x,1);
	cout << s;
	gotoxy(x-1,2);
	for(int i = x-1 ; i <= (x+n+1) ; i++){
		if(i == (x-1) ) cout << char(200);
		if(i == (x+n+1)) cout << char(188);
		else cout << char(205);
	}
	ChonMau4();
	SetColor(14);
	//Tao vien.
	gotoxy(0,1);
	for(int i = 0 ; i<= x-2 ; i++){
		if(i == 0) cout << char(201);
		else 
			cout << char(205);
	}
	gotoxy(x+n+3,1);
	for(int i =x+n+3 ;i<=79; i++){
		if(i == 79) cout << char(187);
		else 
			cout << char(205);
	}
	for(int i = 2; i< 28; i++){
		gotoxy(0,i); cout << char(186);
		gotoxy(79,i); cout << char(186);
	}
	gotoxy(0,28);
	for(int i =0; i<=79 ; i++){
		if(i==0) cout<< char(200);
		else if(i==79) cout << char(188);
		else cout << char(205);
	}
	
}
int YN(string s){ // Tra ve 1 neu Co, 0 neu Khong.
	int PASS = 1;
	int chon =1;
	int n = s.size();
	int c = (40- n)/2;
	ChonMau3();
	gotoxy(20,9);
	for(int i = 0; i<= c ; i++){
		cout << " ";
	}
	gotoxy(20+c,9); cout << s;
	gotoxy(60 - c -1,9); 
	for(int i = 0; i<= (40- n)/2 ; i++){
		cout << " ";
	}
	gotoxy(20,10);
	cout <<"                                        ";
	while(PASS){
		if(chon == 1){
			gotoxy(20+2,10); ChonMau();
			cout <<"  CO   ";
			gotoxy(60-9,10); ChonMau2();
			cout <<" KHONG ";
			ChonMau4();
		}
		else{
			gotoxy(20+2,10); ChonMau2();
			cout <<"  CO   ";
			gotoxy(60-9,10); ChonMau();
			cout <<" KHONG ";
		}
		ChonMau3();
		gotoxy(20,11);
		cout <<"                                        ";
		ChonMau4();
		int c = getch();
		if(c==0 ) c=getch();
		switch(c){
			case 13:
				if(chon == 1){
					ChonMau4();
					gotoxy(20,9); cout <<"                                        ";
					gotoxy(20,10);cout <<"                                        ";
					gotoxy(20,11);cout <<"                                        ";
					gotoxy(45,9); cout << char(179);
					gotoxy(45,10); cout << char(179);
					gotoxy(45,11); cout << char(179);
					return TRUE;}
				else if(chon == 2){
					ChonMau4();
					gotoxy(20,9); cout <<"                                        ";
					gotoxy(20,10);cout <<"                                        ";
					gotoxy(20,11);cout <<"                                        ";
					gotoxy(45,9); cout << char(179);
					gotoxy(45,10); cout << char(179);
					gotoxy(45,11); cout << char(179);
					return FALSE;}	
				break;
			case 27:
					ChonMau4();
					gotoxy(20,9); cout <<"                                        ";
					gotoxy(20,10);cout <<"                                        ";
					gotoxy(20,11);cout <<"                                        ";
					gotoxy(45,9); cout << char(179);
					gotoxy(45,10); cout << char(179);
					gotoxy(45,11); cout << char(179);
					return FALSE;
			case 75:
				if(chon == 1)
					chon = 2;
				else if(chon ==2)
					chon = 1;
				break;
			case 77:
				if(chon == 1)
					chon = 2;
				else if(chon ==2)
					chon = 1;
				break;
		}
	}
}
void KhungTim(string s, int c){ // Neu c = 1 thi hien khung, c = 0 thi xoa khung;
	if(c == 0){
		ChonMau4();
		gotoxy(1,2); cout <<"                        ";
		gotoxy(1,3); cout <<"                        ";
		gotoxy(1,4); cout <<"                        ";
	}
	if (c==1){
		ChonMau2();
		gotoxy(1,2); cout <<"     "<< s <<"     ";
		gotoxy(1,3); cout <<"     ";
		SetBGColor(15); cout <<"              "; 
		ChonMau2();  cout <<"     ";
		gotoxy(1,4); cout <<"                        ";
	}
}
//Thiet lap cua so console.
void CuaSoConsole(){
	HANDLE wHnd;
	HANDLE rHnd; 
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleTitle("DE TAI: QUAN LI VAT TU");
	SMALL_RECT windowSize = {0, 0, 80, 30};
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
}
//-----Cac ham lien quan den vat tu-----//
int StringToInt(string s){ //Ep kieu string sang kieu int
	char *a=new char[20];
	for(int i=0;i<s.size();i++){
		a[i]=s[i];
		a[i+1]=NULL;
	}
	int s1=atoi(a);
	return s1;
}
string rutstring( string s ){
	string s1;
	int i = 0;
	while(i <= s.size()){
		if(s[i] != ' '){
			s1.insert(s1.end(),1,s[i]);
			i++;
		}
		else{
			while(s[i] == ' '){
				i++;
			}
			s1.insert(s1.end(),1,' ');
		}
	}
	if(s1[0]==' ')
		s1.erase(0,1);
	return s1;
}
string IntToString(int x){
	char a[10];
	itoa(x,a,10);
	string s(a);
	return s;
}
int KT_ChuSo(double x){
	int dem;
	while(x>=1){
		if(x / 10 > 0) dem++;
		x = x/10;
	}
	return dem;
}
int Ktra_Dodai_Ma(string s){
    if (s.size()==6) return TRUE;
    return FALSE;
} 
int Ktra_Trung_MaVT(int n){
    for(int j=0; VatTu.Vattu[j].maVT != ""; j++)
        if(VatTu.Vattu[j].maVT == VatTu.Vattu[n].maVT && n != j )
            return FALSE;
    return TRUE;
}
int Ktra_Chuoi(string s){
    if (s.size()==0) return FALSE;
    return TRUE;
}
int Ktra_soLuongTon(string s){	
	for(int i=0;i<s.size();i++)
		{
		if(s[i]<48||s[i]>57)
			return FALSE;}
		return TRUE;
}
void ChuThich_Nhap_VT(int flag){
	ChonMau4();
	SetColor(14);
	gotoxy(3,4);
	cout << "                                                       ";
	gotoxy(3,4);
	switch(flag){
		case 1:
			cout << "*Chu y: Ma vat tu la chuoi,bao gom 6 ki tu.";
			break;
		case 2:
			cout << "*Chu y: Ten vat tu khong duoc de trong.";
			break;
		case 3:
			cout << "*Chu y: Don vi tinh khong duoc de trong.";
			break;
		case 4:
			cout << "*Chu y: So luong ton la so nguyen.";
			break;
	}
	ChonMau4();
}
void ChuThich_Loi_VT(int x){
	ChonMau4();
	SetColor(14);
	gotoxy(3,4);
	cout << "                                            ";
	gotoxy(3,4);
	switch(x){
		case 0:
			cout << "                                            ";
			break;
		case 1:
			cout << "Loi: Ma vat tu phai bao gom 6 ki tu.";
			break;
		case 2:
			cout << "Loi: Ma vat tu bi trung.";
			break;
		case 3:
			cout << "Loi: Ten vat tu de trong.";
			break;
		case 4:
			cout << "Loi: Don vi tinh de trong.";
			break;
		case 5:
			cout << "Loi: So luong ton de trong";
			break;
		case 6:
			cout << "Loi: So luong ton phai la so";
			break;
	}
	ChonMau4();
}
int Search_VT(string maVT){
	for(int i = 0 ; i< VatTu.soVatTu; i++)
		if(VatTu.Vattu[i].maVT == maVT)
			return i;
	return -1;
}
void Insert_VT(struct VatTu VatTu, struct Vat_tu newVatTu){
	VatTu.soVatTu++;
	VatTu.Vattu[VatTu.soVatTu-1] = newVatTu;
}
void Xoa_VT_maVT(string maVT){
	int i = Search_VT(maVT);
	for(int j= i; j < VatTu.soVatTu-1 ; j++){
		VatTu.Vattu[j] = VatTu.Vattu[j+1];
	}
	VatTu.soVatTu--;
}
void Xoa_VT(int i){
	for(int j = i; j < VatTu.soVatTu-1 ; j++){
		VatTu.Vattu[j] = VatTu.Vattu[j+1];
	}
	VatTu.soVatTu--;
}
//------------Quan li vat tu---------------//
int NhapVatTu(){
	MauNen1();
	string SLT; // Tao chuoi so luong ton.
	int cot1 = 4, cot2 = 18 , cot3 = 47, cot4 =66;
	int flag =1 ; //Dang Nhap: 1: Ma VT, 2:Ten VT, 3:DVT , 4: SLT.
	int vitri, y = 8 , hangtb= 21;
	int PASS =1, n=VatTu.soVatTu;
	KhungTieuDe("    NHAP VAT TU     ");
	KhungNhap();
	gotoxy(cot1,6); cout << "Ma Vat Tu";
	gotoxy(cot2+7,6); cout <<"Ten Vat Tu";
	gotoxy(cot3+3,6); cout <<"Don Vi Tinh";
	gotoxy(cot4,6); cout <<"So Luong Ton";
	SetColor(14);
	gotoxy(3,21); cout <<"HDSD: Su dung phim mui ten de di chuyen.";
	gotoxy(3,22); cout << "Ecs de thoat.";
	ChonMau4();
	gotoxy(cot1,y);
	while(PASS){
		if(y == 21){
			KhungNhap();
		}
		while(kbhit()){
			ChuThich_Nhap_VT(flag);
			if (flag == 1)
				vitri = cot1 + VatTu.Vattu[n].maVT.size();
			if (flag == 2)
				vitri = cot2 + VatTu.Vattu[n].tenVT.size();
			if (flag == 3)
				vitri = cot3 + VatTu.Vattu[n].dVT.size();
			if (flag == 4)
				vitri = cot4 + SLT.size();
			char c = getch();
			if (c == 27){
				if( YN("BAN CO MUON LUU VAO FILE KHONG?") == 1)
					Save_Vat_Tu();
				PASS = 0;		
				break;
			}
			else if( c == 13 || c == 9){ //Neu nhan Enter,Tab.
				if(flag==1){
					if(Ktra_Dodai_Ma(VatTu.Vattu[n].maVT) == FALSE){
						ChuThich_Loi_VT(1);
						ChonMau();
						gotoxy(cot1,y);
						cout << VatTu.Vattu[n].maVT;
						ChonMau4();
					}
					else if(Ktra_Trung_MaVT(n) == FALSE){
						ChuThich_Loi_VT(2);
						ChonMau();
						gotoxy(cot1,y);
						cout << VatTu.Vattu[n].maVT;
						ChonMau4();
					}
					else{
						ChuThich_Loi_VT(0);
						gotoxy(cot1,y);
						cout << VatTu.Vattu[n].maVT;
						flag++;
						gotoxy(cot2,y);}
				}
				else if(flag == 2 ){
					if(Ktra_Chuoi(VatTu.Vattu[n].tenVT) == FALSE ){ //Kiem tra do dai ten VT.
						ChuThich_Loi_VT(3);
						ChonMau();
						gotoxy(cot2,y);
						cout << VatTu.Vattu[n].tenVT;
						ChonMau4();
					}
					else{
						ChuThich_Loi_VT(0);
						gotoxy(cot2,y);
						cout <<"                         ";
						VatTu.Vattu[n].tenVT = rutstring(VatTu.Vattu[n].tenVT);
						gotoxy(cot2,y);
						cout << VatTu.Vattu[n].tenVT;
						flag++;
						gotoxy(cot3,y);
					}
				}
				else if( flag == 3 ){
					if(Ktra_Chuoi(VatTu.Vattu[n].dVT) == FALSE){
						ChuThich_Loi_VT(4);
						ChonMau();
						VatTu.Vattu[n].dVT = rutstring(VatTu.Vattu[n].dVT);
						gotoxy(cot3,y);
						cout << "                ";
						gotoxy(cot3,y);
						cout << VatTu.Vattu[n].dVT;
						ChonMau4();
					}
					else{
						ChuThich_Loi_VT(0);
						gotoxy(cot3,y);
						cout << VatTu.Vattu[n].dVT;
						flag++;
						gotoxy(cot4,y);}
				}
				else if( flag==4 ){
					if(Ktra_Chuoi(SLT) == FALSE){
						ChuThich_Loi_VT(5);
						ChonMau();
						gotoxy(cot4,y);
						cout << SLT;
						ChonMau4();
					}
					if(Ktra_soLuongTon(SLT)== FALSE){
						ChuThich_Loi_VT(6);
						ChonMau();
						gotoxy(cot4,y);
						cout << SLT;
						ChonMau4();
					}
					else{
						ChuThich_Loi_VT(0);
						gotoxy(cot4,y);
						VatTu.Vattu[n].soLuongTon = StringToInt(SLT);
						cout << VatTu.Vattu[n].soLuongTon;
						y++; // Tang so cot.
						n++; // Chuyen sang vat tu tiep theo.
						VatTu.soVatTu++;
						SLT = "";
						flag = 1;
						gotoxy(cot1,y);
					}
				}
			}
			else if( ( c>=48 && c<=57 ) || ( c>=97 && c<=122 ) || ( c>=65 && c<=90 ) || (c==32)){// Nhan phim so,ki tu.
				if(flag == 1 && c != 32 && Ktra_Dodai_Ma(VatTu.Vattu[n].maVT)==FALSE ){
					gotoxy(vitri,y);
					if ( c >= 97 && c <= 122) c = c-32;
					cout << c;
					VatTu.Vattu[n].maVT.insert(VatTu.Vattu[n].maVT.end(),1,c);
					vitri++;
				}
				else if (flag == 2 && vitri<45){
                    gotoxy(vitri,y);
                    cout<<c;
                    VatTu.Vattu[n].tenVT.insert(VatTu.Vattu[n].tenVT.end(),1,c);
                    vitri++;
                }
                else if (flag == 3 && vitri<65){
                    gotoxy(vitri,y);
                    cout<<c;
                    VatTu.Vattu[n].dVT.insert(VatTu.Vattu[n].dVT.end(),1,c);
                    vitri++;
                }
                else if (flag == 4 && vitri<78 && c!=32){	
                    gotoxy(vitri,y);
                    cout<<c;
					SLT.insert(SLT.end(),1,c);
                    vitri++;
                }
			}
			else if( c == 8){ //Phim Backspace.
				if( flag == 1 && VatTu.Vattu[n].maVT.size() !=0 ){
                    vitri--;
                    gotoxy(vitri,y);
                    cout << " ";
                    gotoxy(vitri,y);
                    VatTu.Vattu[n].maVT.erase(VatTu.Vattu[n].maVT.end()-1);
                }
            	else if(flag==2 && VatTu.Vattu[n].tenVT.size()!=0){
                    vitri--;
                    gotoxy(vitri,y);
                    cout << " ";
                    gotoxy(vitri,y);
                    VatTu.Vattu[n].tenVT.erase(VatTu.Vattu[n].tenVT.end()-1);
                }

            	else if( flag==3 && VatTu.Vattu[n].dVT.size() !=0 ){
                    vitri--;
                    gotoxy(vitri,y);
                    cout << " ";
                    gotoxy(vitri,y);
                    VatTu.Vattu[n].dVT.erase(VatTu.Vattu[n].dVT.end()-1);
                }
                else if( flag==4 && SLT.size() !=0 ){
                    vitri--;
                    gotoxy(vitri,y);
                    cout << " ";
                    gotoxy(vitri,y);
                    SLT.erase(SLT.end()-1);
                }
			}
			else if (c==-32) // Phim dac biet
            {
                c = getch();
                if (c==72){ //Mui ten di len
                    if ( y > 8 ){
                        n = n - 1 ; y = y - 1;
                        if (flag == 1)
                            gotoxy(cot1+VatTu.Vattu[n].maVT.size(),y);
                        else if (flag == 2)
                            gotoxy(cot2+VatTu.Vattu[n].tenVT.size(),y);
                        else if (flag == 3)
                            gotoxy(cot3+VatTu.Vattu[n].dVT.size(),y);
                        else if (flag ==4){
                        	SLT = IntToString(VatTu.Vattu[n].soLuongTon);
                        	gotoxy(cot4+SLT.size(),y);
                        }
                    }
                }
                if (c==80){ //Mui ten di xuong
                    if(n<VatTu.soVatTu){
                    	n++; y++;
                    }
                    if (flag == 1 && n >= VatTu.soVatTu)
                           gotoxy(cot1+VatTu.Vattu[n].maVT.size(),y);
                    else if (flag == 2 && n >= VatTu.soVatTu )
                        gotoxy(cot2+VatTu.Vattu[n].tenVT.size(),y);
                    else if (flag == 3 && n>= VatTu.soVatTu)
                            gotoxy(cot3+VatTu.Vattu[n].dVT.size(),y);
                    else if (flag ==4){
                        	SLT = IntToString(VatTu.Vattu[n].soLuongTon);
                        	gotoxy(cot4+SLT.size(),y);
                        }        
                    else
                    {
                    	n--;y--;
                    }
                }
                if (c==75){ //Mui ten qua trai
                    if (flag == 2){
                        flag=1;
                        gotoxy(cot1+VatTu.Vattu[n].maVT.size(),y);
                    }
                    else if (flag == 3){
                        flag = 2;
                        gotoxy(cot2+VatTu.Vattu[n].tenVT.size(),y);
                    }
                    else if(flag==4){
                    	flag = 3;
                    	gotoxy(cot3+VatTu.Vattu[n].dVT.size(),y);
                    }
                }
                if (c==77){ //Mui ten qua phai
                    if (flag == 1 && VatTu.Vattu[n].maVT != ""){
                        flag = 2;
                        gotoxy(cot2+VatTu.Vattu[n].tenVT.size(),y);
                    }
                    else if(flag == 1 && VatTu.Vattu[n].maVT == "")
                    	gotoxy(cot1,y);
                    else if ( flag ==2 && VatTu.Vattu[n].tenVT !=""){
                        flag = 3;
                        gotoxy(cot3+VatTu.Vattu[n].dVT.size(),y);
                    }
                    else if (flag ==2 && VatTu.Vattu[n].tenVT =="")
                    	gotoxy(cot2,y);
                    else if( flag == 3 && VatTu.Vattu[n].dVT != "" ){
                    	flag = 4;
                    	gotoxy(cot4 + SLT.size(),y);
                    }
                    else if(flag == 3 && VatTu.Vattu[n].dVT == "")
                    	gotoxy(cot3,y);
                }
            }
		}
	}
	system("cls");
	MauNen1();
}
void LoadVatTu(int vtht){
	ChonMau4();
	int dongbd = 8;
	int trang = vtht / 12 + 1;
	int sotrang = VatTu.soVatTu/12 + 1;
	int cot1 = 4, cot2 = 18 , cot3 = 47, cot4 =66;
	gotoxy(cot1,6); cout << "Ma Vat Tu";
	gotoxy(cot2+7,6); cout <<"Ten Vat Tu";
	gotoxy(cot3+3,6); cout <<"Don Vi Tinh";
	gotoxy(cot4,6); cout <<"So Luong Ton";
	int dem = 0;
	for(int i = 0; i < VatTu.soVatTu; i++){
		if(trang == sotrang){ // Neu la trang cuoi.
			if(vtht == i){
					ChonMau();
					gotoxy(cot1,dongbd+dem); cout <<setw(11)<< VatTu.Vattu[i].maVT;
					gotoxy(cot2,dongbd+dem); cout <<setw(27) << VatTu.Vattu[i].tenVT;
					gotoxy(cot3,dongbd+dem); cout <<setw(18)<< VatTu.Vattu[i].dVT;
					gotoxy(cot4,dongbd+dem); cout <<setw(12)<< VatTu.Vattu[i].soLuongTon;
					dem++;
					ChonMau4();
			}
			else if( i/12+1 == sotrang){
					ChonMau4();
					gotoxy(cot1,dongbd+dem); cout <<setw(11)<< VatTu.Vattu[i].maVT;
					gotoxy(cot2,dongbd+dem); cout <<setw(27) << VatTu.Vattu[i].tenVT;
					gotoxy(cot3,dongbd+dem); cout <<setw(18)<< VatTu.Vattu[i].dVT;
					gotoxy(cot4,dongbd+dem); cout <<setw(12)<< VatTu.Vattu[i].soLuongTon;
					dem++;
			}
			if( i == VatTu.soVatTu-1 ){
				while(dem < 12){
					ChonMau4();
					gotoxy(cot1,dongbd+dem); cout <<setw(11)<< "";
					gotoxy(cot2,dongbd+dem); cout <<setw(27) << "";
					gotoxy(cot3,dongbd+dem); cout <<setw(18)<< "";
					gotoxy(cot4,dongbd+dem); cout <<setw(12)<< "";
					dem++;
				}
			}
	}
	else{
		if(vtht == i){
				ChonMau();
				gotoxy(cot1,dongbd+dem); cout <<setw(11)<< VatTu.Vattu[i].maVT;
				gotoxy(cot2,dongbd+dem); cout <<setw(27) << VatTu.Vattu[i].tenVT;
				gotoxy(cot3,dongbd+dem); cout <<setw(18)<< VatTu.Vattu[i].dVT;
				gotoxy(cot4,dongbd+dem); cout <<setw(12)<< VatTu.Vattu[i].soLuongTon;
				dem++;
				ChonMau4();
		}
		else if( i/12+1 == trang){
				ChonMau4();
				gotoxy(cot1,dongbd+dem); cout <<setw(11)<<VatTu.Vattu[i].maVT ;
				gotoxy(cot2,dongbd+dem); cout <<setw(27) << VatTu.Vattu[i].tenVT;
				gotoxy(cot3,dongbd+dem); cout <<setw(18)<< VatTu.Vattu[i].dVT;
				gotoxy(cot4,dongbd+dem); cout <<setw(12)<< VatTu.Vattu[i].soLuongTon;
				dem++;
				ChonMau4();
		}
		}
	}
	gotoxy(40,21);
}
void ChucNang_DSVT(int f){
		if(f == 0){
			ChonMau2();
			gotoxy(3,23); cout <<"            ";
			gotoxy(3,24); cout <<" Tim vat tu ";
			gotoxy(3,25); cout <<"     F1     ";
			
			gotoxy(20,23);cout <<"             ";
			gotoxy(20,24);cout <<" Them vat tu ";	
			gotoxy(20,25);cout <<"     F2      ";
			
			gotoxy(38,23);cout <<"            ";
			gotoxy(38,24);cout <<" Xoa vat tu ";
			gotoxy(38,25);cout <<"     F3     ";
			
			gotoxy(55,23);cout <<"           ";
			gotoxy(55,24);cout <<"   Thoat   ";
			gotoxy(55,25);cout <<"    Ecs    ";
			ChonMau4();
		}
}
void XemVatTu(){
	MauNen1();
	KhungTieuDe("   DANH SACH VAT TU   ");
	KhungNhap();
	int cot1 = 4, cot2 = 18 , cot3 = 47, cot4 =66;
	char c;
	int vtht = 0;
	int PASS = 1, y;
	int flag =1; //Dang Nhap: 1: Ma VT, 2:Ten VT, 3:DVT , 4: SLT.
	int vitri, hangtb= 21;
	LoadVatTu(vtht);
	SetColor(14);
	gotoxy(39,21); cout <<"HDSD: Su dung phim mui ten de di chuyen.";
	gotoxy(3,22); cout << " Cac phim chuc nang:";
	ChucNang_DSVT(0);
	while(PASS){
		int sotrang = VatTu.soVatTu/12 +1 ;
		SetColor(14);
		gotoxy(3,21); cout << "[Trang:"<<(vtht/12)+1 <<"/"<< sotrang <<"]";
		gotoxy(15,21); cout <<"--- [ " << vtht+1 << "/" << VatTu.soVatTu <<" ]";
		gotoxy(3,3); cout << "Enter : Sua ";
		gotoxy(3,4); cout << "Delete: Xoa ";
		c = getch();
		if(c == 0) c= getch();
		if( c== 59){ //Neu nhan F1.
				string maVT="";
				KhungTim("Nhap ma vat tu",1);
				int vitri =6;
				gotoxy(vitri,3);
				while( 1 ){
					c = getch(); if(c == 0) c= getch();
					if(( c>=48 && c<=57 ) || ( c>=97 && c<=122 ) || ( c>=65 && c<=90 ) || (c==32)){
						if ( c >= 97 && c <= 122) c = c-32;
						gotoxy(vitri,3);
						SetColor(0); SetBGColor(15);
						cout << c;
						vitri++;
						maVT.insert(maVT.end(),1,c);
					}
					else if(c == 8 && maVT.size()!= 0){
					vitri--;
					gotoxy(vitri,3);
                    cout << " ";
                    maVT.erase(maVT.end()-1);
                    }
                    else if(c==13){
                    	if(Ktra_Dodai_Ma(maVT)== 1)
                    		break;
                    	gotoxy(25,4);
                    	cout <<"Loi: Ma vat tu bao gom 6 ki tu!";
                    	Sleep(2000);
                    	gotoxy(25,4);
                    	ChonMau4();
                    	cout <<"                               ";
                    	gotoxy(vitri,3);
                    }
                    else if(c==27)
                     break;
				}
				KhungTim(" ",0);
				ChonMau4();
				if(Search_VT(maVT) != -1){
					vtht = Search_VT(maVT);
					LoadVatTu(vtht);
				}
				else{
					SetColor(14);
					gotoxy(3,4); cout << "Loi: Ma vat tu da nhap khong ton tai!";
					Sleep(2000);
					gotoxy(3,4); cout << "                                      ";
				}
		}
		else if(c == 60){ // Neu nhan F2.
			VatTu.soVatTu++;
			vtht = VatTu.soVatTu -1;
			y = vtht%12+8;
			VatTu.Vattu[vtht].maVT="";
			VatTu.Vattu[vtht].tenVT="";
			VatTu.Vattu[vtht].dVT="";
			string SLT="";
			LoadVatTu(vtht);
			int PASSE = 1;
			ChonMau();
			gotoxy(cot1 + VatTu.Vattu[vtht].maVT.size(),y);
			while(PASSE){
				while(kbhit()){
				ChuThich_Nhap_VT(flag);
				if (flag == 1)
					vitri = cot1 + VatTu.Vattu[vtht].maVT.size();
				if (flag == 2)
					vitri = cot2 + VatTu.Vattu[vtht].tenVT.size();
				if (flag == 3)
					vitri = cot3 + VatTu.Vattu[vtht].dVT.size();
				if (flag == 4)
					vitri = cot4 + SLT.size();
				char c = getch();
				if(c == 27){ // Neu nhan Ecs.
					VatTu.soVatTu--;
					PASS = 0;
					vtht = VatTu.soVatTu;
					LoadVatTu(vtht);}
				if( c == 13 || c == 9){ //Neu nhan Enter,Tab.
					if(flag==1){
						if(Ktra_Dodai_Ma(VatTu.Vattu[vtht].maVT) == FALSE){
							ChuThich_Loi_VT(1);
							ChonMau();
							gotoxy(cot1,y);
							cout << VatTu.Vattu[vtht].maVT;
						}
						else if(Ktra_Trung_MaVT(vtht) == FALSE){
							ChuThich_Loi_VT(2);
							gotoxy(cot1,y);
							ChonMau();
							cout << VatTu.Vattu[vtht].maVT;
						}
						else{
							ChuThich_Loi_VT(0);
							gotoxy(cot1,y);
							ChonMau();
							cout << VatTu.Vattu[vtht].maVT;
							flag++;
							gotoxy(cot2+VatTu.Vattu[vtht].tenVT.size(),y);}
					}
					else if(flag == 2 ){
						if(Ktra_Chuoi(VatTu.Vattu[vtht].tenVT) == FALSE){
							ChuThich_Loi_VT(3);
							ChonMau();
							gotoxy(cot2,y);
							cout << VatTu.Vattu[vtht].tenVT;
						}
						else{
							ChuThich_Loi_VT(0);
							gotoxy(cot2,y);
							ChonMau();
							cout << VatTu.Vattu[vtht].tenVT;
							flag++;
							gotoxy(cot3+VatTu.Vattu[vtht].dVT.size(),y);
						}
					}
					else if( flag == 3 ){
						if(Ktra_Chuoi(VatTu.Vattu[vtht].dVT) == FALSE){
							ChuThich_Loi_VT(4);
							ChonMau();
							gotoxy(cot3,y);
							cout << VatTu.Vattu[vtht].dVT;
						}
						else{
							ChuThich_Loi_VT(0);
							gotoxy(cot3,y);
							ChonMau();
							cout << VatTu.Vattu[vtht].dVT;
							flag++;
							gotoxy(cot4+SLT.size(),y);}
					}
					else if( flag==4 ){
						if(Ktra_Chuoi(SLT) == FALSE){
							ChuThich_Loi_VT(5);
							ChonMau();
							gotoxy(cot4,y);
							cout << SLT;
						}
						if(Ktra_soLuongTon(SLT)== FALSE){
							ChuThich_Loi_VT(6);
							gotoxy(cot4,y);
							ChonMau();
							cout << SLT;
						}
						else{
							VatTu.Vattu[vtht].soLuongTon = StringToInt(SLT);
							ChuThich_Loi_VT(0);
							Save_Vat_Tu();
							PASSE = 0;
							y++;
							LoadVatTu(vtht);		
							break;
						}
					}
				}
			else if( ( c>=48 && c<=57 ) || ( c>=97 && c<=122 ) || ( c>=65 && c<=90 ) || (c==32)){// Nhan phim so,ki tu.
				ChonMau();
				if(flag == 1 && vitri <15 && c != 32){
					gotoxy(vitri,y);
					if ( c >= 97 && c <= 122) c = c-32;
					cout << c;
					VatTu.Vattu[vtht].maVT.insert(VatTu.Vattu[vtht].maVT.end(),1,c);
					vitri++;
				}
				else if (flag == 2 && vitri<45){
                    gotoxy(vitri,y);
                    cout<<c;
                    VatTu.Vattu[vtht].tenVT.insert(VatTu.Vattu[vtht].tenVT.end(),1,c);
                    vitri++;
                }
                else if (flag == 3 && vitri<65){
                    gotoxy(vitri,y);
                    cout<<c;
                    VatTu.Vattu[vtht].dVT.insert(VatTu.Vattu[vtht].dVT.end(),1,c);
                    vitri++;
                }
                else if (flag == 4 && vitri<78 && c!=32){	
                    gotoxy(vitri,y);
                    cout<<c;
					SLT.insert(SLT.end(),1,c);
                    vitri++;
                }
			}
			else if( c == 8){ //Phim Backspace.
				ChonMau();
				if( flag == 1 && VatTu.Vattu[vtht].maVT.size() !=0 ){
                    vitri--;
                    gotoxy(vitri,y);
                    cout << " ";
                    gotoxy(vitri,y);
                    VatTu.Vattu[vtht].maVT.erase(VatTu.Vattu[vtht].maVT.end()-1);
                }
            	else if(flag==2 && VatTu.Vattu[vtht].tenVT.size()!=0){
                    vitri--;
                    gotoxy(vitri,y);
                    cout << " ";
                    gotoxy(vitri,y);
                    VatTu.Vattu[vtht].tenVT.erase(VatTu.Vattu[vtht].tenVT.end()-1);
                }

            	else if( flag==3 && VatTu.Vattu[vtht].dVT.size() !=0 ){
                    vitri--;
                    gotoxy(vitri,y);
                    cout << " ";
                    gotoxy(vitri,y);
                    VatTu.Vattu[vtht].dVT.erase(VatTu.Vattu[vtht].dVT.end()-1);
                }
                else if( flag==4 && SLT.size() !=0 ){
                    vitri--;
                    gotoxy(vitri,y);
                    cout << " ";
                    gotoxy(vitri,y);
                    SLT.erase(SLT.end()-1);
                		}
					}
			else if (c==-32) // Phim dac biet
            {
                c = getch();
				if (c==75){ //Mui ten qua trai
                    if (flag == 2){
                        flag=1;
                        gotoxy(cot1+VatTu.Vattu[vtht].maVT.size(),y);
                    }
                    else if (flag == 3){
                        flag = 2;
                        gotoxy(cot2+VatTu.Vattu[vtht].tenVT.size(),y);
                    }
                    else if(flag==4){
                    	flag = 3;
                    	gotoxy(cot3+VatTu.Vattu[vtht].dVT.size(),y);
                    }
                }
                if (c==77){ //Mui ten qua phai
                    if (flag == 1 && VatTu.Vattu[vtht].maVT != ""){
                        flag = 2;
                        gotoxy(cot2+VatTu.Vattu[vtht].tenVT.size(),y);
                    }
                    else if( flag == 1 && VatTu.Vattu[vtht].maVT == "" )
                    	gotoxy(cot1,y);
                    else if ( flag ==2 && VatTu.Vattu[vtht].tenVT !=""){
                        flag = 3;
                        gotoxy(cot3+VatTu.Vattu[vtht].dVT.size(),y);
                    }
                    else if (flag ==2 && VatTu.Vattu[vtht].tenVT =="")
                    	gotoxy(cot2,y);
                    else if( flag == 3 && VatTu.Vattu[vtht].dVT != "" ){
                    	flag = 4;
                    	gotoxy(cot4 + SLT.size(),y);
                    }
                    else if(flag == 3 && VatTu.Vattu[vtht].dVT == "")
                    	gotoxy(cot3,y);
                }
				}
				}
			}
		}
		else if(c == 61){ //Nhan F3.
			string maVT="";
				KhungTim("Nhap ma vat tu",1);
				int vitri =6;
				gotoxy(vitri,3);
				while( 1 ){
					c = getch(); if(c == 0) c= getch();
					if(( c>=48 && c<=57 ) || ( c>=97 && c<=122 ) || ( c>=65 && c<=90 ) || (c==32)){
						if ( c >= 97 && c <= 122) c = c-32;
						gotoxy(vitri,3);
						SetColor(0); SetBGColor(15);
						cout << c;
						vitri++;
						maVT.insert(maVT.end(),1,c);
					}
					else if(c == 8 && maVT.size()!= 0){
					vitri--;
					gotoxy(vitri,3);
                    cout << " ";
                    maVT.erase(maVT.end()-1);
                    }
                    else if(c==13){
                    	if(Ktra_Dodai_Ma(maVT)== 1)
                    		break;
                    	gotoxy(25,4);
                    	cout <<"Loi: Ma vat tu bao gom 6 ki tu!";
                    	Sleep(2000);
                    	gotoxy(25,4);
                    	ChonMau4();
                    	cout <<"                               ";
                    	gotoxy(vitri,3);
                    }
                    else if(c==27)
                     break;
				}
				KhungTim(" ",0);
				ChonMau4();
				if(Search_VT(maVT) != -1){
					if( YN("Xoa?") == 1){
					Xoa_VT_maVT(maVT);
					LoadVatTu(vtht);
					SetColor(14);
					gotoxy(3,4); cout <<"Da xoa thanh cong";
					Sleep(2000);
					gotoxy(3,4); cout <<"                 ";
					}
				}
				else{
					SetColor(14);
					gotoxy(3,4); cout << "Loi: Ma vat tu da nhap khong ton tai!";
					Sleep(2000);
					gotoxy(3,4); cout << "                                      ";
				}
		}
		else if(c == 27){
				if(YN("Ban co muon luu tat ca thay doi?")==1){
					Save_Vat_Tu();
				}
				PASS = 0;
		}
		else if(c == 13){ //Neu nhan phim Enter.
			int flag =1; //Dang Nhap: 1: Ma VT, 2:Ten VT, 3:DVT , 4: SLT.
			int y = vtht+8;
			int PASSE = 1;
			string SLT = IntToString(VatTu.Vattu[vtht].soLuongTon);
			ChonMau();
			gotoxy(vitri = cot1 + VatTu.Vattu[vtht].maVT.size(),y);
			while(PASSE){
				while(kbhit()){
				ChuThich_Nhap_VT(flag);
				if (flag == 1)
					vitri = cot1 + VatTu.Vattu[vtht].maVT.size();
				if (flag == 2)
					vitri = cot2 + VatTu.Vattu[vtht].tenVT.size();
				if (flag == 3)
					vitri = cot3 + VatTu.Vattu[vtht].dVT.size();
				if (flag == 4)
					vitri = cot4 + SLT.size();
				char c = getch();
				if(c == 27) PASSE=0; // Neu nhan Ecs.
				if( c == 13 || c == 9){ //Neu nhan Enter,Tab.
					if(flag==1){
						if(Ktra_Dodai_Ma(VatTu.Vattu[vtht].maVT) == FALSE){
							ChuThich_Loi_VT(1);
							ChonMau();
							gotoxy(cot1,y);
							cout << VatTu.Vattu[vtht].maVT;
						}
						else if(Ktra_Trung_MaVT(vtht) == FALSE){
							ChuThich_Loi_VT(2);
							gotoxy(cot1,y);
							ChonMau();
							cout << VatTu.Vattu[vtht].maVT;
						}
						else{
							ChuThich_Loi_VT(0);
							gotoxy(cot1,y);
							ChonMau();
							cout << VatTu.Vattu[vtht].maVT;
							flag++;
							gotoxy(cot2+VatTu.Vattu[vtht].tenVT.size(),y);}
					}
					else if(flag == 2 ){
						if(Ktra_Chuoi(VatTu.Vattu[vtht].tenVT) == FALSE){
							ChuThich_Loi_VT(3);
							ChonMau();
							gotoxy(cot2,y);
							cout << VatTu.Vattu[vtht].tenVT;
						}
						else{
							ChuThich_Loi_VT(0);
							gotoxy(cot2,y);
							ChonMau();
							cout << VatTu.Vattu[vtht].tenVT;
							flag++;
							gotoxy(cot3+VatTu.Vattu[vtht].dVT.size(),y);
						}
					}
					else if( flag == 3 ){
						if(Ktra_Chuoi(VatTu.Vattu[vtht].dVT) == FALSE){
							ChuThich_Loi_VT(4);
							ChonMau();
							gotoxy(cot3,y);
							cout << VatTu.Vattu[vtht].dVT;
						}
						else{
							ChuThich_Loi_VT(0);
							gotoxy(cot3,y);
							ChonMau();
							cout << VatTu.Vattu[vtht].dVT;
							flag++;
							gotoxy(cot4+SLT.size(),y);}
					}
					else if( flag==4 ){
						if(Ktra_Chuoi(SLT) == FALSE){
							ChuThich_Loi_VT(5);
							ChonMau();
							gotoxy(cot4,y);
							cout << SLT;
						}
						if(Ktra_soLuongTon(SLT)== FALSE){
							ChuThich_Loi_VT(6);
							gotoxy(cot4,y);
							ChonMau();
							cout << SLT;
						}
						else{
							VatTu.Vattu[vtht].soLuongTon = StringToInt(SLT);
							ChuThich_Loi_VT(0);
							Save_Vat_Tu();
							PASSE = 0;
							LoadVatTu(vtht);		
							break;
						}
					}
				}
			else if( ( c>=48 && c<=57 ) || ( c>=97 && c<=122 ) || ( c>=65 && c<=90 ) || (c==32)){// Nhan phim so,ki tu.
				ChonMau();
				if(flag == 1 && vitri <15 && c != 32){
					gotoxy(vitri,y);
					if ( c >= 97 && c <= 122) c = c-32;
					cout << c;
					VatTu.Vattu[vtht].maVT.insert(VatTu.Vattu[vtht].maVT.end(),1,c);
					vitri++;
				}
				else if (flag == 2 && vitri<45){
                    gotoxy(vitri,y);
                    cout<<c;
                    VatTu.Vattu[vtht].tenVT.insert(VatTu.Vattu[vtht].tenVT.end(),1,c);
                    vitri++;
                }
                else if (flag == 3 && vitri<65){
                    gotoxy(vitri,y);
                    cout<<c;
                    VatTu.Vattu[vtht].dVT.insert(VatTu.Vattu[vtht].dVT.end(),1,c);
                    vitri++;
                }
                else if (flag == 4 && vitri<78 && c!=32){	
                    gotoxy(vitri,y);
                    cout<<c;
					SLT.insert(SLT.end(),1,c);
                    vitri++;
                }
			}
			else if( c == 8){ //Phim Backspace.
				ChonMau();
				if( flag == 1 && VatTu.Vattu[vtht].maVT.size() !=0 ){
                    vitri--;
                    gotoxy(vitri,y);
                    cout << " ";
                    gotoxy(vitri,y);
                    VatTu.Vattu[vtht].maVT.erase(VatTu.Vattu[vtht].maVT.end()-1);
                }
            	else if(flag==2 && VatTu.Vattu[vtht].tenVT.size()!=0){
                    vitri--;
                    gotoxy(vitri,y);
                    cout << " ";
                    gotoxy(vitri,y);
                    VatTu.Vattu[vtht].tenVT.erase(VatTu.Vattu[vtht].tenVT.end()-1);
                }

            	else if( flag==3 && VatTu.Vattu[vtht].dVT.size() !=0 ){
                    vitri--;
                    gotoxy(vitri,y);
                    cout << " ";
                    gotoxy(vitri,y);
                    VatTu.Vattu[vtht].dVT.erase(VatTu.Vattu[vtht].dVT.end()-1);
                }
                else if( flag==4 && SLT.size() !=0 ){
                    vitri--;
                    gotoxy(vitri,y);
                    cout << " ";
                    gotoxy(vitri,y);
                    SLT.erase(SLT.end()-1);
                		}
					}
			else if (c==-32) // Phim dac biet
            {
                c = getch();
				if (c==75){ //Mui ten qua trai
                    if (flag == 2){
                        flag=1;
                        gotoxy(cot1+VatTu.Vattu[vtht].maVT.size(),y);
                    }
                    else if (flag == 3){
                        flag = 2;
                        gotoxy(cot2+VatTu.Vattu[vtht].tenVT.size(),y);
                    }
                    else if(flag==4){
                    	flag = 3;
                    	gotoxy(cot3+VatTu.Vattu[vtht].dVT.size(),y);
                    }
                }
                if (c==77){ //Mui ten qua phai
                    if (flag == 1 && VatTu.Vattu[vtht].maVT != ""){
                        flag = 2;
                        gotoxy(cot2+VatTu.Vattu[vtht].tenVT.size(),y);
                    }
                    else if( flag == 1 && VatTu.Vattu[vtht].maVT == "" )
                    	gotoxy(cot1,y);
                    else if ( flag ==2 && VatTu.Vattu[vtht].tenVT !=""){
                        flag = 3;
                        gotoxy(cot3+VatTu.Vattu[vtht].dVT.size(),y);
                    }
                    else if (flag ==2 && VatTu.Vattu[vtht].tenVT =="")
                    	gotoxy(cot2,y);
                    else if( flag == 3 && VatTu.Vattu[vtht].dVT != "" ){
                    	flag = 4;
                    	gotoxy(cot4 + SLT.size(),y);
                    }
                    else if(flag == 3 && VatTu.Vattu[vtht].dVT == "")
                    	gotoxy(cot3,y);
                }
				}
				}
			}
		}
		else if(c == 83){ //Neu nhan Delete.
			if(YN(" Xoa ?")==1){
			Xoa_VT(vtht);
			SetColor(14);
			gotoxy(3,4); cout <<"Da xoa thanh cong";
			Sleep(2000);
			gotoxy(3,4); cout <<"                 ";
			vtht--;
			LoadVatTu(vtht);
			}
		}
		else if(c == 72){  // Len.
				if(vtht > 0 )
					vtht--;
				LoadVatTu(vtht);
		}
		else if(c == 80){ //Xuong.
				if(vtht < VatTu.soVatTu -1)
					vtht++;
				LoadVatTu(vtht);
		}
		else if(c == 75){ // Ben Trai
				if(vtht<=12)
					vtht=0;
				else if(vtht >= 12 )
					vtht = vtht-12;
				LoadVatTu(vtht);
		}
		else if(c == 77){ // Ben Phai.
				if( vtht+12 < VatTu.soVatTu && vtht+12 != VatTu.soVatTu)
					vtht = vtht+12;
				LoadVatTu(vtht);
			}
	}
	MauNen1();
	system("cls");
}
//--------Quan li nhan vien-------//
int DSMS[MAX];
int SLNV = 0;
int SinhNgauNhien(){
	
	int a, dem;
	if(DSMS[0] == 0){
		srand(time(NULL));
		a = rand()%400 + 100;
		DSMS[0] = a;
		SLNV++;
		a = DSMS[0];
		return a;
	}
	else
	while(SLNV <400){
		srand(time(NULL));
		a = rand()%400 + 100;
		dem = 0;
	for(int  i = 0; DSMS[i]== 0; i++){
		if(a == DSMS[i]) dem++;
	}
	if(dem > 0){
		srand(time(NULL));
	 a = rand()%400 + 100;
	 }
	else{
		DSMS[SLNV] = a;
		SLNV++;
		return a;
	}
}
}
void insert_tree(PTRCay &p,nodeNhanVien a){
	if(p == NULL){
		p = new CayNhanVien;
		p->nhanVien = a;
		p->left = NULL;
		p->right = NULL;
	}
	else
		if(a.maNV<p->nhanVien.maNV)
		insert_tree(p->left,a);
		else if(a.maNV>p->nhanVien.maNV)
		insert_tree(p->right,a);
}
int Ktra_NV(string s){
	if(s.size() != 3) return false;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>=48&&s[i]<=57)
			return true;
	}
}
void ChuThich_Loi_NV(int x){
	ChonMau4();
	SetColor(14);
	gotoxy(3,4);
	cout << "                                            ";
	gotoxy(3,4);
	switch(x){
		case 0:
			cout << "                                            ";
			break;
		case 1:
			cout << "Loi: Ho nhan vien bi loi.";
			break;
		case 2:
			cout << "Loi: Ten nhan vien bi loi.";
			break;
		case 3:
			cout << "Loi: Phai chi co the la NAM/NU.";
			break;
	}
	ChonMau4();
}
PTRCay searchNV(PTRCay &p, int mstk){
   while(p!=NULL)
   {
      if(p->nhanVien.maNV == mstk)          return p;
      else if(mstk < p->nhanVien.maNV)           p = p->left;
        else p = p->right;
	}
    return NULL;
}
date Ngay1,Ngay2;
int iN, iX;
void SavePhu(){
	ofstream t("HoaDon.txt",ios::app|ios::out);
	t << "iN" <<" ";
	t << iN << " ";
	t << "iX" << " ";
	t << iX << endl;
	t << "Ngay" << endl;
	t << Ngay2.day <<endl;
	t << "Thang" << endl;
	t << Ngay2.month << endl;
	t << "Nam" << endl;
	t << Ngay2.year << endl;
	t.close();
}
void LoadPhu(){
	ifstream c("HoaDon.txt",ios::in);
	string f;
	while(c>>f !=NULL)
	{
			if(f == "Thang"){
			c >> Ngay2.month;	
			c.ignore();
		}
		if(f == "Nam"){
			c >> Ngay2.year;	
			c.ignore();
		}
		
		if(f == "iN"){
			c >> iN; 	
			c.ignore();
		}
		if(f == "iX"){
			c >> iX;	
			c.ignore();
		}
		if(f == "Ngay"){
			c >> Ngay2.day;	
			c.ignore();
		}
	
		
	}
	c.close();
}

void taofile(char* tenfile){
	ofstream t(tenfile,ios::out);
	t.close();
}
void LoadNV();
int NhapNV(){
	LoadNV();
	nodeNhanVien DSNV[400];
	MauNen1();
	
	int cot1 = 4, cot2 = 18 , cot3 = 47, cot4 =66;
	int flag =2 ; //Dang Nhap: 1: Ma VT, 2:Ten VT, 3:DVT , 4: SLT.
	int vitri, y = 8 , hangtb= 21;
	int PASS =1, i = 0;
	DSNV[i].maNV = SinhNgauNhien();
	DSNV[i].ho = "";
	DSNV[i].ten = "";
	DSNV[i].phai = "";
	KhungTieuDe("    NHAP NHAN VIEN     ");
	KhungNhap();
	gotoxy(cot1,6); cout << "Ma NV";
	gotoxy(cot2+7,6); cout <<"Ho Nhan Vien";
	gotoxy(cot3+3,6); cout <<"Ten Nhan Vien";
	gotoxy(cot4,6); cout <<"Phai";
	SetColor(14);
	gotoxy(3,21); cout <<"HDSD: Su dung phim mui ten de di chuyen.";
	gotoxy(3,22); cout << "Ecs de thoat.";
	ChonMau4();
	gotoxy(cot2,y);
	while(PASS){
		if( i == 13 ) KhungNhap();
		while(kbhit()){
			if (flag == 2)
				vitri = cot2 + DSNV[i].ho.size();
			if (flag == 3)
				vitri = cot3 + DSNV[i].ten.size();
			if (flag == 4)
				vitri = cot4 + DSNV[i].phai.size();
			char c = getch();
			if (c == 27){
				for(int j = 0; j < i; j++){
					insert_tree(cayNhanVien,DSNV[j]);
				}
				if( YN("BAN CO MUON LUU VAO FILE KHONG?") == 1){
					taofile("NhanVien.txt");
					SaveNV(cayNhanVien);
				}
				PASS = 0;		
				break;
			}
			else if( c == 13 || c == 9){ //Neu nhan Enter,Tab.
				if(flag == 2 ){
					if(Ktra_Chuoi(DSNV[i].ho) == FALSE){
						ChuThich_Loi_NV(1);
						ChonMau();
						gotoxy(cot2,y);
						cout << DSNV[i].ho;
						ChonMau4();
					}
					else{
						ChuThich_Loi_NV(0);
						gotoxy(cot2,y);
						DSNV[i].ho = rutstring(DSNV[i].ho);
						cout<< "                       ";
						gotoxy(cot2,y);
						cout << DSNV[i].ho;
						flag++;
						gotoxy(cot3,y);
					}
				}
				else if( flag == 3 ){
					if(Ktra_Chuoi(DSNV[i].ten) == FALSE){
						ChuThich_Loi_NV(2);
						ChonMau();
						gotoxy(cot3,y);
						cout << DSNV[i].ten;
						ChonMau4();
					}
					else{
						DSNV[i].maNV = SinhNgauNhien();
						ChuThich_Loi_NV(0);
						gotoxy(cot3,y);
						DSNV[i].ten = rutstring(DSNV[i].ten);
						cout<< "                 ";
						gotoxy(cot3,y);
						cout << DSNV[i].ten;
						flag++;
						gotoxy(cot4,y);
					}
				}
				else if( flag==4 ){
					
					if(DSNV[i].phai!= "NAM" && DSNV[i].phai!="NU")
            		{
            			ChuThich_Loi_NV(3);
            			gotoxy(cot4,y);
            			cout<<DSNV[i].phai;
            			ChonMau4();
            		}
					else{
						ChuThich_Loi_NV(0);
						gotoxy(cot4,y);
						cout<<DSNV[i].phai;
            			flag=2;
            			gotoxy(cot1,y);
            			cout << DSNV[i].maNV;
            			i++; // Chuyen sang nhan vien tiep theo.
						y++; // Tang so cot.
						flag=2;
						gotoxy(cot2,y);
					}
				}
			}
			if( ( c >=48 && c<=57 ) || ( c>=97 && c<=122 ) || ( c>=65 && c<=90 ) || (c==32)){// Nhan phim so,ki tu.
				if (flag == 2 && vitri<45){
                    gotoxy(vitri,y);
                    if (c>=97 && c<=122 && (DSNV[i].ho.size() == 0||DSNV[i].ho[DSNV[i].ho.size()-1]==' '))  c=c-32;
                    cout<<c;
                    DSNV[i].ho.insert(DSNV[i].ho.end(),1,c);
                    vitri++;
                }
                else if (flag == 3 && vitri<65){
                    gotoxy(vitri,y);
                    if (c>=97 && c<=122 && (DSNV[i].ten.size() == 0||DSNV[i].ten[DSNV[i].ten.size()-1]==' ')) c=c-32;
                    cout<<c;
                    DSNV[i].ten.insert(DSNV[i].ten.end(),1,c);
                    vitri++;
                }
                else if (flag == 4 && vitri<78 && c!=32){
				if (c>=97 && c<=122) c=c-32;	
                    gotoxy(vitri,y);
                    cout<<c;
					DSNV[i].phai.insert(DSNV[i].phai.end(),1,c);
                    vitri++;
                }
			}
			else if( c == 8){ //Phim Backspace.
				if(flag==2 && DSNV[i].ho.size()!=0){
                    vitri--;
                    gotoxy(vitri,y);
                    cout << " ";
                    gotoxy(vitri,y);
                    DSNV[i].ho.erase(DSNV[i].ho.end()-1);
                }
				else if( flag==3 && DSNV[i].ten.size() !=0 ){
                    vitri--;
                    gotoxy(vitri,y);
                    cout << " ";
                    gotoxy(vitri,y);
                    DSNV[i].ten.erase(DSNV[i].ten.end()-1);
                }
                else if( flag==4 && DSNV[i].phai!= "" ){
                    vitri--;
                    gotoxy(vitri,y);
                    cout << " ";
                    gotoxy(vitri,y);
                    DSNV[i].phai.erase(DSNV[i].phai.end()-1);
                }
			}
			else if (c==-32) // Phim dac biet
            {
                c = getch();
                if (c==72){ //Mui ten di len
                    if ( y > 8 ){
                        i = i - 1 ; y = y - 1;
                        if (flag == 2)
                            gotoxy(cot2+DSNV[i].ho.size(),y);
                        else if (flag == 3)
                            gotoxy(cot3+DSNV[i].ten.size(),y);
                        else if (flag ==4){
                        	gotoxy(cot4+DSNV[i].phai.size(),y);
                        }
                    }
                }
                if (c==80){ //Mui ten di xuong
                    if(i<SLNV-1){
                    	i++; y++;
                    }
                    if (flag == 2 && i >= SLNV )
                        gotoxy(cot2+DSNV[i].ho.size(),y);
                    else if (flag == 3 && i>= SLNV)
                             gotoxy(cot3+DSNV[i].ten.size(),y);
                    else if (flag ==4){
                        	gotoxy(cot4+DSNV[i].phai.size(),y);
                        }        
                    else
                    {
                    	i--;y--;
                    }
                }
                if (c==75){ //Mui ten qua trai
                    if (flag == 3){
                        flag = 2;
                        gotoxy(cot2+DSNV[i].ho.size(),y);
                    }
                    else if(flag==4){
                    	flag = 3;
                    	gotoxy(cot3+DSNV[i].ten.size(),y);
                    }
                }
                if (c==77){ //Mui ten qua phai
                    if ( flag ==2 && DSNV[i].ho !=""){
                        flag = 3;
                        gotoxy(cot3+DSNV[i].ten.size(),y);
                    }
                    else if (flag ==2 && DSNV[i].ho =="")
                    	gotoxy(cot2,y);
                    else if( flag == 3 && DSNV[i].ten != "" ){
                    	flag = 4;
	                    gotoxy(cot4+DSNV[i].phai.size(),y);
					}
                    else if(flag == 3 && DSNV[i].phai == ""){
                    	gotoxy(cot3,y);
                	}
            	}
			}
		}
	}
	MauNen1();
}
PTRCay rp;
void remove_case3(PTRCay &r){
	if(r->left != NULL)
	remove_case3(r->left);
	else{
		rp->nhanVien.maNV = r->nhanVien.maNV;
		rp->nhanVien = r->nhanVien;
		rp = r;
		r = rp->right;	
	}
}
int remove_tree(PTRCay &p, int x){
	if(p == NULL){
		cout <<"Hien chua co nhan vien nao"; return 0;
	} 
	else if(x < p->nhanVien.maNV) remove_tree(p->left, x);
	else if(x > p->nhanVien.maNV) remove_tree(p->right, x);
	else {
		rp = p;
		if(rp->right == NULL) p = p->left;
		else if(rp->left == NULL) p = p->right;
		else remove_case3(rp->right);
		delete rp;
		return 1;
	}
	return 0;
}
void SaveNV(PTRCay p){
	ofstream t("NhanVien.txt",ios::app|ios::out);
	if(p != NULL){
		t<<"NhanVien" << endl;
    	t<<p->nhanVien.ho<<endl<<p->nhanVien.ten<<endl;
		t<<p->nhanVien.phai<<endl<<p->nhanVien.maNV<<endl;
		SaveNV(p->left);
		SaveNV(p->right);
	}
	t.close();
	
}
void LoadNV(){
	SLNV = 0;
	ifstream c("NhanVien.txt",ios::in);
	string f;
	while(getline(c,f) !=NULL)
	{
		nodeNhanVien b;
		if(f == "NhanVien"){
			getline(c,b.ho);
			getline(c,b.ten);
			getline(c,b.phai);
			c>>b.maNV;
			DSMS[SLNV] = b.maNV;
			c.ignore();
		}
		if(b.maNV != 0 && b.phai != ""&&b.ho != "" && b.ten != ""){
			insert_tree(cayNhanVien,b);
			SLNV++;
		}
		
	}
	
	c.close();
}
int TimViTriNV(nodeNhanVien a[],int maNV){
	for(int i = 0; i < SLNV; i++){
		if(a[i].maNV == maNV) return i;
	}
	return -1;
}
void Xoa_NV_maNV(int maNV, nodeNhanVien a[]){
	int i = TimViTriNV(a,maNV);
	for(int j= i; j < SLNV-1 ; j++){
		a[j] = a[j+1];
	}
	SLNV--;
}
void Xoa_NV(int i,nodeNhanVien a[]){
	for(int j = i; j < SLNV -1 ; j++){
		a[j] = a[j+1];
	}
	SLNV--;
}
void SapXepNV(nodeNhanVien a[]){
	for(int i = 0;i < SLNV-1; i++){
		for(int j = i+1;j < SLNV; j++ ){
			if(a[i].ten > a[j].ten)
			swap(a[i],a[j]);
			else if(a[i].ten == a[j].ten){
				if(a[i].ho > a[j].ho)
				swap(a[i],a[j]);
			}
		}
	}
}
void LoadDSNV(int vtht, nodeNhanVien a[]){
	ChonMau4();
	int dongbd = 8;
	int trang = vtht/12 +1;
	int sotrang = SLNV/12 + 1;
	int cot1 = 4, cot2 = 18 , cot3 = 47, cot4 =66;
	int dem = 0;
	for(int i = 0; i < SLNV; i++){
		if(trang == sotrang){ // Neu la trang cuoi.
			if(vtht == i){
					ChonMau();
					gotoxy(cot1,dongbd+dem); cout <<setw(11)<< a[i].maNV;
					gotoxy(cot2,dongbd+dem); cout <<setw(27) << a[i].ho;
					gotoxy(cot3,dongbd+dem); cout <<setw(18)<< a[i].ten;
					gotoxy(cot4,dongbd+dem); cout <<setw(12)<< a[i].phai;
					dem++;
					ChonMau4();
			}
			else if( i/12+1 == sotrang){
					ChonMau4();
					gotoxy(cot1,dongbd+dem); cout <<setw(11)<< a[i].maNV;
					gotoxy(cot2,dongbd+dem); cout <<setw(27) << a[i].ho;
					gotoxy(cot3,dongbd+dem); cout <<setw(18)<< a[i].ten;
					gotoxy(cot4,dongbd+dem); cout <<setw(12)<< a[i].phai;
					dem++;
			}
			if( i == SLNV-1 ){
				while(dem < 12){
					ChonMau4();
					gotoxy(cot1,dongbd+dem); cout <<setw(11)<< "";
					gotoxy(cot2,dongbd+dem); cout <<setw(27) << "";
					gotoxy(cot3,dongbd+dem); cout <<setw(18)<< "";
					gotoxy(cot4,dongbd+dem); cout <<setw(12)<< "";
					dem++;
				}
			}
	}
	else{
		if(vtht == i){
				ChonMau();
				gotoxy(cot1,dongbd+dem); cout <<setw(11)<< a[i].maNV;
				gotoxy(cot2,dongbd+dem); cout <<setw(27) << a[i].ho;
				gotoxy(cot3,dongbd+dem); cout <<setw(18)<< a[i].ten;
				gotoxy(cot4,dongbd+dem); cout <<setw(12)<< a[i].phai;
				dem++;
				ChonMau4();
		}
		else if( i/12+1 == trang){
				ChonMau4();
				gotoxy(cot1,dongbd+dem); cout <<setw(11)<<a[i].maNV ;
				gotoxy(cot2,dongbd+dem); cout <<setw(27)<< a[i].ho;
				gotoxy(cot3,dongbd+dem); cout <<setw(18)<< a[i].ten;
				gotoxy(cot4,dongbd+dem); cout <<setw(12)<< a[i].phai;
				dem++;
				ChonMau4();
		}
		}
	}
	gotoxy(40,21);
}
void ChucNang_DSNV(int f){
		if(f == 0){
			ChonMau2();
			gotoxy(3,23); cout <<"               ";
			gotoxy(3,24); cout <<" Tim nhan vien ";
			gotoxy(3,25); cout <<"     F1        ";
			
			
			gotoxy(20,23);cout <<"               ";
			gotoxy(20,24);cout <<" Xoa nhan vien ";
			gotoxy(20,25);cout <<"     F3        ";
			
			gotoxy(38,23);cout <<"               ";
			gotoxy(38,24);cout <<"   Thoat       ";
			gotoxy(38,25);cout <<"    Ecs        ";
			ChonMau4();
		}
}

int ichepmang = 0;
void ChepMangNV(PTRCay p, nodeNhanVien a[]){
	if(p != NULL){
		a[ichepmang].maNV=0;
		a[ichepmang].ho = "";
		a[ichepmang].ten = "";
		a[ichepmang].phai ="";
		a[ichepmang]= p->nhanVien;
		ichepmang++;
		ChepMangNV(p->left,a);
		ChepMangNV(p->right,a);
		
	}
}
void inDSNV(){
	LoadNV();
	nodeNhanVien a[MAX];
	ichepmang = 0;
	ChepMangNV(cayNhanVien,a);
	SapXepNV(a);
	MauNen1();
	KhungTieuDe("   DANH SACH NHAN VIEN   ");
	KhungNhap();
	int cot1 = 4, cot2 = 18 , cot3 = 47, cot4 =66;
	char c;
	int dongbd= 8;
	int vtht = 0;
	int PASS = 1, y;
	int flag = 2; //Dang Nhap: 1: Ma VT, 2:Ten VT, 3:DVT , 4: SLT.
	int vitri, hangtb= 21;
	LoadDSNV(vtht,a);
	gotoxy(cot1,6); cout << "Ma NV";
	gotoxy(cot2+7,6); cout <<"Ho Nhan Vien";
	gotoxy(cot3+3,6); cout <<"Ten Nhan Vien";
	gotoxy(cot4,6); cout <<"Phai";
	SetColor(14);
	gotoxy(39,21); cout <<"HDSD: Su dung phim mui ten de di chuyen.";
	gotoxy(3,22); cout << " Cac phim chuc nang:";
	ChucNang_DSNV(0);
	while(PASS){
		int sotrang = SLNV/12 +1 ;
		SetColor(14);
		gotoxy(3,21); cout << "[Trang:"<<(vtht/12)+1 <<"/"<< sotrang <<"]";
		gotoxy(15,21); cout <<"--- [ " << vtht+1 << "/" << SLNV<< " ]";
		gotoxy(3,3); cout << "Enter : Sua ";
		gotoxy(3,4); cout << "Delete: Xoa ";
		c = getch();
		if(c == 0) c= getch();
		if( c== 59){ //Neu nhan F1.
				string maNV="";
				KhungTim("Nhap ma NV",1);
				int vitri = 6;
				gotoxy(vitri,3);
				while( 1 ){
					c = getch(); if(c == 0) c = getch();
					if(( c>=48 && c<=57 ) || ( c>=97 && c<=122 ) || ( c>=65 && c<=90 ) || (c==32)){
						if ( c >= 97 && c <= 122) c = c-32;
						gotoxy(vitri,3);
						SetColor(0); SetBGColor(15);
						if(Ktra_NV(maNV) != 1){
							cout << c;
							vitri++;
							maNV.insert(maNV.end(),1,c);
						}
					}
					else if(c == 8 && maNV.size()!= 0){
					vitri--;
					gotoxy(vitri,3);
                    cout << " ";
                    maNV.erase(maNV.end()-1);
                    }
                    else if(c==13){
                    	if(StringToInt(maNV) > 100 && StringToInt(maNV) < 1000)
                    		break;
                    	gotoxy(25,4);
                    	cout <<"Loi: Ma vat tu bao gom 3 chu so!";
                    	Sleep(2000);
                    	gotoxy(25,4);
                    	ChonMau4();
                    	cout <<"                               ";
                    	gotoxy(vitri,3);
                    }
                    else if(c==27)
                     break;
				}
				KhungTim("",0);
				ChonMau4();
				if(TimViTriNV(a,StringToInt(maNV)) != -1){
					vtht = TimViTriNV(a,StringToInt(maNV));
					LoadDSNV(vtht,a);
				}
				else{
					SetColor(14);
					gotoxy(3,4); cout << "Loi: Ma nhan vien da nhap khong ton tai!";
					Sleep(2000);
					gotoxy(3,4); cout << "                                      ";
				}
		}
		else if(c == 61){ //Nhan F3.
				string maNV="";
				KhungTim("Nhap ma NV",1);
				int vitri =6;
				gotoxy(vitri,3);
				while( 1 ){
					c = getch(); if(c == 0) c= getch();
					if(( c>=48 && c<=57 ) || ( c>=97 && c<=122 ) || ( c>=65 && c<=90 ) || (c==32)){
						if ( c >= 97 && c <= 122) c = c-32;
						gotoxy(vitri,3);
						SetColor(0); SetBGColor(15);
						if(Ktra_NV(maNV) != 1){
						cout << c;
						vitri++;
						maNV.insert(maNV.end(),1,c);}
					}
					else if(c == 8 && maNV.size()!= 0){
					vitri--;
					gotoxy(vitri,3);
                    cout << " ";
                    maNV.erase(maNV.end()-1);
                    }
                    else if(c==13){
                    	if(Ktra_NV(maNV)== 1)
                    		break;
                    	gotoxy(25,4);
                    	cout <<"Loi: Ma nhan vien bao gom 3 chu so!";
                    	Sleep(2000);
                    	gotoxy(25,4);
                    	ChonMau4();
                    	cout <<"                               ";
                    	gotoxy(vitri,3);
                    }
                    else if(c==27)
                     break;
				}
				KhungTim("",0);
				ChonMau4();
				if(searchNV(cayNhanVien,StringToInt(maNV)) != NULL){
					if( YN("Xoa?") == 1){
					remove_tree(cayNhanVien,StringToInt(maNV));
					Xoa_NV_maNV(StringToInt(maNV),a);
					LoadDSNV(vtht,a);
					SetColor(14);
					gotoxy(3,4); cout <<"Da xoa thanh cong";
					Sleep(2000);
					gotoxy(3,4); cout <<"                 ";
					}
				}
				else{
					SetColor(14);
					gotoxy(3,4); cout << "Loi: Ma nhan vien da nhap khong ton tai!";
					Sleep(2000);
					gotoxy(3,4); cout << "                                      ";
				}
		}
		else if(c == 27){
				PASS = 0;
		}
		if(c == 27){
			if(YN("Ban co muon luu thay doi?") == 1){
				taofile("NhanVien.txt");
				SaveNV(cayNhanVien);
			}
				PASS = 0;
		}
		else if(c == 13){ //Neu nhan phim Enter.
			int flag =2; //Dang Nhap: 1: Ma VT, 2:Ten VT, 3:DVT , 4: SLT.
			y = vtht%12+8;
			int PASSE = 1;
			ChonMau();
			gotoxy(cot1 + a[vtht].ho.size(),y);
			while(PASSE){
				while(kbhit()){
				if (flag == 2)
					vitri = cot2 + a[vtht].ho.size();
				if (flag == 3)
					vitri = cot3 + a[vtht].ten.size();
				if (flag == 4)
					vitri = cot4 + a[vtht].phai.size();
				char c = getch();
				if(c == 27) PASSE=0; // Neu nhan Ecs.
				if( c == 13 || c == 9){ //Neu nhan Enter,Tab.
					if(flag == 2 ){
						if(Ktra_Chuoi(a[vtht].ho) == FALSE){
							ChuThich_Loi_NV(1);
							ChonMau();
							gotoxy(cot2,y);
							cout << a[vtht].ho;
						}
						else{
							ChuThich_Loi_NV(0);
							gotoxy(cot2,y);
							ChonMau();
							a[vtht].ho = rutstring(a[vtht].ho);
							cout<< "                       ";
							gotoxy(cot2,y);
							cout << a[vtht].ho;
							flag++;
							gotoxy(cot3+a[vtht].ten.size(),y);
						}
					}
					else if( flag == 3 ){
						if(Ktra_Chuoi(a[vtht].ten) == FALSE){
							ChuThich_Loi_NV(2);
							ChonMau();
							gotoxy(cot3,y);
							cout << a[vtht].ten;
						}
						else{
							ChuThich_Loi_VT(0);
							gotoxy(cot3,y);
							ChonMau();
							a[vtht].ten = rutstring(a[vtht].ten);
							cout<< "                 ";
							gotoxy(cot3,y);
							cout << a[vtht].ten;
							flag++;
							gotoxy(cot4+a[vtht].phai.size(),y);}
					}
					else if( flag==4 ){
						if(Ktra_Chuoi(a[vtht].phai) == FALSE){
							ChuThich_Loi_NV(3);
							ChonMau();
							gotoxy(cot4,y);
							cout << a[vtht].phai;
						}
						
						else{
							ChuThich_Loi_NV(0);
							searchNV(cayNhanVien,a[vtht].maNV)->nhanVien = a[vtht];
							taofile("NhanVien.txt");
							SaveNV(cayNhanVien);
							PASSE = 0;
							LoadDSNV(vtht,a);		
							break;
						}
					}
				}
			else if( ( c>=48 && c<=57 ) || ( c>=97 && c<=122 ) || ( c>=65 && c<=90 ) || (c==32)){// Nhan phim so,ki tu.
				ChonMau();
				if (flag == 2 && vitri<45){
					if (c>=97 && c<=122 && (a[vtht].ho.size() == 0||a[vtht].ho[a[vtht].ho.size()-1]==' '))  c=c-32;
                    gotoxy(vitri,y);
                    cout<<c;
                    a[vtht].ho.insert(a[vtht].ho.end(),1,c);
                    vitri++;
                }
                else if (flag == 3 && vitri<65){
                	if (c>=97 && c<=122 && (a[vtht].ten.size() == 0||a[vtht].ten[a[vtht].ten.size()-1]==' '))  c=c-32;
                    gotoxy(vitri,y);
                    cout<<c;
                    a[vtht].ten.insert(a[vtht].ten.end(),1,c);
                    vitri++;
                }
                else if (flag == 4 && vitri<78 && c!=32){
				if (c>=97 && c<=122 )  c=c-32;	
                    gotoxy(vitri,y);
                    cout<<c;
					a[vtht].phai.insert(a[vtht].phai.end(),1,c);
                    vitri++;
                }
			}
			else if( c == 8){ //Phim Backspace.
				ChonMau();
				if(flag==2 && a[vtht].ho.size()!=0){
                    vitri--;
                    gotoxy(vitri,y);
                    cout << " ";
                    gotoxy(vitri,y);
                    a[vtht].ho.erase(a[vtht].ho.end()-1);
                }

            	else if( flag==3 && a[vtht].ten.size() !=0 ){
                    vitri--;
                    gotoxy(vitri,y);
                    cout << " ";
                    gotoxy(vitri,y);
                    a[vtht].ten.erase(a[vtht].ten.end()-1);
                }
                else if( flag==4 && a[vtht].phai.size() !=0 ){
                    vitri--;
                    gotoxy(vitri,y);
                    cout << " ";
                    gotoxy(vitri,y);
                    a[vtht].phai.erase(a[vtht].phai.end()-1);
                		}
					}
			else if (c==-32) // Phim dac biet
            {
                c = getch();
				if (c==75){ //Mui ten qua trai
                    if (flag == 3){
                        flag = 2;
                        gotoxy(cot2+a[vtht].ho.size(),y);
                    }
                    else if(flag==4){
                    	flag = 3;
                    	gotoxy(cot3+a[vtht].ten.size(),y);
                    }
                }
                if (c==77){ //Mui ten qua phai
                    if ( flag ==2 && a[vtht].ho !=""){
                        flag = 3;
                        gotoxy(cot3+a[vtht].ten.size(),y);
                    }
                    else if (flag ==2 && a[vtht].ho =="")
                    	gotoxy(cot2,y);
                    else if( flag == 3 && a[vtht].ten != "" ){
                    	flag = 4;
                    	gotoxy(cot4 + a[vtht].phai.size(),y);
                    }
                    else if(flag == 3 && a[vtht].ten == "")
                    	gotoxy(cot3,y);
                }
				}
				}
			}
		}
		else if(c == 83){ //Neu nhan Delete.
			if(YN(" Xoa ?")==1){
			remove_tree(cayNhanVien,a[vtht].maNV);
			Xoa_NV(vtht,a);
			LoadDSNV(vtht,a);
			SetColor(14);
			gotoxy(3,4); cout <<"Da xoa thanh cong";
			Sleep(2000);
			gotoxy(3,4); cout <<"                 ";
			}
		}
		else if(c == 72){  // Len.
				if(vtht > 0 )
					vtht--;
				LoadDSNV(vtht,a);
		}
		else if(c == 80){ //Xuong.
				if(vtht < SLNV -1)
					vtht++;
				LoadDSNV(vtht,a);
		}
		else if(c == 75){ // Ben Trai
				if(vtht<=12)
					vtht=0;
				else if(vtht >= 12 )
					vtht = vtht-12;
				LoadDSNV(vtht,a);
		}
		else if(c == 77){ // Ben Phai.
				if( vtht+12 < SLNV && vtht+12 != SLNV)
					vtht = vtht+12;
				LoadDSNV(vtht,a);
			}
	}
	MauNen1();
	system("cls");
}
void XoaNV(PTRCay &root){
	KhungTim("Nhap ma nhan vien can xoa",1);
	gotoxy(5,3);
	int mstk;
   	cin >> mstk;
   if(remove_tree(root,mstk) == 0){
   	gotoxy(8,8); cout << "Khong xoa duoc";
   } 
   else {
   	gotoxy(8,8); cout << "Da xoa thanh cong";
   }
   KhungTim(" ",0);
}
//------Quan li hoa don---------//
void ThoiGian(){
	int t;
    char time[128];
	_strtime(time);
    for (t=0;t<5;t++)
        cout<<time[t];
     cout.flush();
}
void In_huong_dan_Nhap_HD(){
    char k = 179;
    int y = wherey()+2;
    int cot1=0, cot2=4, cot3=15, cot4=36, cot5=47, cot6=58, cot7=68;
    gotoxy(cot1,y);
    cout<<"STT";
    gotoxy(cot2-1,y);
    cout<<k;
    gotoxy(cot2,y);
    cout<<"  MA VT";
    gotoxy(cot3-1,y);
    cout<<k;
    gotoxy(cot3,y);
    cout<<"      TEN VT";
    gotoxy(cot4-1,y);
    cout<<k;
    gotoxy(cot4,y);
    cout<<"\tSLT";
    gotoxy(cot5-1,y);
    cout<<k;
    gotoxy(cot5,y);
    cout<<" SO LUONG";
    gotoxy(cot6-1,y);
    cout<<k;
    gotoxy(cot6,y);
    cout<<" DON GIA";
    cout<<endl;
    for(int i=1;i<68;i++)
    {
    	if(i==4 || i==15 || i==36 || i==47 || i==58)
    		cout<<char(197);
    	else
    		cout<<char(196);
    }
    cout<<endl;
}    
void Insert_Vattu(CT_HOADON *&First, string MaVT, long dongia, int soluong){
    CT_HOADON *q = new CT_HOADON;
    q ->MAVT = MaVT;
    q->soluong = soluong;
    q->dongia=dongia;
    q->next = First;
    First = q;
}
int Ktra_trung_SHD(string s,PTRCay p){
	if(p!=NULL){
    for (HOADON *q = p->nhanVien.HoaDon; q != NULL; q = q->next){
        if (q->HoaDon.SoHD == s)
            return false;
    }
          Ktra_trung_SHD(s,p->left);
          Ktra_trung_SHD(s,p->right);
    }
    return true;
}
int ktra_Vtu(string s, int &i){
    for (int j=0; j<VatTu.soVatTu; j++)
        if (VatTu.Vattu[j].maVT == s)
        {
            i = j;
            return true;
        }
    return false;
}
int CHECK_NGAY(int ngay, int thang, int nam) //Ham kiem tra date
{
	if(thang<1 || thang>12)
		return false;
	if(nam<2000)
		return false;
    switch(thang)
	{
    	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
    		if(ngay>31 || ngay<1)
    			return false;
    		break;
    	case 4: case 6: case 9: case 11:
    		if(ngay>30 || ngay<1)
    			return false;
    		break;
    	case 2:
    		if(((ngay>28 || ngay<1) && (nam%4)!=0) || ((ngay>29 || ngay<1) && (nam%4)==0))
    			return false;
    		break;
    }
    return true;
}
void Nhap_DS_Vattu(CT_HOADON *&First, int tinhieu)
{
    //tinhieu = 1 la nhap, tinhieu=0 la xuat
    In_huong_dan_Nhap_HD();
    string MaVT, stdongia,stsoluong;
    int dongia;
    int soluong;
    char k = 179;
    int y = wherey();
    int cot1=0, cot2=4, cot3=15, cot4=36, cot5=47, cot6=58, cot7=68;
    int vitri;
    int plag = 1;
    int i=0;
    int j; //lay vi tri cua ma vat tu
    while (1)
    {
        if (plag==1) //so thu tu
        {
            i++;
            gotoxy(cot1,y);
            cout<<i;
            gotoxy(cot2-1,y);
            cout<<k;
            gotoxy(cot5-1,y);
            cout<<k;
            gotoxy(cot6-1,y);
            cout<<k;
            gotoxy(cot2,y);
            plag=2;
            
        }
		while (plag==5)
        {
            while (kbhit())
            {
            	char c = getch();
                vitri = cot5 + stsoluong.size();
                if (c==27)
                {
                    return;
                }
                else if (c==13 || c==27)
                {
		                	if (tinhieu == 1)
					{
						soluong = StringToInt(stsoluong);
						VatTu.Vattu[j].soLuongTon +=soluong;
						VatTu.Vattu[j].TansuatN++;
						plag = 6;
					}
		            else if(tinhieu == 0)
		            {
		                if (soluong <= VatTu.Vattu[j].soLuongTon)
		                {
		                	MauMacDinh();
		                	gotoxy(0,1);
		                	cout<<"                                                                                                                   ";
		                    VatTu.Vattu[j].soLuongTon -= soluong;
		                    VatTu.Vattu[j].TansuatX++;
		                    plag = 6;
		                }
		                else
		                {
		                    Highligh_Miss();
		                    gotoxy(0,1);
		                    cout<<"So luong ban xuat lon hon so luong vat tu ton kho. So luong vat tu ton kho la "<<VatTu.Vattu[j].soLuongTon<<". Xin moi nhap lai.";
		                    MauMacDinh();
		                    gotoxy(cot5,y);
		                    cout<<"                  ";
		                }
            		}
                        plag = 6;
                        gotoxy(cot6,y);
                }        
                else if(c>=48&&c<=57)
                {
                    gotoxy(vitri,y);
                    stsoluong.insert(stsoluong.end(),1,c);
 				cout << c;
				
                }
                else if (c==8)
                {
                    if (stsoluong.size()!=0)
                    {
                        vitri--;
                        gotoxy(vitri,y);
                        cout<<" ";
                        stsoluong.erase(stsoluong.end()-1);
                    }
                }
            }
        }
        while (plag==6)
        {
            while (kbhit())
            {
            	
            	char c = getch();
                vitri = cot6 + stdongia.size();
                if (c==27)
                {
                    return;
                }
                else if (c==13 || c==27)
                {
		             dongia = StringToInt(stdongia); 
					plag=1;
		            Insert_Vattu(First,MaVT,dongia,soluong);
		            y++; //tang so hang len.
		            MaVT = "";
		            stsoluong = "";
		            stdongia = "";
		            
        		}
                    
                else if(c>=48&&c<=57)
                {
                    gotoxy(vitri,y);
                    stdongia.insert(stdongia.end(),1,c);
 				cout << c;
				
                }
                else if (c==8)
                {
                    if (stdongia.size()!=0)
                    {
                        vitri--;
                        gotoxy(vitri,y);
                        cout<<" ";
                        stdongia.erase(stdongia.end()-1);
                    }
                }
            }
        }
        while (plag==2)
        {
            while (kbhit())
            {
            	char c = getch();
                vitri = cot2 + MaVT.size();
                
                if (c==27)
                {
                    return;
                }
                else if (c==13 || c==27)
                {
                    if (Ktra_Dodai_Ma(MaVT)==false) //ktra ma nhap co dung hay khong
                    {
                        gotoxy(10,1);
                        Highligh_Miss();
                        cout<<"Do dai ma vat tu la 6 ky tu. Xin nhap lai.";
                        gotoxy(cot2,y);
                        cout<<MaVT;
                    }
                    else if (ktra_Vtu(MaVT,j)==false) //kiem tra vat tu co ton tai hay khong
                    {
                        gotoxy(10,1);
                        Highligh_Miss();
                        cout<<"Ma vat tu nay khong ton tai. Xin nhap lai.";
                        gotoxy(cot2,y);
                        cout<<MaVT;
                    }
                    else
                     if (ktra_Vtu(MaVT,j)==true)
                    {
                        gotoxy(10,1);
                        MauMacDinh();
                        cout<<"                                                        ";
                        gotoxy(cot2,y);
                        cout<<"          ";
                        gotoxy(cot2,y);
                        cout<<MaVT;
                        gotoxy(cot3-1,y);
                        cout<<k;
                        gotoxy(cot3,y);
                        cout<<"                   ";
                        gotoxy(cot3,y);
                        cout<<VatTu.Vattu[j].tenVT;
                        gotoxy(cot4-1,y);
                        cout<<k;
                        gotoxy(cot4,y);
                        if(tinhieu==1)
                        {
                        	
                        	 cout<<VatTu.Vattu[j].soLuongTon;
                        	  plag = 5;
                        	  vitri = cot5 + stsoluong.size();
                        	  gotoxy(cot5,y);
                        	 
						}
                        else
                        if(VatTu.Vattu[j].soLuongTon!=0)
                        {
                        		cout<<VatTu.Vattu[j].soLuongTon;
                        		 	  plag = 5;
                        		 	  vitri = cot5 + stsoluong.size();
                        		 	  gotoxy(cot5,y);
                        		
						}
						else
						 {
                       	 gotoxy(10,1);
                       	 Highligh_Miss();
                       	 cout<<"Vat tu chua duoc dinh gia hoac het hang. Xin nhap lai.";
                       	 plag=2;
					   	 }
                        break;
                    }
                }
                else if ((c>=48&&c<=57) || (c>=97 && c<=122) || (c>=65 && c<=90))
                {
                    gotoxy(vitri,y);
                    if (c>=97 && c<=122) c=c-32;
                    cout<<c;
                    MaVT.insert(MaVT.end(),1,c);
                }
                else if (c==8)
                {
                    if (MaVT.size()!=0)
                    {
                        vitri--;
                        gotoxy(vitri,y);
                        cout<<" ";
                        MaVT.erase(MaVT.end()-1);
                    }
                }
            }
        }
    }
}
int CHECK_MANV(int a)
{
	for(int i=0;i<SLNV;i++)
		if(DSMS[i]==a) return true;
	return false;
}
void Insert_hoadon(string MSHD, string MaNV, date Ngay, char loai,CT_HOADON *&First){
    HOADON *q = new HOADON;
    q->HoaDon.SoHD = MSHD;
    q->HoaDon.Loai = loai;
    q->HoaDon.MANV = StringToInt(MaNV);
    q->HoaDon.Ngay = Ngay;
    q->HoaDon.CT_HD = First;
    q->next = searchNV(cayNhanVien,StringToInt(MaNV))->nhanVien.HoaDon;
    searchNV(cayNhanVien,StringToInt(MaNV))->nhanVien.HoaDon = q;
}
void NhapHoaDon(int tinhieu)
{
	time_t baygio = time(0);
	tm *lmt = localtime(&baygio);
    string MSHD, MaNV;
    char Loai;
    CT_HOADON *First = NULL;
    if(tinhieu == 1) Loai = 'N';
    else Loai = 'X';
    system("CLS");
	MauNen1();
    SetColor(12);
    gotoxy(20,0);
    cout <<"****** NHAP HOA DON ******" << endl;
    if (VatTu.soVatTu == 0)
    {
        gotoxy(20,10);
        Highligh_Miss();
        cout<<"Hien trong kho khong co vat tu nao het. ";
        gotoxy(20,12);
        system("Pause");
        return ;
    }
    if (SLNV==0)
    {
        gotoxy(25,10);
        Highligh_Miss();
        cout<<"Hien cong ty chua co nhan vien nao het. ";
        gotoxy(25,12);
        system("Pause");
        return ;
    }
    int y = wherey()+1;
    int check=0;
	Ngay1.day=lmt->tm_mday;
	Ngay1.month=lmt->tm_mon + 1;
	Ngay1.year=lmt->tm_year  + 1900;
	Ngay2 = Ngay1;
	gotoxy(20,y);
	cout << "Tp.HCM ngay " << Ngay1.day << " thang " << Ngay1.month << " nam " << Ngay1.year; 
    y = wherey()+1;
    gotoxy(10,y);
    cout<<"Nhap ma hoa don: ";
    int xHD =wherex();
    gotoxy(xHD+20, y);
    cout<<"Nhap Ma Nhan vien: ";
    int xNV = wherex();
    gotoxy(xNV,y);
    while (check==0)
    {
        while (kbhit())
        {
            int vitri;
            vitri = xNV + MaNV.size();
            gotoxy(vitri,y);
            char c = getch();
            if (c==27)
            {
            	
            	SaveHD();
            	MauNen1();
            	check=2;
                break;
            }
            if(c>=48&&c<=57)
            {
            
                    gotoxy(vitri,y);
                   
                    cout<<c;
                    MaNV.insert(MaNV.end(),1,c);
                
            }
            else if (c==13 || c==9)
            {
                
                
                    if (CHECK_MANV(StringToInt(MaNV))==FALSE)
                    {
                        gotoxy(17,1);
                        Highligh_Miss();
                        cout<<"Ma nhan vien khong ton tai. Xin nhap lai     ";
                        SetBGColor(3);
                        gotoxy(xNV,y);
                        cout<<MaNV;
                        
                    }
                    else
                    {
                       
                        gotoxy(17,1);
                        cout<<"                                                          ";
                        gotoxy(xNV,y);
                        cout<<MaNV;
                        check=1;
                        if(tinhieu == 0)
                        MSHD.insert(MSHD.end(),'X');
                        else if(tinhieu == 1)
                        MSHD.insert(MSHD.end(),'N');
                        MSHD += MaNV;
                        MSHD+=IntToString(Ngay1.day);
                        MSHD+=IntToString(Ngay1.month);
                        MSHD+=IntToString(Ngay1.year - 2000);
                        if(tinhieu == 0){
						MSHD+=IntToString(iX);
                         iX++;
                     	}
                     	else if(tinhieu == 1){
                     		MSHD += IntToString(iN);
                     		iN++;
						 }
                        gotoxy(xHD,y);
                        cout<<MSHD;
                    }
                
            }
            else if (c==8)
            {
                
                if (MaNV.size()!=0)
                {
                    
                    vitri--;
                    gotoxy(vitri,y);
                    cout<<" ";
                    gotoxy(vitri,y);
                    MaNV.erase(MaNV.end()-1);
                }
            }
        }
    }
    if (check==2) return;
    Nhap_DS_Vattu(First,tinhieu);
    Insert_hoadon(MSHD,MaNV,Ngay1,Loai,First);
    MauNen1();
}
void Chi_Tiet_HD(HOADON *F)
{
	int tong = 0;
	PTRCay p = searchNV(cayNhanVien,F->HoaDon.MANV);
	MauNen1();
	SetColor(10);
	int tab=15,i,k;
	int stt=0;
	char T=179;
    int cot1=1, cot2=4, cot3=15, cot4=36, cot5=47, cot6=58;
    gotoxy(0,3);
	cout<<"Thong tin hoa don:"<<endl;
	cout<<"So hoa don:";
	gotoxy(tab,wherey());
	cout<<F->HoaDon.SoHD<<endl;
	cout<<"Loai hoa don:";
	gotoxy(tab,wherey());
	if(F->HoaDon.Loai=='N')
		cout<<"Nhap"<<endl;
	else if(F->HoaDon.Loai='X')
		cout<<"Xuat"<<endl;
	cout<<"Nguoi lap HD:";
	gotoxy(tab,wherey());
	cout<<p->nhanVien.ho<<" "<<p->nhanVien.ten<<endl;
	cout<<"Ma Nhan Vien: ";
	gotoxy(tab,wherey());
	cout<<p->nhanVien.maNV;
	gotoxy(40,wherey());
	cout<<"Ngay "<<(F->HoaDon.Ngay).day<<" thang "<<(F->HoaDon.Ngay).month<<" nam "<<(F->HoaDon.Ngay).year<<endl<<endl;
	cout<<"Danh sach cac vat tu trong hoa don." << endl << endl;
	gotoxy(cot1,wherey());
	cout<<" STT";
	gotoxy(cot2-1,wherey());
	cout<<T<<" Ma VT";
	gotoxy(cot3-1,wherey());
	cout<<T<<"     Ten VT";
	gotoxy(cot4-1,wherey());
	cout<<T<<" So luong";
	gotoxy(cot5-1,wherey());
	cout<<T<<" Don gia"<<endl;
	for(int i=1;i<58;i++)
	{
		if(i==4 || i==15 || i==36 || i==47)
			cout<<char(197);
		else
			cout<<char(196);
	}
	cout<<endl;
	CT_HOADON *C;
	for(C=p->nhanVien.HoaDon->HoaDon.CT_HD;C!=NULL;C=C->next)
	{
		tong += C->soluong*C->dongia;
		stt++;
		cout<<" "<<stt;
		gotoxy(cot2-1,wherey());
		cout<<T<<C->MAVT;
		for(i=0;i<VatTu.soVatTu;i++)
			if(VatTu.Vattu[i].maVT==C->MAVT)
				break;
		gotoxy(cot3-1,wherey());
		cout<<T<<VatTu.Vattu[i].tenVT;
		gotoxy(cot4-1,wherey());
		cout<<T<<C->soluong;
		gotoxy(cot5-1,wherey());
		cout<<T<<C->dongia<<endl;
	}
	gotoxy(0,10);
	cout<<"  Thanh tien: " << tong << " vnd" ;
}
HOADON* TimHD(PTRCay p, string find){
	HOADON *k = new HOADON;
	if(p!= NULL){
		for(k=p->nhanVien.HoaDon;k!=NULL;k=k->next)
		if(k->HoaDon.SoHD==find)
		{
			return k;
		}
		TimHD(p->left,find);
		TimHD(p->right,find);
	}
	return NULL;
}
void In_Thong_Tin_Theo_SoHD(string find){
	HOADON *k = TimHD(cayNhanVien,find);
	int y=wherey()+1;
	MauMacDinh();
	for(int i=0;i<45;i++)
	{
		for(int j=0;j<80;j++)
			cout<<" ";
		gotoxy(0,y+i);
	}
	gotoxy(0,y);
	int check=0;
	HOADON *K = TimHD(cayNhanVien,find);
	
	if(K==NULL)
	{
		Highligh_Miss();
		gotoxy(15,3);
		cout<<"Khong tim thay hoa don.";
	}
	else
	{
		MauMacDinh();
		gotoxy(15,3);
		cout<<"                                              ";
		gotoxy(0,4);
		Chi_Tiet_HD(K);
	}
}
int SoSanhNgay(date a,date b){
	if(a.year*365+a.month*31+a.day<=b.year*365+b.month*31+b.day) return TRUE;
	else return FALSE;
}
void In_Mot_Hoa_Don(){
	MauMacDinh();
	string find;
	int check=0;
	system("cls");
	gotoxy(22,0);
	SetColor(12);
	cout<<"****** THONG TIN MOT HOA DON ******";
	gotoxy(13,2);
	SetColor(14);
	cout<<"Nhap vao so hoa don can xem thong tin: ";
	MauMacDinh();
	int XHD=wherex();
    while (check==0)
    {
        while (kbhit())
        {
            int vitri;
            MauMacDinh();
            vitri = XHD + find.size();
            gotoxy(vitri,2);
            char c = getch();
            if(c==27)
            {
            	gotoxy(15,3);
            	Highlight();
            	cout<<"Ban co muon tro lai muc truoc ?";
            	int xc,xk;
            	xc=wherex();
            	cout<<"Co/";
            	xk=wherex();
            	cout<<"Khong)";
            	gotoxy(xc,wherey());
            	SetColor(0);
            	cout<<"Co";
            	int plagO=0;
            	while(1)
            	{
	                while (!kbhit()) Sleep(100);
	                c=getch();
	                if(c==-32)
	                {
	                	char cc=getch();
	                	if(cc==77 && plagO==0)
	                	{
	                		gotoxy(xc,wherey());
	                		Highlight();
	                		cout<<"Co";
	                		gotoxy(xk,wherey());
	                		SetColor(0);
	                		cout<<"Khong";
	                		plagO=1;
	                	}
	                	if(cc==75 && plagO==1)
	                	{
	                		gotoxy(xk,wherey());
	                		Highlight();
	                		cout<<"Khong";
	                		gotoxy(xc,wherey());
	                		SetColor(0);
	                		cout<<"Co";
	                		plagO=0;
	                	}
	                }
	                if(c==13)
	                {
	                	if(plagO==0)
	                	{
	                		check=2;
	                		break;
	                	}
	                	else
	                	{
	                		gotoxy(15,3);
	                		MauMacDinh();
	                		cout<<"                                               ";
	                		gotoxy(vitri,2);
	                		break;
	                	}
	                }
				}
				if(check==2)
					break;
            }
            else if ((c>=48&&c<=57) || (c>=97 && c<=122) || (c>=65 && c<=90))
            {
                gotoxy(vitri,2);
                
	                if (c>=97 && c<=122) c = c-32;
    	            cout<<c;
        	        find.insert(find.end(),1,c);
        	    
            }
            else if (c==8)
            {
                if (find.size()!=0)
                {
                    MauMacDinh();
                    vitri--;
                    gotoxy(vitri,2);
                    cout<<" ";
                    gotoxy(vitri,2);
                    find.erase(find.end()-1);
                }
            }
            else if (c==13 || c==9)
            {
            	In_Thong_Tin_Theo_SoHD(find);
            	gotoxy(vitri,2);
            }
        }
    }
    MauNen1();
}
void Thong_Ke_Hoa_Don(){
	int cot1 = 2, cot2 = 18 , cot3 = 47, cot4 =66;
	int flag =2 ; //Dang Nhap: 1: Ma VT, 2:Ten VT, 3:DVT , 4: SLT.
	int vitri, y = 6;
	int PASS =1, i = 0;
	date aa,bb;
		system("cls");
		 MauNen1();
	string stngay[2],stthang[2],stnam[2];
	gotoxy(cot1,6); cout << "tu ngay";
	gotoxy(cot2+7,6); cout <<"thang";
	gotoxy(cot3+3,6); cout <<"nam";
	gotoxy(cot1,7); cout << "den ngay";
	gotoxy(cot2+7,7); cout <<"thang";
	gotoxy(cot3+3,7); cout <<"nam";
	HOADON *q = NULL;
	gotoxy(22,0);
	SetColor(12);
    gotoxy(15,3);
    SetColor(14);
	cout<<"Nhap vao khoang thoi gian can tim cac hoa don:";
	MauMacDinh();
	int check=0;
	int xngay,xthang,xnam;
	int tongTrang = 0, trang = 1;
	//nhap ngay thang nam thu 1
    gotoxy(cot2,y);
	while(i<2){
time: gotoxy(cot2,y);	
		while(kbhit()){
			if (flag == 2)
				vitri = cot2 + stngay[i].size();
			if (flag == 3)
				vitri = cot3 + stthang[i].size();
			if (flag == 4)
				vitri = cot4 + stnam[i].size();
			char c = getch();
			if (c == 27){
						
				break;
			}
			else if( c == 13 || c == 9){ //Neu nhan Enter,Tab.
				if(flag == 2 ){
					if(stngay[i] == "" || 1 > StringToInt(stngay[i])||StringToInt(stngay[i]) >31){
						gotoxy(0,0); cout << "Ngay tu 1 den 31";
						ChonMau();
						
						gotoxy(cot2,y);
						cout << stngay[i];
						ChonMau4();
					}
					else{
						SetBGColor(3);
						gotoxy(0,0); cout << "                                ";
						gotoxy(cot2,y);
						gotoxy(cot2,y);
						cout << stngay[i];
						flag++;
						gotoxy(cot3,y);
					}
				}
				else if( flag == 3 ){
					if(stthang[i] == "" || 1 > StringToInt(stthang[i])||StringToInt(stthang[i]) > 12){
					gotoxy(0,0);
					cout << "thang chi tu 1 den 12";
						gotoxy(cot3,y);
						cout << stthang[i];
					}
					else{
						SetBGColor(3);
						gotoxy(0,0); cout << "                                ";
						gotoxy(cot3,y);
						cout << stthang[i];
						flag++;
						gotoxy(cot4,y);
					}
				}
				else if( flag==4 ){
					
					if(stnam[i]== "" || 2000 > StringToInt(stnam[i]))
            		{
            			gotoxy(0,0); cout << "Nam khong hop le";
            			gotoxy(cot4,y);
            			cout<<stnam[i];
            		
            		}
					else{
						SetBGColor(3);
						gotoxy(0,0); cout << "                                ";
						gotoxy(cot4,y);
						cout<<stnam[i];
            			flag=2;
            			gotoxy(cot1,y);
            			i++; // Chuyen sang nhan vien tiep theo.
						y++; // Tang so cot.
						flag=2;
						gotoxy(cot2,y);
					}
				}
			}
			if( ( c >=48 && c<=57 ) || (c==32)){// Nhan phim so.
				if (flag == 2 && vitri<45){
                    gotoxy(vitri,y);
                    cout<<c;
                    stngay[i].insert(stngay[i].end(),1,c);
                    vitri++;
                }
                else if (flag == 3 && vitri<65){
                    gotoxy(vitri,y);
                    cout<<c;
                    stthang[i].insert(stthang[i].end(),1,c);
                    vitri++;
                }
                else if (flag == 4 && vitri<78 && c!=32){	
                    gotoxy(vitri,y);
                    cout<<c;
					stnam[i].insert(stnam[i].end(),1,c);
                    vitri++;
                }
			}
			else if( c == 8){ //Phim Backspace.
				if(flag==2 && stngay[i].size()!=0){
                    vitri--;
                    gotoxy(vitri,y);
                    cout << " ";
                    gotoxy(vitri,y);
                    stngay[i].erase(stngay[i].end()-1);
                }
				else if( flag==3 && stthang[i].size() !=0 ){
                    vitri--;
                    gotoxy(vitri,y);
                    cout << " ";
                    gotoxy(vitri,y);
                    stthang[i].erase(stthang[i].end()-1);
                }
                else if( flag==4 && stnam[i]!= "" ){
                    vitri--;
                    gotoxy(vitri,y);
                    cout << " ";
                    gotoxy(vitri,y);
                    stnam[i].erase(stnam[i].end()-1);
                }
			}
			else if (c==-32) // Phim dac biet
            {
                c = getch();
                
                if (c==75){ //Mui ten qua trai
                    if (flag == 3){
                        flag = 2;
                        gotoxy(cot2+stngay[i].size(),y);
                    }
                    else if(flag==4){
                    	flag = 3;
                    	gotoxy(cot3+stthang[i].size(),y);
                    }
                }
                if (c==77){ //Mui ten qua phai
                    if ( flag ==2 && stngay[i] !=""){
                        flag = 3;
                        gotoxy(cot3+stthang[i].size(),y);
                    }
                    else if (flag ==2 && stngay[i] =="")
                    	gotoxy(cot2,y);
                    else if( flag == 3 && stthang[i] != "" ){
                    	flag = 4;
	                    gotoxy(cot4+stnam[i].size(),y);
					}
                    else if(flag == 3 && stnam[i] == ""){
                    	gotoxy(cot3,y);
                	}
            	}
			}
		}
	}
	aa.day = StringToInt(stngay[0]);
	bb.day = StringToInt(stngay[1]);
	aa.month = StringToInt(stthang[0]);
	bb.month = StringToInt(stthang[1]);
	aa.year = StringToInt(stnam[0]);
	bb.year = StringToInt(stnam[1]);
    if(SoSanhNgay(aa,bb) == FALSE)//kiem tra de thoi gian hop li
        {
        	gotoxy(5,3);
        	Highligh_Miss();
        	cout<<"Ban vui long kiem tra lai khoang thoi gian lap hoa don cho hop li ";
        	Sleep(2700);
        	i = 0;
        	y = 6;
			goto time;	
		}
		
			PTRCay Stack[500];
		int sp = -1;
		PTRCay p =cayNhanVien;
		while(p!= NULL){
			if(p->nhanVien.HoaDon != NULL)
			for(HOADON *CC=p->nhanVien.HoaDon;CC!=NULL;CC=CC->next)
			if(SoSanhNgay(CC->HoaDon.Ngay,aa) == FALSE &&SoSanhNgay(CC->HoaDon.Ngay,bb) == TRUE ){
			tongTrang++;
            HOADON *t = new HOADON;
        	t->HoaDon = CC->HoaDon;
            t->next = q;
            q = t;
			}
			
			if(p->right != NULL)
			Stack[++sp] = p->right;
			if(p->left != NULL) p = p->left;
			else if(sp == -1) break;
			else p = Stack[sp--];			
		}
			if(q == NULL)
  			  {	
    			
       	    	MauNen1();
       	    	textcolor(10);
       	    	gotoxy(0,8);
       	    	for(int i=1;i<80;i++)
					{
      				  cout<<char(196);
					}
					gotoxy(5,3);
      		    Highligh_Miss();
       	    	cout<<"Khong co hoa don nao duoc lap trong khoang thoi gian tren      ";
				gotoxy(0,9+1);
				cout<<"ESC:Thoat !";
				gotoxy(40,9);
				cout<<"Nhan phim bat ky de tiep tuc";
					while(!kbhit()) Sleep(200);
       	    	char c=getch();
       	    	if(c==27){
       	    		MauNen1();
       	    		return;
				}
       	    	else
			   		{	
			   			MauNen1();
				  		goto time;
					} 
                }
    HOADON *k = q;
next:    Chi_Tiet_HD(k);
    gotoxy(0,1);
	for(int i=1;i<80;i++)
	{
        cout<<char(196);
	}
	gotoxy(30,0);
	textcolor(10);
	cout<<"Trang "<<trang<<"/"<<tongTrang;
	gotoxy(60,0);
	char back1 = 27, next = 26;
	cout<<"Back: "<<back1<<" | "<<next<<" :Next";
	gotoxy(0,0);
	cout<<"ESC: Thoat";
back:    char c = getch();
    if (c==-32)
    {
        c = getch();
        if (c==75) //mui ten qua trai
        {
            if (trang == 1)
            {
                HOADON *i;
                for (i = q; i->next != NULL; i=i->next);
                k = i;
                trang = tongTrang;
                goto next;
            }
            else
            {
                HOADON *i;
                for (i = q; i->next !=k; i=i->next);
                k = i;
                trang--;
                goto next;
            }
        }
        else if (c==77) //mui ten qua phai
        {
            if(trang == tongTrang)
            {
                k = q;
                trang = 1;
                goto next;
            }
            else
            {
                k = k->next;
                trang++;
                goto next;
            }
        }
        else goto back;
    }
    else if (c==27)
    {
    	MauNen1();
        return;
       
    }
    else goto back;
}
//-----------Doc va ghi vao file --------//
void Save_Vat_Tu(){
    ofstream a("VATTU.txt",ios::out);
    for(int i=0 ; i<VatTu.soVatTu ;i++){
		a<<VatTu.Vattu[i].maVT<<endl<<VatTu.Vattu[i].tenVT<<endl;
		a<<VatTu.Vattu[i].dVT<<endl<<VatTu.Vattu[i].soLuongTon<< endl << VatTu.Vattu[i].TansuatX<<endl << VatTu.Vattu[i].TansuatN << endl;
	}
	a.close();
}
void Load_Vat_Tu(){
	ifstream a ("VATTU.txt",ios::in);
	while((getline(a,VatTu.Vattu[VatTu.soVatTu].maVT))!= FALSE)
	{
		getline(a,VatTu.Vattu[VatTu.soVatTu].tenVT);
		getline(a,VatTu.Vattu[VatTu.soVatTu].dVT);
		a>>VatTu.Vattu[VatTu.soVatTu].soLuongTon;
		a>>VatTu.Vattu[VatTu.soVatTu].TansuatX;
		a>>VatTu.Vattu[VatTu.soVatTu].TansuatN;
		a.ignore();
		int plag=0;
		for(int i=0 ; i < VatTu.soVatTu ; i++)
			if(VatTu.Vattu[i].maVT==VatTu.Vattu[VatTu.soVatTu].maVT)
			{
				plag=1;
				break;
			}
		if(plag==0)
			VatTu.soVatTu++;
	}
	a.close();
}
void SaveHD(){
	ofstream t("HoaDon.txt",ios::out);
	PTRCay Stack[500];
		int sp = -1;
		PTRCay p = cayNhanVien;
		while(p!= NULL){
			if(p->nhanVien.HoaDon != NULL){
				HOADON *b =NULL;
				for(b=p->nhanVien.HoaDon;b!=NULL;b=b->next){
					if(b!= NULL && b->HoaDon.MANV!= 0){
		
						t<<"HD"<<endl;
						t<<b->HoaDon.SoHD<<" "<<b->HoaDon.MANV<<" "<<(b->HoaDon.Ngay).day<<" "<<(b->HoaDon.Ngay).month<<" "<<(b->HoaDon.Ngay).year<<" "<<b->HoaDon.Loai<<endl;
						CT_HOADON *c;
						for (c = b->HoaDon.CT_HD; c != NULL; c = c->next){
		        			t<<"VT"<<endl;
	            			t<<c->MAVT<<" "<<c->soluong<<" "<<c->dongia<<endl;
	     				}  
		 	
					}
    			}
			}
			if(p->right != NULL)
			Stack[++sp] = p->right;
			if(p->left != NULL) p = p->left;
			else if(sp == -1) break;
			else p = Stack[sp--];			
		}
		 t.close();
		 SavePhu();
}

void LoadHD(){
	ifstream a("HoaDon.txt",ios::in);
	string f;	
	while(getline(a,f)!= NULL)
	{
	
		while(f=="HD")
		{
			CT_HOADON *FirstT = NULL ;
			HOADON *b=new HOADON;
			a>>b->HoaDon.SoHD>>b->HoaDon.MANV>>(b->HoaDon.Ngay).day>>(b->HoaDon.Ngay).month>>(b->HoaDon.Ngay).year>>b->HoaDon.Loai;
			getline(a,f);
			getline(a,f);
			while(f=="VT"){
				CT_HOADON *TAM=new CT_HOADON;
				a>>TAM->MAVT>>TAM->soluong>>TAM->dongia;
				TAM->next=FirstT;
				FirstT=TAM;
				getline(a,f);
				getline(a,f);
			}
			b->HoaDon.CT_HD=FirstT;
			b->next=searchNV(cayNhanVien,b->HoaDon.MANV)->nhanVien.HoaDon;
			searchNV(cayNhanVien,b->HoaDon.MANV)->nhanVien.HoaDon=b;
		}
	}
	a.close();
}
void LoadAll(){
	Load_Vat_Tu();
	LoadNV();
	LoadHD();
	LoadPhu();
	time_t baygio = time(0);
	tm *lmt = localtime(&baygio);
	if(Ngay2.day!=lmt->tm_mday||Ngay2.month!= lmt->tm_mon + 1||Ngay2.year != lmt->tm_year+1900){
		iX = 0;
		iN = 0;
	}//reset so HD
}
void SaveAll(){
	Save_Vat_Tu();
	taofile("NhanVien.txt");
	SaveNV(cayNhanVien);
	SaveHD();
}
void ThongKeTanSuat(){
	system("cls");
	int cot1 = 4, cot2 = 18 , cot3 = 47, cot4 =66;
	int vitri, y = 8;
	for(int i = 0; i < VatTu.soVatTu; i++)
		for(int j = 0; j < VatTu.soVatTu ;j++){
			if(VatTu.Vattu[i].TansuatX > VatTu.Vattu[j].TansuatX)
			swap(VatTu.Vattu[j], VatTu.Vattu[i]);
		}
	MauNen1();
	KhungTieuDe("    Vat tu Xuat Nhieu Nhat     ");
	KhungNhap();
	gotoxy(cot1,6); cout << "Ma Vat Tu";
	gotoxy(cot2+7,6); cout <<"Ten Vat Tu";
	gotoxy(cot3+3,6); cout <<"So Luong Ton";
	gotoxy(cot4,6); cout <<"So Lan Xuat";
	SetColor(14);
	gotoxy(3,22); cout << " Nhan phim bat ki de tiep tuc" << endl;;
	ChonMau4();
	for(int i = 0; i < 10; i++){
		gotoxy(cot1,y); cout << VatTu.Vattu[i].maVT;
		gotoxy(cot2,y); cout << VatTu.Vattu[i].tenVT;
		gotoxy(cot3,y); cout << VatTu.Vattu[i].soLuongTon;
		gotoxy(cot4,y); cout << VatTu.Vattu[i].TansuatX;
		y++;
	}
	getch();
	MauNen1();
	
}
//------------Menu------------//
int current_Mc = 0 ,current_M = 0,dichuyen = 0; //Mc la menu chinh, M la menucon.
string menuChinh[20] ={"1. Quan li vat tu",
					   "2. Quan li nhan vien ",
					   "3. Menu hoa don",
					   "4. Thoat"};
string menu1[10]	 ={"1. Nhap vat tu",
					   "2. Xem ds vat tu ton kho",};
string menu2[10]	 ={"1. Nhap nhan vien",
					   "2. Xem ds nhan vien"};
string menu3[10]	 ={"1. Lap hoa don nhap",
						"2.Lap hoa don xuat",
						"3. In hoa don",
						"4. DSVT Xuat Nhieu Nhat",
						"5.Thong Ke DS Hoa Don"};
string menurong[10] ={"","","","",""};
void MenuChinh(){
	gotoxy(5,6);
	int dem = 6;
	cout << left;
	for(int i=0; i<4 ; i++){
		ChonMau2();
		if(current_Mc == i){
			ChonMau();
			gotoxy(5,i+dem);
			cout << setw(22)<<" " << endl;
			gotoxy(5,i+dem+1);
			cout << setw(22)<<menuChinh[i] << endl;
			gotoxy(5,i+dem+2);
			cout << setw(22)<<" " << endl;
			ChonMau2();
		}
		else{
			gotoxy(5,i+dem);
			cout << setw(22)<<" "<<endl;
			gotoxy(5,i+dem+1);
			cout << setw(22)<<menuChinh[i] << endl;
			gotoxy(5,i+dem+2);
			cout << setw(22)<<" "<< endl;
			ChonMau2();
		}
		dem = dem + 3;
	}
}
void MenuCon(string menu[]){
	cout << left;
	int dem = 7;
	for(int i =0 ; i < 5; i++){
		ChonMau2();
		if(current_M == i){
			if(menu[i].size()!=0){
			ChonMau();
			gotoxy(30,i+dem);
			cout << setw(30)<<" "<<endl;
			gotoxy(30,i+1+dem);
			cout << setw(30)<<menu[i] << endl;
			gotoxy(30,i+2+dem);
			cout << setw(30)<<" "<< endl;
			ChonMau2();
			}
		}
		else{
			if(menu[i].size()!=0){
				gotoxy(30,i+dem);
				cout << setw(30)<<" "<<endl;
				gotoxy(30,i+1+dem);
				cout << setw(30)<<menu[i] << endl;
				gotoxy(30,i+2+dem);
				cout << setw(30)<<" "<< endl;
				ChonMau2();}
			else{
				ChonMau4();
				gotoxy(30,i+dem);
				cout << setw(30)<<" "<<endl;
				gotoxy(30,i+1+dem);
				cout << setw(30)<<" " << endl;
				gotoxy(30,i+2+dem);
				cout << setw(30)<<" "<< endl;
				ChonMau2();
			}
		}
		if(menu[i].size()==0){
			ChonMau4();
			gotoxy(30,i+dem);
			cout << setw(30)<<" "<<endl;
			gotoxy(30,i+1+dem);
			cout << setw(30)<<" " << endl;
			gotoxy(30,i+2+dem);
			cout << setw(30)<<" "<< endl;
			ChonMau2();
		}
		dem = dem+3;
	}
}
void LoadMenu(){
	KhungTieuDe("    M A I N     M E N U   ");
	if(dichuyen == 0){
		ChonMau4();
		gotoxy(30,4);
		cout << "                              ";
		ChonMau3();
		gotoxy(5,4);
		cout << "______________________";
		ChonMau;
	}
	else{
		ChonMau4();
		gotoxy(5,4);
		cout << "                      ";
		ChonMau3();
		gotoxy(30,4);
		cout << "______________________________";
		ChonMau();
	}
	MenuChinh();
	switch(current_Mc){
		case 0:
			MenuCon(menu1);
			break;
		case 1:
			MenuCon(menu2);
			break;
		case 2:
			MenuCon(menu3);
			break;
		case 3:
			MenuCon(menurong);
			break;
	}
}
void Select(){
		MauNen1();
		int PASS = 1;
		int keyboard_read = 0;
		LoadMenu();
		while(PASS){
		keyboard_read = getch();
		if (keyboard_read == 0){ keyboard_read = getch();}
		if(dichuyen ==0) // Dang o Menu Chinh
			switch(keyboard_read){
				case 49: //1
					current_Mc = 0;
					dichuyen++;
					LoadMenu();
					break;
				case 50: //2
					current_Mc = 1;
					dichuyen++;
					LoadMenu();
					break;
				case 51: //3
					current_Mc = 2;
					dichuyen++;
					LoadMenu();
					break;
				case 52://4
					current_Mc = 3;
					LoadMenu();
					PASS =0;
					if(YN("BAN CO MUON LUU TAT CA THAY DOI?")==1)
						 SaveAll();
						 delete cayNhanVien;
					break;
				case 72:
					if(current_Mc > 0){ current_Mc=current_Mc-1;}
				    LoadMenu(); 
					break;
				case 75:
					if(current_Mc > 0){ current_Mc=current_Mc-1;}
				    LoadMenu(); 
					break;
				case 77:
					if(current_Mc == 3){
						PASS =0;
						if(YN("BAN CO MUON LUU TAT CA THAY DOI?")==1)
						 SaveAll();
						 delete cayNhanVien;
					}
					else
						dichuyen++;
					LoadMenu();
					break;
				case 80: 
					if(current_Mc >= 0 && current_Mc < 3)
					{ current_Mc=current_Mc+1;}
					LoadMenu();
					break;
				case 13:
					if(current_Mc == 3){
						PASS =0;
						if(YN("BAN CO MUON LUU TAT CA THAY DOI?")==1)
						 SaveAll();
						 delete cayNhanVien;
					}
					else
						dichuyen++;
					LoadMenu();
					break;
			}
		else // Dang o Menu Con
				switch(keyboard_read){
				case 72: //Len
					if(current_M > 0){ current_M=current_M-1;}
				    LoadMenu(); 
					break;
				case 80: //Xuong;
					if(current_M >= 0 && current_Mc==2 && current_M<4 || current_M >= 0 && current_Mc!=2 && current_M<1 )
					{ current_M = current_M+1;}
					LoadMenu();
					break;
				case 75: //Trai;
					current_M = 0;
					dichuyen--;
					LoadMenu();
					break;
				case 49: //So 1
					if(current_Mc == 0){
						NhapVatTu();
						LoadMenu();
					}
					break;
						
				case 50: //So 2
					if(current_Mc == 0){
						XemVatTu();
						LoadMenu();	
					}
					break;		
				case 13: //Enter;
					if(current_Mc == 0){ //Muc: Quan li vat tu.
						if(current_M == 0)
							NhapVatTu();
						else XemVatTu();
						LoadMenu();
					}
					else if(current_Mc == 1){ //Muc: Quan li nhan vien.
						if(current_M == 0){
							LoadNV();
							NhapNV();
						}
						else{
							inDSNV();
						}
						LoadMenu();
					}
					else if(current_Mc == 2){ //Muc: Quan li hoa don.
						if(current_M == 0){
							NhapHoaDon(1);
						}
						else if(current_M == 1){
							NhapHoaDon(0);
						}
						else if(current_M == 2){
							In_Mot_Hoa_Don();
						}
						else if(current_M == 3){
							ThongKeTanSuat();
						}
						else if(current_M == 4){
							Thong_Ke_Hoa_Don();
						}
						
						LoadMenu();
					}
					break;
				case 27: //Ecs;
					current_M = 0;
					dichuyen--;
					LoadMenu();
					break;
				}	
		}
		KhungKetThuc();
}
int main(){
	CuaSoConsole();
	LoadAll();
	Select();
}
