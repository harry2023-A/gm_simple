#pragma once
#include<iostream>
//#include"worker.h"
#include <fstream>
#include <ctime>
#include <string>
#include <sstream>
// #include "worker.h"
#include <limits>
#include<vector>
#include <conio.h>

//商品文件
#define  FILENAME "empGdFile.txt"
//日志文件
#define  LOGFILENAME "LogGdFile.txt"
//用户文件
#define USRFILENAME "UserFIle.txt"
//admin 默认密码
#define INITPASSWORD "hello"
using namespace std;
// 商品结构
struct goodsInfo
{
    /* data */
    int m_Id;      // 商品编号
    string m_Name; // 商品名称
    int m_Price;   // 商品价格
    int m_Num;     // �
    string m_Unit; // 商品单位
};

//用户结构
struct userInfo
{
    string username;
    unsigned int hashpassword;
};

// 日志类
class Log
{
public:
    /*     void logMessage(const std::string& message) {
            std::cout << "Logging message: " << message << std::endl;
        }; */
    void AddLog(string str);
    void ShowLog();
};

// 用户管理类
class UserManage:public Log
{
public:
    string getUsername() { return username; }
    string getPassword() { return password; }
    // bool isPasswordCorrect(unsigned int password);
    int UserLogin();
    unsigned int simpleHash(const string &str);
    // 判断用户账号和密码是否匹配
    int UserMatch(string input_username, unsigned int encrypted_input_password);
    // 增加用户
    int UserAdd();
    int UserExt();
   //输入密码
    unsigned int InputPassword();
    // 构造函数
    UserManage();

    // 析构函数
    ~UserManage();
    string username;

private:
    string password;
    unsigned int hashPassword;

    int m_EmpNum;

    // 保存文件
    void save();
    // 保存文件
    void save(string input_username, unsigned int encrypted_input_password);
    // 标志文件是否为空
    bool m_FileIsEmpty;
    // 统计人数
    int get_EmpNum();
    // 初始化
    void init_Emp();
    void init_Usr();
    // 按照编号判断商品是否存在,若存在返回商品在数组中位置，不存在返回-1
    int IsExist(int id);

    // 记录文件中的人数个数
//    UserInfo **m_UsrArray;
    vector<userInfo> m_UsrVector;
    void ShowGoodsInfo(goodsInfo tmp);
    void save_vector();
};
//商品管理
class GoodsManager:public Log
{
public:

    //构造函数
    GoodsManager();

    //析构函数
    ~GoodsManager();

   void Show_Menu();
   void exitSystem();
       //记录文件中的人数个数
    int m_EmpNum;

    //保存文件
    void save();  
     //标志文件是否为空
    bool m_FileIsEmpty;
        //统计商品种类数目
    int get_EmpNum();
        //初始化
    void init_Emp();
        //显示
    void Show_Emp();
      //删除
  //  void Del_Emp();
            //按照职工编号判断职工是否存在,若存在返回职工在数组中位置，不存在返回-1
  //  int IsExist(int id);


        // 商品数组的指针
        //  Goods ** m_GdArray;
        vector<goodsInfo>
            m_GdVector;
    void ShowGoodsInfo(goodsInfo tmp);
    void save_vector();

    // 商品编号
    int m_GdNum;


    void GoodsIn();      // 商品入库
    void GoodsOut();     // 商品销售
    void Product_Add();//增加商品
    void product_Show();//商品显示
    int iDSearch(int iCheckID);
  //  Log logh;
    string curentUser;
};


