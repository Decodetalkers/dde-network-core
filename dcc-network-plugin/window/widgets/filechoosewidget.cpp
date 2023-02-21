// SPDX-FileCopyrightText: 2018 - 2022 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include "filechoosewidget.h"

#include <dfilechooseredit.h>

#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>
#include <QFileDialog>

using namespace DCC_NAMESPACE;
DWIDGET_USE_NAMESPACE

namespace dcc {

namespace network {

FileChooseWidget::FileChooseWidget(QWidget *parent)
    : SettingsItem(parent)
    , m_fileChooserEdit(new DFileChooserEdit(this))
    , m_title(new QLabel)
{
    m_title->setFixedWidth(110);
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(m_title);
    m_fileChooserEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    mainLayout->addWidget(m_fileChooserEdit);
    setLayout(mainLayout);
    setObjectName("FileChooseWidget");
}

void FileChooseWidget::setTitle(const QString &title)
{
    m_title->setText(title);
    setAccessibleName(title);
    m_title->setWordWrap(true);
}

void FileChooseWidget::setIsErr(const bool err)
{
    m_fileChooserEdit->setAlert(err);
}
}
}
