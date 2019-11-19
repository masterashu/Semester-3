#include <string>
#include <iostream>
#include "dist/json/json.h"

using namespace std;

int main()
{
    Json::Reader reader;
    Json::Value root;

    string json = "{\"call\": \"KF6GPE\",\"type\":\"l\",\"time\":\"1399371514\",\"lasttime\":\"1418597513\",\"lat\": 37.17667,\"lng\": -122.14650,\"result\":\"ok\"}";

    bool parseSuccess = reader.parse(json, root, false);

    if (parseSuccess)
    {
        const Json::Value resultValue = root["result"];
        cout << "Result is " << resultValue.asString() << "\n";
    }

    Json::StyledWriter styledWriter;
    Json::FastWriter fastWriter;
    Json::Value newValue;
    newValue["result"] = "ok";

    cout << styledWriter.write(newValue) << "\n";
    cout << fastWriter.write(newValue) << "\n";

    return 0;
}
