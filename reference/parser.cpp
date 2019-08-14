#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>


std::vector<std::string> nodeParser(std::string body)
{
    std::vector<std::string> result;
    auto ampPos = body.find('&');
    auto un = body.substr(0, ampPos);
    auto pw = body.substr(ampPos + 1);
    
    auto eqPos = un.find('=');
    auto username = un.substr(eqPos + 1);
    
    eqPos = pw.find('=');
    auto passwd = pw.substr(eqPos + 1);

    result.push_back(username);
    result.push_back(passwd);
    return result;
}

int main(int argc, char const *argv[])
{
    // username=guinho&password=asdf
    auto html = "username=guinho&password=asdf";
    auto nodes = nodeParser(html);
    auto i = 0;
    std::for_each(nodes.begin(), nodes.end(), [&](auto s) { std::cout << s << "\t" << i++ << std::endl; });
    return 0;
}
