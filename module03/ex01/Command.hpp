#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <vector>
#include <string>

struct Article {
    std::string name;
    int quantity;
    float price;

    Article(const std::string& n, int q, float p) : name(n), quantity(q), price(p) {}
};

class Command {
public:
    Command(int i, int d, const std::string& c, const std::vector<Article>& a)
        : id(i), date(d), client(c), articles(a) {}
    virtual ~Command() {}

    virtual float apply_discount(float total) const {
        (void)total;
        return total;
    }

    virtual float get_total_price() const {
        float total = 0;
        for (size_t i = 0; i < articles.size(); ++i)
            total += articles[i].price * articles[i].quantity;
        return apply_discount(total);
    }

protected:
    int id;
    int date;
    std::string client;
    std::vector<Article> articles;
};

#endif
