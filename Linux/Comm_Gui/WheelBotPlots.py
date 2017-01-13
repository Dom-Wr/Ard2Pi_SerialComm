from PlotCanvas import *
from PyQt4.QtCore import SIGNAL

class HeadingPlotCanvas(MplDynamicPlotCanvas):
    """This is a plot canvas for the Wheelbot directional position."""

    def __init__(self, *args, **kwargs):
        MplDynamicPlotCanvas.__init__(self, *args, **kwargs)
        self.Title = "Heading (deg)"
    	self.setTitle()
        self.headingData = []
        print "Heading Plot Canvas initialized"

    def connectSlot(self, commThread):

        self.connect(commThread, SIGNAL("Wheelbot_state_update(PyQt_PyObject)"), self.update_WheelPlot_data)

    def update_WheelPlot_data(self, WheelBotMsg):
        #Keep only last 100 values of heading data for plotting
        if (len(self.headingData) > 100):
            self.headingData.pop(0)
        self.headingData.append(WheelBotMsg.WheelBotTlm.heading_deg)
        #print self.headingData

    def setTitle(self):
        self.axes.set_title(self.Title)

    def update_figure(self):
        self.axes.plot(self.headingData, 'b')
        self.setTitle()
        self.draw()
