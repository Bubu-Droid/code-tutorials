#include <QtWidgets>

// int main(int argc, char* argv[]) {
//   QApplication app(argc, argv);
//   // QPushButton button("Hello World!");
//   // button.show();
//   return app.exec();
//   // QPushButton button("Hello World!");
//   // button.show();
//   // return app.exec();
// }

// int main(int argc, char* argv[]) {
//   QApplication app(argc, argv);
//   QWidget window;
//   window.resize(320, 240);
//   window.show();
//   window.setWindowTitle(
//       QApplication::translate("toplevel", "Top-level widget")
//   );
//   return app.exec();
// }

// int main(int argc, char* argv[]) {
//   QApplication app(argc, argv);
//   QWidget window;
//   window.resize(320, 240);
//   window.setWindowTitle(QApplication::translate("childwidget", "Child widget"));
//   window.show();
//
//   QPushButton* button = new QPushButton(
//       QApplication::translate("childwidget", "Press me"),
//       &window
//   );
//   button->move(100, 100);
//   button->show();
//   return app.exec();
// }

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  QWidget window;
  QLabel* label = new QLabel(QApplication::translate("windowlayout", "Name:"));
  QLineEdit* lineEdit = new QLineEdit();

  QHBoxLayout* layout = new QHBoxLayout();
  layout->addWidget(label);
  layout->addWidget(lineEdit);
  window.setLayout(layout);
  window.setWindowTitle(
      QApplication::translate("windowlayout", "Window layout")
  );
  window.show();
  return app.exec();
}
