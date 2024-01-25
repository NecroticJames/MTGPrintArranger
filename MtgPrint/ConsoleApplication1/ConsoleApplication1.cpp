#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string cutAndAdd(string inputString) {
    string cutString = inputString.substr(2);
    string newString = "1 " + cutString;
    return newString;
}

void processFile(string filename) {
    ifstream inputFile(filename);
    ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        cout << "Error opening file " << filename << endl;
        return;
    }

    int rowNum = 0;
    bool hasComment = false;
    string line;
    string commentsAfterRow;
    int repeatCount = 1;

    while (getline(inputFile, line)) {
        line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());

        // Check if the line is empty
        if (line.length() == 0) {
            continue;
        }

        // Check for "//" and store the text after it
        /*if (line.find("//") != string::npos) {
            hasComment = true;
            commentsAfterRow = line.substr(line.find("//") + 2);
        }*/

        // Get the first number in the line
        int startingNumber = stoi(line.substr(0, 2));

        // Repeat the current line based on the starting number
        switch (startingNumber) {
            case 2:
                repeatCount = 2;
                break;
        case 3:
            repeatCount = 3;
            break;
            case 4:
                repeatCount = 4;
				break;
                case 5:
			repeatCount = 5;
			break;
            case 6:
			repeatCount = 6;
			break;
            case 7:
                repeatCount = 7;
                break;
                case 8:
                    repeatCount = 8;
                    break;
                    case 9:
                        repeatCount = 9;
						break;

        case 10:
            repeatCount = 10;
            break;
        case 11:
            repeatCount = 11;
			break;
		case 12:
			repeatCount = 12;
            break;
            case 13:
                repeatCount = 13;
				break;
				case 14:
					repeatCount = 14;
					break;

        case 15:
            repeatCount = 15;
            break;
        case 16:
			repeatCount = 16;
			break;
        case 17:
			repeatCount = 17;
			break;
            case 18:
                repeatCount= 18;
                break;
            case 19:
                				repeatCount = 19;
				break;
                case 20:
                    repeatCount = 20;
                    break;
                case 21:    
                    repeatCount = 21;
					break;
					case 22:
						repeatCount = 22;
						break;
						case 23:
							repeatCount = 23;
							break;
							case 24:
								repeatCount = 24;
								break;
								case 25:
									repeatCount = 25;
									break;
									case 26:
										repeatCount = 26;
										break;
										case 27:
											repeatCount = 27;
											break;
											case 28:
												repeatCount = 28;
												break;
												case 29:
													repeatCount = 29;
													break;
													case 30:
														repeatCount = 30;
														break;
														case 31:
															repeatCount = 31;
															break;
															case 32:
																repeatCount = 32;
																break;
																case 33:
																	repeatCount = 33;
																	break;
																	case 34:
																		repeatCount = 34;
																		break;
																		case 35:
																			repeatCount = 35;
																			break;
																	
																	





        default:
            repeatCount = 1;
            break;
        }

        // Insert "BACK" rows if necessary
      /*  if (rowNum % 9 == 0 && hasComment) {
            hasComment = false;

            // Insert the text after comment
            for (int i = 0; i < commentsAfterRow.length(); i++) {
                outputFile << commentsAfterRow[i];
            }
        }*/
         if (rowNum % 9 == 0) {
            for (int i = 0; i < 9; i++) {
                outputFile << "1 Back (EXTRA) 001\n";
            }
        }

        // Repeat the current line based on the repeat count
        for (int i = 0; i < repeatCount; i++) {
            cutAndAdd(line);
            outputFile << line << endl;
        }
        repeatCount = 1;

        // Write the current line
        if (startingNumber < 2 || startingNumber > 36) {

            outputFile << line << endl;
        }

        rowNum++;
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    processFile("input.txt");

    return 0;
}