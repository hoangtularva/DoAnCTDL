/*
Hoten: Tran Phong Nha
MSSV: 18211TT1000
Hoten: Nguyen Phuong Tan
MASV: 18211TT2680
Hoten: Tran Trieu Thuan
MASV: 18211TT0530
Hoten: Tran Hoang Tu
MASV: 18211TT0809


Project Chuong Trinh Mo Phong May ATM
Chinh Sua Lan Cuoi 28/05/2019
*/


//Thu vien: 
//loai bo loi canh bao khi chay chuong trinh
#pragma warning(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <ctime>

//Thu vien ham Sleep
#include <Windows.h>

//Thu vien an esc de thoat
#include<conio.h>
using namespace std;

struct TAIKHOAN
{
	string sTaiKhoan;
	string sMatKhau;
	string sHoTen;
	string sSoTaiKhoan;
	string sLoaiTien;
	long int nTien = 0;
};

struct Print
{
	string sThoiGianRut, sThoiGianChuyen;
	string sTenNguoiGui, sTenNguoiNhan, sTaiKhoanNhan, sThoiGianNhan;
	long int nSoTienRut = 0;
	long int nSoTienNhan = 0;
	long int nSoTienChuyen = 0;
};

//Ham Lay thoi gian trong he thong may tinh
time_t now = time('\00');
tm *t = localtime(&now);

string sMaATM = "998091"; //Ma tru ATM
int tam;

//-----------------Khai bao nguyen mau ham-------------------

//thay doi mau cho chu
void SetColor(int ForgC);

//ma hoa mat khau
string maHoaMK(unsigned int maxLength);

//cac ham kiem tra thong tin
int checkTTin(vector<TAIKHOAN> TKdangnhap, string sTaiKhoan, string sMatKhau);
bool test(vector<TAIKHOAN> TKdangnhap, string sTaiKhoan, string sMatKhau);
int checkSoTaiKhoan(vector<TAIKHOAN> TKdangnhap, string sSoTaiKhoan);

//cac ham nhap xuat doi voi file
void docDuLieu(vector<TAIKHOAN>& TKdangnhap);
void capNhatDuLieu(vector<TAIKHOAN>& TKdangnhap);
void LoadN(int& nN);
int nDemSoLuongN();
void docLichSuGiaoDich(vector<TAIKHOAN> & TKdangnhap, int vitri);
int nPhiGiaoDich(int nTien, string sForm);
void rutTien(vector<TAIKHOAN>&TKdangnhap, vector<Print>&pr, int vitri);
void chuyenTien(vector<TAIKHOAN>& TKdangnhap, vector<Print>& pr, int vitri);
void DangNhap(vector<TAIKHOAN>& TKdangnhap, int &vitri);
void menu(vector<TAIKHOAN> & TKdangnhap, vector<Print>& pr, int vitri);
void inHoaDon(vector<TAIKHOAN> & TKdangnhap, vector<Print>& pr, int vitri, string sForm, int nTienRut, int nPGD);
void doiMatKhau(vector<TAIKHOAN>& TKdangnhap, int vitri);
string kiemTraTime(vector<TAIKHOAN>& TKdangnhap, int vitri, string sX);
void ghiLichSuGiaoDich(vector<TAIKHOAN> & TKdangnhap, vector<Print>& pr, int vitri, string sForm, int nTienRut, int nPGD);
//Chuong trinh chinh:
int main() {
	int nN, vitri = -1;
	LoadN(nN);
	vector<TAIKHOAN> vec(nN);
	docDuLieu(vec);
	vector<Print> pr;
	DangNhap(vec, vitri);
	if (vitri != -1) {
		menu(vec, pr, vitri);
	}
	system("pause");
}

//Chuc nang dang nhap 
void DangNhap(vector<TAIKHOAN>& TKdangnhap, int &vitri)
{
DangNhapLai:
	int nDem = 0;
	string sTaiKhoan = "", sMatKhau = "";
	do {
		system("cls");
		nDem++;
		SetColor(11);
		cout << "\t\t*********************************\n";
		SetColor(11);
		cout << "\t\t*";
		SetColor(14);
		cout << "\tDANG NHAP HE THONG\t";
		SetColor(11);
		cout << "*\n";
		SetColor(11);
		cout << "\t\t*********************************\n";
		if (nDem == 2)
		{
			SetColor(12);
			cout << "\n\t\tBAN DA NHAP SAI! VUI LONG NHAP LAI!!\n";
			cout << "\n\t\tCHU Y: CON 2 LAN THU!\n" << endl << endl;
			system("pause");
			system("cls");
		}
		if (nDem == 3) {
			SetColor(12);
			cout << "\n\t\tBAN DA NHAP SAI! VUI LONG NHAP LAI!!\n";
			cout << "\n\t\tCHU Y: CON 1 LAN THU!\n" << endl << endl;
			system("pause");
			system("cls");
		}
		if (nDem >= 4) {
			SetColor(12);
			cout << "\n\t\tBAN DA NHAP SAI QUA 3 LAN! XIN VUI LONG THU LAI SAU!\n" << endl;
			cout << "\t\tHE THONG SE TU DONG THOAT RA KHOI HE THONG SAU VAI GIAY NUA.!!!";
			Sleep(7000);
			goto DangNhapLai;
		}
		system("cls");
		SetColor(11);
		cout << "\t\t*********************************\n";
		SetColor(11);
		cout << "\t\t*";
		SetColor(14);
		cout << "\tDANG NHAP HE THONG\t";
		SetColor(11);
		cout << "*\n";
		SetColor(11);
		cout << "\t\t*********************************\n";
		SetColor(14);
		cout << "\t\tLuu y: Nhan ";
		SetColor(12);
		cout << "ESC";
		SetColor(14);
		cout << " de thoat khoi he thong!\n" << endl;
		SetColor(14);
		cout << "\t\tNhan phim bat ki de bat dau DANG NHAP!\n\n";
		char ESC;
		int kiemtraESC;
		ESC = _getch();
		kiemtraESC = ESC;
		while (kiemtraESC == 27)
		{
			exit(0);
		}
		SetColor(14);
		cout << "\t\tUser:\t";
		SetColor(10);
		rewind(stdin);
		getline(cin, sTaiKhoan);
		//Ma hoa mat khau:
		SetColor(14);
		cout << "\t\tPass:\t";
		SetColor(10);
		sMatKhau = maHoaMK(6);
		SetColor(14);
		cout << "\n\t\tDang kiem tra thong tin...";
		Sleep(1000);
	} while (checkTTin(TKdangnhap, sTaiKhoan, sMatKhau) == -1);
	//tra ve vitri neu da dang nhap thanh cong
	vitri = checkTTin(TKdangnhap, sTaiKhoan, sMatKhau);
	system("cls");
}

