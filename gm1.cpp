#include "gm1.h"
using namespace std;

void test()
{
   //int i;
        //UserManage ur;
      //  i = ur.InputPassword();
    //   unsigned int hashPassValue = ur.simpleHash("test");
    //ur.UserAdd();
    //   ur.UserLogin();  */
    GoodsManager wm;
    wm.ShowLog();

/*     ifstream file(LOGFILENAME); // 打开文件
    string line; */

/*     if (file.is_open()) {
        while (:getline(file, line)) { // 逐行读取文件内容
            cout << line << endl; // 打印每行内容
        }
        file.close(); // 关闭文件
    } else {
        scout << "无法打开文件" << endl;
    }
 */
 
}


int main()
{
    test();
    GoodsManager wm;
    UserManage ur;

    char choice = '0';
    int LoginFlag = 0;
    // 用户登录
    while (LoginFlag == 0)
    {
        LoginFlag = ur.UserLogin();
    }
    // system("cls");
    wm.curentUser = ur.username;

    while (true)
    {
        // 展示菜单
        wm.Show_Menu();
        cout << "choice:" << endl;
            cin >> choice;

        switch (choice)
        {
        case '0': // 退出系统
            wm.exitSystem();
            break;
        case '1': // 添加商品
                //  wm.Add_Emp();
            wm.Product_Add();
            break;
        case '2': // 显示商品
            wm.Show_Emp();
            break;
        case '3': // 商品出货

            wm.GoodsOut();
            break;
        case '4': //

            break;
        case '5': // 商品入库
            wm.GoodsIn();
            break;
        case '6': // 排序商品
            break;
        case '7': // 增加用户
        {
            // 如果账号是admin，可以增加用户
            string str = ur.getUsername();
            int result = str.compare("admin");
            if (result == 0)
                ur.UserAdd();
        }
        break;
        default:
            // 清除屏幕
            //          system("cls");
            break;
        }
    }

    //   system("pause");
    return 0;
}

// 构建函数
GoodsManager::GoodsManager()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    // 商品文件不存在情况
    if (!ifs.is_open())
    {
        //    cout << "file not exit" << endl; //测试输出
        this->m_EmpNum = 0;         // 初始化商品数目
        this->m_FileIsEmpty = true; // 初始化文件为空标志
        //   this->m_GdArray = NULL; //初始化数组
        ifs.close(); // 关闭文件
        return;
    }
    // 文件存在，并且没有记录
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        //    cout << "file empty" << endl;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        //  this->m_GdArray = NULL;
        ifs.close();
        return;
    }
    this->m_FileIsEmpty = false;
    int num = this->get_EmpNum();
    this->m_EmpNum = num; // 更新成员属性

    // 初始化商品
    init_Emp();
}
// 析构
GoodsManager::~GoodsManager()
{
    /*     if (this->m_GdArray != NULL)
        {
            delete[] this->m_GdArray;
        } */
}
// 显示管理菜单
void GoodsManager::Show_Menu()
{
    cout << "**************" << endl;
    cout << "welcome " << endl;
    cout << "0.exit " << endl;
    cout << "1.input goods " << endl;
    cout << "2.show goods" << endl;
    cout << "3.goods out" << endl;
    cout << "4.modify" << endl;
    cout << "5.goods in" << endl;
    cout << "6." << endl;
    // 如果是admin账号，显示增加用户的选择
    string str = this->curentUser;
    int result = str.compare("admin");
    if (result == 0)
        cout << "7.add user" << endl;
    cout << "*************" << endl;
    cout << endl;
}
// 退出系统
void GoodsManager::exitSystem()
{
    cout << "welcome" << endl;
    //    system("pause");
    exit(0);
}

