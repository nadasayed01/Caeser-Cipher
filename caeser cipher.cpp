#include <iostream>
using namespace std;
int main()
{
    // user will chooses if he wants encryption or decryption 
    int choice;
    cout << "1. Encryption\n2. Decryption\nchoose(1,2): ";
    cin >> choice;
    cin.ignore();
    if(choice == 1)
    {
        //if he chooses encryption
        string msg; //type of message will be string because it will be only alphabetic
        cout<<"Message can only be alphabetic"<<endl;
        cout<<"Please Enter Message: "<<endl;
        getline(cin,msg);//taking input from the user(message)
        int shifts;//declaring number of shifts 
        cout<<"Please Enter shifts between(0-25)"<<endl;//from 0 to 25 to equal english letters
        cin>>shifts;//taking input from the user(number of shifts)
        
        cin.ignore();
        string encryptedText = msg;//msg is the message which we took it from the user and will encrypt it
        for(int i = 0; i < msg.size(); i++)//this loop for checking every letter in the message
        {
            if(msg[i]==32)//32 Ascii of space 
            {
                continue; //if Ascii of letter == 32 this means that is a space so i will ignore it
            }
            else
            {
                if((msg[i]+shifts) > 122)//if number of ascii of message + number of shifts greater than 122 (ascii of z small) this is not rational because there are not any letters after z so i will repeat from a again
                {
                    shifts = (shifts % 26 + 26) % 26;//for shifts with negative numbers it will let positive shifts with no changes and convert negative to positive
                    int temp = (msg[i]+shifts)-122;//to start from a again i wil subtract ascii of z small from ascii of (message plus number of shifts) so i can start from a again 
                    encryptedText[i]= 96 + temp;//after this ascii of letter will be in variable (temp) and i will add to it 96 because small letters start from 97
                }
                else if  (msg[i]+shifts > 90 && msg[i] <=96)//if ascii of message plus number of shifts equal number in this zone (this zone does not include letters) so i will start from  a again
                {
                    shifts = (shifts % 26 + 26) % 26;//for shifts with negative numbers it will let positive shifts with no changes and convert negative to positive
                    int temp = (msg[i]+shifts)-90;//to start from A again i wil subtract ascii of z capital from ascii of (message plus number of shifts) so i can start from A again 
                    encryptedText[i]= 64 + temp;// after this ascii of letter will be in variable (temp) and i will add to it 64 because capital letters start from 65
                    
                }
                else
                {
                    shifts = (shifts % 26 + 26) % 26;//for shifts with negative numbers it will let positive shifts with no changes and convert negative to positive
                    encryptedText[i]+=shifts;// if ascii of message plus number of shifts are in zone from a to z or A to Z it will work with no conditions
                }
                       
                    
                
            }
        }
        cout<<"Encrypted Message: "<<encryptedText<<endl;//finally displaying encryptedText in screen 
    }
    else if(choice == 2)
    {
        
        string encryptedMessage;//type of encryptedmessage will be string because it will be only alphabetic
        cout<<"Message can only be alphapetic"<<endl;
        cout<<"Please Enter encrypted text: "<<endl;
        getline(cin,encryptedMessage);//taking input from the user(encryptedmessage)
        int decryptedshifts;//declaring number of shifts 
        cout<<"Plesae Enter shifts between (0-25): "<<endl;//from 0 to 25 to equal english letters
        cin>>decryptedshifts;//taking input from the user(number of shifts)
        cin.ignore();
        string decryptedText = encryptedMessage;//decryptedMessage is the message which we took it from the user and will decrypt it
        for(int i = 0; i < encryptedMessage.size(); i++)//this loop for checking every letter in the encryptedMessage
        {
            if(encryptedMessage[i]==32)//32 Ascii of space 
            {
                continue; //if Ascii of letter == 32 this means that is a space so i will ignore it
            
            }
            else//decryption is opposite of encryption so here i will subtract ascii of encryption message from number of shifts
            {
                if((encryptedMessage[i] - decryptedshifts) < 97 && (encryptedMessage[i] - decryptedshifts) > 90)//if number of ascii of encrypted message - number of shifts less than 97 (ascii of a small) and  greater than 90 (ascii of z capital) this means that the message in a zone that does not include any letters 
                {
                    decryptedshifts = ( decryptedshifts% 26 + 26) % 26;//for shifts with negative numbers it will let positive shifts with no changes and convert negative to positive
                    int temp = (encryptedMessage[i] - decryptedshifts) + 26;//ascii of z - ascii of a + 1 this equation will enable me to start from z again
                    decryptedText[i] = temp;//as i put decryptedMessage in variable temp so encryptedText equal temp
                    
                }
                else if((encryptedMessage[i] - decryptedshifts) < 65)//if number of ascii of encrypted message - number of shifts less than 65 (ascii of A capital) this is not rational because there are not any letters before A so i will repeat from Z again
                    {decryptedshifts = (decryptedshifts % 26 + 26) % 26;//for shifts with negative numbers it will let positive shifts with no changes and convert negative to positive
                    int temp = (encryptedMessage[i] - decryptedshifts) + 26;//ascii of z - ascii of a + 1 this equation will enable me to start from z again
                    decryptedText[i] = temp;//as i put decryptedMessage in variable temp so encryptedText equal temp
                    
                }
                else
                {
                    decryptedshifts = (decryptedshifts % 26 + 26) % 26;//for shifts with negative numbers it will let positive shifts with no changes and convert negative to positive
                    decryptedText[i] = encryptedMessage[i] - decryptedshifts;// if ascii of message plus number of shifts are in zone from a to z or A to Z it will work with no conditions
                }
            }
        }
         cout<<"Decrypted Message: "<<decryptedText<<endl;//finally displaying decryptedText in screen 
    }
    
}