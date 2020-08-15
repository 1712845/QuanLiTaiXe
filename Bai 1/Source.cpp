#include"Header.h"
void ConNguoi::Nhap()
{
	cout << "Nhap ho va ten: ";
	getline(cin, this->HoTen);
	ChuanHoaChuoiString(this->HoTen);
	cout << "Nhap nam sinh: ";
	cin >> this->NamSinh; cin.ignore(1);
	cout << "Nhap que quan: ";
	getline(cin, this->QueQuan);
	ChuanHoaChuoiString(this->QueQuan);
	cout << "Nhap so dien thoai: ";
	getline(cin, this->SoDienThoai);
}
void ConNguoi::Xuat()
{
	cout << "Ho va ten: " << this->HoTen << endl;
	cout << "Nam sinh: " << this->NamSinh << endl;
	cout << "Que quan: " << this->QueQuan << endl;
	cout << "So dien thoai: " << this->SoDienThoai << endl;
}
void Xe::NhapThongTin()
{
	cout << "Nhap loai xe (Bon Cho , Ban Tai, Chin Cho): ";
	getline(cin, this->LoaiXe);
	ChuanHoaChuoiString(this->LoaiXe);
	cout << "Nhap bien so xe:";
	getline(cin, this->BienSoXe);
	cout << "Nhap tinh trang xe (Ban = 0, Ranh = 1): ";
	cin >> this->TrangThai; cin.ignore(1);
}
void Xe::XuatThongTin()
{
	cout << "Loai xe: "<< this->LoaiXe<<endl;
	cout << "Bien so xe: "<< this->BienSoXe<<endl;
	cout << "Tinh trang xe (Ban = 0, Ranh = 1): " << this->TrangThai<<endl;
}
void TaiXe::NhapThongTin()
{
	this->Nhap();
	cout << "Nhap so loai xe co the lai: ";
	do
	{
		cin >> this->SoloaiXeCoTheLai; cin.ignore(1);
		if (this->SoloaiXeCoTheLai <= 0 || this->SoloaiXeCoTheLai > 3) { cout << "0 < Loai xe < 4 vui long nhap lai!\n"; }
	} while (this->SoloaiXeCoTheLai <= 0 || this->SoloaiXeCoTheLai > 3);
	for (int i = 0; i < this->SoloaiXeCoTheLai; i++)
	{
		cout << "Nhap loai xe(Bon Cho,Chin Cho,Ban Tai): ";
		getline(cin, this->LoaiXeCoTheLai[i]);
		ChuanHoaChuoiString(this->LoaiXeCoTheLai[i]);
	}
	cout << "Nhap ma tai xe: ";
	getline(cin, this->MaTaiXe);
	cout << "Nhap trang thai cua tai xe (Ban = 0 , Ranh = 1): ";
	cin >> this->TrangThai; cin.ignore(1);
}
void TaiXe::XuatThongTin()
{
	this->Xuat();
	cout << "So loai xe co the lai: " << this->SoloaiXeCoTheLai << endl;
	cout << "Cac xe co the lai la: ";
	for (int i = 0; i < this->SoloaiXeCoTheLai; i++)
	{
		cout << setw(16) << this->LoaiXeCoTheLai[i];
	}
	cout << "\nMa tai xe: " << this->MaTaiXe << endl;
}
TaiXe TaiXe :: GetTaiXe()
{
	return *this;
}
Xe Xe::GetXe()
{
	return *this;
}
NODE* GetNodeTaiXe(TaiXe X)
{
	NODE*p = new NODE;
	if (p == NULL)
	{
		cout << "Khong du bo nho\n";
	}
	else
	{
		p->DaTaTaiXe = X;
		p->pNext = NULL;
	}
	return p;
}
NODE* GetNodeXe(Xe X)
{
	NODE*p = new NODE;
	if (p == NULL)
	{
		cout << "Khong du bo nho\n";
	}
	else
	{
		p->DaTaXe = X;
		p->pNext = NULL;
	}
	return p;
}
void KhoiTao(LIST& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
void ThemCuoi(LIST& l,NODE* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void XuatDanhSachTaiXe(LIST l)
{
	for (NODE* i = l.pHead; i!= NULL; i=i->pNext)
	{
		cout << i->DaTaTaiXe<<endl;
	}
}
void XuatDanhSachXe(LIST l)
{
	for (NODE* i = l.pHead; i!= NULL; i = i->pNext)
	{
		cout << i->DaTaXe << endl;
	}
}
void HuyDanhSach(LIST &l)
{
	NODE*p;
	while (l.pHead != NULL)
	{
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
	l.pTail = NULL;
}
void ChuanHoaChuoiString(string &str)
{
	while (str[0] == ' ')
	{
		str.erase(str.begin() + 0); // xóa kí tự tại vị trí 0
	}

	// Bước 2: Xóa hết tất cả các kí tự khoảng trắng thừa ở cuối chuỗi
	while (str[str.length() - 1] == ' ')
	{
		str.erase(str.begin() + str.length() - 1); // xóa kí tự tại vị trí cuối của chuỗi
	}
	strlwr((char *)str.c_str()); // hàm chuyển chuỗi str về chuỗi in thường
	// Bước 2: viết hoa kí tự đầu của mỗi từ
	if (str[0] != ' ')
	{
		if (str[0] >= 97 && str[0] <= 122)
		{
			str[0] -= 32;
		}

	}
	// Xoa khoang trang giua cac tu
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			str.erase(str.begin() + i);
			i--;
		}
	}
	// kí tự tại vị trí i là khoảng trắng, i + i khác khoảng trắng thì kí tự tại vị trí i + 1 chính là kí tự đầu tiên của mỗi từ
	for (int i = 0; i < str.length() - 1; i++)
	{
		if (str[i] == ' ' && str[i + 1] != ' ')
		{
			if (str[i + 1] >= 97 && str[i + 1] <= 122)
			{
				// - 32 là chuyển kí tự in thường về in hoa
				str[i + 1] -= 32; // <=> str[i + 1] = str[i + 1] - 32;
			}
		}
	}
}
ostream& operator <<(ostream& outdev, TaiXe& A)
{
	A.XuatThongTin();
	return outdev;
}
ostream& operator <<(ostream& outdev, Xe& X)
{
	X.XuatThongTin();
	return outdev;
}
void TraCuuThongTinTaiXe(LIST l,string MaTaiXe)
{
	for (NODE* i = l.pHead; i; i = i->pNext)
	{
		if (i->DaTaTaiXe.MaTaiXe == MaTaiXe)
		{
			system("cls");
			i->DaTaTaiXe.XuatThongTin();
		}
	}
}
void TraCuuThongTinXe(LIST l, string BienSoXe)
{
	for (NODE* i = l.pHead; i; i = i->pNext)
	{
		if (i->DaTaXe.BienSoXe == BienSoXe)
		{
			system("cls");
			i->DaTaXe.XuatThongTin();
		}
	}
}
void DeXuatTaiXe(LIST l,int luachon)
{
	int f = 0;
	NODE* i = l.pHead;
	switch (luachon)
	{
	case 1:
		for (; i!= NULL; i = i->pNext)
		{
			if (i->DaTaTaiXe.TrangThai == 1)
			{
				for (int j = 0; j < i->DaTaTaiXe.SoloaiXeCoTheLai;j++)
				{
					if (i->DaTaTaiXe.LoaiXeCoTheLai[j] == "Bon Cho" || i->DaTaTaiXe.LoaiXeCoTheLai[j] == "4 Cho" || i->DaTaTaiXe.LoaiXeCoTheLai[j] == "Chin Cho" || i->DaTaTaiXe.LoaiXeCoTheLai[j] == "9 Cho")
					{
						i->DaTaTaiXe.XuatThongTin();
						f++;
						break;
					}
				}
			}
			if (f == 1) { break; }
		}
		if (f == 0) {cout << "Khong co tai xe\n"; }
		break;
	case 2:
		for (; i != NULL; i = i->pNext)
		{
			if (i->DaTaTaiXe.TrangThai == 1)
			{
				for (int j = 0; j < i->DaTaTaiXe.SoloaiXeCoTheLai; j++)
				{
					if (i->DaTaTaiXe.LoaiXeCoTheLai[j] == "Ban Tai")
					{
						i->DaTaTaiXe.XuatThongTin();
						f++;
						break;
					}
				}
			}
			if (f == 1) { break; }
		}
		if (f == 0) { cout << "Khong co tai xe\n"; }
		break;
	}
}
void DeXuatXe(LIST l, int luachon)
{
	int f = 0;
	stringstream ss[100];
	string temp_1[100];
	string temp_2[100];
	string temp_3[100];
	for (int i = 0; i < 99; i++)
	{
		temp_1[i] = "Bon Cho";
		temp_2[i] = "Chin Cho";
		temp_3[i] ="Ban Tai";
	}
	switch (luachon)
	{
	case 1:
		for (NODE* i = l.pHead; i; i = i->pNext)
		{
			for (int j = 0; j < 99; j++)
			{
				if (j == 0)
				{
					if (i->DaTaXe.TrangThai == 1)
					{
						if (i->DaTaXe.LoaiXe == temp_1[0] || i->DaTaXe.LoaiXe == temp_2[0])
						{
							i->DaTaXe.XuatThongTin();
							f++;
							break;
						}

					}
				}
				else
				{
					if (i->DaTaXe.TrangThai == 1)
					{
						ss[j] << j;
						temp_1[j] = temp_1[j] + " " + ss[j].str();
						temp_2[j] = temp_2[j] + " " + ss[j].str();
						if (i->DaTaXe.LoaiXe == temp_1[j] || i->DaTaXe.LoaiXe == temp_2[j])
						{
							i->DaTaXe.XuatThongTin();
							f++;
							break;
						}
					}
				}
			}
			if (f == 1) { break; }
		}
		if (f == 0) { cout << "Khong co xe\n"; }
		break;
	case 2:
		for (NODE* i = l.pHead; i; i = i->pNext)
		{
			for (int j = 0; j < 99; j++)
			{
				if (j == 0)
				{
					if (i->DaTaXe.TrangThai == 1)
					{
						if (i->DaTaXe.LoaiXe == temp_3[0])
						{
							i->DaTaXe.XuatThongTin();
							f++;
							break;
						}
					}
				}
				else
				{
					if (i->DaTaXe.TrangThai == 1)
					{
						ss[j] << j;
						temp_3[j] = temp_3[j] + " " + ss[j].str();
						if (i->DaTaXe.LoaiXe == temp_3[j])
						{
							i->DaTaXe.XuatThongTin();
							f++;
							break;
						}
					}
				}
			}

			if (f == 1) { break; }
		}
		if (f == 0) { cout << "Khong co xe\n"; }
		break;
	case 3:
		for (NODE* i = l.pHead; i; i = i->pNext)
		{
			for (int j = 0; j < 99; j++)
			{
				if (j == 0)
				{
					if (i->DaTaXe.TrangThai == 1)
					{
						if (i->DaTaXe.LoaiXe == temp_3[0])
						{
							i->DaTaXe.XuatThongTin();
							f++;
							break;
						}
					}
				}
				else
				{
					if (i->DaTaXe.TrangThai == 1)
					{
						ss[j] << j;
						temp_3[j] = temp_3[j] + " " + ss[j].str();
						if (i->DaTaXe.LoaiXe == temp_3[j])
						{
							i->DaTaXe.XuatThongTin();
							f++;
							break;
						}
					}
				}
			}

			if (f == 1) { break; }
		}
		if (f == 0) { cout << "Khong co xe\n"; }
		break;
	}
}
void LuaChon()
{
	int luachon;
	int temp;
	int SoLuongTaiXeCuaCongTy;
	int SoLuongXeCuaTongTy;
	TaiXe A;
	Xe X;
	NODE*p;
	LIST TaiXe, Xe;
	KhoiTao(TaiXe);
	KhoiTao(Xe);
	string MaTaiXe, BienSoXe;
	cout << "Nhap so luong tai xe cua cong ty: ";
	cin >> SoLuongTaiXeCuaCongTy; cin.ignore(1);
	for (int i = 0; i < SoLuongTaiXeCuaCongTy; i++)
	{
		system("cls");
		A.NhapThongTin();
		p = GetNodeTaiXe(A.GetTaiXe());
		ThemCuoi(TaiXe, p);
	}
	system("cls");
	cout << "Nhap so luong xe cua cong ty: ";
	cin >> SoLuongXeCuaTongTy; cin.ignore(1);
	for (int i = 0; i < SoLuongXeCuaTongTy; i++)
	{
		system("cls");
		X.NhapThongTin();
		p = GetNodeXe(X.GetXe());
		ThemCuoi(Xe, p);
	}
	system("cls");
	cout << "0.An phim ESC de thoat khoi chuong trinh\n";
	cout <<"1.Tra cuu thong tin tai xe thong qua ma tai xe da nhap\n";
	cout << "2.Tra cuu thong tin cua xe thong qua bien so xe da nhap\n";
	cout << "3.De xuat ra tai xe va xe dua tren nhu cau cua khach hang\n";
	cout << "4.Xuat ra danh sach tai xe va xe vua nhap:\n";
	cout << "Nhap lua chon cua ban:";
	cin >> luachon; cin.ignore();
	switch (luachon)
	{
	case 1:
		cout << "Nhap ma tai xe: ";
		getline(cin, MaTaiXe);
		TraCuuThongTinTaiXe(TaiXe, MaTaiXe);
		break;
	case 2:
		cout << "Nhap ma bien so xe: ";
		getline(cin, BienSoXe);
		TraCuuThongTinXe(Xe, BienSoXe);
		break;
	case 3:
		system("cls");
		cout << "0.An 1 phim bat ki de thoat: " << endl;
		cout << "1.Cho khach" << endl;
		cout << "2.Cho hang hoac cho hang va khach: " << endl<<endl;
		cout << "Lua chon cua ban la: ";
		cin >> temp; cin.ignore(1);
		switch (temp)
		{
		case 1:
			system("cls");
			cout << "---TAI---XE---PHU---HOP---" << endl;
			DeXuatTaiXe(TaiXe,1);
			cout << "\n---XE---PHU---HOP---" << endl;
			DeXuatXe(Xe, 1);
			break;
		case 2:
			system("cls");
			cout << "\n---TAI---XE---PHU---HOP---" << endl;
			DeXuatTaiXe(TaiXe,2);
			cout << "\n---XE---PHU---HOP---" << endl;
			DeXuatXe(Xe, 2);
			break;
		default:
			cout << "Da thoat chuong trinh" << endl;
			system("pause");
			exit(0);
			break;
		}
		break;
	case 4:
		system("cls");
		XuatDanhSachTaiXe(TaiXe);
		XuatDanhSachXe(Xe);
		break;
	default:
		cout << "Da thoat chuong trinh" << endl;
		system("pause");
		exit(0);
		break;
	}
}