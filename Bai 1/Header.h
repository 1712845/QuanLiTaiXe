#pragma once
#ifndef __HEAD__H__
#define __HEAD__H__
#include<iostream>
#include<string>
#include<iomanip>
#include<sstream>
#pragma warning(disable:4996)
using namespace std;
class ConNguoi
{
private:
	string HoTen;
	int NamSinh;
	string QueQuan;
	string SoDienThoai;
public:
	void Nhap();
	void Xuat();
};
class Xe
{
public:
	string LoaiXe;
	string BienSoXe;
	bool TrangThai;
public:
	void NhapThongTin();
	void XuatThongTin();
	Xe GetXe();
	
};
class TaiXe : public ConNguoi
{
public:
	int SoloaiXeCoTheLai;
	string MaTaiXe;
	string LoaiXeCoTheLai[3];
	bool TrangThai;
public:
	void NhapThongTin();
	void XuatThongTin();
	TaiXe GetTaiXe();
	
};
struct NODE
{
	Xe DaTaXe;
	TaiXe DaTaTaiXe;
	NODE* pNext;
};
struct LIST
{
	NODE* pHead;
	NODE* pTail;
};
NODE* GetNodeTaiXe(TaiXe X);
NODE* GetNodeXe(Xe X);
void KhoiTao(LIST &l);
void ThemCuoi(LIST &l,NODE* p);
void HuyDanhSach(LIST &l);
void ChuanHoaChuoiString(string &str);
void XuatDanhSachTaiXe(LIST l);
void XuatDanhSachXe(LIST l);
ostream& operator <<(ostream& outdev, TaiXe& A);
ostream& operator <<(ostream& outdev, Xe& X);
void TraCuuThongTinTaiXe(LIST l, string MaTaiXe);
void TraCuuThongTinXe(LIST l, string BienSoXe);
void DeXuatTaiXe(LIST l, int luachon);
void DeXuatXe(LIST l, int luachon);
void LuaChon();
#endif 