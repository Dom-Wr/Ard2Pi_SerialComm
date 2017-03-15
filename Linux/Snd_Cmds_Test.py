from WheelBotMsg import WheelBotMsg
from cmd import Cmd
import time


Message = WheelBotMsg('../../../../../dev/ttyACM7')

class MyPrompt(Cmd):

    def do_start_comm(self, args):
        """Starts Comm System on a different Thread and initiates Arduino"""
        Message.run_comm = True
        Message.RunComm()

    def do_stop_comm(self, args):
        """Stops Arduino Communication and Data Logging and Exits Command Prompt"""
        Message.run_comm = False
        Message.data_logging = False
        raise SystemExit

    def do_data_print(self,args):
        """Prints the current heading of the Rover"""
        print Message.WheelBotTlm.heading
        print Message.WheelBotTlm.distance

    def do_send_desired(self,args):
        """Sends current commands to the Arduino"""
        des_head = float(raw_input("Enter Desired Heading: "))
        des_dist = float(raw_input("Enter Desired Distance: "))
        Message.WheelBotCmds.des_heading = des_head
        Message.WheelBotCmds.des_distance = des_dist
        print Message.WheelBotCmds.des_heading
        print Message.WheelBotCmds.des_distance
        print "The waypoint has been sent to the Arduino"

        #adding sending down heading and distance desired.



    def do_log_data(self, args):
        """Begins logging data to csv file"""
        print "The lograte is: "
        Message.data_logging = True

    def do_stop_log_data(self, args):
        """Ends loggging data"""
        Message.data_logging = False

#    def do_set_lograte(self, args):
#        """"Allows user to set the frequency data will be logged to a csv"""
#        Message.log_frequency = args
#        print Message.log_frequency

    def do_q(self, args):
        """Force quits the program"""
        print "Force Quit"
        raise SystemExit

if __name__ == '__main__':
    prompt = MyPrompt()
    prompt.prompt = '>'
    prompt.cmdloop('Ard2Pi Comm System Prompt...')
