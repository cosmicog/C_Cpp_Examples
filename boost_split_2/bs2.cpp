#include <boost/algorithm/string/classification.hpp> // Include boost::for is_any_of
#include <boost/algorithm/string/split.hpp> // Include for boost::split
#include <iostream>

int main()
{
std::vector<std::string> words;
std::string s("cmd:reboot");
boost::split(words, s, boost::is_any_of(":"), boost::token_compress_on);
std::cout<<words.at(0) << std::endl;
std::cout<<words.at(1)<< std::endl;

return 0;
}

