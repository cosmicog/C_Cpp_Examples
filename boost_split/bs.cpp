#include <boost/spirit/include/qi.hpp>

struct misc {
    static void split(const std::string &input, std::string &left, std::string &right, char separator)
    {
        using namespace boost::spirit::qi;

        parse(input.begin(), input.end(), *~char_(separator) >> separator >> *char_, left, right);
    }
};

int main() {
    for (std::string s : {
            "",
            "a",
            "a;",
            "a;b",
            ";b",
            ";",
            "a;b;",
            ";;" })
    {
        std::string l,r;
        misc::split(s,l,r,';');
        std::cout << "'" << s << "'\t-> l:'" << l << "'\tr:'" << r << "'\n";
    }
}
