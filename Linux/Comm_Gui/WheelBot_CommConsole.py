from PyQt4 import QtCore, QtGui, uic
from CommQThread import *
from WheelBotPlots import *
import sys
import glob
#import comm_window
import serial


qtCreatorFile = "comm_window.ui"
Ui_Comm_Window, QtBaseClass = uic.loadUiType(qtCreatorFile)

class WheelBot_CommConsole(QtGui.QMainWindow, Ui_Comm_Window):

    def __init__(self):
        QtGui.QMainWindow.__init__(self)
        Ui_Comm_Window.__init__(self)
        self.setupUi()

    def setupUi(self):
        super(WheelBot_CommConsole, self).setupUi(self)

        #Combo box should list available serial ports
        self.PortcomboBox.addItems(self.serialPorts())

        #Connect and Disconnect Buttons with Serial ports
        self.Connect_Btn.clicked.connect(self.connectToArd)
        self.Disconnect_Btn.clicked.connect(self.disconnectFromArd)

        #Connect plots to the plot layout
        self.headingPlot = HeadingPlotCanvas(None, width=5, height=4, dpi=100)
        self.Lo_Plots.addWidget(self.headingPlot)

        #Connect Send Commands checkbox to start sending Commands
        

    def serialPorts(self):
        if sys.platform.startswith('win'):
            ports = ['COM%s' % (i + 1) for i in range(256)]
        elif sys.platform.startswith('linux') or sys.platform.startswith('cygwin'):
            # this excludes your current terminal "/dev/tty"
            ports = glob.glob('/dev/tty[A-Za-z]*')
        elif sys.platform.startswith('darwin'):
            ports = glob.glob('/dev/tty.*')
        else:
            raise EnvironmentError('Unsupported platform')

        result = []
        for port in ports:
            try:
                s = serial.Serial(port)
                s.close()
                result.append(port)
            except (OSError, serial.SerialException):
                pass
        print result
        return result

    def connectToArd(self):
        #start comm thread
        print type(self.PortcomboBox.currentText())
        self.ConsoleCommThread = CommQThread(str(self.PortcomboBox.currentText()))

        self.connect(self.ConsoleCommThread, SIGNAL("Wheelbot_state_update(PyQt_PyObject)"), self.update_Wheelbot_data)

        self.ConsoleCommThread.connectSlot(self)

        #Connect live plots to the WheelBot state update SIGNAL
        self.headingPlot.connectSlot(self.ConsoleCommThread)

        self.ConsoleCommThread.start()

        print "Connect procedure completed"

    def disconnectFromArd(self):
        if (self.ConsoleCommThread):
            self.ConsoleCommThread.terminate()

    def update_Wheelbot_data(self, WheelBotMsg):
        #Updating Motor speed as it comes back to the Linux system
        #Currently set to heading
        #print "Updating"
        self.Rgt_Motor_Speed.setText("%.2f"%WheelBotMsg.WheelBotTlm.heading)






if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)
    window = WheelBot_CommConsole()
    window.show()
    sys.exit(app.exec_())
