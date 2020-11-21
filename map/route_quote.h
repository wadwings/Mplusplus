#ifndef ROUTE_QUOTE_H
#define ROUTE_QUOTE_H
#include <QtWidgets>
#include <search_quote.h>
#include <close.h>
class route_quote : public QWidget
{
public:
    vector<string> o;
    closetag *tag;
    searchlist *begin, *end;
    route_quote(QWidget * parent = nullptr, vector<string> o = {""});
};

#endif // ROUTE_QUOTE_H
