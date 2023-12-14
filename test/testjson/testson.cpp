#include "json .hpp"
using json = nlohmann::json;
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

string func()
{
    json js;
    js["msg_type"] = 2;
    js["msg"] = "hello, what are you doing now?";
    js["from"] = "zhang san";
    js["to"] = "li si";

    string sendBuf = js.dump();

    // cout << sendBuf.c_str() << endl;
    return sendBuf;
}

string func2()
{
    json js;
    js["id"] = {1, 2, 3, 4, 5};
    js["name"] = "zhang san";
    js["msg"]["zhang san"] = "hello world";
    js["msg"]["liu shou"] = "hello china";
    js["msg"] = {{"zhang san", "hello world"}, {"liu shuo", "hello china"}};

    //  cout << js << endl;
    return js.dump();
}

string func3()
{
    json js;
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);

    js["list"] = vec;

    map<int, string> m;
    m.insert({1, "黄山"});
    m.insert({2, "华山"});
    m.insert({3, "泰山"});

    js["path"] = m;

    string bbb = js.dump();
    cout << bbb.c_str() << endl;
    return bbb;
}

int main()
{
    string recvbuf = func3();
    json jsbuf = json::parse(recvbuf);

    vector<int> vec = jsbuf["list"];
    for (int &v : vec)
    {
        cout << v << " ";
    }
    cout << endl;

    map<int, string> mymqp = jsbuf["path"];
    for (auto &b : mymqp)
    {
        cout << b.first << b.second << endl;
    }
    cout << endl;
    // cout << jsbuf["msg_type"] << endl;
    // cout << jsbuf["from"] << endl;
    // cout << jsbuf["to"] << endl;
    // cout << jsbuf["msg"] << endl;
    // cout << jsbuf["id"] << endl;
    // auto arr = jsbuf["id"];
    // cout << arr[2] << endl;

    // auto magjs = jsbuf["msg"];
    // cout << magjs["zhang san"] << endl;
    // cout << magjs["liu shuo"] << endl;

    // func3();
    // func2();
    // func();
    return 0;
}
// 序列化示例1
