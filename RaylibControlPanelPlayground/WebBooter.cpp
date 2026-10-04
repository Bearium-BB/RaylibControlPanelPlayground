#include "WebBooter.hpp"
#include <regex>

bool WebBooter::hasHTTPorHTTPS(const std::string& url)
{
    return url.starts_with("http://") ||
        url.starts_with("https://");
}

bool WebBooter::isValidURL(const std::string& url)
{
    std::regex pattern(
        R"(^(https?://)([a-zA-Z0-9-]+\.)+[a-zA-Z]{2,}(/.*)?$)"
    );

    return std::regex_match(url, pattern);
}

bool WebBooter::isValidIP(const std::string& ip)
{
    std::regex pattern(
        R"(^(25[0-5]|2[0-4][0-9]|1?[0-9]?[0-9])(\.(25[0-5]|2[0-4][0-9]|1?[0-9]?[0-9])){3}$)"
    );

    return std::regex_match(ip, pattern);
}

void WebBooter::OpenBrowser(const std::string& search)
{
    std::string url;
    if (isValidURL(search))
    {
        url = search;
    }
    else if (isValidIP(search))
    {
        url = "http://" + search;
    }
    else
    {
        url = "https://www.google.com/search?q=" + search;
    }

#ifdef _WIN32
    std::string command = "start \"\" \"" + url + "\"";
#elif __APPLE__
    std::string command = "open \"" + url + "\"";
#elif __linux__
    std::string command = "xdg-open \"" + url + "\"";
#else
    return;
#endif

    std::system(command.c_str());
}

WebBooter::WebBooter() 
{

}