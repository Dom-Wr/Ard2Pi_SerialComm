from PyQt4.QtCore import QThread, QObject, SIGNAL
from WheelBotMsg import WheelBotMsg


class CommQThread(QThread):
    def __init__(self, serialPort):
        QThread.__init__(self)
        self.serialPort = serialPort
        #print type(serialPort)
        self.Message = WheelBotMsg(serialPort)
        print self.Message.ser.is_open

    def __del__(self):
        self.wait()

    def connectSlot(self, uiThread):
        self.connect(uiThread, SIGNAL("send_WheelBot_cmds(PyQt_PyObject)"), self.process_WheelBot_cmds)

    def process_WheelBot_cmds(self, WheelBotMsg):
        self.Message.WheelBotCmds.kp = WheelBotMsg.WheelBotCmds.kp

    def run(self):
        print "Run function is runnning"
        while True:
            self.Message.Rcv_Send()
            self.emit(SIGNAL('Wheelbot_state_update(PyQt_PyObject)'), self.Message)
            self.msleep(20)
