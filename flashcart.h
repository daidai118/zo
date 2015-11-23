#ifndef FLASHCART_H
#define FLASHCART_H

#include <QObject>

class FlashCart : public QObject
{
    Q_OBJECT
public:
    explicit FlashCart(QObject *parent = 0);

signals:

public slots:
};

#endif // FLASHCART_H