// 获取商品种类数目
int GoodsManager::get_EmpNum()
{
    int id;
    string name;
    int iNum;
    string sUnit;
    int iPrice;
    int num = 0;
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    while (ifs >> id && ifs >> name && ifs >> sUnit && ifs >> iNum && ifs >> iPrice)
    {
        // 记录数目
        num++;
    }
    ifs.close();

    return num;
}
// 从商品文件读取商品信息，初始化数组
void GoodsManager::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

  /*   int id;*/
 /*   string name;
    int iNum;
    string sUnit;
    int iPrice; */
    int index = 0;
    goodsInfo tmp;

    while (ifs >> tmp.m_Id && ifs >>tmp.m_Name && ifs >> tmp.m_Unit && ifs >> tmp.m_Num && ifs >> tmp.m_Price)
    {

   /*       tmp.m_Id = id;
        tmp.m_Name = name;
        tmp.m_Unit = sUnit;
        tmp.m_Num = iNum;
        tmp.m_Price = iPrice; */

        this->m_GdVector.push_back(tmp); //   push_back(goods);//   push_back(goods);
        index++;
    }
    ifs.close();
}
// 显示商品
void GoodsManager::Show_Emp()
{
    int i;
    if (this->m_FileIsEmpty)
    {
        cout << "file not exit" << endl;
    }
    else
    {
        for (i = 0; i < this->m_EmpNum; i++)
        {
            /* code */
            goodsInfo tmp = this->m_GdVector.at(i);
            this->ShowGoodsInfo(tmp);
        }
    }
}

void GoodsManager::ShowGoodsInfo(goodsInfo tmp)
{

    cout << "id      :" << tmp.m_Id
         << " \tname  :" << tmp.m_Name
         << " \tprice :" << tmp.m_Price
         << " \tnumber:" << tmp.m_Num
         << " \tunite :" << tmp.m_Unit << endl;
}

// 增加商品
void GoodsManager::Product_Add()
{
    stringstream ss;
    string str;
  //  Log logh; // 创建日志对象
    goodsInfo tmp;
    tmp.m_Num=0;
    cout << "Input ID: " << endl;
   // cin >> tmp.m_Id;
    do
    {
        cin >> tmp.m_Id;
    } while (tmp.m_Id <= 0);
                   /*    while (!(cin >> id) || id < 0)
                      {
                          cout << "Invalid input. Please enter a valid ID: ";
                          cin.clear();
                          cin.ignore(numeric_limits<streamsize>::max(), '\n');
                      }
                   */
    cout<< "input name: " << endl;
    /*     cin.ignore(); // Ignore any remaining characters in the input buffer
        getline(cin, name); */
    // 输入回车要重新输入
 /*    do
    {
        cin >> name;
    } while (name.empty()); */
    
    cin >> tmp.m_Name;

     cout << "Input price: " << endl;
    /*             while (!(cin >> iPrice) || iPrice < 0)
                   {
                       cout << "Invalid input. Please enter a valid price: ";
                       cin.clear();
                       cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } */
   do
   {
    cin >> tmp.m_Price;
   }while(tmp.m_Price<=0);

    cout<< "input unit: " << endl;

/*     do
    {
        cin >> sUnit;
    } while (sUnit.empty()); */
    cin >> tmp.m_Unit;

 
    this->m_GdVector.push_back(tmp);
    // 更新新的个数
    this->m_EmpNum++;
    // 更新商品不为空标志
    this->m_FileIsEmpty = false;
    this->save_vector();

    cout << "add success" << endl;

    // 生成日志消息
    ss <<"user::"<<this->curentUser<< " input id:" << tmp.m_Id << " name:" << tmp.m_Name << " price:" << tmp.m_Price << " unite:" << tmp.m_Unit;
    getline(ss, str);
    this->AddLog(str);
    //   nname, iNum, sUnit, iPrice

    //   system("pause");
    //  system("cls");
}

