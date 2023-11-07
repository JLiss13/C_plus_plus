/************************************************
*    * Do not modify this starter code. *       *
* * Your code should be added at the bottom. *  *
*        * Thank you and good luck! *           *
************************************************/

#include <iostream>
#include <string>
using namespace std;

// YOU WILL NEED TO CALL THIS FUNCTION
// Function for taking a string and creating a "checksum" in ASCII
// Reminder: The input string should be more than just the "command"
//           Review problem description for more info
unsigned char checksum(std::string input) {
  unsigned char accumulated = 0;
  for(char& c : input) {
    accumulated += c;
  }
  return (accumulated % 26) + 'A';
}

// Required output format
const std::string MSG_HEADER = "ZOOX";

const std::string MSG_LEFT = "LEFT";
const std::string MSG_RIGHT = "RIGHT";
const std::string MSG_FORWARD = "FORWARD";
const std::string MSG_BEEP = "BEEP";

const std::string OUTPUT_LEFT = "L";
const std::string OUTPUT_RIGHT = "R";
const std::string OUTPUT_FORWARD = "F";
const std::string OUTPUT_BEEP = "!";

// You should not need to call this function
// Util used by execute_packet_command(...)
void execute_command(std::string cmd, int repeat) {
  for (int i = 0; i < repeat; i++) {
    std::cout << cmd;
  }
}

// YOU WILL NEED TO CALL THIS FUNCTION
// Provide the content of the command packet as inputs.
// cmd should be the command string from the packet
// repeat should be the repeat byte from the packet
void execute_packet_command(std::string cmd, int repeat) {
  if (cmd.compare(MSG_LEFT) == 0) {
    execute_command(OUTPUT_LEFT, repeat);
  }
  if (cmd.compare(MSG_RIGHT) == 0) {
    execute_command(OUTPUT_RIGHT, repeat);
  }
  if (cmd.compare(MSG_FORWARD) == 0) {
    execute_command(OUTPUT_FORWARD, repeat);
  }
  if (cmd.compare(MSG_BEEP) == 0) {
    execute_command(OUTPUT_BEEP, repeat);
  }
}

// Set up packets and bool statuses
std::string headerPacket;
std::string lengthPacket;
std::string cmdPacket ;
std::string repeatPacket;
std::string checksumPacket;
std::string currentPacket;

// Digest each byte one at a time in a whileloop and switch case
enum class ParseState {HEADER,LENGTH,CMD,REPEAT,CHECKSUM};
ParseState msgState = ParseState::HEADER;

// Required prototype and main
void parse(char c);
int main() {
  std::string input;
//   input = "ZOOX6RIGHT3X";
  input = "ZOOX5LEFT2QZOOX5BEEP3C";
//   cin >> input;
  cout << "Cmd: ";
  for(char& c : input) {
    parse(c);
  }
  return 0;
}

/************************************************/
// ------ Do not modify above this line ----------
// ----------- Add your code below ---------------
/************************************************/

// Notes
// Objectives:
//   Mod parse(char c) function to digest the command packet
//   Use execute_packet_command to test with
// Assumptions
//   Robot takes commands sent one byte at a time over serial to command packets
//   Header : "zoox", ASCII
//   Length byte: Tells you the size of the packet as decimal digit char [0 to 9]
//     Length= command length + repeat length
//   Command : Length + ASCII command "LEFT","RIGHT", "FORWARD","BEEP"
//   Repeat : decimal digit char [0 to 9] tells you the # times to repeat the command
//   Checksum : [A-Z] = calculation for bit errors
//   Noisy data link
//   Lots of bit errors
//
// Inputs --> Outputs
//  ZOOX6RIGHT3X -> Cmd: RRR
//  ZOOX5LEFT2QZOOX5BEEP3C -> Cmd: LL!!!

void parse(char c)
{

    // Concat the char input
    std::string byteChar(1,c);
    currentPacket=currentPacket + byteChar;
    // currentPacket.append(byteChar);

    // Check for the header
    switch (msgState)
    {
        case ParseState::HEADER:
            if (currentPacket.size()==4 && currentPacket==MSG_HEADER)
            {
                headerPacket.append(currentPacket);
                msgState = ParseState::LENGTH;
                currentPacket="";
            }
            else if (currentPacket.size()==4 && currentPacket!=MSG_HEADER)
            {
                msgState=ParseState::HEADER;
            }
            break;
        case ParseState::LENGTH:
            try
            {
                // Digest the length of the command
                if (currentPacket.size()==1 && 
                    stoi(currentPacket)>=0 &&
                    stoi(currentPacket)<=9)
                {
                int cmdLength = stoi(currentPacket);
                lengthPacket=currentPacket;
                currentPacket="";
                msgState=ParseState::CMD;
                }
            }
            catch (const std::invalid_argument& e)
            {
                std::cout << "Invalid argument: " << e.what() << std::endl;
                currentPacket="";
                msgState=ParseState::HEADER;
            }
        break;
        case ParseState::CMD:
        
            // Digest the next command
            if (currentPacket.size() > 3 && currentPacket.size() <=7)
            {
                if (currentPacket==MSG_LEFT) // Left command
                {
                cmdPacket = currentPacket;
                currentPacket="";
                msgState=ParseState::REPEAT;
                }
                else if (currentPacket==MSG_BEEP) // Beep command
                {
                cmdPacket = currentPacket;
                currentPacket="";
                msgState=ParseState::REPEAT;
                }
                else if (currentPacket==MSG_RIGHT) // Right command
                {
                cmdPacket = currentPacket;
                currentPacket="";
                msgState=ParseState::REPEAT;
                }
                else if (currentPacket==MSG_FORWARD) // Forward command
                {
                cmdPacket = currentPacket;
                currentPacket="";
                msgState=ParseState::REPEAT;
                }
            }
            else if (currentPacket.size() > 7) // Errorous data
            {
                currentPacket="";
                msgState=ParseState::HEADER;
            }
            break;
            case ParseState::REPEAT:
                try
                {
                    // Digest the length of the command
                    if (currentPacket.size()==1 && 
                        stoi(currentPacket)>=0 &&
                        stoi(currentPacket)<=9)
                    {
                    int cmdLength = stoi(currentPacket);
                    repeatPacket=currentPacket;
                    currentPacket="";
                    msgState=ParseState::CHECKSUM;
                    }
                }
                catch (const std::invalid_argument& e)
                {
                    std::cout << "Invalid argument: " << e.what() << std::endl;
                    currentPacket="";
                    msgState=ParseState::HEADER;
                }
                break;
        case ParseState::CHECKSUM:
        
            // Once checksum is digested verify the checksum matches
            if (currentPacket.size()==1)
            {
                std::string completeCommandPacket = lengthPacket + cmdPacket + repeatPacket;
                std::string commandString = cmdPacket;
                char checkChar = checksum(completeCommandPacket);
                std::string checkString(1,checkChar);
                if (checkString == currentPacket)
                {
                    // Collect packets into one command
                    execute_packet_command(commandString, stoi(repeatPacket));
                    
                    currentPacket ="";
                    // Reset parser state machine
                    msgState=ParseState::HEADER;
                }
                else
                {
                    // Reset parser state machine
                    msgState=ParseState::HEADER; 
                }
            }
        break;
    }
}