void SetColor(int ForgC)
{
	WORD wColor;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	//We use csbi for the wAttributes word.
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		//Mask out all but the background attribute, and add in the forgournd color
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
	return;
}

void docDuLieu(vector<TAIKHOAN>& TKdangnhap)
{
	ifstream fcin;
	fcin.open("TheTu.txt");
	fcin.ignore(2);
	for (int i = 0; i < TKdangnhap.size(); i++)
	{
		rewind(stdin);
		getline(fcin, TKdangnhap[i].sTaiKhoan, '#');
		rewind(stdin);
		getline(fcin, TKdangnhap[i].sMatKhau, '#');
		rewind(stdin);
		getline(fcin, TKdangnhap[i].sHoTen, '#');
		rewind(stdin);
		getline(fcin, TKdangnhap[i].sSoTaiKhoan, '#');
		rewind(stdin);
		getline(fcin, TKdangnhap[i].sLoaiTien, '#');
		fcin >> TKdangnhap[i].nTien;
		fcin.ignore(1);
	}
	fcin.close();
}

int nDemSoLuongN()
{
	int nDem = 0;
	string s = "";
	ifstream fin;
	fin.open("TheTu.txt");
	while (!fin.eof())
	{
		nDem++;
		getline(fin, s, '\n');
	}
	fin.close();
	return nDem;
}

void capNhatDuLieu(vector<TAIKHOAN>& TKdangnhap) {
	int nSoLuongN = nDemSoLuongN();
	ofstream fcout;
	fcout.open("TheTu.txt");
	fcout << TKdangnhap.size() << endl;
	for (int i = 0; i < TKdangnhap.size(); i++) {
		fcout << TKdangnhap[i].sTaiKhoan << "#" << TKdangnhap[i].sMatKhau
			<< "#" << TKdangnhap[i].sHoTen << "#" << TKdangnhap[i].sSoTaiKhoan
			<< "#" << TKdangnhap[i].sLoaiTien
			<< "#" << TKdangnhap[i].nTien << endl;
	}
	fcout.close();
}

bool test(vector<TAIKHOAN> TKdangnhap, string sTaiKhoan, string sMatKhau)
{
	TAIKHOAN TKhoan;
	for (int i = 0; i < TKdangnhap.size(); i++)
	{
		if (TKdangnhap[i].sTaiKhoan == sTaiKhoan && TKdangnhap[i].sMatKhau == sMatKhau)
		{
			return true;
		}
	}
	return false;
}

void LoadN(int& nN)
{
	ifstream fcin;
	fcin.open("TheTu.txt");
	fcin >> nN;
	fcin.close();
}

int checkTTin(vector<TAIKHOAN> TKdangnhap, string sTaiKhoan, string sMatKhau) {
	TAIKHOAN TKhoan;
	for (int i = 0; i < TKdangnhap.size(); i++)
	{
		if (TKdangnhap[i].sTaiKhoan == sTaiKhoan && TKdangnhap[i].sMatKhau == sMatKhau)
		{
			return i;
		}
	}
	return -1;
}

int checkSoTaiKhoan(vector<TAIKHOAN> TKdangnhap, string sSoTaiKhoan) {
	for (int i = 0; i < TKdangnhap.size(); i++)
	{
		if (TKdangnhap[i].sSoTaiKhoan == sSoTaiKhoan)
		{
			return i;
		}
	}
	return -1;
}

string maHoaMK(unsigned int maxLength)
{
	string pw = "";
	for (char c; (c = _getch()); )
	{
		if (c == '\n' || c == '\r') { // \n là phím phím enter + \r là Nhảy về đầu hàng, không xuống hàng
			cout << "\n";
			break;
		}
		else if (c == '\b') { //phi­m backspace
			cout << "\b \b";
			if (!pw.empty())
				pw.erase(pw.size() - 1);
		}
		else if (c == -32) {//phím mũi tên
			_getch(); //bỏ qua kí tự tiếp theo (hướng mũi tên)
		}
		else if (isprint(c) && pw.size() < maxLength) {  //isprint tức là chỉ nhận những ký tự in ra được (có tính khoảng trắng)
			cout << '*';
			pw += c;
		}
	}
	return pw;
}