void GoodsManager::save_vector()
{
    int i;
    goodsInfo tmp;
    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    for (i = 0; i < this->m_EmpNum; i++)
    {
        tmp = this->m_GdVector.at(i);
        ofs << tmp.m_Id << " "
            << tmp.m_Name << " "
            << tmp.m_Unit << " "
            << tmp.m_Num << " "
            << tmp.m_Price
            << endl;
    }

    ofs.close();
}
// 判断商品编号是否存在，返回在数据里的位置
int GoodsManager::iDSearch(int iCheckID)
{

    goodsInfo tmp;
    if (this->m_FileIsEmpty)
    {
        cout << "file not empty" << endl;
    }
    else
    {
        for (int i = 0; i < m_EmpNum; i++)
        {
            // 容器化版本
            tmp = this->m_GdVector.at(i);
            if (tmp.m_Id == iCheckID)
            {
                return i;
            }
        }
    }
    return -1;
}
// 根据商品编号，输入入库商品数量
void GoodsManager::GoodsIn()
{
    int iCheckID = 0;
    int SegNum = 0;
    int iNum = 0;
    stringstream ss;
    string str;
    goodsInfo tmpGoods;

    cout << "input goods id: " << endl;
    cin>>iCheckID;
/*     while (!(cin >> iCheckID))
    {
        cout << "Invalid input. Please enter a valid ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } */

    // cin >> iCheckID;

    if (this->m_FileIsEmpty)
    {
        cout << "goods file not empty" << endl;
    }
    else
    {
        if (iCheckID == 0)
        {
            cout << "goods input err" << endl;
        }
        else
        {
            SegNum = this->iDSearch(iCheckID);
            //          this->m_EmpArray[i]->showInfo();
            if (SegNum >= 0)
            {
                // this->m_GdArray[SegNum]->ShowGInfo();
                tmpGoods = this->m_GdVector.at(SegNum);
                this->ShowGoodsInfo(tmpGoods);
                /*                      cout<<"是否要增加该商品的入库(yes/no?)"<<endl;
                                    if ( )
                                    {

                                    }  */
                cout
                    << "Product delivery quantity: " << endl;
                cin >> iNum;
                if (iNum > 0)
                {
                    //  this->m_GdArray[SegNum]->m_Num = this->m_GdArray[SegNum]->m_Num + iNum;
                    tmpGoods.m_Num = tmpGoods.m_Num + iNum;
                    this->m_GdVector.erase(this->m_GdVector.begin() + SegNum);
                    this->m_GdVector.insert(this->m_GdVector.begin() + SegNum, tmpGoods);
                    // this->Show_Emp();
                    tmpGoods = this->m_GdVector.at(SegNum);
                    cout
                        << "add success" << endl;
                    // this->save();
                    this->save_vector();

                    // 生成日志消息
                    ss << "user::" << this->curentUser<< "ID: " << tmpGoods.m_Id << " name:" << tmpGoods.m_Name << " in:" << iNum;
                    getline(ss, str);
                    this->AddLog(str);
                }
                else
                {
                    cout << "input err" << endl;
                }
            }
            else
            {
                cout << "not found ID" << endl;
            }
        }
    }
}
// 工具商品编号，输入出库商品数量
void GoodsManager::GoodsOut()
{
    //    cout << "input id" << endl;
    int iCheckID = 0;
    int iNum = 0;
    stringstream ss;
    string str;
    //   cin >> iCheckID;
    int SegNum = 0;
    goodsInfo tmpGoods;

    cout << "input goods id: " << endl;
    cin >> iCheckID;
/*     while (!(cin >> iCheckID))
    {
        cout << "Invalid input. Please enter a valid ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
 */
    if (this->m_FileIsEmpty)
    {
        cout << "goods file not exit" << endl;
    }
    else
    {

        if (iCheckID == 0)
        {
            cout << "input err" << endl;
        }
        else
        {
            SegNum = this->iDSearch(iCheckID);
            //          this->m_EmpArray[i]->showInfo();
            if (SegNum >= 0)
            {
                // this->m_GdArray[SegNum]->ShowGInfo();
                tmpGoods = this->m_GdVector.at(SegNum);
                this->ShowGoodsInfo(tmpGoods);
                /*                      cout<<"是否要增加该商品的入库(yes/no?)"<<endl;
                                    if ( )
                                    {

                                    }  */
                cout << "Quantity of goods in stock: " << endl;
                cin >> iNum;
                // if (iNum > 0 && (this->m_GdArray[SegNum]->m_Num - iNum) > 0)
                if (iNum > 0 && (tmpGoods.m_Num - iNum > 0))
                {
                    //   this->m_GdArray[SegNum]->m_Num = this->m_GdArray[SegNum]->m_Num - iNum;
                    tmpGoods.m_Num = tmpGoods.m_Num - iNum;
                    this->m_GdVector.erase(this->m_GdVector.begin() + SegNum);
                    this->m_GdVector.insert(this->m_GdVector.begin() + SegNum, tmpGoods);
                    tmpGoods = this->m_GdVector.at(SegNum);
                    cout << "add success" << endl;
                    // this->save();
                    this->save_vector();
                    // 生成日志消息
                    ss << "user::" << this->curentUser<< "ID:" << tmpGoods.m_Id << " name:" << tmpGoods.m_Name << " out" << iNum;
                    //  ss << "id:" << tmpGoods.m_Id << " name:" << tmpGoods.m_Name << " sold" << iNum;
                    getline(ss, str);
                    //    logh.AddLog(str);
                    this->AddLog(str);
                }
                else
                {
                    cout << "input err" << endl;
                }
            }
            else
            {
                cout << "not found ID" << endl;
            }
        }
    }
}

