

#include <QObject>
#include <QNetworkCookieJar>
#include <QNetworkCookie>

class WebDiyCookie : public QNetworkCookieJar
{
    Q_OBJECT

    public:
    WebDiyCookie();
        WebDiyCookie(QObject *parent);
        ~WebDiyCookie();

        QList<QNetworkCookie> getCookies();
        void setCookies(const QList<QNetworkCookie>& cookieList);
    private:
};