void menu(vector<TAIKHOAN> & TKdangnhap, vector<Print>& pr, int vitri)
{
menu:
	int chon;
	char c;
	TAIKHOAN TKhoan;
	system("cls");
	SetColor(11);
	cout << "\t\t*********************************\n";
	SetColor(11);
	cout << "\t\t*";
	SetColor(14);
	cout << "\tKINH CHAO QUY KHACH\t";
	SetColor(11);
	cout << "*\n";
	SetColor(11);
	cout << "\t\t*********************************\n";
	SetColor(14);
	cout << "\t\t\tCAC CHUC NANG CHINH:\n";
	cout << "\t\t1. Rut tien\n";
	cout << "\t\t2. Chuyen tien\n";
	cout << "\t\t3. Doi Mat Khau\n";
	cout << "\t\t4. Xem lich su giao dich\n\n";
	SetColor(27);
	cout << "\t\tNhan ESC de thoat!\n";
	cout << "\t\tNhan phim bat ki de tiep tuc!!!\n\n";
	char ESC;
	int kiemtraESC;
	ESC = _getch();
	kiemtraESC = ESC;
	while (kiemtraESC == 27)
	{
		exit(0);
	}
	SetColor(14);
	cout << "\t\tBan chon chuc nang so: ";
	cin >> chon;
	system("cls");
	switch (chon)
	{
	case 1:
	{
		rutTien(TKdangnhap, pr, vitri);
		cout << "\t\tNHAN PHIM BAT KI DE TIEP TUC. HOAC NHAN ESC DE THOAT CHUONG TRINH !!!" << endl;
		while (true) {
			c = _getwch();
			if (c != 27)
				goto menu; //Quay chương trình về điểm "menu:"
			else
				exit(0); //Thoát chương trình
		}
		break;
	}
	case 2:
	{
		chuyenTien(TKdangnhap, pr, vitri);
		cout << "\t\tNHAN PHIM BAT KI DE TIEP TUC. HOAC NHAN ESC DE THOAT CHUONG TRINH !!!" << endl;
		while (true) {
			c = _getwch();
			if (c != 27)
				goto menu; //Quay chương trình về điểm "menu:"
			else
				exit(0); //Thoát chương trình
		}
		break;
	}
	case 3:
	{
		doiMatKhau(TKdangnhap, vitri);
		SetColor(14);
		cout << "\t\tNHAN PHIM BAT KI DE TIEP TUC. HOAC NHAN ESC DE THOAT CHUONG TRINH !!!" << endl;
		while (true) {
			c = _getwch();
			if (c != 27)
				goto menu; //Quay chương trình về điểm "menu:"
			else
				exit(0); //Thoát chương trình
		}
		break;
	}
	case 4:
	{
		docLichSuGiaoDich(TKdangnhap, vitri);
		SetColor(14);
		cout << "\t\t\tNHAN PHIM BAT KI DE TIEP TUC. HOAC NHAN ESC DE THOAT CHUONG TRINH !!!" << endl;
		while (true) {
			c = _getwch();
			if (c != 27)
				goto menu; //Quay chương trình về điểm "menu:"
			else
				exit(0); //Thoát chương trình
		}
		break;
	}
	default:
		break;
	}
}

int nPhiGiaoDich(int nTien, string sForm)
{
	if (sForm == "RUTTIEN")
	{
		if (nTien <= 500000)
		{
			return 1000;
		}
		else if (nTien <= 1000000)
		{
			return 3000;
		}
		else if (nTien <= 10000000)
		{
			return 10000;
		}
		return 22000;
	}
	else if (sForm == "CHUYENTIEN")
	{
		if (nTien <= 1000000)
		{
			return 10000;
		}
		else if (nTien <= 5000000)
		{
			return 20000;
		}
		else if (nTien <= 10000000)
		{
			return 30000;
		}
		return 40000;
	}
	return 0;
}