// 日志保存

void Log::AddLog(string sMessage)
{
    ofstream ofs;
    string time_str;
    // 获取当前时间
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);

    // 将时间转换为年月日小时分钟的格式   struct tm *tm = localtime(&now);
    // 将时间存储到string变量中
    time_str = to_string(tm->tm_year + 1900) + "-" + to_string(tm->tm_mon) + "-" + to_string(tm->tm_mday) + " " + to_string(tm->tm_hour) + ":" + to_string(tm->tm_min) + ":" + to_string(tm->tm_sec);
    // 输出时间

    ofs.open(LOGFILENAME, ios::app);
    ofs << time_str << "  " << sMessage << endl;

    ofs.close();
}

//显示日志
void Log::ShowLog()
{
    ifstream file(LOGFILENAME); // 打开文件
    string line;

    if (file.is_open())
    {
        while (getline(file, line))
        {                         // 逐行读取文件内容
            cout << line << endl; // 打印每行内容
        }
        file.close(); // 关闭文件
    }
    else
    {
        cout << "无法打开文件" << endl;
    }
}

// 用户登录
int UserManage::UserLogin()
{
    // 读取用户名和密码
    string encrypted_username, encrypted_password;
    // 提示用户输入用户名和密码
    cout << "input user name: ";
    string input_username;
    cin >> input_username;

    cout << "input password: "; 
    unsigned int encrypted_input_password;
   // cin >> input_password;
    /*   unsigned int encrypted_input_password = this->simpleHash(input_password); */

    encrypted_input_password = this->InputPassword();

    // string encrypted_input_password = input_password;
    // 验证用户名和密码是否匹配
    // UserList ur(encrypted_username, encrypted_password);
    int Userseg;
    Userseg = this->UserMatch(input_username, encrypted_input_password);
    if (Userseg >= 0)
    {
        cout << "login success" << endl;
        this->username = input_username;
        this->password = encrypted_input_password;
        return 1;
    }
    else
    {
        cout << "login failed" << endl;
        return 0;
    }
}

// 简单加密算法
// Simple hash function that sums the ASCII values of characters
unsigned int UserManage::simpleHash(const std::string &str)
{
    unsigned int hash = 0;
    for (char c : str)
    {
        hash += static_cast<unsigned int>(c);
    }
    return hash;
}

// 构造函数
UserManage::UserManage()
{
    unsigned int hashPassValue = simpleHash(INITPASSWORD);
    ifstream ifs;
    ifs.open(USRFILENAME, ios::in);
 
    // 文件不存在情况
    if (!ifs.is_open())
    {
        ifs.close();
       // ofstream ofs;
        // 建立默认账号
        this->save("admin", hashPassValue);

        //    return;
    }
// 文件存在，并且没有记录
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        ifs.close();
        // 建立默认账号
        this->save("admin", hashPassValue);
    }
    this->m_FileIsEmpty = false;
    int num = this->get_EmpNum();
    // cout << "user number" << num << endl; // 测试代码
    this->m_EmpNum = num; // 更新成员属性

    // 初始化用户
    init_Usr();
}
//输入密码，回显'*'
unsigned int UserManage::InputPassword()
{
    char password[20];
    int i = 0;
    char ch;
    string str;
  //  cout << "input user password: ";
    while (1)
    {
        ch = getch();
        if (ch == '\r') // 判断是否是回车键
        {
            password[i] = '\0'; // 字符串结束标记
            break;
        }
        else if (ch == '\b') // 判断是否是退格键
        {
            if (i > 0)
            {
                cout << "\b \b"; // 删除一个字符
                i--;
            }
        }
        else // 正常字符
        {
            password[i] = ch;
            i++;
            cout << "*"; // 屏幕上以"*"显示输入的字符
        }
    }
    cout << endl;
    /**    << "input user password: " << password; */
    i = this->simpleHash(password);
    return i;
}

