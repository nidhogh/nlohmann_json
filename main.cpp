#include <iostream>
#include <vector>
#include <set>
#include <QCoreApplication>
#include <QDebug>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;    // for convenience

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    //1：json对象初始化
    json j1 = {
      {"msgIds", {111,222,333}},
    };

//    cout << "j1: " << j1 << endl;   //输出json对象值

    std::vector<int> v = j1["msgIds"];

    //2：通过string构造json对象
    json j2 = json::parse(R"(
{
  "msgIds": [
    {
      "msgId": "11",
      "chatId": "22"
    },
    {
      "msgId": "33",
      "chatId": "44"
    },
    {
      "msgId": "55",
      "chatId": "66"
    }
  ]
}
)");

    j2 = json::parse(R"(
{"fileName":"MEjPTY0DMzVvOnG4FDt0DVb7yGFsBJG3.gif","size":678390,"width":500,"height":281,"isOrigin":true,"isGif":true,"downloadUrl":"https://sy-develop.uban360.com:21007/sfs/file?digest=fid0c0f4bb61202a1f7f7160b8653084db5&imageSizeType=2"}
)");

//    cout << "j2: " << j2["isGif"] << endl;

//    vector<string> msgIdVec;
//    vector<string> chatIdVec;
//    for (auto elem : j2["msgIds"]) {
//        msgIdVec.push_back(elem["msgId"]);
//        chatIdVec.push_back(elem["chatId"]);
//    }

    json j3 = json::parse(R"(
{
  "chatId": "444",
  "msgIds": [
    "111",
    "222",
    "333"
  ]
}
)");

    string chatId = j3["chatId"];
    vector<string> msgIds = j3["msgIds"];   //json转vector

    json j4;
    j4["content"] = "11";
    string s = j4.dump();   //3：json对象转string
//    cout << "j4" << s << endl;

    json j = json::parse(R"({"voice":[3,3,4,4,7,7,8,6,7,5,4,4],"duration":3})");
    json j5;
    j5["xxx"] = "yyy";
    j5["duration"] = j["duration"];
    j5["voice"] = j["voice"];
    j5["nothing"] = nullptr;
//    cout << j5 << endl;

    json a1 = json::parse(R"(
    {
      "type": "11",
      "extra": "22"
    }
)");
    json a2 = json::parse(R"(
    {
      "type": "33",
      "extra": "44"
    }
)");
    json ja;
    ja.push_back(a1);
    ja.push_back(a2);

    json jb;
    jb["list"] = ja;
//    cout << "jb" << jb.dump() << endl;

    std::set<int> set{1,2,3,4};
    json jv(set);
    qDebug() << __FUNCTION__ << "jv" << jv.dump().c_str();

    return a.exec();
}
