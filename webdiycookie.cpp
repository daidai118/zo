#include "webdiycookie.h"

WebDiyCookie::WebDiyCookie()
{

}

WebDiyCookie::WebDiyCookie(QObject *parent)
    : QNetworkCookieJar(parent)
{

}

WebDiyCookie::~WebDiyCookie()
{

}

QList<QNetworkCookie> WebDiyCookie::getCookies()
{
    return allCookies();
}

void WebDiyCookie::setCookies(const QList<QNetworkCookie>& cookieList)
{
    if(this == NULL)
        return;
    this->setAllCookies(cookieList);
}
