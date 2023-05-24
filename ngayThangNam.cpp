#include "stdio.h"
#include "windows.h"

int ngay , thang, nam;

int ngayTrongThang(int thang, int nam)
{
    switch(thang)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;

        case 4:
        case 6:
        case 9:
        case 11:
            return 30;

        case 2:
            return ((nam % 400 == 0 || nam % 4 == 0 && nam % 100 != 0)? 29:28);
    }
}

void xuatNgayTrongThang ( int thang, int nam)
{
    printf("Ngày trong tháng %d: %d ", thang, ngayTrongThang(thang, nam));
}

int dieuKienNhap (int ngay, int thang, int nam)
{
    if (thang < 1 || thang > 12)
        return 0;
    
    if (nam < 1)
        return 0;

    int soNgay = ngayTrongThang(thang, nam);
    
    if (ngay < 1 || ngay > soNgay)
        return 0;
    
    return 1;
}

void nhapNgayThangNam(int &ngay, int &thang, int &nam)
{
    do
    {
        printf("Nhập lần lượt ngày-tháng-năm: ");
        scanf("%d%d%d", &ngay, &thang, &nam);
    } while (!dieuKienNhap(ngay, thang, nam));
}

int ngayThuXTrongNam (int ngay, int thang, int nam)
{
    int tongNgay = 0;

    for (int i = 1; i < thang; i++)
    {
        tongNgay += ngayTrongThang(i, nam);
    }

    tongNgay += ngay;

    return tongNgay;
}

void xuatTongNgay (int ngay, int thang, int nam)
{
    printf("\nNgày thứ %d trong năm %d", ngayThuXTrongNam(ngay, thang, nam), nam);
}

void inNgaySauDo (int ngay, int thang, int nam)
{
    int soNgay = ngayTrongThang(thang, nam);
    if (ngay == soNgay)
    {
        if (thang == 12)
        {
            ngay = 1;
            thang = 1;
            nam++;
        }
        else
        {
            ngay = 1;
            thang++;
        }
    }
    else
    {
        ngay++;
    }

    printf("Ngày sau đó: %d/%d/%d", ngay, thang, nam);
}

void inNgayTruocDo(int ngay, int thang, int nam)
{
    if (ngay == 1)
    {
        if (thang == 1)
        {
            ngay = 31;
            thang = 12;
            nam--;
        }
        else
        {
            thang--;
            ngay = ngayTrongThang(thang, nam);
        }
    }
    else
    {
        ngay--;
    }

    printf ("Ngày trước đó: %d/%d/%d", ngay, thang, nam);
}

void xuatNgayThangNam (int ngay, int thang, int nam)
{
    printf("Ngày tháng năm vừa nhập: %d/%d/%d", ngay, thang, nam);
}

void xuongDong()
{
    printf("\n");
}

void menu()
{
    printf("1.Nhập ngày, tháng, năm");
    printf("\n2.Xuất ngày, tháng, năm");
    printf("\n3.Xuất ngày thứ mấy trong năm");
    printf("\n4.In ngày sau đó");
    printf("\n5.In ngày trước đó");
    printf("\n6. Xuất ngày trong tháng");
    printf("\nLựa chọn của bạn: ");
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int thoat;
    int chon;
    int luaChon;
    running:
        do
        {   
            nhap:
                printf("Nhập 0 để thoát, 1 để tiếp tục: ");
                scanf("%d", &thoat);
                if (thoat == 1)
                {
                    MENU:
                        menu();
                        scanf("%d", &chon);
                        if (chon == 1)
                        {
                            nhapNgayThangNam(ngay, thang, nam);
                        }
                        else if (chon == 2)
                        {
                            xuatNgayThangNam(ngay, thang, nam);
                            xuongDong();
                        }
                        else if (chon == 3)
                        {
                            xuatTongNgay(ngay, thang, nam);
                            xuongDong();
                        }
                        else if (chon == 4)
                        {
                            inNgaySauDo(ngay, thang, nam);
                            xuongDong();
                        }
                        else if (chon == 5)
                        {
                            inNgayTruocDo(ngay, thang, nam);
                            xuongDong();
                        }   
                        else if (chon == 6)
                        {
                            xuatNgayTrongThang(thang, nam);
                            xuongDong();
                        }
                        else
                        {
                            printf("Lựa chọn của bạn không tồn tại");
                            printf("\nVui lòng chọn lại\n");
                        }

                        tiepTucHayQuayLai:
                            printf("Nhập 0 để quay lại, 1 để ở lại và tiếp tục: ");
                            scanf("%d", &luaChon);

                            if (luaChon == 0)
                            {
                                goto nhap;
                            }
                            else if (luaChon == 1)
                            {
                                goto MENU;
                            }
                            else
                            {
                                printf("Lựa chọn của bạn không hợp lệ");
                                xuongDong();
                                goto tiepTucHayQuayLai;
                            }
                }
                else if(thoat != 0)
                {
                    goto running;
                }    
                else
                {
                    printf("Bạn đã thoát chương trình");
                }
        }
        while (thoat == 1);
}