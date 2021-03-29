#include <iostream>
using namespace std;

//VanCu
struct DiemSV
{
	char maSinhVien[200];
	char tenSinhVien[200];
	char monhocID[10];
	float ChuyenCan;
	float GiuaKy;
	float CuoiKy;
	float TBM;
};

struct NodeDiem
{
	DiemSV Diem;
	struct NodeDiem *Left;
	struct NodeDiem *Right;
};

typedef struct NodeDiem *PtrDiem;