void inHoaDon(vector<TAIKHOAN> & TKdangnhap, vector<Print>& pr, int vitri, string sForm, int nTienRut, int nPGD) {
	time_t now = time('\00');
	tm *t = localtime(&now);
	if (sForm == "RUTTIEN")
	{
		SetColor(9);
		cout << "\t\t/-----------------------------------------------------\\\n";
		cout << "\t\t| BIDV - Ngan Hang TMCP Dau Tu Va Phat Trien Viet Nam |\n";
		cout << "\t\t|-----------------------------------------------------|\n";
		cout << "\t\t|\t\t\t\t\t\t      |\n";
		cout << "\t\t|\t\t    RUT TIEN MAT\t\t      |\n";
		cout << "\t\t|Ngay\t\t\tGio\t\t       May ATM|\n";
		cout << "\t\t|" << t->tm_mday << "/" << 1 + t->tm_mon << "/" << 1900 + t->tm_year << "\t\t" << t->tm_hour << ":" << t->tm_min << "\t\t\t" << sMaATM << "|\n";
		cout << "\t\t|\t\t\t\t\t\t      |\n";
		cout << "\t\t|So tai khoan:  " << TKdangnhap[vitri].sSoTaiKhoan << "\t\t\t      |\n";
		cout << "\t\t|So tien rut:   " << nTienRut << " " << " " << " " << TKdangnhap[vitri].sLoaiTien << "\t\t\t      |\n";
		TKdangnhap[vitri].nTien = TKdangnhap[vitri].nTien - 550;
		cout << "\t\t|So du tai khoan: " << TKdangnhap[vitri].nTien << " " << TKdangnhap[vitri].sLoaiTien << "\t\t\t      |\n";
		cout << "\t\t|\t\t\t\t\t\t      |\n";
		cout << "\t\t|Phi: " << nPGD - (nPGD / 11) << " " << TKdangnhap[vitri].sLoaiTien << "\t\t\tVAT: " << nPGD / 11 << " " << TKdangnhap[vitri].sLoaiTien << "\t      |\n";
		cout << "\t\t|Phi in hoa don: 500 " << " " << TKdangnhap[vitri].sLoaiTien << "\t\t\t      |\n";
		cout << "\t\t|VAT in hoa don: 50 " << " " << TKdangnhap[vitri].sLoaiTien << " \t\t\t      |\n";
		cout << "\t\t|-----------------------------------------------------|\n";
		cout << "\t\t| \tDien thoai ho tro 24/24: 09888.2.33.77 \t      |\n";
		cout << "\t\t\\-----------------------------------------------------/\n";
		SetColor(7);
	}
	else if (sForm == "CHUYENTIEN")
	{
		SetColor(9);
		cout << "\t\t/-----------------------------------------------------\\\n";
		cout << "\t\t BIDV - Ngan Hang TMCP Dau Tu Va Phat Trien Viet Nam \n";
		cout << "\t\t-----------------------------------------------------\n";
		cout << "\t\t\t\t\t\t\t\t  \n";
		cout << "\t\t\t\t  CHUYEN TIEN TRONG NUOC\t \n";
		cout << "\t\tNgay\t\t\tGio\t\t       May ATM\n";
		cout << "\t\t" << t->tm_mday << "/" << 1 + t->tm_mon << "/" << 1900 + t->tm_year << "\t\t" << t->tm_hour << ":" << t->tm_min << "\t\t\t" << sMaATM << "\n";
		cout << "\t\t\t\t\t\t\t\t  \n";
		cout << "\t\tSo tai khoan:  " << TKdangnhap[vitri].sSoTaiKhoan << "\t\t\t \n";
		cout << "\t\tSo tien chuyen:   " << nTienRut << " " << " " << TKdangnhap[vitri].sLoaiTien << "\t\t\t \n";
		TKdangnhap[vitri].nTien = TKdangnhap[vitri].nTien - 550;
		cout << "\t\tSo du tai khoan: " << TKdangnhap[vitri].nTien << " " << TKdangnhap[vitri].sLoaiTien << "\t\t \n";
		if (tam != -1) {
			cout << "\t\tChuyen den so tai khoan: " << TKdangnhap[tam].sSoTaiKhoan << "\t      \n";
		}
		cout << "\t\t\t\t\t\t\t\t  \n";
		cout << "\t\tPhi: " << nPGD - (nPGD / 11) << " " << TKdangnhap[vitri].sLoaiTien << "\t\t\tVAT: " << nPGD / 11 << " " << TKdangnhap[vitri].sLoaiTien << "\t \n";
		cout << "\t\tPhi in hoa don: 500 " << " " << TKdangnhap[vitri].sLoaiTien << "\t\t\t  \n";
		cout << "\t\tVAT in hoa don: 50 " << " " << TKdangnhap[vitri].sLoaiTien << " \t\t\t  \n";
		cout << "\t\t-----------------------------------------------------\n";
		cout << "\t\t \tDien thoai ho tro 24/24: 09888.2.33.77 \t      \n";
		cout << "\t\t\\-----------------------------------------------------/\n";
		SetColor(7);
	}
}

