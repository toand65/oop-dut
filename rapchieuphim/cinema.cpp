#include "cinema.cc"

int main()
{
    int day;
    cout << "Gut mo ninh, hom nay la thu: ";
    do
    {
        cin >> day;
        if (day <= 1 or day >= 9)
            cout << "Nhap vao ngay khong hop le!!" << endl;
        else
        {
            cout << "Hello, chao mung toi phan mem dat lich xem phim" << endl;
            if (day == 5)
                cout << "Hom nay rap chieu phim giam gia 50%";
            break;
        }
    } while (day <= 1 or day >= 9);
    cout << "\n\nCinema cua ban loai gi:";
    cout << "\n1.Cinema Thuong";
    cout << "\n2.Cinema Vip";
    cout << "\nPress 1 or 2 to choose: ";
    int choose;
    cin >> choose;
    if (choose == 1)
    {
        Cinema *c1 = new CinemaNormal(4, 4);
        cout << "Cinema Normal voi day ghe la 4x4" << endl
             << "Day ghe:" << endl;
        for (int i = 0; i < c1->getX(); i++)
        {
            for (int j = 0; j < c1->getY(); j++)
            {
                cout << "\t" << c1->isActive(i, j);
            }
            cout << endl;
        }
        c1->Price(day);
        c1->Booking();
        for (int i = 0; i < c1->getX(); i++)
        {
            for (int j = 0; j < c1->getY(); j++)
            {
                cout << "\t" << c1->isActive(i, j);
            }
            cout << endl;
        }
        int sure;
        do
        {
            cout << "Ban co muon dat tiep ko: 1 = co, 0 = khong" << endl
                 << ">";
            cin >> sure;
            if (sure == 1)
            {
                c1->Booking();
                for (int i = 0; i < c1->getX(); i++)
                {
                    for (int j = 0; j < c1->getY(); j++)
                    {
                        cout << "\t" << c1->isActive(i, j);
                    }
                    cout << endl;
                }
            }
            else
                break;
        } while (sure != 1 or sure != 0);
        cout << "Ban muon kiem tra ve tai vi tri nao:\n>";
        int x, y;
        cout << "\tHang ngang: ";
        cin >> x;
        cout << "\tHang doc: ";
        cin >> y;
        cout << "Tinh trang ghe tai vi tri " << x << " " << y << " la:" << c1->isActive(x - 1, y - 1);
        cout << "\nBan co muon kiem tra gia ve tai vi tri nao do ko:\n";
        cout << "\tHang ngang: ";
        cin >> x;
        cout << "\tHang doc: ";
        cin >> y;
        if (day == 5)
            cout << "Gia ve tai vi tri " << x << " " << y << "la: " << c1->getPrice(x - 1, y - 1);
        else
            cout << "\nGia ve tai vi tri " << x << " " << y << "la: " << c1->getPrice(x - 1, y - 1);
        cout << "\nKiem tra tinh trang ghe con trong trong rap!" << endl;
        cout << "\nCac ghe trong rap con lai la: " << c1->Available();
    }
    else
    {
        Cinema *c1 = new CinemaVip(4, 4);
        cout << "Cinema Vip voi day ghe la 4x4" << endl
             << "Day ghe:" << endl;
        for (int i = 0; i < c1->getX(); i++)
        {
            for (int j = 0; j < c1->getY(); j++)
            {
                cout << "\t" << c1->isActive(i, j);
            }
            cout << endl;
        }
        c1->Price(day);
        c1->Booking();
        for (int i = 0; i < c1->getX(); i++)
        {
            for (int j = 0; j < c1->getY(); j++)
            {
                cout << "\t" << c1->isActive(i, j);
            }
            cout << endl;
        }
        int sure;
        do
        {
            cout << "Ban co muon dat tiep ko: 1 = co, 0 = khong" << endl
                 << ">";
            cin >> sure;
            if (sure == 1)
            {
                c1->Booking();
                for (int i = 0; i < c1->getX(); i++)
                {
                    for (int j = 0; j < c1->getY(); j++)
                    {
                        cout << "\t" << c1->isActive(i, j);
                    }
                    cout << endl;
                }
            }
            else
                break;
        } while (sure != 1 or sure != 0);
        cout << "Ban muon kiem tra ve tai vi tri nao:\n>";
        int x, y;
        cout << "\tHang ngang: ";
        cin >> x;
        cout << "\tHang doc: ";
        cin >> y;
        cout << "Tinh trang ghe tai vi tri " << x << " " << y << " la:" << c1->isActive(x - 1, y - 1);
        cout << "\nBan co muon kiem tra gia ve tai vi tri nao do ko:\n";
        cout << "\tHang ngang: ";
        cin >> x;
        cout << "\tHang doc: ";
        cin >> y;
        if (day == 5)
            cout << "Gia ve tai vi tri " << x << " " << y << "la: " << c1->getPrice(x - 1, y - 1);
        else
            cout << "\nGia ve tai vi tri " << x << " " << y << "la: " << c1->getPrice(x - 1, y - 1);
        cout << "\nKiem tra tinh trang ghe con trong trong rap!" << endl;
        cout << "\nCac ghe trong rap con lai la: " << c1->Available();
    }
    return 0;
}
