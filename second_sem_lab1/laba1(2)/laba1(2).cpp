#include <iostream>
#include <windows.h>

using namespace std;

struct client_info
{
    unsigned int id;
    char name[20];
    char surname[20];
    char login[20];
    char password[20];
    float payment;
};

struct tour_info
{
    unsigned int id;
    char tour[50]; 
    char description[256];
    float price;
};

client_info register_user()
{
    unsigned int id = 0;
    client_info elem;
    FILE* fp = fopen("../client.dat", "rb");
    fseek(fp, 0, SEEK_END);
    long pos = ftell(fp);
    if (pos > 0)
    {
        fseek(fp, pos - sizeof(client_info), SEEK_SET);
        fread(&elem, sizeof(elem), 1, fp);
        id = elem.id + 1;
    }
    fclose(fp);
    fp = fopen("../client.dat", "ab");
    fseek(fp, 0, SEEK_END);
    while (true)
    {
        elem.id = id;
        cout << "Enter your name: ";
        cin >> elem.name;
        cout << "Enter your surname: ";
        cin >> elem.surname;
        cout << "Create a login: ";
        cin >> elem.login;
        cout << "Create a password: ";
        cin >> elem.password;
        elem.payment = 0;
        if (strlen(elem.password) < 8) {
            cout << "Invalid password (length must be at least 8 symbols)!" << endl;
            cout << "Try again!" << endl;
        }
        else {
            fwrite(&elem, sizeof(elem), 1, fp);
            break;
        }
    }
    fclose(fp);
   
    return elem;
}

void add_payment(float payment,unsigned int id)
{
    client_info elem;
    FILE* fp = fopen("../client.dat", "rb");
    fp = fopen("../client.dat", "rb");
    fseek(fp, 0, SEEK_END);
    long pos = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    int count = pos / sizeof(client_info);
    client_info* tmp = new client_info[count];
    fread(tmp, sizeof(client_info), count, fp);
    for (int i = 0; i < count; i++)
    {

        if (i == id)
        {   
            tmp[i].payment=payment;
        } 
        
    }       
    fclose(fp);

    fp = fopen("../client.dat", "wb");
    fseek(fp, 0, SEEK_END);
    for (int i = 0; i < count; i++)
    {
        fwrite(&tmp[i], sizeof(elem), 1, fp);
    }
   
    
    
    
}

client_info login_user()
{
    unsigned int id = 0;
    client_info elem;
    FILE* fp = fopen("../client.dat", "rb");
    fp = fopen("../client.dat", "rb");
    fseek(fp, 0, SEEK_END);
    cout << "Enter a login: ";
    cin >> elem.login;
    //strcat(elem.login, "\0");
    cout << "Enter a password: ";
    cin >> elem.password;

    fseek(fp, 0, SEEK_END);
    long pos = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    int count = pos / sizeof(client_info);
    client_info* tmp = new client_info[count];
    fread(tmp, sizeof(client_info), count, fp);
    for (int i = 0; i < count; i++)
    {
        //strcat(tmp[i].login, "\0");
        if (strcmp(tmp[i].login, elem.login) == 0 && strcmp(tmp[i].password, elem.password) == 0)
        {
            
            /*client_info* ans = new client_info;
            ans->id = elem.id;
            strcpy(ans->name, elem.name);
            strcpy(ans->surname, elem.surname);
            ans->payment = elem.payment;
            cout << elem.name<<" "<< tmp[i].name << " " << ans->name << endl;*/
            return tmp[i];
        }
        
    }
    fclose(fp);    
    client_info ans;
    ans.id = -1;
    return ans;
        

}

tour_info tour(unsigned int id)
{
    
    tour_info elem;
    FILE* fp = fopen("../tour.dat", "rb");
    fp = fopen("../tour.dat", "rb");  
    fseek(fp, 0, SEEK_END);
    long pos = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    int count = pos / sizeof(tour_info);
    tour_info* tmp = new tour_info[count];
    fread(tmp, sizeof(tour_info), count, fp);
    for (int i = 0; i < count; i++)
    {
        
        if (i == id)
        {            
            return tmp[i];
        }

    }
    fclose(fp);
    tour_info ans;
    ans.id = -1;
    return ans;


}

void read_all_users()
{
    FILE* fp = fopen("../client.dat", "rb");
    fseek(fp, 0, SEEK_END);
    long pos = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    int count = pos / sizeof(client_info);
    client_info* part = new client_info[count];
    fread(part, sizeof(client_info), count, fp);
    for (int i = 0; i < count; i++)
        cout << " Name: " << part[i].name << " Surname: " << part[i].surname << " Login: " << part[i].login << " Password: " << part[i].password << " Payment: " << part[i].payment << endl;
    delete[] part;
    fclose(fp);
}

void read_all_tours()
{
    SetConsoleOutputCP(1251);
    FILE* fp = fopen("../tour.dat", "rb");
    fseek(fp, 0, SEEK_END);
    long pos = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    int count = pos / sizeof(tour_info);
    tour_info* part = new tour_info[count];
    fread(part, sizeof(tour_info), count, fp);
    for (int i = 0; i < count; i++)
       cout <<"\n"<<i+1<<". " <<part[i].tour << "\n   Price: " << part[i].price << "\u20AC" <<endl;
    delete[] part;
    fclose(fp);
}

