#include "OOP_Seminar07_chat_QtGuiApplication.h"
#include <QtWidgets/QApplication>
#include "ChatSession.h"
#include "ChatWindow.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//OOP_Seminar07_chat_QtGuiApplication w;

	ChatSession cs{};
	ChatWindow cw1{ "Korina", &cs };
	ChatWindow cw2{ "Andrei", &cs };
	ChatWindow cw3{ "Geo", &cs };
	ChatWindow cw4{ "Alexandra", &cs };

	cw1.setWindowTitle("Korina");
	cw2.setWindowTitle("Andrei");
	cw3.setWindowTitle("Geo");
	cw4.setWindowTitle("Alexandra");

	cs.registerObserver(&cw1);
	cs.registerObserver(&cw2);
	cs.registerObserver(&cw3);
	cs.registerObserver(&cw4);

	cw1.show();
	cw2.show();
	cw3.show();
	cw4.show();


	//w.show();
	return a.exec();
}
