#include <string>
#pragma once
class WebBooter
{
	public:
		WebBooter();
		void OpenBrowser(const std::string& search);
	private:
		bool hasHTTPorHTTPS(const std::string& url);
		bool isValidURL(const std::string& url);
		bool isValidIP(const std::string& ip);
};