void rutTien(vector<TAIKHOAN>& TKdangnhap, vector<Print>&pr, int vitri)
{
	long int nTienRut = 0;
	do
	{
		system("cls");
		SetColor(11);
		cout << "\t\t*********************************\n";
		SetColor(11);
		cout << "\t\t*";
		SetColor(14);
		cout << "\tCHUC NANG RUT TIEN\t";
		SetColor(11);
		cout << "*\n";
		SetColor(11);
		cout << "\t\t*********************************\n";
		SetColor(12);
		cout << "\t\tSO TIEN RUT PHAI > 50000 & < 5000000 & >= SO DU HIEN TAI 50000" << endl;
		SetColor(14);
		cout << "\t\tNhan ESC de thoat!\n\n";
		cout << "\t\tNhan phim bat ki de tiep tuc su dung!\n\n";
		char ESC;
		int kiemtraESC;
		ESC = _getch();
		kiemtraESC = ESC;
		while (kiemtraESC == 27)
		{
			exit(0);
		}
		SetColor(19);
		cout << "\t\tNHAP SO TIEN CAN RUT: ";
		SetColor(22);
		cin >> nTienRut;

	} while (nTienRut < 50000 || nTienRut > TKdangnhap[vitri].nTien - 50000);
	if (nTienRut % 50000 == 0) {
		double dSoDuKhaDung = 0;
		dSoDuKhaDung = TKdangnhap[vitri].nTien - 50000;
		if (nTienRut > dSoDuKhaDung)
		{
			SetColor(4);
			cout << "\t\tSo du trong tai khoan khong du de thuc hien giao dich.\n";
		}
		else
		{
			system("cls");
			SetColor(10);
			cout << "\t\t\t\t RUT TIEN THANH CONG!\n";
			SetColor(10);
			cout << "\t\t\t\t Thong Tin Rut Tien\n\n";
			SetColor(3);
			cout << "\t\t\tMa Tai Khoan: " << TKdangnhap[vitri].sTaiKhoan << endl;
			cout << "\t\t\tTen Khach Hang: " << TKdangnhap[vitri].sHoTen << endl;
			cout << "\t\t\tSo Tai Khoan: " << TKdangnhap[vitri].sSoTaiKhoan << endl;
			cout << "\t\t\tSo Tien Da Giao Dich: " << nTienRut << " " << TKdangnhap[vitri].sLoaiTien << endl;
			cout << "\t\t\tPhi Giao Dich: " << (nPhiGiaoDich(nTienRut, "RUTTIEN") - nPhiGiaoDich(nTienRut, "RUTTIEN") / 11) << " " << TKdangnhap[vitri].sLoaiTien << endl;
			cout << "\t\t\tSo Du Con Lai: " << TKdangnhap[vitri].nTien - nTienRut - (nPhiGiaoDich(nTienRut, "RUTTIEN") - nPhiGiaoDich(nTienRut, "RUTTIEN") / 11) << " " << TKdangnhap[vitri].sLoaiTien << endl << endl;

			TKdangnhap[vitri].nTien = TKdangnhap[vitri].nTien - nTienRut - (nPhiGiaoDich(nTienRut, "RUTTIEN") - nPhiGiaoDich(nTienRut, "RUTTIEN") / 11);
			SetColor(10);
			cout << "\n\t\t\Ban da rut thanh cong: " << nTienRut << " " << TKdangnhap[vitri].sLoaiTien << endl;
			cout << "\t\t\tSo du con lai: " << TKdangnhap[vitri].nTien << " " << TKdangnhap[vitri].sLoaiTien << endl;

			//In hoa don rut tien?
			string kTra = "";
			SetColor(9);
			cout << "\n\t\tNhap \""; SetColor(10); cout << "YES"; SetColor(9); cout << "\" de in hoa don. Nhap \""; SetColor(4); cout << "NO"; SetColor(9); cout << "\" de thoat: "; SetColor(7);
			rewind(stdin);
			getline(cin, kTra);
			if (kTra == "YES" || kTra == "yes" || kTra == "yEs" || kTra == "Yes" || kTra == "yeS" || kTra == "yES" || kTra == "YEs")
			{
				int nPGD = nPhiGiaoDich(nTienRut, "RUTTIEN");
				nPGD += 550;
				inHoaDon(TKdangnhap, pr, vitri, "RUTTIEN", nTienRut, nPhiGiaoDich(nTienRut, "RUTTIEN"));
				//them ham update du lieu va in ra xem lich su
				capNhatDuLieu(TKdangnhap);
				ghiLichSuGiaoDich(TKdangnhap, pr, vitri, "RUTTIEN", nTienRut, nPGD);
			}
			else
			{
				SetColor(10);
				cout << "\t\t\t\tBan da chon khong in hoa don !\n\n";
				SetColor(7);
				capNhatDuLieu(TKdangnhap);
				ghiLichSuGiaoDich(TKdangnhap, pr, vitri, "RUTTIEN", nTienRut, nPhiGiaoDich(nTienRut, "RUTTIEN"));
			}
		}
		SetColor(14);
		cout << "\t\tBAN MUON THUC HIEN GIAO DICH KHAC KHONG?\n" << endl;
		Sleep(500);
	}
}