//统计用户数目
int UserManage::get_EmpNum()
{
    string encrypted_username;
    unsigned int hashPassValue;
    ifstream ifs;
    ifs.open(USRFILENAME, ios::in);

    int num = 0;

    while (ifs >> encrypted_username && ifs >> hashPassValue)
    {
        // 记录用户数目
        //              this->m_GdArray[num]->m_Id = id;
        num++;
    }
    ifs.close();

    return num;
}
// 析构函数
UserManage::~UserManage()
{
    /*      if (this->m_UsrArray != NULL)
         {
             delete[] this->m_UsrArray;
         } */
}
// 读取用户文件，放入到数组里
void UserManage::init_Usr()
{
    ifstream ifs;
    ifs.open(USRFILENAME, ios::in);
    userInfo tmpUser;

    string encrypted_username;
    unsigned int hashPassValue;
    int index = 0;

    while (ifs >> encrypted_username && ifs >> hashPassValue)
    {
        // 容器化
        tmpUser.username = encrypted_username;
        tmpUser.hashpassword = hashPassValue;
        this->m_UsrVector.push_back(tmpUser); //   push_back(goods);//   push_back(goods);
        index++;
    }
    ifs.close();
}
// 在用户数组里匹配
int UserManage::UserMatch(string input_username, unsigned int encrypted_input_password)
{
    userInfo tmpUser;

    if (this->m_FileIsEmpty)
    {
        cout << "user file not exit" << endl;
    }
    else
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            // 匹配用户名和密码
            tmpUser = this->m_UsrVector.at(i);
            if ((tmpUser.hashpassword == encrypted_input_password) && (tmpUser.username == input_username))
            {
                return i;
            }
        }
    }
    return -1;
}
// 增加用户
int UserManage::UserAdd()
{
    stringstream ss;
    // string input_username;

    // 计算新空间大小
  //  int newSize = this->m_EmpNum;

    // 输入新数据

    string input_name;
    unsigned int input_password1, input_password2;
    string str;

    // 提示用户输入用户名和密码

    cout << "input user's name: " ;
    cin >> input_name;

    // 加入异常处理
    /*      cin.ignore(); // Ignore any remaining characters in the input buffer
        getline(cin, input_name);  */
    //先换行，再输出
     cout << "input password: ";
    /*cin >> input_password1; */
    input_password1=this->InputPassword();

            /*          cin.ignore(); // Ignore any remaining characters in the input buffer
                    getline(cin, input_password1);  */
    // 先换行，再输出
    cout<<"input password again: ";
    input_password2=this->InputPassword();
    //   cout << "input password ";
    /*      cin.ignore(); // Ignore any remaining characters in the input buffer
        getline(cin, input_password2);  */

   /*  cin >> input_password2; */
    //判断两次密码是否输入相同
    if (input_password1 != input_password2)
    {
        cout << "the password is not same "<<endl;
        return 0;
    }

    // 指针模式

    // 容器模式
    userInfo tmp;
    // 生成hash加密密码
   // unsigned int hashPassValue = this->simpleHash(input_password1);
    tmp.username = input_name;
    tmp.hashpassword = input_password1;

    this->m_UsrVector.push_back(tmp);
    // 更新新的个数
    this->m_EmpNum++;
    // 更新商品不为空标志
    this->m_FileIsEmpty = false;
    this->save_vector();

    cout << "add success" << endl;
   //日志记录
    ss << "add user:" ;

    getline(ss, str);

    // logh.AddLog(str);
    this->AddLog(str);

    return 1;
}

// 保存指定用户
void UserManage::save(string input_username, unsigned int encrypted_input_password)
{
    ofstream ofs;
    ofs.open(USRFILENAME, ios::out);

    ofs << input_username << " "
        << encrypted_input_password << " "

        << endl;

    ofs.close();
}
// 保存用户数组
void UserManage::save_vector()
{
    userInfo tmp;
    ofstream ofs;
    ofs.open(USRFILENAME, ios::out);

    for (int i = 0; i < this->m_EmpNum; i++)
    {
        tmp = this->m_UsrVector.at(i);
        ofs << tmp.username << " "
            << tmp.hashpassword << " "
            << endl;
    }

    ofs.close();
}