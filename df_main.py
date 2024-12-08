import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QVBoxLayout, QWidget,QLabel
from PyQt5.uic import loadUi
from PyQt5.QtGui import QPixmap, QPainter
from PyQt5.QtCore import Qt
from qcustomplot import QCustomPlot

class MyWindow(QMainWindow):
    def __init__(self):
        super(MyWindow, self).__init__()
        self.initUI()

    def initUI(self):
        # Load the UI file
        loadUi('df_gui_version_1.ui', self)

        # Connect any signals and slots if needed

        self.set_background_image("jpgtopngconverter-com.jpg")  # Replace 'background.jpg' with your image file path

        self.pushButton_6.setStyleSheet("color: red;")  # Change 'red' to the desired color
        self.pushButton_5.setStyleSheet("color: #6b8a7a;")  # Change 'red' to the desired color
        self.pushButton_4.setStyleSheet("color: #6b8a7a;")  # Change 'red' to the desired color




        self.show()
    def set_background_image(self, image_path):
        self.background_image = QPixmap(image_path)

    def paintEvent(self, event):
        painter = QPainter(self)
        painter.drawPixmap(0, 0, self.width(), self.height(), self.background_image)
        super().paintEvent(event)
def main():
    app = QApplication(sys.argv)
    window = MyWindow()
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()