void chuyenTien(vector<TAIKHOAN>& TKdangnhap, vector<Print>& pr, int vitri)
{
	long int nChuyenTien = 0;
	string sSoTaiKhoan;
	tam = -1;

	time_t baygio = time(0);
	tm *t = localtime(&baygio);
	do
	{
		system("cls");
		SetColor(11);
		cout << "\t\t************************************\n";
		SetColor(11);
		cout << "\t\t*";
		SetColor(14);
		cout << "\tCHUC NANG CHUYEN TIEN\t";
		SetColor(11);
		cout << "   *\n";
		SetColor(11);
		cout << "\t\t************************************\n";
		SetColor(12);
		cout << "\t\tSO TIEN CHUYEN PHAI > 50000 & < 1000000 & >= SO DU HIEN TAI 50000" << endl;
		SetColor(14);
		cout << "\t\tNhan ESC de thoat!\n\n";
		cout << "\t\tNhan phim bat ki de tiep tuc su dung!\n\n";
		char ESC;
		int kiemtraESC;
		ESC = _getch();
		kiemtraESC = ESC;
		while (kiemtraESC == 27)
		{
			exit(0);
		}
		SetColor(19);
		cout << "\t\tNHAP SO TAI KHOAN NGUOI NHAN: ";
		SetColor(22);
		rewind(stdin);
		getline(cin, sSoTaiKhoan);
		SetColor(19);
		if (checkSoTaiKhoan(TKdangnhap, sSoTaiKhoan) != -1) {
			tam = checkSoTaiKhoan(TKdangnhap, sSoTaiKhoan);
			do
			{
				cout << "\t\tNHAP SO TIEN CAN CHUYEN: ";
				SetColor(22);
				cin >> nChuyenTien;
			} while (nChuyenTien < 50000 || nChuyenTien > TKdangnhap[vitri].nTien - 50000);
		}
	} while (checkSoTaiKhoan(TKdangnhap, sSoTaiKhoan) == -1);
	TKdangnhap[tam].nTien += nChuyenTien;
	if (nChuyenTien % 50000 == 0) {
		double dSoDuKhaDung = 0;
		dSoDuKhaDung = TKdangnhap[vitri].nTien - 50000;
		if (nChuyenTien > dSoDuKhaDung) {
			SetColor(4);
			cout << "\t\tSo du trong tai khoan khong du de thuc hien giao dich.\n";
		}
		else {
			system("cls");
			SetColor(10);
			cout << "\t\t\t\t CHUYEN TIEN THANH CONG!\n";
			SetColor(10);
			cout << "\t\t\t\t Thong Tin Chuyen Tien\n\n";
			SetColor(3);
			cout << "\t\t\tMa Tai Khoan: " << TKdangnhap[vitri].sTaiKhoan << endl;
			cout << "\t\t\tTen Khach Hang: " << TKdangnhap[vitri].sHoTen << endl;
			cout << "\t\t\tSo Tai Khoan: " << TKdangnhap[vitri].sSoTaiKhoan << endl;
			cout << "\t\t\tSo Tien Da Giao Dich: " << nChuyenTien << " " << TKdangnhap[vitri].sLoaiTien << endl;
			cout << "\t\t\tPhi Giao Dich: " << (nPhiGiaoDich(nChuyenTien, "CHUYENTIEN") - nPhiGiaoDich(nChuyenTien, "CHUYENTIEN") / 11) << " " << TKdangnhap[vitri].sLoaiTien << endl;
			cout << "\t\t\tSo Du Con Lai: " << TKdangnhap[vitri].nTien - nChuyenTien - (nPhiGiaoDich(nChuyenTien, "CHUYENTIEN") - nPhiGiaoDich(nChuyenTien, "CHUYENTIEN") / 11) << " " << TKdangnhap[vitri].sLoaiTien << endl << endl;
			cout << "\t\t\tSo Tai Khoan Nhan: " << TKdangnhap[tam].sSoTaiKhoan << endl;
			TKdangnhap[vitri].nTien = TKdangnhap[vitri].nTien - nChuyenTien - (nPhiGiaoDich(nChuyenTien, "CHUYENTIEN") - nPhiGiaoDich(nChuyenTien, "CHUYENTIEN") / 11);
			SetColor(10);
			cout << "\n\t\t\tBan da chuyen thanh cong: " << nChuyenTien << " " << TKdangnhap[vitri].sLoaiTien << endl << "\t\t\tCHO SO TAI KHOAN " << sSoTaiKhoan;;
			cout << endl << "\t\t\tSo du con lai: " << TKdangnhap[vitri].nTien << " " << TKdangnhap[vitri].sLoaiTien << endl;

			//In hoa don rut tien?
			string kTra = "";
			SetColor(9);
			cout << "\n\t\tNhap \""; SetColor(10); cout << "YES"; SetColor(9); cout << "\" de in hoa don. Nhap \""; SetColor(4); cout << "NO"; SetColor(9); cout << "\" de thoat: "; SetColor(7);
			rewind(stdin);
			getline(cin, kTra);
			if (kTra == "YES" || kTra == "yes" || kTra == "yEs" || kTra == "Yes" || kTra == "yeS" || kTra == "yES" || kTra == "YEs")
			{
				int nPGD = nPhiGiaoDich(nChuyenTien, "CHUYENTIEN");
				nPGD += 550;
				inHoaDon(TKdangnhap, pr, vitri, "CHUYENTIEN", nChuyenTien, nPhiGiaoDich(nChuyenTien, "CHUYENTIEN"));
				//them ham update du lieu va in ra xem lich su
				capNhatDuLieu(TKdangnhap);

				ofstream fcout;
				fcout.open(TKdangnhap[vitri].sSoTaiKhoan + ".dat", ios::app);
				fcout << "\n"
					<< "CHUYEN\n TIEN:   " << kiemTraTime(TKdangnhap, vitri, "hh") << t->tm_hour << ":"
					<< kiemTraTime(TKdangnhap, vitri, "m") << t->tm_min << ":" << kiemTraTime(TKdangnhap, vitri, "ss") << t->tm_sec << "   "
					<< kiemTraTime(TKdangnhap, vitri, "dd") << t->tm_mday << "/" << kiemTraTime(TKdangnhap, vitri, "mm") << 1 + t->tm_mon << "/"
					<< 1900 + t->tm_year << "\t" << nChuyenTien << TKdangnhap[vitri].sLoaiTien << kiemTraTime(TKdangnhap, vitri, "100") << "   "
					<< TKdangnhap[vitri].nTien << TKdangnhap[vitri].sLoaiTien << "\t" << nPhiGiaoDich(nChuyenTien, "CHUYENTIEN") << "\tsend\t"
					<< TKdangnhap[tam].sSoTaiKhoan << "  " << TKdangnhap[tam].sHoTen << "  " << sMaATM << endl;
				fcout.close();

				fcout.open(TKdangnhap[tam].sSoTaiKhoan + ".dat", ios::app);
				fcout << "\n"
					<< "NHAN\nTIEN:   " << kiemTraTime(TKdangnhap, vitri, "hh") << t->tm_hour << ":"
					<< kiemTraTime(TKdangnhap, vitri, "m") << t->tm_min << ":" << kiemTraTime(TKdangnhap, vitri, "ss") << t->tm_sec << "   "
					<< kiemTraTime(TKdangnhap, vitri, "dd") << t->tm_mday << "/" << kiemTraTime(TKdangnhap, vitri, "mm") << 1 + t->tm_mon << "/"
					<< 1900 + t->tm_year << "\t" << nChuyenTien << TKdangnhap[vitri].sLoaiTien << kiemTraTime(TKdangnhap, vitri, "100") << "   "
					<< TKdangnhap[tam].nTien << TKdangnhap[vitri].sLoaiTien << "\t" << nPhiGiaoDich(nChuyenTien, "CHUYENTIEN") << "\tplus\t"
					<< TKdangnhap[vitri].sSoTaiKhoan << "  " << TKdangnhap[vitri].sHoTen << "   " << sMaATM << endl;
				fcout.close();
			}
			else
			{
				SetColor(10);
				cout << "\t\t\t\tBan da chon khong in hoa don !\n\n";
				SetColor(7);
				capNhatDuLieu(TKdangnhap);

				ofstream fcout;
				fcout.open(TKdangnhap[vitri].sSoTaiKhoan + ".dat", ios::app);
				fcout << "\n"
					<< "CHUYEN\n TIEN:   " << kiemTraTime(TKdangnhap, vitri, "hh") << t->tm_hour << ":"
					<< kiemTraTime(TKdangnhap, vitri, "m") << t->tm_min << ":" << kiemTraTime(TKdangnhap, vitri, "ss") << t->tm_sec << "   "
					<< kiemTraTime(TKdangnhap, vitri, "dd") << t->tm_mday << "/" << kiemTraTime(TKdangnhap, vitri, "mm") << 1 + t->tm_mon << "/"
					<< 1900 + t->tm_year << "\t" << nChuyenTien << TKdangnhap[vitri].sLoaiTien << kiemTraTime(TKdangnhap, vitri, "100") << "   "
					<< TKdangnhap[vitri].nTien << TKdangnhap[vitri].sLoaiTien << "\t" << nPhiGiaoDich(nChuyenTien, "CHUYENTIEN") << "\tsend\t"
					<< TKdangnhap[tam].sSoTaiKhoan << "  " << TKdangnhap[tam].sHoTen << "  " << sMaATM << endl;
				fcout.close();

				fcout.open(TKdangnhap[tam].sSoTaiKhoan + ".dat", ios::app);
				fcout << "\n"
					<< "NHAN\nTIEN:   " << kiemTraTime(TKdangnhap, vitri, "hh") << t->tm_hour << ":"
					<< kiemTraTime(TKdangnhap, vitri, "m") << t->tm_min << ":" << kiemTraTime(TKdangnhap, vitri, "ss") << t->tm_sec << "   "
					<< kiemTraTime(TKdangnhap, vitri, "dd") << t->tm_mday << "/" << kiemTraTime(TKdangnhap, vitri, "mm") << 1 + t->tm_mon << "/"
					<< 1900 + t->tm_year << "\t" << nChuyenTien << TKdangnhap[vitri].sLoaiTien << kiemTraTime(TKdangnhap, vitri, "100") << "   "
					<< TKdangnhap[tam].nTien << TKdangnhap[vitri].sLoaiTien << "\t" << nPhiGiaoDich(nChuyenTien, "CHUYENTIEN") << "\tplus\t"
					<< TKdangnhap[vitri].sSoTaiKhoan << "  " << TKdangnhap[vitri].sHoTen << "   " << sMaATM << endl;
				fcout.close();
			}
		}
	}
	SetColor(14);
	cout << "\t\tBAN MUON THUC HIEN GIAO DICH KHAC KHONG?\n" << endl;
	Sleep(500);
}

