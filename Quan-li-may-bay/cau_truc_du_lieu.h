#ifndef cau_truc_du_lieu
#define cau_truc_du_lieu

#include<windows.h>
#include<mylib.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include "my_time.h"

const int MAXSIZE=300;


//cau truc danh sach may bay: MANG CON TRO.
struct may_bay{
	char so_hieu_may_bay[16];//15
	char loai_may_bay[41];//40
	int socho;// so cho>=20.
	
	
	//CHI SO PHU: so luot thuc hien
	int so_luot_thuc_hien=0;
	
	//CHI SO PHU: active
	bool active=true;
	
};
struct ds_may_bay{
	may_bay *data[MAXSIZE];// khi khoi tao la MAXSIZE[]
	int n=0;        //nen de n=0 ban dau luon.
};



// ve: dung mang con tro
struct ve{
	char cmnd[10]="x";
	int stt;// stt-so thu tu: so ve.
};
struct ds_ve{
	ve **so_ghe;//khoi tao bang so_cho cua may bay.
	int n;//so ve da duoc dat.
	int limit;// so phan tu toi da!
};


void initialize_ve(ds_ve &DS_VE, int quantity,int booked){
	DS_VE.so_ghe=new ve*[quantity];
	for(int i=0;i<quantity;i++){
		DS_VE.so_ghe[i] = new ve[1];
	}
	DS_VE.limit = quantity;
	DS_VE.n = booked;
}


//cau truc chuyen bay : DANH SACH LIEN KET DON!


struct chuyen_bay{
	char macb[16]="x";
	date_time depart_time;
	char san_bay_den[21];
	int trang_thai; // 0:huy chuyen 1:con ve 2:het ve 3:hoan tat.
	char so_hieu_may_bay[16];
	
	//moi ve bao gom: cmnd va stt
	ds_ve danh_sach_ve;
	
};
struct node_cb{	
	chuyen_bay data;
	node_cb*pnext=NULL;
};
typedef node_cb*PTR_chuyenbay;




//Hanh khach: CAY NHI PHAN TIM KIEM CAN BANG.
 struct hanh_khach{
 	char cmnd[10];
 	char ho[31];
 	char ten[11];
 	bool phai;
};
 
 struct node_hk{
 	hanh_khach data;	
 	int bf=0;//chi so can bang cua nut hien tai.
 	node_hk *right=NULL;
 	node_hk *left=NULL;
 };
typedef node_hk*NODE_hanhkhach;

#endif
