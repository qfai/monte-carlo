#pragma once
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

class InputDialog:QDialog
{
public slots:
void reject() {
	setVisible(false);

	}
//void setsamplecount() {
//	parent()->
//
//}
public:
	void visible(bool b) { setVisible(b); }
	QDialogButtonBox *buttonBox;
	explicit InputDialog(QWidget *parent = 0):QDialog(parent){
		setupUi(this);

	}
	QLabel *label;
	QLineEdit *textEdit;

	void setupUi(QDialog *Dialog)
	{
		if (Dialog->objectName().isEmpty())
			Dialog->setObjectName(QStringLiteral("Dialog"));
		Dialog->resize(385, 168);
		buttonBox = new QDialogButtonBox(Dialog);
		buttonBox->setObjectName(QStringLiteral("buttonBox"));
		buttonBox->setGeometry(QRect(30, 110, 341, 32));
		buttonBox->setOrientation(Qt::Horizontal);
		buttonBox->setStandardButtons(QDialogButtonBox::Cancel | QDialogButtonBox::Ok);
		label = new QLabel(Dialog);
		label->setObjectName(QStringLiteral("label"));
		label->setGeometry(QRect(30, 60, 201, 51));
		QValidator *validator = new QIntValidator(1000, 10000, this); // 0-100 only accept number
		textEdit = new QLineEdit();
		textEdit->setValidator(validator);
		textEdit->setObjectName(QStringLiteral("textEdit"));
		textEdit->setGeometry(QRect(240, 70, 104, 31));

		retranslateUi(Dialog);
		connect(buttonBox, SIGNAL(accepted()), Dialog->parent(), SLOT(setsamplecount()));
		connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

	} // setupUi

	void retranslateUi(QDialog *Dialog)
	{
		Dialog->setWindowTitle(QApplication::translate("Dialog", "Input Sample Count", 0));
		label->setText(QApplication::translate("Dialog", "Input Sample Count(1000-10000)", 0));
	} // retranslateUi
};