int main() {
    read_all_users();
    char RorL;
    cout << "Welcome to our tour agency!" << endl;
    unsigned int id = 0;
    client_info elem;
    FILE* fp = fopen("../client.dat", "rb");

    while (true) {
        cout << "Press 'R' to register or press 'L' to login" << endl;
        cin >> RorL;
        if (RorL == 'R' || RorL == 'r'|| RorL == 'L' || RorL == 'l')
        {
            break;
        }
        else {
            cout << "Invalid syntax. Try again" << endl;
        }
        
    }

    while (RorL == 'L' || RorL == 'l')
    {
        elem = login_user();
        RorL = '0';
        if (elem.id == -1) {
            cout << "Invalid login or password" << endl;
            cout << "Press 'L' to try again or press 'R' to register" << endl;
            cin >> RorL;
            if (RorL == 'R' || RorL == 'r')
            {
                elem = register_user();
                RorL = '0';
                break;
            }
            else if (!(RorL == 'L' || RorL == 'l'))
            {
                cout << "Error. Invalid key" << endl;
                return 1;
            }
        }
    }
    if (RorL == 'R' || RorL == 'r')
    {
        elem = register_user();
    }
    char YorN, EorR;
    float k;
    cout << "Hello, " << elem.name << " " << elem.surname << "!" << endl;

    do {
        tour_info t_el;
        FILE* tt = fopen("../tour.dat", "rb");
        do {
            cout << "Now you can choose your tour:" << endl;

            read_all_tours();
            do
            {

            
            cout << "\nEnter the number of the selected tour:" << endl;
            cin >> t_el.id; 
            if (t_el.id > 7)
            {
                cout << "Invalid number. Try again" << endl;
            }
            } while (t_el.id > 7);
            t_el = tour(t_el.id-1);
            cout << "Your choice: '" << t_el.tour << "'" << endl;
            if (elem.payment >= 500 && elem.payment<1000)
            {
                k = 0.03;
                
            }
            else if (elem.payment >= 1000&& elem.payment<2000)
            {
                k = 0.05; 
            }
            else if (elem.payment >= 2000&& elem.payment<2500 )
            {
                k = 0.1;
            }
            else if (elem.payment >= 2500&& elem.payment<3000)
            {
                k = 0.15;
            }
            else if (elem.payment >= 3000&& elem.payment<4000)
            {
                k = 0.2; 
            }
            else if (elem.payment >= 4000)
            {
                k = 0.3; 
            }
            else if(elem.payment<500)
            {
                k = 0; 
            }
            
          
            cout << "Your have " << t_el.price * (1 - k) << "\u20AC to pay" << endl;
            cout << "Press 'Y' to confirm or press 'N' to cancel" << endl;
            cin >> YorN;
        } while (YorN == 'N'||YorN == 'n');
        if (YorN == 'Y'|| YorN == 'y')
        {       
            //elem.payment = 0;
            elem.payment = elem.payment + t_el.price * (1 - k);
            
            cout << "Your discount is " << k * 100 << "%!" << endl;
            add_payment(elem.payment, elem.id);

        }
        cout << "Press 'R' to order one more tour or press any key to exit"<< endl;
        cin >> EorR;
       
        
    } while (EorR == 'R'|| EorR == 'r');
    
    return 0;
}







//void read_all_tours()
//{
//    SetConsoleOutputCP(1251);
//    FILE* fp = fopen("../tour.dat", "rb");
//    fseek(fp, 0, SEEK_END);
//    long pos = ftell(fp);
//    fseek(fp, 0, SEEK_SET);
//    int count = pos / sizeof(tour_info);
//    tour_info* part = new tour_info[count];
//    fread(part, sizeof(tour_info), count, fp);
//    for (int i = 0; i < count; i++)
//       cout << part[i].tour<<endl<< part[i].description<<endl  << part[i].price<< "\u20AC" <<endl;
//    delete[] part;
//    fclose(fp);
//}
//
//int main() {
//
//    read_all_tours();
//    unsigned int id = 0;
//    tour_info elem;
//    FILE* fp = fopen("../tour.dat", "rb");
//    fseek(fp, 0, SEEK_END);
//    long pos = ftell(fp);
//    if (pos > 0)
//    {
//        fseek(fp, pos - sizeof(tour_info), SEEK_SET);
//        fread(&elem, sizeof(elem), 1, fp);
//        id = elem.id + 1;
//    }
//    fclose(fp);
//
//    fp = fopen("../tour.dat", "ab");
//    fseek(fp, 0, SEEK_END);
//    while (true)
//    {
//        elem.id = id;
//        cout << "Enter tour name: ";
//        cin.getline(elem.tour, 50); 
//        cout << "Enter description: ";
//        cin.getline(elem.description, 256);
//        cout << "Enter price: ";
//        cin >> elem.price;        
//        if (elem.price < 1) break;
//        else fwrite(&elem, sizeof(elem), 1, fp);
//        id++;
//    }
//    fclose(fp);
//
//    return 0;
//}