void doiMatKhau(vector<TAIKHOAN>& TKdangnhap, int vitri)
{
	int nDem = 0;
	char ESC;
	int kiemtraESC;
	system("cls");
	SetColor(3);
	cout << "\t\t\t\t***************************" << endl;
	cout << "\t\t\t\t*  ";
	SetColor(13);
	cout << "\tDOI MAT KHAU\t"; SetColor(3);
	cout << "  *" << endl;
	cout << "\t\t\t\t***************************" << endl;
	SetColor(7);
	string matKhauHienTai = "";
doiMK:
	SetColor(10);
	cout << "\t\t\tNhap mat khau hien tai: ";
	SetColor(7);
	matKhauHienTai = maHoaMK(6);
	nDem++;
	if (matKhauHienTai == TKdangnhap[vitri].sMatKhau) //kiem tra mat khau vua nhap co trung mat khau trong he thong...
	{
		string matKhauMoi = "";
		string nhapLaiMK = "";
		SetColor(4);
		cout << "\n\t\t\tLuu y: Mat khau gom 6 chu so\n";
		SetColor(7);
		SetColor(013);
		cout << "\t\t\tNhap mat khau moi: ";
		SetColor(7);
		matKhauMoi = maHoaMK(6);
		SetColor(013);
		cout << "\t\t\tNhap lai de xac nhan mat khau moi: ";
		SetColor(7);
		nhapLaiMK = maHoaMK(6);
		if (matKhauMoi == nhapLaiMK)
		{
			if (matKhauMoi.length() == 6)
			{
				TKdangnhap[vitri].sMatKhau = matKhauMoi;
				capNhatDuLieu(TKdangnhap);
				SetColor(11);
				cout << "\t\t\t---------------------------\n";
				SetColor(6);
				cout << "\t\t\tThay doi mat khau thanh cong !!!\n";
				cout << "\t\t\tBan se dung mat khau moi cho lan dang nhap tiep theo!!\n";
			}
			else
			{
				system("cls");
				SetColor(3);
				cout << "\t\t\t\t***************************" << endl;
				cout << "\t\t\t\t*  ";
				SetColor(13);
				cout << "\tDOI MAT KHAU\t"; SetColor(3);
				cout << "  *" << endl;
				cout << "\t\t\t\t***************************" << endl;
				SetColor(7);
				SetColor(4);
				cout << "\t\t\tLuu y: mat khau moi bao gom 6 chu so. Vui long nhap lai\n";
				SetColor(7);
				goto doiMK;
			}
		}
		else if (matKhauMoi == "ESC" || matKhauMoi == "esc" || nhapLaiMK == "ESC" || nhapLaiMK == "esc")
		{
			SetColor(10);
			cout << "\tBAN DA CHON THOAT KHOI HE THONG !!!\n";
			Sleep(1000);
			system("cls");
			exit(0);
			SetColor(7);
		}
		else
		{
			system("cls");
			SetColor(3);
			cout << "\t\t\t\t***************************" << endl;
			cout << "\t\t\t\t*  ";
			SetColor(13);
			cout << "\tDOI MAT KHAU\t"; SetColor(3);
			cout << "  *" << endl;
			cout << "\t\t\t\t***************************" << endl;
			SetColor(7);
			SetColor(4);
			cout << "\t\tMat khau khong trung khop, vui long nhap lai: \n";
			SetColor(7);
		}
	}
	else if (nDem == 3)
	{
		system("cls");
		SetColor(3);
		cout << "\t\t\t\t***************************" << endl;
		cout << "\t\t\t\t*  ";
		SetColor(13);
		cout << "\tDOI MAT KHAU\t"; SetColor(3);
		cout << "  *" << endl;
		cout << "\t\t\t\t***************************" << endl;
		SetColor(7);
		SetColor(4);
		cout << "\t\tBan nhap sai qua 3 lan, tai khoan nay da bi khoa !!! \a\n\n";
		SetColor(7);
		Sleep(7000);
		DangNhap(TKdangnhap, vitri);
	}
	else
	{
		system("cls");
		SetColor(3);
		cout << "\t\t\t\t***************************" << endl;
		cout << "\t\t\t\t*  ";
		SetColor(13);
		cout << "\tDOI MAT KHAU\t"; SetColor(3);
		cout << "  *" << endl;
		cout << "\t\t\t\t***************************" << endl;
		SetColor(7);
		SetColor(4);
		cout << "\t\tMat khau nhap vao sai. Vui long nhap lai.\n";
		cout << "\t\tNhap ESC de thoat khoi chuong trinh !\n";
		ESC = _getch();
		kiemtraESC = ESC;
		while (kiemtraESC == 27)
		{
			exit(0);
		}
		goto doiMK;
	}
}

