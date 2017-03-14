from WheelBotMsg import WheelBotMsg
from cmd import Cmd
import time


Message = WheelBotMsg('../../../../../dev/ttyACM5')

class MyPrompt(Cmd):

    def do_start_comm(self, args):
        """Starts Comm System on a different Thread and initiates Arduino"""
        Message.run_comm = True
        Message.snd_cmds = True
        Message.RunComm()

    def do_stop_comm(self, args):
        """Stops Arduino Communication and Data Logging and Exits Command Prompt"""
        Message.run_comm = False
        Message.data_logging = False
        raise SystemExit

    def do_heading_print(self,args):
        """Prints the current heading of the Rover"""
        print Message.WheelBotTlm.heading[0]

    def do_send_cmd(self,args):
        """Sends current commands to the Arduino"""
        #Message.encode()
        Message.snd_cmds = True
        Message.send()
        print "The commands have been sent to the Arduino"


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
