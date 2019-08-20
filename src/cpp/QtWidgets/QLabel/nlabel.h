#pragma once

#include <QLabel>
#include "src/cpp/core/NodeWidget/nodewidget.h"

class NLabel: public QLabel, public NodeWidget
{
    NODEWIDGET_IMPLEMENTATIONS(QLabel)
public:
    using QLabel::QLabel; //inherit all constructors of QLabel
};