string kiemTraTime(vector<TAIKHOAN>& TKdangnhap, int vitri, string sX)
{
	// làm dữ liệu lịch sử giao dịch 
	time_t now = time('\0');
	tm *t = localtime(&now);
	if (sX == "ss")
	{
		if (t->tm_sec < 10)
		{
			return "0";
		}
	}
	if (sX == "m")
	{
		if ((t->tm_min) < 10)
		{
			return "0";
		}
	}
	if (sX == "hh")
	{
		if (t->tm_hour < 10)
		{
			return "0";
		}
	}
	if (sX == "dd")
	{
		if (t->tm_mday < 10)
		{
			return "0";
		}
	}
	if (sX == "mm")
	{
		if (t->tm_mon + 1 < 10)
		{
			return "0";
		}
	}
	if (sX == "100")
	{
		if (TKdangnhap[vitri].nTien < 100000)
		{
			return " ";
		}
	}
	return "";
}

void ghiLichSuGiaoDich(vector<TAIKHOAN> & TKdangnhap, vector<Print>& pr, int vitri, string sForm, int nTienRut, int nPGD) {
	time_t baygio = time(0);
	tm *t = localtime(&baygio);
	ofstream fcout;
	fcout.open(TKdangnhap[vitri].sSoTaiKhoan + ".dat", ios::app);
	if (sForm == "RUTTIEN")
	{
		fcout << "\n"
			<< "RUTTIEN: " << kiemTraTime(TKdangnhap, vitri, "hh") << t->tm_hour << ":" << kiemTraTime(TKdangnhap, vitri, "m")
			<< t->tm_min << ":" << kiemTraTime(TKdangnhap, vitri, "ss") << t->tm_sec << "   " << kiemTraTime(TKdangnhap, vitri, "dd")
			<< t->tm_mday << "/" << kiemTraTime(TKdangnhap, vitri, "mm") << 1 + t->tm_mon << "/" << 1900 + t->tm_year << "\t"
			<< nTienRut << TKdangnhap[vitri].sLoaiTien << kiemTraTime(TKdangnhap, vitri, "100") << "   " << TKdangnhap[vitri].nTien << TKdangnhap[vitri].sLoaiTien
			<< "\t" << nPGD << "\twith" << "\t Not Applicable\t" << "\tN/A\t  " << sMaATM << endl;
	}
	fcout.close();
}

void docLichSuGiaoDich(vector<TAIKHOAN> & TKdangnhap, int vitri)
{
	string sDong = "";
	ifstream fcin;
	fcin.open(TKdangnhap[vitri].sSoTaiKhoan + ".dat", ios::app);
	cout << "__________________________________________________LICH SU GIAO DICH____________________________________________________\n\n";
	cout << "Loai GD\t Thoi gian\tNgay\t  Tien GD\tSo Du\tPhi GD\tType\tSo Tai Khoan\t   FullName\t   Ma ATM\n";
	while (!fcin.eof())
	{
		getline(fcin, sDong, '\n');
		cout << sDong << endl;
		Sleep(30);
	}
	fcin.close();
	cout << "_______________________________________________________________________________________________________________________\n";
}